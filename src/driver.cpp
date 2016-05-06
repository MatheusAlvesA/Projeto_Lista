#include <iostream>
#include "vector.h"
int main() {

Vector<int> lista;

for(int x = 0; x < 20; x++)
 lista[x] = x;

for(int x = 0; x < 20; x++)
 std::cout << lista[x] << "\n";

    std::cout << ">>>> Saida normal\n";
	return 0;
}