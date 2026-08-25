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
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int mat);
int consulta_lista_posicao(Lista* li, int posicao, struct aluno *aluno);
int consulta_lista_matricula(Lista* li, int matricula, struct aluno *aluno); //função para fazer uma consulta por conteúdo da posição (nesse caso pela matrícula)
void imprime_lista(Lista* li);