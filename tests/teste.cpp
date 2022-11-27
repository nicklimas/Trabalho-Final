#include <iostream>
#include "../include/biblioteca/sistema.hpp"
#include "../include/biblioteca/biblioteca.hpp"

#include <locale>

std::string get_classe (Pessoa &pessoa){
    return pessoa.get_classe();
}
    

int main  (){
    Biblioteca biblioteca = Biblioteca ();
    biblioteca.cria();




    return 0;
}