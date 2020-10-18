#include "vertex.h"
#include <map>

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978

/*
   	 Construtor da classe vértice.
 */

vertex::vertex(std::pair<std::string,std::string> chave) {
    this->chave = chave;
    this->d = 0;
    this->patrao = nullptr;
    this->visitei = false;
    this->adj_list = std::vector<vertex*>();
}

vertex::~vertex() {}

/*
        Função que inseri o ponteiro do vértice e insere na lista de adjacências.
 */
void vertex::make_pair(vertex *v) {
    this->adj_list.push_back(v);
}
