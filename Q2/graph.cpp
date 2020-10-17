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
graph::graph(ul size) {
    this->size = size;
    V = new std::list<std::string>[size];
}

void graph::insert(std::string v1, std::string v2){
    V[v1].push_back(v2);
}