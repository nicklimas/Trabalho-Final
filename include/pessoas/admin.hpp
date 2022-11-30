/**
 * @file admin.hpp
 * @author  Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe do administrador
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ADMIN_H
#define ADMIN_H

#include "pessoa.hpp"
#include "../livro/livro.hpp"
#include <map>
#include <fstream>
#include <vector>
#include <sstream>



class Admin : public Pessoa {

    public:

        //METODOS

        /**
         * @brief Constrói um novo objeto Admin 
         * 
         * @param email 
         * @param senha 
         */
        Admin (std::string email, std::string senha);

        /**
         * @brief Destrói o objeto Admin 
         * 
         */
        ~Admin ();

        /**
         * @brief Retorna a string "admin"
         * 
         * @return std::string classe
         */
        std::string get_classe () const override;

        /**
         * @brief Escreve na tela os dados da biblioteca
         * 
         * @return std::string dados
         */
        std::string view_dados () const override;
};






#endif
