#include "connection.h"
#include <QDir>
#include <QSqlQuery>
#include <QStringList>
#include <QProcess>
#include <QSettings>
#include <QFile>
#include <QMessageBox>
#include <QVariant>

Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

Connection::~Connection()
{
    if (db.isOpen()) {
        db.close();
    }
}

Connection& Connection::getInstance()
{
    static Connection instance;
    return instance;
}

bool Connection::createConnection()
{
    qDebug() << "=== CONNECTING TO ORACLE XE ===";
    qDebug() << "Username: SOUMAYA";
    qDebug() << "Password: esprit18";

    // Try multiple connection formats with SOUMAYA credentials
    QStringList xeConnections = {
        "DRIVER={Oracle in XE};DBQ=localhost:1521/XE;UID=SOUMAYA;PWD=esprit18",
        "DRIVER={Oracle in XE};DBQ=XE;UID=SOUMAYA;PWD=esprit18",
        "DRIVER={Oracle in XE};SERVER=localhost:1521/XE;UID=SOUMAYA;PWD=esprit18",
        "DRIVER={Oracle in XE};DBQ=(DESCRIPTION=(ADDRESS=(PROTOCOL=TCP)(HOST=localhost)(PORT=1521))(CONNECT_DATA=(SERVICE_NAME=XE)));UID=SOUMAYA;PWD=esprit18"
    };

    for (const QString &connStr : xeConnections) {
        qDebug() << "Trying:" << connStr;
        db.setDatabaseName(connStr);

        if (db.open()) {
            qDebug() << "✅ ORACLE XE CONNECTION SUCCESSFUL!";

            // Test the connection and show current user
            QSqlQuery query;
            if (query.exec("SELECT USER FROM DUAL")) {
                query.next();
                QString currentUser = query.value(0).toString();
                qDebug() << "Connected as user:" << currentUser;

                // Check if we have access to SAMAR20 tables
                qDebug() << "\nChecking database access...";

                // Check if we can see the MATERIEL table
                QSqlQuery checkQuery;

                // First, check if MATERIEL table exists in current schema
                if (checkQuery.exec("SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = 'MATERIEL'")) {
                    checkQuery.next();
                    if (checkQuery.value(0).toInt() > 0) {
                        qDebug() << "✅ MATERIEL table exists in" << currentUser << "schema";
                    } else {
                        qDebug() << "⚠️  MATERIEL table NOT found in" << currentUser << "schema";

                        // Try to access SAMAR20's tables with schema prefix
                        if (checkQuery.exec("SELECT COUNT(*) FROM ALL_TABLES WHERE OWNER = 'SAMAR20' AND TABLE_NAME = 'MATERIEL'")) {
                            checkQuery.next();
                            if (checkQuery.value(0).toInt() > 0) {
                                qDebug() << "✅ SAMAR20.MATERIEL table exists";

                                // Try to select from SAMAR20's table
                                QSqlQuery sampleQuery;
                                if (sampleQuery.exec("SELECT CODE_BARRE, NOM_MATR FROM SAMAR20.MATERIEL WHERE ROWNUM <= 3")) {
                                    qDebug() << "Sample data from SAMAR20.MATERIEL:";
                                    while (sampleQuery.next()) {
                                        qDebug() << "  -" << sampleQuery.value(0).toString()
                                        << "|" << sampleQuery.value(1).toString();
                                    }
                                } else {
                                    qDebug() << "Cannot access SAMAR20.MATERIEL:" << sampleQuery.lastError().text();
                                    qDebug() << "You might need SELECT privileges on SAMAR20 tables";
                                }
                            }
                        }
                    }
                }
            }

            // Try to create MATERIEL table in SOUMAYA schema if it doesn't exist
            QSqlQuery createCheck;
            if (createCheck.exec("SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = 'MATERIEL'")) {
                createCheck.next();
                if (createCheck.value(0).toInt() == 0) {
                    qDebug() << "\nCreating MATERIEL table in SOUMAYA schema...";

                    QString createTable =
                        "CREATE TABLE MATERIEL ("
                        "   CODE_BARRE   VARCHAR2(100) PRIMARY KEY,"
                        "   NOM_MATR     VARCHAR2(100) NOT NULL,"
                        "   TYPE_MAT     VARCHAR2(100),"
                        "   ETAT         VARCHAR2(50),"
                        "   QTITE        NUMBER DEFAULT 0,"
                        "   ID_EMPLOYE   NUMBER(*,0)"
                        ")";

                    QSqlQuery createQuery;
                    if (createQuery.exec(createTable)) {
                        qDebug() << "✅ MATERIEL table created in SOUMAYA schema";

                        // Insert sample data
                        QString insertData =
                            "INSERT INTO MATERIEL (CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT, QTITE, ID_EMPLOYE) VALUES "
                            "('SOUMAYA001', 'Ordinateur SOUMAYA', 'Informatique', 'Fonctionnel', 3, 1),"
                            "('SOUMAYA002', 'Imprimante', 'Bureau', 'Fonctionnel', 2, 2)";

                        QSqlQuery insertQuery;
                        if (insertQuery.exec(insertData)) {
                            qDebug() << "✅ Sample data inserted into MATERIEL table";
                        }
                    } else {
                        qDebug() << "Failed to create MATERIEL table:" << createQuery.lastError().text();
                    }
                } else {
                    qDebug() << "\n✅ MATERIEL table already exists in SOUMAYA schema";
                }
            }

            // Check all tables in current schema
            qDebug() << "\nTables in" << query.value(0).toString() << "schema:";
            QSqlQuery tablesQuery("SELECT TABLE_NAME FROM USER_TABLES ORDER BY TABLE_NAME");
            bool hasTables = false;
            while (tablesQuery.next()) {
                qDebug() << "  -" << tablesQuery.value(0).toString();
                hasTables = true;
            }
            if (!hasTables) {
                qDebug() << "  No tables found in current schema";
            }

            // Migrate SQLite data if exists
            migrateSQLiteToOracle();

            return true;
        } else {
            qDebug() << "Failed:" << db.lastError().text();
        }
    }

    // Try DSN connection with SOUMAYA
    qDebug() << "\nTrying DSN connection...";
    db.setDatabaseName("DSN=Source_Projet2A;UID=SOUMAYA;PWD=esprit18");
    if (db.open()) {
        qDebug() << "✅ DSN CONNECTION SUCCESSFUL!";
        migrateSQLiteToOracle();
        return true;
    } else {
        qDebug() << "DSN failed:" << db.lastError().text();
    }

    // Check if we can connect as SAMAR20 (for testing)
    qDebug() << "\nTrying SAMAR20 credentials for testing...";
    if (testConnection("SAMAR20", "Demonslayer789")) {
        qDebug() << "⚠️  Note: Can connect as SAMAR20 but not as SOUMAYA";
        qDebug() << "Check if SOUMAYA user exists and has proper privileges";
    }

    // Fallback to SQLite
    qDebug() << "\nFalling back to SQLite...";
    return setupSQLite();
}

void Connection::checkODBCDrivers()
{
    qDebug() << "Checking installed ODBC drivers...";

    // Check 64-bit ODBC drivers
    QSettings registry64("HKEY_LOCAL_MACHINE\\SOFTWARE\\ODBC\\ODBCINST.INI\\ODBC Drivers", QSettings::NativeFormat);
    QStringList drivers64 = registry64.childKeys();

    qDebug() << "64-bit ODBC Drivers:";
    if (drivers64.isEmpty()) {
        qDebug() << "  None found";
    } else {
        foreach(QString driver, drivers64) {
            qDebug() << "  -" << driver;
        }
    }

    // Also check 32-bit drivers
    QSettings registry32("HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\ODBC\\ODBCINST.INI\\ODBC Drivers", QSettings::NativeFormat);
    QStringList drivers32 = registry32.childKeys();

    if (!drivers32.isEmpty()) {
        qDebug() << "32-bit ODBC Drivers:";
        foreach(QString driver, drivers32) {
            qDebug() << "  -" << driver;
        }
    }
}

bool Connection::setupSQLite()
{
    // Remove the existing QODBC connection
    if (db.isOpen()) {
        db.close();
    }

    // Remove the database connection
    QString connectionName = db.connectionName();
    QSqlDatabase::removeDatabase(connectionName);

    // Create SQLite database
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/projet_smart_city_temp.db";
    db.setDatabaseName(dbPath);

    if (db.open()) {
        QSqlQuery query;

        // Create MATERIEL table matching Oracle structure
        query.exec("CREATE TABLE IF NOT EXISTS MATERIEL ("
                   "CODE_BARRE       VARCHAR(100) PRIMARY KEY,"
                   "NOM_MATR         VARCHAR(100) NOT NULL,"
                   "TYPE_MAT         VARCHAR(100),"
                   "ETAT             VARCHAR(50),"
                   "QTITE            INTEGER DEFAULT 0,"
                   "ID_EMPLOYE       INTEGER)");

        // Create other tables as needed
        query.exec("CREATE TABLE IF NOT EXISTS EMPLOYE ("
                   "ID_EMPLOYE       INTEGER PRIMARY KEY,"
                   "NOM              VARCHAR(20),"
                   "PRENOM           VARCHAR(20),"
                   "POSTE            VARCHAR(20),"
                   "SALAIRE          REAL,"
                   "EMAIL            VARCHAR(50),"
                   "NUM_TEL          INTEGER)");

        // Insert sample data
        query.exec("INSERT OR IGNORE INTO EMPLOYE (ID_EMPLOYE, NOM, PRENOM, POSTE, SALAIRE, EMAIL, NUM_TEL) "
                   "VALUES (1, 'SOUMAYA', 'Admin', 'Manager', 4000, 'soumayatest@example.com', 98765432)");

        query.exec("INSERT OR IGNORE INTO MATERIEL (CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT, QTITE, ID_EMPLOYE) "
                   "VALUES ('SQLITE001', 'Laptop SQLite', 'Informatique', 'Fonctionnel', 5, 1),"
                   "('SQLITE002', 'Scanner', 'Bureau', 'En réparation', 1, 1)");

        QMessageBox::information(nullptr, "Mode SQLite",
                                 "Impossible de se connecter à Oracle avec l'utilisateur SOUMAYA.\n"
                                 "Utilisation de SQLite temporairement.\n"
                                 "Données migrées vers Oracle lors de la reconnexion.");
        qDebug() << "✅ SQLite database created at:" << dbPath;
        return true;
    }

    qDebug() << "❌ Failed to create SQLite database";
    return false;
}

bool Connection::migrateSQLiteToOracle()
{
    // Only migrate if we're connected to Oracle
    if (!db.isOpen() || db.databaseName().contains("SQLite", Qt::CaseInsensitive)) {
        return false;
    }

    QString sqlitePath = QDir::currentPath() + "/projet_smart_city_temp.db";

    if (!QFile::exists(sqlitePath)) {
        return true; // No data to migrate
    }

    QSqlDatabase sqliteDb = QSqlDatabase::addDatabase("QSQLITE", "migration_connection");
    sqliteDb.setDatabaseName(sqlitePath);

    if (!sqliteDb.open()) {
        qDebug() << "Failed to open SQLite database for migration";
        return false;
    }

    int migratedCount = 0;

    // Migrate MATERIEL table
    QSqlQuery sqliteQuery("SELECT CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT, QTITE, ID_EMPLOYE FROM MATERIEL", sqliteDb);

    while (sqliteQuery.next()) {
        QString code_barre = sqliteQuery.value(0).toString();
        QString nom_matr = sqliteQuery.value(1).toString();
        QString type_mat = sqliteQuery.value(2).toString();
        QString etat = sqliteQuery.value(3).toString();
        int qtite = sqliteQuery.value(4).toInt();
        int id_employe = sqliteQuery.value(5).toInt();

        // Check if record exists (don't check schema prefix since we're in SOUMAYA)
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT COUNT(*) FROM MATERIEL WHERE CODE_BARRE = :code_barre");
        checkQuery.bindValue(":code_barre", code_barre);

        bool recordExists = false;
        if (checkQuery.exec() && checkQuery.next()) {
            recordExists = (checkQuery.value(0).toInt() > 0);
        }

        if (!recordExists) {
            QSqlQuery oracleQuery;
            oracleQuery.prepare("INSERT INTO MATERIEL (CODE_BARRE, NOM_MATR, TYPE_MAT, ETAT, QTITE, ID_EMPLOYE) "
                                "VALUES (:code_barre, :nom_matr, :type_mat, :etat, :qtite, :id_employe)");
            oracleQuery.bindValue(":code_barre", code_barre);
            oracleQuery.bindValue(":nom_matr", nom_matr);
            oracleQuery.bindValue(":type_mat", type_mat);
            oracleQuery.bindValue(":etat", etat);
            oracleQuery.bindValue(":qtite", qtite);
            oracleQuery.bindValue(":id_employe", id_employe);

            if (oracleQuery.exec()) {
                migratedCount++;
            }
        }
    }

    sqliteDb.close();
    QSqlDatabase::removeDatabase("migration_connection");

    if (migratedCount > 0) {
        qDebug() << "✅" << migratedCount << "enregistrements migrés de SQLite vers Oracle (SOUMAYA)";
        QFile::remove(sqlitePath);
    }

    return true;
}

bool Connection::testConnection(const QString &username, const QString &password)
{
    QString testConnStr = QString("DRIVER={Oracle in XE};DBQ=localhost:1521/XE;UID=%1;PWD=%2")
    .arg(username).arg(password);

    QSqlDatabase testDb = QSqlDatabase::addDatabase("QODBC", "test_connection_" + username);
    testDb.setDatabaseName(testConnStr);

    bool success = testDb.open();
    if (success) {
        qDebug() << "✅ Test connection successful for user:" << username;

        // Show current user
        QSqlQuery query("SELECT USER FROM DUAL", testDb);
        if (query.next()) {
            qDebug() << "  Connected as:" << query.value(0).toString();
        }

        testDb.close();
    } else {
        qDebug() << "❌ Test connection failed for user:" << username << "-" << testDb.lastError().text();
    }

    QSqlDatabase::removeDatabase("test_connection_" + username);
    return success;
}
