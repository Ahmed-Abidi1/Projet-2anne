/********************************************************************************
** Form generated from reading UI file 'appar_fonction.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPAR_FONCTION_H
#define UI_APPAR_FONCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_appar_fonction
{
public:
    QGroupBox *groupBox;
    QTableWidget *historique;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QPushButton *play_pause;
    QPushButton *stop;
    QPushButton *mute;
    QSlider *volumeSlider;
    QGroupBox *video;
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
    QGroupBox *groupBox_3;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *total;
    QLabel *label_4;
    QLabel *label_5;
    QProgressBar *Bar_occ;
    QProgressBar *Bar_dis;
    QLabel *stat;

    void setupUi(QDialog *appar_fonction)
    {
        if (appar_fonction->objectName().isEmpty())
            appar_fonction->setObjectName("appar_fonction");
        appar_fonction->resize(1441, 612);
        appar_fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);"));
        groupBox = new QGroupBox(appar_fonction);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(240, 79, 451, 251));
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
        historique = new QTableWidget(groupBox);
        if (historique->columnCount() < 3)
            historique->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        historique->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        historique->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font;
        font.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        historique->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        historique->setObjectName("historique");
        historique->setGeometry(QRect(10, 30, 431, 211));
        historique->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        historique->setMidLineWidth(0);
        groupBox_2 = new QGroupBox(appar_fonction);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(700, 80, 731, 511));
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
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 40, 541, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        play_pause = new QPushButton(groupBox_2);
        play_pause->setObjectName("play_pause");
        play_pause->setGeometry(QRect(40, 460, 41, 31));
        play_pause->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color: rgb(0, 85, 0);"));
        stop = new QPushButton(groupBox_2);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(90, 460, 41, 31));
        stop->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color: rgb(0, 85, 0);"));
        mute = new QPushButton(groupBox_2);
        mute->setObjectName("mute");
        mute->setGeometry(QRect(550, 460, 41, 31));
        mute->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"color: rgb(0, 85, 0);"));
        volumeSlider = new QSlider(groupBox_2);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(600, 460, 81, 31));
        volumeSlider->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 125, 209);"));
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);
        video = new QGroupBox(groupBox_2);
        video->setObjectName("video");
        video->setGeometry(QRect(10, 70, 711, 381));
        video->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame = new QFrame(appar_fonction);
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
        logo->setGeometry(QRect(70, 59, 121, 91));
        accueil = new QPushButton(appar_fonction);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 30, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        fonction = new QPushButton(appar_fonction);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 30, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_3 = new QGroupBox(appar_fonction);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(240, 340, 451, 251));
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
        frame_2 = new QFrame(groupBox_3);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(10, 30, 431, 211));
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
        total->setGeometry(QRect(140, 140, 131, 31));
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
"background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        Bar_occ = new QProgressBar(frame_2);
        Bar_occ->setObjectName("Bar_occ");
        Bar_occ->setGeometry(QRect(140, 40, 131, 31));
        Bar_occ->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        Bar_occ->setValue(24);
        Bar_dis = new QProgressBar(frame_2);
        Bar_dis->setObjectName("Bar_dis");
        Bar_dis->setGeometry(QRect(140, 90, 131, 31));
        Bar_dis->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        Bar_dis->setValue(24);
        stat = new QLabel(frame_2);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(280, 30, 141, 141));
        stat->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));

        retranslateUi(appar_fonction);

        QMetaObject::connectSlotsByName(appar_fonction);
    } // setupUi

    void retranslateUi(QDialog *appar_fonction)
    {
        appar_fonction->setWindowTitle(QCoreApplication::translate("appar_fonction", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("appar_fonction", "Historique", nullptr));
        QTableWidgetItem *___qtablewidgetitem = historique->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("appar_fonction", "Date et Heure ", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = historique->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("appar_fonction", "Identifiant", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = historique->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("appar_fonction", "A_M_S", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("appar_fonction", "Video", nullptr));
        label_2->setText(QCoreApplication::translate("appar_fonction", "Cette video est comme une visite virtuelle pour vous :", nullptr));
        play_pause->setText(QString());
        stop->setText(QString());
        mute->setText(QString());
        video->setTitle(QString());
        ges_emp->setText(QCoreApplication::translate("appar_fonction", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("appar_fonction", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("appar_fonction", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("appar_fonction", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("appar_fonction", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("appar_fonction", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        accueil->setText(QCoreApplication::translate("appar_fonction", "Accueil", nullptr));
        fonction->setText(QCoreApplication::translate("appar_fonction", "Fonctionalit\303\251s", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("appar_fonction", "Statistique", nullptr));
        label_3->setText(QCoreApplication::translate("appar_fonction", "     Total", nullptr));
        total->setText(QString());
        label_4->setText(QCoreApplication::translate("appar_fonction", "   Occup\303\251", nullptr));
        label_5->setText(QCoreApplication::translate("appar_fonction", "Disponible", nullptr));
        stat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class appar_fonction: public Ui_appar_fonction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPAR_FONCTION_H
