#include "vehicules.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

Vehicules::Vehicules()
    : id_vehicule(0), num_serie(""), localisation(""), type(""),
      marque(""), modele(""), proprietaire(""), id_employe(0)
{
}

Vehicules::Vehicules(int id_vehicule, const QString &num_serie, const QString &localisation,
                     const QString &type, const QString &marque, const QString &modele,
                     const QString &proprietaire, int id_employe)
{
    this->id_vehicule = id_vehicule;
    this->num_serie = num_serie;
    this->localisation = localisation;
    this->type = type;
    this->marque = marque;
    this->modele = modele;
    this->proprietaire = proprietaire;
    this->id_employe = id_employe;
}

// =================== AJOUTER ===================
bool Vehicules::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO VEHICULE (ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE) "
                  "VALUES (:id, :num_serie, :localisation, :type, :marque, :modele, :proprietaire, :id_employe)");

    query.bindValue(":id", id_vehicule);
    query.bindValue(":num_serie", num_serie);
    query.bindValue(":localisation", localisation);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":proprietaire", proprietaire);
    query.bindValue(":id_employe", id_employe);

    if (!query.exec()) {
        qDebug() << "Erreur ajout:" << query.lastError().text();
        return false;
    }
    return true;
}

// =================== AFFICHER ===================
QSqlQueryModel* Vehicules::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT ID_VEHICULE, NUM_SERIE, LOCALISATION, TYPE, MARQUE, MODELE, PROPRIETAIRE, ID_EMPLOYE "
                    "FROM VEHICULE ORDER BY ID_VEHICULE");

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Num Série");
    model->setHeaderData(2, Qt::Horizontal, "Localisation");
    model->setHeaderData(3, Qt::Horizontal, "Type");
    model->setHeaderData(4, Qt::Horizontal, "Marque");
    model->setHeaderData(5, Qt::Horizontal, "Modèle");
    model->setHeaderData(6, Qt::Horizontal, "Propriétaire");
    model->setHeaderData(7, Qt::Horizontal, "ID Employé");

    return model;
}

// =================== SUPPRIMER ===================
bool Vehicules::supprimer(int idVehicule)
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULE WHERE ID_VEHICULE = :id");
    query.bindValue(":id", idVehicule);

    if (!query.exec()) {
        qDebug() << "Erreur suppression:" << query.lastError().text();
        return false;
    }
    return true;
}

// =================== MODIFIER ===================
bool Vehicules::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE VEHICULE SET "
                  "NUM_SERIE = :num_serie, "
                  "LOCALISATION = :localisation, "
                  "TYPE = :type, "
                  "MARQUE = :marque, "
                  "MODELE = :modele, "
                  "PROPRIETAIRE = :proprietaire, "
                  "ID_EMPLOYE = :id_employe "
                  "WHERE ID_VEHICULE = :id");

    query.bindValue(":id", id_vehicule);
    query.bindValue(":num_serie", num_serie);
    query.bindValue(":localisation", localisation);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":modele", modele);
    query.bindValue(":proprietaire", proprietaire);
    query.bindValue(":id_employe", id_employe);

    if (!query.exec()) {
        qDebug() << "Erreur modification:" << query.lastError().text();
        return false;
    }
    return true;
}
