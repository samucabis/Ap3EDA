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
    Metodo de inserir o vertex no grafo, pegamos um par de inteiro com par de strings (que é o funcionario e o chefe), 
    e criamos um vertex  com o par de strings na posição do inteiro no vetor de vertex do grafo.
*/
void graph::insert(std::pair<int, pair<std::string, std::string>> par)
{
    V[par.first] = new vertex(par.second);
}

/*
    No metodo de ligamento, inserimos nos vetores adjacentes os vertices.
    Pegamos uma chave do vertice v que é um par de strings, a segunda string da chave 
    indica o chefe e procuramos no vetor de vertices um vertice u que possua na primeira 
    string da chave a mesma string de v segundo, e adicionamos na lista de adjacentes, fazemos 
    isso para o vetor inteiro de vertices.
*/

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

/*
    Função que retorna um par com o maior d, e o index de onde está esse d.
*/

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

/*
    Aqui é o metodo que executa o que pede a questão, pegamos o maior d e seu index,
    enquanto o maior for maior que 0 executamos o codigo, onde pegamos o vertice com
    maior d e "tiramos" ele da lista adjacente, e diminuimos o d de todos os vertices 
    que estão na lista adjacente dele ou que possuem ele na sua lista de adjacentes, 
    depois marcamos ele como expulso e modificamos seu d para -1.
    A ideia nisso tudo é se possivel zerar o d de todos, pois se o d for 0 indica que 
    a pessoa pode ir para festa, caso o d for menor que 0 ele foi eliminado da festa
    e caso o d seja maior que 0 temos que rodar de novo o paredao() até que o d seja 0 ou -1
*/
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

/*
    Metodo que printa a resposta, aqui contamos a quantidade de d's iguais a 0 e printamos
*/
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
/*
    Metodo que exibia o grafo, foi usado somente para debug e ver se o grafo estava corretamente povoado
    e se sua lista de adjacentes estava correta assim como o valor de d de cada vertice

*/
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