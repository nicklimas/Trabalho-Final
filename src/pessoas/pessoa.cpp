#include "../../include/pessoas/pessoa.hpp"

Pessoa::Pessoa () {}

Pessoa::Pessoa (std::string email, std::string senha) : _email (email), _senha (senha) {};

Pessoa::Pessoa (std::string nome, std::string email, std::string senha) : _nome (nome), _email (email), _senha (senha) {};

Pessoa::~Pessoa (){}

std::string Pessoa::get_senha () const { return this->_senha; }

std::string Pessoa::get_email () const { return this->_email; }

std::string Pessoa::get_nome () const { return this->_nome; }

std::string Pessoa::get_classe () const { return "pessoa"; }

std::string Pessoa::view_dados () const {
    return "Nome: " + get_nome() + "\nEmail: " + get_email();
}



