#include "../../include/biblioteca/biblioteca.hpp"



//Chama as funções para iniciar os atributos a partir dos arquivos de salvamento
Biblioteca::Biblioteca (){
    inicia_livros();
    inicia_autores();
    inicia_categorias();
}

//Destrutor
Biblioteca::~Biblioteca (){}

//Retorna o map de livros
std::map <std::string, Livro*>* Biblioteca::get_livros (){
    return &_livros;
}


//Le o arquivo de livros e inicia o map com eles
void Biblioteca::inicia_livros (){

    std::ifstream arquivo ("saves/livros.txt");
    std::string linha;
    
    if (!arquivo)
        throw ErroaAbrirArquivo ("livros.txt");

    while (getline(arquivo, linha)){
        std::stringstream line(linha);
        std::string titulo, autor, categoria, sinopse, paginas, corredor, prateleira, disponivel;
        
        getline(line, titulo, '#');
        getline(line, autor, '#');
        getline(line, categoria, '#');
        getline(line, sinopse, '#');
        getline(line, paginas, '#');
        getline(line, corredor, '#');
        getline(line, prateleira, '#');
        getline(line, disponivel, '#');

        this->_livros [titulo] = (new Livro(titulo,autor,categoria,sinopse,std::stoi(paginas),std::stoi(corredor),std::stoi(prateleira), disponivel));
    }
    
    arquivo.close();  
}


//Separa os livros por categorias
void Biblioteca::inicia_categorias (){
    std::ifstream arquivo ("saves/categorias.txt");
    std::string linha;

    if (!arquivo)
        throw ErroaAbrirArquivo ("categorias.txt");

    while (getline(arquivo, linha)){

        std::set <Livro*> livros_da_categoria;

        for (auto &x : _livros){
            if (x.second->get_categoria()== linha)
                livros_da_categoria.insert(x.second); 
        }
        this->_categorias[linha] = livros_da_categoria;
    }

    arquivo.close();
}


//Separa os livros por autores
void Biblioteca::inicia_autores (){
    std::ifstream arquivo ("saves/autores.txt");
    std::string linha;

    if (!arquivo)
        throw ErroaAbrirArquivo ("autores.txt");

    while (getline(arquivo, linha)){

        std::set <Livro*> livros_do_autor;

        for (auto &x : (_livros)){
            if (x.second->get_autor() == linha)
                livros_do_autor.insert(x.second); 
        }
        this->_autores [linha] = livros_do_autor;
    }

    arquivo.close();
    
}


//Escreve na tela todos livros da biblioteca
void Biblioteca::lista_livros (){
    for (auto &x : _livros)
        std::cout << x.first << std::endl;
}


//Escreve na tela todos autores
void Biblioteca::lista_autores (){
    for (auto &x : _autores)
        std::cout << x.first << std::endl;
}


//Escreve na tela os livros de determinado autor
void Biblioteca::lista_livros_do_autores (std::string autor){
    for(auto &x : _autores.find(autor)->second)
        std::cout << x->get_titulo();
}


//Escreve na tela todas categorias
void Biblioteca::lista_categorias (){
    for (auto &x : _categorias)
        std::cout << x.first << std::endl;
}


//Escreve na tela os livros de determinada categoria
void Biblioteca::lista_livros_da_categoria (std::string categoria){
    for(auto &x : _categorias.find(categoria)->second)
        std::cout << x->get_titulo();
}


//Adciona um autor novo ao arquivo de autores e ao map de autores
void Biblioteca::add_autor (std::string autor, std::string titulo){
    Arquivos::adciona_linha ("saves/autores.txt", autor);
    std::set <Livro*> livros_do_autor;
    livros_do_autor.insert(_livros.find(titulo)->second);
    _autores [autor] = livros_do_autor;
}


//Adciona uma categoria nova ao arquivo de categorias e ao map de categorias
void Biblioteca::add_categoria (std::string categoria, std::string titulo){
    Arquivos::adciona_linha ("saves/categorias.txt", categoria);
    std::set <Livro*> livros_da_categoria;
    livros_da_categoria.insert(_livros.find(titulo)->second);
    _categorias [categoria] = livros_da_categoria;
}
    
/*
Metodo que cria um livro novo e retorna um ponteira para ele
Adciona ele ao arquivo de livros e ao map de livros
Caso o autor não exista, adciona ele ao arquivo de autores e ao map de autores
Caso a categoria não existe, adciona ela ao arquivo de categorias e ao map de categorias
*/
Livro* Biblioteca::adciona_livro (){
    std::string titulo, autor, categoria, sinopse, disponivel, paginas, corredor, prateleira;
    
        std::cout << "Digite o título: ";
        getline(std::cin, titulo);
        
        std::cout << "Digite o autor: ";
        getline(std::cin, autor);

        std::cout << "Digite a categoria: ";
        getline(std::cin, categoria);

        std::cout << "Digite a sinopse: ";
        getline(std::cin, sinopse);

        bool invalido_pg;
        do {

            std::cout << "Digite o numero de páginas: ";
            std::cin >> paginas;
            fflush(stdin);
            for (unsigned int i = 0; i < paginas.length(); i++) {
                if (isdigit(paginas[i]) == false){
                    invalido_pg = true;
                    break;
                }
                else
                    invalido_pg = false;
            }
            if (invalido_pg)
                std::cout <<"Entrada Inválida\n";
        } while (invalido_pg);
        
        
        bool invalido_c, invalido_p;

        std::cout << "Digite sua localização" << std::endl;
        do{
            std::cout << "Corredor: ";
            std::cin >> corredor;
            fflush(stdin);
            for (unsigned int i = 0; i < corredor.length(); i++) {
                if (isdigit(corredor[i]) == false){
                    invalido_c = true;
                    break;
                }
                else    
                    invalido_c = false;
            }

            if(invalido_c)
                std::cout <<"Entrada Inválida\n";

        } while(invalido_c);

        do{    
            std::cout << "Prateleira: ";
            std::cin >> prateleira;
            fflush(stdin);
            for (unsigned int i = 0; i < prateleira.length(); i++) {
                if (isdigit(prateleira[i]) == false){
                    invalido_p = true;
                    break;
                }
                else
                invalido_p = false;
            }
            
            if(invalido_p)
                std::cout <<"Entrada Inválida\n";
        } while (invalido_p);

        disponivel = "sim";
    
    if (_livros.find(titulo) != _livros.end()){
        std::cout << "Esse livro já está na biblioteca\n";
        return nullptr;
    }

    std::cout   << "\nInformacoes do livro: "<<
                    "\n  Título: " << titulo << 
                    "\n  Autor: " << autor <<  
                    "\n  Categoria: " << categoria << 
                    "\n  Sinopse: " << sinopse << 
                    "\n  Páginas: " << paginas << 
                    "\n  Localização: corredor " << corredor << ", prateleira " << prateleira << std::endl;

    std::string confirma;

    do {
        std::cout << "\nDeseja adcionar esse livro à biblioteca? (s/n) ";
        std::cin >> confirma;
    } while (!(confirma == "s"|| confirma == "n"));

    if (confirma == "n"){
        throw OperacaoInterrompida ("O livro não foi criado");
        return nullptr;
    }

    Livro* livro = new Livro (titulo, autor, categoria, sinopse, std::stoi(paginas), std::stoi(corredor), std::stoi(prateleira), disponivel);
    _livros [titulo] = livro;

    bool existe;

    for (auto &x : _autores){
        if (x.first == autor){
            existe = true;
            break;
        }
        else    
            existe = false;
    }

    if (!existe)
        this->add_autor(autor, titulo);

    for (auto &x : _categorias){
        if (x.first == categoria){
            existe = true;
            break;
        }
        else    
            existe = false;
    }

    if (!existe)
        this->add_categoria (categoria, titulo);
        
    
    std::string linha =  titulo + "#" + autor + "#" + categoria + "#" + sinopse + "#" + paginas + "#" + corredor + "#" + prateleira + "#" + disponivel;
    Arquivos::adciona_linha ("saves/livros.txt", linha);

    std::string nome_do_arquivo = "saves/historico/" + titulo + ".txt";
    Arquivos::cria_arquivo (nome_do_arquivo);

    std::cout << "O livro foi criado com sucesso\n";
    return livro;
}

/*
Metodo que encontra um livro
Recebe uma string que pode ser o título de um livro, um autor ou uma categoria
Caso seja um livro retorna o proprio livro
Caso seja um autor mostra os livros que esse autor tem para serem escolhidos
Caso seja uma categoria mostra os livros que essa categoria tem para serem escolhidos
Se a pesquisa não encontrar nada retorna um ponteira nulo
*/
Livro* Biblioteca::find_livro (std::string pesquisa){
    if (_livros.find(pesquisa) != _livros.end()){
        return _livros.find(pesquisa)->second;
    }
    if (_autores.find(pesquisa) != _autores.end()){
        lista_livros_do_autores(pesquisa);
        std::cout << "\n\nQual livro deseja escolher ?  ";
        std::string escolha;
        getline (std::cin, escolha);
        if (_livros.find(escolha) != _livros.end())
            return _livros.find(escolha)->second;
        else 
            throw OperacaoInterrompida ("Esse livro não existe");
    }

    if (_categorias.find(pesquisa) != _categorias.end()){
        lista_livros_da_categoria (pesquisa);
        std::cout << "\n\nQual livro deseja escolher ?  ";
        std::string escolha;
        getline (std::cin, escolha);
        if (_livros.find(escolha) != _livros.end())
            return _livros.find(escolha)->second;
        else 
            throw OperacaoInterrompida ("Esse livro não existe");
    }
    throw OperacaoInterrompida ("Sua pesquisa não encontrou nada correspondente");
    return nullptr;

}

/*
Metodo que remove um livro
Recebe um livro
Deleta o livro do arquivo de livros
Deleta o arquivo de historico do livro
Remove o livro do map de livros
Remove o livro do map de autores
    Caso seja o unico livro desse autor, deleta o autor do arquivo de autor e do map de autores
Remove o livro do map de categorias
    Caso seja o unico livro da categoria, deleta a categoria do arquivo de categorias e do map de categorias
*/
void Biblioteca::remove_livro(Livro* livro){

    //RETIRANDO LIVRO DO ARQUIVO LIVROS
    Arquivos::deleta_linha("saves/livros.txt", livro->get_titulo(), '#', 1);
    

    //DELETANDO INFORMAÇÕES DO LIVRO
    std::string nome_do_arquivo = "saves/historico/" + livro->get_titulo() + ".txt";

    std::remove(nome_do_arquivo.c_str());

    _livros.erase(livro->get_titulo());

    _autores.find(livro->get_autor())->second.erase(livro);
    if (_autores.find(livro->get_autor())->second.empty()){
        Arquivos::deleta_linha ("saves/autores.txt", livro->get_autor());
        _autores.erase(livro->get_autor());
    }

    _categorias.find(livro->get_categoria())->second.erase(livro);
    if (_categorias.find(livro->get_categoria())->second.empty()){
        Arquivos::deleta_linha ("saves/categorias.txt", livro->get_categoria());
        _categorias.erase(livro->get_categoria());
    }

    delete livro;
    delete &livro;

    std::cout << "Livro removido da biblioteca \n";
}







