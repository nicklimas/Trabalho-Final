#ifndef USUARIO_H
#define USUARIO_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include "../biblioteca/arquivos.hpp"
#include <set>
#include <fstream>
#include <map>
#include <sstream>


//Classe do usuario
class Usuario : public Pessoa {

    private:

        //ATRIBUTOS

        std::set <Livro*> _livros;

    public:

        //METODOS

        //  Construtor e destrutor
        Usuario (std::string nome, std::string email, std::string senha);
        ~Usuario ();

        // Metodo de inicialização
        void inicia_set_livros (std::map <std::string, Livro*>* biblioteca);

        //  Gets
        std::set <Livro*>* get_livros ();
        std::string get_classe () const override;

        // Metodo relacionados ao livro
        void pega_livro (Livro* livro);
        void devolve_livro (Livro* livro);

        // Auxiliares
        std::string view_livros () const;
        std::string view_dados () const override;
        

};



#endif