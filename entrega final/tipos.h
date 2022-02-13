#ifndef T_H
#define T_H

/** O Exp_n ficará nesse arquivo 
*   pois é compartilhado recursivamente nos módulos tabela.h e absyn.h, assim evitamos conflitos 
*/

typedef struct Exp_n Exp_n;  //Apenas essa classe está definida neste header

typedef struct ExpSeq ExpSeq; //Prototipos para serem incluídos em absyn.h
typedef struct Var_n Var_n;
typedef struct Dec_n Dec_n;
typedef struct DecList DecList;
typedef struct Tipo_n Tipo_n;
typedef struct VarList VarList;

typedef enum //usar esse enum para diferenciar entre os diversos tipos
{
    nulo=0,
    exp_t,
    lvalue_t, //exp
    expseq_t,
    neg_t, //op de negaçao
    
    nil_t,
    int_t,
    str_t,
    
    call_t,
    op_t,
    
    record_t, //tid 10
    atribui_t,
    ifthen_t,
    if_t,
    while_t,
    for_t,
    break_t,
    let_t,
    
    mais_op, menos_op, //operadores exp  18
    vezes_op, dividir_op, 
    igual_op, diferente_op, 
    menor_op, maior_op, 
    menorig_op, maiorig_op, 
    e_op, ou_op,
    
    ty_nome, //nomes de tipos 30
    ty_record,
    ty_arranjo,
    
    normalvar_t, //tipo de variavel 33
    funcvar_t,
    arranjovar_t, 
    
    var_nome, //nome do lvalue_t 36
    var_interna,//variavel interna do
    
    args_t,
    ideps_t,
    
    fundec_t, //decs 40
    vardec_t,
    tydec_t
} Tipo_e;

typedef struct Exp_n //estrutura para os tipos derivados do nao terminal exp
{
    int pos; //posiçao no código
    Tipo_e tipoExp;
    
    struct
    {
        int nil;
        int int_v;
        char *str_v;
    } constante;
    
    ExpSeq* espar;   
    
    struct
    {
      int idTab;       //endereço na tabela
      ExpSeq *args;   //args eh um vetor do tipo Exp
      
    } call;           //chamada proc

    struct oper
    {
        Exp_n* opEsq;
        Exp_n* opDir;
    } oper;

    struct
    {
      Tipo_n* tipo;   //vetor de tipos
      Exp_n* ExpSeq;
    } record;

    struct
    {
      Var_n *var;     //variavel
      char* nome;
      Exp_n *exp;    //exp lado dir
    } atribui;

    struct
    {
      Exp_n *teste;//test booleano
      Exp_n *then; //corpo
      Exp_n *cc;   // caso contrario
    } se;

    struct
    {
      Exp_n *teste; //teste booleano
      Exp_n *exp;
    } enquanto;

    struct
    {
      char* varId;  //nome da var
      int* simb;
      
      Exp_n *ini;  //cond ini
      Exp_n *fin;  //cond fin
      Exp_n *exp;  //corpo
      int escape;  //break
    } para;
    
    struct
    { 
        int quebrar; 
    }quebrar; //break;

    struct
    {
      DecList* declist; // decs 
      ExpSeq* expseq;   // expseq
    } let;

    struct
    {
      Tipo_n *typ; 
      int tamanho;
      Exp_n *init;
    } arranjo;
}Exp_n;

#endif
