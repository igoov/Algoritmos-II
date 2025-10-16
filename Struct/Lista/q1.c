#include <stdio.h>
#include <string.h>

#define MAX_PERSONAGENS 10

typedef struct {
    char nome[50];
    float ataque;
    float defesa;
    float vida;
} Personagem;

int buscarPersonagem(Personagem personagens[], int total, char nomeBusca[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(personagens[i].nome, nomeBusca) == 0) {
            return i;
        }
    }
    return -1;
}

void exibirPersonagem(Personagem p) {
    printf("Nome: %s\n", p.nome);
    printf("Ataque: %.2f\n", p.ataque);
    printf("Defesa: %.2f\n", p.defesa);
    printf("Vida: %.2f\n", p.vida);
}

int cadastrarPersonagem(Personagem personagens[], int total) {
    if (total >= MAX_PERSONAGENS) {
        printf("Limite de personagens atingido.\n");
        return total;
    }
    printf("\n--- Cadastro de Personagem ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", personagens[total].nome);
    printf("Ataque: ");
    scanf("%f", &personagens[total].ataque);
    printf("Defesa: ");
    scanf("%f", &personagens[total].defesa);
    printf("Vida: ");
    scanf("%f", &personagens[total].vida);
    printf("Personagem cadastrado com sucesso!\n");
    exibirPersonagem(personagens[total]);
    return total + 1;
}

int removerPersonagem(Personagem personagens[], int total) {
    char nomeRemover[50];
    printf("\nDigite o nome do personagem a ser removido: ");
    scanf(" %[^\n]", nomeRemover);

    int pos = buscarPersonagem(personagens, total, nomeRemover);
    if (pos == -1) {
        printf("Personagem nao encontrado.\n");
        return total;
    }

    for (int i = pos; i < total - 1; i++) {
        personagens[i] = personagens[i + 1];
    }
    printf("Personagem removido com sucesso.\n");
    return total - 1;
}

void iniciarLuta(Personagem personagens[], int total) {
    if (total < 2) {
        printf("\nSao necessarios pelo menos 2 personagens para lutar.\n");
        return;
    }

    char nome1[50], nome2[50];
    printf("\n--- Iniciar Luta ---\n");
    printf("Digite o nome do primeiro personagem: ");
    scanf(" %[^\n]", nome1);
    printf("Digite o nome do segundo personagem: ");
    scanf(" %[^\n]", nome2);

    int pos1 = buscarPersonagem(personagens, total, nome1);
    int pos2 = buscarPersonagem(personagens, total, nome2);

    if (pos1 == -1 || pos2 == -1) {
        printf("Um ou ambos os personagens nao foram encontrados.\n");
        return;
    }

    Personagem p1 = personagens[pos1];
    Personagem p2 = personagens[pos2];
    int rodada = 1;

    while (p1.vida > 0 && p2.vida > 0) {
        printf("\n--- Rodada %d ---\n", rodada++);

        float dano_p1_causa = p1.ataque - p2.defesa;
        if (dano_p1_causa < 0) dano_p1_causa = 0;
        p2.vida -= dano_p1_causa;

        float dano_p2_causa = p2.ataque - p1.defesa;
        if (dano_p2_causa < 0) dano_p2_causa = 0;
        p1.vida -= dano_p2_causa;
        
        printf("Estado Atual:\n");
        printf("%s:\n", p1.nome);
        printf(" Vida: %.2f\n", p1.vida < 0 ? 0 : p1.vida);
        printf(" Dano sofrido: %.2f\n", dano_p2_causa);
        printf("%s:\n", p2.nome);
        printf(" Vida: %.2f\n", p2.vida < 0 ? 0 : p2.vida);
        printf(" Dano sofrido: %.2f\n", dano_p1_causa);
    }

    printf("\n--- Fim da Luta ---\n");
    if (p1.vida <= 0) {
        printf("Resultado: %s venceu a luta!\n", p2.nome);
    } else {
        printf("Resultado: %s venceu a luta!\n", p1.nome);
    }
}

int main() {
    Personagem personagens[MAX_PERSONAGENS];
    int totalPersonagens = 0;
    int opcao;
    char continuar;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar Personagem\n");
        printf("2. Remover Personagem\n");
        printf("3. Iniciar Luta\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                totalPersonagens = cadastrarPersonagem(personagens, totalPersonagens);
                break;
            case 2:
                totalPersonagens = removerPersonagem(personagens, totalPersonagens);
                break;
            case 3:
                iniciarLuta(personagens, totalPersonagens);
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
        
        printf("Deseja voltar ao menu inicial? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');
    
    printf("Encerrando o programa.\n");

    return 0;
}