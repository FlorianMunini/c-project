//
// Created by isen on 13/04/18.
//

#include "NoeudConstante.h"


int NoeudConstante::getNumber() const {
    return number;
}

void NoeudConstante::setNumber(int number) {
    NoeudConstante::number = number;
}

NoeudOperateur *NoeudConstante::getOperateurs() const {
    return operateurs;
}

void NoeudConstante::setOperateurs(NoeudOperateur *operateurs) {
    NoeudConstante::operateurs = operateurs;
}

NoeudConstante::NoeudConstante() {}
