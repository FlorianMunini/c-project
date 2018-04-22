#include <iostream>

#include "Noeud.h"

#include<bits/stdc++.h>
using namespace std;
int main() {

    cout << "Hello, World!" << std::endl;

    std::string expression;

    int i;
    stack<Noeud *> st,dump;


    while(expression.compare("lol")!=0){







        std::cin >> expression;

        if ((expression[0] == '*') || (expression[0] == '+') || (expression[0] == '-') || (expression[0] == '/')) {
            std::cout << "c'est un operateur : " << expression[0] << "\n";
            Noeud* no = new Noeud();
            no->setValue(expression);
            no->setType(1);
            st.push(no);
        } else if (isalpha(expression[0])) {
            std::cout << "c'est une lettre : " << expression[0]<< "\n";
        } else {
            i = 0;
            while (expression[i] != '\0') {
                if (!isdigit(expression[i])) {
                    std::cout << "error retaper\n";
                    std::cin >> expression;
                }
                i++;
            }
            std::cout << "c'est un chiffre" << expression << "\n";
            Noeud* no = new Noeud();
            no->setValue(expression);
            no->setType(0);



            st.push(no);
        }




    }

    // boucle for pour afficcher ce que contient le stack
    for(dump = st;!dump.empty(); dump.pop()){

        if(dump.top()->getType() == 0){
            printf("ce stack est un nombre\n");
            cout << dump.top()->getValue();
        }
        else{
            printf("ce stack est un opérateur\n");
            cout << dump.top()->getValue();
        }




    }






    return 0;
}