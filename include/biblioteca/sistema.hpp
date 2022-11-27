#ifndef SISTEMA_H
#define SISTEMA_H

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


/* Classe responsável por armazenar o histórico de livros

    - Possui funcionalidades relacionados ao usuario
*/
class Sistema {
    private:
        
        //  ATRIBUTOS

        // Map de titulo de livros e o vector de usuarios que já pegaram
        std::map <std::string, std::vector<std::string>> _historicos;

    public:

        //  MÉTODOS

        //  Contrutor e destutoro
        Sistema ();
        ~Sistema ();

        //  Método de inicialização a partir do arquivo de salvamento
        void inicia_historico ();

        //  Métodos relacionados diretamento ao usuario
        Pessoa* login ();
        void cadastra_usuario ();
        void deletar_usuario (Usuario *usuario);

        //  Metódos relacionados ao historico
        void cria_historico (std::string titulo);
        void get_historico (std::string titulo);
        void atualiza_historico (std::string titulo, std::string nome);
        void atualiza_arquivo_livros (Livro *livro);
        
        
        //  Método complementares a outros de outras classes
        void pega_livro (Livro *livro, Usuario *usuario);
        void remove_livro (std::string titulo);
       
        
       
};


#endif