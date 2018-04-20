//
// Created by isen on 13/04/18.
//

#ifndef PROJETC_NOEUDCONSTANTE_H
#define PROJETC_NOEUDCONSTANTE_H


#include "NoeudOperateur.h"
class NoeudOperateur;
class NoeudConstante: public Noeud {
protected: int number;
protected: NoeudOperateur* operateurs;
public:
    NoeudConstante();

public:
    int getNumber() const;

    void setNumber(int number);

    NoeudOperateur *getOperateurs() const;

    void setOperateurs(NoeudOperateur *operateurs);

};




#endif //PROJETC_NOEUDCONSTANTE_H
