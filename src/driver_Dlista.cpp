#include <iostream>
#include "DFlist.h"

void mostrar(List<int> &lista) {
List<int>::iterator itr = lista.begin(); //criando um interador para a lista começando no valor head
 try {
  while(itr.ptr()->next != nullptr) {
    std::cout << *itr << std::endl;
    itr++;
   }
 }
 catch(std::runtime_error erro) {
     std::cout << "ERRO em tempo de execução, linha 12 do driver_lista.cpp\n";
 }
}

int main() {
List<int> lista; // criando a lista

lista.push_front(2);
lista.push_front(3);
lista.push_front(4);
lista.push_front(6);
List<int>::iterator interador = lista.begin(); //criando um interador para a lista começando no node 5

lista.insert_after(interador, 5); // inserindo valor apos o 5, que nesse caso é antes do 3
lista.push_back(1); // colocando na posição devida

if(!lista.empty()) {
  std::cout << "O tamanho é: " << lista.size() << "\n\n";
  mostrar(lista); // mostrando atravez do interador
}
else {
	std::cout << "A lista está vazia.\n";
}

std::cout << "Deletando elemento...\n";
interador = lista.begin(); // resetando o valor de iterator ois ele pode ter sido deletado
lista.erase_after(interador);
std::cout << "Agora o tamanho é: " << lista.size() << "\n\n";
mostrar(lista);

std::cout << "Executando um pop_back: " << lista.pop_back() << std::endl;
std::cout << "Executando um pop_front: " << lista.pop_front() << std::endl;

std::cout << "\nO elemento da frente é: " << lista.front() << "\n";
std::cout << "O elemento da cauda é: " << lista.back() << "\n";

std::cout << "\nUsando o assign com o valor 42\n";
lista.assign(42);
std::cout << "Agora o tamanho é: " << lista.size() << "\n\n";
mostrar(lista);

std::cout << "\nLimpando completamente\n";
lista.clear();
std::cout << "Agora o tamanho é: " << lista.size() << "\n\n";

std::cout << "_________________________________________________________________";
std::cout << "\nInserindo muitos dados...\n";
List<int>::iterator head = lista.before_begin(); //criando um interador para a lista começando no valor head
lista.insert_after(head, 1); // grava no inicio
lista.push_back(2);
lista.push_back(3);
lista.push_back(4);
lista.push_back(5);
lista.push_back(6);
lista.push_back(7);
lista.push_back(8);
std::cout << "Agora o tamanho é: " << lista.size() << ", e o ultimo é: " << *(lista.end()) << "\n\n";
mostrar(lista);

try {
std::cout << "\nBuscando o valor 5: " << *(lista.find(5)) << "\n\n";
}
catch(std::runtime_error erro) {
std::cout << "\nNão encontrado\n\n";
}

std::cout << "Deletando elementos do 3 ao 6...\n";
interador = lista.begin(); // resetando o valor de iterator pois ele pode ter sido deletado
interador++; // posição 2
interador++; // posição 3
List<int>::iterator interador2 = interador.ptr(); //criando o do final
interador2++; // posição 4
interador2++; // posição 5
interador2++; // posição 6
lista.erase_after(interador, interador2);
std::cout << "Agora o tamanho é: " << lista.size() << "\n\n";
mostrar(lista);

    std::cout << "\n>>>> Saida normal\n";
	return 0;
}
