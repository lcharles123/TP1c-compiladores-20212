#include "imprimir.h"


static char oper[][12] = { "+", "-", "*", "/", "==", "!=", "<", ">", "<=", ">=", "&&", "||"};

void imprimir_declist(DecList* d) //decs do let
{
    if(d != NULL) 
    {
        //puts("imprimiu dec");
        imprimir_dec(d->elem);
        imprimir_declist(d->prox);
    }  
}

void imprimir_expseq(ExpSeq* es) //exps do let
{
    //puts("imprimiu expseq");
    if(es != NULL)
    {
        imprimir_exp(es->elem);
        printf(" ; "); 
        imprimir_expseq(es->prox);
    }  
}

void imprimir_exp(Exp_n* e)
{
    //printf("impressa_exp\n");
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
        case menos_op:
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
            printf(" OPER( '%s' , ", oper[e->tipoExp - mais_op]);
            imprimir_exp(e->oper.opEsq);
            printf(" , "); 
            imprimir_exp(e->oper.opDir);
            printf(" ) ");
            break;
        }
        case neg_t:
        {
            printf(" OPER( '-' , nil , ");
            imprimir_exp(e->oper.opDir);
            printf(" ) "); 
            break;
        }
        case lvalue_t:
        {
            puts("lvalue");
            break;   
        }
        
        case expseq_t:
        {
            
            puts("(expseq)");
            break;   
        }
        case atribui_t: //atribuiçao
        {
            printf("Atribui( %s , ", e->atribui.var->nome);
            imprimir_exp(e->atribui.var->normalVar.valor);
            printf(" ) ");
            break;   
        }
        case if_t: //bloco if then
        {
            printf(" IF( ");
            imprimir_exp(e->se.teste);
            printf(" , ");
            imprimir_exp(e->se.then);
            printf(" ) ");
            break;   
        }
        case ifthen_t: //bloco if then else
        {
            //puts("ife ");
            printf(" IF( ");
            imprimir_exp(e->se.teste);
            printf(" , ");
            imprimir_exp(e->se.then);
            printf(" , ");
            imprimir_exp(e->se.cc);
            printf(" ) ");
            break;   
        }
        case while_t: //bloco while
        {
            printf(" WHILE( ");
            imprimir_exp(e->enquanto.teste);
            printf(" , ");
            imprimir_exp(e->enquanto.exp);
            printf(" ) ");
            break;   
        }
        case for_t: //bloco for
        {
            //puts("for ");
            printf(" FOR( %s , ", e->para.varId);
            imprimir_exp(e->para.ini);
            printf(" , ");
            imprimir_exp(e->para.fin);
            printf(" , ( ");
            imprimir_exp(e->para.exp);
            printf(" ) ");
            break;   
        }
        case break_t: 
        {
            puts("bk");
            break;   
        }
        case let_t: //eh uma lista, desempacotar ela
        {       

            printf("LET ( ");
            if(e->let.declist != NULL) { imprimir_declist(e->let.declist); }
            printf(" ) IN ( ");
            if(e->let.expseq != NULL) { imprimir_expseq(e->let.expseq); }
            printf(" ) END\n"); 
            break;
        }
        
        default://erro exp tipo
        { 
            printf("Tipo = %d ", e->tipoExp); 
            int ErroTipo = 0; 
            assert(ErroTipo); 
        }
    }
}

void imprimir_dec(Dec_n* d)
{
    switch(d->tipoDec)
    {
        case fundec_t:
        {
            printf(" FunDec ("); break;
        }
        case vardec_t:
        {
            printf(" VarDec (");
            printf(" %s , ", d->varDec.nome); 
            imprimir_exp(d->varDec.var);
            printf(" ) ");
            break;
        }
        case tydec_t: 
        {
            printf("TyDec ("); break;
        }
        default: printf("default %d ", d->tipoDec);
    }
}

