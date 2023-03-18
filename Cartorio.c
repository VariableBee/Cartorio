#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca para alocar espa�os na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

//definindo fun��es:

int registrar() //fun��o responsavel por cadastrar os usu�rios no sistema 
{	
	//vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf);  //%s salva informa��es de strings em vari�veis 
	strcpy(arquivo, cpf); //copia o valor de uma string em outra
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //"w" escreve no arquivo que est� sendo criado e acessado
	fprintf(file, cpf); //salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	 
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo que est� sendo acessado
	fprintf(file, ", ");  //passando uma v�rgula para separar informa��es do usu�rio
	fclose(file); //fecha o arquivo
	
	printf("Digite um nome a ser cadastrado: "); //cadastrando nome do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite um sobrenome a ser cadastrado: "); //cadastrando sobrenome do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //cadastrando cargo do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);	
} //fim da fun��o "cadastrar"

int consultar()  //fun��o responsavel por consultar os usu�rios no sistema
{	
	//definindo idioma
	setlocale(LC_ALL, "Portuguese"); 
	
	//vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: "); //consultando o usu�rio por CPF
	scanf("%s", cpf); //%s salva informa��es de strings em vari�veis 
	
	FILE *file; //criando/acessando o arquivo
	file = fopen(cpf, "r"); //"r" para "ler" o arquivo que est� sendo acessado
	
	
	if(file == NULL) //validando CPF
	{
		printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Pega todas os dados do usu�rio com base em seu CPF
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause"); //pausa no sistema para o usu�rio verificar seus dados
	
} //fim da fun��o "consultar"

int deletar()  //fun��o responsavel por deletar os usu�rios do sistema
{	
	//vari�veis/strings
	char cpf[40];
	//fim das vari�veis/strings
	
	//consultando usu�rio por CPF
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	system("cls"); //limpa a tela
	
	//acessando o arquivo para "ler" o CPF
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	//se o CPF for inexistente: O usu�rio n�o se encontra no sistema!
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	else
	{
	remove(cpf);
	printf("\nUsu�rio deletado com sucesso\n\n");
	system("pause");
	}
	
} //fim da fun��o "deletar"

int main()  //fun��o principal do programa
	{ 
	//definindo vari�veis
	int opcao = 0; 
	int laco = 1;
	//fim das vari�veis
	
	//loop do programa
	for(laco=1;laco=1;) 
	{	
		
		system("cls"); //limpa a tela
		setlocale(LC_ALL, "Portuguese"); //definindo idioma
		
		//in�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema \n\n"); 
		printf("Op��o: ");
		//fim do menu
		
		
		scanf("%d",&opcao); //armazena a escolha do usu�rio
		system("cls"); //limpa a tela
		
		//in�cio da sele��o do menu
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema\n");
				return 0;
				break;
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		}  //fim da sele��o
	}
}
