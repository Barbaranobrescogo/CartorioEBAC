#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //biblioteca respónsavel por cuidar das string

int registro() //criamos as ariaveis que a gente precisava, Função responsavel por cadastrar os usuarios no sistema 
{
	//inicio da criação de variaveis ou strings (conj)
	char arquivo[40]; //conchetes é criação de string, o nome muda, novo user
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado:  "); //criamos o cpf, coletando info do usuario
	scanf("%s", cpf);// salva na variavel %s refere a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string, puxa do cpf pro arquivo
	
	FILE *file; //cria arquivo , chama uma função pronta pelo  sistema
	file = fopen(arquivo,"w"); // no banco de dados - composição w é escrever
	fprintf(file,cpf);          //salva (fprint) no arquivo (valor da variavel)
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //a de atualização para incluir
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a"); // a de atualização
	fprintf(file, nome);          
	fclose(file);
	
	file = fopen(arquivo, "a"); // virgula na main
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");          
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo); 
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //salvamos na varoavel, string conjunto das variaveis
	
	FILE *file;
	file = fopen(cpf, "r");  //acessa aquele arquivo, consulta ele, os, ler, cpf r de read
	
	if(file == NULL)	
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //gets é buscar. laço de repetição, enquanto, salvar até acabar. (ele salva o conteudo de 200 carc dentro do arquivo, quando n achar é nulo e sai da função
	{
		printf("\nEssas são as informações do usuário: "); //após armazenar ele trará as informações para a gente
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	}
	
	

	
	
}
int main()//menu
    {
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	 system("cls");//responsavel por lmpar a tela
	
	 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	 printf("### Cartório da EBAC ###\n\n");//inicio do menu
	 printf ("Escolha a opção desejada do menu:\n\n");
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Consultar nomes\n");
	 printf("\t3 - Deletar nomes\n\n"); 
	 printf("\t4 - Sair do sistema\n\n");
	 printf("Opção:");//fim do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuario
	
	 system("cls");
	 
	 switch(opcao)//inicio da seleção do menu
	 {
	 	 case 1:
	 	 registro();//chamada de funções
		 break;
		 
		 case 2: 
		 consulta();
		 break;
		 
		 case 3:
		 deletar();
 	     system("pause");
		 break;	
		 
		 case 4:
		 printf("Obrigado por utilizar o sistema!\n");
		 return 0;
		 break;
		 
	 	 default:
	 	 printf("Essa opção não está disponivel!\\n");
		 system("pause");
		 break; //fim da seleação
	 	
	 }
	
	 	
      

     }
}

