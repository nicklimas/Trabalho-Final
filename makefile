CC := g++
FLAGS := -I thrid_party/ -I include/ -Wall
BUILD := build/
SRC := src/
TESETDIR := tests/
TEST := teste.exe
TARGET := biblioteca.exe

all: main

$(BUILD):
	@mkdir $(BUILD)

main: sistema biblioteca arquivos
	$(CC) $(FLAGS) $(BUILD)arquivos.o $(BUILD)sistema.o $(BUILD)biblioteca.o $(BUILD)pessoa.o $(BUILD)usuario.o $(BUILD)autor.o $(BUILD)admin.o  $(BUILD)livro.o $(SRC)main.cpp -o $(TARGET)

test: sistema biblioteca arquivos
	$(CC) $(FLAGS) $(BUILD)arquivos.o $(BUILD)sistema.o $(BUILD)biblioteca.o $(BUILD)pessoa.o $(BUILD)usuario.o $(BUILD)autor.o $(BUILD)admin.o  $(BUILD)livro.o $(TESETDIR)teste.cpp -o $(TEST)

admin:
	$(CC) $(FLAGS) -c $(SRC)pessoas/admin.cpp -o $(BUILD)admin.o

usuario:
	$(CC) $(FLAGS) -c $(SRC)pessoas/usuario.cpp -o $(BUILD)usuario.o

pessoa: usuario  admin  
	$(CC) $(FLAGS) -c $(SRC)pessoas/pessoa.cpp -o $(BUILD)pessoa.o

livro: 
	$(CC) $(FLAGS) -c $(SRC)livro/livro.cpp -o $(BUILD)livro.o

biblioteca: livro 
	$(CC) $(FLAGS) -c $(SRC)biblioteca/biblioteca.cpp -o $(BUILD)biblioteca.o

sistema: pessoa 
	$(CC) $(FLAGS) -c $(SRC)biblioteca/sistema.cpp -o $(BUILD)sistema.o

arquivos:
	$(CC) $(FLAGS) -c $(SRC)biblioteca/arquivos.cpp -o $(BUILD)arquivos.o

clean:	
	$(RM) -r $(BUILD)*$(TARGET)