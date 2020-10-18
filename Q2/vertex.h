#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <string>
#include <map>

// NOME: JOSE GABRIEL BERNARDES DE ALMEIDA E SAMUEL RIBEIRO BEZERRA 
// MATRICULA: 403958 / 393978

/*
        Classe vértice, onde tem os atributos da classe.
        R e B são as cores e SCOR quer dizer que não foi pintado ainda.
*/
enum cores {R, B, SCOR};

class vertex {
public:
    std::pair<std::string,std::string> chave;
    int d;
    std::string valor;
    cores cor;
    vertex *patrao;
    bool expulso;
    std::vector<vertex*> adj_list;

    vertex(std::pair<std::string,std::string>);
    ~vertex();

    void make_pair(vertex*);
};

#endif // VERTEX_H
