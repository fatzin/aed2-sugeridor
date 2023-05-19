#ifndef ABBAVL_H
#define ABBAVL_H

#include <string>
#include <vector>

/*

    Arquivo de header com todas as declarações de funçoes
    para a construçao da arvore

*/
class Node {
public:
    std::string palavra;
    int altura;
    Node* esquerda;
    Node* direita;

    Node(const std::string& w);
};

class AVL {
private:
    Node* raiz;

public:
    AVL();

    void insert(const std::string& palavra);
    std::vector<std::string> search(const std::string& prefix);

private:
    int getAltura(Node* node);
    int getBalanceamento(Node* node);
    Node* rotacionarEsquerda(Node* node);
    Node* rotacionarDireita(Node* node);
    Node* inserirPalavra(Node* node, const std::string& palavra);
    void procurarPalavra(Node* node, const std::string& prefix, std::vector<std::string>& resultado);
};

#endif // ABBAVL_H
