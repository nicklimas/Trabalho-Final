#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include "../erros/erros.hpp"


//Classe mãe de usuario e admin
class Pessoa {
    private:
        
        //ATRIBUTOS
        std::string _nome;
        std::string _email;
        std::string _senha;
    
    public:

        //METODOS

        //  Construtores e destrutore
        Pessoa ();
        Pessoa (std::string email, std::string senha);
        Pessoa (std::string nome, std::string email, std::string senha);
        virtual ~Pessoa ();

        // Gets
        virtual std::string get_classe () const;
        std::string get_senha () const;
        std::string get_email () const;
        std::string get_nome () const;

        //  Auxiliar
        virtual std::string view_dados () const;
    
        

};


#endif