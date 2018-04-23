#include <iostream>

#include "Noeud.h"

#include<bits/stdc++.h>
using namespace std;


Noeud * createTree (string expression) {
    int i;
    stack<Noeud *> st,dump;
    Noeud *Pere, *FilsGauche, *FilsDroit;

    while(expression.compare("lol")!=0){

        std::cin >> expression;

        if ((expression[0] == '*') || (expression[0] == '+') || (expression[0] == '-') || (expression[0] == '/')) {
            std::cout << "c'est un operateur : " << expression[0] << std::endl;
            Pere = new Noeud();
            Pere->setValue(expression);
            Pere->setType(1);
            st.push(Pere);
        } else if (isalpha(expression[0])) {
            std::cout << "c'est une lettre : " << expression[0]<< std::endl;
        } else {
            i = 0;
            while (expression[i] != '\0') {
                if (!isdigit(expression[i])) {
                    std::cout << "error retaper\n";
                    std::cin >> expression;
                }
                i++;
            }
            cout << "c'est un chiffre" << expression << std::endl;
            Pere = new Noeud();
            Pere->setValue(expression);
            Pere->setType(0);
            st.push(Pere);

            // Pop two top nodes
            FilsDroit = st.top(); // Store top
            st.pop();      // Remove top
            FilsGauche = st.top();
            st.pop();

            //  make them children
            Pere->setFilsDroit(FilsDroit);
            Pere->setFilsGauche(FilsGauche);

            // Add this subexpression to stack
            st.push(Pere);
        }
    }
    // boucle for pour afficcher ce que contient le stack
    for(dump = st;!dump.empty(); dump.pop()){

        if(dump.top()->getType() == 0){
            cout << "ce stack est un nombre" << std::endl;
            cout << dump.top()->getValue();
        }
        else{
            cout << "ce stack est un opérateur" << std::endl;
            cout << dump.top()->getValue();
        }
    }
    Pere=st.top();
    st.pop();
    return Pere;
}


int main() {

    cout << "Entrez votre expression en écriture polonaise inversé" << std::endl;

    std::string expression;
    expression = "ab+ef*g*-";
    Noeud* n = createTree(expression);

    return 0;
}