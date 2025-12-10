#include "appartement.h"
#include "connection.h"
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace {

bool enregistrerDansHistorique(const QString &appartementId, const QString &action)
{
    if (appartementId.isEmpty()) {
        qWarning() << "Historique: identifiant vide pour l'action" << action;
        return false;
    }

    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();

    // FIXED: Use correct method name
    if (!conn.createConnection()) {
        qWarning() << "Historique: Impossible de se connecter à la base de données";
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    const QDateTime now = QDateTime::currentDateTime();

    // Always use A_M_S column for historique
    QSqlQuery histQuery(db);
    histQuery.prepare(QStringLiteral(
        "INSERT INTO HISTORIQUE (Date_et_Heure, Id_Appartement, A_M_S) "
        "VALUES (:dateHeure, :id, :action)"));
    histQuery.bindValue(":dateHeure", now);
    histQuery.bindValue(":id", appartementId);
    histQuery.bindValue(":action", action);

    if (!histQuery.exec()) {
        qWarning() << "Echec insertion historique:" << histQuery.lastError().text();
        qDebug() << "Query:" << histQuery.executedQuery();
        qDebug() << "Values - Date:" << now << "ID:" << appartementId << "Action:" << action;
        return false;
    }

    qDebug() << "Historique enregistré avec succès pour" << appartementId << "action:" << action;
    return true;
}

} // namespace

Appartement::Appartement()
    : id(""), numtel(""), numapp(""), adresse(""), etage(""), nbrPieces(""), etat("Disponible"), prix(0)
{
}

Appartement::Appartement(QString id, QString numtel, QString numapp, QString adresse, QString etage, QString nbrPieces)
    : id(id), numtel(numtel), numapp(numapp), adresse(adresse), etage(etage), nbrPieces(nbrPieces), etat("Disponible"), prix(0)
{
}

bool Appartement::ajouter()
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("INSERT INTO APPARTEMENT (ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix) "
                  "VALUES (:id, :numtel, :numapp, :adresse, :etage, :nbrPieces, :etat, :prix)");

    query.bindValue(":id", id);
    query.bindValue(":numtel", numtel);
    query.bindValue(":numapp", numapp);
    query.bindValue(":adresse", adresse);
    query.bindValue(":etage", etage);
    query.bindValue(":nbrPieces", nbrPieces);
    query.bindValue(":etat", etat);
    query.bindValue(":prix", prix);

    if (query.exec())
    {
        if (!enregistrerDansHistorique(id, QStringLiteral("Ajouter"))) {
            qWarning() << "Historique non mis a jour pour l'ajout de" << id;
        }
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de l'ajout:" << query.lastError().text();
        return false;
    }
}

bool Appartement::modifier()
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("UPDATE APPARTEMENT SET NUMERO_TEL=:numtel, NUMERO_AP=:numapp, ADRESSE=:adresse, "
                  "ETAGE=:etage, NBR_PIECES=:nbrPieces, Etat=:etat, Prix=:prix WHERE ID_APPARTEMENT=:id");

    query.bindValue(":id", id);
    query.bindValue(":numtel", numtel);
    query.bindValue(":numapp", numapp);
    query.bindValue(":adresse", adresse);
    query.bindValue(":etage", etage);
    query.bindValue(":nbrPieces", nbrPieces);
    query.bindValue(":etat", etat);
    query.bindValue(":prix", prix);

    if (query.exec())
    {
        if (!enregistrerDansHistorique(id, QStringLiteral("Modifier"))) {
            qWarning() << "Historique non mis a jour pour la modification de" << id;
        }
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }
}

bool Appartement::supprimer(QString idAppartement)
{
    // Record in historique BEFORE deleting the apartment
    if (!enregistrerDansHistorique(idAppartement, QStringLiteral("Supprimer"))) {
        qWarning() << "Historique non mis a jour pour la suppression de" << idAppartement;
        // Continue with deletion even if historique fails
    }

    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("DELETE FROM APPARTEMENT WHERE ID_APPARTEMENT=:id");
    query.bindValue(":id", idAppartement);

    if (query.exec())
    {
        qDebug() << "Appartement" << idAppartement << "supprimé avec succès";
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
}

bool Appartement::rechercher(QString idAppartement)
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return false;
    }

    QSqlDatabase db = conn.getDatabase();
    QSqlQuery query(db);
    query.prepare("SELECT ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix "
                  "FROM APPARTEMENT WHERE ID_APPARTEMENT=:id");
    query.bindValue(":id", idAppartement);

    if (query.exec() && query.next())
    {
        id = query.value(0).toString();
        numtel = query.value(1).toString();
        numapp = query.value(2).toString();
        adresse = query.value(3).toString();
        etage = query.value(4).toString();
        nbrPieces = query.value(5).toString();
        etat = query.value(6).toString();
        prix = query.value(7).toInt();
        return true;
    }
    else
    {
        qDebug() << "Appartement non trouvé ou erreur:" << query.lastError().text();
        return false;
    }
}

bool Appartement::estValide() const
{
    if (id.isEmpty() || numtel.isEmpty() || numapp.isEmpty() || adresse.isEmpty() || nbrPieces.isEmpty())
    {
        return false;
    }

    if (etage.isEmpty() || etage == "Ajouter étage")
    {
        return false;
    }

    // Validate that numtel is numeric
    bool ok;
    numtel.toInt(&ok);
    if (!ok)
    {
        return false;
    }

    // Validate that numapp is numeric
    numapp.toInt(&ok);
    if (!ok)
    {
        return false;
    }

    // Validate that nbrPieces is numeric
    nbrPieces.toInt(&ok);
    if (!ok)
    {
        return false;
    }

    return true;
}

QList<Appartement> Appartement::rechercherTous()
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return QList<Appartement>();
    }

    QSqlDatabase db = conn.getDatabase();
    QList<Appartement> appartements;
    QSqlQuery query(db);
    query.exec("SELECT ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix FROM APPARTEMENT");

    while (query.next())
    {
        Appartement app;
        app.setId(query.value(0).toString());
        app.setNumTel(query.value(1).toString());
        app.setNumApp(query.value(2).toString());
        app.setAdresse(query.value(3).toString());
        app.setEtage(query.value(4).toString());
        app.setNbrPieces(query.value(5).toString());
        app.setEtat(query.value(6).toString());
        app.setPrix(query.value(7).toInt());
        appartements.append(app);
    }

    return appartements;
}

QList<Appartement> Appartement::rechercherParEtage(QString etage)
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return QList<Appartement>();
    }

    QSqlDatabase db = conn.getDatabase();
    QList<Appartement> appartements;
    QSqlQuery query(db);
    query.prepare("SELECT ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix FROM APPARTEMENT WHERE ETAGE=:etage");
    query.bindValue(":etage", etage);

    if (query.exec())
    {
        while (query.next())
        {
            Appartement app;
            app.setId(query.value(0).toString());
            app.setNumTel(query.value(1).toString());
            app.setNumApp(query.value(2).toString());
            app.setAdresse(query.value(3).toString());
            app.setEtage(query.value(4).toString());
            app.setNbrPieces(query.value(5).toString());
            app.setEtat(query.value(6).toString());
            app.setPrix(query.value(7).toInt());
            appartements.append(app);
        }
    }

    return appartements;
}

QList<Appartement> Appartement::rechercherParNbrPieces(QString nbrPieces)
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return QList<Appartement>();
    }

    QSqlDatabase db = conn.getDatabase();
    QList<Appartement> appartements;
    QSqlQuery query(db);
    query.prepare("SELECT ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix FROM APPARTEMENT WHERE NBR_PIECES=:nbrPieces");
    query.bindValue(":nbrPieces", nbrPieces);

    if (query.exec())
    {
        while (query.next())
        {
            Appartement app;
            app.setId(query.value(0).toString());
            app.setNumTel(query.value(1).toString());
            app.setNumApp(query.value(2).toString());
            app.setAdresse(query.value(3).toString());
            app.setEtage(query.value(4).toString());
            app.setNbrPieces(query.value(5).toString());
            app.setEtat(query.value(6).toString());
            app.setPrix(query.value(7).toInt());
            appartements.append(app);
        }
    }

    return appartements;
}

QList<Appartement> Appartement::rechercherParEtat(QString etat)
{
    // FIXED: Use singleton instance
    Connection& conn = Connection::getInstance();
    if (!conn.createConnection()) {
        return QList<Appartement>();
    }

    QSqlDatabase db = conn.getDatabase();
    QList<Appartement> appartements;
    QSqlQuery query(db);
    query.prepare("SELECT ID_APPARTEMENT, NUMERO_TEL, NUMERO_AP, ADRESSE, ETAGE, NBR_PIECES, Etat, Prix FROM APPARTEMENT WHERE Etat=:etat");
    query.bindValue(":etat", etat);

    if (query.exec())
    {
        while (query.next())
        {
            Appartement app;
            app.setId(query.value(0).toString());
            app.setNumTel(query.value(1).toString());
            app.setNumApp(query.value(2).toString());
            app.setAdresse(query.value(3).toString());
            app.setEtage(query.value(4).toString());
            app.setNbrPieces(query.value(5).toString());
            app.setEtat(query.value(6).toString());
            app.setPrix(query.value(7).toInt());
            appartements.append(app);
        }
    }

    return appartements;
}
