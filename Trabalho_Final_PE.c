#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estruturas
typedef struct{
	int dia;
	int mes;
	int ano;
}tdata;
typedef struct{
	char cpf[12];
	char nome[100]; //Nome de funcionario!
	tdata dt_adm;
	tdata dt_nasc;
	int cargo;
	int dept;
}tFuncionario;
typedef struct{
	char nome[100]; //Nome de departamento!
	int cod; //Codigo do departamento
	int quant; //Quantidade de funcionarios do departamento
}tDepartamento;

//Variaveis Globais
tFuncionario func[150];
int prox[150];
int controle[1][150];

//Prototipo de funcoes
    // Menus                        ====
int menuPrincipal();
int menuFuncionario();
int menuDepartamento();
    // Funcoes do Menu Funcionario  ====
int cadastarFuncionario(tFuncionario func[150], int cont);
void alterarDados(); //Nao implementado
void trasnferir();   //Nao implementado
void demitir();      //Nao implementado
void listarTodos(int cont);
void listarPorDept(int cont);//Nao implementado
    // Funcoes do Menu Departamento ====
int criarDept();     //Nao implementado
void alterarDept();  //Nao implementado
void consultarDept();//Nao implementado
void listarDept();   //Nao implementado
void excluirDept();  //Nao implementado

//Main
int main (){
	system ("title Gerenciador de Funcionários - Trab. Final PE");
	//int prox[150];
	int i;
	int respP, respF, respD;
	int cont=0, cont2;
	char cpf[12];
	do{
		respP=menuPrincipal();
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

// Funções
int menuPrincipal(){ //FUNCAO QUE EXIBE O MENU PRINCIPAL
	int resp;
	printf("\t\tMenu Principal\n\n1. Funcion%crio\n2. Departamento\n0. Sair\nDigite uma op%c%co do menu: ", 160, 135, 198);
	scanf("%d", &resp);
	return resp;
}
int menuFuncionario(){ //FUNCAO QUE EXIBE O MENU FUNCIONARIO
	int resp;
	system ("clear || cls");
	printf("\n\t\tMenu Funcion%crio\n\n1. Cadastrar funcion%crio\n2. Alterar dados do funcion%crio\n3. Transferir funcion%crio de departamento\n",160, 160, 160, 160);
	printf("4. Demitir Funcion%crio\n5. Listar todos os funcion%crios\n6. Listar todos de um departamento\n", 160, 160);
	printf("0. Sair\n\n");
	printf("Digite uma op%c%co do menu: ", 135, 198);
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;
}
void listarTodos(int cont){ //FUNCAO QUE LISTA TODOS OS FUNCIONARIOS
	int i;
	printf ("Lista de funcion%crios cadastrados:\n", 160);
	for (i=0;i<cont;i++){
		printf("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
		printf("Funcion%crio indice: %d\nDEPARTAMENTO: %d\n\n", 160, i, func[i].dept);
	}
}
void listarPorDept(int cont){ //FUNCAO QUE LISTA TODOS OS FUNCIONARIOS
	int i;
	printf ("Lista de funcion%crios deste departamento:\nessa funcao ainda nao funciona", 160);
	for (i=0;i<cont;i++){
		printf("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
		printf("Funcion%crio indice: %d\nDEPARTAMENTO: %d\n\n", 160, i, func[i].dept);
	}	
}

int menuDepartamento(){ //FUNCAO QUE EXIBE O MENU DEPARTAMENTO
	int resp;
	system ("clear || cls");
	printf("\n\t\tMenu Departamento\n\n1. Criar Departamento\n2. Alterar nome do Departamento\n3. Consultar Departamento\n4. Listar Departamentos\n5. Excluir Departamento\n0. Sair\n\n");
	printf("Digite uma op%c%co do menu: ", 135, 198);
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;
}

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
	// Trecho abaixo: Recebe e valida das datas =========================
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
	//================================================================================
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