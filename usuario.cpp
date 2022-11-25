#include "../../include/pessoas/usuario.hpp"



Usuario::Usuario (std::string nome, std::string email, std::string senha) : Pessoa (nome, email, senha) {};

Usuario::~Usuario (){}

void Usuario::inicia_set_livros (std::map <std::string, Livro*> biblioteca) {
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    std::ifstream arquivo(nome_do_arquivo);
    if (!arquivo)
        throw ErroaAbrirArquivo (nome_do_arquivo);

    std::string linha;
    while (getline(arquivo, linha))
        _livros.insert(biblioteca.find(linha)->second);
    arquivo.close();
}
  
void Usuario::pega_livro (Livro* livro) {
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    std::fstream arquivo (nome_do_arquivo, std::ios::app);
    if (!arquivo)
        throw ErroaAbrirArquivo (nome_do_arquivo);
    arquivo << livro->get_titulo() << std::endl; 
    std::cout << "Concluido\n";
    _livros.insert (livro);
}
 
void Usuario::devolve_livro (Livro* livro){
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    std::fstream arquivo;
    arquivo.open(nome_do_arquivo);

    if (!arquivo)
        throw ErroaAbrirArquivo (nome_do_arquivo);

    std::string linha;
    std::vector <std::string> texto;

    while (getline(arquivo,linha)){
        if (!(linha == livro->get_titulo()))
            texto.push_back(linha);  
    }

    arquivo.close();

    arquivo.open(nome_do_arquivo, std::ios::out);
    
    for (auto &x : texto)
        arquivo << x << std::endl;
    
    arquivo.close();
    _livros.erase (livro);
}

void Usuario::view_livros (){
    for (auto &x : _livros)
        std::cout << x->get_titulo () << std::endl;
}

std::string Usuario::get_classe() {
    return "usuario";
}






