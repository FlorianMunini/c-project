//
// Created by isen on 13/04/18.
//

#include "NoeudOperateur.h"

NoeudOperateur::NoeudOperateur() {}

char NoeudOperateur::getOperateur() const {
    return operateur;
}

void NoeudOperateur::setOperateur(char operateur) {
    NoeudOperateur::operateur = operateur;
}

NoeudOperateur *NoeudOperateur::getOperateurs() const {
    return operateurs;
}

void NoeudOperateur::setOperateurs(NoeudOperateur *operateurs) {
    NoeudOperateur::operateurs = operateurs;
}

NoeudConstante *NoeudOperateur::getConstantes() const {
    return constantes;
}

void NoeudOperateur::setConstantes(NoeudConstante *constantes) {
    NoeudOperateur::constantes = constantes;
}

