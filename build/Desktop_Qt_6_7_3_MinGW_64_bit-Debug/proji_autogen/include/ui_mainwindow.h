/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QPushButton *recherche;
    QTableWidget *res;
    QLabel *label_9;
    QComboBox *tripar;
    QPushButton *trier;
    QComboBox *repar;
    QLineEdit *rech;
    QGroupBox *groupBox_3;
    QPushButton *modifier;
    QLabel *label_8;
    QLineEdit *idmodsup;
    QPushButton *supprimer;
    QPushButton *pdf;
    QPushButton *accueil;
    QPushButton *fonction;
    QFrame *frame;
    QPushButton *ges_emp;
    QPushButton *ges_mat;
    QPushButton *ges_es_vert;
    QPushButton *ges_vehic;
    QPushButton *ges_appar;
    QPushButton *deconnect;
    QLabel *logo;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *numtel;
    QLabel *label_3;
    QLineEdit *numapp;
    QLabel *label_4;
    QLineEdit *add;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *ss;
    QPushButton *valider;
    QPushButton *annuler;
    QComboBox *etage;
    QLabel *label_10;
    QLineEdit *prix;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1441, 612);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(550, 80, 881, 381));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 40, 151, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        recherche = new QPushButton(groupBox_2);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(380, 40, 121, 29));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        res = new QTableWidget(groupBox_2);
        if (res->columnCount() < 8)
            res->setColumnCount(8);
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic")});
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        res->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        res->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        res->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        res->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        res->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        res->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        res->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        res->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        res->setObjectName("res");
        res->setGeometry(QRect(20, 81, 841, 281));
        res->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(510, 40, 91, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        tripar = new QComboBox(groupBox_2);
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->setObjectName("tripar");
        tripar->setGeometry(QRect(600, 40, 151, 28));
        tripar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(770, 40, 90, 29));
        trier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        repar = new QComboBox(groupBox_2);
        repar->addItem(QString());
        repar->addItem(QString());
        repar->addItem(QString());
        repar->addItem(QString());
        repar->setObjectName("repar");
        repar->setGeometry(QRect(140, 40, 131, 28));
        repar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        rech = new QLineEdit(groupBox_2);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(280, 40, 91, 28));
        rech->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(550, 470, 881, 111));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        modifier = new QPushButton(groupBox_3);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(330, 50, 101, 29));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 50, 111, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        idmodsup = new QLineEdit(groupBox_3);
        idmodsup->setObjectName("idmodsup");
        idmodsup->setGeometry(QRect(130, 50, 181, 28));
        idmodsup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(450, 50, 121, 29));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        pdf = new QPushButton(groupBox_3);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(660, 50, 201, 29));
        pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        accueil = new QPushButton(centralwidget);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 40, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        fonction = new QPushButton(centralwidget);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 40, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -40, 241, 671));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        ges_emp = new QPushButton(frame);
        ges_emp->setObjectName("ges_emp");
        ges_emp->setGeometry(QRect(10, 170, 231, 71));
        ges_emp->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color:rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ges_mat = new QPushButton(frame);
        ges_mat->setObjectName("ges_mat");
        ges_mat->setGeometry(QRect(10, 240, 231, 71));
        ges_mat->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color:rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ges_es_vert = new QPushButton(frame);
        ges_es_vert->setObjectName("ges_es_vert");
        ges_es_vert->setGeometry(QRect(10, 310, 231, 71));
        ges_es_vert->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color:rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ges_vehic = new QPushButton(frame);
        ges_vehic->setObjectName("ges_vehic");
        ges_vehic->setGeometry(QRect(10, 380, 231, 71));
        ges_vehic->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color:rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ges_appar = new QPushButton(frame);
        ges_appar->setObjectName("ges_appar");
        ges_appar->setGeometry(QRect(10, 450, 231, 71));
        ges_appar->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"color: rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        deconnect = new QPushButton(frame);
        deconnect->setObjectName("deconnect");
        deconnect->setGeometry(QRect(10, 580, 231, 71));
        deconnect->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color: rgb(170, 0, 0);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        logo = new QLabel(frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(80, 59, 121, 91));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(250, 80, 291, 501));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 121, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        id = new QLineEdit(groupBox);
        id->setObjectName("id");
        id->setGeometry(QRect(20, 60, 181, 28));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 221, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numtel = new QLineEdit(groupBox);
        numtel->setObjectName("numtel");
        numtel->setGeometry(QRect(20, 120, 181, 28));
        numtel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 230, 171, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numapp = new QLineEdit(groupBox);
        numapp->setObjectName("numapp");
        numapp->setGeometry(QRect(20, 190, 181, 28));
        numapp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 300, 61, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        add = new QLineEdit(groupBox);
        add->setObjectName("add");
        add->setGeometry(QRect(20, 260, 181, 28));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 160, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 350, 161, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ss = new QLineEdit(groupBox);
        ss->setObjectName("ss");
        ss->setGeometry(QRect(190, 350, 51, 28));
        ss->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        valider = new QPushButton(groupBox);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(40, 450, 90, 29));
        valider->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(160, 450, 90, 29));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        etage = new QComboBox(groupBox);
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->setObjectName("etage");
        etage->setGeometry(QRect(90, 300, 161, 28));
        etage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 400, 51, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        prix = new QLineEdit(groupBox);
        prix->setObjectName("prix");
        prix->setGeometry(QRect(70, 400, 131, 28));
        prix->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Recherche par", nullptr));
        recherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = res->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = res->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "N\302\260 t\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = res->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "N\302\260 appartement", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = res->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = res->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Etage", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = res->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "N\302\260 de pi\303\251ce", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = res->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = res->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Tri\303\251e par", nullptr));
        tripar->setItemText(0, QCoreApplication::translate("MainWindow", "Aucun", nullptr));
        tripar->setItemText(1, QCoreApplication::translate("MainWindow", "Etage", nullptr));
        tripar->setItemText(2, QCoreApplication::translate("MainWindow", "Nombre de pi\303\251ce", nullptr));
        tripar->setItemText(3, QCoreApplication::translate("MainWindow", "Etat", nullptr));
        tripar->setItemText(4, QCoreApplication::translate("MainWindow", "Prix", nullptr));

        trier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        repar->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        repar->setItemText(1, QCoreApplication::translate("MainWindow", "Etage", nullptr));
        repar->setItemText(2, QCoreApplication::translate("MainWindow", "Nombre de pi\303\251ce", nullptr));
        repar->setItemText(3, QCoreApplication::translate("MainWindow", "Etat", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Modifier ou Supprimer", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "Exportation PDF", nullptr));
        accueil->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        fonction->setText(QCoreApplication::translate("MainWindow", "Fonctionalit\303\251s", nullptr));
        ges_emp->setText(QCoreApplication::translate("MainWindow", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("MainWindow", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("MainWindow", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("MainWindow", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("MainWindow", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("MainWindow", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter Appartement", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        id->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de t\303\251l\303\251phone", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Etage", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro d'appartement", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nombre de pi\303\251ce", nullptr));
        valider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        annuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        etage->setItemText(0, QCoreApplication::translate("MainWindow", "Ajouter \303\251tage", nullptr));
        etage->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        etage->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        etage->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        etage->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        etage->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
