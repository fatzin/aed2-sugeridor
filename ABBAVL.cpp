#include "ABBAVL.h"
#include <algorithm>

Node::Node(const std::string& w) : palavra(w), altura(1), esquerda(nullptr), direita(nullptr) {}

AVL::AVL() : raiz(nullptr) {}

void AVL::insert(const std::string& palavra) {
    raiz = inserirPalavra(raiz, palavra);
}

std::vector<std::string> AVL::search(const std::string& prefix) {
    std::vector<std::string> resultado;
    procurarPalavra(raiz, prefix, resultado);
    return resultado;
}
/*

    Funções auxiliares para descobrir altura e balanceamento de nós

*/
int AVL::getAltura(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->altura;
}

int AVL::getBalanceamento(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getAltura(node->esquerda) - getAltura(node->direita);
}

/*

    Funções para rotacionar nós na árvore

*/
Node* AVL::rotacionarEsquerda(Node* node) {
    Node* novaRaiz = node->direita;
    Node* subarvore = novaRaiz->esquerda;

    novaRaiz->esquerda = node;
    node->direita = subarvore;

    node->altura = std::max(getAltura(node->esquerda), getAltura(node->direita)) + 1;
    novaRaiz->altura = std::max(getAltura(novaRaiz->esquerda), getAltura(novaRaiz->direita)) + 1;

    return novaRaiz;
}


Node* AVL::rotacionarDireita(Node* node) {
    Node* novaRaiz = node->esquerda;
    Node* subarvore = novaRaiz->direita;

    novaRaiz->direita = node;
    node->esquerda = subarvore;

    node->altura = std::max(getAltura(node->esquerda), getAltura(node->direita)) + 1;
    novaRaiz->altura = std::max(getAltura(novaRaiz->esquerda), getAltura(novaRaiz->direita)) + 1;

    return novaRaiz;
}
/* --------------------------------------------------------------------------------------------- */

//funcao para inserir palavras na árvore efetuando o balanceamento de acordo com o fator de cada nó
Node* AVL::inserirPalavra(Node* node, const std::string& palavra) {
    if (node == nullptr) {
        return new Node(palavra);
    }

    if (palavra < node->palavra) {
        node->esquerda = inserirPalavra(node->esquerda, palavra);
    } else if (palavra > node->palavra) {
        node->direita = inserirPalavra(node->direita, palavra);
    } else {
        return node; // Palavra já existe na árvore
    }

    node->altura = std::max(getAltura(node->esquerda), getAltura(node->direita)) + 1;

    int fatorBalanceamento = getBalanceamento(node);

    // Casos de rotação para balanceamento
    if (fatorBalanceamento > 1 && palavra < node->esquerda->palavra) {
        return rotacionarDireita(node);
    }

    if (fatorBalanceamento < -1 && palavra > node->direita->palavra) {
        return rotacionarEsquerda(node);
    }

    if (fatorBalanceamento > 1 && palavra > node->esquerda->palavra) {
        node->esquerda = rotacionarEsquerda(node->esquerda);
        return rotacionarDireita(node);
    }

    if (fatorBalanceamento < -1 && palavra < node->direita->palavra) {
        node->direita = rotacionarDireita(node->direita);
        return rotacionarEsquerda(node);
    }

    return node;
}

//função para procurar palavra na árvore e armazenar no vetor de resultados
void AVL::procurarPalavra(Node* node, const std::string& prefix, std::vector<std::string>& resultado) {
    if (node == nullptr) {
        return;
    }

    if (node->palavra.substr(0, prefix.length()) >= prefix) {
        procurarPalavra(node->esquerda, prefix, resultado);
    }

    if (node->palavra.substr(0, prefix.length()) == prefix) {
        resultado.push_back(node->palavra);
    }
    if (node->palavra.substr(0, prefix.length()) <= prefix) {
        procurarPalavra(node->direita, prefix, resultado);
    }
}
