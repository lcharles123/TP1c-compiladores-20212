#ifndef ABS_H
#define ABS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tabela.h"

/*
typedef struct Exp *Exp_n; //Exp_nó é uma estrutura que será um nó na árvore

typedef struct Var *var_n;
typedef struct Dec *dec_n;
typedef struct Tipo *tipo_n;
typedef struct Const *const_n;*/
typedef struct Exp_n Exp_n; //necessario para tipos recursivos
typedef struct Var_n Var_n;
typedef struct Dec_n Dec_n;
typedef struct Tipo_n Tipo_n;

typedef enum //usar esse enum para diferenciar entre os diversos tipos
{
    //exp
    exp_t = 1,
    lvalue_t, //exp
    nil_t,
    expseq_t,
    net_t,

    int_t,
    str_t,
    
    call_t,
    op_t,
    
    record_t, //tid
    atribui_t,
    if_t,
    while_t,
    for_t,
    break_t,
    let_t,
    
    mais_op, menos_op, //operadores exp 
    vezes_op, dividir_op, 
    igual_op, diferente_op, 
    menor_op, maior_op, 
    menorig_op, maiorig_op, 
    e_op, ou_op,
    
    ty_nome, //nomes de tipos
    ty_record,
    ty_arranjo,
    
    normal_t, //tipo de variavel
    func_t,
    arranjo_t,
    
    fundec_t, //decs
    vardec_t,
    tydec
} Tipo_e;

typedef struct Exp_n //estrutura para os tipos derivados do nao terminal exp
{
    int pos; //posiçao no código
    Tipo_e tipoExp;

    Var_n *var;
    int nil;
    int int_n;
    char *str_n;

    struct
    {
      char* id;
      Exp_n *args; //args eh um vetor do tipo Exp
    } call; //chamada proc

    struct
    {
        Tipo_e tipoOp;

        Exp_n* opEsq;
        Exp_n* opDir;
    } oper;

    struct
    {
      Tipo_n* tipo;
      Exp_n* expList;
    } record;

    struct
    {
      Var_n *var;
      Exp_n *exp;
    } atribui;

    struct
    {
      Exp_n *test;
      Exp_n *then;
      Exp_n *cc;
    } se;

    struct
    {
      Exp_n *test;
      Exp_n *body;
    } enquanto;

    struct
    {
      Var_n *var; //symbol?
      Exp_n *lo;
      Exp_n *hi;
      Exp_n *body;
      int escape;
    } para;
    
    struct
    { }quebrar; //precisa apenas de pos

    struct
    {
      Dec_n* decs;
      Exp_n* body;
    } let;

    struct
    {
      Tipo_n *typ;//sym
      int tamanho;
      Exp_n *init;
    } arranjo;
}Exp_n;

typedef struct Var_n
{
    int pos;
    Tipo_e tipoVar;
    
    struct
    {
        Tabela* tab; //simbolo
    }normalVar;
    
    struct
    {
        Tabela* tab; //simbolo
    }funcVar;
    
    struct
    {
        Var_n* var; //simbolo
        Exp_n* exp;
    }arranjoVar;
}Var_n;

typedef struct Dec_n
{
    int pos;
    Tipo_e tipoDec;
    
    Dec_n* funDecList;
    Tipo_n* tylist;
    struct
    {
        Tabela tab;
        Exp_n init;
        int escape;
    }varDec;
    struct
    {
        Tabela tab;
        Exp_n init;
        int escape;
    }funDec;
    struct
    {
        Tabela tab;
        Exp_n init;
        int escape;
    }tyDec;
    
    

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




#endif
