#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/livro/livro.hpp"

//testar 0 e negativos

TEST_CASE("Testando livro válido") {

    Livro livro("Titulo", "autor", "categoria", "Este e um texto como exemplo de sinopse", 737, 3, 1, "nao");
    std::vector <int> local;
    local.push_back(3);
    local.push_back(1);

    CHECK(livro.get_titulo() == "Titulo");
    CHECK(livro.get_autor() == "autor");
    CHECK(livro.get_categoria() == "categoria");
    CHECK(livro.get_sinopse() == "Este e um texto como exemplo de sinopse");
    CHECK(livro.get_paginas() == "737");
    CHECK(livro.get_localizacao() == local);
    CHECK(livro.get_disponibilidade() == "nao");

}
