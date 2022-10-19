#include <stdio.h>

typedef struct {
    char nome[60];
    char dataDeNascimento[10];
    char cpf[12];
    float salarioBase;
    float totalVendido;
} Vendedor;

void cadastraVendedor(Vendedor *v1) {
    printf("Insira o nome do vendedor:\n");
    scanf("%s", v1->nome);

    printf("Insira o CPF:\n");
    scanf("%s", v1->cpf);

    printf("Insira a data de nascimento (DDMMAA):\n");
    scanf("%s", v1->dataDeNascimento);

    printf("Insira o salario base:\nR$");
    scanf("%f", &v1->salarioBase);

    printf("Insira o total vendido:\nR$");
    scanf("%f", &v1->totalVendido);
}

void printVendedor(Vendedor *v1) {
    printf("\nNome do vendedor: %s", v1->nome);
    printf("\nCPF do vendedor: %s", v1->cpf);
    printf("\nData de nascimento do vendedor: %s", v1->dataDeNascimento);
    printf("\nSalario base: R$%.2f", v1->salarioBase);
    printf("\nTotal vendido: R$%.2f", v1->totalVendido);
}

int quantVendedor() {
    int qnt;
    printf("Insira a quantidade de vendedores a ser cadastrada:\n");
    scanf("%d", &qnt);
    return qnt;
}

void calculoComissao(float valorVendido) {
    printf(" Comissão: R$%.2f\n", valorVendido * 0.03);
}

void tamanhoVetor(Vendedor *v, int size){
    for(int i = 0; i < size; i++){
        printf("\nTamanho %d", i);
    }
}

