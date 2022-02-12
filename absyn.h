#ifndef ABS_H
#define ABS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tabela.h"

#include "tipos.h"


typedef struct ExpSeq //listas encadeadas para expressoes
{
    Tipo_e t;
    Exp_n* elem;
    ExpSeq* prox;
}ExpSeq;

typedef struct DecList //listas encadeadas para declaraçoes
{
    Tipo_e t;
    Dec_n* elem;
    DecList* prox;
}DecList;

typedef struct VarList //listas encadeadas para declaraçoes
{
    Tipo_e t;
    Var_n* elem;
    VarList* prox;
}VarList;


typedef struct Var_n
{
    int pos;
    Tipo_e tipoVar;
    char* nome;
    struct
    {

        Exp_n* valor;
        int tab[2]; //pos,escopo
    }normalVar;
    
    struct
    {
        Exp_n* valor;
        int tab[2]; //pos,escopo
    }funcVar;
    
    struct
    {
        Exp_n* valor;
        int tab[2]; //pos,escopo
        Exp_n* exp;
    }arranjoVar;
}Var_n;

typedef struct Dec_n
{
    int pos;
    Tipo_e tipoDec;
    
    Dec_n* funDecList;
    Tipo_n* tylist;
    
    struct //declaraçao var
    {
        int* simb; //tupla(lina e escopo na tabela)
        char* nome;
        Exp_n* var;
        int escape;
    }varDec;
    
    struct
    {
        int* simb; //tupla(lina e escopo na tabela)
        char* nome;
        Exp_n init;
        int escape;
    }funDec; //declaraçao fun
    
    struct
    {
        int simb[2]; //tupla(lina e escopo na tabela)
        char* nome;
        Exp_n init;
        int escape;
    }tyDec; //declaraçao tipo

}Dec_n;

typedef struct Tipo_n
{
    int pos;
    Tipo_e tipoTipo;
    
    struct
    {
        Dec_n* tydec;
        Tabela*  tab;
    } tipo;

}Tipo_n;

Exp_n* novo_call(int pos, Tipo_e tipo, char* idFun, ExpSeq* a, Tabela* t); //vale 

Exp_n* novo_ifthen(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Exp_n* novo_ifthenelse(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2, Exp_n* e3); //vale 

Exp_n* novo_while(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Exp_n* novo_for(int pos, Tipo_e tipo, char* idVar, Exp_n* e1, Exp_n* e2, Exp_n* e3, Tabela* t); //vale 

Exp_n* lvalue_to_exp(Tipo_e tipo, Var_n* v, Tabela* t);

Exp_n* novo_atribuicao(int pos, Tipo_e tipo, Var_n* v, Exp_n* e, Tabela* t);

Var_n* acessar_lvalue(int pos, Tipo_e tipo, Var_n* lv, char* idVar, Exp_n* e, Tabela* t);

DecList* novo_varlist(int pos, Tipo_e tipo, char* varId, char* tyId, DecList* dl, Tabela* t);

Tipo_n* novo_tipo(int pos, Tipo_e tipo );

Dec_n* novo_tipodec(int pos, Tipo_e tipo, char* tyId, DecList* dl, Tabela* t); //igual struct de C

Dec_n* novo_vardec(int pos, Tipo_e tipo, char* varId, char* tyId, Exp_n* exp, Tabela* t); //simple var, record var, array var
Dec_n* novo_fundec(int pos, Tipo_e tipo, char* funId, DecList* tl, char* tyId, Exp_n* e, Tabela* t);

DecList* novo_declist(int pos, Tipo_e tipo, Dec_n* d, DecList* dl);

ExpSeq* novo_expseq(int pos, Tipo_e tipo, Exp_n* e, ExpSeq* es);

Exp_n* novo_expseqpar(int pos, Tipo_e tipo, ExpSeq* es);

Exp_n* novo_const(int pos, Tipo_e tipo, int vi, char* vs);

Exp_n* novo_exp_op(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Exp_n* novo_let(int pos, Tipo_e tipo, DecList* dl, ExpSeq* es, Tabela* t); 

Dec_n* novo_dec(int pos, Tipo_e tipo, Dec_n* d); //nao precisa

#endif
