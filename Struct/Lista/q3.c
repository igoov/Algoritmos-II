#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char tipo[50];
    char endereco[200];
    float preco;
    int quartos;
    float area;
    char status[20];
} Imovel;

void cadastrarImovel(Imovel imoveis[], int index) {
    imoveis[index].id = index + 1;
    printf("\n--- Cadastro de Imovel ID %d ---\n", imoveis[index].id);
    printf("Digite o tipo do imovel (casa/apartamento): ");
    scanf(" %[^\n]", imoveis[index].tipo);
    printf("Digite o endereco: ");
    scanf(" %[^\n]", imoveis[index].endereco);
    printf("Digite o preco: ");
    scanf("%f", &imoveis[index].preco);
    printf("Digite o numero de quartos: ");
    scanf("%d", &imoveis[index].quartos);
    printf("Digite a area (m2): ");
    scanf("%f", &imoveis[index].area);
    printf("Digite o status (disponivel/vendido/alugado): ");
    scanf(" %[^\n]", imoveis[index].status);
    printf("Imovel cadastrado com sucesso!\n");
}

void listarImoveis(Imovel imoveis[], int total) {
    if (total == 0) {
        printf("\nNenhum imovel cadastrado.\n");
        return;
    }
    printf("\n--- Lista de Imoveis ---\n");
    for (int i = 0; i < total; i++) {
        printf("------------------------\n");
        printf("ID: %d\n", imoveis[i].id);
        printf("Tipo: %s\n", imoveis[i].tipo);
        printf("Endereco: %s\n", imoveis[i].endereco);
        printf("Preco: R$%.2f\n", imoveis[i].preco);
        printf("Quartos: %d\n", imoveis[i].quartos);
        printf("Area: %.2f m2\n", imoveis[i].area);
        printf("Status: %s\n", imoveis[i].status);
    }
}

void buscarPorStatus(Imovel imoveis[], int total) {
    char statusBusca[20];
    int encontrou = 0;
    printf("\nDigite o status para buscar (disponivel/vendido/alugado): ");
    scanf(" %[^\n]", statusBusca);

    printf("\n--- Imoveis com status '%s' ---\n", statusBusca);
    for (int i = 0; i < total; i++) {
        if (strcmp(imoveis[i].status, statusBusca) == 0) {
            printf("------------------------\n");
            printf("ID: %d\n", imoveis[i].id);
            printf("Tipo: %s\n", imoveis[i].tipo);
            printf("Endereco: %s\n", imoveis[i].endereco);
            printf("Preco: R$%.2f\n", imoveis[i].preco);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum imovel encontrado com este status.\n");
    }
}

int main() {
    int n;
    printf("Quantos imoveis podem ser cadastrados? ");
    scanf("%d", &n);

    Imovel imoveis[n];
    int totalCadastrados = 0;
    int opcao;

    do {
        printf("\nSistema de Gerenciamento Imobiliario\n");
        printf("1. Cadastrar imovel\n");
        printf("2. Listar todos os imoveis\n");
        printf("3. Buscar imoveis por status\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalCadastrados < n) {
                    cadastrarImovel(imoveis, totalCadastrados);
                    totalCadastrados++;
                } else {
                    printf("Limite de cadastro de imoveis atingido.\n");
                }
                break;
            case 2:
                listarImoveis(imoveis, totalCadastrados);
                break;
            case 3:
                buscarPorStatus(imoveis, totalCadastrados);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}