#ifndef ABS_H
#define ABS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tabela.h"


typedef enum //usar esse enum para diferenciar entre os diversos tipos
{
    //exp
    nulo,
    exp_t = 1,
    lvalue_t, //exp
    expseq_t,
    neg_t, //op de negaçao
    
    nil_t,
    int_t,
    str_t,
    
    call_t,
    op_t,
    
    record_t, //tid
    atribui_t,
    ifthen_t,
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
    
    normalvar_t, //tipo de variavel
    funcvar_t,
    arranjovar_t, 
    
    var_nome, //nome do lvalue_t
    var_interna,//variavel interna do
    
    args_t,
    ideps_t,
    
    fundec_t, //decs
    vardec_t,
    tydec_t
} Tipo_e;


typedef struct Exp_n Exp_n;  //Exp_nó é uma estrutura que será um nó na árvore
typedef struct ExpSeq ExpSeq;
typedef struct Var_n Var_n;
typedef struct Dec_n Dec_n;
typedef struct DecList DecList;
typedef struct Tipo_n Tipo_n;
typedef struct VarList VarList;

typedef struct ExpSeq //listas encadeadas para expressoes
{
    Exp_n* elem;
    ExpSeq* prox;
}ExpSeq;

typedef struct DecList //listas encadeadas para declaraçoes
{
    Dec_n* elem;
    DecList* prox;
}DecList;

typedef struct VarList //listas encadeadas para declaraçoes
{
    Var_n* elem;
    VarList* prox;
}VarList;

typedef struct Exp_n //estrutura para os tipos derivados do nao terminal exp
{
    int pos; //posiçao no código
    Tipo_e tipoExp;

    Var_n *var;
    
    struct
    {
        int nil;
        int int_v;
        char *str_v;
    }constante;
    
    struct
    {
      int idTab; //endereço na tabela
      ExpSeq *args; //args eh um vetor do tipo Exp
      
    } call; //chamada proc

    struct oper //todos os endpoints de exp estão nas structs abaixo, e os tipos serão unificados nessa struct Exp_n
    {
        Exp_n* opEsq;
        Exp_n* opDir;
    } oper;

    struct
    {
      Tipo_n* tipo; //vetor de tipos
      Exp_n* ExpSeq;
    } record;

    struct
    {
      Var_n *var; //variavel
      Exp_n *exp; //exp lado dir
    } atribui;

    struct
    {
      Exp_n *test; //test booleano
      Exp_n *then; //corpo
      Exp_n *cc;  // caso contrario
    } se;

    struct
    {
      Exp_n *test; //teste booleano
      Exp_n *body;
    } enquanto;

    struct
    {
      Var_n *var; //colocar na tabela de simbolos
      Exp_n *lo;  //cond ini
      Exp_n *hi;    //cond fin
      Exp_n *body;  //corpo
      int escape; //break
    } para;
    
    struct
    { 
        int quebrar; 
    }quebrar; //break;

    struct
    {
      Dec_n* decs; //o programa : declaraçoes
      Exp_n* body; //           : cor
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
        int tab[2]; //pos,escopo
    }normalVar;
    
    struct
    {
        int tab[2]; //pos,escopo
    }funcVar;
    
    struct
    {
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
        int simb[2]; //tupla(lina e escopo na tabela)
        Exp_n init;
        int escape;
    }varDec;
    
    struct
    {
        int simb[2]; //tupla(lina e escopo na tabela)
        Exp_n init;
        int escape;
    }funDec; //declaraçao fun
    
    struct
    {
        int simb[2]; //tupla(lina e escopo na tabela)
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

Exp_n* novo_call(int pos, Tipo_e tipo, char* idFun, Expseq* a, Tabela* t); //vale 

Exp_n* novo_ifthen(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Exp_n* novo_ifthenelse(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2, Exp_n* e3); //vale 

Exp_n* novo_while(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Exp_n* novo_for(int pos, Tipo_e tipo, char* idVar, Exp_n* e1, Exp_n* e2, Exp_n* e3, Tabela* t); //vale 

Exp_n* lvalue_to_exp(Tipo_e tipo, int** pos, Tabela* t);

Exp_n* novo_atribuicao(int pos, Tipo_e tipo, int* end, Exp_n* e, Tabela* t);

int* acessar_lvalue(int pos, Tipo_e tipo, Var_n* lv, char* idVar, Exp_n* e, Tabela* t);

VarList* novo_varlist(int pos, Tipo_e tipo, char* varId, char* tyId, VarList* tl, Tabela* t);

Tipo_n* novo_tipo(int pos, Tipo_e tipo );

Dec_n* novo_tipodec(int pos, Tipo_e tipo, char* tyId, Tipo_n* tn, Tabela* t); //igual struct de C

Dec_n* novo_vardec(int pos, Tipo_e tipo, char* varId, char* tyId, Exp_n* exp, Tabela* t); //simple var, record var, array var
Dec_n* novo_fundec(int pos, Tipo_e tipo, char* funId, VarList* tl, char* tyId, Exp_n* e, Tabela* t);

DecList* novo_declist(int pos, Tipo_e tipo, Dec_n* d, DecList* dl);

ExpSeq* novo_expseq(int pos, Tipo_e tipo, Exp_n* e, ExpSeq* es);

Exp_n* novo_const(int pos, Tipo_e tipo, int vi, char* vs);

Exp_n* novo_exp_op(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2); //vale 

Var_n* novo_var(int pos, Tipo_e tipo );

Exp_n* novo_let(int pos, Tipo_e tipo, DecList* dl, ExpSeq* es, Tabela* t); //; // FIXME colocar declist e explist

Dec_n* novo_dec(int pos, Tipo_e tipo, Dec_n* d); //nao precisa



#endif
