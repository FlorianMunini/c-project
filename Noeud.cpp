//
// Created by isen on 20/04/18.
//

#include "Noeud.h"


Noeud::Noeud() {}

Noeud *Noeud::getParent() const {
    return parent;
}

void Noeud::setParent(Noeud *parent) {
    Noeud::parent = parent;
}

Noeud *Noeud::getFilsDroit() const {
    return filsDroit;
}

void Noeud::setFilsDroit(Noeud *filsDroit) {
    Noeud::filsDroit = filsDroit;
}

Noeud *Noeud::getFilsGauche() const {
    return filsGauche;
}

void Noeud::setFilsGauche(Noeud *filsGauche) {
    Noeud::filsGauche = filsGauche;
}

const std::string &Noeud::getValue() const {
    return value;
}

void Noeud::setValue(const std::string &value) {
    Noeud::value = value;
}

int Noeud::getType() const {
    return type;
}

void Noeud::setType(int type) {
    Noeud::type = type;
}
