/**
 * @file arquivos.hpp
 * @author Arthur, Gabriel, Mariana, Nicolas, Samantha.
 * @brief Classe assistente para facilitar a manipulação de arquivos
 * @version 0.1
 * @date 2022-11-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ARQUIVOS_H
#define ARQUIVOS_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include "../erros/erros.hpp"
 
/**
 * @brief Classe assistente para facilitar a manipulação de arquivos: deletar e adicionar linhas a arquivos existentes e criar novos arquivos. 
 * 
 */
class Arquivos {

    public:
        /**
         * @brief Deleta do arquivo a linha que tem o termo passado na referência 
         * 
         * @param arquivo string com o endereço de um arquivo com apenas uma informação por linha 
         * @param termo string com o termo que é para ser encontrado
         */
        static void deleta_linha (std::string arquivo, std::string termo);

        /**
         * @brief Deleta do arquivo a linha que tem o termo passado na referência 
         * 
         * @param arquivo string com o endereço de um arquivo com mais de uma informação por linha 
         * @param termo string com o termo que é para ser encontrado
         * @param separador char com o separador utilizado para separar as informações na linha
         * @param posicao int com a posição da informação na linha
         */
        static void deleta_linha (std::string arquivo, std::string termo, char separador, int posicao);

        /**
         * @brief Adiciona a linha ao arquivo 
         * 
         * @param arquivo string com o endereço de um arquivo 
         * @param linha string com a linha que deve ser adicionada
         */
        static void adciona_linha (std::string arquivo, std::string linha);

        /**
         * @brief Cria o arquivo
         * 
         * @param nome string com o nome do arquivo
         */
        static void cria_arquivo (std::string nome);

};


#endif