#ifndef SEM_H
#define SEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "absyn.h"



//retornar uma enum com o tipo retornado pelo checker, para guardar nas variáveis da ast
Tipo_e chk_Exp(Exp_n* e, Tipo_e tipo, int pos)
{
    switch(tipo)
    {
        case exp_t: puts("okexp"); break;

        
        
        default: puts("okexp");
    }
    return tipo;
}

void chk_Var(Var_n* v, Tipo_e tipo, int pos)
{
    switch(tipo)
    {
        case exp_t: puts("okexp");
        default:;
    }   
}

void chk_Dec(Dec_n* d, Tipo_e tipo, int pos)
{
    switch(tipo)
    {
        case exp_t: puts("okdec");
        default:;
    }    
}

void chk_Tipo(Tipo_n* t, Tipo_e tipo, int pos)
{
    switch(tipo)
    {
        case exp_t: puts("oktyp");
        default:;
    }   
}

Tipo_e chk_Const(void* c, Tipo_e tipo, int pos)
{
    //printf("pos %d\n", pos);
    switch(tipo)
    {
        case int_t: return int_t;
        case str_t: return str_t;
        default: printf("ERRO: Constante inválida, Posição %d\n", pos);;
    }    return tipo;
}



#endif
