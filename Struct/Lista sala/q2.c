#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    int DDD;
    int numero;
} Telefone;

typedef struct {
    char rua[100];
    int numero;
    char bairro[100];
    char cidade[100];
    char estado[50];
    char pais[50];
} Endereco;

typedef struct {
    int id;
    char nome[100];
    char email[100];
    Telefone telefone;
    Endereco endereco;
} Contato;

int inserirContato(Contato ctts[], int quantidade) {
    if (quantidade >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return quantidade;
    }

    Contato novo_contato;
    novo_contato.id = quantidade + 1;

    printf("\n--- Inserir Novo Contato (ID: %d) ---\n", novo_contato.id);
    printf("Nome: ");
    scanf(" %[^\n]", novo_contato.nome);
    printf("E-mail: ");
    scanf(" %[^\n]", novo_contato.email);

    do {
        printf("Telefone (DDD): ");
        scanf("%d", &novo_contato.telefone.DDD);
        if (novo_contato.telefone.DDD < 0) {
            printf("DDD invalido. Tente novamente.\n");
        }
    } while (novo_contato.telefone.DDD < 0);
    
    printf("Telefone (Numero): ");
    scanf("%d", &novo_contato.telefone.numero);

    printf("--- Endereco ---\n");
    printf("Rua: ");
    scanf(" %[^\n]", novo_contato.endereco.rua);
    printf("Numero: ");
    scanf("%d", &novo_contato.endereco.numero);
    printf("Bairro: ");
    scanf(" %[^\n]", novo_contato.endereco.bairro);
    printf("Cidade: ");
    scanf(" %[^\n]", novo_contato.endereco.cidade);
    printf("Estado: ");
    scanf(" %[^\n]", novo_contato.endereco.estado);
    printf("Pais: ");
    scanf(" %[^\n]", novo_contato.endereco.pais);

    ctts[quantidade] = novo_contato;
    printf("Contato inserido com sucesso!\n");
    return quantidade + 1;
}

int deletarContato(Contato ctts[], int quantidade, int id) {
    if (quantidade == 0) {
        printf("Nenhum contato para deletar.\n");
        return 0;
    }

    int pos_encontrada = -1;
    for (int i = 0; i < quantidade; i++) {
        if (ctts[i].id == id) {
            pos_encontrada = i;
            break;
        }
    }

    if (pos_encontrada == -1) {
        printf("Contato com ID %d nao encontrado.\n", id);
        return quantidade;
    }

    for (int i = pos_encontrada; i < quantidade - 1; i++) {
        ctts[i] = ctts[i + 1];
    }
    
    printf("Contato deletado com sucesso!\n");
    return quantidade - 1;
}

void listarContatos(Contato ctts[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhum contato cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("----------------------------\n");
        printf("ID: %d\n", ctts[i].id);
        printf("Nome: %s\n", ctts[i].nome);
        printf("E-mail: %s\n", ctts[i].email);
        printf("Telefone: (%d) %d\n", ctts[i].telefone.DDD, ctts[i].telefone.numero);
        printf("Endereco: %s, %d - %s, %s - %s, %s\n", ctts[i].endereco.rua, ctts[i].endereco.numero, ctts[i].endereco.bairro, ctts[i].endereco.cidade, ctts[i].endereco.estado, ctts[i].endereco.pais);
    }
    printf("----------------------------\n");
}


int main() {
    Contato contatos[MAX_CONTATOS];
    int quantidade_contatos = 0;
    int opcao, id_para_deletar;

    do {
        printf("\n--- Agenda Telefonica ---\n");
        printf("1. Inserir um novo contato\n");
        printf("2. Deletar um contato existente (por ID)\n");
        printf("3. Listar todos os contatos\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                quantidade_contatos = inserirContato(contatos, quantidade_contatos);
                break;
            case 2:
                printf("Digite o ID do contato a ser deletado: ");
                scanf("%d", &id_para_deletar);
                quantidade_contatos = deletarContato(contatos, quantidade_contatos, id_para_deletar);
                break;
            case 3:
                listarContatos(contatos, quantidade_contatos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}