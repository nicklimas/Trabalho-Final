#include "../../include/biblioteca/arquivos.hpp"

/*  
-Recebe:    o endereço de um arquivo com apenas uma informação por linha 
            o termo que é para se encontrado

-Deleta a linha do arquivo que tem esse termo 
*/
void Arquivos::deleta_linha (std::string arquivo, std::string termo){

    std::fstream file;
    std::string linha;
    std::vector <std::string> texto;

    //Lendo o arquivo e salvando as linhas necessárias

    file.open (arquivo);

    if(!(file))
        throw ErroaAbrirArquivo (arquivo);
    
   
    while (getline(file, linha)) {
        if (linha != termo)
            texto.push_back (linha); 
   }

    file.close();

    //Reescrevendo arquivo

    file.open(arquivo, std::ios::out);

    for (auto &x : texto)
        file<< x << std::endl;
    
    file.close();
    
}


/*  
-Recebe:    o endereço de um arquivo com mais de uma informação por linha 
            o termo que é para se encontrado
            o separador utilizado para separar as informações na linha
            a posição da informação na linha

-Deleta a linha do arquivo que tem esse termo 
*/
void Arquivos::deleta_linha (std::string arquivo, std::string termo, char separador, int posicao){

    std::fstream file;
    std::string linha;
    std::vector <std::string> texto;

    // Lendo arquivo e salvando as linhas

    file.open (arquivo);

    if(!(file))
            throw ErroaAbrirArquivo (arquivo);
        
    while (getline(file, linha)) {

            std::stringstream line(linha);
            std::string comparador;

            for (int i = 0; i < posicao; i++)
                getline(line, comparador, separador);
            
            if (comparador != termo)
                texto.push_back (linha); 
    }

    file.close();

    // Reescrevendo o arquivo

    file.open(arquivo, std::ios::out);

    for (auto &x : texto)
            file<< x << std::endl;
        
    file.close();
}


/*  
-Recebe:    o endereço de um arquivo 
            a linha que é para ser adcionada
                
-Adciona a linha ao arquivo 
*/
void Arquivos::adciona_linha (std::string arquivo, std::string linha){

    std::fstream file;

    file.open(arquivo, std::ios::app);

    if (!file)
        throw ErroaAbrirArquivo ("login.txt");

    file << linha << std::endl;
    file.close();
}


/*  
-Recebe:    o nome do arquivo
                
-Cria o arquivo 
*/
 void Arquivos::cria_arquivo (std::string nome){

    std::fstream file (nome, std::ios::out);
    file.close();
    
 }