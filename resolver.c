#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"

/**
Esta função é a função principal do comando resolver, é esta a função que inicia o comando, começando por correr as estrategias em loop ate que as estrategias deixem de fazer alterações no tabuleiro.
Quando as estrategias deixaram de fazer alterações no tabuleiro e se o tabuleiro não estiver resolvido, aplica se a função aleatorio, que ira executar uma jogada no tabuleiro.
@param tabubleiro *tab - Recebe o tabuleiro atual do jogo.
@return tabuleiro *tab - Retorna o tabuleiro resolvido.
*/
  
tabuleiro *resolver(tabuleiro *tab){
	char tmp[100][100];
	int lin,col;
	tabuleiro *f, *w, *z, *x;

		do{
			for(lin=0;lin!=tab->tamanho[0];lin++)
				for(col=0;col!=tab->tamanho[1];col++)
					tmp[lin][col]=tab->quadro[lin][col];
	   
        	f=aloca(tab);
        	w=verigual(tab,estra1(f));

        	f=aloca(w);
        	z=verigual(w,estra2(f));
	
        	f=aloca(z);
        	x=verigual(z,estra3(f));

        	f=aloca(x);
        	tab=verigual(x,estra4(f));


		}while(changes(tmp,tab) && verifica(tab)!=2);

		if(verifica(tab)==2);
		else tab=aleatorio(tab,0);


	return tab;
}

/**
*A função que testa se as estrategias fizeram de facto alterações no tabuleiro.
@param char tmp[100][100] - Recebe uma matriz que corresponde ao tabuleiro antes de executar as estrategias.
@param tabuleiro *tab - Recebe o tabuleiro completo do jogo.
@return tabuleiro *tab - Retorna um inteiro como valor de verdade.
*/

int changes(char tmp[100][100], tabuleiro *tab){
	int lin,col,r=0;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			if(tmp[lin][col]!=tab->quadro[lin][col]) r=1;

	return r;
}

/**
A função aleatorio começa por criar um array com as combinações possiveis de jogadas e um array com o numero das linhas correspondentes a essas combinações.
Aseguir ordena se o array das combinações e coloca se o array das linhas pela mesma ordem.
Guarda se uma matriz com o tabuleiro antes de executarmos qualquer alteração ao tabuleiro e agora podemos aplicar a primeira combinação ao tabuleiro atravez da função aleoaux, e apos esta jogada, aplicam se as estrategias, se estas resultarem num tabuleiro invalido, o tabuleiro é substituido pela tabuleiro inicial e executavel a segunda combinação, se testarmos todas as combinações desta linha e nenhuma delas funcionar para resolver o tabuleiro, avancemos para a proxima linha ate o tabuleiro estar resolvido, ou não haverem mais combinações possiveis, se chegar ao fim e não tiver mais nenhuma combinação possivel, e o tabuleiro não estiver resolvido, retorna o tabuleiro inicial antes das alterações
@param tabubleiro *tab - Recebe o tabuleiro completo do jogo.
@param int before - Recebe um inteiro que tem o valor 0, se for a primeira vez que o aleatorio estiver a correr, ou valor 1 se ja tiver corrido antes.
@return tabuleiro *tab - Retorna o tabuleiro de forma a que o programa continue a correr.
*/

tabuleiro *aleatorio(tabuleiro *tab,int before){
	int lin,col,i,l,com=0,barexist,barconess, posicoes;
	int linhas[100],comb[100];
	char tmp[100][100],local[100][100];
	tabuleiro *f, *w, *z, *x;

	


	for(lin=0;lin!=tab->tamanho[0];lin++){
		barexist=0;
		posicoes=0;
		for(col=0;col!=tab->tamanho[1];col++){
			if(caniboat(tab,lin,col)) posicoes++;
			else if(tab->quadro[lin][col]!='~' && tab->quadro[lin][col]!='.') barexist++;
		}
		barconess=tab->linhas[lin]-barexist;
		comb[lin]=combinacoes(posicoes,barconess);
	}


	for(i=0;i!=tab->tamanho[0];i++)
		linhas[i]=i;



	ordena(comb,linhas,0,tab->tamanho[0]);



	for(i=0;comb[i]==0;i++);

	l=linhas[i];
	com=0;








	for(lin=0;lin!=tab->tamanho[0];lin++)
	   	for(col=0;col!=tab->tamanho[1];col++)
	   		tmp[lin][col]=tab->quadro[lin][col];


		do{
			if(verifica(tab)==2) ;
			else if(verifica(tab)==0){

				for(lin=0;lin!=tab->tamanho[0];lin++)
	   				for(col=0;col!=tab->tamanho[1];col++)
	   					tab->quadro[lin][col]=tmp[lin][col];

	   				++com;

					if(com>=comb[i]) {com=0; l=linhas[++i];}

	   				tab=aleoaux(tab,l,com);
	   			}

	  	    else if(verifica(tab)==1){

	  	    	++com;

				if(com>=comb[i]) {com=0; l=linhas[++i];}



	  	    	tab=aleoaux(tab,l,com);
	  	    } 			

			do{
				for(lin=0;lin!=tab->tamanho[0];lin++)
	   				for(col=0;col!=tab->tamanho[1];col++)
	   					local[lin][col]=tab->quadro[lin][col];
	   	

        	f=aloca(tab);
        	w=verigual(tab,estra1(f));


        	f=aloca(w);
        	z=verigual(w,estra2(f));


        	f=aloca(z);
        	x=verigual(z,estra3(f));

        	f=aloca(x);
        	tab=verigual(x,estra4(f));



		}while(changes(local,tab) && verifica(tab)!=2);


		if(verifica(tab)==0){
			for(lin=0;lin!=tab->tamanho[0];lin++)
	   				for(col=0;col!=tab->tamanho[1];col++)
	   					tmp[lin][col]=tab->quadro[lin][col];

		}




		if(before==1){
			for(lin=0;lin!=tab->tamanho[0];lin++)
	   				for(col=0;col!=tab->tamanho[1];col++)
	   					tmp[lin][col]=tab->quadro[lin][col];

	   	return tab;

		}
		else if(verifica(tab)!=2 && i+1==tab->tamanho[0]) tab=aleatorio(tab,1);

		if(dots(tab) || verifica(tab)!=2) {
			for(lin=0;lin!=tab->tamanho[0];lin++)
	   				for(col=0;col!=tab->tamanho[1];col++)
	   					tmp[lin][col]=tab->quadro[lin][col];

	   	return tab;

		}

	}while(verifica(tab)!=2);


   return tab;
}


/**
Esta função verifica se é possivel colocar um barco no tabuleiro na posição quadro[lin][col].
@param int lin - A linha atual da posição.
@param int col - A colona atual da posição.
@return int - Retorna um inteiro com valor de verdade.
*/


int caniboat(tabuleiro *tab,int lin,int col){
	int r=TRUE;

	if(pos(tab,lin,col)!='.') r=FALSE;
	if(pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='n') r=FALSE;
	if(pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='n') r=FALSE;
	if(pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='n') r=FALSE;
	if(pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='n') r=FALSE;
	if(pos(tab,lin,col-1)=='>' || pos(tab,lin,col-1)=='O' ||pos(tab,lin,col-1)=='v' || pos(tab,lin,col-1)=='^') r=FALSE;
	if(pos(tab,lin,col+1)=='<' || pos(tab,lin,col-1)=='O' ||pos(tab,lin,col-1)=='v' || pos(tab,lin,col-1)=='^') r=FALSE;
	if(pos(tab,lin+1,col)=='>' || pos(tab,lin+1,col)=='O' ||pos(tab,lin+1,col)=='<' || pos(tab,lin+1,col)=='^') r=FALSE;
	if(pos(tab,lin-1,col)=='>' || pos(tab,lin-1,col)=='O' ||pos(tab,lin-1,col)=='<' || pos(tab,lin-1,col)=='v') r=FALSE;

	return r;
}

/**
Esta função calcula atravez da formula matematica o numero de combinações possivel para colocar p barcos em n espaços.
@param int n - Um inteiro representativo do numero de posições disponiveis para colocar os barcos.
@param int p - Um inteiro representativo do numero de barcos.
@return int - Retorna o numero de combinações.
*/

int combinacoes(int n, int p){
	if(p==0 || n==0) return 0;
	else return fact(n)/(fact(p) *fact(n-p));
}

/**
Esta função calcula o fatorial de um numero atravez da recursividade.
@param int n - Um inteiro para calcular o fatorial desse numero.
@return int - Retorna o fatorial de um numero.
*/
int fact(int n){
	int r;
	if(n==0) return 1;
	for(r=1;n!=1;n--)r*=n;


	return r;
}
/**
Esta função calcula atravez da formula matematica o numero de combinações possivel para colocar p barcos em n espaços.
@param tabuleiro *tab - Recebe o tabuleiro do jogo.
@param int p - A linha onde vai fazer os testes.
@return int - Retorna o numero correpondente a possiveis onde se possa fazer jogadas
*/

int nbarcos(tabuleiro *tab,int lin){
	int col,r=0;

	for(col=0;col!=tab->tamanho[1];col++)
		if(caniboat(tab,lin,col))r++;

	return r;
}

/**
Esta função efetua uma jogada na linha l consoante o inteiro play, sendo que se play=1 executa a primeira jogada possivel, se play=2 executa a segunda jogada possivel, etc etc.
@param tabuleiro *tab- Recebe o tabuleiro do jogo atual.
@param int l - Recebe a linha onde ira efetuar a jogada.
@param int play - Recebe um inteiro que representa a jogada que ira fazer.
@return int - Retorna o tabuleiro apos a jogada ser feita.
*/


tabuleiro *aleoaux(tabuleiro *tab,int l,int play){
	int col,i,nboats=0,posicoes=0,n,n1;
	int pos[100];
	int inicio[100];
	int limite[100];
	int colunas[100];


	posicoes=nbarcos(tab,l);
	
	for(col=0;col!=tab->tamanho[1];col++)
		if(tab->quadro[l][col]!='.' && tab->quadro[l][col]!='~') nboats++;
	nboats=tab->linhas[l]-nboats;

	for(i=0;i!=nboats;i++){pos[i]=1+i; inicio[i]=1+i;}
	
	for(i=nboats;i!=0;i--,posicoes--) limite[i]=posicoes;



	for(;play!=0;play--){
		if(pos[nboats-1]!=limite[nboats-1]) pos[nboats-2]++;
		else{
				for(n=nboats-1;n!=0;n--){
					if(pos[n]!=limite[n]){
						pos[n]++; inicio[n]++;
						for(n1=n+1;n1!=nboats;n1++){
							inicio[n1]=inicio[n1-1]+1;
							pos[n1]=inicio[n1];
						}
					} 
				break;
				}
		}
	}


	for(col=0,i=0;col!=tab->tamanho[1];col++)
		if(caniboat(tab,l,col)) colunas[i++]=col;


	for(i=0;i!=nboats;i++)
		--pos[i];


	for(i=0;i!=nboats;i++)
		coloca(tab,'o',l,colunas[pos[i]]);


   return tab;

}


/**
Esta função ordena um array, e da a outro array a mesma ordem que o primeiro.
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa onde o inicio por onde se deve começar a ordenar.
@param int u - Inteiro que representa ate que elemento do array se deve ordenar o array.
*/


void ordena(int comb[], int lin[],int p, int u){
	int m;
	if(p<u){
		m=particao(comb,lin,p,u);
		ordena(comb,lin,p,m-1);
		ordena(comb,lin,m+1,u);
	}
}


/**
Esta função partição é uma auxiliar da função ordena, que ordena uma pequena parte do array
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa onde o inicio por onde se deve começar a ordenar.
@param int u - Inteiro que representa ate que elemento do array se deve ordenar o array.
@return int - Retorna o numero que corresponde ao meio do segmento do array.
*/

int particao(int comb[],int lin[],int i, int s){
	int j,p;

	for(j=p=i;j<s;j++)
		if(comb[j]<=comb[s]) swap(comb,lin,j,p++);

	swap(comb,lin,p,s);

	return p;
}

/**
Esta função swap é funçao auxiliar da função partição que troca dois inteiros num array, e troca outros dois noutro array, para que os arrays possam ficar pela mesma ordem
@param int comb[]- Array que irá ser ordenado.
@param int lin[] - Array que ficara na mesma ordem que o primeiro.
@param int p - Inteiro que representa a posição do primeiro elemento a ser trocado.
@param int u - Inteiro que representa a posição do segundo elemento a ser trocado.
*/
void swap(int comb[], int lin[], int p, int s){
	int tmp;

	tmp=comb[p];
	comb[p]=comb[s];
	comb[s]=tmp;


	tmp=lin[s];
	lin[s]=lin[p];
	lin[p]=tmp;
}