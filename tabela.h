#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 128 //maximo de linhas na tabela
#define NMAX 16 //num maximo caracteres do nome
//organizaçao linear


typedef struct Linha
{   
    int nivel;
    
    char* nome;
    int tipo;
    int endereco; //EM_tokPos
    char* valor;
    
}Linha;

typedef struct Tabela
{
    Linha* linha;//vetor das linhas da tabela
    int* escopo; //vetor de indices de linhas
    int nivel;   //indice do vetor de escopo atual
    int L;       //indice do primeira linha vazia
}Tabela;

Tabela* T_init();

void T_entrar_bloco(Tabela* t); //conforme aula 17 min 30 ; slide comp-06

void T_sair_bloco(Tabela* t);

int T_checar_existencia(Tabela* t, char* nome);

void T_instalar(Tabela* t, char* nome, int tipo, char* valor); //retorna o endereço na tabela em formato char*

void T_imprimir(Tabela* t);

void T_delete(Tabela* t);

#endif

