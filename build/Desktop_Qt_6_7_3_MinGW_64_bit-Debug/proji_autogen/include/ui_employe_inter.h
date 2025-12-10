/********************************************************************************
** Form generated from reading UI file 'employe_inter.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_INTER_H
#define UI_EMPLOYE_INTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employe_inter
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;
    QPushButton *faceIdButton;

    void setupUi(QDialog *employe_inter)
    {
        if (employe_inter->objectName().isEmpty())
            employe_inter->setObjectName("employe_inter");
        employe_inter->resize(681, 517);
        employe_inter->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        centralwidget = new QWidget(employe_inter);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(10, 10, 659, 497));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic")});
        font.setPointSize(12);
        font.setWeight(QFont::Black);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));

        verticalLayout->addWidget(usernameLineEdit);

        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 900 9pt \"Franklin Gothic\";"));
        passwordLineEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(passwordLineEdit);

        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));

        verticalLayout->addWidget(loginButton);

        faceIdButton = new QPushButton(centralwidget);
        faceIdButton->setObjectName("faceIdButton");
        faceIdButton->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));

        verticalLayout->addWidget(faceIdButton);


        retranslateUi(employe_inter);

        QMetaObject::connectSlotsByName(employe_inter);
    } // setupUi

    void retranslateUi(QDialog *employe_inter)
    {
        employe_inter->setWindowTitle(QCoreApplication::translate("employe_inter", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("employe_inter", "<html><head/><body><p><span style=\" font-size:20pt;\">Acc\303\250s Employ\303\251</span></p></body></html>", nullptr));
        usernameLineEdit->setPlaceholderText(QCoreApplication::translate("employe_inter", "Nom d'utilisateur", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("employe_inter", "Mot de passe", nullptr));
        loginButton->setText(QCoreApplication::translate("employe_inter", "Se connecter", nullptr));
        faceIdButton->setText(QCoreApplication::translate("employe_inter", "Simuler Face ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employe_inter: public Ui_employe_inter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_INTER_H
