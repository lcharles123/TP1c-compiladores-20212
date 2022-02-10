#ifndef PRI_H
#define PRI_H

#include <stdio.h>
#include <assert.h>
#include "absyn.h" //para o enum principal

static char oper[][12] = { "+", "-", "*", "/", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};

void imprimir(Exp_n* e)
{
    assert(e);
    switch(e->tipoExp)
    {
        case int_t:
        {
            printf("int(%d)", e->constante.int_v); break;
        }
        case str_t:
        {
            printf("str(%s)", e->constante.str_v); break;
        }
        case mais_op: //operadores, checar os tipos tem que ser ambos int, e1 e e2 serão usados
        case menos_op: // tipo é o nome da operação, apenas propagar ele
        case vezes_op: 
        case dividir_op: 
        case igual_op: 
        case diferente_op: 
        case menor_op: 
        case maior_op: 
        case menorig_op: 
        case maiorig_op: 
        case e_op: 
        case ou_op: 
        {
            printf(" OPER( '%s' , ", oper[ mais_op % e->tipoExp]);
            imprimir(e->oper.opEsq);
            printf(" , "); 
            imprimir(e->oper.opDir);
            printf(" ) ");
            break;
        }
        case neg_t:
        {
            printf(" OPER( '-' , nil , ");
            imprimir(e->oper.opDir);
            printf(" ) "); break;
        }
        case lvalue_t: //variavel ou funcao
        {
            
            break;   
        }
        
        case expseq_t: //varias exp entre parenteses
        {
         
            break;   
        }
        case atribui_t: //atribuiçao
        {
         
            break;   
        }
        case if_t: //bloco if then
        {
         
            break;   
        }
        case ifthen_t: //bloco if then else
        {
         
            break;   
        }
        case while_t: //bloco while
        {
         
            break;   
        }
        case for_t: //bloco for
        {
         
            break;   
        }
        case break_t: 
        {
         
            break;   
        }
        case let_t: // de escopo e declaraçoes seguindo expressoes
        {
        
            break;
        }
        
        default: assert(0);//erro exp tipo
    }
    
    
    //ver como imprimir
    //printf("%s\n", stringDeErro);
    //exit(EXIT_FAILURE);
}


#endif