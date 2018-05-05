//
// Created by isen on 04/05/18.
//

#include "Terme.h"


const std::string &Terme::getValue() const {
    return value;
}

void Terme::setValue(const std::string &value) {
    Terme::value = value;
}

int Terme::getType() const {
    return type;
}

void Terme::setType(int type) {
    Terme::type = type;
}
