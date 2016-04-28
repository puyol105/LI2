#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"


/**
A função lerf, desepenha o mesmo papel que a função ler, ou seja, lê um tabuleiro, no entanto dado por um ficheiro. A função baseia-se na função auxiliar scanf e fgets para a leitura dos dados.
O que diferencia da função ler, é que o fgets, em vez de ler do teclado, lê de um ficheiro.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@param char - Recebe o nome do ficheiro.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *lerf(tabuleiro *tab,char *n){
  int l,c,s;
  char linha[MAX_SIZE];
  char resto[MAX_SIZE];
  char *z;
  FILE *in;

  in = fopen (n, "r");

  z=fgets(linha,MAX_SIZE,in);
  sscanf(linha,"%d %d",&tab->tamanho[0],&tab->tamanho[1]);  
  z=fgets(linha,MAX_SIZE,in);                           
  for(l=0;l<tab->tamanho[0];l++){
    int v;
    sscanf(linha,"%d %[^\n]",&v,resto);  
    tab->linhas[l]=v;
    strcpy(linha,resto);
  }

  z=fgets(linha,MAX_SIZE,in);
  for(c=0;c<tab->tamanho[1];c++){
    int b;
    sscanf(linha,"%d %[^\n]",&b,resto); 
    tab->colunas[c]=b;
    strcpy(linha,resto);
  }

  for(l=0;l<tab->tamanho[0];l++){
    z=fgets(linha,MAX_SIZE,in);    
    for(c=0;c<tab->tamanho[1];c++){
      tab->quadro[l][c]=linha[c];
    }
  }
  fclose(in);
  s=strlen (z)*0;
  if(s==0) return tab;
  return tab;
}

/**
A função imprimirf, desepenha o mesmo papel que a função imprimir, ou seja, imprime o estado actual do tabuleiro num ficheiro, pelo nome dado. 
A diferença é que esta função imprime o tabuleiro no mesmo formato que se lê, ou seja, imprime o estado do tabuleiro de forma que seja possivel que seja lido pela função lerf.
@param tab - Recebe a estrutura onde irá guardar o tabuleiro do jogo.
@param char - Recebe o nome do ficheiro.
@return tabuleiro *tab - Retorna o tabuleiro novo.
*/

tabuleiro *imprimirf(tabuleiro *tab,char *n){
    FILE *out;
     int i,j;
    /* abre o ficheiro resultados.txt para escrita e associa-o a out */
    out = fopen( n, "w");
 
    fprintf(out, "%d %d\n",tab->tamanho[0],tab->tamanho[1]);

    for(i=0;i!=tab->tamanho[0];i++){
        if ((i+1)!=tab->tamanho[0]) fprintf(out, "%d ",tab->linhas[i] );
        else fprintf(out, "%d",tab->linhas[i]);}
        fprintf(out, "\n");

    for(i=0;i!=tab->tamanho[1];i++){
        if ((i+1)!=tab->tamanho[1]) fprintf(out, "%d ",tab->colunas[i] );
        else fprintf(out, "%d",tab->colunas[i]); }    
        fprintf(out, "\n"); 

    for(i=0;i<tab->tamanho[0];i++){
       for(j=0;j<tab->tamanho[1];j++)
           fprintf(out,"%c",tab->quadro[i][j]);  
       fprintf(out, "\n");              
  }
      /* fecha os ficheiros */
      fclose( out );
    return tab;

}