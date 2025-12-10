#include "employe.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

// Constante pour le nom de la table corrigé (Schéma + Nom)
#define TABLE_EMPLOYE "SYSTEM.EMPLOYE"

Employe::Employe() {}

Employe::Employe(int id, QString nom, QString prenom, QString email, QString tel, QString poste, double salaire)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->tel = tel;
    this->poste = poste;
    this->salaire = salaire;
}

int Employe::getId() { return id; }
QString Employe::getNom() { return nom; }
QString Employe::getPrenom() { return prenom; }
QString Employe::getEmail() { return email; }
QString Employe::getTel() { return tel; }
QString Employe::getPoste() { return poste; }
double Employe::getSalaire() { return salaire; }

bool Employe::existe(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM " TABLE_EMPLOYE " WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    qDebug() << "Erreur vérification existence:" << query.lastError().text();
    return false;
}

bool Employe::ajouter()
{
    if (existe(this->id)) {
        qDebug() << "Erreur: L'ID" << this->id << "existe déjà (vérification locale).";
        return false;
    }

    QSqlQuery query;
    // Utilisation de QString::arg() pour contourner les problèmes ODBC/Oracle
    QString queryString = QString("INSERT INTO " TABLE_EMPLOYE " (ID_EMPLOYE, NOM, PRENOM, EMAIL, NUM_TEL, POSTE, SALAIRE) "
                                  "VALUES (%1, '%2', '%3', '%4', '%5', '%6', %7)")
                              .arg(id)
                              .arg(nom)
                              .arg(prenom)
                              .arg(email)
                              .arg(tel)
                              .arg(poste)
                              .arg(salaire);

    if(query.exec(queryString)) {
        qDebug() << "Employé ajouté avec succès";
        return true;
    } else {
        qDebug() << "Erreur ajout employé:" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Employe::afficher(const QString& filtre, const QString& tri)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = "SELECT ID_EMPLOYE, NOM, PRENOM, EMAIL, NUM_TEL, POSTE, SALAIRE FROM " TABLE_EMPLOYE;

    if (!filtre.isEmpty()) {
        query += " WHERE ID_EMPLOYE = " + filtre;
    }

    if (!tri.isEmpty()) {
        query += " ORDER BY " + tri;
    }

    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur affichage:" << model->lastError().text();
    }

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prénom");
    model->setHeaderData(3, Qt::Horizontal, "Email");
    model->setHeaderData(4, Qt::Horizontal, "Téléphone");
    model->setHeaderData(5, Qt::Horizontal, "Poste");
    model->setHeaderData(6, Qt::Horizontal, "Salaire");

    return model;
}

bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM " TABLE_EMPLOYE " WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if(query.exec()) {
        qDebug() << "Employé supprimé avec succès";
        return true;
    } else {
        qDebug() << "Erreur suppression:" << query.lastError().text();
        return false;
    }
}

bool Employe::modifier(int id)
{
    QSqlQuery query;
    QString queryString = QString("UPDATE " TABLE_EMPLOYE " SET NOM='%1', PRENOM='%2', EMAIL='%3', NUM_TEL='%4', POSTE='%5', SALAIRE=%6 WHERE ID_EMPLOYE=%7")
                              .arg(nom)
                              .arg(prenom)
                              .arg(email)
                              .arg(tel)
                              .arg(poste)
                              .arg(salaire)
                              .arg(id);

    if(query.exec(queryString)) {
        qDebug() << "Employé modifié avec succès";
        return true;
    } else {
        qDebug() << "Erreur modification:" << query.lastError().text();
        return false;
    }
}
