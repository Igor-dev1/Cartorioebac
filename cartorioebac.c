#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em memoria - entradas e saidas de fun��es
#include <locale.h> // Biblioteca de textos por regi�o
#include <string.h> // biblioteca que cuida das strings



int registrar() // fun��o int para registrar alunos e funcionarios da empresa
{
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o seu cpf: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // responsavel por copiar os valores da string, aqui estou dizendo que arquivo=cpf, ou seja dado pelo usuario(do cpf) ira ser atribuido ao arquivo
    
    FILE *file; // Chamei a fun��o FILE DA biblioteca e criei um arquivo file
    file = fopen(arquivo, "w"); // cria��o do file arquivo, aqui estou dando o comando para abertura e leitura da variavel arquivo( que tem o nome do cpf)  w=escreva um novo arquivo
    fprintf(file, "seu cpf � : %s", cpf); // gravando dentro do file(ou arquivo) a variavel cpf)
    fclose(file);
    
    
    printf("Digite o seu nome: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file,"\nseu nome �: %s", nome); // aqui eu decidi acrescentar no arquivo, uma informa��o anterior ao dado de entrada, para ficar visualmente bonito ao usuario
    fclose(file);
    
    
    printf("Digite o seu sobrenome: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file,"\nseu sobrenome �: %s", sobrenome); // aqui eu decidi acrescentar no arquivo, uma informa��o anterior ao dado de entrada, para ficar visualmente bonito ao usuario
    fclose(file);
    
    
    printf("Digite o seu cargo: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, "\nseu cargo �: %s\n\n", cargo); // aqui eu decidi acrescentar no arquivo, uma informa��o anterior ao dado de entrada, para ficar visualmente bonito ao usuario
    fclose(file);
    
      
      system("pause");
    
}

int consultar() // fun��o int para consultar os alunos e funcionarios registrados no programa
{
	char cpf[40];
	char arquivo[200];
	
	printf("consulte o cpf a ser buscado: ");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
     {
		printf("N�o foi possivel encontrar o usuario\n\n");
		system("pause");
		system("cls");
		return 0;
	
	 }
     
    printf("Seus dados s�o o seguinte:\n\n");
		
	while(fgets(arquivo, 200, file)!= NULL) //
	{
		
		printf("%s", arquivo);
	
	}
	
	system("pause");
	
	return 0;
	
}
int deletar() // fun��o para deletar e registrar os alunos e funcionarios da empresa
{   
    char cpf[40];  
    printf("Escolha o usu�rio que deseja deletar: ");
    scanf("%s", cpf); // vou armazenar o input do usuario dentro da string, (tipo da varivel, nome da variavel) 
      
    system("cls");
    
    FILE *file;
    file = fopen(cpf, "r"); // abra o arquivo e "r" = leia
	
	if(file == NULL) // primeiro precisamos verificar se o arquivo existe, se remover antes n�o conseguira dizer se existe ou n�o o cadastro
	{
		printf("Este usuario n�o est� cadastrado no nosso banco de dados\n\n");
		system("pause");
	}	
       
    else // aqui consigo usar o if else dentro para dizer se foi removido com sucesso ou ocurreu algum erro ou bug na hora de deletar o arquivo ou dados
	{
		fclose(file); // preciso fechar o arquivo antes de da o comando pra remove-lo
		
	if(remove(cpf) == 0) //aqui posso usar o comando remove(cpf) dentro de uma valida��o
	{
		printf("Usuario foi deletado com sucesso\n\n");
		system("pause");
		    
    }
	else
		{
		printf("Erro ao deletar o us�ario\n\n");
		system("pause");
		}
	}
}


int main()
{
   int opcao=0; //definindo a variavel
   int x=1; // outra reserva de espa�o na memoria para a variavel relacionada a repeti��o
   char senhalogin[10]="0";
   int senha;
   
   
   setlocale(LC_ALL, "Portuguese");
   printf("### Cart�rio EBAC ###\n\n");
   while(1)
   {
   	

   printf("Login do administrador!\n\nDigite a sua senha: ");
   scanf("%s", senhalogin);
   system("cls");
   
   
   senha=strcmp(senhalogin, "admin"); // esse comando "strcmp" compara duas fun��es, nesse caso a "senhalogin" que recebera a entrada do usuario, e o valor "admin"(ou string admin)
                                         
   
   if(senha == 0) //usei senha como uma variavel que foi igualada ao comando strcmp(senhalogin, "admin"), se caso esse comando ou compara��o for 0, a senha sera 0 tamb�m, e condinado um comando a esse resultado
   {
  
     for(x=1; x==1;) // condicional de la�o, para o ciclo se repetir e o programa principal main n�o acabar, mas retornar ao menu principal apos o termino
      {
   	  
	    system("cls");
	  	  
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
   
        printf("### Cart�rio EBAC ###\n\n"); //inicio do menu
   
        printf("Escolha a op��o desejada do menu:\n\n"); 
   
        printf("\t1- Registrar nomes\n");
        printf("\t2- Consultar nomes\n");
        printf("\t3- Deletar nomes\n"); 
        printf("\t4- Sair do sistema\n\n");
        printf(" Escolha a op��o que deseja:");
   
        scanf("%d", &opcao); //armezenando o input do usuario ou escolha do usuario
   
        system("cls"); // dando uma limpada no visual(tela) ap�s finalizar a escolha do usuario
          
        switch(opcao) // condicional onde me da a oportunidade de montar casos e chamar fun��es, aqui seria o MENU
        {
          	case 1:
      	    registrar(); // chamada de fun��o
      	    break;
   	    
   	        case 2:
          	consultar(); // chamada de fun��o
   	        break;
   	    
   	        case 3:
        	deletar(); // chamada de fun��o
   	        break;
   	        
   	        case 4:
   	        printf("Obrigado por utilizar o sistema");
   	        return 0;
   	        break;
   	    
   	        default:
            printf("Op��o n�o disponivel\n\n");
   	        system("pause");
   	        break;
	 	}    	 // fim da sele��o  
      }   
    }
    
    else
	{
    
        printf("\nSenha incorreta\n\n");
        system("pause");
        system("cls");
        
	}
	}

	
	
	
}



 //printf("Este software � desenvolvido para o programa de estudos EBAC");//
