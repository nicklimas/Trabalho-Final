#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <vector>
#include <string>




class Livro  {
    private:

        //Atributos

        std::string _titulo;
        std::string _autor;
        std::string _categoria;
        std::string _sinopse;
        int _paginas;
        bool _emprestado;
        std::vector <int> _loc;

    public:
        
        //Metodos

        Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel);
        Livro ();
        ~Livro ();
        std::string get_titulo () const ;
        std::string get_autor() const ;
        std::string get_categoria () const ;
        std::string get_localizacao () const;
        bool get_status  ();
        void muda_status ();
        void view_dados ();

};

#endif