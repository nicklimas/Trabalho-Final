#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include "../erros/erros.hpp"

class Pessoa {
    private:
        //Atributos
        std::string _nome;
        std::string _email;
        std::string _senha;
		
    public:
        //Metodos
        Pessoa ();
        Pessoa (std::string nome);
        Pessoa (std::string email, std::string senha);
        Pessoa (std::string nome, std::string email, std::string senha);
        ~Pessoa ();
        std::string get_senha () const;
        std::string get_email () const;
        std::string get_nome () const;
        std::string get_class () const;
};
#endif