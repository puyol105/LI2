#ifndef resolver
#define resovler

/**
Esta função é a função principal do comando resolver, é esta a função que inicia o comando, começando por correr as estrategias em loop ate que as estrategias deixem de fazer alterações no tabuleiro.
Quando as estrategias deixaram de fazer alterações no tabuleiro e se o tabuleiro não estiver resolvido, aplica se a função aleatorio, que ira executar uma jogada no tabuleiro.
@param tabubleiro *tab - Recebe o tabuleiro atual do jogo.
@return tabuleiro *tab - Retorna o tabuleiro resolvido.
*/
  

tabuleiro *resolver(tabuleiro *tab);

/**
*A função que testa se as estrategias fizeram de facto alterações no tabuleiro.
@param char tmp[100][100] - Recebe uma matriz que corresponde ao tabuleiro antes de executar as estrategias.
@param tabuleiro *tab - Recebe o tabuleiro completo do jogo.
@return tabuleiro *tab - Retorna um inteiro como valor de verdade.
*/

int changes(char tmp[100][100], tabuleiro *tab);

/**
A função aleatorio começa por criar um array com as combinações possiveis de jogadas e um array com o numero das linhas correspondentes a essas combinações.
Aseguir ordena se o array das combinações e coloca se o array das linhas pela mesma ordem.
Guarda se uma matriz com o tabuleiro antes de executarmos qualquer alteração ao tabuleiro e agora podemos aplicar a primeira combinação ao tabuleiro atravez da função aleoaux, e apos esta jogada, aplicam se as estrategias, se estas resultarem num tabuleiro invalido, o tabuleiro é substituido pela tabuleiro inicial e executavel a segunda combinação, se testarmos todas as combinações desta linha e nenhuma delas funcionar para resolver o tabuleiro, avancemos para a proxima linha ate o tabuleiro estar resolvido, ou não haverem mais combinações possiveis, se chegar ao fim e não tiver mais nenhuma combinação possivel, e o tabuleiro não estiver resolvido, retorna o tabuleiro inicial antes das alterações
@param tabubleiro *tab - Recebe o tabuleiro completo do jogo.
@param int before - Recebe um inteiro que tem o valor 0, se for a primeira vez que o aleatorio estiver a correr, ou valor 1 se ja tiver corrido antes.
@return tabuleiro *tab - Retorna o tabuleiro de forma a que o programa continue a correr.
*/

tabuleiro *aleatorio(tabuleiro *tab,int before);

/**
Esta função verifica se é possivel colocar um barco no tabuleiro na posição quadro[lin][col].
@param int lin - A linha atual da posição.
@param int col - A colona atual da posição.
@return int - Retorna um inteiro com valor de verdade.
*/

int caniboat(tabuleiro *tab,int lin,int col);

/**
Esta função calcula atravez da formula matematica o numero de combinações possivel para colocar p barcos em n espaços.
@param int n - Um inteiro representativo do numero de posições disponiveis para colocar os barcos.
@param int p - Um inteiro representativo do numero de barcos.
@return int - Retorna o numero de combinações.
*/

int combinacoes(int n, int p);

/**
Esta função calcula o fatorial de um numero atravez da recursividade.
@param int n - Um inteiro para calcular o fatorial desse numero.
@return int - Retorna o fatorial de um numero.
*/

int fact(int n);

/**
Esta função calcula atravez da formula matematica o numero de combinações possivel para colocar p barcos em n espaços.
@param tabuleiro *tab - Recebe o tabuleiro do jogo.
@param int p - A linha onde vai fazer os testes.
@return int - Retorna o numero correpondente a possiveis onde se possa fazer jogadas
*/

int nbarcos(tabuleiro *tab,int lin);

/**
Esta função efetua uma jogada na linha l consoante o inteiro play, sendo que se play=1 executa a primeira jogada possivel, se play=2 executa a segunda jogada possivel, etc etc.
@param tabuleiro *tab- Recebe o tabuleiro do jogo atual.
@param int l - Recebe a linha onde ira efetuar a jogada.
@param int play - Recebe um inteiro que representa a jogada que ira fazer.
@return int - Retorna o tabuleiro apos a jogada ser feita.
*/

tabuleiro *aleoaux(tabuleiro *tab,int l,int play);

/**
Esta função ordena um array, e da a outro array a mesma ordem que o primeiro.
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa onde o inicio por onde se deve começar a ordenar.
@param int u - Inteiro que representa ate que elemento do array se deve ordenar o array.
*/


void ordena(int comb[], int lin[],int p, int u);


/**
Esta função partição é uma auxiliar da função ordena, que ordena uma pequena parte do array
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa onde o inicio por onde se deve começar a ordenar.
@param int u - Inteiro que representa ate que elemento do array se deve ordenar o array.
@return int - Retorna o numero que corresponde ao meio do segmento do array.
*/

int particao(int comb[],int lin[],int i, int s);

/**
Esta função swap é funçao auxiliar da função partição que troca dois inteiros num array, e troca outros dois noutro array, para que os arrays possam ficar pela mesma ordem
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa a posição do primeiro elemento a ser trocado.
@param int u - Inteiro que representa a posição do segundo elemento a ser trocado.
*/


void swap(int comb[], int lin[], int p, int s);

#endif
