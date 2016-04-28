#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"



/**
A função imprimir,proveniente do comando m, imprime o estado do tabuleiro naquele preciso momento. O procedimento baseia-se 2 ciclos, um
que imprime as linhas, e em cada fim coloca o valor de segmentos existentes nessa coluna. Por fim, o último ciclo imprimme os valores dos
segmentos existentes em cada coluna.
@param tabubleiro *tab - Recebe o tabuleiro completo do jogo.
@return tabuleiro *tab - Retorna o tabuleiro de forma a que o programa continue a correr.
*/
tabuleiro *imprimir(tabuleiro *tab){
	int lin,col,n=0;

	
	for(lin=0;lin<tab->tamanho[0];lin++){
		for(col=0;col<tab->tamanho[1];col++)
			printf("%c",tab->quadro[lin][col]);
		printf(" %d\n",tab->linhas[lin]);                   
	}

	for(col=0;col<tab->tamanho[1];col++){
		if(tab->colunas[col]<10) {printf("%d",tab->colunas[col]); n++;}
		else if(tab->colunas[col]<100) printf("%d",tab->colunas[col]/10);
		else if(tab->colunas[col]<1000) printf("%d",tab->colunas[col]/100);
	}
	printf("\n");

	if(n==tab->tamanho[1]) return tab;
	else for(col=0;col<tab->tamanho[1];col++){
			if(tab->colunas[col]<10) printf(" ");
			else if(tab->colunas[col]<100){ printf("%d",tab->colunas[col]%10); n++;}
			else if(tab->colunas[col]<1000) printf("%d",(tab->colunas[col]/10)%10);
		}
	printf("\n");
	
	if(n==tab->tamanho[1]) return tab;
	else for(col=0;col<tab->tamanho[1];col++){
		if(tab->colunas[col]<10) printf(" ");
		else if(tab->colunas[col]<100) printf(" ");
		else if(tab->colunas[col]<1000) printf("%d",(tab->colunas[col]%100)%10);
		}
	printf("\n");

    return tab;
}


/**
A função acol, muda o estado de todos os pontos desconhecidos(.) de uma coluna em água(~). Esta relacionada com o comando v. 
A função recebe uma variável n, que representa o número da coluna a ser alterada, dado pelo ultilizador. O procedimento para alterar o estado
é através de um ciclo de um for, que corre a coluna, e verifica em cada posição, e caso a posição sejam um (.), atera-o para (~).
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual irá efetuar as alterações necessarias.
@param char *n - Recebe um carácter que mais tarde será convertido num número para saber qual a coluna que deverá sofrer alterações.
@return tabuleiro *tab - A função retorna o tabuleiro alterado de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *acol(tabuleiro *tab,int n){
	int i;
	for(i=0;i!=tab->tamanho[0];i++)
		if (tab->quadro[i][n]=='.') tab->quadro[i][n]='~';  
	return tab;
}


/**
A função alin, muda o estado de todos os pontos desconhecidos(.) de uma linha em água(~). Esta relacionada com o comando h. 
A função recebe uma variável n, que representa o número da linha a ser alterada, dado pelo ultilizador. O procedimento para alterar o estado,
idêndico a função acol, é através de um ciclo de um for, que corre a linha, e verifica em cada posição, e caso a posição sejam um (.), atera-o para (~).
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual irá efetuar as alterações necessarias.
@param char *n - Recebe um carácter que mais tarde será convertido num número para saber qual a linha que deverá sofrer alterações.
@return tabuleiro *tab - A função retorna o tabuleiro de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *alin(tabuleiro *tab,int n){
	int i;
	for(i=0;i!=tab->tamanho[1];i++)
		if (tab->quadro[n][i]=='.') tab->quadro[n][i]='~'; 
	return tab;
}


/**
A função coloca, proveniente do comando p, imprime um caracter no tabuleiro, nas cooordenadas dadas pelo utilizador. O procedimento concentra-se apenas em, mudar 
o estado da posição dado pelo utilizador (l) e (c), para o caracter n, também dado pelo utilizador. 
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar as alterações necessárias.
@param char *n - O carácter n representa o novo caracter que deverá ser posto na posição indicada.
@param char *l - O carácter l representa a linha onde o carácter será posicionado, mais tarde será convertido para um int.
@param char *c - O carácter c representa a coluna onde carácter será posicionado, mais tarde será convertido para um int.
@return tabuleiro *tab - A função retorna o tabuleiro de forma a que o programa continue a correr no final desta operação.
*/
tabuleiro *coloca (tabuleiro *tab,char n,int l,int c){


    if(l<tab->tamanho[0] && c<tab->tamanho[1] && l>-1 && c>-1) tab->quadro[l][c]=n;
    return tab;
}


/**
A função ler, está relacionada com o comando c, pois lê um tabuleiro dado pelo utilizador. A função baseia-se na função auxiliar scanf e fgets para a leitura dos dados.
O procedimento para a leitura do tabuleiro, passa através da leitura do tamanho do tabuleiro, ou seja, número de linhas e número de colunas. 
Posteriormente, ocorrem 3 ciclos de for, o primeiro para a leitura dos números de segmentos existentes em linha, e o segundo para a leitura dos números
de segmentos existentes em coluna. Por fim o último ciclo, lê o mapa por linhas.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/
tabuleiro *ler (tabuleiro *tab){
	int l,c,s;
	char linha[MAX_SIZE];
	char resto[MAX_SIZE];
    char *z;



	z=fgets(linha,MAX_SIZE,stdin);
	sscanf(linha,"%d %d",&tab->tamanho[0],&tab->tamanho[1]);  
	z=fgets(linha,MAX_SIZE,stdin);                           
	for(l=0;l<tab->tamanho[0];l++){
		int v;
		sscanf(linha,"%d %[^\n]",&v,resto); 
		tab->linhas[l]=v;
		strcpy(linha,resto);
	}

	z=fgets(linha,MAX_SIZE,stdin);
	for(c=0;c<tab->tamanho[1];c++){
		int v;
		sscanf(linha, "%d %[^\n]",&v,resto); 
		tab->colunas[c]=v;
		strcpy(linha,resto);
	}

	for(l=0;l<tab->tamanho[0];l++){
		z=fgets(linha,MAX_SIZE,stdin);    
		for(c=0;c<tab->tamanho[1];c++){
			tab->quadro[l][c]=linha[c];
		}
	}
    s=strlen (z)*0;
    if(s==0) return tab;
	return tab;
}
/**
A função invalido() imprime a mensagem "Comando invalido!" no caso de o utilizador ter tentado utilizar um comando não conhecido pelo programa.
*/

void invalido(){
	printf ("Comando invalido!\n");

}

/**
A função desfaz, liberta o tabuleiro actual e passa para o anterior, ou seja, retorna para o estado anterior. Como a estutura é em listas ligadas, cada tabuleiro novo tem sempre o 
endereço do anterior, a função liberta o tabuleiro actual, e devolve o anteriro. No entanto, caso o anterior seja o tabuleiro NULL, devolve o mesmo tabuleiro. 
@param tabuleiro *tab - Recebe o tabuleiro actual.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *desfaz(tabuleiro *tab){
	tabuleiro *n;
    n=tab;
    if (n->prox==NULL) return tab;    
    free(tab);
    return n->prox;
}

/**
A função aloca, cria um novo espaço na memoria, para um tabuleiro igual ao que a função recebe. Esta função basicamente cria o tabuleiro seguinte, na lista ligada.
@param tabuleiro *tab - Recebe o tabuleiro actual.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *aloca(tabuleiro *tab){
 	int i,lin,col;
 	tabuleiro *novo =(tabuleiro *) malloc(sizeof(struct tabuleiro));



 	for (i=0;i!=2;i++) novo->tamanho[i]=tab->tamanho[i];
 	
 	for (i=0;i!=tab->tamanho[0];i++) novo->linhas[i]= tab->linhas[i];
 
 	for (i=0;i!=tab->tamanho[1];i++) novo->colunas[i]= tab->colunas[i];

	for (col=0;col!=tab->tamanho[1];col++)
		for(lin=0;lin!=tab->tamanho[0];lin++)
      	 novo->quadro[lin][col]=tab->quadro[lin][col];

	novo->prox=tab;

	return novo;
}

/**
A função verigual, verifica se dois tabuleiros são iguais ou não. Caso sejam iguais, liberta um tabuleiro, caso contrário liberta o outro. O tabuleiro q, é o tabuleiro actual, 
e o tabuleiro w é o tabuleiro que sofre alterções de outras funções. Caso existem alterações, a função devolve esse tabuleiro, caso contŕario devolve o tabuleiro actual.
@param tabuleiro *q - Recebe o tabuleiro actual.
@param tabuleiro *w - Recebe o tabuleiro alterado ou não. 
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *verigual (tabuleiro *q,tabuleiro *w){
 int i,j,s=1;

 for (i=0;i!=q->tamanho[0];i++)
    for(j=0;j!=q->tamanho[1];j++)
        if (q->quadro[i][j] != w->quadro[i][j]) s=0;

 if(s==1){
    free(w);          
    return q;
}
 return w;
}


/**
A função pos(tabuleiro *tab,int l,int c) devolve o caracter na linha l e coluna c, verificando tambem se a peça se encontra dentro do tabuleiro ou não, sendo que senão se encontrar dentro do tabuleiro devolve 'n'.
@param tabuleiro *tab - Recebe o tabuleiro para consultar a posição.
@param int l- Recebe a linha onde o caracter se encontra.
@param int c- Recebe a coluna onde o caracter se encontra.
@return char - Retorna o caracter que esta na posiçao l, c, se o caracter estiver dentro do tabuleiro e retorna 'n' caso contrario.
*/

char pos(tabuleiro *tab,int l,int c){
	if(l<0 || c<0 || l>=tab->tamanho[0] || c>=tab->tamanho[1]) return 'n';
	else return tab->quadro[l][c];
}