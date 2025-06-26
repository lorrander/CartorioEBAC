#include <stdlib.h> //bibiloteca de aloca��o de espa�o de memoria
#include <locale.h>//bibiloteca de aloca��o de texto por regi�o 
#include <stdio.h>//bibiloteca de comunica��o com o usu�rio
#include <string.h>//bibiloteca resposalvbel por cuidar das string

int registro()// fun��o resposavel por cadastrar os usu�rios no sistema
{
	//inicio cria��o da vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	//final cria��o da vari�veis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
    scanf("%s", cpf);//%S refere-se a string

    strcpy(arquivo, cpf);//resposavel  por copiar os valores das strings

    FILE *file;//cria o arquivo 
    file = fopen(arquivo, "w");// cria o arquivo  e o "w" significa escrever 
    fprintf(file, "%s", cpf);//salvar  o valor da variavel
    fclose(file);//fecha arquivo

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

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    system("pause");
    return 0;
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//Defindo a linguagem
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF  a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file =fopen(cpf,"r");
    
    if(file==NULL)
	{
		printf("N�o foi possivel  abrir o arquivo, n�o localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio:(CPF,nome,sobrenome,cargo):  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a  ser deletado: ");
    scanf("%s",cpf);
    	
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!. \n");
    	system("pause");
	}
}

int main()
{
    int opcao;
    int laco = 1;

    setlocale(LC_ALL, "Portuguese");//Defindo a linguagem

    for (laco=1;laco=1;)
    {
        system("cls");

        printf("## Cart�rio da EBAC ##\n\n");//inico do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t0 - Sair\n\n"); //fim do menu

        scanf("%d", &opcao);//armazendo a escolha do usuario

        system("cls");// resposavel por limpar a tela

        switch (opcao)//inicio da sele��o do menu
        {
        case 1:
            registro();//chamda de fun�oes
            break;
        case 2:
            consulta();//chamda de fun�oes
            break;
        case 3:
            deletar();//chamda de fun�oes
            break;
        case 0:
            printf("Saindo do programa.\n");
            laco = 0;
            break;
        default:
            printf("Op��o inv�lida! Tente novamente.\n");
            system("pause");
            break;
        }
    }

    return 0;
}

