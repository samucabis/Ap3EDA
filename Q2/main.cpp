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
		Aqui na main abrimos o arquivo grafos.txt e os valores são lidos como pedido no enunciado da questão 1
*/

bool verifica(std::string texto){
	if(texto == "1" || texto == "2" || texto == "3" || texto == "4" || texto == "5" 
								|| texto == "6" || texto == "7" || texto == "8" || texto == "9" || texto == "0" )
								return true;
	return false;
}


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
				//cout<<par.first<<' '<<par.second.first<<' '<< par.second.second<<endl;
			}
			g->ligamento();
			g->exibirGraph();
			
			
		}
	}


    //delete g;
    
    return 0;
}
