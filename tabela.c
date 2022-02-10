#include "tabela.h"

char tipo[][27] = {"", "int", "string", "nil", 
"var", "exp", "dec", "ty", 
"decList", "expList", "field", "fieldList", "fundec", "fundecList", "namety", "nametyList", "efield", "efieldList", 
"mais_op", "menos_op", "menos_un", "vezes_op", "dividr_op", "igual_op", "diff_op", "menorq_op", "menorig_op", "maiorq_op", "maiorig_op", "oper"};
    //printf("%d\n",t->linha->nivel);
    //printf("%d\n",);

Tabela* T_init()
{
    Tabela* t = malloc(sizeof(Tabela));
    t->linha = malloc(MAX * sizeof(Linha)); //alocar todas as linhas de uma vez
    t->escopo = malloc(MAX * sizeof(int)); //indice para vetor linha acima linha    
    t->linha->nivel = 0;
    t->escopo[0] = 0; //& da primeira linha
    t->nivel = 0;
    t->L = 0; //primeira linha em branco
    return t;
} 

void T_entrar_bloco(Tabela* t)
{
    t->nivel++;
    assert(t->nivel < MAX); //impor limite aos escopos também
    t->escopo[t->nivel] = t->L;
}

void T_sair_bloco(Tabela* t)
{
        
    T_imprimir(t);
    
    t->L = t->escopo[t->nivel];
    t->nivel--; //eliminar as linhas até chegar 
    assert(t->nivel >= 0);
}

int T_checar_existencia(Tabela* t, char* nome)
{
   int k = t->L;
    while(k > 0)
    {
        k--;
        if(0 == strcmp(t->linha[k].nome, nome))
            return k;
    }
    return -1;
}

void T_instalar(Tabela* t, char* nome, int tipo, char* valor)
{
    assert(t->L < MAX); //tabela cheia
    int k = t->L;
    while(k > t->escopo[t->nivel])
    {
        k--;
        if(0 == strcmp(t->linha[k].nome, nome)) 
        {
            assert(0); //nome duplicado
        }
    }
    //tudo certo, instalar
    t->linha[t->L].nome = malloc(NMAX * sizeof(char));
    strcpy(t->linha[t->L].nome, nome);
    t->linha[t->L].tipo = tipo;
    t->linha[t->L].valor = malloc(64 * sizeof(char));
    strcpy(t->linha[t->L].valor, valor);
    t->linha[t->L].nivel = t->nivel;
    t->L++;
}


void T_imprimir(Tabela* t)
{
    printf("Nome\tNivel\tTipo\tValor\n");
    for(int i = 0; i < t->L; i++)
    {
        printf("%s\t%d\t%s\t%s\n",t->linha[i].nome, t->linha[i].nivel, tipo[t->linha[i].tipo], t->linha[i].valor);  
    }
    
    for(int i = 0; i <= t->nivel; i++) printf("%d ",t->escopo[i]); 
    printf("\nNivel %d, L %d\n",t->nivel, t->L); 
}

void T_delete(Tabela* t)
{
    while(t->L > 0)
    {
        t->L--;
        free(t->linha[t->L].nome);
    }
    free(t->linha);
    free(t->escopo);
    free(t);
}




