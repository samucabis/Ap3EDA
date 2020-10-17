#include "graph.h"

#include <iostream>
#include <queue>
// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978

/*
        Construtor da classe graph
*/
graph::graph(ul size) {
    this->size = size;
    this->V = std::vector<vertex*>(size);

    for(ul i = 0; i < size; i++) {
        V[i] = new vertex(i);
    }
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

void graph::insert(ul chave_1, ul chave_2) {
    V[chave_1]->adj_list.push_back(V[chave_2]);
    V[chave_2]->adj_list.push_back(V[chave_1]);
}

/*      

        Função de pintar os vertices como a questão pede, primeiro a gente pinta todos os vertices como nulo.
        Depois a gente faz uma busca verificando se cada node foi pintado, se o node u for nulo então pinto de R senão 
        não mudamos sua cor. Em seguida percorremos cada vizinho v de u, e verificamos se a cor de u for R e v for nulo 
        pintamos v de B, caso contrario retornamos falso.


*/

bool graph::pintar() {
    for(vertex *v : this->V) {
        v->cor = SCOR;
        v->d = INF;
        v->pai = nullptr;
        v->visitei = false;
    }

    vertex *aux = this->V[0];
    aux->visitei = true;
    aux->d = 0;

    std::queue<vertex*> f = std::queue<vertex*>();

    f.push(aux);

    while(!f.empty()) {
        vertex *u = f.front();
        f.pop();

        if(u->cor == SCOR) {
            u->cor = R;
        }

        for(vertex *v : u->adj_list) {
            if(!v->visitei)
                f.push(v);

            v->visitei = true;
            v->d = u->d + 1;
            v->pai = u;

            if(u->cor == R) {
                if(v->cor == SCOR) {
                    v->cor = B;
                } else {
                    if(v->cor == R) {
                        return false;
                    }
                }
            }

            if(u->cor == B) {
                if(v->cor == SCOR) {
                    v->cor = R;
                } else {
                    if(v->cor == B) {
                        return false;
                    }
                }
            }

        }
    }

    return true;
}

/*
        Percorremos o vetor de vertices mostrando suas cores
 */

void graph::mostrar_cores() {
    for(vertex *v : this->V) {
        std::cout << v->chave << " ";
        if(v->cor == R) {
            std::cout << "R" << std::endl;
        } else if (v->cor == B){
            std::cout << "B" << std::endl;
        } else {
			std::cout << "SCOR" << std::endl;
        }
    }
}
