#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>
#define ul unsigned long

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978

/*
        Classe vértice, onde tem os atributos da classe.
        R e B são as cores e SCOR quer dizer que não foi pintado ainda.
*/
enum cores {R, B, SCOR};

class vertex {
public:
    ul chave;
    ul d;
    std::string valor;
    cores cor;
    vertex *pai;
    bool visitei;
    std::vector<vertex*> adj_list;

    vertex(ul);
    ~vertex();

    void make_pair(vertex*);
};

#endif // VERTEX_H
