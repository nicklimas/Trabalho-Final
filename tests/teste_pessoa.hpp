#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/pessoas/pessoa.hpp"

//testar 0 e negativos

TEST_CASE("Testando Pessoa: ") {

    Pessoa p ("Nome", "email@example.com","Senha");

    CHECK(p.get_nome() == "Nome");
    CHECK(p.get_email() == "email@example.com");
    CHECK(p.get_senha() == "Senha");
    CHECK(p.get_classe() == "pessoa");
    CHECK(p.view_dados() == "Nome: Nome\nEmail:email@example.com");
   
   
}

