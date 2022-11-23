#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "../livro/livro.hpp"
#include "../pessoas/usuario.hpp"
#include "../pessoas/admin.hpp"
#include "../erros/erros.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>




class Biblioteca {
    
    private:

        //Atributos
        std::map <std::string, Livro*> _livros;
        std::map <std::string, std::set <Livro*>> _autores;
        std::map <std::string, std::set <Livro*>> _categorias;

       
        

    public:

        //Metodos
        Biblioteca ();
        ~Biblioteca ();
        
        //Livros
        std::map <std::string, Livro*> get_livros ();
        void lista_livros ();
        void inicia_livros ();
        void inicia_categorias ();
        Livro* find_livro (std::string pesquis); 
        void inicia_autores ();
        void adciona ();

        //Pessoas
        
        void lista_autores ();
        void lista_categorias ();
        void lista_livros_da_categoria (std::string categoria);
        void lista_livros_do_autores (std::string autor);
        
       
        
        void add_autor (std::string autor);
        void add_categoria (std::string categoria);

};

#endif