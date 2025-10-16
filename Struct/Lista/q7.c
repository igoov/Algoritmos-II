#include <stdio.h>

typedef struct {
    int matricula;
    char texto[100];
} Aluno;

typedef struct {
    char disciplina[20];
    char texto[100];
} Professor;

typedef struct {
    float codigoAuth;
    char texto[100];
} Administrador;

typedef union {
    Aluno aluno;
    Professor professor;
    Administrador admin;
} Mensagem;

typedef struct {
    int tipo; // 1: Aluno, 2: Professor, 3: Administrador
    Mensagem msg;
} Envelope;

void lerMensagem(Envelope* env) {
    printf("Tipo (1=Aluno, 2=Professor, 3=Administrador): ");
    scanf("%d", &env->tipo);

    switch (env->tipo) {
        case 1:
            printf("Matricula do aluno: ");
            scanf("%d", &env->msg.aluno.matricula);
            printf("Mensagem: ");
            scanf(" %[^\n]", env->msg.aluno.texto);
            break;
        case 2:
            printf("Disciplina do professor: ");
            scanf(" %[^\n]", env->msg.professor.disciplina);
            printf("Mensagem: ");
            scanf(" %[^\n]", env->msg.professor.texto);
            break;
        case 3:
            printf("Codigo de autenticacao: ");
            scanf("%f", &env->msg.admin.codigoAuth);
            printf("Mensagem: ");
            scanf(" %[^\n]", env->msg.admin.texto);
            break;
        default:
            printf("Tipo invalido.\n");
            env->tipo = 0;
            break;
    }
}

void exibirMensagem(Envelope env, int num) {
    printf("Mensagem %d: ", num);
    switch (env.tipo) {
        case 1:
            printf("Aluno (Matricula %d) enviou: %s\n", env.msg.aluno.matricula, env.msg.aluno.texto);
            break;
        case 2:
            printf("Professor (Disciplina %s) enviou: %s\n", env.msg.professor.disciplina, env.msg.professor.texto);
            break;
        case 3:
            printf("Administrador (Codigo %.2f) enviou: %s\n", env.msg.admin.codigoAuth, env.msg.admin.texto);
            break;
    }
}

int main() {
    Envelope mensagens[3];

    for (int i = 0; i < 3; i++) {
        printf("\nMensagem %d\n", i + 1);
        lerMensagem(&mensagens[i]);
    }

    printf("\n--- Mensagens Decodificadas ---\n");
    for (int i = 0; i < 3; i++) {
        if(mensagens[i].tipo != 0){
             exibirMensagem(mensagens[i], i + 1);
        }
    }

    return 0;
}