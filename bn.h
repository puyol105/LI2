#ifndef bn
#define bn
#define MAX_SIZE 1024

/**O tipo tamanho tem dois indices, um para o número de colunas, e outro para o número de linhas, delimitando o tamanho do tabuleiro do jogo. 
O tipo colunas define as colunas do tabuleiro. O tipo linhas define as linhas do tabuleiro.
O tipo quadro é o tabuleiro, no formato de uma matriz.*/
typedef struct  tabuleiro{

    int tamanho[2];
    int colunas[100];
    int linhas[100];
    char quadro[100][100];
    struct tabuleiro *prox;

}tabuleiro;


/**
A função imprimir,proveniente do comando m, imprime o estado do tabuleiro naquele preciso momento. O procedimento baseia-se 2 ciclos, um
que imprime as linhas, e em cada fim coloca o valor de segmentos existentes nessa coluna. Por fim, o último ciclo imprimme os valores dos
segmentos existentes em cada coluna.
@param tabubleiro *tab - Recebe o tabuleiro completo do jogo.
@return int - Retorna um inteiro de forma a que o programa continue a correr.
*/
tabuleiro *imprimir(tabuleiro *tab);

/**
A função acol, muda o estado de todos os pontos desconhecidos(.) de uma coluna em água(~). Esta relacionada com o comando v. 
A função recebe uma variável n, que representa o número da coluna a ser alterada, dado pelo ultilizador. O procedimento para alterar o estado
é através de um ciclo de um for, que corre a coluna, e verifica em cada posição, e caso a posição sejam um (.), atera-o para (~).
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual irá efetuar as alterações necessarias.
@param char *n - Recebe um carácter que mais tarde será convertido num número para saber qual a coluna que deverá sofrer alterações.
@return int - A função retorna o valor 1 de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *acol(tabuleiro *tab,int n);

/**
A função alin, muda o estado de todos os pontos desconhecidos(.) de uma linha em água(~). Esta relacionada com o comando h. 
A função recebe uma variável n, que representa o número da linha a ser alterada, dado pelo ultilizador. O procedimento para alterar o estado,
idêndico a função acol, é através de um ciclo de um for, que corre a linha, e verifica em cada posição, e caso a posição sejam um (.), atera-o para (~).
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual irá efetuar as alterações necessarias.
@param char *n - Recebe um carácter que mais tarde será convertido num número para saber qual a linha que deverá sofrer alterações.
@return int - A função retorna o valor 1 de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *alin(tabuleiro *tab,int n);

/**
A função coloca, proveniente do comando p, imprime um caracter no tabuleiro, nas cooordenadas dadas pelo utilizador. O procedimento concentra-se apenas em, mudar 
o estado da posição dado pelo utilizador (l) e (c), para o caracter n, também dado pelo utilizador. 
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar as alterações necessárias.
@param char *n - O carácter n representa o novo caracter que deverá ser posto na posição indicada.
@param char *l - O carácter l representa a linha onde o carácter será posicionado, mais tarde será convertido para um int.
@param char *c - O carácter c representa a coluna onde carácter será posicionado, mais tarde será convertido para um int.
@return int - A função retorna o valor 1 de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *coloca (tabuleiro *tab,char n,int l,int c);

/**
A função ler, está relacionada com o comando c, pois lê um tabuleiro dado pelo utilizador. A função baseia-se na função auxiliar scanf e fgets para a leitura dos dados.
O procedimento para a leitura do tabuleiro, passa através da leitura do tamanho do tabuleiro, ou seja, número de linhas e número de colunas. 
Posteriormente, ocorrem 3 ciclos de for, o primeiro para a leitura dos números de segmentos existentes em linha, e o segundo para a leitura dos números
de segmentos existentes em coluna. Por fim o último ciclo, lê o mapa por linhas.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@return int - Retorna um valor diferente de 0 para que a funçao interpretador() continue a correr.
*/
tabuleiro *ler (tabuleiro *tab);

/**
A função invalido() imprime a mensagem "Comando invalido!" no caso de o utilizador ter tentado utilizar um comando não conhecido pelo programa.
*/

void invalido();

/**
A função desfaz, liberta o tabuleiro actual e passa para o anterior, ou seja, retorna para o estado anterior. Como a estutura é em listas ligadas, cada tabuleiro novo tem sempre o 
endereço do anterior, a função liberta o tabuleiro actual, e devolve o anteriro. No entanto, caso o anterior seja o tabuleiro NULL, devolve o mesmo tabuleiro. 
@param tabuleiro *tab - Recebe o tabuleiro actual.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *desfaz(tabuleiro *tab);

/**
A função aloca, cria um novo espaço na memoria, para um tabuleiro igual ao que a função recebe. Esta função basicamente cria o tabuleiro seguinte, na lista ligada.
@param tabuleiro *tab - Recebe o tabuleiro actual.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *aloca(tabuleiro *tab);

/**
A função verigual, verifica se dois tabuleiros são iguais ou não. Caso sejam iguais, liberta um tabuleiro, caso contrário liberta o outro. O tabuleiro q, é o tabuleiro actual, 
e o tabuleiro w é o tabuleiro que sofre alterções de outras funções. Caso existem alterações, a função devolve esse tabuleiro, caso contŕario devolve o tabuleiro actual.
@param tabuleiro *q - Recebe o tabuleiro actual.
@param tabuleiro *w - Recebe o tabuleiro alterado ou não. 
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *verigual (tabuleiro *q,tabuleiro *w);

/**
A função pos(tabuleiro *tab,int l,int c) devolve o caracter na linha l e coluna c, verificando tambem se a peça se encontra dentro do tabuleiro ou não, sendo que senão se encontrar dentro do tabuleiro devolve 'n'.
@param tabuleiro *tab - Recebe o tabuleiro para consultar a posição.
@param int l- Recebe a linha onde o caracter se encontra.
@param int c- Recebe a coluna onde o caracter se encontra.
@return char - Retorna o caracter que esta na posiçao l, c, se o caracter estiver dentro do tabuleiro e retorna 'n' caso contrario.
*/
char pos(tabuleiro *tab,int l,int c);

#endif