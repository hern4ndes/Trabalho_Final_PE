#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}tdata;

typedef struct {
	char cpf[12];
	char nome[100];
	tdata dt_adm;
	tdata dt_nasc;
	int cargo;
	int dept;
}tFuncionario;

//***FUNǃO MENU***
int menu(){
	int resp;
	printf("\n\t\t MENU\n\n1. Cadastrar funcion%crio\n2. Demitir funcion%crio\n3. Transferir funcion%crio de departamento\n", 160, 160, 160);
	printf("\n\t\tTESTE \n\n4. Listar geral (Fun%c%co para Testes)\n5. Listar por departamento (Fun%c%co para Testes)\n6.",135, 198, 135, 198);
	printf("Listar por cargo (Fun%c%co para Testes)\n\n0. Sair\n",135,198);
	printf("Digite uma op%c%co do menu: ", 135, 198);
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;

}
/*
//***FUNǃO PESQUISAR E TRANSFERIR***
int pesquisar (char cpf, int cont){
	int i, novoDept;
	for (i=0;i<cont;i++){
		if (strcmp(cpf, cpf2)==0){
			printf ("Para qual departamento voc%c deseja transferir?", 136);
			scanf ("%d", &novoDept);
		}
	}
}
*/
//***FUNǃO CADASTRAR FUNCIONRIO***
int cadastarFuncionario(tFuncionario func[150], int cont){
	int i; i=cont;
	
	printf ("1. Cadastrar novo funcion%crio na base de dados\nPreencha os dados que se pedem a seguir\n\n", 160);
	do{
	printf ("CPF: ");
	scanf ("%s", &func[i].cpf);
	
	if(strlen(func[i].cpf) != 11){
			printf("Digite um CPF valido\n");
		}
	}while(strlen(func[i].cpf)!=11);
	printf ("Nome Completo: ");
	scanf (" %100[^\n]s", &func[i].nome);
	printf ("Data de Admiss%co: ", 198);
	scanf ("%d%d%d", &func[i].dt_adm.dia, &func[i].dt_adm.mes, &func[i].dt_adm.ano);     //Incompleto e/ou incorreto
	printf ("Data de Nascimento: ");
	scanf ("%d%d%d", &func[i].dt_nasc.dia, &func[i].dt_nasc.mes, &func[i].dt_nasc.ano);    //Incompleto e/ou incorreto
	printf ("C%cdigo do cargo a ser designado: ", 162);
	scanf ("%d", &func[i].cargo);
	printf ("Departamento a ser designado: ");
	scanf ("%d", &func[i].dept);
	system ("cls");
	printf ("Usu%crio cadastrado. Verifique os dados que voc%c digitou:\n", 160, 136);
	printf ("  CPF: %s\n  Nome: %s\n  Data de Admiss%co: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  C%cdigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, 198, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, 162, func[i].cargo, func[i].dept);
	return 1;
	
}

int main (){
	system ("title Gerenciador de FuncionᲩos - Trab. Final PE");
	tFuncionario func[150];
	int prox[150];
	int i;
	int resp;
	int cont=0, cont2;
	char cpf[12];
	do{
		resp=menu();
		switch (resp){
			case 1: cont2 = cadastarFuncionario(func, cont);
					cont++;
   			        break;
            case 2: break; //N㯠definido ainda
            case 3: printf ("Digite o CPF do funcion%crio: ", 160);
					scanf ("%s", cpf[12]);
					
					//pesquisar (cpf, cont);
								
					break;
            case 4: printf ("Lista de funcion%crios cadastrados:\n", 160);
					for (i=0;i<cont;i++){
						printf ("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
	   	   	   	   	}
	   	   	   	   	break;
		    case 5: break; //N㯠definido ainda
 			case 6: break; //N㯠definido ainda
            case 0: break;
            default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
		}
	}while(resp!=0);
	return 0;
}
