#include <iostream>
#include <cstdio>
#include <locale>
#include <cstdlib>
#include <stdio.h>
#include "../include/biblioteca/sistema.hpp"
#include "../include/biblioteca/biblioteca.hpp"



int main (){
    try{

        setlocale(LC_ALL, "portuguese");


        //Inicia o sistema e a biblioteca
        Sistema sistema = Sistema ();
        Biblioteca biblioteca = Biblioteca ();
        

        std::cout << "\nBEM-VINDO AO SISTEMA DA BIBLIOTECA\n";   

        //Loop do programa

        while (std::cin) {

            Pessoa *login = new Pessoa ();
            std::string entrada;

            fflush(stdin);

            //MENU PRINCIPAL
            do {
                std::cout << "--------------------------------------"<<std::endl;
                std::cout << "\nPara logar digite: login\nPara cadastrar digite: cadastrar\nPara finalizar o programa digite: sair\n\nDigite o seu comando: ";
                
                std::cin >> entrada;
                
                //cadastra um usuário
                if (entrada == "cadastrar"){
                    fflush(stdin);
                    std::cout << std::endl;

                    sistema.cadastra_usuario();

                    std::cout << "\nUSUÁRIO CADASTRADO\n";
                }

                if (!(entrada == "login" || entrada == "sair"))
                    std::cout << "Entrada Inválida\n";
                    
            } while (!(entrada == "login" || entrada == "sair"));

            fflush(stdin);
            
            //finaliza o programa
            if(entrada == "sair"){
                break;
            }


            //login
            if (entrada == "login"){
                try { 

                    login = sistema.login(); 

                    std::cout << "\n--------------------------------------\n";
                }

                catch (OperacaoInterrompida &e){
                    std::cout << e.what() << std::endl;
                    std::system("pause");
                }
            }
                

            //MENU DO ADMINISTRADOR
            if (login->get_classe() == "admin"){

                Admin admin = Admin (login->get_email(), login->get_senha());

                std::cout << "BEM-VINDO À ÁREA DO ADMINISTRADOR";

                //loop do administrador
                while (std::cin){

                    std::cout << "\n--------------------------------------\n\n";
                    std::cout << "Para ver a lista de livros digite: livros\n"
                            << "Para adcionar um livro à biblioteca digite: adcionar\n" 
                            << "Para remover um livro da biblioteca digite: remover\n"
                            << "Para ver o histórico de usuarios de um livro digite: historico\n"
                            << "Para ver os dados da biblioteca digite: dados\n"
                            << "Para sair digite: sair\n"
                            << "\nDigite o seu comando: ";
                    
                    std::string entrada;

                    while (std::cin){

                        std::cin >> entrada;
                        std::cout << std::endl;


                        if (entrada == "livros"){
                            fflush(stdin);
                            std::cout << "Livros:\n";
                            biblioteca.lista_livros();
                            std::cout << std::endl;
                            std::system("pause");
                            break;
                        }

                        if (entrada == "adcionar"){
                            fflush(stdin);
                            std::cout << "ADCIONANDO LIVRO\n\n";
                            try{ 
                                Livro *livro = biblioteca.adciona_livro(); 
                                if (livro != nullptr)
                                    sistema.cria_historico(livro->get_titulo());
                            }
                            catch (ErroaAbrirArquivo &e){
                                std::cout << e.what();
                            }
                            catch (OperacaoInterrompida &e){
                                std::cout << e.what();
                                 
                            }
                            std::system("pause");
                            break;
                        }

                        if (entrada == "remover"){
                            fflush(stdin);
                            std::string livro;
                            std::cout << "Digite o nome do livro que deseja remover: ";
                            getline (std::cin, livro);
                            if(biblioteca.get_livros()->find(livro) == biblioteca.get_livros()->end()){
                                std::cout << "Livro não encontrado\n";
                                std::system("pause"); 
                                break;
                            }

                            std::cout << "Tem certeza que deseja remover o livro " << livro << " ?(s/n): ";
                            std::string confrima;
                            std::cin >> confrima;

                            if(confrima == "s"){
                                try{
                                    sistema.remove_livro (livro);
                                    biblioteca.remove_livro(biblioteca.get_livros()->find(livro)->second);
                                } catch (ErroaAbrirArquivo &e){
                                    std::cout << e.what() << std::endl;
                                    break;
                                    std::system("pause"); 
                                }
                            }
                            
                            std::system("pause"); 
                            break;                                 
                        }
                                          
                        if(entrada == "historico"){
                            fflush(stdin);
                            std::cout << "Digite o nome do livro que deseja ver o histórico: ";
                            std::string livro;
                            getline (std::cin, livro);

                            if(biblioteca.get_livros()->find(livro) == biblioteca.get_livros()->end())
                                std::cout << "Livro não encontrado\n";

                            else{
                                sistema.get_historico(livro);
                                std::system("pause");
                            }

                            break;
                        }

                        if(entrada == "dados"){
                            try { std::cout << admin.view_dados(); }
                            catch (ErroaAbrirArquivo &e){
                                std::cout << e.what(); 
                            }
                            std::system("pause");
                            break;
                        }

                        if(entrada == "sair")
                            break;
                        
                        else 
                            std::cout << "Comando inválido\n";
                    }

                    fflush(stdin);

                    if(entrada == "sair"){
                        std::cout << "Você finalizou sua sessão e será redirecionado para o menu principal\n";
                        std::system("pause");
                        break;
                    }
                }
                
                delete &admin;
            }


            //MENU DO USUARIO
            if (login->get_classe() == "usuario"){
                Usuario usuario = Usuario (login->get_nome(), login->get_email(), login->get_senha());
                usuario.inicia_set_livros (biblioteca.get_livros());

                std::cout << "BEM-VINDO À ÁREA DO VISITANTE";

                //loop do usuario
                while (std::cin){

                    std::cout << "\n--------------------------------------\n\n";
                    std::cout << "Para fazer uma busca digite: busca\n\n"
                            << "Para ver a lista de livros digite: livros\n"
                            << "Para ver a lista de autores digite: autores\n"
                            << "Para ver a listade categorias digite: categorias\n\n"
                            << "Para pegar algum livro você primeiro deve fazer uma busca\n"
                            << "Para devolver algum livro digite: devolver \n\n"
                            << "Para ver os livros que você possui digite: lista\n"
                            << "Para ver os dados da sua conta digite: dados\n"
                            << "Para deletar sua conta digite: deletar (exige confirmação)\n\n"
                            << "Para sair digite: sair\n"
                            << "\nDigite o seu comando: ";

                    std::string entrada;

                    while (std::cin){
                        fflush(stdin);
                        std::cin >> entrada;
                        std::cout << std::endl;

                        if(entrada == "busca"){
                            fflush(stdin);
                            std::string pesquisa;
                            std::cout << "Digite o nome de um livro, de um autor ou de uma categoria: ";
                            getline (std::cin, pesquisa);
                            Livro *livro = nullptr;
                            try {livro = biblioteca.find_livro(pesquisa); }
                            catch (OperacaoInterrompida &e){
                                std::cout << e.what(); 
                                std::system("pause");
                                break;
                            }
                            livro->view_dados();
                            if (livro->get_status()){
                                std::cout << "O livro não está disponível para emprestímo\n";
                                std::system("pause");
                                break;
                            }
                            if (!(livro->get_status())){
                                std::string emprestimo;
                                std::cout << "Deseja pegar esse livro emprestado? (s/n): ";
                                do{
                                    std::cin >> emprestimo;
                                } while (!(emprestimo == "s" || emprestimo == "n"));

                                if(emprestimo == "n")
                                    break;
                                
                                if(emprestimo == "s"){
                                    sistema.pega_livro(livro, &usuario);
                                    std::cout << "\nLivro emprestado\n";
                                    std::system("pause");
                                    break;
                                }
                                
                                
                            }
                        

                        }

                        if(entrada == "livros"){
                            std::cout << "Livros:\n";
                            biblioteca.lista_livros();
                            std::cout << std::endl;
                            std::system("pause");
                            break;
                        }
                        
                        if(entrada == "autores"){
                            std::cout << "Autores:\n";
                            biblioteca.lista_autores();
                            std::cout << std::endl;
                            std::system("pause");
                            break;
                        }

                        if(entrada == "categorias"){
                            std::cout << "Categorias:\n";
                            biblioteca.lista_categorias();
                            std::cout << std::endl;
                            std::system("pause");
                            break;
                            }

                        if(entrada == "devolver"){
                            fflush(stdin);
                            if (usuario.get_livros()->empty()){
                                std::cout << "Você não possui livros\n";
                                std::system("pause");
                                break;
                            }

                            std::string livro;
                            std::cout << "Digite o nome do livro que deseja devolver: ";
                            getline (std::cin, livro);
                            if(usuario.get_livros()->find(biblioteca.get_livros()->find(livro)->second) == usuario.get_livros()->end())
                                std::cout << "Livro não encontrado\n";
                            else
                                usuario.devolve_livro(biblioteca.get_livros()->find(livro)->second);
                            std::system("pause");
                            break;
                        }

                        if(entrada == "lista"){
                            std::cout << usuario.view_livros() << std::endl << std::endl;
                            std::system("pause");
                            break;
                        }

                        if(entrada == "dados"){
                            std::cout << usuario.view_dados();
                            std::system("pause");
                            break;
                        }

                        if(entrada == "deletar"){
                            try {
                                sistema.deletar_usuario(&usuario);
                                break;
                                }
                            catch (ErroaAbrirArquivo &e){
                                std::cout << e.what(); 
                            }
                            catch (OperacaoInterrompida &e){
                                std::cout << e.what();
                                break;
                            }
                        }

                        if(entrada == "sair" || entrada == "deletar")
                            break;

                        else 
                            std::cout << "Comando inválido\n";
                    }

                    fflush(stdin);

                    if(entrada == "sair" || entrada == "deletar"){
                        std::cout << "Você finalizou sua sessão e será redirecionado para o menu principal\n";
                        std::system("pause");
                        break;
                    }
                }
                
                delete &usuario;
            }

            delete login;
                    
        }

    //finalização do programa

    std::cout << "\nPROGRAMA FINALIZADO\n--------------------------------------";
    return 0;

    } catch (ErroaAbrirArquivo &e){
        std::cout << e.what(); 
    } catch (OperacaoInterrompida &e){
        std::cout << e.what(); 
    }
}