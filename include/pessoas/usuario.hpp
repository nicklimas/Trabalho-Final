/**
 * @file usuario.hpp
 * @author  Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe do usuario
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef USUARIO_H
#define USUARIO_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include "../biblioteca/arquivos.hpp"
#include <set>
#include <fstream>
#include <map>
#include <sstream>


/**
 * @brief Classe do usuario
 * 
 */
class Usuario : public Pessoa {

    private:

        //ATRIBUTOS
        /**
         * @brief lista de livros emprestados do usuario
         * 
         */
        std::set <Livro*> _livros;

    public:

        //METODOS

        /**
         * @brief Constrói um novo objeto Usuario
         * 
         * @param nome nome
         * @param email email
         * @param senha senha
         */
        Usuario (std::string nome, std::string email, std::string senha);

        /**
         * @brief Destrói o objeto Usuario
         * 
         */
        ~Usuario ();

        // Metodo de inicialização

        /**
         * @brief Le o arquivo com os livros do usuario e inicia o set de livros a partir dele. Em caso de ero ao abrir o arquivo, joga um erro.

         * 
         * @param biblioteca biblioteca
         */
        void inicia_set_livros (std::map <std::string, Livro*>* biblioteca);

        /**
         * @brief Retorna um ponteiro para o set de livros emprestados do usuario
         * 
         * @return std::set <Livro*>*  livros emprestados
         */
        std::set <Livro*>* get_livros ();

        /**
         * @brief Retorna a string "usuario"

         * 
         * @return std::string 
         */
        std::string get_classe () const override;

        // Metodo relacionados ao livro
        /**
         * @brief 
        Recebe um ponteiro para um livro.
        Adiciona o livro ao arquivo de livros emprestados do usuario.
        Insere o livro no set de livros do usuario.
         * 
         * @param livro livro
         */
        void pega_livro (Livro* livro);

        /**
         * @brief Recebe um livro.
        Deleta ele do arquivo de livros do usuario.
        Muda o status de emprestimo do livro.
        Remove o livro do set de livros do usario.

         * 
         * @param livro livro
         */
        void devolve_livro (Livro* livro);

        // Auxiliares

        /**
         * @brief Escreve na tela os livros do usuário e caso ele não tenha escreve "Você não possui livros."
         * 
         * @return std::string livros
         */
        std::string view_livros () const;

        /**
         * @brief Escreve na tela os dados do usuario

         * 
         * @return std::string 
         */
        std::string view_dados () const override;
        

};



#endif
