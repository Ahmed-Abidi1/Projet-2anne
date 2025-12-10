/********************************************************************************
** Form generated from reading UI file 'espace_inter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESPACE_INTER_H
#define UI_ESPACE_INTER_H

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

class Ui_espace_inter
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
    QGroupBox *groupBox_3;
    QPushButton *modifier;
    QLineEdit *nommodsup;
    QPushButton *supprimer;
    QPushButton *pdf;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QPushButton *recherche;
    QTableWidget *res;
    QLabel *label_9;
    QComboBox *tripar;
    QPushButton *trier;
    QLabel *label;
    QComboBox *repar;
    QLineEdit *rech;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLineEdit *nom;
    QLabel *label_2;
    QLineEdit *sup;
    QLabel *label_3;
    QLineEdit *local;
    QLabel *label_4;
    QLineEdit *amen;
    QLabel *label_5;
    QPushButton *valider;
    QPushButton *annuler;
    QLineEdit *equip;
    QLabel *label_6;

    void setupUi(QDialog *espace_inter)
    {
        if (espace_inter->objectName().isEmpty())
            espace_inter->setObjectName("espace_inter");
        espace_inter->resize(1441, 612);
        espace_inter->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame = new QFrame(espace_inter);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -39, 241, 671));
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
        ges_es_vert->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"color: rgb(255, 191, 62);\n"
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
        groupBox_3 = new QGroupBox(espace_inter);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(490, 480, 941, 111));
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
        nommodsup = new QLineEdit(groupBox_3);
        nommodsup->setObjectName("nommodsup");
        nommodsup->setGeometry(QRect(100, 50, 181, 28));
        nommodsup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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
        pdf->setGeometry(QRect(720, 50, 201, 29));
        pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 50, 71, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        pushButton_2 = new QPushButton(espace_inter);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 53, 171, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_2 = new QGroupBox(espace_inter);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(490, 90, 941, 381));
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
        recherche = new QPushButton(groupBox_2);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(360, 40, 121, 29));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        res = new QTableWidget(groupBox_2);
        if (res->columnCount() < 9)
            res->setColumnCount(9);
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic")});
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        res->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        res->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        res->setObjectName("res");
        res->setGeometry(QRect(10, 81, 921, 281));
        res->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(510, 40, 111, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        tripar = new QComboBox(groupBox_2);
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->setObjectName("tripar");
        tripar->setGeometry(QRect(620, 40, 181, 28));
        tripar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(820, 40, 90, 29));
        trier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 151, 20));
        label->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        repar = new QComboBox(groupBox_2);
        repar->addItem(QString());
        repar->addItem(QString());
        repar->addItem(QString());
        repar->addItem(QString());
        repar->setObjectName("repar");
        repar->setGeometry(QRect(130, 40, 111, 28));
        repar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        rech = new QLineEdit(groupBox_2);
        rech->setObjectName("rech");
        rech->setGeometry(QRect(250, 40, 101, 28));
        rech->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(espace_inter);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 53, 101, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox = new QGroupBox(espace_inter);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 90, 241, 501));
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
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(20, 70, 181, 28));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 110, 181, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        sup = new QLineEdit(groupBox);
        sup->setObjectName("sup");
        sup->setGeometry(QRect(20, 140, 181, 28));
        sup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 250, 171, 20));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        local = new QLineEdit(groupBox);
        local->setObjectName("local");
        local->setGeometry(QRect(20, 210, 181, 28));
        local->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 320, 171, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        amen = new QLineEdit(groupBox);
        amen->setObjectName("amen");
        amen->setGeometry(QRect(20, 280, 181, 28));
        amen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 180, 181, 20));
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
        equip = new QLineEdit(groupBox);
        equip->setObjectName("equip");
        equip->setGeometry(QRect(20, 350, 181, 28));
        equip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 40, 91, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));

        retranslateUi(espace_inter);

        QMetaObject::connectSlotsByName(espace_inter);
    } // setupUi

    void retranslateUi(QDialog *espace_inter)
    {
        espace_inter->setWindowTitle(QCoreApplication::translate("espace_inter", "Dialog", nullptr));
        ges_emp->setText(QCoreApplication::translate("espace_inter", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("espace_inter", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("espace_inter", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("espace_inter", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("espace_inter", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("espace_inter", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("espace_inter", "Modifier ou Supprimer", nullptr));
        modifier->setText(QCoreApplication::translate("espace_inter", "Modifier", nullptr));
        supprimer->setText(QCoreApplication::translate("espace_inter", "Supprimer", nullptr));
        pdf->setText(QCoreApplication::translate("espace_inter", "Exportation PDF", nullptr));
        label_7->setText(QCoreApplication::translate("espace_inter", "Nom", nullptr));
        pushButton_2->setText(QCoreApplication::translate("espace_inter", "Fonctionalit\303\251s", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("espace_inter", "Recherche", nullptr));
        recherche->setText(QCoreApplication::translate("espace_inter", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = res->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("espace_inter", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = res->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("espace_inter", "Superficie", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = res->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("espace_inter", "Localisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = res->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("espace_inter", "Am\303\251nagemet", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = res->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("espace_inter", "Equipement", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = res->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("espace_inter", "V\303\251g\303\251tation", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = res->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("espace_inter", "S\303\251curit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = res->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("espace_inter", "Proximit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = res->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("espace_inter", "Fr\303\251quentation", nullptr));
        label_9->setText(QCoreApplication::translate("espace_inter", "Tri\303\251e par", nullptr));
        tripar->setItemText(0, QCoreApplication::translate("espace_inter", "Aucun", nullptr));
        tripar->setItemText(1, QCoreApplication::translate("espace_inter", "Superficie", nullptr));
        tripar->setItemText(2, QCoreApplication::translate("espace_inter", "V\303\251g\303\251tation", nullptr));
        tripar->setItemText(3, QCoreApplication::translate("espace_inter", "S\303\251curit\303\251", nullptr));

        trier->setText(QCoreApplication::translate("espace_inter", "Trier", nullptr));
        label->setText(QCoreApplication::translate("espace_inter", "Recherche par", nullptr));
        repar->setItemText(0, QCoreApplication::translate("espace_inter", "Aucun", nullptr));
        repar->setItemText(1, QCoreApplication::translate("espace_inter", "Superficie", nullptr));
        repar->setItemText(2, QCoreApplication::translate("espace_inter", "V\303\251g\303\251tation", nullptr));
        repar->setItemText(3, QCoreApplication::translate("espace_inter", "S\303\251curit\303\251", nullptr));

        pushButton->setText(QCoreApplication::translate("espace_inter", "Accueil", nullptr));
        groupBox->setTitle(QCoreApplication::translate("espace_inter", "Ajouter un espace vert", nullptr));
        nom->setText(QString());
        label_2->setText(QCoreApplication::translate("espace_inter", "Superficie", nullptr));
        label_3->setText(QCoreApplication::translate("espace_inter", "Am\303\251nagemet", nullptr));
        label_4->setText(QCoreApplication::translate("espace_inter", "Equipement", nullptr));
        label_5->setText(QCoreApplication::translate("espace_inter", "Localisation", nullptr));
        valider->setText(QCoreApplication::translate("espace_inter", "Valider", nullptr));
        annuler->setText(QCoreApplication::translate("espace_inter", "Annuler", nullptr));
        label_6->setText(QCoreApplication::translate("espace_inter", "Nom", nullptr));
    } // retranslateUi

};

namespace Ui {
    class espace_inter: public Ui_espace_inter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESPACE_INTER_H
