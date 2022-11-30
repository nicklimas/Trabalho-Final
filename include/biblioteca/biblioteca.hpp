/**
 * @file biblioteca.hpp
 * @author Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe responsável por armazenar os livros existentes, adicionar e remover livros, e separá-los por autores e por categorias

    -Possui funcionalidades relaciondas aos livros
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

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
 * @brief Classe responsável por armazenar os livros existentes, adicionar e remover livros, e separá-los por autores e por categorias
 * 
 */
class Biblioteca {
    
    private:

        //  ATRIBUTOS

        /**
         * @brief Map que associa o titulo do livro e o livro
         * 
         */
        std::map <std::string, Livro*> _livros;

        /**
         * @brief Map que associa o nome do autor e seu set de livros
         * 
         */
        std::map <std::string, std::set <Livro*>> _autores;

        /**
         * @brief Map que associa a categoria e seu set de livros
         * 
         */
        std::map <std::string, std::set <Livro*>> _categorias;
        
       
    public:

        //  METODOS

        /**
         * @brief Constrói um novo objeto Biblioteca 
         * 
         */
        Biblioteca ();
        /**
         * @brief Destrói o objeto Biblioteca
         * 
         */
        ~Biblioteca ();
        
        //  Métodos de inicialização a partir dos arquivos de salvamento
        /**
         * @brief Le o arquivo dque contem os  livros e inicia o map com eles. Em caso de falha ao abrir o arquivo, joga uma exceção
         * 
         */
        void inicia_livros ();

        /**
         * @brief Separa os livros por categoria específica. Em caso de falha ao abrir o arquivo, joga uma exceção
         * 
         */
        void inicia_categorias ();

        /**
         * @brief Separa os livros por autor. Em caso de falha ao abrir o arquivo, joga uma exceção
         * 
         */
        void inicia_autores ();

        /**
         * @brief Retorna o map de livros
         * 
         * @return std::map <std::string, Livro*>* 
         */
        std::map <std::string, Livro*>* get_livros ();

        // Métodos de cout

        /**
         * @brief Escreve na tela todos livros da biblioteca
         */
        void lista_livros ();

        /**
         * @brief Escreve na tela todos autores
         * 
         */
        void lista_autores ();

        /**
         * @brief Escreve na tela os livros de determinado autor
         * 
         * @param autor nome do autor
         */
        void lista_livros_do_autores (std::string autor);

        /**
         * @brief Escreve na tela todas categorias
         * 
         */
        void lista_categorias ();

        /**
         * @brief Escreve na tela os livros de determinada categoria

         * 
         * @param categoria nome da categoria
         */
        void lista_livros_da_categoria (std::string categoria);

        // Metodos que atualizam arquivos de salvamento

        /**
         * @brief Adiciona um autor novo ao arquivo de autores e ao map de autores
         * 
         * @param autor nome do autor
         * @param titulo titulo do livro
         */
        void add_autor (std::string autor, std::string titulo);

        /**
         * @brief Adiciona uma categoria nova ao arquivo de categorias e ao map de categorias

         * 
         * @param categoria nome da categoria
         * @param titulo titulo do livro
         */
        void add_categoria (std::string categoria, std::string titulo);

        // Metodos de criação e deleção de livros do sistema da biblioteca

        /**
         * @brief Metodo que cria um livro novo e retorna um ponteira para ele
            Adiciona ele ao arquivo de livros e ao map de livros
            Caso o autor não exista, adciona ele ao arquivo de autores e ao map de autores
            Caso a categoria não exista, adiciona ela ao arquivo de categorias e ao map de categorias
         * 
         * @return Livro* ponteiro para o livro criado
         */
        Livro* adciona_livro ();

        /**
         * @brief Metodo que remove um livro.
            Recebe um livro.
            Deleta o livro do arquivo de livros.
            Deleta o arquivo de historico do livro.
            Remove o livro do map de livros.
            Remove o livro do map de autores.
            Caso seja o unico livro desse autor, deleta o autor do arquivo de autor e do map de autores.
            Remove o livro do map de categorias.
            Caso seja o unico livro da categoria, deleta a categoria do arquivo de categorias e do map de categorias.
         * 
         * @param livro livro a ser removido
         */
        void remove_livro(Livro* livro);

        // Metodo para achar um livro dentro do sistema

        /**
         * @brief Metodo que encontra um livro.
            Recebe uma string que pode ser o título de um livro, um autor ou uma categoria.
            Caso seja um livro retorna o proprio livro.
            Caso seja um autor mostra os livros que esse autor tem para serem escolhidos.
            Caso seja uma categoria mostra os livros que essa categoria tem para serem escolhidos.
            Se a pesquisa não encontrar nada retorna um ponteira nulo.
            Em caso de livro inexistente, joga uma exceção.
         * 
         * @param pesquisa string que pode ser o título de um livro, um autor ou uma categoria
         * @return Livro* 
         */
        Livro* find_livro (std::string pesquisa); 
        
        

};

#endif
