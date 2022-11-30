/**
 * @file pessoa.hpp
 * @author  Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe mãe de usuario e admin
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include "../erros/erros.hpp"


/**
 * @brief Classe mãe de usuario e admin
 * 
 */
class Pessoa {
    private:
        
        //ATRIBUTOS
        /**
         * @brief nome da pessoa
         * 
         */
        std::string _nome;
        /**
         * @brief email da pessoa
         * 
         */
        std::string _email;
        /**
         * @brief senha de acesso à biblioteca
         * 
         */
        std::string _senha;
    
    public:

        //METODOS

        /**
         * @brief Constrói um objeto Pessoa com atributos vazios
         * 
         */
        Pessoa ();
        
        /**
         * @brief Constrói um objeto Pessoa com email e senha
         * 
         * @param email 
         * @param senha 
         */
        Pessoa (std::string email, std::string senha);

        /**
         * @brief Constrói um objeto Pessoa com nome, email e senha
         * 
         * @param nome 
         * @param email 
         * @param senha 
         */
        Pessoa (std::string nome, std::string email, std::string senha);

        /**
         * @brief Destrói o objeto Pessoa 
         * 
         */
        virtual ~Pessoa ();

        /**
         * @brief Retorna a string "pessoa"

         * 
         * @return std::string classe
         */
        virtual std::string get_classe () const;

        /**
         * @brief Retorna a senha
         * 
         * @return std::string senha
         */
        std::string get_senha () const;

        /**
         * @brief Retorna o email
         * 
         * @return std::string email
         */
        std::string get_email () const;

        /**
         * @brief Retorna o nome
         * 
         * @return std::string nome
         */
        std::string get_nome () const;
        

        //  Auxiliar

        /**
         * @brief Escreve na tela os dados da pessoa
         * 
         * @return std::string dados
         */
        virtual std::string view_dados () const;
    
        

};


#endif
