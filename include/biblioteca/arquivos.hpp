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


//  Classe assistente para facilitar a manipulação de arquivos

class Arquivos {

    public:
        static void deleta_linha (std::string arquivo, std::string termo);
        static void deleta_linha (std::string arquivo, std::string termo, char separador, int posicao);
        static void adciona_linha (std::string arquivo, std::string linha);
        static void cria_arquivo (std::string nome);

};


#endif