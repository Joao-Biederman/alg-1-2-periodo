Aula sobre Ordenação
Implementações em sala

BubbleSort

    Análise :
            Comparações :
                c = 1/2.(n² - n)

                Onde:
                    c = número de comparações;
                    n = número de elementos do conjunto.
        
        Trocas :
            Melhor caso : 0 (zero, para um vetor já ordenado)
            Caso médio: T = 3/4.(n²-n)
            Pior caso: T = 3/4.(n²-n)

            Onde :
                T = número de trocas;
                n = número de elementos do conjunto.

        Tempo de execução :
            Quadrático


Shakesort

    Melhoramento do algoritmo de bolha;
    Implementação dupla da bolha em um mesmo algoritmo, cada uma em uma direção;

    Análise :
        Tempo de excução é de ordem quadratica;
        Número de comparações não é alterado;
        Número de trocas é menor em grupos de dados pequenos.


Selectionsort

    Seleciona o elemento de menor valor e troca com o 1º elemento;
    Para os n-1 elementos restantes ele procura o 2º menor elemento e troca com o 2º elemento;
    Continua esta sequencia até achar o maior elemento;
    
    Análise :
        Comparações :
            c = 1/2.(n²-n)

            Onde :
                c = número de comparações;
                n = número de elementos do conjunto.

        Trocas : 
            Melhor caso :
                T = 3(n-1)
            
            Caso médio :
                T = n(log(n+e))

            Pior caso :
                T = n²/4 + 3(n-1)
            
            Onde
                T = Tempo de trocas;
                n = número de elementos do conjunto;
                e = número de Euler (aproximadamente 2,718).

        Mesmo número de comparações dos casos de bolha;
        Menor número de trocas do que o módemo de bolha.


Insertionsort

    Baseia-se no processo de ordenação de cartas de baralho em uma mão de jogo;
    Considera-se inicialmente o conjunto divido em duas partes, uma já ordenada e outra a ser ordenada;
    A primeira parte (ordenada) inicialmente coloca-se apenas o primeiro elemento;
    A seguir pega o primeiro elemento da segunda parte e insere na sua posição correta dentro da parte ordenada;
    Repete-se até o ultimo elemento passar para a parte dos dados já ordenados.

    Análise:
        Comparações :
            Melhor Caso :
                c = n-1

            Caso Médio :
                c = 1/2.(n²+n)

            Pior Caso :
                c = 1/4.(n²+n)

            Onde :
                c = número de comparações;
                n = número de elementos do conjunto.

            No melhor caso o método de inserção é linear;
            No pior caso o metodo de inserção é tão ruim quanto a bolha e a seleção;

        O comportamento é natural (bom para conjuntos quase ordenados);
        Nao rearranja elementos que possuam chaves iguais;
        
        O vetor precisa ser deslocado cada vez que um elemento é posto na posição correta.

        Trocas :
            Melhor Caso :
                T =

            Caso Médio :
                T =

            Pior Caso :
                T =
            
            Onde :
                T = número de trocas;
                n = número de elementos do conjunto.