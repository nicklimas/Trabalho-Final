#ifndef ERROS_H
#define ERROS_H

#include <iostream>
#include <string>
#include <cstring>

//  Classes de tratamento de exceções

class ErroaAbrirArquivo : public std::exception {
    private:
        std::string _mensagem;
    public:
        ErroaAbrirArquivo (std::string nome) {
            _mensagem = "Não foi possível abrir o arquivo " + nome + "\n";
        };

        const char* what () const noexcept override { 
            char *arr = new char [_mensagem.length() + 1];
            std::strcpy (arr, _mensagem.c_str());
            return arr;
        }
};

class OperacaoInterrompida : public std::exception {
    private:
        std::string _mensagem;
    public:
        OperacaoInterrompida (std::string mensagem) {
            _mensagem = mensagem + "\n";
        }

         const char* what () const noexcept override {
            char *arr = new char [_mensagem.length() + 1];
            std::strcpy (arr, _mensagem.c_str());
            return  arr;
         }
};


#endif