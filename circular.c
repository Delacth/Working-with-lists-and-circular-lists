#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"header1.h"
#include <locale.h>
#include <unistd.h>


//* Desafio 1 

typedef struct l {
    char v;
    struct l *prox;
    struct l *ant;
} lista;

//* FUNÇÃO DA ALINEA A
lista *inicializarlista() {
    return NULL;
}

//* FUNÇÃO DA ALINEA B
lista *insereinicio(lista *l, char letra) {
    lista *novo = (lista *)malloc(sizeof(lista));
    if (novo) {
        novo->v = letra;
        novo->prox = l;
        novo->ant = NULL;
        if (l != NULL) {
            l->ant = novo;
        }
        return novo;
    } else {
        printf("Erro :(\n");
        return l;
    }
}

//* FUNÇÃO DA ALINEA C
lista *removeno(lista *l, char letra) {
    lista *aux = l;
    while (aux != NULL && aux->v != letra) {
        aux = aux->prox;
    }
    if (aux != NULL) {
        if (aux->ant != NULL) {
            aux->ant->prox = aux->prox;
        } else {
            l = aux->prox;
        }
        if (aux->prox != NULL) {
            aux->prox->ant = aux->ant;
        }
        free(aux);
    }
    return l;
}

//* FUNÇÃO DA ALINEA D
void imprime(lista *l) {
    lista *aux = l;
    while (aux != NULL) {
        printf("%c ", aux->v);
        aux = aux->prox;
    }
    printf("\n");
}

//* FUNÇÃO DA ALINEA E
void procuraelemento(lista *l, char letra) {
    lista *aux = l;
    while (aux != NULL && aux->v != letra) {
        aux = aux->prox;
    }
    if (aux != NULL && aux->v == letra) {
        printf("Elemento encontrado: %c\n", aux->v);
    } else {
        printf("Elemento não encontrado\n");
    }
}

//* FUNÇÃO DA ALINEA F
 //FUNÇÃO DA ALINEA F
void verificarpali(lista *l) {
    int i, n = 0;
    
    lista *inicio = l;
    lista *fim = l;

    //* Contar o número de elementos na lista
    while (fim->prox != NULL) {
        fim = fim->prox;
        n++;
    }

    //* Comparar os elementos para verificar se é um palíndromo
    for (i = 0; i < n / 2; i++) {
        if (inicio->v != fim->v) {
            printf("Não é palíndromo\n");
            return;
        }
        inicio = inicio->prox;
        fim = fim->ant;
    }

    printf("É palíndromo\n");
}
  	 
//* FUNÇÃO DA ALINEA F
void removerlista(lista *l) {
    lista *aux = l;
    while (aux != NULL) {
        lista *temp = aux;
        aux = aux->prox;
        free(temp);
    }
}







//* Desafio 2 

struct slotmachine
{
     //* data */
    int value;
    struct slotmachine *  prox;
   
};

SM * criaslot(){
    return NULL;
}

SM * insereslot(SM * cl, int valueSort){
     SM *slot = (SM *)malloc(sizeof(SM));
    if (slot)
    {
        slot->value = valueSort;
        if (cl == NULL)
        {
            slot->prox = slot;
        }
        else
        {
            slot->prox = cl;
            SM *aux = cl;
            while (aux->prox != cl)
            {
                aux = aux->prox;
            }
            aux->prox = slot;
        }
    }
    else
    {
        printf("Erro de Alocação");
    }
    return slot;
}

void gameOn(SM *cl)
{   
    setlocale(LC_ALL, "Portuguese");
   
    int gamerA[3], gamerB[3];
    int countA = 0;
    int countB = 0;
    srand(time(NULL));
    SM *auxA = cl; //* Ponteiro adicional para o início da lista do Gamer A
    SM *auxB = cl; //* Ponteiro adicional para o início da lista do Gamer B

    printf("\n Gamer A \n");
    //* Gera três números aleatórios para o Gamer A
    for (int indexCicle = 0; indexCicle < 3; indexCicle++)
    {
        int randomNumber = rand() % 9 + 1; //* Gera números de 1 a 10
        gamerA[indexCicle] = randomNumber;

        while (auxA->prox->value != randomNumber)
        {
            auxA = auxA->prox;
        }

        printf(" %d ", gamerA[indexCicle]);

        auxA = cl->prox; //* Reinicializa auxA para o início da lista do Gamer A
    }
    printf("\n\n Gamer B \n");
    if (gamerA[0] == gamerA[1] && gamerA[1] == gamerA[2])
    {
        printf("\n\nGamer A é o Vencedor. JACKPOT\n\n");
    }
    else
    {
        auxB = cl; //* Reinicializa auxB para o início da lista do Gamer B

        //* Gera três números aleatórios para o Gamer B
        for (int indexCicle = 0; indexCicle < 3; indexCicle++)
        {
            int randomNumber = rand() % 9 + 1; //* Gera números de 1 a 10
            gamerB[indexCicle] = randomNumber;

            while (auxB->prox->value != randomNumber)
            {
                auxB = auxB->prox;
            }

            printf(" %d ", gamerB[indexCicle]);

            auxB = cl->prox; //* Reinicializa auxB para o início da lista do Gamer B
        }

        if (gamerB[0] == gamerB[1] && gamerB[1] == gamerB[2])
        {
            printf("\n\nGamer B é o Vencedor. JACKPOT\n\n");
        }
        else
        {
            //* Verifica se há pelo menos dois números iguais em gamerA
            if (gamerA[0] == gamerA[1] || gamerA[1] == gamerA[2] || gamerA[0] == gamerA[2])
            {
                countA = 2;
            }

            //* Verifica se há pelo menos dois números iguais em gamerB
            if (gamerB[0] == gamerB[1] || gamerB[1] == gamerB[2] || gamerB[0] == gamerB[2])
            {
                countB = 2;
            }

            //* Verifica quem foi o Vencedor por Acumulação de Ponto
            if (countA == countB)
            {
                printf("\n\n Houve um empate\n\n");
            }
            else
            {
                if (countA > countB)
                {
                    printf("\n\nGamer A é o Vencedor com mais Pontos.\n\n");
                }
                else
                {
                    printf("\n\n Gamer B é o Vencedor com mais Pontos.\n\n");
                }
            }
        }
    }
}


void gameOver(SM * cl){
     free(cl->prox);
    free(cl);
}

void menuPrincipal(){
    setlocale(LC_ALL, "Portuguese");
    int answer = 0;

    printf("-------------- Seja Bem-vinda Professora Sílvia --------------");
    printf("\n");
    printf("                  -- Menu Principal --                         ");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("[1]- Implementação das TAD Listas Duplamente Ligadas Simples \n");
    printf("[2] Desafio do Slot Machine\n");
    printf("[3] Sair\n\n");

    printf("R: ");
    scanf("%i", &answer);
     SM *loading =NULL;
     lista *minhaLista = NULL;
 

    switch (answer)
    {
    case 1:
     minhaLista = inicializarlista();

    char log1;
    int number = 0;
    system("cls");
    printf("\n\nDigite o número de caracteres que serão alocados na lista: ");
    scanf("%i", &number);

    //* Limpar o buffer do teclado
    while ((getchar()) != '\n');

    for (int count = 0; count < number; count++) {
        char log;
        printf("Digite a letra: ");
        scanf(" %c", &log);  

        minhaLista = insereinicio(minhaLista, log);
    }
    printf("\n\n");        

   

    //* Teste da função imprime
    printf("Lista após inserção no início:\n");
    imprime(minhaLista);

    printf("\n\n");

    //* Teste da função removeno
    printf("Qual é a letra que deseja remover: ");
    char remove;
    scanf(" %c", &remove); 

    minhaLista = removeno(minhaLista, remove);

    //* Teste da função imprime após remoção
    printf("\n\nLista após remoção de %c:\n",remove);
    imprime(minhaLista);

    //* Teste da função procuraelemento

     //* Limpar o buffer do teclado
    while ((getchar()) != '\n');
    
    printf("\n\nProcurando letra:\n");
    scanf("%c", &log1);
    procuraelemento(minhaLista, log1);

     //* Limpar o buffer do teclado
    while ((getchar()) != '\n');
    
    //* Teste da função verificarpali
    printf("\n\nVerificando se a lista é palíndroma :\n");
    verificarpali(minhaLista);

    //* Teste da função removerlista
    removerlista(minhaLista);
    minhaLista = NULL;

       printf("Deseja continuar no programa? [1-Sim]/[2-Não] \n R: ");

        int change =0;
        scanf("%i", &change);

        if(change == 1){
            system("cls");
            menuPrincipal();
        }else{
            if(change == 2){
                system("cls");
                printf("\n\n Ok, muito obrigada Sra Professora \n\n");
            }else{
                printf("%i não é válido nessa operação \n .... \n retornando ao Menu Principal... \n\n", change);
                sleep(5); //* Atraso de 5 segundos
                system("cls");
                menuPrincipal();

            }
        }


    
        break;
    case 2: 
        loading= criaslot();
   
        //* Adiciona números de 1 a 10 à lista
        for (int count = 1; count < 10; count++) {
            loading = insereslot(loading, count);
        }
        system("cls");
        printf("\n\n Início do Jogo!\n");
        //* Joga o jogo
        gameOn(loading);

        //* Libera a memória alocada
        gameOver(loading); 

        printf("Deseja continuar no programa? [1-Sim]/[2-Não] \n R: ");

        int change1 =0;
        scanf("%i", &change1);

        if(change1 == 1){
            system("cls");
            menuPrincipal();
        }else{
            if(change1 == 2){
                system("cls");
                printf("\n\n Ok, muito obrigada Sra Professora \n\n");
            }else{
                printf("%i não é válido nessa operação \n .... \n retornando ao Menu Principal... \n\n", change1);
                sleep(5); //* Atraso de 5 segundos
                system("cls");
                menuPrincipal();

            }
        }
        
        break;
    case 3:
         system("cls");
         printf("\n\n Ok, muito obrigada Sra Professora \n\n");
        break;

    default:
        printf("\n\nNúmero não corresponde a nenhuma opção válida");
        break;
    }

}

