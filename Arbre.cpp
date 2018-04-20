//
// Created by isen on 13/04/18.
//

#include <cstdio>
#include <iostream>
#include "Arbre.h"

 int Arbre::lireExpression(std::string expression,int index) {

    int i = 0;
    if(index == 0){
        for(i=0;expression[i];i++){

            // printf("%c",expression[i]);
            if(expression[i]=='('){
                // std::cout>> "" << std::endl;
              //  printf("parenthese ouvrante ");
            }
            else if(expression[i]==')'){
               // printf("parenthese fermante ");
            }
            else if((expression[i]=='*')||(expression[i]=='+')||(expression[i]=='-')||(expression[i]=='/')){
                //printf("operateur ");
                if(expression[i-1]==')'){
                    printf("main operator");
                    printf("%c",expression[i]);
                }
                else if(expression[i-1]==' '){
                    if(expression[i-2]==')'){
                        printf("main operator");
                        printf("%c",expression[i]);
                    }

                }
            }
            else if(isdigit(expression[i])){
               // printf("nombre ");
            }
            else if(expression[i]==' '){
              //  printf("space ");
            }
            else{
               // printf("caractere unexpected ");
            }

        }
    }



    return 0;
}