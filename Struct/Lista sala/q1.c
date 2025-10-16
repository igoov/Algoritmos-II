#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    int codigo;
    int disponivel; // 1 para disponivel, 0 para emprestado
} Livro;

int buscarPosicaoPorCodigo(Livro livros[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }
    return -1; // Nao encontrado
}

void CadastrarLivros(Livro livros[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastro do Livro %d ---\n", i + 1);
        int codigo_temp;
        int codigo_existe;

        do {
            printf("Digite o codigo do livro: ");
            scanf("%d", &codigo_temp);
            codigo_existe = buscarPosicaoPorCodigo(livros, i, codigo_temp);
            if (codigo_existe != -1) {
                printf("Erro: Codigo ja cadastrado. Tente novamente.\n");
            }
        } while (codigo_existe != -1);

        livros[i].codigo = codigo_temp;

        printf("Digite o titulo do livro: ");
        scanf(" %[^\n]", livros[i].titulo);
        livros[i].disponivel = 1; // Todo livro comeca como disponivel
    }
    printf("\nCadastro de %d livros concluido.\n", n);
}

void ConsultarLivro(Livro livros[], int n) {
    int codigo_busca;
    printf("\nDigite o codigo do livro que deseja consultar: ");
    scanf("%d", &codigo_busca);

    int pos = buscarPosicaoPorCodigo(livros, n, codigo_busca);

    if (pos != -1) {
        printf("\n--- Informacoes do Livro ---\n");
        printf("Titulo: %s\n", livros[pos].titulo);
        printf("Codigo: %d\n", livros[pos].codigo);
        printf("Status: %s\n", livros[pos].disponivel ? "Disponivel" : "Emprestado");
    } else {
        printf("Livro com o codigo %d nao encontrado.\n", codigo_busca);
    }
}

void EmprestarLivro(Livro livros[], int n) {
    int codigo_emprestimo;
    printf("\nDigite o codigo do livro que deseja emprestar: ");
    scanf("%d", &codigo_emprestimo);

    int pos = buscarPosicaoPorCodigo(livros, n, codigo_emprestimo);

    if (pos != -1) {
        if (livros[pos].disponivel == 1) {
            livros[pos].disponivel = 0;
            printf("Livro '%s' emprestado com sucesso.\n", livros[pos].titulo);
        } else {
            printf("O livro '%s' ja esta emprestado.\n", livros[pos].titulo);
        }
    } else {
        printf("Livro com o codigo %d nao encontrado.\n", codigo_emprestimo);
    }
}

int main() {
    int n;
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numero invalido.\n");
        return 1;
    }

    Livro estante[n];

    CadastrarLivros(estante, n);
    ConsultarLivro(estante, n);
    EmprestarLivro(estante, n);
    ConsultarLivro(estante, n); // Consultando novamente para ver a mudanca de status

    return 0;
}