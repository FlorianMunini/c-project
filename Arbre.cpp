//
// Created by isen on 13/04/18.
//

#include <cstdio>
#include <iostream>
#include "Arbre.h"
#include "Noeud.h"
#include "NoeudConstante.h"

int Arbre::lireExpression(std::string expression,int index) {

    int i = 0;
    int previous = 88;
    Noeud *root = NULL;
    Noeud *current;
        for(i=expression.back();i>0;i--){


            // printf("%c",expression[i]);
            if(expression[i]=='('){
                // std::cout>> "" << std::endl;
              //  printf("parenthese ouvrante ");
            }
            else if(expression[i]==')'){
               // printf("parenthese fermante ");
                previous = 0;
            }
            else if((expression[i]=='*')||(expression[i]=='+')||(expression[i]=='-')||(expression[i]=='/')){
                //printf("operateur ");
                if(previous == 1 ){
                    if(root == NULL){
                        root = new NoeudOperateur();
                        root->setValue(std::to_string(expression[i]));
                    }
                }

            }
            else if(isdigit(expression[i])){
               // printf("nombre ");
                if(previous == 0){

                    current = new NoeudConstante();
                    current->setValue(std::to_string(expression[i]));
                    previous = 1 ;
                }


            }
            else if(expression[i]==' '){
              //  printf("space ");
            }
            else{
               // printf("caractere unexpected ");
            }

        }





    return 0;
}