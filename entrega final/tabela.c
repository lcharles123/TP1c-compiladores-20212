#include "tabela.h"
#include <unistd.h>


char tipo[][6] = {"nil", "int", "string"}; //usar [tipo - nil_t]
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

void T_entrar_bloco(Tabela* t) //conforme aula 17 min 30 ; slide comp-06
{
    t->nivel++;
    assert(t->nivel < MAX); //impor limite aos escopos também
    t->escopo[t->nivel] = t->L;
}

void T_sair_bloco(Tabela* t)
{
    return;
    //T_imprimir(t);
    
    t->L = t->escopo[t->nivel];
    t->nivel--; //eliminar as linhas até chegar 
    assert(t->nivel >= 0);
}

Linha* T_obter_linha(Tabela* t, int pos)
{
    return &t->linha[pos];
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

int* T_instalar(Tabela* t, char* nome, int tipo, Exp_n* atributo)
{
    assert(t->L < MAX && nome != NULL); //tabela cheia ou parametro invalido
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

    t->linha[t->L].atributo = malloc(sizeof(struct Exp_n));
    t->linha[t->L].atributo = atributo;
    
    t->linha[t->L].nivel = t->nivel;
    t->L++;
    int* pos = malloc(2*sizeof(int));
    pos[0] = t->L-1;
    pos[1] = t->nivel;
    
    return pos;
}

void T_imprimir(Tabela* t)
{
    printf("Nome\tNivel\tTipo\tValor\n");
    for(int i = 0; i < t->L; i++)
    {
        printf("%s\t%d\t%s\t",t->linha[i].nome, t->linha[i].nivel, tipo[t->linha[i].tipo - nil_t]);  
        if(t->linha[i].atributo==NULL) printf("%s\n", "nil");
        //t->linha[i].atributo->pos = 1; assert(0);
        else if(t->linha[i].atributo->tipoExp == int_t) printf("%d\n", t->linha[i].atributo->constante.int_v);
        else if(t->linha[i].atributo->tipoExp == str_t)  printf("%s\n", t->linha[i].atributo->constante.str_v);
        //else assert(0);
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

