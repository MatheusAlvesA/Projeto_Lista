All:
	@echo "Escolha uma opção VECTOR, LISTA(lista comum) ou DLISTA(lista duplamente encadeada)"
VECTOR:
	@echo "Compilando o Vector..."
	@g++ -Wall -std=c++11 src/driver_vector.cpp -I include/ -g -o bin/lista
LISTA:
	@echo "A lista ainda não está pronta"
	@g++ -Wall -std=c++11 src/driver_vector.cpp -I include/ -g -o bin/lista
DLISTA:
	@echo "A lista duplamente encadeada ainda não está pronta"
	@g++ -Wall -std=c++11 src/driver_vector.cpp -I include/ -g -o bin/lista
clean:
	@echo "Limpando..."
	@rm bin/*
