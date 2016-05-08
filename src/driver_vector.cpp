#include <iostream>
#include "vector.h"

void mostrar(Vector<int> &lista) {
Vector<int>::iterator interador(lista);
std::cout << "Mostrando todos os elementos usando o iterador >>>>\n[";
for(unsigned int x = 0; x < lista.size(); x++) {
 std::cout << *interador << ", ";
 interador++;
}
std::cout << "]\n";
}

int main() {

Vector<int> lista;
std::cout << "A capacidade atual é " << lista.capacity() << " elementos, e o tamanho logico é de " << lista.size() << " elementos.\n";
std::cout << "Guardando 20 valores inteiros>>>>\n";
for(int x = 0; x < 20; x++)
 lista.at(x) = x;
std::cout << "A capacidade atual é " << lista.capacity() << " elementos, e o tamanho logico é de " << lista.size() << " elementos.\n\n";


mostrar(lista);

std::cout << "\nPrimeiro elemento: " << lista.front() << ".\n";
std::cout << "\nUltimo elemento: " << lista.back() << ".\n";

std::cout << "\nLimpando lista...";
lista.clear();
if(lista.empty())
 std::cout << " Vazia!!!\n\n";
else
  std::cout << " Falha!!!\n\n";

std::cout << "A capacidade atual é " << lista.capacity() << " elementos, e o tamanho logico é de " << lista.size() << " elementos.\n";
std::cout << "Guardando 20 valores inteiros om push_back()>>>>\n";
for(int x = 0; x < 20; x++)
 lista.push_back(x);
std::cout << "A capacidade atual é " << lista.capacity() << " elementos, e o tamanho logico é de " << lista.size() << " elementos.\n\n";

mostrar(lista);

std::cout << "Executando 3 pop_back()\'s\n";
lista.pop_back();
lista.pop_back();
lista.pop_back();

mostrar(lista);

std::cout << "\nAgora usando assing(42) >>>\n\n";

lista.assign(42);
mostrar(lista);

    std::cout << ">>>> Saida normal\n";
	return 0;
}