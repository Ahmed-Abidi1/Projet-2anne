/********************************************************************************
** Form generated from reading UI file 'vehicule_inter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULE_INTER_H
#define UI_VEHICULE_INTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_vehicule_inter
{
public:
    QFrame *frame;
    QPushButton *ges_emp;
    QPushButton *ges_mat;
    QPushButton *ges_es_vert;
    QPushButton *ges_vehic;
    QPushButton *ges_appar;
    QPushButton *deconnect;
    QLabel *logo;
    QPushButton *fonction;
    QPushButton *accueil;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_idVehicule;
    QLabel *label_2;
    QLineEdit *lineEdit_numSerie;
    QLabel *label_3;
    QLineEdit *lineEdit_marque;
    QLabel *label_4;
    QLineEdit *lineEdit_localisation;
    QLabel *label_5;
    QPushButton *validerV;
    QPushButton *annulerV;
    QComboBox *lineEdit_type;
    QLineEdit *lineEdit_proprietaire;
    QLabel *label_6;
    QLabel *label_10;
    QLineEdit *lineEdit_modele;
    QLabel *label_11;
    QComboBox *comboBoxid;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QPushButton *recherche;
    QTableWidget *tableWidgetv;
    QLabel *label_9;
    QComboBox *tripar;
    QPushButton *trier;
    QComboBox *rech_par;
    QLineEdit *rech;
    QGroupBox *groupBox_3;
    QPushButton *modifierV;
    QPushButton *supprimerV;
    QPushButton *pdf;

    void setupUi(QDialog *vehicule_inter)
    {
        if (vehicule_inter->objectName().isEmpty())
            vehicule_inter->setObjectName("vehicule_inter");
        vehicule_inter->resize(1441, 612);
        vehicule_inter->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);"));
        frame = new QFrame(vehicule_inter);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -38, 241, 671));
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
        ges_vehic->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"color: rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ges_appar = new QPushButton(frame);
        ges_appar->setObjectName("ges_appar");
        ges_appar->setGeometry(QRect(10, 450, 231, 71));
        ges_appar->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color:rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        deconnect = new QPushButton(frame);
        deconnect->setObjectName("deconnect");
        deconnect->setGeometry(QRect(10, 580, 231, 71));
        deconnect->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color: rgb(170, 0, 0);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        logo = new QLabel(frame);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(70, 59, 121, 91));
        fonction = new QPushButton(vehicule_inter);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 40, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        accueil = new QPushButton(vehicule_inter);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 40, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox = new QGroupBox(vehicule_inter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 80, 291, 511));
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
        label->setGeometry(QRect(20, 30, 191, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        lineEdit_idVehicule = new QLineEdit(groupBox);
        lineEdit_idVehicule->setObjectName("lineEdit_idVehicule");
        lineEdit_idVehicule->setGeometry(QRect(20, 50, 181, 28));
        lineEdit_idVehicule->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 221, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        lineEdit_numSerie = new QLineEdit(groupBox);
        lineEdit_numSerie->setObjectName("lineEdit_numSerie");
        lineEdit_numSerie->setGeometry(QRect(20, 100, 181, 28));
        lineEdit_numSerie->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 230, 171, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        lineEdit_marque = new QLineEdit(groupBox);
        lineEdit_marque->setObjectName("lineEdit_marque");
        lineEdit_marque->setGeometry(QRect(20, 150, 181, 28));
        lineEdit_marque->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 280, 171, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        lineEdit_localisation = new QLineEdit(groupBox);
        lineEdit_localisation->setObjectName("lineEdit_localisation");
        lineEdit_localisation->setGeometry(QRect(20, 250, 181, 28));
        lineEdit_localisation->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 130, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        validerV = new QPushButton(groupBox);
        validerV->setObjectName("validerV");
        validerV->setGeometry(QRect(20, 460, 90, 29));
        validerV->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        annulerV = new QPushButton(groupBox);
        annulerV->setObjectName("annulerV");
        annulerV->setGeometry(QRect(120, 460, 90, 29));
        annulerV->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        lineEdit_type = new QComboBox(groupBox);
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(20, 310, 181, 28));
        lineEdit_type->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(217, 217, 217);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        lineEdit_proprietaire = new QLineEdit(groupBox);
        lineEdit_proprietaire->setObjectName("lineEdit_proprietaire");
        lineEdit_proprietaire->setGeometry(QRect(20, 360, 181, 26));
        lineEdit_proprietaire->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 340, 171, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 180, 231, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        lineEdit_modele = new QLineEdit(groupBox);
        lineEdit_modele->setObjectName("lineEdit_modele");
        lineEdit_modele->setGeometry(QRect(20, 200, 181, 28));
        lineEdit_modele->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 390, 171, 20));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        comboBoxid = new QComboBox(groupBox);
        comboBoxid->setObjectName("comboBoxid");
        comboBoxid->setGeometry(QRect(20, 420, 181, 26));
        comboBoxid->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        groupBox_2 = new QGroupBox(vehicule_inter);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(540, 80, 891, 381));
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
        recherche->setGeometry(QRect(360, 40, 121, 29));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        tableWidgetv = new QTableWidget(groupBox_2);
        if (tableWidgetv->columnCount() < 7)
            tableWidgetv->setColumnCount(7);
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic")});
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidgetv->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidgetv->setObjectName("tableWidgetv");
        tableWidgetv->setGeometry(QRect(20, 81, 861, 281));
        tableWidgetv->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(490, 40, 111, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        tripar = new QComboBox(groupBox_2);
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->setObjectName("tripar");
        tripar->setGeometry(QRect(590, 40, 181, 28));
        tripar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(217, 217, 217);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(780, 40, 90, 29));
        trier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        rech_par = new QComboBox(groupBox_2);
        rech_par->addItem(QString());
        rech_par->addItem(QString());
        rech_par->addItem(QString());
        rech_par->addItem(QString());
        rech_par->setObjectName("rech_par");
        rech_par->setGeometry(QRect(140, 40, 111, 28));
        rech_par->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(217, 217, 217);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        rech = new QLineEdit(groupBox_2);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(260, 40, 91, 26));
        rech->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        groupBox_3 = new QGroupBox(vehicule_inter);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(540, 470, 891, 121));
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
        modifierV = new QPushButton(groupBox_3);
        modifierV->setObjectName("modifierV");
        modifierV->setGeometry(QRect(30, 50, 101, 29));
        modifierV->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        supprimerV = new QPushButton(groupBox_3);
        supprimerV->setObjectName("supprimerV");
        supprimerV->setGeometry(QRect(140, 50, 121, 29));
        supprimerV->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        pdf = new QPushButton(groupBox_3);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(670, 50, 201, 29));
        pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));

        retranslateUi(vehicule_inter);

        QMetaObject::connectSlotsByName(vehicule_inter);
    } // setupUi

    void retranslateUi(QDialog *vehicule_inter)
    {
        vehicule_inter->setWindowTitle(QCoreApplication::translate("vehicule_inter", "Dialog", nullptr));
        ges_emp->setText(QCoreApplication::translate("vehicule_inter", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("vehicule_inter", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("vehicule_inter", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("vehicule_inter", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("vehicule_inter", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("vehicule_inter", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        fonction->setText(QCoreApplication::translate("vehicule_inter", "Fonctionalit\303\251s", nullptr));
        accueil->setText(QCoreApplication::translate("vehicule_inter", "Accueil", nullptr));
        groupBox->setTitle(QCoreApplication::translate("vehicule_inter", "Ajouter Vehicule", nullptr));
        label->setText(QCoreApplication::translate("vehicule_inter", "Identifiant vehicule ", nullptr));
        lineEdit_idVehicule->setText(QString());
        label_2->setText(QCoreApplication::translate("vehicule_inter", "Num\303\251ro de s\303\251rie", nullptr));
        label_3->setText(QCoreApplication::translate("vehicule_inter", "Localisation", nullptr));
        label_4->setText(QCoreApplication::translate("vehicule_inter", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("vehicule_inter", "Marque", nullptr));
        validerV->setText(QCoreApplication::translate("vehicule_inter", "Valider", nullptr));
        annulerV->setText(QCoreApplication::translate("vehicule_inter", "Annuler", nullptr));
        lineEdit_type->setItemText(0, QCoreApplication::translate("vehicule_inter", "Vehicule en question", nullptr));
        lineEdit_type->setItemText(1, QCoreApplication::translate("vehicule_inter", "Voiture", nullptr));
        lineEdit_type->setItemText(2, QCoreApplication::translate("vehicule_inter", "Bus", nullptr));
        lineEdit_type->setItemText(3, QCoreApplication::translate("vehicule_inter", "Camion", nullptr));
        lineEdit_type->setItemText(4, QCoreApplication::translate("vehicule_inter", "Moto", nullptr));
        lineEdit_type->setItemText(5, QCoreApplication::translate("vehicule_inter", "Bicyclette", nullptr));

        label_6->setText(QCoreApplication::translate("vehicule_inter", "Proprietaire", nullptr));
        label_10->setText(QCoreApplication::translate("vehicule_inter", "Modele", nullptr));
        label_11->setText(QCoreApplication::translate("vehicule_inter", " Id Employe", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("vehicule_inter", "Recherche", nullptr));
        label_7->setText(QCoreApplication::translate("vehicule_inter", "Recherche par", nullptr));
        recherche->setText(QCoreApplication::translate("vehicule_inter", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetv->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("vehicule_inter", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetv->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("vehicule_inter", "N\302\260 S\303\251rie", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetv->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("vehicule_inter", "Localisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetv->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("vehicule_inter", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetv->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("vehicule_inter", "Marque", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetv->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("vehicule_inter", "Mod\303\251le", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetv->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("vehicule_inter", "Propri\303\251taire", nullptr));
        label_9->setText(QCoreApplication::translate("vehicule_inter", "Tri\303\251e par", nullptr));
        tripar->setItemText(0, QCoreApplication::translate("vehicule_inter", "Aucun", nullptr));
        tripar->setItemText(1, QCoreApplication::translate("vehicule_inter", "Marque ", nullptr));
        tripar->setItemText(2, QCoreApplication::translate("vehicule_inter", "Mod\303\251le", nullptr));
        tripar->setItemText(3, QCoreApplication::translate("vehicule_inter", "Type", nullptr));

        trier->setText(QCoreApplication::translate("vehicule_inter", "Trier", nullptr));
        rech_par->setItemText(0, QCoreApplication::translate("vehicule_inter", "Aucun", nullptr));
        rech_par->setItemText(1, QCoreApplication::translate("vehicule_inter", "Marque ", nullptr));
        rech_par->setItemText(2, QCoreApplication::translate("vehicule_inter", "Mod\303\251le", nullptr));
        rech_par->setItemText(3, QCoreApplication::translate("vehicule_inter", "Type", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("vehicule_inter", "Modifier ou Supprimer", nullptr));
        modifierV->setText(QCoreApplication::translate("vehicule_inter", "Modifier", nullptr));
        supprimerV->setText(QCoreApplication::translate("vehicule_inter", "Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("vehicule_inter", "Exportation PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vehicule_inter: public Ui_vehicule_inter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULE_INTER_H
