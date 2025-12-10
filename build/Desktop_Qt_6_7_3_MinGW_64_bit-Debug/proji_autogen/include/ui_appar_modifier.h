/********************************************************************************
** Form generated from reading UI file 'appar_modifier.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPAR_MODIFIER_H
#define UI_APPAR_MODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_appar_modifier
{
public:
    QGroupBox *groupBox_3;
    QPushButton *modifier;
    QLabel *label_8;
    QLineEdit *id;
    QPushButton *annuler;
    QLabel *label_9;
    QLineEdit *numtel;
    QLabel *label_10;
    QLineEdit *numapp;
    QLineEdit *add;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *ss;
    QLineEdit *prix;
    QComboBox *etage;
    QCheckBox *checkBox;

    void setupUi(QDialog *appar_modifier)
    {
        if (appar_modifier->objectName().isEmpty())
            appar_modifier->setObjectName("appar_modifier");
        appar_modifier->resize(1075, 269);
        appar_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        groupBox_3 = new QGroupBox(appar_modifier);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 20, 1051, 231));
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
        modifier->setGeometry(QRect(770, 190, 121, 29));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 50, 111, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        id = new QLineEdit(groupBox_3);
        id->setObjectName("id");
        id->setGeometry(QRect(130, 50, 181, 28));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        annuler = new QPushButton(groupBox_3);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(910, 190, 121, 29));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(330, 50, 141, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numtel = new QLineEdit(groupBox_3);
        numtel->setObjectName("numtel");
        numtel->setGeometry(QRect(470, 50, 181, 28));
        numtel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(680, 50, 161, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        numapp = new QLineEdit(groupBox_3);
        numapp->setObjectName("numapp");
        numapp->setGeometry(QRect(850, 50, 181, 28));
        numapp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        add = new QLineEdit(groupBox_3);
        add->setObjectName("add");
        add->setGeometry(QRect(130, 110, 181, 28));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 110, 111, 20));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(330, 110, 111, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(680, 110, 121, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 180, 111, 20));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(330, 180, 111, 20));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        ss = new QLineEdit(groupBox_3);
        ss->setObjectName("ss");
        ss->setGeometry(QRect(850, 110, 181, 28));
        ss->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        prix = new QLineEdit(groupBox_3);
        prix->setObjectName("prix");
        prix->setGeometry(QRect(470, 170, 181, 28));
        prix->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        etage = new QComboBox(groupBox_3);
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->addItem(QString());
        etage->setObjectName("etage");
        etage->setGeometry(QRect(470, 110, 181, 28));
        etage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(130, 180, 141, 25));
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));

        retranslateUi(appar_modifier);

        QMetaObject::connectSlotsByName(appar_modifier);
    } // setupUi

    void retranslateUi(QDialog *appar_modifier)
    {
        appar_modifier->setWindowTitle(QCoreApplication::translate("appar_modifier", "Dialog", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("appar_modifier", "Modifier", nullptr));
        modifier->setText(QCoreApplication::translate("appar_modifier", "Confirmer", nullptr));
        label_8->setText(QCoreApplication::translate("appar_modifier", "Identifiant", nullptr));
        annuler->setText(QCoreApplication::translate("appar_modifier", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("appar_modifier", "N\302\260 t\303\251l\303\251phone", nullptr));
        label_10->setText(QCoreApplication::translate("appar_modifier", "N\302\260 appartement", nullptr));
        label_11->setText(QCoreApplication::translate("appar_modifier", "Adresse", nullptr));
        label_12->setText(QCoreApplication::translate("appar_modifier", "Etage", nullptr));
        label_13->setText(QCoreApplication::translate("appar_modifier", "N\302\260 de pi\303\251ce", nullptr));
        label_14->setText(QCoreApplication::translate("appar_modifier", "Etat", nullptr));
        label_15->setText(QCoreApplication::translate("appar_modifier", "Prix", nullptr));
        etage->setItemText(0, QCoreApplication::translate("appar_modifier", "Ajouter \303\251tage", nullptr));
        etage->setItemText(1, QCoreApplication::translate("appar_modifier", "1", nullptr));
        etage->setItemText(2, QCoreApplication::translate("appar_modifier", "2", nullptr));
        etage->setItemText(3, QCoreApplication::translate("appar_modifier", "3", nullptr));
        etage->setItemText(4, QCoreApplication::translate("appar_modifier", "4", nullptr));
        etage->setItemText(5, QCoreApplication::translate("appar_modifier", "5", nullptr));

        checkBox->setText(QCoreApplication::translate("appar_modifier", "Occup\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class appar_modifier: public Ui_appar_modifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPAR_MODIFIER_H
