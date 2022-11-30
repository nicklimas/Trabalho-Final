#include "../../include/pessoas/usuario.hpp"


Usuario::Usuario (std::string nome, std::string email, std::string senha) : Pessoa (nome, email, senha) {};

Usuario::~Usuario (){}

std::set <Livro*>* Usuario::get_livros (){
    return &_livros;
}

void Usuario::inicia_set_livros (std::map <std::string, Livro*>* biblioteca) {
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    std::ifstream arquivo(nome_do_arquivo);
    if (!arquivo)
        throw ErroaAbrirArquivo (nome_do_arquivo);

    std::string linha;
    while (getline(arquivo, linha))
        _livros.insert(biblioteca->find(linha)->second);
    arquivo.close();
}
  

void Usuario::pega_livro (Livro* livro) {
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    Arquivos::adciona_linha (nome_do_arquivo, livro->get_titulo()); 
    livro->muda_status();
    _livros.insert (livro);
}
 

void Usuario::devolve_livro (Livro* livro){
    std::string nome_do_arquivo = "saves/usuarios/" + get_nome() + ".txt";
    Arquivos::deleta_linha (nome_do_arquivo, livro->get_titulo());
    livro->muda_status();
    _livros.erase (livro);
    std::cout << "Livro devolvido\n";
}



std::string Usuario::view_livros () const{
    std::string livros;   
    if (_livros.empty())
        return "Você não possui livros.";
    for (auto &x : _livros){
        livros += x->get_titulo ();
        if (_livros.find(x) == (_livros.end())--)
            livros += ".";
        else 
            livros += ","; 
    }
    return livros;
}

std::string Usuario::view_dados () const{
    return Pessoa::view_dados() + "\nNúmero de livros: " + std::to_string(+_livros.size()) + "\nLivros: "+ view_livros () + "\n";
}

std::string Usuario::get_classe() const {
    return "usuario";
}






