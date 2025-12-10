#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int id, QString nom, QString prenom, QString email, QString tel, QString poste, double salaire);

    int getId();
    QString getNom();
    QString getPrenom();
    QString getEmail();
    QString getTel();
    QString getPoste();
    double getSalaire();

    bool ajouter();
    // SIGNATURE MISE À JOUR pour le tri et le filtrage
    QSqlQueryModel* afficher(const QString& filtre = "", const QString& tri = "");
    bool supprimer(int id);
    bool modifier(int id);
    bool existe(int id); // Déclaration de la fonction de vérification d'ID

private:
    int id;
    QString nom, prenom, email, poste, tel;
    double salaire;
};

#endif // EMPLOYE_H
