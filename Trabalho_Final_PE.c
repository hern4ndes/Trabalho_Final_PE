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
int controle[1][11];
tDepartamento dep[11];
/*                    FUNCOES                   */
/*
 * [RAIZ]Funcao Menu Relatorio: Exibe o Menu Relatorio, menu raiz.
 * A partir dele, sao chamados os menus Funcionario e Departamento.
 */
int menuRelatorio(){
	int resp;
	printf("\t\tMenu Relatorio\n\n");
	printf("1. Funcionario\n");
	printf("2. Departamento\n");
	printf("0. Sair\n");
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
	printf("\n\t\tMenu Funcionario\n\n");
	printf("1. Cadastrar funcionario\n");
	printf("2. Alterar dados do funcionario\n");
	printf("3. Transferir funcionario de departamento\n");
	printf("4. Demitir Funcionario\n");
	printf("5. Listar todos os funcionarios\n");
	printf("6. Listar todos de um departamento\n");
	printf("0. Sair\n\n");
	printf("Digite uma opcao do menu: ");
	scanf("%d", &resp);
	system ("cls || clear" );
    return resp;
}
/*
 *     1.1 Funcao Cadastrar Funcionario: Cadastra um funcionario na base de dados.
 */
 int cadastarFuncionario(tFuncionario func[150], int pos){

 	printf ("1. Cadastrar novo funcionario\n");
 	printf("Preencha os dados que se pedem a seguir\n\n");
 	printf ("CPF: ");
 	scanf ("%s", &func[pos].cpf);
 	printf ("Nome Completo: ");
 	scanf (" %100[^\n]s", &func[pos].nome);
  	do{
 		printf ("Data de Admiss%co: ", 198);
 		scanf ("%d%d%d", &func[pos].dt_adm.dia, &func[pos].dt_adm.mes, &func[pos].dt_adm.ano);
 		if (valida_data(func[pos].dt_adm.dia, func[pos].dt_adm.mes, func[pos].dt_adm.ano) == 0){
 			printf ("Data inv%clida! Digite novamente\n", 160);
 		}
 	} while (valida_data(func[pos].dt_adm.dia, func[pos].dt_adm.mes, func[pos].dt_adm.ano) == 0);
 	do{
 		printf ("Data de Nascimento: ");
 		scanf ("%d%d%d", &func[pos].dt_nasc.dia, &func[pos].dt_nasc.mes, &func[pos].dt_nasc.ano);
 		if (valida_data(func[pos].dt_nasc.dia, func[pos].dt_nasc.mes, func[pos].dt_nasc.ano)==0){
 			printf ("Data inv%clida! Digite novamente\n", 160);
 		}
 	} while (valida_data(func[pos].dt_nasc.dia, func[pos].dt_nasc.mes, func[pos].dt_nasc.ano)==0);
 	printf ("Codigo do cargo a ser designado: ");
 	scanf ("%d", &func[pos].cargo);
 	printf ("Departamento a ser designado: ");
 	scanf ("%d", &func[pos].dept);
 	mostrarDados(pos);
	controle[1][0]++;
 	system ("cls || clear" );
 	return 1;
 }
/*
 *     1.2 Fun��o Alterar dados do funcionario: Alterar dados do funcionario
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.3 Fun��o Transferir Funcionario de Departmento: Altera o departamento
 */
          //
		  //IMPLEM8ENTACAO
		  //
/*
 *     1.4 Fun��o Demitir funcionario: Apaga o funcionario dos dados
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.5 Funcao Listar Todos: Lista todos os funcionarios de um departamento
 */
void mostrarDados(int i) {
	printf("CPF: %s\n", func[i].cpf);
	printf("Nome: %s\n",func[i].nome);
	printf("Data de Admissao: %d/%d/%d\n",func[i].dt_adm.dia,func[i].dt_adm.mes,func[i].dt_adm.ano);
	printf("Data de Nascimento: %d/%d/%d\n",func[i].dt_nasc.dia ,func[i].dt_nasc.mes, func[i].dt_nasc.ano);
	printf("Codigo do Cargo: %d\n",func[i].cargo);
	printf("Departamento: %d\n\n\n",func[i].dept);
	printf ("Funcionario indice: %d\n", i);
	printf("DEPARTAMENTO: %d\n", func[i].dept);
	/* code */
}
void listarTodos(int cont){
	int i;
	printf ("Lista de funcion%crios cadastrados:\n", 160);
	for (i=0;i<cont;i++){
		mostrarDados(i);


	}
}

/*
 * 1.6 Fun��o Listar Por Departamento: Lista todos os funcionarios de um departamento.
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
	printf ("\n\tMenu Departamento\n\n");
	printf("1. Criar departamento\n");
	printf("2. Alterar nome do departamento\n");
	printf("3. Consultar departamento\n");
	printf("4. Listar departamentos\n");
	printf("5. Excluir departamento\n");
	printf("0. Sair\n");
	printf("Digite sua resposta: ");
	scanf("%d", &resp);
}
//   #1
int criarDepartamento(int contDep){
	do{
	printf("Qual o codigo do departamento? ");
	scanf("%d", &dep[contDep].cod);
}	while (dep[contDep].cod > 10);
		/* code */

	printf("Qual o nome do departamento? ");
	scanf("%s", &dep[contDep].nome);
	dep[contDep].quant=0;
	return contDep; //Quando for chamado novamente, esse valor retornado � incrementado no main
	                //e volta como parametro.
}
//    #2
void alterarNomeDept(){
	int cod;
	int i;
	int y=0, n=0, pos;
	int resp;
	do{
		printf("Qual o codigo do departamento? ");
		scanf("%d", &cod);
		for(i=0;i<11;i++){
			if(cod==dep[i].cod){
				y=1;
				pos=i;
			}               //y=sim, n=nao. 0 e o valor pra nao e 1 pra sim
			else{
				n=0;
			}
		}
		if(y==1){
			printf("Qual o novo nome do departamento? ");
			scanf("%s", dep[pos].nome);
			resp=0;
		}
		if((y==0)&&(n==0)){
			printf("�Departamento <cod> nao existe! Digite 0 para retornar ao menu departamento ou 1 para digitar um novo c�digo: ");
			scanf("%d", &resp);
		}
	}while(resp==1);
}
//    #3
void consultarDepartamento(){
	int i;
	int cod;
	int nope=0;
	printf("Qual o codigo do departamento? ");
	scanf("%d", &cod);

	for(i=0;i<11;i++){
		if(cod==dep[i].cod){
			printf("Nome: %s\nQuantidade de funcionarios: %d", dep[i].nome, dep[i].quant);
		}else{
			nope=1;
		}
	}
	if(nope==1){
		printf("�Departamento <cod> nao existe!");
	}
}
//    #4
void listarDepartamento(){
	int i;
	int cont=0;
	for(i=0;i<11;i++){
		if (dep[i].cod>0){		//considerando que os codigos nao sejam negativos
			cont++;
		}
	}
	for(i=0;i<cont;i++){
		printf("Codigo: %d\nNome: %s\nQuantidade de funcionarios cadastrados: %d", dep[i].cod, dep[i].nome, dep[i].quant);
	}
}
 /*     2.5 Funcao Excluir Departamento: Deleta um departamento
 */
          //
		  //IMPLEMENTACAO
		  //

/*          OUTRAS FUNCOES         */
/*
 * Funcao Valida Datas: Valida as datas que sao inseridas no programa
 */
int valida_data(int dia, int mes, int ano){
    if ((dia>=1 && dia<=31)&&(mes>=1 && mes<=12)&&(ano>=1900 && ano<=2100))
        {
            if ((dia==29 && mes==2) && ((ano%4)==0)){
                return 1;
            }
            if (dia<=28 && mes==2){
                return 1;
            }
            if ((dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11)){
                return 1;
            }
            if ((dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)){
                return 1;
            } else{
                return 0;
            }
        } else{
                return 0;
		}
}
void testecontrole(){
	int i = 0, j = 0;
	for (i = 0; i <= 1; i++){
		for (j = 0; j <= 10; j++) {
			printf("%d ", controle[i][j]);
		}
		printf("\n");
	}
}
void matrizControle(int dep, int func) {

	controle[1][func] = func;

}
int pesquisarFuncionario(){
	int i;
	char cpf[12];
	int result;
	printf("Digite um CPF: ");
	scanf("%s", cpf);
	for(i=0;i<150;i++){
		result = strcmp(cpf, func[i].cpf);
		if (result==0){
			return 0;
		}else{
			return -1;
		}
	}
}
int menu_AlterarFuncionario(char cpf[12]){
	int resp;
	printf("1. CPF\n");
	printf("2. Nome\n");
	printf("3. Data de Nascimento\n");
	printf("4. Data de Admissao na Empresa\n");
	printf("5. Cargo\n");
	printf("0. Sair\n");
	printf("Digite uma opcao: ");
	scanf("%d", &resp);
	return resp;
}
void alterarFuncionario_CPF(){

}
int funcao_AlterarFuncionario(){
	char cpf[12];
	int i, j;
	int resp, rsp; //rsp PARA O MENU e resp PARA AS CONDICOES DE REPETICAO
	printf("Qual o CPF do funcionario? ");
	scanf("%s", &cpf);
	/*
	for(i=0;i<150;i++){
		do{
			if(strcmp(func[i].cpf, cpf)==0){
				printf("MENU ALTERAR FUNCIONARIO (CPF: %s)\n\n", cpf);

			}else{
				printf("CPF nao encontrado. 1 para digitar novamente, 0 pra sair");
			}
		}while(resp==1);
	}
	*/
	for(i=0;i<150;i++){
		if(strcmp(func[i].cpf, cpf)==0){
			j=i;
			rsp=menu_AlterarFuncionario(cpf);
		}
	}
	if(rsp==1){
		do{
			printf("Qual o novo CPF? ");
			scanf("%s", &cpf);
			for(i=0;i<150;i++){
				if (strcmp(func[j].cpf, cpf)==0){
					printf("CPF %s ja cadastrado! Digite 0 para retornar ao menu alterar funcionario ou 1 para digitar um novo cpf: ", cpf);
					scanf("%d", &resp);
				}else{

					printf("CPF alterado com sucesso!");
				}
			}
		}while(resp==1);
	}
	if(rsp==2){
		printf("Qual o novo nome? ");
		scanf("%s", &func[j].nome);
		printf("Nome alterado com sucesso!");
	}
	if(rsp==3){
		do{
			printf ("Qual a nova data de nascimento? ");
			scanf ("%d%d%d", &func[j].dt_nasc.dia, &func[j].dt_nasc.mes, &func[j].dt_nasc.ano);
			if (valida_data(func[j].dt_nasc.dia, func[j].dt_nasc.mes, func[j].dt_nasc.ano)==0){
				printf ("Data invalida! Digite novamente: ");
			}else{
				printf("Data de nascimento alterada com sucesso!");
			}
		}while (valida_data(func[j].dt_nasc.dia, func[j].dt_nasc.mes, func[j].dt_nasc.ano)==0);
	}
	if(rsp==4){
		do{
			printf ("Qual a nova data de admissao? ");
			scanf ("%d%d%d", &func[j].dt_adm.dia, &func[j].dt_adm.mes, &func[j].dt_adm.ano);
			if (valida_data(func[j].dt_adm.dia, func[j].dt_adm.mes, func[j].dt_adm.ano) == 0){
				printf ("Data invalida! Digite novamente:");
			}else{
				printf("Data de admissao alterada com sucesso!");
			}
		}while (valida_data(func[j].dt_adm.dia, func[j].dt_adm.mes, func[j].dt_adm.ano) == 0);
	}
	if(rsp==5){
		printf("Qual o novo cargo? ");
  	   	scanf("%d", &func[j].cargo);
		printf("Cargo alterado com sucesso!");
	}
	if(rsp==0){
		return 0;
	}
	return 0;
}
/*               MAIN               */
int main (){

	int i;
	int respP, respF, respD;
	char cpf[12];
	int cont, contDep=0;
	controle[0][0]=-1;
	for(i=1;i <= 10;i++){
		controle[0][i] = i;
	}
	do{
		respP=menuRelatorio();
		switch (respP){
			case 1: respF=menuFuncionario(); //ABRIR MENU FUNCIONARIO
					switch (respF){
						case 1: cadastarFuncionario(func, controle[1][0]);
								cont++;
   			        			break; //CADASTRAR
            			case 2: funcao_AlterarFuncionario();
								break; //ALTERAR DADOS
            			case 3: printf("Digite o CPF do funcion%crio: ", 160);
								scanf("%s", cpf);
								break; //TRANSFERIR
						case 4: break; //DEMITIR
						case 5: listarTodos(controle[1][0]);
	   	   	   	   				break; //LISTAR TODOS
	   	   				case 6: listarPorDept(controle[1][0]);
								break; //LISTAR POR DEPARTAMENTO
                  		case 7: testecontrole();
                  		case 8: if(pesquisarFuncionario()==0){
                  					printf("O funcionario existe :p");
								}
								if(pesquisarFuncionario()==-1){
									printf("O funcionario nao existe :(");
								}
							break;


                    break; //SAIR
                  case 0: break; //SAIR
            			default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
					}
   			        break;
            case 2: respD=menuDepartamento(); //ABRIR MENU DEPARTAMENTO
            		switch (respD){
						case 1: criarDepartamento(contDep);
								contDep++;
								break; //CRIAR DEPT
						case 2: alterarNomeDept();
								break; //ALTERAR NOME DEPT
						case 3: consultarDepartamento();
								break; //CONSULTAR DEPT
						case 4: listarDepartamento();
								break; //LISTAR DEPT;
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
