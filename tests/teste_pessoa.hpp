#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "third_party\doctest.h"
#include "include\pessoa\pessoa.hpp"

//testar 0 e negativos

TEST_CASE("Testando Pessoa: ") {

    Pessoa ("Nome", "email@example.com","Senha");

    CHECK(Pessoa.get_nome() == "Nome");
    CHECK(Pessoa.get_email() == "email@example.com");
    CHECK(Pessoa.get_senha() == "Senha");
    CHECK(Pessoa.get_classe() == "pessoa");
    
    

    
    Pessoa ("ExemplodeEmail", "senhateste");
    
    CHECK(Pessoa.get_email() == "ExemplodeEmail");
    CHECK(Pessoa.get_senha() == "senhateste");
    CHECK(Pessoa.get_classe() == "pessoa");
   
   
}

