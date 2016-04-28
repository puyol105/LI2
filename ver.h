#ifndef ver
#define ver
#define TRUE 1
#define FALSE 0

/**
A função verifica(tabuleiro *tab) analisa o estado do tabuleiro, isto é, se o tabuleiro atual é possivel de resolver ou não, devolvendo falso e imprimdo a mensagem NAO no caso de não ser possivel de resolver, e retornando 1 e escrevendo SIM se for possivel resolver o tabuleiro no estado atual.
@param tabuleiro *tab - Recebe o tabuleiro que deve verificar se é valido ou não.
@return int - Retorna um inteiro indicando o valor de verdade acerca do tabuleiro ser ou não possivel de resolver. 
*/

int verifica(tabuleiro *tab);

/**
A função verifica se todos os caracteres do tabuleiro pertencem a lista de caracteres permitidos pelo programa (O,~,#,<,>,v,^,o,.).
@param tabuleiro *tab - Recebe como argumento o tabuleiro que deverá avaliar.
@return int- Retorna um inteiro com a função de valor de verdade (0-FALSE, 1-TRUE).
*/

int caracteres(tabuleiro *tab);

/**
A função verilin(tabuleiro *tab) verifica se o numero de segmentos de barcos da linha é igual, maior ou menor que o numero limite de segmentos dessa linha.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna 0 se tiver mais segmentos do que o possivel, 2 se tiver menos e 1 se tiver exatamente o mesmo numero de segmentos, ou seja, se a linha estiver resolvida.
*/

int verilin (tabuleiro *tab);

/**
A função vericol(tabuleiro *tab) verifica se o numero de segmentos de barcos da coluna é igual, maior ou menor que o numero limite de segmentos dessa coluna.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna 0 se tiver mais segmentos do que o possivel, 2 se tiver menos e 1 se tiver exatamente o mesmo numero de segmentos, ou seja, se a coluna estiver resolvida.
*/

int vericol(tabuleiro *tab);

/**
A função submar(tabuleiro tab), verifica se para todos os barcos dados como submarinos(1 segmento de comprimento) estão bem colocadas no tabuleiro, isto é, sem nenhum outro segmento de barco nas proximidades.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int -Retorna um inteiro como valor de verdade, isto é 0 para FALSE (o tabuleiro tem submarinos a tocar em outros barcos) e 1 para TRUE (os submarinos estão bem colocados).
*/

int submar(tabuleiro *tab);

/**
A função bottom(tabuleiro *tab) verifica se todas as peças inferiores dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco acima e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças 'v' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int bottom(tabuleiro *tab);

/**
A função top(tabuleiro *tab) verifica se todas as peças superiores dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco abaixo e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int top(tabuleiro *tab);

/**
A função rigth(tabuleiro *tab) verifica se todas as peças a direita dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco a esquerda e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int rigth(tabuleiro *tab);

/**
A função left(tabuleiro *tab) verifica se todas as peças a esquerda dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco a direita e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int left(tabuleiro *tab);

/**
A função middle(tabuleiro *tab) verifica se todas as peças interiores dos barcos estão bem colocadas, ou seja, tem que ter pelo menos um segmento de barco abaixo e outro acima, ou um a sua direita e outro a sua esquerda, e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int middle(tabuleiro *tab);

/**
A função size(tabuleiro *tab) verifica se todas as linhas e colunas tem um numero de segmentos esperado (quando o tabuleiro estiver resolvido) possivel para o tamanho do tabuleiro.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se tiver segmentos amais para o tamanho da tabuleiro) ou 1 para TRUE (se o numero de segmentos for possivel de colocar no tabuleiro).
*/

int size(tabuleiro *tab);

/**
A função size(tabuleiro *tab) verifica se todas as linhas e colunas tem um numero de segmentos possivel, com a adição de que se houver um segmento que tenha de estar nessa linha ou coluna obrigatoriamente, mas ainda nao se saiba (por exemplo se tivermos um segmento '<' e aseguir um '.', sabemos que esse ponto terá de ser um segmento, mas ainda é um segmento ficticio, e esta função tenta encontrar casos como esses.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se tiver segmentos amais para o tamanho da tabuleiro) ou 1 para TRUE (se o numero de segmentos for possivel de colocar no tabuleiro).
*/

int tamfix(tabuleiro *tab);



int space(tabuleiro *tab);


int dots(tabuleiro *tab);
#endif
