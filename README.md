# Sugeridor de palavras

## Compilando o projeto

```terminal
g++ main.cpp ABBAVL.cpp -O2 -o pesquisa
```

## Como testar o projeto

- Compilar o programa
- Aguardar as palavras serem carregadas
- Escrever o prefixo da palavra que está buscando no terminal

## Complexidade do código

- A complexidade da inserção em uma árvore AVL é: $$ O(\log(n)) $$ onde n é o número de elementos na árvore. Isso ocorre porque a inserção envolve a busca pelo local correto na árvore e possíveis rotações para manter o balanceamento.

- A complexidade da busca em uma árvore AVL também é: $$ O(\log(n)) $$pois envolve percorrer a árvore em busca dos elementos correspondentes ao prefixo fornecido.
- A complexidade da leitura das palavras do arquivo e construção da árvore AVL é $$ O(m\* \log(n)) $$ onde m é o número de palavras no arquivo e n é o número total de palavras inseridas na árvore. Isso ocorre porque para cada palavra lida do arquivo, é realizada a inserção na árvore AVL, cuja complexidade é O(log n).
- A complexidade da impressão das palavras correspondentes ao prefixo fornecido depende do número de palavras correspondentes encontradas. Se houver k palavras correspondentes, a complexidade será $$ O(k) $$ pois precisamos imprimir cada uma delas.

Fonte: [1](<https://www.freecodecamp.org/portuguese/news/insercao-rotacao-e-fator-de-balanceamento-da-arvore-avl-explicados/#:~:text=As%20árvores%20AVL%20têm%20uma%20complexidade%20de%20tempo%20de%20busca,caso%20é%20O(n)%20.>)

## Limitações

O sugeridor de palavras implementado com a árvore AVL possui algumas limitações:

1.  Sensibilidade ao caso: O sugeridor atual não é sensível ao caso das letras. Isso significa que ele considera todas as palavras em letras minúsculas, independentemente da entrada do usuário. Portanto, se o usuário digitar um prefixo com letras maiúsculas, o sugeridor não encontrará correspondências.
2.  Acentuação e caracteres especiais: O sugeridor atual não trata acentuação ou caracteres especiais de forma especial. Ele trata todas as letras de forma individual, ignorando qualquer acento ou caractere especial. Isso pode resultar em correspondências inconsistentes ou em falta de correspondências quando acentuação ou caracteres especiais estão envolvidos.
3.  Espaços e pontuação: O sugeridor não lida com palavras que contenham espaços ou pontuação. Ele considera apenas palavras contínuas sem espaços ou pontuação(e palavras compostas como cofre-forte). Portanto, se houver palavras no dicionário que contenham espaços ou pontuação, elas não serão consideradas corretamente pelo sugeridor.
4.  Tamanho do dicionário: O desempenho do sugeridor pode ser afetado pelo tamanho do dicionário. À medida que o número de palavras aumenta, as operações de inserção e busca podem se tornar mais lentas. Embora a estrutura da árvore AVL ajude a manter um bom desempenho na maioria dos casos, pode haver uma degradação gradual à medida que o dicionário cresce muito.
5.  Eficiência de memória: A árvore AVL utiliza uma quantidade adicional de memória para armazenar os nós e as informações de balanceamento. Dependendo do tamanho do dicionário, isso pode ocupar mais espaço em memória do que outras estruturas de dados mais compactas.
