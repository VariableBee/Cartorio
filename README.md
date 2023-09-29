# **Sobre**

Esse foi meu primeiro projeto em C.
Um sistema de cadastro e consulta com base em nome, sobrenome, cargo e cpf.

## **Bibliotecas**
```c
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca para alocar espaços na memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings
```

## **Como funciona?**
Ao executar este progrma, o usuário primeiro deve inserir suas credenciais de administrador¹, e então, verá o seguinte menu:

Escolha a opção desejada do menu:

1 - Registrar nomes

2 - Consultar nomes

3 - Deletar nomes

4 - Sair do sistema

Opção: SUA ESCOLHA

### **PS¹: A senha é "a"**
Você pode alterar isso dentro da função **int main()**

linha 134 do programa > char senhaDigitada[10] = "INSIRA SUA SENHA";

Ao escolher uma ação do menu o programa vai executar as seguintes linhas de código,
chamando assim as funções listadas abaixo, dentro da função principal do programa.
Ao final de cada ação, registrar por exemplo, o usuário pode voltar ao menu principal e fazer uma nova ação, como consultar um pessoa já cadastrada com base em cargo, cpf, nome, sobrenome.

```c
// Início da seleção do menu
switch (opcao) {
    case 1:
        registrar(); // Chamada de funções
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
        printf("Essa opção não está disponível!\n");
        system("pause");
        break;
} // Fim da seleção
```
## **Funções**
- **registrar()** //função responsavel por cadastrar os usuários no sistema
- **consultar()** //função responsavel por consultar os usuários no sistema
- **deletar()**   //função responsavel por deletar os usuários do sistema
- 
```c
int registrar() //função responsavel por cadastrar os usuários no sistema 
{	
	//variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf);  //%s salva informações de strings em variáveis 
	strcpy(arquivo, cpf); //copia o valor de uma string em outra
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //"w" escreve no arquivo que está sendo criado e acessado
	fprintf(file, cpf); //salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	 
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo que está sendo acessado
	fprintf(file, ", ");  //passando uma vírgula para separar informações do usuário
	fclose(file); //fecha o arquivo
	
	printf("Digite um nome a ser cadastrado: "); //cadastrando nome do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite um sobrenome a ser cadastrado: "); //cadastrando sobrenome do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //cadastrando cargo do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);	
} //fim da função "cadastrar"

int consultar()  //função responsavel por consultar os usuários no sistema
{	
	//definindo idioma
	setlocale(LC_ALL, "Portuguese"); 
	
	//variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim das variáveis/strings
	
	printf("Digite o CPF a ser consultado: "); //consultando o usuário por CPF
	scanf("%s", cpf); //%s salva informações de strings em variáveis 
	
	FILE *file; //criando/acessando o arquivo
	file = fopen(cpf, "r"); //"r" para "ler" o arquivo que está sendo acessado
	
	
	if(file == NULL) //validando CPF
	{
		printf("Não foi possível abrir o arquivo. Arquivo não localizado ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //Pega todas os dados do usuário com base em seu CPF
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause"); //pausa no sistema para o usuário verificar seus dados
	
} //fim da função "consultar"

int deletar()  //função responsavel por deletar os usuários do sistema
{	
	//variáveis/strings
	char cpf[40];
	//fim das variáveis/strings
	
	//consultando usuário por CPF
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	system("cls"); //limpa a tela
	
	//acessando o arquivo para "ler" o CPF
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	//se o CPF for inexistente: O usuário não se encontra no sistema!
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	else
	{
	remove(cpf);
	printf("\nUsuário deletado com sucesso\n\n");
	system("pause");
	}
```

