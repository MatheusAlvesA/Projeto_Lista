All:
	@echo "Escolha uma opção VECTOR, LISTA(lista comum) ou DLISTA(lista duplamente encadeada)"
VECTOR:
	@echo "Compilando o Vector..."
	@g++ -Wall -std=c++11 src/driver_vector.cpp -I include/ -g -o bin/vector
LISTA:
	@echo "Compilando Lista comum..."
	@g++ -Wall -std=c++11 src/driver_lista.cpp -I include/ -g -o bin/lista
DLISTA:
	@echo "Compilando Lista duplamente encadeada..."
	@g++ -Wall -std=c++11 src/driver_Dlista.cpp -I include/ -g -o bin/Dlista
clean:
	@echo "Limpando..."
	@rm bin/*