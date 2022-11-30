/**
 * @file livro.hpp
 * @author Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe do objeto Livro

 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <vector>
#include <string>



class Livro  {
    private:

        //ATRIBUTOS

        /**
         * @brief Titulo do livro
         * 
         */
        std::string _titulo;

        /**
         * @brief Autor do livro
         * 
         */
        std::string _autor;

        /**
         * @brief categoria do livro
         * 
         */
        std::string _categoria;

        /**
         * @brief sinopse do livro
         * 
         */
        std::string _sinopse;

        /**
         * @brief número de páginas do livro
         * 
         */
        int _paginas;

        /**
         * @brief parametro que diz se o livro esta disponivel para empréstimo ou não
         * 
         */
        bool _emprestado;

        /**
         * @brief localização do livro na biblioteca física
         * 
         */
        std::vector <int> _loc;

    public:
        
        //METODOS

        //  Construtores e destrutores

        /**
         * @brief Constrói um novo objeto Livro
         * 
         * @param titulo 
         * @param autor 
         * @param categoria 
         * @param sinopse 
         * @param paginas 
         * @param corredor 
         * @param prateleira 
         * @param disponivel 
         */
        Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel);

        /**
         * @brief Constrói um novo objeto Livro com parametros vazios
         * 
         */
        Livro ();

        /**
         * @brief Destrói o Livro
         * 
         */
        ~Livro ();

        // Gets

        /**
         * @brief retorna o titulo do livro
         * 
         * @return std::string titulo
         */
        std::string get_titulo () const;

        /**
         * @brief retorna o autor do livro
         * 
         * @return std::string autor
         */
        std::string get_autor() const;

        /**
         * @brief Retorna a categoria do livro
         * 
         * @return std::string categoria
         */
        std::string get_categoria () const;

        /**
         * @brief Retorna a sinopse do livro
         * 
         * @return std::string sinopse
         */
        std::string get_sinopse () const;

        /**
         * @brief Retorna o número de paginas do livro
         * 
         * @return std::string número de paginas
         */
        std::string get_paginas () const;

        /**
         * @brief Retorna o vetor com a localização do livro
         *          
         * @return std::vector <int> localização
         */
        std::vector <int> get_localizacao ();

        /**
         * @brief Retorna "sim" se o livro está disponível e "não" caso o contrário

         * 
         * @return std::string disponibilidade
         */
        std::string get_disponibilidade () const;

        /**
         * @brief Retorna uma expressão booleana se o livro está emprestado ou não
         * 
         * @return true ou
         * @return false 
         */
        bool get_status  ();

        // Auxiliares

        /**
         * @brief Muda o status de empréstimo do livro.
        Se ele está emprestado passa a não estar e vice-versa.
         * 
         */
        void muda_status ();

        /**
         * @brief Escreve na tela as informações do livro     

         * 
         */
        void view_dados ();

};

#endif
