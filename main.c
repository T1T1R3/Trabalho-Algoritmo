#include "sellerSystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int opc;
    int opc2;
    int qtd = 0;
    int qtdParcial = 0;
    Vendedor temp;
    Vendedor *vetorVendedor = 0;

    do {
        system("cls||clear");
        printf("1- Cadastrar novos vendedores");
        printf("\n2- Mostrar dados dos vendedores cadastrados");
        printf("\n3- Calcular comissões");
        printf("\n4- Mostrar dados de um vendedor específico");

        printf("\n\n0- Sair");
        printf("\n\nInsira a opção desejada:\n");
        scanf("%d", &opc);

        if (opc == 1) {
            qtd = qtdParcial;
            system("cls || clear");
            printf("Insira a quantidade de vendedores: ");
            scanf("%d", &qtd);

            if (vetorVendedor == 0) {
                vetorVendedor = malloc(qtd * sizeof(int));
            } else {
                vetorVendedor = realloc(vetorVendedor, qtdParcial + (qtd * sizeof(int)));
            }
            for (int i = qtdParcial; i < qtd + qtdParcial; i++) {
                system("cls || clear");
                cadastraVendedor(&vetorVendedor[i]);
            }
            for (int i = 1; i < qtd; i++) {
                for (int j = 0; j < qtd - 1; j++) {
                    if (strcmp(vetorVendedor[j].nome, vetorVendedor[j + 1].nome) > 0) {
                        temp = vetorVendedor[j];
                        vetorVendedor[j] = vetorVendedor[j + 1];
                        vetorVendedor[j + 1] = temp;
                    }
                }
            }
            qtdParcial += qtd;
        }
        if (opc == 2) {
            system("cls || clear");
            for (int i = 0; i < qtdParcial; i++) {
                printVendedor(&vetorVendedor[i]);
                printf("\n\n");
            }
            printf("\n\nPressione qualquer número para voltar\n");
            scanf("%d", &opc2);
        }

        if (opc == 3) {
            system("cls || clear");
            for (int i = 0; i < qtdParcial; i++) {
                printf("%s", vetorVendedor[i].nome);
                calculoComissao(vetorVendedor[i].totalVendido);
            }
            printf("\n\nPressione qualquer número para voltar\n");
            scanf("%d", &opc2);
        }

        if (opc == 4) {
            system("cls || clear");
            char cpfDigitado[12];
            int retrn;
            printf("Insira o CPF do vendedor: ");
            scanf("%s", cpfDigitado);

            for (int i = 0; i < qtd; i++) {
                retrn = strcmp(vetorVendedor[i].cpf, cpfDigitado);
                if (retrn == 0) {
                    printf("Vendedor encontrado\n\n");
                    printVendedor(&vetorVendedor[i]);
                    break;
                }
            }
            if (retrn != 0) {
                printf("Vendedor não encontrado");
            }
            printf("\n\nPressione qualquer tecla para voltar\n");
            scanf("%d", &opc2);
        }

    } while (opc != 0);

    free(vetorVendedor);
    system("cls||clear");
    printf("Programa encerrado");

    return 0;
}