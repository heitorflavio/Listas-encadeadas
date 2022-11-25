#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>

typedef struct No {
    int valor;
    char nome;
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    int media;
    int exame;
    char status;
    struct No *prox;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;

void inicializa(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

void insere(Lista *lista,  char nome, int nota1, int nota2, int nota3, int nota4,int media,char status, int exame) {
    No *novo = (No*) malloc(sizeof(No));
    novo->nome = nome;
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->nota3 = nota3;
    novo->nota4 = nota4;
    novo->media = media;
    novo->exame = exame;
    novo->status = status;
    novo->prox = NULL;
    if (lista->inicio == NULL) {
        novo->valor = 1;
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->valor = lista->fim->valor + 1;
        lista->fim->prox = novo;
        lista->fim = novo;
    }

}

void imprime( Lista *lista) {
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("id: %d Nome: %c Nota1: %d Nota2: %d Nota3: %d Nota4: %d Media: %d Status %c  Exame: %d \n", aux->valor, aux->nome, aux->nota1, aux->nota2, aux->nota3, aux->nota4, aux->media, aux->status, aux->exame);
        printf("--------------------------------------- \n");
        aux = aux->prox;
    }
}

void pesquisa(Lista *lista, int valor) {
    No *aux = lista->inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            printf("--------------------------------------- \n");
            printf("id: %d Nome: %c Nota1: %d Nota2: %d Nota3: %d Nota4: %d Media: %d Status %c Exame: %d \n", aux->valor, aux->nome, aux->nota1, aux->nota2, aux->nota3, aux->nota4, aux->media, aux->status, aux->exame);
            printf("--------------------------------------- \n");
            return;
        }
        aux = aux->prox;
    }
    printf("Nao encontrado\n");
}

char aprovados(Lista *lista) {
    No *aux = lista->inicio;
    while (aux != NULL) {
        if (aux->media >= 7) {
            printf("--------------------------------------- \n");
            printf("id: %d Nome: %c Nota1: %d Nota2: %d Nota3: %d Nota4: %d Media: %d Status %c Exame: %d \n", aux->valor, aux->nome, aux->nota1, aux->nota2, aux->nota3, aux->nota4, aux->media, aux->status, aux->exame);
            printf("--------------------------------------- \n");

        }
        aux = aux->prox;
    }
    printf("Nao encontrado\n");
}

char reprovados(Lista *lista) {
    No *aux = lista->inicio;
    while (aux != NULL) {
        if (aux->media < 7) {
            printf("--------------------------------------- \n");
            printf("id: %d Nome: %c Nota1: %d Nota2: %d Nota3: %d Nota4: %d Media: %d Status %c Exame: %d \n", aux->valor, aux->nome, aux->nota1, aux->nota2, aux->nota3, aux->nota4, aux->media, aux->status, aux->exame);
            printf("--------------------------------------- \n");

        }
        aux = aux->prox;
    }
    printf("Nao encontrado\n");
}

char mediaGeralAprovados(Lista *lista) {
    No *aux = lista->inicio;
    int soma = 0;
    int cont = 0;
    while (aux != NULL) {
        if (aux->media >= 7) {
            soma = soma + aux->media;
            cont++;
        }
        aux = aux->prox;
    }
    printf("Media geral dos aprovados: %d \n", soma / cont);
}
char mediaGeralReprovados(Lista *lista) {
    No *aux = lista->inicio;
    int soma = 0;
    int cont = 0;
    while (aux != NULL) {
        if (aux->media < 7) {
            soma = soma + aux->media;
            cont++;
        }
        aux = aux->prox;
    }
    printf("Media geral dos aprovados: %d \n", soma / cont);
}


int main() {
    Lista lista;
    inicializa(&lista);
    int valor, nota1, nota2, nota3, nota4, opcao;
    int exame;
    float media,mediaold;
    char nome,status;

    do {
        printf("--------------------------------------- \n");
        printf("0 - Sair \n");
        printf("1 - Inserir aluno\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Pesquisar aluno\n");
        printf("4 - Listar alunos aprovados\n");
        printf("5 - Listar alunos reprovados\n");
        printf("6 - Media geral dos aprovados\n");
        printf("7 - Media geral dos reprovados\n");
        printf("--------------------------------------- \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o nome: ");
                scanf("%s", &nome);
                fflush(stdin);
                printf("Digite a nota 1: ");
                scanf("%d", &nota1);
                fflush(stdin);
                printf("Digite a nota 2: ");
                scanf("%d", &nota2);
                fflush(stdin);
                printf("Digite a nota 3: ");
                scanf("%d", &nota3);
                fflush(stdin);
                printf("Digite a nota 4: ");
                scanf("%d", &nota4);
                fflush(stdin);
                media = (nota1 + nota2 + nota3 + nota4) / 4;
                mediaold = media;

                printf("Media: %f \n", media);
                if(media >= 7) {
                    status = 'A';
                } else {
                    status = 'R';
                }
               if(media <  7 && media >= 4) {
                    printf("Digite a nota do exame: ");
                    scanf("%d", &exame);
                    media = (media + exame) / 2;
                    if(media >= 7) {
                        status = 'A';
                    } else {
                        status = 'R';
                        exame = media;
                    }
                }
                exame = mediaold;
                insere(&lista, nome, nota1, nota2, nota3, nota4,media,status,exame);

                break;
            case 2:
                imprime(&lista);
                break;
            case 3:
               printf("Digite o id do aluno: ");
                scanf("%d", &valor);
                pesquisa(&lista, valor);
                break;
            case 4:
                aprovados(&lista);
                break;
            case 5:
                reprovados(&lista);
                break;
            case 6:
                mediaGeralAprovados(&lista);
                break;
            case 7:
                mediaGeralReprovados(&lista);
                break;

            default:
                printf("Opcao invalida");
                break;
        }
    } while (opcao != 0);

    return 0;
}