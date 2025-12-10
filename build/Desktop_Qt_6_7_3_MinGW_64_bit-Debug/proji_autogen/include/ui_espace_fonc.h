/********************************************************************************
** Form generated from reading UI file 'espace_fonc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESPACE_FONC_H
#define UI_ESPACE_FONC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Espace_fonc
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
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLineEdit *id;
    QLabel *label_6;
    QLineEdit *espace_vert;
    QLabel *label_7;
    QPushButton *envoyer;
    QDateEdit *date;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLineEdit *lon;
    QLineEdit *lat;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *recherche2;
    QWidget *map_2;

    void setupUi(QDialog *Espace_fonc)
    {
        if (Espace_fonc->objectName().isEmpty())
            Espace_fonc->setObjectName("Espace_fonc");
        Espace_fonc->resize(1441, 612);
        Espace_fonc->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        frame = new QFrame(Espace_fonc);
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
        pushButton_2 = new QPushButton(Espace_fonc);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(370, 40, 171, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        pushButton = new QPushButton(Espace_fonc);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 40, 101, 29));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_2 = new QGroupBox(Espace_fonc);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(240, 90, 491, 501));
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
        textEdit_3 = new QTextEdit(groupBox_2);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(10, 50, 471, 441));
        textEdit_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 49, 471, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(Espace_fonc);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(740, 470, 691, 121));
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
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 40, 121, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        id = new QLineEdit(groupBox_3);
        id->setObjectName("id");
        id->setGeometry(QRect(10, 70, 161, 28));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(200, 40, 181, 21));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        espace_vert = new QLineEdit(groupBox_3);
        espace_vert->setObjectName("espace_vert");
        espace_vert->setGeometry(QRect(200, 70, 161, 28));
        espace_vert->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 40, 161, 21));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        envoyer = new QPushButton(groupBox_3);
        envoyer->setObjectName("envoyer");
        envoyer->setGeometry(QRect(590, 70, 90, 29));
        envoyer->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        date = new QDateEdit(groupBox_3);
        date->setObjectName("date");
        date->setGeometry(QRect(390, 70, 161, 31));
        date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        groupBox = new QGroupBox(Espace_fonc);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(740, 90, 691, 361));
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
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 541, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        lon = new QLineEdit(groupBox);
        lon->setObjectName("lon");
        lon->setGeometry(QRect(370, 60, 161, 28));
        lon->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        lat = new QLineEdit(groupBox);
        lat->setObjectName("lat");
        lat->setGeometry(QRect(100, 60, 161, 28));
        lat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 91, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(270, 60, 101, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
""));
        recherche2 = new QPushButton(groupBox);
        recherche2->setObjectName("recherche2");
        recherche2->setGeometry(QRect(550, 60, 121, 29));
        recherche2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        map_2 = new QWidget(groupBox);
        map_2->setObjectName("map_2");
        map_2->setGeometry(QRect(10, 100, 671, 251));
        map_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(62, 62, 62);\n"
""));

        retranslateUi(Espace_fonc);

        QMetaObject::connectSlotsByName(Espace_fonc);
    } // setupUi

    void retranslateUi(QDialog *Espace_fonc)
    {
        Espace_fonc->setWindowTitle(QCoreApplication::translate("Espace_fonc", "Dialog", nullptr));
        ges_emp->setText(QCoreApplication::translate("Espace_fonc", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("Espace_fonc", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("Espace_fonc", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("Espace_fonc", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("Espace_fonc", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("Espace_fonc", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("Espace_fonc", "Fonctionalit\303\251s", nullptr));
        pushButton->setText(QCoreApplication::translate("Espace_fonc", "Accueil", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Espace_fonc", "Statistiques", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Espace_fonc", "Envoi automatique du SMS ", nullptr));
        label_5->setText(QCoreApplication::translate("Espace_fonc", "Id emply\303\251", nullptr));
#if QT_CONFIG(whatsthis)
        id->setWhatsThis(QCoreApplication::translate("Espace_fonc", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_6->setText(QCoreApplication::translate("Espace_fonc", "Nom d'espace vert", nullptr));
#if QT_CONFIG(whatsthis)
        espace_vert->setWhatsThis(QCoreApplication::translate("Espace_fonc", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_7->setText(QCoreApplication::translate("Espace_fonc", "Date de maintenance", nullptr));
        envoyer->setText(QCoreApplication::translate("Espace_fonc", "Valider", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Espace_fonc", "G\303\251olocalisation", nullptr));
        label_2->setText(QCoreApplication::translate("Espace_fonc", "Enter les coordonn\303\251es GPS ", nullptr));
#if QT_CONFIG(whatsthis)
        lon->setWhatsThis(QCoreApplication::translate("Espace_fonc", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(whatsthis)
        lat->setWhatsThis(QCoreApplication::translate("Espace_fonc", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_3->setText(QCoreApplication::translate("Espace_fonc", "Latitude", nullptr));
        label_4->setText(QCoreApplication::translate("Espace_fonc", "Longitude", nullptr));
        recherche2->setText(QCoreApplication::translate("Espace_fonc", "Rechercher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Espace_fonc: public Ui_Espace_fonc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESPACE_FONC_H
