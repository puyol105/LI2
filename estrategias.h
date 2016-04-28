#ifndef estrategias
#define estrategias

/**
A função estra1(tabuleiro *tab) analisa o tabuleiro e em todos os segmentos de barcos conhecidos coloca água nas posições em redor ao segmento.
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra1(tabuleiro *tab);

/**
A função estra2(tabuleiro *tab) analisa o tabuleiro e em todas as colunas e linhas que ja tenham o seu numero total de segmentos de barcos, coloca nessas colunas ou linhas todos os elementos que ainda não sejam conhecidos ('.') como sendo água.
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra2(tabuleiro *tab);

/**
A função estra3(tabuleiro *tab) analisa o tabuleiro e em todos os sitios onde poder acrescentar segmentos de barcos (por não haver mais nenhuma outra hipotse de escolha) coloca esses barcos nessas posições, e ainda tenta descobrir de que tipo de segmentos são os segmentos desconhecidos ('o').
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra3(tabuleiro *tab);

/**
A função substitui(tabuleiro *tab) é uma auxiliar da função estra3(tabuleiro *tab) que apos a colocação de todos os 'A' (sendo que o 'A' representa que existe um segmento ali, porem ainda se ira estudar que tipo de segmento será) e os troca por caracteres validos do problema.
@param tabuleiro *tab- Recebe o tabuleiro sobre o qual ira efetuar as alterações.
*/

void substitui(tabuleiro *tab);

/**
A função replaceo(tabuleiro *tab) é uma auxiliar da função estra3(tabuleiro *tab) que tenta trocar todos os segmentos não conhecidos ('o') pelo seu caracter final.
*/

void replaceo(tabuleiro *tab);

tabuleiro *estra4(tabuleiro *tab);


#endif