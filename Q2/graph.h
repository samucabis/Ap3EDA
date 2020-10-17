#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <limits>
#include <list>
#define INF std::numeric_limits<int>::max()

/*
    Classe graph, aqui temos os atributos do grafo.
*/
class graph {
private:
    unsigned long size;
    std::list<std::string> *V;

public:
    graph(ul);
    ~graph();

    void insert(std::string v1, std::string v2);
    void mostrar_cores();
    bool pintar();
};

#endif // GRAPH_H

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978