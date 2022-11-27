#ifndef USUARIO_H
#define USUARIO_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include <set>
#include <fstream>
#include <map>
#include <sstream>

class Usuario : public Pessoa {
    private:
        //Atributos
        std::set <Livro*> _livros;

    public:
        //Metodos
        Usuario (std::string nome, std::string email, std::string senha);
        ~Usuario ();
        void inicia_set_livros (std::map <std::string, Livro*> biblioteca);
        void pega_livro (Livro* livro);
        void devolve_livro (Livro* livro);
        void view_livros ();
        std::string get_classe();
};
#endif