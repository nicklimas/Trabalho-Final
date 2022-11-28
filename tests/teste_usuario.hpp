#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "third_party\doctest.h"
#include "include\pessoa\usuario.hpp"

//testar 0 e negativos

TEST_CASE("Testando usuario: ") {

    Pessoa ("Nome", "email@example.com","Senha");

    CHECK(Pessoa.get_nome() == "Nome");
    CHECK(Pessoa.get_email() == "email@example.com");
    CHECK(Pessoa.get_senha() == "Senha");
    CHECK(Pessoa.get_classe() == "usuario");
    
    
   
}

