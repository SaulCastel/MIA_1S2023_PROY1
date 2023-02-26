#include <iostream>
#include "parser.h"

int main(){
    std::cout << "Universidad San Carlos de Guatemala\n";
    std::cout << "Saul Esteban Castellanos Ubeda\n";
    std::cout << "201801178\n \n";
    std::cout << "$ ";
    char command [400];
    scanf(" %[^\n]",command);
    parse(command);
    return 0;
}