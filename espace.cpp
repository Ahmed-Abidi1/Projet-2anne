#include "espace.h"
#include <QSqlError>
#include <QDebug>

Espace::Espace()
    : nom(""), sup(""),  local(""), amen(""), equip(""), veg(""), sec(""), prox(""), frequ("")
{
}

Espace::Espace(QString nom, QString sup, QString local, QString amen, QString equip, QString veg, QString sec, QString prox, QString frequ)
    : nom(nom), sup(sup), local(local), amen(amen), equip(equip), veg(veg), sec(sec), prox(prox), frequ(frequ)
{
}

bool Espace::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ESPACE (NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION) "
                  "VALUES (:nom, :sup, :local, :amen, :equip, :veg, :sec, :prox, :frequ)");

    query.bindValue(":nom", nom);
    query.bindValue(":sup", sup);
    query.bindValue(":local", local);
    query.bindValue(":amen", amen);
    query.bindValue(":equip", equip);
    query.bindValue(":veg", veg);
    query.bindValue(":sec", sec);
    query.bindValue(":prox", prox);
    query.bindValue(":frequ", frequ);

    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de l'ajout:" << query.lastError().text();
        return false;
    }
}

bool Espace::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE ESPACE SET SUPERFICIE=:sup, LOCALISATION=:local, AMENAGEMENT=:amen, "
                  "EQUIPEMENT=:equip, VEGETATION=:veg, SECURITE=:sec, PROXIMITE=:prox, FREQUENTATION=:frequ WHERE NOM_ESPACE=:nom");

    query.bindValue(":nom", nom);
    query.bindValue(":sup", sup);
    query.bindValue(":local", local);
    query.bindValue(":amen", amen);
    query.bindValue(":equip", equip);
    query.bindValue(":veg", veg);
    query.bindValue(":sec", sec);
    query.bindValue(":prox", prox);
    query.bindValue(":frequ", frequ);

    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }
}

bool Espace::supprimer(QString nomEspace)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ESPACE WHERE NOM_ESPACE=:nom");
    query.bindValue(":nom", nomEspace);

    if (query.exec())
    {
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
}

    bool Espace::rechercher(QString nomEspace)
{
    QSqlQuery query;
    query.prepare("SELECT NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION "
                  "FROM ESPACE WHERE NOM_ESPACE=:nom");
    query.bindValue(":nom", nomEspace);

    if (query.exec() && query.next())
    {
        nom = query.value(0).toString();
        sup = query.value(1).toString();
        local = query.value(2).toString();
        amen = query.value(3).toString();
        equip = query.value(4).toString();
        veg = query.value(5).toString();
        sec = query.value(6).toString();
        prox = query.value(7).toString();
        frequ = query.value(8).toString();

        return true;
    }
    else
    {
        qDebug() << "Espace non trouvé ou erreur:" << query.lastError().text();
        return false;
    }
}

bool Espace::estValide() const
{
    if (nom.isEmpty() || sup.isEmpty() || local.isEmpty() || amen.isEmpty() || equip.isEmpty())
    {
        return false;
    }

    return true;
}

QList<Espace> Espace::rechercherTous()
{
    QList<Espace> espaces;
    QSqlQuery query("SELECT NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION FROM ESPACE");

    while (query.next())
    {
        Espace esp;
        esp.setNom(query.value(0).toString());
        esp.setSup(query.value(1).toString());
        esp.setLocal(query.value(2).toString());
        esp.setAmen(query.value(3).toString());
        esp.setEquip(query.value(4).toString());
        esp.setVeg(query.value(5).toString());
        esp.setSec(query.value(6).toString());
        esp.setProx(query.value(7).toString());
        esp.setFrequ(query.value(8).toString());
        espaces.append(esp);
    }

    return espaces;
}

QList<Espace> Espace::rechercherParSuperficie(QString sup)
{
    QList<Espace> espaces;
    QSqlQuery query;
    query.prepare("SELECT NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION "
                  "FROM ESPACE WHERE SUPERFICIE=:sup");
    query.bindValue(":sup", sup);

    if (query.exec())
    {
        while (query.next())
        {
            Espace esp;
            esp.setNom(query.value(0).toString());
            esp.setSup(query.value(1).toString());
            esp.setLocal(query.value(2).toString());
            esp.setAmen(query.value(3).toString());
            esp.setEquip(query.value(4).toString());
            esp.setVeg(query.value(5).toString());
            esp.setSec(query.value(6).toString());
            esp.setProx(query.value(7).toString());
            esp.setFrequ(query.value(8).toString());
            espaces.append(esp);
        }
    }

    return espaces;
}

QList<Espace> Espace::rechercherParVegetation(QString veg)
{
    QList<Espace> espaces;
    QSqlQuery query;
    query.prepare("SELECT NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION "
                  "FROM ESPACE WHERE VEGETATION=:veg");
    query.bindValue(":veg", veg);

    if (query.exec())
    {
        while (query.next())
        {
            Espace esp;
            esp.setNom(query.value(0).toString());
            esp.setSup(query.value(1).toString());
            esp.setLocal(query.value(2).toString());
            esp.setAmen(query.value(3).toString());
            esp.setEquip(query.value(4).toString());
            esp.setVeg(query.value(5).toString());
            esp.setSec(query.value(6).toString());
            esp.setProx(query.value(7).toString());
            esp.setFrequ(query.value(8).toString());
            espaces.append(esp);
        }
    }

    return espaces;
}

QList<Espace> Espace::rechercherParSecurite(QString sec)
{
    QList<Espace> espaces;
    QSqlQuery query;
    query.prepare("SELECT NOM_ESPACE, SUPERFICIE, LOCALISATION, AMENAGEMENT, EQUIPEMENT, VEGETATION, SECURITE, PROXIMITE, FREQUENTATION "
                  "FROM ESPACE WHERE SECURITE=:sec");
    query.bindValue(":sec", sec);

    if (query.exec())
    {
        while (query.next())
        {
            Espace esp;
            esp.setNom(query.value(0).toString());
            esp.setSup(query.value(1).toString());
            esp.setLocal(query.value(2).toString());
            esp.setAmen(query.value(3).toString());
            esp.setEquip(query.value(4).toString());
            esp.setVeg(query.value(5).toString());
            esp.setSec(query.value(6).toString());
            esp.setProx(query.value(7).toString());
            esp.setFrequ(query.value(8).toString());
            espaces.append(esp);
        }
    }

    return espaces;
}

