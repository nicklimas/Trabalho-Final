#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/biblioteca/biblioteca.hpp"

//testar 0 e negativos

TEST_CASE("Testando Biblioteca: ") {
    Biblioteca b = Biblioteca();
    
    //inicia livros



    //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    //Adiciona exclui livro

    Livro *livro = new Livro;
    livro = b.adciona_livro(); //adiciona livro
    //entradas.txt
    CHECK(livro->get_titulo() == "testando"); // get titulo test
    CHECK(b.find_livro(livro->get_titulo())== livro); //confere se adicionou
    b.remove_livro(livro); // remove livro
    CHECK_FALSE(livro->get_titulo() == "testando"); //confere se remooveu


    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //find Livro caso negativo
    CHECK_THROWS(b.find_livro("Livro IneXistente"));
    
    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //add autor REVER
    b.add_autor("testante","test");
    std::string autor;
    //autor = (Biblioteca::_autores.find("testante")) ;
    CHECK(autor == "testante");

    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //add categoria REVER
    b.add_categoria("CatTest","test");
    std::string cat;
    //cat = (Biblioteca::_categoria.find("CatTest")) ;
    CHECK(autor == "CatTest");

 
   
}

