#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bn.h"
#include "file.h"
#include "estrategias.h"
#include "ver.h"
#include "resolver.h"



/**
A função interpretar serve para interpretar os comandos, e verificar se existe, e se caso exista, aplicar a função correspondente. A função
verifica os comandos inseridos com a função strcmp, e caso seja igual, excuta a respectiva função de cada comando, caso contário, 
imprime "Comando inválido!".
@param char *linha - Recebe uma string iniciada na função interpretador().
@param tabuleiro *tab - Recebe a estrutura tabuleiro, na qual o programa irá atuar.
@return tabuleiro * - Retorna o tabuleiro mais recente.
*/
tabuleiro *interpretar(char *linha,tabuleiro *tab) {
    char comando[MAX_SIZE];
    char arg1[MAX_SIZE];
    char arg2[MAX_SIZE];
    int nargs;
    tabuleiro *w,*f;
    nargs = sscanf(linha , "%s %s %s",comando , arg1 , arg2);

    if(strcmp(comando , "q") == 0) return 0;

    else if(strcmp(comando , "c") == 0 && nargs==1) {
        w = (tabuleiro *) malloc(sizeof(struct tabuleiro));
        w->prox=tab;
        return ler(w);
    }

    else if(strcmp(comando , "m") == 0 && nargs==1) return imprimir(tab);

    else if(strcmp(comando , "h") == 0 && nargs==2) {
        f = aloca(tab);
        return verigual(tab,alin(f,(atoi(arg1)-1)));
    }

    else if(strcmp(comando , "v") == 0 && nargs==2) {
        f = aloca(tab);
        return verigual(tab,acol(f,(atoi(arg1)-1)));
    }

    else if((comando[0]=='p') && nargs==3) {
        f = aloca(tab);
        return verigual(tab,coloca(f,comando[1],(atoi(arg1)-1),(atoi(arg2)-1)));
    }

    else if(strcmp(comando , "l") == 0 && nargs==2){
        w = (tabuleiro *) malloc(sizeof(struct tabuleiro));
        w->prox=tab;
        return lerf(w,arg1);
    }

	else if(strcmp(comando , "e") == 0 && nargs==2) return imprimirf(tab,arg1);

	else if(strcmp(comando , "V") == 0 && nargs==1) {

        if(verifica(tab)==FALSE) printf("NAO\n");
        else printf("SIM\n");

        return tab;}

	else if(strcmp(comando , "D") == 0 && nargs==1) return desfaz(tab);

	else if(strcmp(comando ,"E1") == 0 && nargs==1) {
        f = aloca(tab);
        return verigual(tab,estra1(f));
    }

	else if(strcmp(comando ,"E2") == 0 && nargs==1) {
        f = aloca(tab);
        return verigual(tab,estra2(f));
    }

	else if(strcmp(comando ,"E3") == 0 && nargs==1) {
        f = aloca(tab);
        return verigual(tab,estra3(f));
    } 

    else if(strcmp(comando ,"E4") == 0 && nargs==1) {
        f = aloca(tab);
        return verigual(tab,estra4(f));
    } 


    else if(strcmp(comando ,"R") == 0 && nargs==1) {
        f = aloca(tab);
        return verigual(tab,resolver(f));
    } 

    else invalido();

    return tab;
}


/**
A função interpretador tem como objectivo controlar os valores dados pela funçao interpretar, e apatir dai para o ciclo ou continua. 
@param tabuleiro *tab - Recebe a estrutura tabuleiro inicializada na função main().
*/
void interpretador (tabuleiro *tab){
     char buffer[MAX_SIZE];
     int ciclo = 1;
     while(ciclo && fgets(buffer , MAX_SIZE , stdin) != NULL){
           tab = interpretar(buffer,tab);
        if(tab == NULL) ciclo = 0;}
}

/**
A main do programa que apenas excuta a função interpretar.
@return int - Se o programa funcionar corretamente, retorna o inteiro 0.
*/
int main () {
   tabuleiro *tab=(tabuleiro *) malloc(sizeof(struct tabuleiro));
   interpretador (tab);
   return 0;
}
