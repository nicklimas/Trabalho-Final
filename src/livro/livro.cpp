#include "../../include/livro/livro.hpp"


Livro::Livro (std::string titulo, std::string autor, std::string categoria, std::string sinopse, int paginas, int corredor, int prateleira, std::string disponivel) {
    _titulo =titulo; _autor = autor; _categoria = categoria; _sinopse = sinopse ; _paginas = paginas; 
    if (disponivel == "sim")
        _emprestado = false;
    if (disponivel == "nao")
        _emprestado = true;
    _loc.push_back(corredor);
    _loc.push_back(prateleira);
}

Livro::Livro (){}

Livro::~Livro (){}

std::string Livro::get_titulo () const { return this-> _titulo; }

std::string Livro::get_autor() const { return this->_autor; }
   
std::string Livro::get_categoria () const { return this->_categoria; }

std::string Livro::get_sinopse () const { return this->_sinopse; }

std::string Livro::get_paginas () const { return std::to_string(_paginas);}

std::vector <int> Livro::get_localizacao (){ return this->_loc;}

std::string Livro::get_disponibilidade  () const {
    if (_emprestado)
        return "nao";
    else
        return "sim";
}

bool Livro::get_status  () { return this-> _emprestado; }


void Livro::muda_status () {
    if (_emprestado){
        _emprestado = false;
    } else {
        _emprestado = true;
    }
}

void Livro::view_dados () {
    std::cout   << "\nTítulo: " << _titulo << std::endl 
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


