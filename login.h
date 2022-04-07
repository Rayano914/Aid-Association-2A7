#ifndef LOGIN_H
#define LOGIN_H
#include <QString>
#include <iostream>
#include <QSqlQueryModel>


class login
{
public:
    login();
    login(QString,QString);
    ~login(){}
    void set_mdp(QString mdp){this->mdp=mdp;}
    QString get_mdp(){return mdp;}
    void set_nom_utilisateur(QString nom_utilisateur){this->nom_utilisateur=nom_utilisateur;}
    QString get_nom_utilisateur(){return nom_utilisateur;}
    void set_code(QString code){this->code=code;}
    QString get_code(){return code;}

    bool ajouterLogin(QString);
    bool modifierLogin();
    QSqlQueryModel* affichernom_utilisateur();
private:
    QString nom_utilisateur;
    QString mdp;
    QString code;
};

#endif // LOGIN_H
