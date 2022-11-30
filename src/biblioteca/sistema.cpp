#include "../../include/biblioteca/sistema.hpp"

//Chama as funções para iniciar os atributos a partir do arquvios de salvamento
Sistema::Sistema (){
    inicia_historico ();
}

//Destrutor
Sistema::~Sistema (){}

/*
Metodo para logar a pessoa no sistema
Le da entrada um email e uma senha
Compara a entrada com as informações no arquivo de login
Caso as informações batam, o login é efetuado com sucesso
Caso não a função termina
Retorna um ponteiro do tipo pessoa com as informações do usuario logado
*/
Pessoa* Sistema::login (){
    std::fstream arquivo;
    arquivo.open("saves/login.txt", std::ios::in);

    if(!arquivo)
        throw ErroaAbrirArquivo ("login.txt");

    std::string linha, email, senha;

    std::cout << "Digite seu email:  ";
    std::cin >> email;
    std::cout << "Digite sua senha:  ";
    std::cin >> senha;
    
    while (getline(arquivo, linha)){
        std::stringstream line(linha);
        std::string identificador, email_arquivo, senha_arquivo, nome;
        
        getline (line, identificador, '#');
        getline (line, email_arquivo, '#');
        getline (line, senha_arquivo, '#');
        getline (line, nome, '#');
            
        
        if (email_arquivo == email){
            if (senha_arquivo == senha){
                arquivo.close();
                if (identificador == "a")
                    return new Admin (email, senha);
                if (identificador == "u") 
                    return new Usuario (nome, email, senha); 
            }
            else {
                throw OperacaoInterrompida ("Senha incorreta");
                arquivo.close();
            }
        } 
    }
    arquivo.close();
    throw OperacaoInterrompida ("Usuário não encontrado");
    return nullptr;

}

/*
Metodo para cadastrar um usuario
Le na entrada um nome, um email e uma senha
Adciona o novo usuario no arquivo de login
*/
void Sistema::cadastra_usuario(){

    std::string nome, email, senha, confirmar;

    do{
        std::cout << "Digite seu nome:  ";
        std::cin >> nome;

        do {
        std::cout << "Confirmar? (s/n)  ";
        std::cin >> confirmar;
        } while (!(confirmar == "s"|| confirmar == "n"));

        if (confirmar == "s")
            break;

    } while(true);

    
    do{
        std::cout << "\nDigite seu email:  ";
        std::cin >> email;

        do {
        std::cout << "Confirmar? (s/n)  ";
        std::cin >> confirmar;
        } while (!(confirmar == "s"|| confirmar == "n"));

        if (confirmar == "s")
            break;

    } while(true);


    do{
        std::cout << "\nDigite sua senha:  ";
        std::cin >> senha;
    
        std::cout << "Confirme sua senha: ";
        std::cin >> confirmar;

        if (confirmar == senha)
            break;

    } while(true);

    std::string linha = "u#" + email + "#" + senha + "#" + nome;
    Arquivos::adciona_linha ("saves/login.txt", linha);
    

    std::string nome_do_arquivo = "saves/usuarios/" + nome + ".txt";
    Arquivos::cria_arquivo (nome_do_arquivo);
}


//Le o arquivo de historico de cada livro e inicia o map de historico
void Sistema::inicia_historico (){
    std::ifstream livros ("saves/livros.txt");

    if (!livros)
        throw ErroaAbrirArquivo ("livros.txt");

    std::string linha;

    while (getline(livros, linha)){
        std::stringstream line (linha);
        if (!(linha.empty())){
            std::string titulo;
            
            getline (line, titulo, '#');
            std::string nome_do_arquivo = "saves/historico/" + titulo + ".txt";

            std::ifstream historico (nome_do_arquivo);
            
            if (!historico)
                throw ErroaAbrirArquivo (nome_do_arquivo);

            std::string usuario;
            std::vector <std::string> historico_de_usuarios;

            while (getline(historico, usuario)) {
                historico_de_usuarios.push_back (usuario);
            }

            _historicos [titulo] = historico_de_usuarios;
        }
    }
    
}

//Cria o historico de um livro novo criado
void Sistema::cria_historico (std::string titulo){
    std::vector <std::string> historico {};
    _historicos [titulo] = historico;
}

//Recebe o titulo do livro e escreve na tela o historico desse livro
void Sistema::get_historico (std::string titulo){
    if (_historicos.find(titulo)->second.empty())
        std::cout << "Este livro não tem histórico\n";
    else
        for (auto x = _historicos.find(titulo)->second.end()-1; x >= _historicos.find(titulo)->second.begin(); x--)
            std::cout << *x << std::endl;
}

/*
Recebe o titulo do livro e o nome do usuario
Atualiza o arquivo e o map do historico deste livro adcionando o usuario a ele
*/
void Sistema::atualiza_historico (std::string titulo, std::string nome){
    std::string nome_do_arquivo = "saves/historico/" + titulo + ".txt";
    Arquivos::adciona_linha (nome_do_arquivo, nome);
    _historicos.find(titulo)->second.push_back(nome);
}

//Recebe um ponteiro para um livro e atualiza o arquivo desse livro quando ele é emprestado ou devolvido
void Sistema::atualiza_arquivo_livros (Livro *livro){
    std::string atualiza = livro->get_titulo() + "#" + livro->get_autor() + "#" + livro->get_categoria() + "#" + livro->get_sinopse() + 
                            "#" + livro->get_paginas() + "#" + std::to_string(livro->get_localizacao()[0]) + "#" + std::to_string(livro->get_localizacao()[1]) + 
                            "#" + livro->get_disponibilidade ();

    Arquivos::deleta_linha ("saves/livros.txt", livro->get_titulo(), '#', 1);
    Arquivos::adciona_linha ("saves/livros.txt", atualiza);
    
}

/*
Recebe um ponteiro para um livro e para um usuario
Chama a função para adcionar esse livro ao usuario
Muda o status do livro para emprestado
Chama a função para atualizar o arquivo de historico do livro
Chama a função para atualizar o livro no arquivo de livros para salvá-lo como indisponível 
*/
void Sistema::pega_livro (Livro *livro, Usuario *usuario){
    usuario->pega_livro(livro);
    atualiza_historico(livro->get_titulo(), usuario->get_nome());
    atualiza_arquivo_livros(livro);
    
}

/*
Recebe um ponteiro para usuario
Deleta o usuario do arquivo de login
Deleta o arquivo de livros do usuario
*/
void Sistema::deletar_usuario (Usuario *usuario){
    std::string entrada;
    std::cout << "Você tem certeza disso? (s/n): ";
    do {
        std::cin >> entrada;
    } while (!(entrada == "s" || entrada == "n"));

    if (entrada == "n")
        throw OperacaoInterrompida ("Cancelado");
    std::string senha;
    fflush(stdin);
    std::cout << "Digite sua senha para confirmar: ";
    std::cin >> senha;

    if(senha == usuario->get_senha()){
        std::string nome_do_arquivo = "saves/usuarios/" + usuario->get_nome() + ".txt";
        std::remove(nome_do_arquivo.c_str());

        Arquivos::deleta_linha ("saves/login.txt", usuario->get_email(), '#', 2);
        
        for (auto &x : (*usuario->get_livros())){
            x->muda_status();
            atualiza_arquivo_livros(x);
        }


        delete usuario;
        delete &usuario;
        std::cout << "Usuario removido\n";
    }

    else 
        std::cout << "Senha incorreta\n";
}

/*
Recebe um ponteiro para livro e um ponteiro para usuario
Chama a função de devolução de livro do usuario para remove-lo do set e do arquivo do usuario
Chama a função de atualizar arquivo de livros para salvá-lo como indisponível
*/
void Sistema::devolve_livro (Livro *livro, Usuario *usuario){
    usuario->devolve_livro(livro);
    atualiza_arquivo_livros(livro);
}

/*
Auxiliar da função remove livro da biblioteca
Recebe um ponteiro para um livro
Deleta o livro do arquivo de livros do usuario que possui ele no momento
Deleta o livro do map de historico
*/
void Sistema::remove_livro (std::string titulo){
    //RETIRANDO LIVRO DO USUARIO QUE O POSSUI
    
    if (!(_historicos.find(titulo)->second.empty())){
        
        std::string usuario = _historicos.find(titulo)->second.back();
        std::string nome_do_arquivo_usario = "saves/usuarios/" + usuario + ".txt";
        Arquivos::deleta_linha (nome_do_arquivo_usario, titulo);
        
    }


    
    _historicos.erase(titulo);
}

