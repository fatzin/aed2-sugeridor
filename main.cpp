#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ABBAVL.h"

int main() {

    //inicializando uma arvore
    AVL avl;

    /*
        Pode se alterar o arquivo de texto para qualquer um dos outros no repositorio
        (????????) = talvez seja
        palavras1472.txt -> palavras mais usadas (????????)
        palavras29000.txt -> palavras mais recorrentes (????????) 
        palavras245366.txt -> palavras da língua portuguesa com verbos conjugados   
    */
    std::ifstream palavras("palavras29000.txt");
    std::string palavra;

    //lê as palavras do arquivo e insere na arvore
    std::cout << "Adicionando palavras na arvore. . ." << std::endl;
    if (palavras.is_open()) {
        while (std::getline(palavras, palavra)) {
            avl.insert(palavra);
        }
        palavras.close();
    } else {
        std::cerr << "Falha ao abrir o arquivo de palavras." << std::endl;
        return 1;
    }

    std::string prefix;
    std::vector<std::string> resultado;

    std::cout << "Palavras carregadas!" << std::endl;
    std::cout << "Para sair digite 0 a qualquer momento :)" << std::endl;
    std::cout << "\n";
    while (true) {
        std::cout << "Digite um prefixo: ";
        std::cin >> prefix;

        if (prefix == "0") {
            break;
        }
        //atribui ao vetor resultado todas as strings encontradas com o prefixo pedido
        resultado = avl.search(prefix);
        std::cout << "Palavras correspondentes:" << std::endl;
        //printa todas as palavras do vetor resultado
        for (const std::string& palavra : resultado) {
            std::cout << palavra << std::endl;
        }
        std::cout << "\n";
    }

    return 0;
}
