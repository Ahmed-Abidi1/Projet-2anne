/********************************************************************************
** Form generated from reading UI file 'vehicule_fonc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VEHICULE_FONC_H
#define UI_VEHICULE_FONC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_vehicule_fonc
{
public:
    QPushButton *fonction;
    QPushButton *accueil;
    QGroupBox *groupBox;
    QGroupBox *groupBox_3;
    QLineEdit *lets_chat;
    QPushButton *envoyer;
    QTextEdit *rep;
    QPushButton *computer;
    QGroupBox *groupBox_2;
    QLabel *QR3;
    QLabel *QR1;
    QLabel *QR2;
    QFrame *frame;
    QPushButton *ges_emp;
    QPushButton *ges_mat;
    QPushButton *ges_es_vert;
    QPushButton *ges_vehic;
    QPushButton *ges_appar;
    QPushButton *deconnect;
    QLabel *logo;
    QGroupBox *groupBox_4;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *total;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *voiture;
    QProgressBar *moto;
    QLabel *stat;
    QProgressBar *camion;
    QProgressBar *bus;
    QProgressBar *bis;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *vehicule_fonc)
    {
        if (vehicule_fonc->objectName().isEmpty())
            vehicule_fonc->setObjectName("vehicule_fonc");
        vehicule_fonc->resize(1441, 612);
        vehicule_fonc->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        fonction = new QPushButton(vehicule_fonc);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 43, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        accueil = new QPushButton(vehicule_fonc);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 43, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox = new QGroupBox(vehicule_fonc);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(250, 92, 521, 501));
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
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 20, 501, 471));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        lets_chat = new QLineEdit(groupBox_3);
        lets_chat->setObjectName("lets_chat");
        lets_chat->setGeometry(QRect(10, 420, 431, 41));
        lets_chat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        envoyer = new QPushButton(groupBox_3);
        envoyer->setObjectName("envoyer");
        envoyer->setGeometry(QRect(450, 420, 41, 41));
        envoyer->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        rep = new QTextEdit(groupBox_3);
        rep->setObjectName("rep");
        rep->setGeometry(QRect(60, 30, 421, 381));
        rep->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 255, 255);\n"
"}"));
        computer = new QPushButton(groupBox_3);
        computer->setObjectName("computer");
        computer->setGeometry(QRect(10, 30, 41, 41));
        computer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(vehicule_fonc);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(780, 90, 651, 251));
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
        QR3 = new QLabel(groupBox_2);
        QR3->setObjectName("QR3");
        QR3->setGeometry(QRect(460, 40, 171, 191));
        QR3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 125, 209);"));
        QR1 = new QLabel(groupBox_2);
        QR1->setObjectName("QR1");
        QR1->setGeometry(QRect(20, 40, 171, 191));
        QR1->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 125, 209);"));
        QR2 = new QLabel(groupBox_2);
        QR2->setObjectName("QR2");
        QR2->setGeometry(QRect(230, 40, 171, 191));
        QR2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 125, 209);"));
        frame = new QFrame(vehicule_fonc);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-10, -37, 241, 671));
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
        groupBox_4 = new QGroupBox(vehicule_fonc);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(780, 350, 651, 241));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        frame_2 = new QFrame(groupBox_4);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 30, 631, 201));
        frame_2->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(52, 52, 52);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        total = new QLabel(frame_2);
        total->setObjectName("total");
        total->setGeometry(QRect(140, 140, 101, 31));
        total->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(52, 52, 52);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 40, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 90, 121, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(237, 28, 36);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        voiture = new QProgressBar(frame_2);
        voiture->setObjectName("voiture");
        voiture->setGeometry(QRect(140, 40, 101, 31));
        voiture->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        voiture->setValue(24);
        moto = new QProgressBar(frame_2);
        moto->setObjectName("moto");
        moto->setGeometry(QRect(140, 90, 101, 31));
        moto->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(237, 28, 36);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        moto->setValue(24);
        stat = new QLabel(frame_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(250, 40, 141, 131));
        camion = new QProgressBar(frame_2);
        camion->setObjectName("camion");
        camion->setGeometry(QRect(400, 40, 101, 31));
        camion->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        camion->setValue(24);
        bus = new QProgressBar(frame_2);
        bus->setObjectName("bus");
        bus->setGeometry(QRect(400, 90, 101, 31));
        bus->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(93, 135, 143);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        bus->setValue(24);
        bis = new QProgressBar(frame_2);
        bis->setObjectName("bis");
        bis->setGeometry(QRect(400, 140, 101, 31));
        bis->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(254, 182, 52);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        bis->setValue(24);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(510, 40, 111, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(510, 90, 111, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(93, 135, 143);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(510, 140, 111, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(254, 182, 52);\n"
"font: 900 12pt \"Franklin Gothic\";"));

        retranslateUi(vehicule_fonc);

        QMetaObject::connectSlotsByName(vehicule_fonc);
    } // setupUi

    void retranslateUi(QDialog *vehicule_fonc)
    {
        vehicule_fonc->setWindowTitle(QCoreApplication::translate("vehicule_fonc", "Dialog", nullptr));
        fonction->setText(QCoreApplication::translate("vehicule_fonc", "Fonctionalit\303\251s", nullptr));
        accueil->setText(QCoreApplication::translate("vehicule_fonc", "Accueil", nullptr));
        groupBox->setTitle(QCoreApplication::translate("vehicule_fonc", "Chatbot", nullptr));
        groupBox_3->setTitle(QString());
        envoyer->setText(QString());
        computer->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("vehicule_fonc", "QR Code", nullptr));
        QR3->setText(QString());
        QR1->setText(QString());
        QR2->setText(QString());
        ges_emp->setText(QCoreApplication::translate("vehicule_fonc", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("vehicule_fonc", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("vehicule_fonc", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("vehicule_fonc", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("vehicule_fonc", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("vehicule_fonc", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("vehicule_fonc", "Statistique", nullptr));
        label_3->setText(QCoreApplication::translate("vehicule_fonc", "     Total", nullptr));
        total->setText(QString());
        label_4->setText(QCoreApplication::translate("vehicule_fonc", "    Voiture", nullptr));
        label_5->setText(QCoreApplication::translate("vehicule_fonc", "     Moto", nullptr));
        stat->setText(QString());
        label_2->setText(QCoreApplication::translate("vehicule_fonc", "  Camion", nullptr));
        label_6->setText(QCoreApplication::translate("vehicule_fonc", "     Bus", nullptr));
        label_7->setText(QCoreApplication::translate("vehicule_fonc", "Bicyclette", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vehicule_fonc: public Ui_vehicule_fonc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VEHICULE_FONC_H
