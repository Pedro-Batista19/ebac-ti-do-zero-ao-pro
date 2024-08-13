#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void registro() {
    char arquivo[40];
    char CPF[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", CPF);

    strcpy(arquivo, CPF);

    FILE *file;
    file = fopen(arquivo, "w");
    if (file != NULL) {
        fprintf(file, "%s,", CPF);
        fclose(file);
    } else {
        printf("Erro ao criar arquivo!\n");
        return;
    }

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    if (file != NULL) {
        fprintf(file, "%s,", nome);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    if (file != NULL) {
        fprintf(file, "%s,", sobrenome);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    if (file != NULL) {
        fprintf(file, "%s", cargo);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("Registro salvo com sucesso!\n");
}

void consulta() {
    char CPF[40];
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", CPF);

    FILE *file;
    file = fopen(CPF, "r");
    if (file != NULL) {
        char conteudo[200];
        fgets(conteudo, sizeof(conteudo), file);
        printf("Dados cadastrados: %s\n", conteudo);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo! Verifique se o CPF está correto.\n");
    }
    
    system("pause");
}

void deletar() {
    char CPF[40];
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", CPF);

    if (remove(CPF) == 0) {
        printf("Registro deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar o registro! Verifique se o CPF está correto.\n");
    }
}

void teste() {
    printf("Funcionou a função Pedro!\n");
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    int laco = 1;

    while (laco == 1) {
        system("cls");

        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Teste\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                teste();
                break;
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        }
    }

    return 0;
}

