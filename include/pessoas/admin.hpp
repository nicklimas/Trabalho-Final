#ifndef ADMIN_H
#define ADMIN_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include <map>
#include <fstream>
#include <vector>
#include <sstream>


//Classe do administrador

class Admin : public Pessoa {

    public:

        //METODOS

        //  Construtores
        Admin (std::string email, std::string senha);
        ~Admin ();

        //Get
        std::string get_classe () const override;

        // Auxiliar
        std::string view_dados () const override;
};






#endif