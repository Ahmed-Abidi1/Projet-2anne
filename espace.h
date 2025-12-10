#ifndef ESPACE_H
#define ESPACE_H

#include <QString>
#include <QSqlQuery>
#include <QList>

class Espace
{
public:
    Espace();
    Espace(QString nom, QString sup, QString local, QString amen, QString equip, QString veg, QString sec, QString prox, QString frequ);
    
    QString getNom() const { return nom; }
    QString getSup() const { return sup; }
    QString getLocal() const { return local; }
    QString getAmen() const { return amen; }
    QString getEquip() const { return equip; }
    QString getVeg() const { return veg; }
    QString getSec() const { return sec; }
    QString getProx() const { return prox; }
    QString getFrequ() const { return frequ; }
    
    void setNom(QString nom) { this->nom = nom; }
    void setSup(QString sup) { this->sup = sup; }
    void setLocal(QString local) { this->local = local; }
    void setAmen(QString amen) { this->amen = amen; }
    void setEquip(QString equip) { this->equip = equip; }
    void setVeg(QString veg) { this->veg = veg; }
    void setSec(QString sec) { this->sec = sec; }
    void setProx(QString prox) { this->prox = prox; }
    void setFrequ(QString frequ) { this->frequ = frequ; }
    
    bool ajouter();
    bool modifier();
    bool supprimer(QString nomEspace);
    bool rechercher(QString nomEspace);
    
    static QList<Espace> rechercherTous();
    static QList<Espace> rechercherParSuperficie(QString sup);
    static QList<Espace> rechercherParSecurite(QString sec);
    static QList<Espace> rechercherParVegetation(QString veg);
    
    bool estValide() const;

private:
    QString nom;
    QString sup;
    QString local;
    QString amen;
    QString equip;
    QString veg;
    QString sec;
    QString prox;
    QString frequ;
};

#endif // ESPACE_H

