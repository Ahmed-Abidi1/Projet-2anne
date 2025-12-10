#ifndef APPARTEMENT_H
#define APPARTEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QList>

class Appartement
{
public:
    Appartement();
    Appartement(QString id, QString numtel, QString numapp, QString adresse, QString etage, QString nbrPieces);
    
    QString getId() const { return id; }
    QString getNumTel() const { return numtel; }
    QString getNumApp() const { return numapp; }
    QString getAdresse() const { return adresse; }
    QString getEtage() const { return etage; }
    QString getNbrPieces() const { return nbrPieces; }
    QString getEtat() const { return etat; }
    int getPrix() const { return prix; }
    
    void setId(QString id) { this->id = id; }
    void setNumTel(QString numtel) { this->numtel = numtel; }
    void setNumApp(QString numapp) { this->numapp = numapp; }
    void setAdresse(QString adresse) { this->adresse = adresse; }
    void setEtage(QString etage) { this->etage = etage; }
    void setNbrPieces(QString nbrPieces) { this->nbrPieces = nbrPieces; }
    void setEtat(QString etat) { this->etat = etat; }
    void setPrix(int prix) { this->prix = prix; }
    
    bool ajouter();
    bool modifier();
    bool supprimer(QString idAppartement);
    bool rechercher(QString idAppartement);
    
    static QList<Appartement> rechercherTous();
    static QList<Appartement> rechercherParEtage(QString etage);
    static QList<Appartement> rechercherParNbrPieces(QString nbrPieces);
    static QList<Appartement> rechercherParEtat(QString etat);
    
    bool estValide() const;

private:
    QString id;
    QString numtel;
    QString numapp;
    QString adresse;
    QString etage;
    QString nbrPieces;
    QString etat;
    int prix;
};

#endif // APPARTEMENT_H

