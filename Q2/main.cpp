#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "graph.h"

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978


using namespace std;

/*
		Aqui na main abrimos o arquivo grafos.txt e os valores são lidos como pedido no enunciado da questão 2
*/

bool verifica(std::string texto){
	if(texto == "1" || texto == "2" || texto == "3" || texto == "4" || texto == "5" 
								|| texto == "6" || texto == "7" || texto == "8" || texto == "9" || texto == "0" )
								return true;
	return false;
}

/*	
	Aqui na main, lemos o arquivo do txt e pegamos o primeiro elemento que é o n
	e criamos um graph com n, e depois lemos o segundo elemento do txt 
	que é o dono da empresa e criamos um vertice no grafo com o dono da empresa
	e depois executamos para cada linha adicionando um vertice com um par<string,string>
	até chegarmos no fim do primeiro teste.

*/

int main() {
	ifstream file = ifstream("grafos.txt");
	graph *g = nullptr;
	
	if(!file) {
		cout << "Arquivo grafos.txt nao encontrado" << endl;
	} else {

		int n;
		std::string c1, c2, c0;	
		std::pair<int,std::pair<std::string,std::string>> par;
		int aux;

		while(file >> n) {

			int cont = 0;

			if(n == 0)
				break;

			

			aux = n;	
			g = new graph(n);
			file>>c0;
			par	= make_pair(cont, make_pair(c0,""));
			g->insert(par);
			cont++;
			aux--;

			while(aux != 0) {
				file >> c1>>c2;
				if(verifica(c1))
					break;
				
				par	= make_pair(cont, make_pair(c1, c2));
				g->insert(par);
				cont++;
				
				aux--;
			}
			g->ligamento();
			//g->exibirGraph();
			g->paredao();
			g->vao();
			
			
		}
	}


    delete g;
    
    return 0;
}
