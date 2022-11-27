#include "../../include/pessoas/pessoa.hpp"

//Construtor vazio
Pessoa::Pessoa () {}

//Contrutor com email e senha
Pessoa::Pessoa (std::string email, std::string senha) : _email (email), _senha (senha) {};

//Construtor completo
Pessoa::Pessoa (std::string nome, std::string email, std::string senha) : _nome (nome), _email (email), _senha (senha) {};

//Destrutor
Pessoa::~Pessoa (){}

//Retorna a senha
std::string Pessoa::get_senha () const { return this->_senha; }

//Retorna o email
std::string Pessoa::get_email () const { return this->_email; }

//Retorna o nome
std::string Pessoa::get_nome () const { return this->_nome; }

//Retorna a string "pessoa"
std::string Pessoa::get_classe () const { return "pessoa"; }

//Escreve na tela os dados
std::string Pessoa::view_dados () const {
    return "Nome: " + get_nome() + "\nEmail: " + get_email();
}







