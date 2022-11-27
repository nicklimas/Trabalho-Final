#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <vector>
#include <string>



//  Classe do objeto Livro

class Livro  {
    private:

        //ATRIBUTOS

        std::string _titulo;
        std::string _autor;
        std::string _categoria;
        std::string _sinopse;
        int _paginas;
        bool _emprestado;
        std::vector <int> _loc;

    public:
        
        //METODOS

        //  Construtores e destrutores
        Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel);
        Livro ();
        ~Livro ();

        // Gets
        std::string get_titulo () const;
        std::string get_autor() const;
        std::string get_categoria () const;
        std::string get_sinopse () const;
        std::string get_paginas () const;
        std::vector <int> get_localizacao ();
        std::string get_disponibilidade () const;
        bool get_status  ();

        // Auxiliares
        void muda_status ();
        void view_dados ();

};

#endif