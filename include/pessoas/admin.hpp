#ifndef ADMIN_H
#define ADMIN_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include <map>
#include <fstream>
#include <vector>
#include <sstream>

class Admin : public Pessoa {
    public:
        //Metodos
        Admin (std::string email, std::string senha);
        ~Admin ();
        void remove_livro (Livro* livro);
        std::string get_classe ();
};
#endif