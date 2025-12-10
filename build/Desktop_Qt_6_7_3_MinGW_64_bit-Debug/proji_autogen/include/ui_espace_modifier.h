/********************************************************************************
** Form generated from reading UI file 'espace_modifier.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESPACE_MODIFIER_H
#define UI_ESPACE_MODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_espace_modifier
{
public:
    QGroupBox *groupBox_3;
    QPushButton *modifier;
    QLabel *label_8;
    QLineEdit *nom;
    QPushButton *annuler;
    QLabel *label_9;
    QLineEdit *sup;
    QLabel *label_10;
    QLineEdit *local;
    QLineEdit *amen;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *veg;
    QLineEdit *prox;
    QLineEdit *frequ;
    QLabel *label_16;
    QLineEdit *sec;
    QLineEdit *equip;

    void setupUi(QDialog *espace_modifier)
    {
        if (espace_modifier->objectName().isEmpty())
            espace_modifier->setObjectName("espace_modifier");
        espace_modifier->resize(1075, 294);
        espace_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        groupBox_3 = new QGroupBox(espace_modifier);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 20, 1051, 271));
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
        modifier->setGeometry(QRect(770, 230, 121, 29));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 50, 111, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        nom = new QLineEdit(groupBox_3);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(130, 50, 181, 28));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        annuler = new QPushButton(groupBox_3);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(910, 230, 121, 29));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(330, 50, 141, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        sup = new QLineEdit(groupBox_3);
        sup->setObjectName("sup");
        sup->setGeometry(QRect(470, 50, 181, 28));
        sup->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(680, 50, 161, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        local = new QLineEdit(groupBox_3);
        local->setObjectName("local");
        local->setGeometry(QRect(850, 50, 181, 28));
        local->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        amen = new QLineEdit(groupBox_3);
        amen->setObjectName("amen");
        amen->setGeometry(QRect(130, 110, 181, 28));
        amen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
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
        label_14->setGeometry(QRect(20, 170, 111, 20));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(330, 170, 111, 20));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        veg = new QLineEdit(groupBox_3);
        veg->setObjectName("veg");
        veg->setGeometry(QRect(850, 110, 181, 28));
        veg->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        prox = new QLineEdit(groupBox_3);
        prox->setObjectName("prox");
        prox->setGeometry(QRect(470, 170, 181, 28));
        prox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        frequ = new QLineEdit(groupBox_3);
        frequ->setObjectName("frequ");
        frequ->setGeometry(QRect(850, 170, 181, 28));
        frequ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(680, 170, 121, 20));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        sec = new QLineEdit(groupBox_3);
        sec->setObjectName("sec");
        sec->setGeometry(QRect(130, 170, 181, 28));
        sec->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        equip = new QLineEdit(groupBox_3);
        equip->setObjectName("equip");
        equip->setGeometry(QRect(470, 110, 181, 28));
        equip->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(espace_modifier);

        QMetaObject::connectSlotsByName(espace_modifier);
    } // setupUi

    void retranslateUi(QDialog *espace_modifier)
    {
        espace_modifier->setWindowTitle(QCoreApplication::translate("espace_modifier", "Dialog", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("espace_modifier", "Modifier", nullptr));
        modifier->setText(QCoreApplication::translate("espace_modifier", "Confirmer", nullptr));
        label_8->setText(QCoreApplication::translate("espace_modifier", "Nom", nullptr));
        annuler->setText(QCoreApplication::translate("espace_modifier", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("espace_modifier", "Superficie", nullptr));
        label_10->setText(QCoreApplication::translate("espace_modifier", "Localisation", nullptr));
        label_11->setText(QCoreApplication::translate("espace_modifier", "Am\303\251nagemet", nullptr));
        label_12->setText(QCoreApplication::translate("espace_modifier", "Equipement", nullptr));
        label_13->setText(QCoreApplication::translate("espace_modifier", "V\303\251g\303\251tation", nullptr));
        label_14->setText(QCoreApplication::translate("espace_modifier", "S\303\251curit\303\251", nullptr));
        label_15->setText(QCoreApplication::translate("espace_modifier", "Proximit\303\251", nullptr));
        label_16->setText(QCoreApplication::translate("espace_modifier", "Fr\303\251quentation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class espace_modifier: public Ui_espace_modifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESPACE_MODIFIER_H
