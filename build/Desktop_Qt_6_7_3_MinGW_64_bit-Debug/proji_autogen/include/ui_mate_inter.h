/********************************************************************************
** Form generated from reading UI file 'mate_inter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATE_INTER_H
#define UI_MATE_INTER_H

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

class Ui_mate_inter
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
    QPushButton *accueil;
    QPushButton *fonction;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *numtel;
    QLabel *label_3;
    QLineEdit *numapp;
    QLineEdit *add;
    QLabel *label_5;
    QPushButton *valider;
    QPushButton *annuler;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QLineEdit *idrech;
    QPushButton *recherche;
    QTableWidget *tableWidget;
    QLabel *label_9;
    QComboBox *tripar;
    QPushButton *trier;
    QGroupBox *groupBox_3;
    QPushButton *modifier;
    QLabel *label_8;
    QLineEdit *idmodsup;
    QPushButton *supprimer;
    QPushButton *exportToPDF;

    void setupUi(QDialog *mate_inter)
    {
        if (mate_inter->objectName().isEmpty())
            mate_inter->setObjectName("mate_inter");
        mate_inter->resize(1441, 612);
        mate_inter->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame = new QFrame(mate_inter);
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
        ges_mat->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"color: rgb(255, 191, 62);\n"
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
        logo->setGeometry(QRect(80, 59, 121, 91));
        accueil = new QPushButton(mate_inter);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 51, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        fonction = new QPushButton(mate_inter);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 51, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox = new QGroupBox(mate_inter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 90, 251, 501));
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
        label->setGeometry(QRect(20, 40, 111, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        id = new QLineEdit(groupBox);
        id->setObjectName("id");
        id->setGeometry(QRect(20, 70, 181, 28));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 110, 221, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numtel = new QLineEdit(groupBox);
        numtel->setObjectName("numtel");
        numtel->setGeometry(QRect(20, 140, 181, 28));
        numtel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 250, 171, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numapp = new QLineEdit(groupBox);
        numapp->setObjectName("numapp");
        numapp->setGeometry(QRect(20, 210, 181, 28));
        numapp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        add = new QLineEdit(groupBox);
        add->setObjectName("add");
        add->setGeometry(QRect(20, 280, 181, 28));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 180, 191, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        valider = new QPushButton(groupBox);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(20, 450, 90, 29));
        valider->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(120, 450, 90, 29));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_2 = new QGroupBox(mate_inter);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(500, 90, 931, 381));
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
        label_7->setGeometry(QRect(10, 40, 131, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        idrech = new QLineEdit(groupBox_2);
        idrech->setObjectName("idrech");
        idrech->setGeometry(QRect(140, 40, 161, 28));
        idrech->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        recherche = new QPushButton(groupBox_2);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(310, 40, 121, 29));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 81, 891, 281));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        tableWidget->horizontalHeader()->setDefaultSectionSize(155);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(470, 40, 111, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        tripar = new QComboBox(groupBox_2);
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->setObjectName("tripar");
        tripar->setGeometry(QRect(580, 40, 181, 28));
        tripar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(790, 40, 90, 29));
        trier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_3 = new QGroupBox(mate_inter);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(500, 480, 931, 111));
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
        label_8->setGeometry(QRect(10, 50, 131, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        idmodsup = new QLineEdit(groupBox_3);
        idmodsup->setObjectName("idmodsup");
        idmodsup->setGeometry(QRect(140, 50, 181, 28));
        idmodsup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(440, 50, 121, 29));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        exportToPDF = new QPushButton(groupBox_3);
        exportToPDF->setObjectName("exportToPDF");
        exportToPDF->setGeometry(QRect(710, 50, 201, 29));
        exportToPDF->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));

        retranslateUi(mate_inter);

        QMetaObject::connectSlotsByName(mate_inter);
    } // setupUi

    void retranslateUi(QDialog *mate_inter)
    {
        mate_inter->setWindowTitle(QCoreApplication::translate("mate_inter", "Dialog", nullptr));
        ges_emp->setText(QCoreApplication::translate("mate_inter", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("mate_inter", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("mate_inter", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("mate_inter", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("mate_inter", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("mate_inter", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        accueil->setText(QCoreApplication::translate("mate_inter", "Accueil", nullptr));
        fonction->setText(QCoreApplication::translate("mate_inter", "Fonctionalit\303\251s", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mate_inter", "Ajouter matriele", nullptr));
        label->setText(QCoreApplication::translate("mate_inter", "Nom", nullptr));
        id->setText(QString());
        label_2->setText(QCoreApplication::translate("mate_inter", "Type", nullptr));
        label_3->setText(QCoreApplication::translate("mate_inter", "Quantit\303\251", nullptr));
        label_5->setText(QCoreApplication::translate("mate_inter", "Etat", nullptr));
        valider->setText(QCoreApplication::translate("mate_inter", "Valider", nullptr));
        annuler->setText(QCoreApplication::translate("mate_inter", "Annuler", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("mate_inter", "Recherche", nullptr));
        label_7->setText(QCoreApplication::translate("mate_inter", "Code A Barre", nullptr));
#if QT_CONFIG(whatsthis)
        idrech->setWhatsThis(QCoreApplication::translate("mate_inter", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        recherche->setText(QCoreApplication::translate("mate_inter", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mate_inter", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mate_inter", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("mate_inter", "Etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("mate_inter", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("mate_inter", "Code a barre", nullptr));
        label_9->setText(QCoreApplication::translate("mate_inter", "Tri\303\251e par", nullptr));
        tripar->setItemText(0, QCoreApplication::translate("mate_inter", "Etat", nullptr));
        tripar->setItemText(1, QCoreApplication::translate("mate_inter", "Type", nullptr));
        tripar->setItemText(2, QCoreApplication::translate("mate_inter", "Quantit\303\251", nullptr));
        tripar->setItemText(3, QCoreApplication::translate("mate_inter", "nom", nullptr));

        trier->setText(QCoreApplication::translate("mate_inter", "Trier", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("mate_inter", "Modifier ou Supprimer", nullptr));
        modifier->setText(QCoreApplication::translate("mate_inter", "Modifier", nullptr));
        label_8->setText(QCoreApplication::translate("mate_inter", "Code A Barre", nullptr));
        supprimer->setText(QCoreApplication::translate("mate_inter", "Supprimer", nullptr));
        exportToPDF->setText(QCoreApplication::translate("mate_inter", "Exportation PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mate_inter: public Ui_mate_inter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATE_INTER_H
