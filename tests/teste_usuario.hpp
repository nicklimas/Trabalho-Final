#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/pessoas/usuario.hpp"

//testar 0 e negativos

TEST_CASE("Testando usuario: ") {

    Usuario u ("Nome", "email@example.com","Senha");
    
    CHECK(u.get_nome() == "Nome");
    CHECK(u.get_email() == "email@example.com");
    CHECK(u.get_senha() == "Senha");
    CHECK(u.get_classe() == "usuario");
    CHECK(u.view_dados() == "Nome: Nome\nEmail:email@example.com\nNúmero de livros: 0\nLivros: Você não possui livros.\n" );
    
    
   
}

