#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*                   ESTRUTURAS                 */
typedef struct{
	int dia;
	int mes;
	int ano;
}tdata;

typedef struct{
	char cpf[12];
	char nome[100];
	tdata dt_adm;
	tdata dt_nasc;
	int cargo;
	int dept;
}tFuncionario;

typedef struct{
	char nome[100];
	int cod;
	int quant;
}tDepartamento;


/*     VARIAVEIS GLOBAIS (VETORES/MATRIZES)     */
tFuncionario func[150];
int prox[150];
int controle[1][150];


/*                    FUNCOES                   */
/*
 * [RAIZ]Funcao Menu Relatorio: Exibe o Menu Relatorio, menu raiz.
 * A partir dele, sao chamados os menus Funcionario e Departamento.
 */
int menuRelatorio(){
	int resp;
	printf("\t\tMenu Relatorio\n\n1. Funcionario\n2. Departamento\n0. Sair\n");
	printf("Digite uma opcaoo do menu: ");
	scanf("%d", &resp);
	return resp;
}
/*
 * 1. Funcao Menu Funcionario: Mostra as opcoes de Funcionario
 */
int menuFuncionario(){
	int resp;
	system ("clear || cls");
	printf("\n\t\tMenu Funcionario\n\n1. Cadastrar funcionario\n2. Alterar dados do funcionario\n");
	printf("3. Transferir funcion%crio de departamento\n4. Demitir Funcion%crio\n");
	printf("5. Listar todos os funcion%crios\n6. Listar todos de um departamento\n0. Sair\n\n");
	printf("Digite uma opcao do menu: ");
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;
}
/*
 *     1.1 Funcao Cadastrar Funcionario: Cadastra um funcionario na base de dados.
 */
int cadastarFuncionario(tFuncionario func[150], int cont){
	int i;
	int rsp;
	int d, m ,a;
	i=cont;
	printf ("1. Cadastrar novo funcion%crio\nPreencha os dados que se pedem a seguir\n\n", 160);
	printf ("CPF: ");
	scanf ("%s", &func[i].cpf);
	printf ("Nome Completo: ");
	scanf (" %100[^\n]s", &func[i].nome);
 	do{
 		rsp=0;
		printf ("Data de Admiss%co: ", 198);
		scanf ("%d%d%d", &func[i].dt_adm.dia, &func[i].dt_adm.mes, &func[i].dt_adm.ano);
		d=func[i].dt_adm.dia;
		m=func[i].dt_adm.mes;
		a=func[i].dt_adm.ano;
		if((a>=1900)&&(a<=2100)){
			if((m>=1)&&(m<=12)){
				if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){
					if((d>=1)&&(d<=31)){
						rsp=1;
					}
				}
				if((m==4)||(m==6)||(m==9)||(m==11)){
					if((d>=1)&&(d<=30)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4!=0)){
					if((d>=1)&&(d<=28)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100!=0)){
					if((d>=1)&&(d<=29)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100==0)&&(a%400==0)){
					if((d>=1)&&(d<=29)){
						rsp=1;
					}
				} else{
					if((d>=1)&&(d<=28)){
						rsp=1;
					}
				}
			}
		}
		if (rsp==0){
			printf ("Data inv%clida! Digite novamente\n", 160);
		}
	} while (rsp==0);
	do{
 		rsp=0;
		printf ("Data de Nascimento: ");
		scanf ("%d%d%d", &func[i].dt_nasc.dia, &func[i].dt_nasc.mes, &func[i].dt_nasc.ano);
		d=func[i].dt_nasc.dia;
		m=func[i].dt_nasc.mes;
		a=func[i].dt_nasc.ano;
		if((a>=1900)&&(a<=2100)){
			if((m>=1)&&(m<=12)){
				if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){
					if((d>=1)&&(d<=31)){
						rsp=1;
					}
				}
				if((m==4)||(m==6)||(m==9)||(m==11)){
					if((d>=1)&&(d<=30)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4!=0)){
					if((d>=1)&&(d<=28)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100!=0)){
					if((d>=1)&&(d<=29)){
						rsp=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100==0)&&(a%400==0)){
					if((d>=1)&&(d<=29)){
						rsp=1;
					}
				} else{
					if((d>=1)&&(d<=28)){
						rsp=1;
					}
				}
			}
		}
		if (rsp==0){
			printf ("Data inv%clida! Digite novamente\n", 160);
		}
	} while (rsp==0);
	printf ("C%cdigo do cargo a ser designado: ", 162);
	scanf ("%d", &func[i].cargo);
	printf ("Departamento a ser designado: ");
	scanf ("%d", &func[i].dept);
	system ("cls || clear");
	printf ("Usu%crio cadastrado. Verifique os dados que voc%c digitou:\n", 160, 136);
	printf ("  CPF: %s\n  Nome: %s\n  Data de Admiss%co: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  C%cdigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, 198, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, 162, func[i].cargo, func[i].dept);
	printf ("Funcion%crio indice: %d\nDEPARTAMENTO: %d\n", 160, i, func[i].dept);
	return 1;
}
/*
 *     1.2 Função Alterar dados do funcionario: Alterar dados do funcionario
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.3 Função Transferir Funcionario de Departmento: Altera o departamento
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.4 Função Demitir funcionario: Apaga o funcionario dos dados
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.5 Funcao Listar Todos: Lista todos os funcionarios de um departamento
 */
void listarTodos(int cont){
	int i;
	printf ("Lista de funcion%crios cadastrados:\n", 160);
	for (i=0;i<cont;i++){
		printf("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
		printf("Funcion%crio indice: %d\nDEPARTAMENTO: %d\n\n", 160, i, func[i].dept);
	}
}
/*
 * 1.6 Função Listar Por Departamento: Lista todos os funcionarios de um departamento.
 * Eh solicitado o codigo do departamento e eh listado os funcionarios.
 */
void listarPorDept(int cont){
	int i;
	printf ("Lista de funcion%crios deste departamento:\nessa funcao ainda nao funciona", 160);
	for (i=0;i<cont;i++){
		printf("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
		printf("Funcion%crio indice: %d\nDEPARTAMENTO: %d\n\n", 160, i, func[i].dept);
	}	
}
/*
 * 2. Funcao Menu Departamento: Mostra as opcoes de Departamento
 */
int menuDepartamento(){
	int resp;
	system ("clear || cls");
	printf("\n\t\tMenu Departamento\n\n1. Criar Departamento\n2. Alterar nome do Departamento\n3. Consultar Departamento\n4. Listar Departamentos\n5. Excluir Departamento\n0. Sair\n\n");
	printf("Digite uma op%c%co do menu: ", 135, 198);
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;
}
/*
 *     2.1 Funcao Criar Departamento: Cria um Departamento 
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     2.2 Funcao Alterar nome do Departamento: Altera o nome do departamento criado
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     2.3 Funcao Consultar Departamento: Faz uma consulta de departamento
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     2.4 Funcao Listar Departamento: Lista todos os departamentos cadastrados
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     2.5 Funcao Excluir Departamento: Deleta um departamento
 */
          //
		  //IMPLEMENTACAO
		  //
		  
/*               MAIN               */
int main (){
	system ("title Gerenciador de Funcionários - Trab. Final PE");
	int i;
	int respP, respF, respD;
	int cont=0, cont2;
	char cpf[12];
	do{
		respP=menuRelatorio();
		switch (respP){
			case 1: respF=menuFuncionario(); //ABRIR MENU FUNCIONARIO
					switch (respF){
						case 1: cont2 = cadastarFuncionario(func, cont);
								cont++;
   			        			break; //CADASTRAR
            			case 2: break; //ALTERAR DADOS
            			case 3: printf("Digite o CPF do funcion%crio: ", 160);
								scanf("%s", cpf);								
								break; //TRANSFERIR
						case 4: break; //DEMITIR 
						case 5: listarTodos(cont);
	   	   	   	   				break; //LISTAR TODOS
	   	   				case 6: listarPorDept(cont);
								break; //LISTAR POR DEPARTAMENTO
            			case 0: break; //SAIR
            			default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
					}
   			        break;
            case 2: respD=menuDepartamento(); //ABRIR MENU DEPARTAMENTO
            		switch (respD){
						case 1: break; //CRIAR DEPT
						case 2: break; //ALTERAR NOME DEPT
						case 3: break; //CONSULTAR DEPT
						case 4: break; //LISTAR DEPT;
						case 5: break; //EXCLUIR DEPT
						case 0: break; //SAIR
					}
            		
					break;
            case 0: break; //SAIR
            default: system ("clear || cls");
					 printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
					 
		}
	}while(respP!=0);
	return 0;
}