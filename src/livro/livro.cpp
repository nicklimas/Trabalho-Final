#include "../../include/livro/livro.hpp"

//Inicia os atributos do livro
Livro::Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel) {
    _titulo =titulo; _autor = autor; _categoria = categoria; _sinopse = sinopse ; _paginas = paginas; 
    if (disponivel == "sim")
        _emprestado = false;
    if (disponivel == "nao")
        _emprestado = true;
    _loc.push_back(corredor);
    _loc.push_back(prateleira);
}

//Construtor vazio
Livro::Livro (){}

//Destrutor
Livro::~Livro (){}

//Retorna o titulo
std::string Livro::get_titulo () const { return this-> _titulo; }

//Retorna o autor
std::string Livro::get_autor() const { return this->_autor; }
   
//Retorna a categoria
std::string Livro::get_categoria () const { return this->_categoria; }

//Retorna a sinopse
std::string Livro::get_sinopse () const { return this->_sinopse; }

//Retorna o numero de paginas
std::string Livro::get_paginas () const { return std::to_string(_paginas);}

//Retorna o vetor com a localização
std::vector <int> Livro::get_localizacao (){ return this->_loc;}

//Retorna "sim" se o livro está disponível e "não" caso o contrário
std::string Livro::get_disponibilidade  () const {
    if (_emprestado)
        return "nao";
    else
        return "sim";
}

//Retorna uma expressão booleana se o livro está emprestado ou não
bool Livro::get_status  () { return this-> _emprestado; }

/*
Muda o status de empréstimo do livro
Se ele está emprestado passa a não estar e vice-versa
*/
void Livro::muda_status () {
    if (_emprestado){
        _emprestado = false;
    } else {
        _emprestado = true;
    }
}

//Escreve na tela as informações do livro     
void Livro::view_dados () {
    std::cout   << "Título: " << _titulo << std::endl 
                << "Autor: " << _autor << std::endl 
                << "Categoria: " << _categoria << std::endl 
                << "Sinopse: " << _sinopse << std::endl 
                << "Páginas: " << std::to_string(_paginas) << std::endl
                << "Localização: " << "corredor " << get_localizacao()[0] << ", prateleira " << get_localizacao()[1]  << std::endl;;
                

    if (_emprestado)
        std::cout << "Emprestado " << std::endl;
    else 
        std::cout << "Disponível " << std::endl;
}


