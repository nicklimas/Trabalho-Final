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
    livro = b.adciona_livro();
    //automatizar cin???
    CHECK(livro->get_titulo() == "testando");
    //CHECK(b.find_livro(livro)== &livro);
    b.remove_livro(livro);
    CHECK_FALSE(livro->get_titulo() == "testando");


    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    //find Livro caso negativo
    CHECK_THROWS(b.find_livro("Livro IneXistente"));
    



    /*
        //---Testa se tem cout---\\
        std::ostringstream oss;
        std::streambuf* p_cout_streambuf = std::cout.rdbuf();
        std::cout.rdbuf(oss.rdbuf());

        f();

        std::cout.rdbuf(p_cout_streambuf); // restore

        // test your oss content...
        assert(oss && oss.str() == "hello world\n";
        std::cout << oss.str();
    */
 
   
}

/*
    Lista de funcoes


    void inicia_livros ();
    void inicia_categorias ();
    void inicia_autores ();

    //  Gets
    std::map <std::string, Livro*>* get_livros ();

    // Métodos de cout
    void lista_livros ();
    void lista_autores ();
    void lista_livros_do_autores (std::string autor);
    void lista_categorias ();
    void lista_livros_da_categoria (std::string categoria);

    // Metodos que atualizam arquivos de salvamento
    void add_autor (std::string autor, std::string titulo);
    void add_categoria (std::string categoria, std::string titulo);

    // Metodos de criação e deleção de livros do sistema da biblioteca
        Livro* adciona_livro ();
        void remove_livro(Livro* livro);

    // Metodo para achar um livro dentro do sistema
        Livro* find_livro (std::string pesquisa);  
*/
