#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "graph.h"

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978


using namespace std;

/*
		Aqui na main abrimos o arquivo grafos.txt e os valores são lidos como pedido no enunciado da questão 1
*/

int main() {
	ifstream file = ifstream("grafos.txt");
	graph *g = nullptr;
	
	if(!file) {
		cout << "Arquivo grafos.txt nao encontrado" << endl;
	} else {
		ul n, c1, c2;
		
		while(file >> n) {
			if(n == 0)
				break;
				
			g = new graph(n);
			
			while(file >> c1 >> c2) {
				if(c1 == 0 && c2 == 0)
					break;
					
				g->insert(c1, c2);
			}
			
			if(g->pintar()) {
				cout << "SIM" << endl;
				g->mostrar_cores();
			} else {
				cout << "NAO" << endl;
			}
		}
	}

    delete g;
    
    return 0;
}
