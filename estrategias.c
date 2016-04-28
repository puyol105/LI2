#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"



/**
A função estra1(tabuleiro *tab) analisa o tabuleiro e em todos os segmentos de barcos conhecidos coloca água nas posições em redor ao segmento.
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra1(tabuleiro *tab){
	int lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++){
			if(tab->quadro[lin][col]!='.' && tab->quadro[lin][col]!='~'){
				if(pos(tab,lin+1,col+1)=='.') coloca(tab,'~',lin+1,col+1);
				if(pos(tab,lin+1,col-1)=='.') coloca(tab,'~',lin+1,col-1);
				if(pos(tab,lin-1,col+1)=='.') coloca(tab,'~',lin-1,col+1);
				if(pos(tab,lin-1,col-1)=='.') coloca(tab,'~',lin-1,col-1);
					if(tab->quadro[lin][col]=='o') ;
					else if(tab->quadro[lin][col]=='#'){
						if(pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n')  	{if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);}
						else if(pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') {if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);}
						else if(pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n') {if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);}
						else if(pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') {if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);}

						if((pos(tab,lin-1,col)!='~' && pos(tab,lin-1,col)!='.' && pos(tab,lin-1,col)!='n') ||
						   (pos(tab,lin+1,col)!='~' && pos(tab,lin+1,col)!='.' && pos(tab,lin+1,col)!='n')){if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);
																										    if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);}
						else if((pos(tab,lin,col+1)!='~' && pos(tab,lin,col+1)!='.' && pos(tab,lin,col+1)!='n') ||
							    (pos(tab,lin,col-1)!='~' && pos(tab,lin,col-1)!='.' && pos(tab,lin,col-1)!='n')){if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);
																												 if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);}
					}
					else if(tab->quadro[lin][col]=='v'){ 
						if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);
						if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);
						if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);}
					else if(tab->quadro[lin][col]=='^'){
						if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);
						if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);
						if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);}
					else if(tab->quadro[lin][col]=='<'){
						if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);
						if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);
						if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);}
					else if(tab->quadro[lin][col]=='>'){
						if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);
						if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);
						if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);}
					else if(tab->quadro[lin][col]=='O'){
						if(pos(tab,lin+1,col)=='.') coloca(tab,'~',lin+1,col);
						if(pos(tab,lin-1,col)=='.') coloca(tab,'~',lin-1,col);
						if(pos(tab,lin,col+1)=='.') coloca(tab,'~',lin,col+1);
						if(pos(tab,lin,col-1)=='.') coloca(tab,'~',lin,col-1);}}
		}

	return tab;
}

/**
A função estra2(tabuleiro *tab) analisa o tabuleiro e em todas as colunas e linhas que ja tenham o seu numero total de segmentos de barcos, coloca nessas colunas ou linhas todos os elementos que ainda não sejam conhecidos ('.') como sendo água.
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra2(tabuleiro *tab){
	int lin,col,n;

	for(lin=0;lin!=tab->tamanho[0];lin++){
		n=0;
		for(col=0;col!=tab->tamanho[1];col++) if(tab->quadro[lin][col]!='.' && tab->quadro[lin][col]!='~') n++;

		if (n==tab->linhas[lin]) alin(tab,lin);
	}

	for(col=0;col!=tab->tamanho[1];col++){
		n=0;
		for(lin=0;lin!=tab->tamanho[0];lin++) if(tab->quadro[lin][col]!='.' && tab->quadro[lin][col]!='~') n++;

		if (n==tab->colunas[col]) acol(tab,col);
	}

	return tab;
}

/**
A função estra3(tabuleiro *tab) analisa o tabuleiro e em todos os sitios onde poder acrescentar segmentos de barcos (por não haver mais nenhuma outra hipotse de escolha) coloca esses barcos nessas posições, e ainda tenta descobrir de que tipo de segmentos são os segmentos desconhecidos ('o').
@param tabuleiro *tab - Recebe o tabuleiro onde ira efetuar as alterações.
@return tabuleiro *tab - Devolve o tabuleiro apos as alterações.
*/

tabuleiro *estra3(tabuleiro *tab){
	int lin,col,dots,boat,col1,lin1;

		for(lin=0;lin!=tab->tamanho[0];lin++){
		dots=0;
		boat=0;
		for(col=0;col!=tab->tamanho[1];col++){ if(tab->quadro[lin][col]=='~');
											   else if (tab->quadro[lin][col]=='.')dots++;
											   else boat++;}

				if(tab->linhas[lin]==(boat+dots))
					for(col1=0;col1!=tab->tamanho[1];col1++)
						if(tab->quadro[lin][col1]=='.') coloca(tab,'A',lin,col1);}



		for(col=0;col!=tab->tamanho[1];col++){
		dots=0;
		boat=0;
		for(lin=0;lin!=tab->tamanho[0];lin++){ if(tab->quadro[lin][col]=='~');
											   else if (tab->quadro[lin][col]=='.')dots++;
											   else boat++;}

				if(tab->colunas[col]==(boat+dots))
					for(lin1=0;lin1!=tab->tamanho[0];lin1++)
							if(tab->quadro[lin1][col]=='.') coloca(tab,'A',lin1,col);}


		substitui(tab);
		replaceo(tab);


	return tab;}

/**
A função substitui(tabuleiro *tab) é uma auxiliar da função estra3(tabuleiro *tab) que apos a colocação de todos os 'A' (sendo que o 'A' representa que existe um segmento ali, porem ainda se ira estudar que tipo de segmento será) e os troca por caracteres validos do problema.
@param tabuleiro *tab- Recebe o tabuleiro sobre o qual ira efetuar as alterações.
*/

void substitui(tabuleiro *tab){
	int lin,col;



	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			if(pos(tab,lin,col)=='A'){

				if(((pos(tab,lin-1,col)=='A' || pos(tab,lin-1,col)=='#' || pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='o') && 
				    (pos(tab,lin+1,col)=='A' || pos(tab,lin+1,col)=='#' || pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='o')) ||
				   ((pos(tab,lin,col-1)=='A' || pos(tab,lin,col-1)=='#' || pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='o') && 
				    (pos(tab,lin,col+1)=='A' || pos(tab,lin,col+1)=='#' || pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='o'))) coloca(tab,'#',lin,col);
				
				else if((pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='o' || pos(tab,lin+1,col)=='A' || pos(tab,lin+1,col)=='#') &&
					    (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n' )) coloca(tab,'^',lin,col);

				else if((pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='o' || pos(tab,lin-1,col)=='A' || pos(tab,lin-1,col)=='#') &&
					    (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n')) coloca(tab,'v',lin,col);

				else if((pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='o' || pos(tab,lin,col+1)=='A' || pos(tab,lin,col+1)=='#') &&
					    (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n')) coloca(tab,'<',lin,col);

				else if((pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='o' || pos(tab,lin,col-1)=='A' || pos(tab,lin,col-1)=='#') &&
					    (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n')) coloca(tab,'>',lin,col);

				else if((pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n'  ) &&
					    (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n'  ) &&
					    (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n'  ) &&
					    (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n'  )) coloca(tab,'O',lin,col);
			}

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++)
				if(pos(tab,lin,col)=='A') coloca(tab,'o',lin,col);
}

/**
A função replaceo(tabuleiro *tab) é uma auxiliar da função estra3(tabuleiro *tab) que tenta trocar todos os segmentos não conhecidos ('o') pelo seu caracter final.
*/

void replaceo(tabuleiro *tab){
	int lin,col;

	for(lin=0;lin!=tab->tamanho[0];lin++)
		for(col=0;col!=tab->tamanho[1];col++)
			if(pos(tab,lin,col)=='o'){

				if(((pos(tab,lin-1,col)=='#' || pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='o') && 
				    (pos(tab,lin+1,col)=='#' || pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='o')) ||
				   ((pos(tab,lin,col-1)=='#' || pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='o') && 
				    (pos(tab,lin,col+1)=='#' || pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='o'))) coloca(tab,'#',lin,col);
				
				else if((pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='o' || pos(tab,lin+1,col)=='#') &&
					    (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n' )) coloca(tab,'^',lin,col);

				else if((pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='o' || pos(tab,lin-1,col)=='#') &&
					    (pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n')) coloca(tab,'v',lin,col);

				else if((pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='o' || pos(tab,lin,col+1)=='#') &&
					    (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n')) coloca(tab,'<',lin,col);

				else if((pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='o' || pos(tab,lin,col-1)=='#') &&
					    (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n')) coloca(tab,'>',lin,col);

				else if((pos(tab,lin+1,col)=='~' || pos(tab,lin+1,col)=='n') &&
					    (pos(tab,lin-1,col)=='~' || pos(tab,lin-1,col)=='n') &&
					    (pos(tab,lin,col+1)=='~' || pos(tab,lin,col+1)=='n') &&
					    (pos(tab,lin,col-1)=='~' || pos(tab,lin,col-1)=='n')) coloca(tab,'O',lin,col);

			}
}


tabuleiro *estra4(tabuleiro *tab){
	int lin,col;

		for(lin=0;lin!=tab->tamanho[0];lin++)
			for(col=0;col!=tab->tamanho[1];col++)
				 	 if (pos(tab,lin,col)=='<' && pos(tab,lin,col+1)=='.') coloca(tab,'o',lin,col+1);
				else if (pos(tab,lin,col)=='>' && pos(tab,lin,col-1)=='.') coloca(tab,'o',lin,col-1);
				else if (pos(tab,lin,col)=='#' && (
						(pos(tab,lin,col+1)=='#' || pos(tab,lin,col+1)=='>' || pos(tab,lin,col+1)=='o' || pos(tab,lin,col-1)=='#' || pos(tab,lin,col-1)=='<' || pos(tab,lin,col-1)=='o') ||
						(pos(tab,lin+1,col)=='n' || pos(tab,lin+1,col)=='~' || pos(tab,lin-1,col)=='n' || pos(tab,lin-1,col)=='~'))) { if(pos(tab,lin,col-1)=='.') coloca(tab,'o',lin,col-1);
																																	   if(pos(tab,lin,col+1)=='.') coloca(tab,'o',lin,col+1);}



		for(col=0;col!=tab->tamanho[1];col++)
			for(lin=0;lin!=tab->tamanho[0];lin++)
					 if (pos(tab,lin,col)=='^' && pos(tab,lin+1,col)=='.') coloca(tab,'o',lin+1,col);
				else if (pos(tab,lin,col)=='v' && pos(tab,lin-1,col)=='.') coloca(tab,'o',lin-1,col);
				else if (pos(tab,lin,col)=='#' && (
						(pos(tab,lin+1,col)=='#' || pos(tab,lin+1,col)=='v' || pos(tab,lin+1,col)=='o' || pos(tab,lin-1,col)=='#' || pos(tab,lin-1,col)=='^' || pos(tab,lin-1,col)=='o') ||
						(pos(tab,lin,col+1)=='n' || pos(tab,lin,col+1)=='~' || pos(tab,lin,col-1)=='n' || pos(tab,lin,col-1)=='~'))) { if(pos(tab,lin-1,col)=='.') coloca(tab,'o',lin-1,col);
																																	   if(pos(tab,lin+1,col)=='.') coloca(tab,'o',lin+1,col);}

			

			replaceo(tab);


	return tab;
}