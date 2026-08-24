#include <stdio.h>
#include <stdlib.h>
#include "ListaEstaticaSequencial.h"

int main(){

    Lista* li = cria_lista();

    int x = tamanho_lista(li);

    libera_lista(li);
    system("pause");
    return 0;
}