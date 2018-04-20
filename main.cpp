#include <iostream>
#include "Arbre.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
 //   char* lol2 = (char*)malloc(50* sizeof(char));
    std::string lol2;
    int lol3;

    std::getline(std::cin, lol2);


    Arbre* lol = new Arbre();
    lol3 = lol->lireExpression(lol2,0);
   // printf("%d",lol3);

    return 0;
}