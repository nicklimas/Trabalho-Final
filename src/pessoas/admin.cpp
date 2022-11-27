#include "../../include/pessoas/admin.hpp"

//Construtor
Admin::Admin (std::string email, std::string senha) : Pessoa (email, senha) {};

//Destrutor
Admin::~Admin () {}

//Escreve na tela os dados da biblioteca
std::string Admin::view_dados () const{
    std::ifstream arquivo ("saves/login.txt");
    if (!arquivo)
        throw ErroaAbrirArquivo ("login.txt");

    int n_usuarios = -1;
    std::string linha;
    while(getline(arquivo,linha)){
        n_usuarios++;
    }
    arquivo.close();

    arquivo.open ("saves/livros.txt");
    int n_livros = 0;

    
    while(getline(arquivo,linha)){
        n_livros++;
    }
    arquivo.close();

    return "Número de livros: " + std::to_string(n_livros) + "\nNúmero de usuários: " + std::to_string(n_usuarios) + "\n";
}

//Retorna a string "admin"
std::string Admin::get_classe () const{
    return "admin";
}





