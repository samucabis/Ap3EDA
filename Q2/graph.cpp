#include "graph.h"

#include <iostream>
#include <queue>
#include <list>
#include <string>

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978

/*
        Construtor da classe graph
*/
int cont = 0;
graph::graph(int size) {
    this->size = size;
    this->V = std::vector<vertex*>(size);

}

/*
        Destrutor da classe
*/
graph::~graph() {
    V.clear();
}

/*
        Função de inserir, ela recebe dois valores e depois procura no vetor de vértices o vertice certo para inserir o valor que será seu vizinho.
*/
void graph::insert(std::map<int,string> v1) {
    V[cont] = new vertex(v1);
    cont++;
}
void graph::insert(std::map<int,string> v1, string v2) {


}

/*      

        Função de pintar os vertices como a questão pede, primeiro a gente pinta todos os vertices como nulo.
        Depois a gente faz uma busca verificando se cada node foi pintado, se o node u for nulo então pinto de R senão 
        não mudamos sua cor. Em seguida percorremos cada vizinho v de u, e verificamos se a cor de u for R e v for nulo 
        pintamos v de B, caso contrario retornamos falso.


*/