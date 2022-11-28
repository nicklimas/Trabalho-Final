#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "third_party\doctest.h"
#include "include\livro\livro.hpp"

//testar 0 e negativos

TEST_CASE("Testando Livro: ") {


    //Livro::Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel)
    
    Livro::Livro ("Titulo", "autor", "categoria", "Este e um texto como exemplo de sinopse", 737, 3, 1, "nao");
    std::vector <int> local;
    local.pushcack(3);
    local.pushcack(1);
    CHECK(Livro.get_titulo() == "Titulo");
    CHECK(Livro.get_autor() == "autor");
    CHECK(Livro.get_categoria() == "categoria");
    CHECK(Livro.get_sinopse() == "Este e um texto como exemplo de sinopse");
    CHECK(Livro.get_paginas() == "737");
    CHECK(Livro.get_localizacao() == local);
    CHECK(Livro.get_disponibilidade() == "nao");

    Livro::Livro ("O senhor Dos Aneis", "JRR Tolkien", "Aventura", "Este e o melhor livro de todos, CONFIA", 1250, 1, 1, "sim");
    std::vector <int> localidade;
    local.pushcack(1);
    local.pushcack(1);
    CHECK(Livro.get_titulo() == "O senhor Dos Aneis");
    CHECK(Livro.get_autor() == "JRR Tolkien");
    CHECK(Livro.get_categoria() == "Aventura");
    CHECK(Livro.get_sinopse() == "Este e o melhor livro de todos, CONFIA");
    CHECK(Livro.get_paginas() == "1250");
    CHECK(Livro.get_localizacao() == localidade);
    CHECK(Livro.get_disponibilidade() == "sim");
        
   
   
}