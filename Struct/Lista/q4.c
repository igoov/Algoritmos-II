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

typedef struct {
    int id;
    char nome[100];
    char email[100];
    char telefone[20];
    int imovel_id;
} Cliente;

// Funcoes da Questao 3 (cadastrarImovel, listarImoveis, buscarPorStatus)
// sao reutilizadas aqui. Para brevidade, elas nao serao reescritas.
// Imagine que elas estao aqui.

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
        printf("Status: %s\n", imoveis[i].status);
    }
}

void cadastrarCliente(Cliente clientes[], int index) {
    clientes[index].id = index + 1;
    printf("\n--- Cadastro de Cliente ID %d ---\n", clientes[index].id);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", clientes[index].nome);
    printf("Digite o e-mail: ");
    scanf(" %[^\n]", clientes[index].email);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", clientes[index].telefone);
    clientes[index].imovel_id = 0; // Nenhum imovel associado inicialmente
    printf("Cliente cadastrado com sucesso! ID: %d\n", clientes[index].id);
}

void listarClientes(Cliente clientes[], int total) {
    if (total == 0) {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }
    printf("\n--- Lista de Clientes ---\n");
    for (int i = 0; i < total; i++) {
        printf("------------------------\n");
        printf("ID: %d\n", clientes[i].id);
        printf("Nome: %s\n", clientes[i].nome);
        printf("E-mail: %s\n", clientes[i].email);
        printf("Telefone: %s\n", clientes[i].telefone);
        if (clientes[i].imovel_id != 0) {
            printf("Imovel associado (ID): %d\n", clientes[i].imovel_id);
        }
    }
}

void comprarImovel(Imovel imoveis[], int totalImoveis, Cliente clientes[], int totalClientes) {
    int idCliente, idImovel;
    printf("\nDigite o ID do cliente: ");
    scanf("%d", &idCliente);
    printf("Digite o ID do imovel: ");
    scanf("%d", &idImovel);

    if (idCliente <= 0 || idCliente > totalClientes || idImovel <= 0 || idImovel > totalImoveis) {
        printf("ID de cliente ou imovel invalido.\n");
        return;
    }

    if (strcmp(imoveis[idImovel - 1].status, "disponivel") == 0) {
        strcpy(imoveis[idImovel - 1].status, "vendido");
        clientes[idCliente - 1].imovel_id = idImovel;
        printf("Imovel comprado com sucesso! Status atualizado para \"vendido\".\n");
    } else {
        printf("Este imovel nao esta disponivel para compra.\n");
    }
}

void listarImoveisVendidos(Imovel imoveis[], int totalImoveis, Cliente clientes[], int totalClientes){
    printf("\n--- Imoveis Vendidos ---\n");
    int encontrou = 0;
    for(int i = 0; i < totalImoveis; i++){
        if(strcmp(imoveis[i].status, "vendido") == 0){
            printf("------------------------\n");
            printf("ID Imovel: %d\n", imoveis[i].id);
            printf("Tipo: %s\n", imoveis[i].tipo);
            printf("Endereco: %s\n", imoveis[i].endereco);
            printf("Preco: R$%.2f\n", imoveis[i].preco);
            for(int j = 0; j < totalClientes; j++){
                if(clientes[j].imovel_id == imoveis[i].id){
                    printf("Cliente: %s\n", clientes[j].nome);
                    break;
                }
            }
            encontrou = 1;
        }
    }
    if(!encontrou){
        printf("Nenhum imovel vendido encontrado.\n");
    }
}


int main() {
    int n;
    printf("Quantos imoveis/clientes podem ser cadastrados? ");
    scanf("%d", &n);

    Imovel imoveis[n];
    Cliente clientes[n];
    int totalImoveis = 0;
    int totalClientes = 0;
    int opcao;

    do {
        printf("\nSistema de Gerenciamento Imobiliario e Clientes\n");
        printf("1. Cadastrar imovel\n");
        printf("2. Listar todos os imoveis\n");
        printf("3. Cadastrar cliente\n");
        printf("4. Listar todos os clientes\n");
        printf("5. Comprar imovel\n");
        printf("6. Listar imoveis vendidos com cliente\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalImoveis < n) cadastrarImovel(imoveis, totalImoveis++);
                else printf("Limite de imoveis atingido.\n");
                break;
            case 2:
                listarImoveis(imoveis, totalImoveis);
                break;
            case 3:
                if (totalClientes < n) cadastrarCliente(clientes, totalClientes++);
                else printf("Limite de clientes atingido.\n");
                break;
            case 4:
                listarClientes(clientes, totalClientes);
                break;
            case 5:
                comprarImovel(imoveis, totalImoveis, clientes, totalClientes);
                break;
            case 6:
                listarImoveisVendidos(imoveis, totalImoveis, clientes, totalClientes);
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