#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file, "%s", cpf);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    system("pause");
    return 0;
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
        system("pause");
        return 1;
    }

    while (fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
    {
        printf("Usu�rio deletado com sucesso.\n");
    }
    else
    {
        printf("O usu�rio n�o se encontra no sistema!.\n");
    }

    system("pause");
    return 0;
}

int main()
{
    int opcao = 0;
    int laco = 1;
    int comparacao;
    char senhadigitada[10] = "a";

    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    comparacao = strcmp(senhadigitada, "admin");

    if (comparacao == 0)
    {
        while (laco)
        {
            system("cls");

            setlocale(LC_ALL, "Portuguese");

            printf("### Cart�rio da EBAC ###\n\n");
            printf("Escolha a op��o desejada do menu\n\n");
            printf("\t1 - Registrar nomes\n\n");
            printf("\t2 - Consultar nomes\n\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - Sair do sistema\n\n");
            printf("op��o: ");

            scanf("%d", &opcao);

            system("cls");

            switch (opcao)
            {
            case 1:
                printf("Voc� escolheu registrar nomes\n");
                registro();
                break;

            case 2:
                printf("Voc� escolheu consultar nomes\n");
                consulta();
                break;

            case 3:
                printf("Voc� escolheu deletar nomes\n");
                deletar();
                break;
                
            case 4:
            	printf("obrigado por utilizar o sistema!\n");
            	return 0;
            	break;

            default:
                printf("Essa op��o n�o est� dispon�vel\n");
                system("pause");
                break;
            }
        }
    }
    else
    {
        printf("Senha incorreta!\n");
        system("pause");
    }

    return 0;
}

