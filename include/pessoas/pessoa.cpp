#include "../../include/pessoas/pessoa.hpp"

Pessoa::Pessoa () {}

Pessoa::Pessoa (std::string nome) : _nome (nome) {};

Pessoa::Pessoa (std::string nome, std::string email) : _nome (nome), _email (email) {};

Pessoa::Pessoa (std::string nome, std::string email, std::string senha) : _nome (nome), _email (email), _senha (senha) {};

Pessoa::~Pessoa (){}

std::string Pessoa::get_senha () const { return this->_senha; }

std::string Pessoa::get_email () const { return this->_email; }

std::string Pessoa::get_nome () const { return this->_nome; }

std::string Pessoa::get_class () const { return "pessoa"; }






