#ifndef ficheiro
#define ficheiro

/**
A função lerf, desepenha o mesmo papel que a função ler, ou seja, lê um tabuleiro, no entanto dado por um ficheiro. A função baseia-se na função auxiliar scanf e fgets para a leitura dos dados.
O que diferencia da função ler, é que o fgets, em vez de ler do teclado, lê de um ficheiro.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@param char - Recebe o nome do ficheiro.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *lerf(tabuleiro *tab,char *n);

/**
A função imprimirf, desepenha o mesmo papel que a função imprimir, ou seja, imprime o estado actual do tabuleiro num ficheiro, pelo nome dado. 
A diferença é que esta função imprime o tabuleiro no mesmo formato que se lê, ou seja, imprime o estado do tabuleiro de forma que seja possivel que seja lido pela função lerf.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@param char - Recebe o nome do ficheiro.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *imprimirf(tabuleiro *tab,char *n);

#endif

