#include <stdlib.h> //bibiloteca de alocação de espaço de memoria
#include <locale.h>//bibiloteca de alocação de texto por região 
#include <stdio.h>//bibiloteca de comunicação com o usuário
#include <string.h>//bibiloteca resposalvbel por cuidar das string

int registro()// função resposavel por cadastrar os usuários no sistema
{
	//inicio criação da variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
	//final criação da variáveis/string

    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
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
		printf("Não foi possivel  abrir o arquivo, não localizado!\n\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\n Essas são as informações do usuário:(CPF,nome,sobrenome,cargo):  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a  ser deletado: ");
    scanf("%s",cpf);
    	
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    	printf("O usuário não se encontra no sistema!. \n");
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

        printf("## Cartório da EBAC ##\n\n");//inico do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar os nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t0 - Sair\n\n"); //fim do menu

        scanf("%d", &opcao);//armazendo a escolha do usuario

        system("cls");// resposavel por limpar a tela

        switch (opcao)//inicio da seleção do menu
        {
        case 1:
            registro();//chamda de funçoes
            break;
        case 2:
            consulta();//chamda de funçoes
            break;
        case 3:
            deletar();//chamda de funçoes
            break;
        case 0:
            printf("Saindo do programa.\n");
            laco = 0;
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            system("pause");
            break;
        }
    }

    return 0;
}

