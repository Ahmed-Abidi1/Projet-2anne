/********************************************************************************
** Form generated from reading UI file 'employe_fonc.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_FONC_H
#define UI_EMPLOYE_FONC_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employe_fonc
{
public:
    QWidget *centralWidget;
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
    QLineEdit *id2;
    QPushButton *supprimer;
    QPushButton *export_2;
    QFrame *frame;
    QPushButton *ges_emp;
    QPushButton *ges_mat;
    QPushButton *ges_es_vert;
    QPushButton *ges_vehic;
    QPushButton *ges_appar;
    QPushButton *deconnect;
    QLabel *logo;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *id;
    QLabel *label_2;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *valider;
    QPushButton *annuler;
    QLineEdit *mail;
    QLineEdit *tel;
    QLabel *label_10;
    QLineEdit *poste;
    QLabel *label_11;
    QLineEdit *salaire;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Layout;
    QFrame *chartContainer;

    void setupUi(QDialog *employe_fonc)
    {
        if (employe_fonc->objectName().isEmpty())
            employe_fonc->setObjectName("employe_fonc");
        employe_fonc->resize(1441, 612);
        employe_fonc->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 217, 217);"));
        centralWidget = new QWidget(employe_fonc);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(-70, -40, 1561, 671));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(610, 50, 891, 311));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px;\n"
"padding: 5px;\n"
"border-color: rgb(255, 191, 62);\n"
"}"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 40, 111, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        idrech = new QLineEdit(groupBox_2);
        idrech->setObjectName("idrech");
        idrech->setGeometry(QRect(132, 40, 161, 28));
        idrech->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        recherche = new QPushButton(groupBox_2);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(300, 40, 121, 29));
        recherche->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        tableWidget = new QTableWidget(groupBox_2);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QFont font;
        font.setFamilies({QString::fromUtf8("Franklin Gothic")});
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 81, 861, 221));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(440, 40, 111, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        tripar = new QComboBox(groupBox_2);
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->addItem(QString());
        tripar->setObjectName("tripar");
        tripar->setGeometry(QRect(540, 40, 181, 28));
        tripar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        trier = new QPushButton(groupBox_2);
        trier->setObjectName("trier");
        trier->setGeometry(QRect(780, 40, 90, 29));
        trier->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(610, 370, 891, 121));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px;\n"
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
        label_8->setGeometry(QRect(10, 50, 111, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        id2 = new QLineEdit(groupBox_3);
        id2->setObjectName("id2");
        id2->setGeometry(QRect(130, 50, 181, 28));
        id2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(450, 50, 121, 29));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        export_2 = new QPushButton(groupBox_3);
        export_2->setObjectName("export_2");
        export_2->setGeometry(QRect(670, 50, 201, 29));
        export_2->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(60, 0, 241, 671));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        ges_emp = new QPushButton(frame);
        ges_emp->setObjectName("ges_emp");
        ges_emp->setGeometry(QRect(10, 170, 231, 71));
        ges_emp->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 211, 211);\n"
"color: rgb(255, 191, 62);\n"
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(310, 110, 291, 511));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox\n"
"{\n"
"background-color: rgb(0, 125, 209);\n"
"color:  rgb(255, 191, 62);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"border: 2px solid ;\n"
"border-radius: 12px;\n"
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
        id->setGeometry(QRect(20, 60, 181, 28));
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);\n"
""));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 221, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(20, 120, 181, 28));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        prenom = new QLineEdit(groupBox);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(20, 180, 181, 28));
        prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 280, 171, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 160, 231, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 330, 141, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        valider = new QPushButton(groupBox);
        valider->setObjectName("valider");
        valider->setGeometry(QRect(20, 470, 90, 29));
        valider->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(140, 470, 90, 29));
        annuler->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 179, 122);\n"
"font: 900 12pt \"Franklin Gothic\";\n"
"color: rgb(0, 85, 0);"));
        mail = new QLineEdit(groupBox);
        mail->setObjectName("mail");
        mail->setGeometry(QRect(20, 300, 181, 28));
        mail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        tel = new QLineEdit(groupBox);
        tel->setObjectName("tel");
        tel->setGeometry(QRect(20, 360, 181, 28));
        tel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 390, 141, 31));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        poste = new QLineEdit(groupBox);
        poste->setObjectName("poste");
        poste->setGeometry(QRect(20, 420, 181, 28));
        poste->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 220, 171, 20));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(0, 125, 209);\n"
"font: 900 12pt \"Franklin Gothic\";"));
        salaire = new QLineEdit(groupBox);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(20, 240, 181, 28));
        salaire->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 900 9pt \"Franklin Gothic\";\n"
"color: rgb(0, 0, 0);"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(610, 500, 891, 141));
        Layout = new QVBoxLayout(verticalLayoutWidget);
        Layout->setObjectName("Layout");
        Layout->setContentsMargins(0, 0, 0, 0);
        chartContainer = new QFrame(verticalLayoutWidget);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setEnabled(true);
        chartContainer->setFrameShape(QFrame::Shape::StyledPanel);
        chartContainer->setFrameShadow(QFrame::Shadow::Raised);

        Layout->addWidget(chartContainer);


        retranslateUi(employe_fonc);

        QMetaObject::connectSlotsByName(employe_fonc);
    } // setupUi

    void retranslateUi(QDialog *employe_fonc)
    {
        employe_fonc->setWindowTitle(QCoreApplication::translate("employe_fonc", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("employe_fonc", "Recherche", nullptr));
        label_7->setText(QCoreApplication::translate("employe_fonc", "Identifiant", nullptr));
#if QT_CONFIG(whatsthis)
        idrech->setWhatsThis(QCoreApplication::translate("employe_fonc", "<html><head/><body><p>iden</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        recherche->setText(QCoreApplication::translate("employe_fonc", "Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("employe_fonc", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("employe_fonc", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("employe_fonc", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("employe_fonc", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("employe_fonc", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("employe_fonc", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("employe_fonc", "Salaire", nullptr));
        label_9->setText(QCoreApplication::translate("employe_fonc", "Tri\303\251e par", nullptr));
        tripar->setItemText(0, QCoreApplication::translate("employe_fonc", "Aucun", nullptr));
        tripar->setItemText(1, QCoreApplication::translate("employe_fonc", "Poste", nullptr));
        tripar->setItemText(2, QCoreApplication::translate("employe_fonc", "Salaire", nullptr));

        trier->setText(QCoreApplication::translate("employe_fonc", "Trier", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("employe_fonc", "Modifier ou Supprimer", nullptr));
        modifier->setText(QCoreApplication::translate("employe_fonc", "Modifier", nullptr));
        label_8->setText(QCoreApplication::translate("employe_fonc", "Identifiant", nullptr));
        supprimer->setText(QCoreApplication::translate("employe_fonc", "Supprimer", nullptr));
        export_2->setText(QCoreApplication::translate("employe_fonc", "Exportation PDF", nullptr));
        ges_emp->setText(QCoreApplication::translate("employe_fonc", "Gestion Employ\303\251", nullptr));
        ges_mat->setText(QCoreApplication::translate("employe_fonc", "Gestion Mat\303\251riels", nullptr));
        ges_es_vert->setText(QCoreApplication::translate("employe_fonc", "Gestion Espaces Verts", nullptr));
        ges_vehic->setText(QCoreApplication::translate("employe_fonc", "Gestion V\303\251hicule", nullptr));
        ges_appar->setText(QCoreApplication::translate("employe_fonc", "Gestion Appartements", nullptr));
        deconnect->setText(QCoreApplication::translate("employe_fonc", "Se D\303\251connecter", nullptr));
        logo->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("employe_fonc", "Ajouter Employ\303\251", nullptr));
        label->setText(QCoreApplication::translate("employe_fonc", "Identifiant", nullptr));
        id->setText(QString());
        label_2->setText(QCoreApplication::translate("employe_fonc", "Nom", nullptr));
        label_4->setText(QCoreApplication::translate("employe_fonc", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("employe_fonc", "Pr\303\251nom", nullptr));
        label_6->setText(QCoreApplication::translate("employe_fonc", "T\303\251l\303\251phone", nullptr));
        valider->setText(QCoreApplication::translate("employe_fonc", "Valider", nullptr));
        annuler->setText(QCoreApplication::translate("employe_fonc", "Annuler", nullptr));
        label_10->setText(QCoreApplication::translate("employe_fonc", "Poste", nullptr));
        label_11->setText(QCoreApplication::translate("employe_fonc", "Salaire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employe_fonc: public Ui_employe_fonc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_FONC_H
