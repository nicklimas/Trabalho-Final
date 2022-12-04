# Sistema de Biblioteca

## Video mostrando o funcionamento do programa
https://youtu.be/FwcRnVhpkoo

## Diagrama de Classes
https://prnt.sc/EmhhnhJta5zb

## Como usar
- Para compilar apenas use o makefile
- Para executar o programa apenas abra o arquivo .exe criado pelo make file ou abra-o pelo terminal
- Para testar a funcionalidade do programa siga abaixo a descrição das funcionalidades 

## Descrição

Esse projeto foi criado para funcionar como uma biblioteca digital, que permite, aos seus administradores, cadastrar novos livros, ou remover livros existentes do sistema e acessar informações como os dados gerais da biblioteca ou o histórico de empréstimos de um livro específico. Aos usuários comuns, possibilita a visualização dos livros da biblioteca e suas informações(autor, categoria e sinopse), também oferece ferramentade busca por título, autor ou categoria, o usuário pode também fazer o empréstimo ou devolução de algum livro e ver dados da sua conta, como sua lista de empréstimos atual.

## Funcionalidades

### As funcionalidades mais básicas são utilizadas no menu inicial do sistema:

Funcionalidades do menu inicial:

1.Login: Utilizando as credenciais previamente cadastradas, pode-se fazer login em dois tipos de usuário, administrador ou usuário comum.

2.Cadastro: Cadastra um novo usuário no sistema, utilizando nome, e-mail e senha.

3.Sair: Encerra o sistema.

### As demais funcionalidades do sistema são divididas em duas categorias: funcionalidades de administrador e funcionalidades de usuário:

#### Funcionalidades de administrador:

1.Cadastro de novos livros, com título, autor, categoria, sinopse, número de páginas e sua localização na biblioteca física.

2.Remoção de um livro já cadastrado na biblioteca pelo seu título.

3.Visualização do histórico de empréstimo de um livro.

4.Visualização dos dados da biblioteca: o número total de livros e o número de usuários.

5.Sair: Faz o logout do admin e volta ao menu inicial.

#### Funcionalidades de usuário:

1.Ver a lista de todos os livros cadastrados na biblioteca.

2.Ver a lista de todos os autores cadastrados na biblioteca.

3.Ver a lista de todas as categorias cadastradas na biblioteca.

4.Ferramenta de busca, que pesquisa pelo termo em títulos, autores e categorias cadastrados.

5.Empréstimo de livros, de forma que caso o livro já esteja emprestado para outros usuário, o empréstimo não é feito.

6.Devolução de livros emprestados ao usuário.

7.Visualização da lista de livros emprestados ao usuário.

8.Visualização dos dados do usuário: Número de livros emprestados e seus títulos.

9.Opção de deletar a conta do sistema.

10.Sair: Faz o logout do usuário e volta ao menu inicial.

## Para gerar a documentação no Windows, siga o passo a passo:

1. Faça o download do instalador do Doxygen em https://www.doxygen.nl/download.html. Procure por: "A binary distribution for Windows. All 64bit versions of Windows are supported". Utilizando o Windows Explorer, acesse o local onde o arquivo foi salvo (por padrão, Downloads). Utilize um duplo clique no arquivo doxygen-1.7.6.1-setup.exe para executar o instalador do Doxygen.

2. Faça o download do instalador do Graphviz em http://graphviz.org/pub/graphviz/stable/windows/graphviz-2.28.0.msi. O instalador do Graphviz é bem simples, apenas siga as instruções do instalador.

3. Execute o Doxygen.

4. Na pagina aberta, preencha com:
working directory: (o diretório-raiz onde o projeto se encontra).
Project name: Biblioteca
Project version or id: 1.0.
Source code directory: Trabalho-final. Marque a opção Scan recursively.
Destination directory: (local onde deseja criar a documentação.)

5. Em Wizard / Mode:
extraction mode: Documented entities only. 
programming language: C++.

6. Em Wizard / Output:
HTML. Selecione também With search function.

7. Em Wizard / Diagrams:
Marque a opção Use dot tool from the GraphViz package e marque abaixo as opções de gráficos que deseja gerar.

8. Em Expert / Project:
TYPEDEF_HIDES_STRUCT: marcado.
 
9. Em Expert / Build:
EXTRACT_STATIC: marcado.
EXTRACT_LOCAL_METHODS: marcado.

10. Em Expert / Messages:
WARN_NO_PARAMDOC: marcado. 
 
11. Em Expert / Source Browser:
VERBATIM_HEADERS: não marcado. 

12. Expert / Index
ALPHABETICAL_INDEX: não marcado.
 
13. Em Expert / Dot:
HAVE_DOT: marcado.
UML_LOOK: marcado.
DOT_PATH:  A localização do dot instalado anteriormente.

14. Para executar Doxygen de dentro do Doxywizard, abra o Doxyfile (presente dentro  do projeto) no Doxywizard, vá para a aba Run e então clique no botão Run doxygen. Clique em Show HTML output para ver a documentação gerada. Também pode ser acessada em "index.html" na pasta de documentação gerada.

- Passo a passo baseado em: https://inacioferrarini.wordpress.com/pt-br/documentation/doxygen/


## Autores

Arthur Ferreira Vilela

Gabriel Cardoso Peroni

Mariana Pinho Barroso Sousa

Nicolas Limas Nascimento

Samantha Kelly de Souza Sena
