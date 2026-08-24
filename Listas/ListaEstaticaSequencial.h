// Arquivo ListaEstáticaSequencial.h
#define MAX 100

struct aluno{
    int matricula;
    char nome[50];
    float n1, n2, n3; 
};

//Definição do tipo de Lista
struct lista{
    int quantidade;
    struct aluno dados[MAX];
};
typedef struct lista Lista;

Lista* cria_lista();

void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int insere_lista_inicio(Lista* li, struct aluno aluno);
int insere_lista_final(Lista* li, struct aluno aluno);
int insere_lista_ordenada(Lista* li, struct aluno aluno);