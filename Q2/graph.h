#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <limits>
#include <list>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define INF std::numeric_limits<int>::max()

/*
    Classe graph, aqui temos os atributos do grafo.
*/
class graph {
private:
    int size;
    std::vector<vertex*> V;

public:
    graph(int);
    ~graph();

    void insert(std::map<int,string> v1);
    void insert(std::map<int,string> v1, string v2);
    void mostrar_cores();
    bool pintar();
};




#endif // GRAPH_H

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978