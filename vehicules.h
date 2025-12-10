#ifndef VEHICULES_H
#define VEHICULES_H

#include <QString>
#include <QSqlQueryModel>
#include <QTableWidgetItem>


class Vehicules
{
private:
    int id_vehicule;
    QString num_serie;
    QString localisation;
    QString type;
    QString marque;
    QString modele;
    QString proprietaire;
    int id_employe;  // Correspond à ID_EMPLOYE dans VEHICULE

public:
    Vehicules();
    Vehicules(int id_vehicule, const QString &num_serie, const QString &localisation,
              const QString &type, const QString &marque, const QString &modele,
              const QString &proprietaire, int id_employe);

    // Getters
    int getIdVehicule() const { return id_vehicule; }
    QString getNumSerie() const { return num_serie; }
    QString getLocalisation() const { return localisation; }
    QString getType() const { return type; }
    QString getMarque() const { return marque; }
    QString getModele() const { return modele; }
    QString getProprietaire() const { return proprietaire; }
    int getIdEmploye() const { return id_employe; }

    // Setters
    void setIdVehicule(int id) { id_vehicule = id; }
    void setNumSerie(const QString &ns) { num_serie = ns; }
    void setLocalisation(const QString &loc) { localisation = loc; }
    void setType(const QString &t) { type = t; }
    void setMarque(const QString &m) { marque = m; }
    void setModele(const QString &mod) { modele = mod; }
    void setProprietaire(const QString &p) { proprietaire = p; }
    void setIdEmploye(int id) { id_employe = id; }

    // CRUD
    bool ajouter();
    QSqlQueryModel* afficher();
    static bool supprimer(int idVehicule);
    bool modifier();
};

#endif // VEHICULES_H
