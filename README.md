# tsp-implementation
Implementação de uma heurística para o Problema do Caixeiro Viajante. 

### Objetivo
Desenvolver uma solução aproximada para instâncias simétricas do Problema do Caixeiro Viajante (TSP). O objetivo do TSP é encontrar um caminho hamiltoniano de custo mínimo em um grafo completo. No caso simétrico do problema, é garantido que para quaisquer nós u e v do grafo, as arestas (u, v) e (v, u) têm o mesmo custo.

O TSP é conhecido como um problema NP-difícil, ou seja, não se conhece uma solução ótima em tempo polinomial. Dessa forma, o objetivo será desenvolver uma solução em tempo polinomial que se aproxime do caminho ótimo. O projeto terá como entrada os arquivos encontrados na TSPLib, referentes às instâncias simétricas do TSP.

### Abordagem
A abordagem adotada foi uma implementação do Algoritmo de Christofides, que encontra um caminho TSP com custo próximo ao custo do caminho ótimo. Resumidamente, o algoritmo funciona em seis passos:

1. Encontrar uma Árvore Geradora Mínima (MST) do grafo;
2. Separar um conjunto dos vértices da MST cujo grau é ímpar;
3. Encontrar um matching perfeito de custo mínimo entre esses vértices;
4. Construir um multigrafo contendo tanto as arestas da MST quanto as do matching perfeito;
5. Encontrar um caminho euleriano no multigrafo;
6. Converter o caminho euleriano em um caminho TSP.

Na etapa de encontrar a Árvore Geradora Mínima, foi utilizada uma implementação do algoritmo de Prim. Para fazer o matching perfeito, foi utilizado um algoritmo guloso, que a cada iteração simplesmente escolhe a aresta de menor peso entre dois vértices não conectados do conjunto. Por fim, o algoritmo que encontra o caminho euleriano pode ser implementado facilmente utilizando uma busca em profundidade (DFS).

### Como Rodar
Para rodar o projeto, copie o repositório em um diretório da sua máquina, e abra uma janela do terminal nesse diretório. Utilizando um terminal UNIX, digite os seguintes comandos no terminal:

```bash
% make build
% ./main
```

Isso irá gerar e rodar o executável do programa. Em seguida, siga as instruções no terminal para rodar o programa com uma instância do TSP. Certifique-se de ter a pasta instance com os arquivos .tsp no diretório do projeto.

### Dependências
Os arquivos .tsp, que contém instâncias simétricas do TSP, foram encontrados na TSPLib (disponível em https://web.archive.org/web/20250908094043/http:/comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp/). Suas respectivas soluções ótimas podem ser encontradas em https://web.archive.org/web/20250821025851/http:/comopt.ifi.uni-heidelberg.de/software/TSPLIB95/STSP.html. A TSPLib também oferece um artigo que serviu como base para desenvolver o projeto, explicando detalhes sobre a representação dos grafos nos arquivos disponibilizados. O arquivo está disponível em https://web.archive.org/web/20250903091423/http:/comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp95.pdf.

Não foram utilizadas dependências como frameworks ou bibliotecas externas. O projeto foi todo implementado na linguagem C++, utilizando a ferramenta Make para facilitar a compilação. Não foram utilizadas ferramentas de IA generativa em nenhuma etapa do desenvolvimento.

### Resultados Obtidos
O resultado final é uma aplicação de terminal que solicita ao usuário o nome de uma instância do TSP, e em seguida exibe uma solução para o problema encontrada de acordo com a abordagem descrita acima.

### Possíveis Melhorias
Embora o Algoritmo de Christofides garanta um custo com fator de 3/2 do custo do caminho ótimo no pior caso, essa métrica leva em consideração a implementação de um algoritmo de minimum weight perfect mathing, que garante que o matching entre os nós de grau ímpar da MST terá o menor custo possível. O algoritmo guloso utilizado não garante encontrar o matching de menor custo. A implementação de um algoritmo de minimum weight perfect matching tende a ser bastante complicada, tendo em mente o escopo deste projeto. Porém, uma vez implementado, o algoritmo poderia ser facilmente incorporado ao projeto, melhorando o resultado no pior caso.

Além disso, o resultado do Algoritmo de Christofides pode ser usado como um ponto de partida para otimizações adicionais. Os algoritmos da classe k-opt (em especial o 2-opt e 3-opt) são algoritmos em tempo polinomial cujo objetivo é fazer substituições de arestas do caminho TSP em busca de um caminho com custo menor. Em geral, as melhores soluções são obtidas ao utilizar um algoritmo como ponto de partida (como um algoritmo guloso ou o Algoritmo de Christofides) e em seguida rodar um algoritmo k-opt para otimizar o caminho encontrado.