#include <iostream>
#include <string>
#include "Noeud.h"
#include <fstream>

#include<bits/stdc++.h>
using namespace std;


float ParcoursInfixe (Noeud * Courant) {
    float gauche;
    float droit;
    float result;
    if (Courant->getType() == 0) {
        return stof(Courant->getValue());
    } else {
        gauche = ParcoursInfixe(Courant->getFilsGauche());
        droit = ParcoursInfixe(Courant->getFilsDroit());
        if (Courant->getValue().compare("+") == 0) {
            result = gauche + droit;
        } else if (Courant->getValue().compare("-") == 0) {
            result = gauche - droit;
        } else if (Courant->getValue().compare("*") == 0) {
            result = gauche * droit;

        } else if (Courant->getValue().compare("/") == 0) {

            result = gauche / droit;
        }
        return result;
    }
}


Noeud * createTree () {
    int i;
    stack<Noeud *> st,dump;
    Noeud *Pere, *FilsGauche, *FilsDroit;
    float result;
    string Gauche;
    string Droite;
    float opGauche;
    float opDroite;
    string expression;
    ofstream myfile ("../logArbre.txt");
    int previous = -88;

    while(expression.compare("lol")!=0){

        cin >> expression;

        if (((expression[0] == '*') || (expression[0] == '+') || (expression[0] == '-') || (expression[0] == '/')) && (expression[1]=='\0')) {
            cout << "c'est un operateur : " << expression[0];
            cout << endl;



            if(previous == 0){

                Pere = new Noeud();
                Pere->setValue(expression);
                Pere->setType(1);


                if(!st.empty()){

                    FilsDroit = st.top(); // Store top
                    st.pop();


                    FilsGauche = st.top();
                    st.pop();

                }
                Pere->setFilsDroit(FilsDroit);
                Pere->setFilsGauche(FilsGauche);

                if (myfile.is_open())
                {
                    myfile << "Fils Droit : " << FilsDroit->getValue() << "\n";
                    myfile << "Fils Gauche : " << FilsGauche->getValue() << "\n";


                }
                else cout << "Unable to open file";

                // Add this subexpression to stack
                st.push(Pere);
                previous = 0;
            }
            else{
                Pere = new Noeud();
                Pere->setValue(expression);
                Pere->setType(1);


                // Pop two top nodes
                if(!st.empty()){

                    FilsDroit = st.top(); // Store top
                    st.pop();


                    FilsGauche = st.top();
                    st.pop();

                }
                else{
                    FilsDroit = NULL;
                    FilsGauche = NULL;
                }
                if ((FilsDroit!=NULL) && (FilsGauche!=NULL)){
                    cout << "Pere: " << Pere->getValue() << endl;
                    Droite=FilsDroit->getValue();
                    Gauche=FilsGauche->getValue();
                    cout << "Gauche: " << Gauche << " Droite: " << Droite << endl;


                }
                //  make them children
                Pere->setFilsDroit(FilsDroit);
                Pere->setFilsGauche(FilsGauche);

                if (myfile.is_open())
                {
                    myfile << "Pere : " << Pere->getValue() << "\n";
                    myfile << "Fils Gauche : " << FilsGauche->getValue() << "\n";
                    myfile << "Fils Droit : " << FilsDroit->getValue() << "\n";



                }
                else cout << "Unable to open file";

                // Add this subexpression to stack
                st.push(Pere);
                previous = 0;
            }



        } else if (isalpha(expression[0]) && (expression[1]=='\0')) {
            cout << "c'est une lettre : " << expression[0];
            cout << endl;
        }else if (isdigit(expression[0])) {
            i = 0;
            previous = 1;
            while (expression[i] != '\0') {
                if (isdigit(expression[i])) {
                    cout << "c'est un chiffre : " << expression;
                    cout << endl;
                }

                i++;

            }
            // Ajout dans l'arbre
            Pere = new Noeud();
            Pere->setValue(expression);
            Pere->setType(0);
            st.push(Pere);

        }

        else if (expression[0]=='-' && isdigit(expression[1])) {
            i = 0;
            previous = 1;
            while (expression[i] != '\0') {
                if (expression[0] == '-' && isdigit(expression[i])) {
                    cout << "c'est un chiffre : " << expression;
                    cout << endl;
                }

                i++;

            }

            // Ajout dans l'arbre
            Pere = new Noeud();
            Pere->setValue(expression);
            Pere->setType(0);
            st.push(Pere);




        } else{
            cout << "error retaper";
            cout << endl;
        }






    }
    myfile.close();
    // boucle for pour afficcher ce que contient le stack
    for(dump = st;!dump.empty(); dump.pop()){

        if(dump.top()->getType() == 0){
            cout << "ce stack est un nombre : ";
            cout << dump.top()->getValue();
            cout << endl;
        }
        else{
            cout << "ce stack est un opérateur : ";
            cout << dump.top()->getValue();
            cout << endl;
        }
    }
    Pere=st.top();
    st.pop();
    return Pere;
}


int main() {
    float result;
    cout << "Entrez votre expression en écriture polonaise inversé" << endl;

    string expression;
    expression = "5+4*2*-";
    Noeud* n = createTree();
    result = ParcoursInfixe(n);
    printf("le resultat est: %f",result);


    return 0;
}