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

/*
    Metodo de inserir o vertex no grafo,
*/
void graph::insert(std::pair<int, pair<std::string, std::string>> par)
{
    V[par.first] = new vertex(par.second);
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

std::pair<int,int> graph::Maximo(){
    pair<int,int> par = make_pair(0,-1);
    for(int i = 0; i < V.size(); i++){
            if(V[i]->d > par.second && !V[i]->expulso){
                par.second = V[i]->d;
                par.first = i;
            }
     }
    return par;
}

void graph::paredao()
{
    int maior,index;
    maior = Maximo().second;
    index = Maximo().first;
    while(maior--){
        if(V.size() == 2)
            break;
        if(Maximo().second == 0)
            break;
        maior = Maximo().second;
        index = Maximo().first;
        V[index]->d = -1;
        V[index]->expulso = true;
        for( vertex* v : V[index]->adj_list){
            v->d--;
        }
    }  

}
void graph::vao(){
    cont = 0;
    if(V.size() > 2){
        for( vertex *v : V){
            if(v->d == 0)
                cont++;
        }
    }else{
        cout << V[0]->d <<  " Não" << endl;
        return;
    }
    cout << cont << " Sim" << endl;
    
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