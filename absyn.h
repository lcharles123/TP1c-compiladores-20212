#ifndef ABS_H
#define ABS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Exp Exp_n; //Exp_nó é uma estrutura que será um nó na árvore

typedef struct Var var_n;
typedef struct Dec dec_n;
typedef struct Tipo tipo_n;
typedef struct Const const_n;

struct Exp //estrutura para os tipos derivados do nao terminal exp
{
    int pos; //posiçao no código
    
    enum 
    {
      var_t,
      nil_t,
      int_t,
      str_t,
      call_t,
      op_t,
      record_t,
      seq_t,
      assign_t,
      if_t,
      while_t,
      for_t,
      break_t,
      let_t,
      array_t
    } tipo;
    
    Var *var;
    int nil;
    int intt;
    char *str;

    struct
    {
      char* id;
      Exp *args; //args eh um vetor do tipo Exp
    } call;

    struct
    {
        enum { mais, menos, vezes, dividir, igual, diferente, menor, maior, menorig, maiorig, e, ou } op;
      
      Exp* op_esq;
      Exp* op_dir;
    } oper;

    struct
    {
      sym_symbol        *typ;
      absyn_efield_list *fields;
    } record;

    absyn_exp_list *seq;

    struct
    {
      absyn_var *var;
      absyn_exp *exp;
    } assign;

    struct
    {
      absyn_exp *test;
      absyn_exp *then;
      absyn_exp *elsee;
    } iff;

    struct
    {
      absyn_exp *test;
      absyn_exp *body;
    } whilee;

    struct
    {
      sym_symbol *var;
      absyn_exp  *lo;
      absyn_exp  *hi;
      absyn_exp  *body;
      bool              escape;
    } forr;
    /* breakk; - need only pos */
    struct
    {
      absyn_dec_list *decs;
      absyn_exp      *body;
    } let;

    struct
    {
      sym_symbol *typ;
      absyn_exp  *size;
      absyn_exp  *init;
    } array;

  
};






#endif
