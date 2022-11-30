/**
 * @file sistema.hpp
 * @author Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe responsável por armazenar o histórico de livros

    - Possui funcionalidades relacionados ao usuario
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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


/**
 * @brief Classe responsável por armazenar o histórico de livros

    - Possui funcionalidades relacionados ao usuario
 * 
 */
class Sistema {
    private:
        
        //  ATRIBUTOS

        /**
         * @brief Map que associa o titulo do livro e o vector de usuarios que já emprestaram o livro
         * 
         */
        std::map <std::string, std::vector<std::string>> _historicos;

    public:

        //  MÉTODOS

        /**
         * @brief Constrói um novo objeto Sistema
         * 
         */
        Sistema ();

        /**
         * @brief Destrói o objeto Sistema
         * 
         */
        ~Sistema ();

        
        /**
         * @brief Le o arquivo de historico de cada livro e inicia o map de historico. Em caso de erro ao abrir os arquivos, joga uma exceção. 
         * 
         */
        void inicia_historico ();

        //  Métodos relacionados diretamento ao usuario

        /**
         * @brief Metodo para logar a pessoa no sistema.
        Le da entrada um email e uma senha.
        Compara a entrada com as informações no arquivo de login.
        Caso as informações batam, o login é efetuado com sucesso.
        Caso não, a função termina.
        Retorna um ponteiro do tipo pessoa com as informações do usuario logado.
        Em caso de erro ao abrir os arquivos ou usuario nao encontrado, joga uma exceção.
         * 
         * @return Pessoa* ponteiro do tipo pessoa com as informações do usuario logado.
         */
        Pessoa* login ();

        /**
         * @brief Metodo para cadastrar um usuario.
        Le na entrada um nome, um email e uma senha.
        Adiciona o novo usuario no arquivo de login.
         * 
         */
        void cadastra_usuario ();

        /**
         * @brief Recebe um ponteiro para usuario.
        Deleta o usuario do arquivo de login mediante confirmação com senha.
        Deleta o arquivo de livros do usuario.
         * 
         * @param usuario usuario a ser deletado .
         */
        void deletar_usuario (Usuario *usuario);

        //  Metódos relacionados ao historico

        /**
         * @brief Cria o historico de emprestimos um livro novo criado.

         * 
         * @param titulo titulo do livro.
         */
        void cria_historico (std::string titulo);

        /**
         * @brief Recebe o titulo do livro e escreve na tela o historico de emprestimos desse livro.
         * 
         * @param titulo titulo do livro.
         */
        void get_historico (std::string titulo);

        /**
         * @brief 
        Recebe o titulo do livro e o nome do usuario.
        Atualiza o arquivo e o map do historico de emprestimos deste livro adicionando o usuario a ele.

         * 
         * @param titulo titulo do livro.
         * @param nome nome do usuario.
         */
        void atualiza_historico (std::string titulo, std::string nome);

        /**
         * @brief Recebe um ponteiro para um livro e atualiza o arquivo desse livro quando ele é emprestado ou devolvido.

         * 
         * @param livro ponteiro para um livro.
         */
        void atualiza_arquivo_livros (Livro *livro);
        
        
        //  Método complementares a outros de outras classes

        /**
         * @brief Recebe um ponteiro para um livro e para um usuario.
        Chama a função para adicionar esse livro a lista de livros do usuario.
        Muda o status do livro para emprestado.
        Chama a função para atualizar o arquivo de historico do livro.
        Chama a função para atualizar o livro no arquivo de livros para salvá-lo como indisponível.
         * 
         * @param livro ponteiro para um livro.
         * @param usuario ponteiro para um usuario.
         */
        void pega_livro (Livro *livro, Usuario *usuario);

        /**
         * @brief 
        Recebe um ponteiro para livro e um ponteiro para usuario.
        Chama a função de devolução de livro do usuario para remove-lo do set e do arquivo do usuario.
        Chama a função de atualizar arquivo de livros para salvá-lo como disponível.
         * 
         * @param livro ponteiro para um livro.
         * @param usuario ponteiro para um usuario.
         */
        void devolve_livro (Livro *livro, Usuario *usuario);

        /**
         * @brief 
        Auxiliar da função remove livro da biblioteca.
        Recebe um ponteiro para um livro.
        Deleta o livro do arquivo de livros do usuario que possui ele no momento.
        Deleta o livro do map de historico.

         * 
         * @param titulo ponteiro para um livro.
         */
        void remove_livro (std::string titulo);
       
        
       
};


#endif
