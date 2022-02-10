#include "absyn.h"	
#include "erro.h"	
/* O tipo será determinado pela gramática, aqui vamos verificar de acordo com a posição no código */
/* valor é um apontador para int ou char* */


Exp_n* novo_call(int pos, Tipo_e tipo, char* idFun, Expseq* a, Tabela* t){ return NULL;} //vale 

Exp_n* novo_ifthen(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2) { return NULL;}//vale 

Exp_n* novo_ifthenelse(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2, Exp_n* e3){ return NULL;} //vale 

Exp_n* novo_while(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2){ return NULL;} //vale 

Exp_n* novo_for(int pos, Tipo_e tipo, char* idVar, Exp_n* e1, Exp_n* e2, Exp_n* e3, Tabela* t){ return NULL;} //vale 

Exp_n* lvalue_to_exp(Tipo_e tipo, int** pos, Tabela* t){ return NULL;}

Exp_n* novo_atribuicao(int pos, Tipo_e tipo, int* end, Exp_n* e, Tabela* t){ return NULL;}

int* acessar_lvalue(int pos, Tipo_e tipo, Var_n* lv, char* idVar, Exp_n* e, Tabela* t){ return NULL;}

VarList* novo_varlist(int pos, Tipo_e tipo, char* varId, char* tyId, VarList* tl, Tabela* t){ return NULL;}

Tipo_n* novo_tipo(int pos, Tipo_e tipo ){ return NULL;}

Dec_n* novo_tipodec(int pos, Tipo_e tipo, char* tyId, Tipo_n* tn, Tabela* t){ return NULL;} //igual struct de C









Dec_n* novo_fundec(int pos, Tipo_e tipo, char* funId, TipoList* tl, char* tyId, Exp_n* e, Tabela* t){ return NULL;}

Dec_n* novo_vardec(int pos, Tipo_e tipo, char* varId, char* tyId, Exp_n* exp, Tabela* t){ return NULL;}

DecList* novo_declist(int pos, Tipo_e tipo, Dec_n* d, DecList* dl){ return NULL;}

ExpSeq* novo_expseq(int pos, Tipo_e tipo, Exp_n* e, ExpSeq* es)
{    
    ExpSeq*  ess = malloc(sizeof(ExpSeq));
    //es->tipoExp = tipo; 
    //es->pos = pos;
    
    return ess;}

Exp_n* novo_let(int pos, Tipo_e tipo, DecList* dl, ExpSeq* es, Tabela* t) //
{
    Exp_n* ne = malloc(sizeof(Exp_n));
    ne->tipoExp = tipo; 
    ne->pos = pos;
    
    return ne;
}

Exp_n* novo_const(int pos, Tipo_e tipo, int vi, char* vs) //quebrar as funçoes para simplificar e nao ter params nulos
{
    Exp_n* ne = malloc(sizeof(Exp_n));
    ne->tipoExp = tipo; 
    ne->pos = pos;
    switch(tipo)
    {
        case int_t:
        {
            //printf("foi i = %d\n",(int)v); assert(0); 
            ne->constante.int_v = vi;
            return ne;
        }
        case str_t:
        {
            ne->constante.str_v = vs;
            return ne;
        }
        case nil_t: 
        {
            ne->constante.nil = 1;
            return ne;   
        }
        default:
        {
            char buff[64];
            sprintf(buff, "\n*** Posição:%d erro: Constante desconhecida ***\n", pos);
            erro(buff);
        }
    }
    return NULL;
}

Exp_n* novo_exp_op(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2)
{
           //nova exp
    Exp_n* ne = malloc(sizeof(Exp_n));//há vazamento de memória caso erro na compilaçao, mas economiza escrita
    ne->tipoExp = tipo; //atribuir de uma vez em toda chamada, já que será atribuido em todo caso
    ne->pos = pos;
    //assert(0); 
    switch(tipo)
    {
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
            if(e1->tipoExp == int_t && e2->tipoExp == int_t) //verificar se ambos sao tipo int
            { 
                ne->oper.opEsq = e1;
                ne->oper.opDir = e2;
            }
            else
            {
                char buff[128];
                sprintf(buff, "\n*** Posição:%d erro: Operações lógicas e aritiméticas devem ser apenas entre tipo int ***\n", pos);
                erro(buff); //erro a oper b
            }
            return ne;   


        }
        case lvalue_t: //variavel ou funcao
        {
            
            break;   
        }
        
        case expseq_t: //varias exp entre parenteses
        {
         
            break;   
        }
        case neg_t: //negaçao unaria 
        {
            if(e1->tipoExp == int_t) //verificar se é int
            { 
                ne->tipoExp = neg_t;
                
                ne->oper.opEsq = NULL;
                ne->oper.opDir = e1; //valor da const pra negaçao
            }
            else
            {
                char buff[128];
                sprintf(buff, "\n*** Posição:%d erro: Operação negação unária devem ser apenas entre tipo int ***\n", pos);
                erro(buff); //erro a oper b
            }
            return ne;   
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
    
    return ne;
}

Var_n* novo_var(int pos, Tipo_e tipo )
{
   /* Var_n* nv = malloc(sizeof(Var_n));//há vazamento de memória caso erro na compilaçao, mas economiza escrita
    nv->tipoVar = tipo; //atribuir de uma vez em toda chamada, já que será atribuido em todo caso
    
    switch(var)
    {
        case : 
        {
         
            return ;   
        }
        
        default: assert(0);//erro var
    }*/return NULL;
}

Dec_n* novo_dec(int pos, Tipo_e tipo, Dec_n* d)
{
  /*  Dec_n* nd = malloc(sizeof(Dec_n));//há vazamento de memória caso erro na compilaçao, mas economiza escrita
    nd->tipoDec = tipo; //atribuir de uma vez em toda chamada, já que será atribuido em todo caso
    
    switch(var)
    {
        case : 
        {
         
            return ;   
        }
        
        default: assert(0);//erro var
    }*/
    return d;
}

Tipo_n* novo_tipo(int pos, Tipo_e tipo )
{ 
   /* Tipo_n* nt = malloc(sizeof(Tipo_n));//há vazamento de memória caso erro na compilaçao, mas economiza escrita
    nt->tipoTipo = tipo; //atribuir de uma vez em toda chamada, já que será atribuido em todo caso
  
    switch(tipo)
    {
        case : 
        {
         
            return ;   
        }
        
        default: assert(0);//erro var
    }*/ return NULL;
} 


