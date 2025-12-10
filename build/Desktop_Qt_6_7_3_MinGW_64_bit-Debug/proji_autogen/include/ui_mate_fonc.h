/********************************************************************************
** Form generated from reading UI file 'mate_fonc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATE_FONC_H
#define UI_MATE_FONC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mate_fonc
{
public:
    QPushButton *accueil;
    QFrame *frame;
    QPushButton *ges_emp;
    QPushButton *ges_mat;
    QPushButton *ges_es_vert;
    QPushButton *ges_vehic;
    QPushButton *ges_appar;
    QPushButton *deconnect;
    QLabel *logo;
    QPushButton *fonction;
    QGroupBox *groupBox_5;
    QLabel *label_10;
    QTableWidget *tableWidget_3;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *stat;
    QPushButton *supprimer2;

    void setupUi(QDialog *mate_fonc)
    {
        if (mate_fonc->objectName().isEmpty())
            mate_fonc->setObjectName("mate_fonc");
        mate_fonc->resize(1441, 612);
        mate_fonc->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        accueil = new QPushButton(mate_fonc);
        accueil->setObjectName("accueil");
        accueil->setGeometry(QRect(250, 10, 101, 29));
        accueil->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        frame = new QFrame(mate_fonc);
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
        logo->setGeometry(QRect(70, 59, 121, 91));
        fonction = new QPushButton(mate_fonc);
        fonction->setObjectName("fonction");
        fonction->setGeometry(QRect(370, 10, 171, 29));
        fonction->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_5 = new QGroupBox(mate_fonc);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(250, 50, 1171, 551));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px; \n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 40, 541, 20));
        tableWidget_3 = new QTableWidget(groupBox_5);
        if (tableWidget_3->columnCount() < 2)
            tableWidget_3->setColumnCount(2);
        QFont font;
        font.setPointSize(12);
        font.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setPointSize(12);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(10, 30, 991, 221));
        tableWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 6pt \"Segoe UI\";\n"
"font: 7pt \"Segoe UI\";\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        tableWidget_3->setMidLineWidth(0);
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(157);
        tableWidget_3->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_3->horizontalHeader()->setStretchLastSection(true);
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 260, 1151, 281));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget = new QWidget(groupBox_4);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(470, 240, 31, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stat = new QLabel(groupBox_4);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(10, 30, 1131, 241));
        supprimer2 = new QPushButton(groupBox_5);
        supprimer2->setObjectName("supprimer2");
        supprimer2->setGeometry(QRect(1020, 120, 131, 31));
        supprimer2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));

        retranslateUi(mate_fonc);

        QMetaObject::connectSlotsByName(mate_fonc);
    } // setupUi

    void retranslateUi(QDialog *mate_fonc)
    {
        mate_fonc->setWindowTitle(QCoreApplication::translate("mate_fonc", "Dialog", nullptr));
        accueil->setText(QCoreApplication::translate("mate_fonc", "Accueil", nullptr));
        ges_emp->setText(QCoreApplication::translate("mate_fonc", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("mate_fonc", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("mate_fonc", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("mate_fonc", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("mate_fonc", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("mate_fonc", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        fonction->setText(QCoreApplication::translate("mate_fonc", "Fonctionalit\303\251s", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("mate_fonc", "Notification", nullptr));
        label_10->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("mate_fonc", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("mate_fonc", "Notifications", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("mate_fonc", "Statestique", nullptr));
        stat->setText(QString());
        supprimer2->setText(QCoreApplication::translate("mate_fonc", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mate_fonc: public Ui_mate_fonc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATE_FONC_H
