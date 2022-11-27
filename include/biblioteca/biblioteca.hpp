#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "../livro/livro.hpp"
#include "../pessoas/usuario.hpp"
#include "../pessoas/admin.hpp"
#include "../erros/erros.hpp"
#include "arquivos.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>


/*  Classe responsável por armazenar os livros existentes e separá-los por autores e por categorias

    -Possui funcionalidades relaciondas aos livros

*/
class Biblioteca {
    
    private:

        //  ATRIBUTOS

        // Map do titulo do livro e o livro
        std::map <std::string, Livro*> _livros;

        // Map do nome do autor e seu set de livros
        std::map <std::string, std::set <Livro*>> _autores;

        // Map da categoria e seu set de livros
        std::map <std::string, std::set <Livro*>> _categorias;
        
       
    public:

        //  METODOS

        //  Contrutos e destrutor
        Biblioteca ();
        ~Biblioteca ();
        
        //  Métodos de inicialização a partir dos arquivos de salvamento
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
        

        

       
        
        
        
        
        
        
       
        
       
        
        

};

#endif