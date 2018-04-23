//
// Created by isen on 20/04/18.
//

#ifndef PROJETC_NOEUD_H
#define PROJETC_NOEUD_H


#include <string>

class Noeud {



protected:Noeud *parent;
protected:Noeud *filsDroit;
protected:Noeud *filsGauche;
protected: std::string value;
protected: int type;

public:
    Noeud();

    Noeud *getParent() const;

    void setParent(Noeud *parent);

    Noeud *getFilsDroit() const;

    void setFilsDroit(Noeud *filsDroit);

    Noeud *getFilsGauche() const;

    void setFilsGauche(Noeud *filsGauche);

    const std::string &getValue() const;

    void setValue(const std::string &value);

    int getType() const;

    void setType(int type);

};


#endif //PROJETC_NOEUD_H
