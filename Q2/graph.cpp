#include "graph.h"

#include <iostream>
#include <queue>
#include <list>
#include <string>
int cont = 0;
// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA
// MATRICULA: 403958 / 393978

/*
        Construtor da classe graph
*/
graph::graph(int size)
{
    this->size = size;
    this->V = std::vector<vertex *>(size);
}

void graph::insert(std::pair<int, pair<std::string, std::string>> par)
{
    V[par.first] = new vertex(par.second);
    //V[par.first]->adj_list.push_back(V[retornaPatrao(par.second.second).indice]);
}
void graph::ligamento()
{
    for (int i = 0; i < V.size(); i++)
    {

        for (int j = 0; j < V.size(); j++)
        {
            if (V[i]->chave.second == V[j]->chave.first)
            {
                V[j]->d++;
                V[i]->d++;
                V[i]->adj_list.push_back(V[j]);
                V[j]->adj_list.push_back(V[i]);
                break;
            }
        }
    }
}
void graph::paredao()
{
    int maior, index = 0;
    maior = V[0]->d;
    for (int i = 0; i < V.size(); i++)
    {

        if (V[i]->d > maior)
        {
            index = i;
            maior = V[i]->d;
        }
    }
}
void graph::exibirGraph()
{
    for (vertex *v : V)
    {
        cout << v->chave.first << endl;
        cout << "Adjacentes: "
             << "(" << v->d << ") ";
        for (int i = 0; i < v->adj_list.size(); i++)
        {
            cout << "-" << v->adj_list.at(i)->chave.first;
        }
        cout << endl;
    }
}