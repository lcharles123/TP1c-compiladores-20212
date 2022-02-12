#include "absyn.h"	
#include "erro.h"	
/* O tipo será determinado pela gramática, aqui vamos verificar de acordo com a posição no código */
/* valor é um apontador para int ou char* */

Exp_n* novo_expseqpar(int pos, Tipo_e tipo, ExpSeq* es)
{
    Exp_n* e = malloc(sizeof(Exp_n));
    e->tipoExp = tipo;
    e->espar = es;
    return NULL;
}

Exp_n* novo_call(int pos, Tipo_e tipo, char* idFun, ExpSeq* a, Tabela* t)
{ 
    Exp_n* e = malloc(sizeof(Exp_n));
    
    
    return e;
}  

Exp_n* novo_ifthen(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2) 
{ 
    Exp_n* se = malloc(sizeof(Exp_n));
    se->tipoExp = tipo;
    se->se.teste = e1;
    se->se.then = e2;
    se->se.cc = NULL;
    
    return se;
} 

Exp_n* novo_ifthenelse(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2, Exp_n* e3)
{ 
    Exp_n* sethen = malloc(sizeof(Exp_n));
    sethen->tipoExp = tipo;
    sethen->se.teste = e1;
    sethen->se.then = e2;
    sethen->se.cc = e3;
    
    return sethen;
} 

Exp_n* novo_while(int pos, Tipo_e tipo, Exp_n* e1, Exp_n* e2)
{ 
    Exp_n* enq = malloc(sizeof(Exp_n)); 
    enq->tipoExp = tipo;
    enq->enquanto.teste = e1;
    enq->enquanto.exp = e2;
    
    return enq;
}  

Exp_n* novo_for(int pos, Tipo_e tipo, char* idVar, Exp_n* e1, Exp_n* e2, Exp_n* e3, Tabela* t)
{ //assert(0);
    Exp_n* paraExp = malloc(sizeof(Exp_n));
    
    int simbPos = T_checar_existencia(t, idVar);
    if(simbPos != -1) assert(0); //erro id do for já foi declarado
    
    //Linha* lin = T_obter_linha(t, simbPos);
    //assert(0);
    
    paraExp->tipoExp = tipo;
    paraExp->para.varId = malloc(strlen(idVar)+1);
    strcpy(paraExp->para.varId, idVar);
    
    paraExp->para.ini = e1;
    paraExp->para.fin = e2;
    paraExp->para.exp = e3;
    paraExp->para.escape = 0;
     //assert(0);
    return paraExp;
} //vale 

Exp_n* lvalue_to_exp(Tipo_e tipo, Var_n* v, Tabela* t)
{ 
    return NULL;
}

Exp_n* novo_atribuicao(int pos, Tipo_e tipo, Var_n* v, Exp_n* e, Tabela* t)
{ 
    Exp_n* a = malloc(sizeof(Exp_n));
    a->tipoExp = tipo; 
    a->pos = pos;
    a->atribui.var = v;
    a->atribui.nome = v->nome;
    a->atribui.exp = e;
    //rv->atribui.varDec.nome = 
    
    return a;
}
    

Var_n* acessar_lvalue(int pos, Tipo_e tipo, Var_n* lv, char* idVar, Exp_n* e, Tabela* t)
{
    int posTab = T_checar_existencia(t, idVar);
    assert(-1 != posTab);//erro variavel nao declarada
    Linha* lin = T_obter_linha(t, posTab);
    Exp_n* attr = lin->atributo;
    assert(attr != NULL);
    
    Var_n* v = malloc(sizeof(Var_n));
    v->tipoVar = tipo;   //T_imprimir(t);
    v->nome = malloc(strlen(idVar)+1);
    strcpy(v->nome, idVar);
    
    
    switch(tipo)
    {
        case var_nome:
        {   
            v->normalVar.valor = attr;
            break; 
        }
        case var_interna:
        {
            v->funcVar.valor = e;
            break; 
        }
        case arranjovar_t:
        {
            v->arranjoVar.valor = e;
            break; 
        }
        default: assert(0);
    }
    return v;
}

DecList* novo_varlist(int pos, Tipo_e tipo, char* varId, char* tyId, DecList* tl, Tabela* t)
{ 
    return NULL;
}


Dec_n* novo_tipodec(int pos, Tipo_e tipo, char* tyId, DecList* dl, Tabela* t)
{ 
    return NULL;
} //igual struct de C





Dec_n* novo_fundec(int pos, Tipo_e tipo, char* funId, DecList* tl, char* tyId, Exp_n* e, Tabela* t)
{ 
    return NULL;
}

Dec_n* novo_vardec(int pos, Tipo_e tipo, char* varId, char* tyId, Exp_n* exp, Tabela* t)
{ 
    
    Dec_n* d = malloc(sizeof(Dec_n));
    d->pos = pos;
    d->tipoDec = tipo;
    if(-1 != T_checar_existencia(t, varId)) assert(0);//erro
    d->varDec.simb = T_instalar(t, varId, exp->tipoExp, exp);
    d->varDec.var = exp;
    d->varDec.nome = malloc(strlen(varId)+1);
    strcpy(d->varDec.nome, varId);
    return d;
}

DecList* novo_declist(int pos, Tipo_e tipo, Dec_n* d, DecList* dl)//let decs
{ 
    DecList* ndl = malloc(sizeof(DecList));
    ndl->elem = d;
    ndl->prox = dl;
    return ndl;
}

ExpSeq* novo_expseq(int pos, Tipo_e tipo, Exp_n* e, ExpSeq* es)//let in expseq
{    
    ExpSeq* exs = malloc(sizeof(ExpSeq));
    exs->elem = e;
    exs->prox = es;   
    return exs;
}

Exp_n* novo_let(int pos, Tipo_e tipo, DecList* dl, ExpSeq* es, Tabela* t) //ok
{
    T_entrar_bloco(t);
    Exp_n* e = malloc(sizeof(Exp_n));
    e->tipoExp = tipo; 
    e->pos = pos;
    e->let.declist = dl;
    e->let.expseq = es;
    
    return e;
}

Exp_n* novo_const(int pos, Tipo_e tipo, int vi, char* vs) //quebrar as funçoes para simplificar e nao ter params nulos
{
    
    Exp_n* ne = malloc(sizeof(Exp_n));
    ne->tipoExp = tipo; 
    ne->pos = pos;
    switch(tipo)
    {
        case int_t:
        {printf("const %d,",vi);
            ne->constante.int_v = vi;
            return ne;
        }
        case str_t:
        {printf("const %s,",vs);
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
    return ne;
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
            assert(e1 != NULL ||  e2 != NULL);
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


