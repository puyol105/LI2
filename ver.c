#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"


/**
A função verifica(tabuleiro *tab) analisa o estado do tabuleiro, isto é, se o tabuleiro atual é possivel de resolver ou não, devolvendo falso e imprimdo a mensagem NAO no caso de não ser possivel de resolver, e retornando 1 e escrevendo SIM se for possivel resolver o tabuleiro no estado atual.
@param tabuleiro *tab - Recebe o tabuleiro que deve verificar se é valido ou não.
@return int - Retorna um inteiro indicando o valor de verdade acerca do tabuleiro ser ou não possivel de resolver. 
*/


int verifica(tabuleiro *tab){
	int r=TRUE,lin,col;

	char tmp[100][100];

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			tmp[lin][col]=tab->quadro[lin][col];


	estra1(tab);
	estra3(tab);
	estra4(tab);

	if (caracteres(tab)!=0){
		if(size(tab)!=0){
			if(space(tab)!=0){
				if(tamfix(tab)!=0){
					if(verilin(tab)!=0){
						if(vericol(tab)!=0){
							if(submar(tab)!=0){
								if(bottom(tab)!=0){
									if(top(tab)!=0){
										if(rigth(tab)!=0){
											if(left(tab)!=0){ 
												if(middle(tab)!=0);
												else r=FALSE;}
											else r=FALSE;}
										else r=FALSE;}
									else r=FALSE;}
								else r=FALSE;}
							else r=FALSE;}	
						else r=FALSE;}
					else r=FALSE;}
				else r=FALSE;}
			else r=FALSE;}
		else r=FALSE;}
	else r=FALSE;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			tab->quadro[lin][col]=tmp[lin][col];

	if(r && dots(tab)) return 2;


	return r;
}
/**
A função verifica se todos os caracteres do tabuleiro pertencem a lista de caracteres permitidos pelo programa (O,~,#,<,>,v,^,o,.).
@param tabuleiro *tab - Recebe como argumento o tabuleiro que deverá avaliar.
@return int- Retorna um inteiro com a função de valor de verdade (0-FALSE, 1-TRUE).
*/

int caracteres (tabuleiro *tab){
		int r=1,lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			if(tab->quadro[lin][col]!='O' &&
			   tab->quadro[lin][col]!='~' && 
			   tab->quadro[lin][col]!='#' && 
			   tab->quadro[lin][col]!='<' && 
			   tab->quadro[lin][col]!='>' && 
			   tab->quadro[lin][col]!='v' && 
			   tab->quadro[lin][col]!='^' &&
			   tab->quadro[lin][col]!='o' &&
			   tab->quadro[lin][col]!='.') r=0;

	return r;
}

/**
A função verilin(tabuleiro *tab) verifica se o numero de segmentos de barcos da linha é igual, maior ou menor que o numero limite de segmentos dessa linha.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna 0 se tiver mais segmentos do que o possivel, 2 se tiver menos e 1 se tiver exatamente o mesmo numero de segmentos, ou seja, se a linha estiver resolvida.
*/

int verilin (tabuleiro *tab){
	int r=1,lin,col,q;


	for(lin=0;lin!=tab->tamanho[0];lin++){
		q=0;
		for(col=0;col!=tab->tamanho[1];col++)
			if(pos(tab,lin,col)!='~' && pos(tab,lin,col)!='.') q++;
		if (q>tab->linhas[lin]) return 0;
		else if (q<tab->linhas[lin]) r=2;
		else{} ;
	}

	return r;
}

/**
A função vericol(tabuleiro *tab) verifica se o numero de segmentos de barcos da coluna é igual, maior ou menor que o numero limite de segmentos dessa coluna.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna 0 se tiver mais segmentos do que o possivel, 2 se tiver menos e 1 se tiver exatamente o mesmo numero de segmentos, ou seja, se a coluna estiver resolvida.
*/

int vericol(tabuleiro *tab){
	int r=1,lin,col,q;

	for(col=0;col!=tab->tamanho[1];col++){
		q=0;
		for(lin=0;lin!=tab->tamanho[0];lin++)
			if(pos(tab,lin,col)!='~' && pos(tab,lin,col)!='.') q++;
		if (q>tab->colunas[col]) return 0;
		else if (q<tab->colunas[col]) r=2;
		else{};
	}
	return r;

}

/**
A função submar(tabuleiro tab), verifica se para todos os barcos dados como submarinos(1 segmento de comprimento) estão bem colocadas no tabuleiro, isto é, sem nenhum outro segmento de barco nas proximidades.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int -Retorna um inteiro como valor de verdade, isto é 0 para FALSE (o tabuleiro tem submarinos a tocar em outros barcos) e 1 para TRUE (os submarinos estão bem colocados).
*/


int submar(tabuleiro *tab){
	int r=1,lin,col;



	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++){
				 if(pos(tab,lin,col)=='O' &&(
				   (pos(tab,lin+1,col)!='.' && pos(tab,lin+1,col)!='~' && pos(tab,lin+1,col)!='n') ||
				   (pos(tab,lin-1,col)!='.' && pos(tab,lin-1,col)!='~' && pos(tab,lin-1,col)!='n') ||
				   (pos(tab,lin,col+1)!='.' && pos(tab,lin,col+1)!='~' && pos(tab,lin,col+1)!='n') ||
				   (pos(tab,lin,col-1)!='.' && pos(tab,lin,col-1)!='~' && pos(tab,lin,col-1)!='n') ||
				   (pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='n') ||
				   (pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='n') ||
				   (pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='n') ||
				   (pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='n'))) r=0;}

	return r;
}

/**
A função bottom(tabuleiro *tab) verifica se todas as peças inferiores dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco acima e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças 'v' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/



int bottom(tabuleiro *tab){
	int r=1,lin,col;

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++){
				 if(pos(tab,lin,col)=='v' &&(
				   (pos(tab,lin+1,col)!='.' && pos(tab,lin+1,col)!='~' && pos(tab,lin+1,col)!='n') ||
				   (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n') ||
				   (pos(tab,lin,col+1)!='.' && pos(tab,lin,col+1)!='~' && pos(tab,lin,col+1)!='n') ||
				   (pos(tab,lin,col-1)!='.' && pos(tab,lin,col-1)!='~' && pos(tab,lin,col-1)!='n') ||
				   (pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='n') ||
				   (pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='n') ||
				   (pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='n') ||
				   (pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='n'))) r=0;}
		return r;
}

/**
A função top(tabuleiro *tab) verifica se todas as peças superiores dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco abaixo e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int top(tabuleiro *tab){
	int r=1,lin,col;

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++){
				 if(pos(tab,lin,col)=='^' &&(
				   (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') ||
				   (pos(tab,lin-1,col)!='.' && pos(tab,lin-1,col)!='~' && pos(tab,lin-1,col)!='n') ||
				   (pos(tab,lin,col+1)!='.' && pos(tab,lin,col+1)!='~' && pos(tab,lin,col+1)!='n') ||
				   (pos(tab,lin,col-1)!='.' && pos(tab,lin,col-1)!='~' && pos(tab,lin,col-1)!='n') ||
				   (pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='n') ||
				   (pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='n') ||
				   (pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='n') ||
				   (pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='n'))) r=0;}
		return r;

}

/**
A função left(tabuleiro *tab) verifica se todas as peças a esquerda dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco a direita e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int left(tabuleiro *tab){
	int r=1,lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++){
				 if(pos(tab,lin,col)=='<' &&(
				   (pos(tab,lin+1,col)!='.' && pos(tab,lin+1,col)!='~' && pos(tab,lin+1,col)!='n') ||
				   (pos(tab,lin-1,col)!='.' && pos(tab,lin-1,col)!='~' && pos(tab,lin-1,col)!='n') ||
				   (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') ||
				   (pos(tab,lin,col-1)!='.' && pos(tab,lin,col-1)!='~' && pos(tab,lin,col-1)!='n') ||
				   (pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='n') ||
				   (pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='n') ||
				   (pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='n') ||
				   (pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='n'))) r=0;}
		return r;
}

/**
A função rigth(tabuleiro *tab) verifica se todas as peças a direita dos barcos estão bem colocadas, ou seja, tem que ter um segmento de barco a esquerda e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/

int rigth(tabuleiro *tab){
	int r=1,lin,col;

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++){
				 if(pos(tab,lin,col)=='>' &&(
				   (pos(tab,lin+1,col)!='.' && pos(tab,lin+1,col)!='~' && pos(tab,lin+1,col)!='n') ||
				   (pos(tab,lin-1,col)!='.' && pos(tab,lin-1,col)!='~' && pos(tab,lin-1,col)!='n') ||
				   (pos(tab,lin,col+1)!='.' && pos(tab,lin,col+1)!='~' && pos(tab,lin,col+1)!='n') ||
				   (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n') ||
				   (pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='n') ||
				   (pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='n') ||
				   (pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='n') ||
				   (pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='n'))) r=0;}

		return r;
}

/**
A função middle(tabuleiro *tab) verifica se todas as peças interiores dos barcos estão bem colocadas, ou seja, tem que ter pelo menos um segmento de barco abaixo e outro acima, ou um a sua direita e outro a sua esquerda, e nenhum em qualquer dos outros lados.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se as peças '^' estiverem mal colodadas) ou 1 para TRUE (se as peças tiverem bem colocadas).
*/


int middle(tabuleiro *tab){
	int r=1,lin,col;

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++)
				 if(pos(tab,lin,col)=='#') {
				    if((pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='#' || pos(tab,lin+1,col)=='o') && (pos(tab,lin-1,col)!='#' && pos(tab,lin-1,col)!='^' && pos(tab,lin-1,col)!='o')) r=0;
				 	else if((pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='#' || pos(tab,lin-1,col)=='o') && (pos(tab,lin+1,col)!='#' && pos(tab,lin+1,col)!='v' && pos(tab,lin+1,col)!='o')) r=0;
				 	else if((pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='#' || pos(tab,lin,col+1)=='o') && (pos(tab,lin,col-1)!='#' && pos(tab,lin,col-1)!='<' && pos(tab,lin,col-1)!='o')) r=0;
				 	else if((pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='#' || pos(tab,lin,col-1)=='o') && (pos(tab,lin,col+1)!='#' && pos(tab,lin,col+1)!='>' && pos(tab,lin,col+1)!='o')) r=0;

				 	else if((pos(tab,lin+1,col+1)!='~' && pos(tab,lin+1,col+1)!='.' && pos(tab,lin+1,col+1)!='n') ||
				 		    (pos(tab,lin+1,col-1)!='~' && pos(tab,lin+1,col-1)!='.' && pos(tab,lin+1,col-1)!='n') ||
				 		    (pos(tab,lin-1,col+1)!='~' && pos(tab,lin-1,col+1)!='.' && pos(tab,lin-1,col+1)!='n') ||
				 		    (pos(tab,lin-1,col-1)!='~' && pos(tab,lin-1,col-1)!='.' && pos(tab,lin-1,col-1)!='n')) r=0;

				    else if (pos(tab,lin+1,col)=='<' || pos(tab,lin+1,col)=='>' || pos(tab,lin+1,col)=='^' || pos(tab,lin+1,col)=='O') r=0;
				 	else if (pos(tab,lin-1,col)=='<' || pos(tab,lin-1,col)=='>' || pos(tab,lin-1,col)=='v' || pos(tab,lin-1,col)=='O') r=0;
				    else if (pos(tab,lin,col+1)=='<' || pos(tab,lin,col+1)=='v' || pos(tab,lin,col+1)=='^' || pos(tab,lin,col+1)=='O') r=0;
				    else if (pos(tab,lin,col-1)=='>' || pos(tab,lin,col-1)=='v' || pos(tab,lin,col-1)=='^' || pos(tab,lin,col-1)=='O') r=0;

				 }

			return r;
}


/**
A função size(tabuleiro *tab) verifica se todas as linhas e colunas tem um numero de segmentos esperado (quando o tabuleiro estiver resolvido) possivel para o tamanho do tabuleiro.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se tiver segmentos amais para o tamanho da tabuleiro) ou 1 para TRUE (se o numero de segmentos for possivel de colocar no tabuleiro).
*/

int size(tabuleiro *tab){
	int r=1,lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		if(tab->linhas[lin]>tab->tamanho[0]) r=0;
	for(col=0;col!=tab->tamanho[1];col++)
		if(tab->colunas[col]>tab->tamanho[1]) r=0;

	return r;

}

/**
A função size(tabuleiro *tab) verifica se todas as linhas e colunas tem um numero de segmentos possivel, com a adição de que se houver um segmento que tenha de estar nessa linha ou coluna obrigatoriamente, mas ainda nao se saiba (por exemplo se tivermos um segmento '<' e aseguir um '.', sabemos que esse ponto terá de ser um segmento, mas ainda é um segmento ficticio, e esta função tenta encontrar casos como esses.
@param tabuleiro *tab - Recebe o tabuleiro sobre o qual ira efetuar os testes.
@return int - Retorna o valor de verdade 0 para FALSE (se tiver segmentos amais para o tamanho da tabuleiro) ou 1 para TRUE (se o numero de segmentos for possivel de colocar no tabuleiro).
*/

int tamfix(tabuleiro *tab){
	int r=TRUE,lin,col,n;

	for(lin=0;lin!=tab->tamanho[0];lin++){
		n=0;
		for(col=0;col!=tab->tamanho[1];col++){ if(tab->quadro[lin][col]!='.' && tab->quadro[lin][col]!='~')n++;
				if(pos(tab,lin,col)=='<' && pos(tab,lin,col+1)=='.')n++;
				if(pos(tab,lin,col)=='>' && pos(tab,lin,col-1)=='.')n++;

				 if(pos(tab,lin,col)=='#' && (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') && pos(tab,lin,col-1)=='.' && pos(tab,lin,col+1)=='.') n+=2;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') && pos(tab,lin,col+1)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') && pos(tab,lin,col-1)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n') && pos(tab,lin,col-1)=='.' && pos(tab,lin,col+1)=='.') n+=2;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n') && pos(tab,lin,col+1)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n') && pos(tab,lin,col-1)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col-1)=='#' || pos(tab,lin,col-1)=='<') && pos(tab,lin,col+1)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col+1)=='#' || pos(tab,lin,col+1)=='>') && pos(tab,lin,col-1)=='.') n++;
		}
		if(n>tab->linhas[lin])r=0;
	}
	for(col=0;col!=tab->tamanho[1];col++){
		n=0;
		for(lin=0;lin!=tab->tamanho[0];lin++){ if(tab->quadro[lin][col]!='.' && tab->quadro[lin][col]!='~')n++;
				if(pos(tab,lin,col)=='v' && pos(tab,lin-1,col)=='.')n++;
				if(pos(tab,lin,col)=='^' && pos(tab,lin+1,col)=='.')n++;

				 if(pos(tab,lin,col)=='#' && (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') && pos(tab,lin-1,col)=='.' && pos(tab,lin+1,col)=='.') n+=2;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') && pos(tab,lin+1,col)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') && pos(tab,lin-1,col)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n') && pos(tab,lin-1,col)=='.' && pos(tab,lin+1,col)=='.') n+=2;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n') && pos(tab,lin+1,col)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n') && pos(tab,lin-1,col)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin-1,col)=='#' || pos(tab,lin-1,col)=='<') && pos(tab,lin+1,col)=='.') n++;
			else if(pos(tab,lin,col)=='#' && (pos(tab,lin+1,col)=='#' || pos(tab,lin+1,col)=='>') && pos(tab,lin-1,col)=='.') n++;
		}
		if(n>tab->colunas[col]) r=0;
	}


	return r;
}


int space(tabuleiro *tab){
	int lin,col,n,r=TRUE;

	for(lin=0;lin!=tab->tamanho[0];lin++){
		n=0;
		for(col=0;col!=tab->tamanho[1];col++)
			if(tab->quadro[lin][col]!='~') n++;
		if (n<tab->linhas[lin]) r=FALSE;
	}
	for(col=0;col!=tab->tamanho[1];col++){
		n=0;
		for(lin=0;lin!=tab->tamanho[0];lin++)
			if(tab->quadro[lin][col]!='~') n++;
		if(n<tab->colunas[col]) r=FALSE;
	}

	return r;
}



int dots(tabuleiro *tab){
	int lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			if(tab->quadro[lin][col]=='.' || tab->quadro[lin][col]=='o') return FALSE;

	return TRUE;
}