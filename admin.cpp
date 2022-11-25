#include "../../include/pessoas/admin.hpp"


Admin::Admin (std::string email, std::string senha) : Pessoa (email, senha) {};

Admin::~Admin () {}

void Admin::remove_livro (Livro* livro){
    std::fstream arquivo;
    arquivo.open("saves/livros.txt");

    if (!arquivo)
        throw ErroaAbrirArquivo ("livros.txt");

    std::string linha;
    std::vector <std::string> texto;

    while (getline(arquivo,linha)){

        std::stringstream line(linha);
        std::string titulo;

        getline(line, titulo, '#');

        if (!(titulo == livro->get_titulo()))
            texto.push_back(linha);  
    }
    arquivo.close();

    arquivo.open("saves/livros.txt", std::ios::out);
    if (!arquivo)
        throw ErroaAbrirArquivo ("livros.txt");
    
    for (auto &x : texto)
        arquivo << x << std::endl;
    
    arquivo.close();
    std::cout << "Livro removido da biblioteca \n";
    delete livro ;
}

std::string Admin::get_classe (){
    return "admin";
}





