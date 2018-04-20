//
// Created by isen on 13/04/18.
//

#ifndef PROJETC_NOEUDOPERATEUR_H
#define PROJETC_NOEUDOPERATEUR_H


#include "NoeudConstante.h"
#include "Noeud.h"

class NoeudConstante;
class NoeudOperateur: public Noeud {

protected: char operateur ;
protected: NoeudOperateur* operateurs;
protected: NoeudConstante* constantes;

public:
    NoeudOperateur();

    char getOperateur() const;

    void setOperateur(char operateur);

    NoeudOperateur *getOperateurs() const;

    void setOperateurs(NoeudOperateur *operateurs);

    NoeudConstante *getConstantes() const;

    void setConstantes(NoeudConstante *constantes);

};


#endif //PROJETC_NOEUDOPERATEUR_H
