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
	printf("\t\tMenu Principal\n\n");
	printf("1. Funcionario\n");
	printf("2. Departamento\n");
	printf("0. Sair\n");
	printf("Digite uma opcao do menu: ");
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
 	int depOK=0;//1: Departamento OK, 0:Departamento nao existe
 	int i;
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
 	do{
  		printf ("Departamento a ser designado: ");
 		scanf ("%d", &func[pos].dept);
 		for(i=0;i<11;i++){
 			if(func[pos].dept==dep[i].cod){
 				depOK=1;
 				break;
			 }
 		}
	}while(depOK==0);
	printf("Funcionario cadastrado com sucesso! Verifique seus dados:\n");
 	mostrarDados(pos);
	controle[1][0]++;
 	return 1;
 }
/*
 *     1.2 Funcao Alterar dados do funcionario: Altera dados do funcionario
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.3 Funcao Transferir Funcionario de Departmento: Altera o departamento
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.4 Funcao Demitir funcionario: Apaga o funcionario dos dados
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
	printf("Departamento: %d\n",func[i].dept);
	printf ("Funcionario indice: %d\n", i);//extra
}
void listarTodos(int cont){
	int i;
	printf ("Lista de funcionarios cadastrados:\n");
	
	for (i=0;i<cont;i++){                //AGORA ELA ~DEVE~ CLASSIFICAR POR DEPARTAMENTOS
		mostrarDados(i);                 //por isso, tem q refazer


	}
}

/*
 * 1.6 Funcao Listar Por Departamento: Lista todos os funcionarios de um departamento.
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


//-------------------------------------------------------INICIO DAS FUNCOES DE DEPARTAMENTO--------------------------------------------------
//2. Funcao Menu Departamento: Mostra as opcoes de Departamento
    //Objetivo: Mostrar o menu Departamento
    //Parametros: Nenhum
    //Retorno: A resposta do usuario, ou seja, a opcao desejada do menu
int menuDepartamento(){
	system("clear || cls");
	int resp;
	printf ("\n\tMenu Departamento\n\n");//#1
	printf("1. Criar departamento\n");//#2
	printf("2. Alterar nome do departamento\n");//#3
	printf("3. Consultar departamento\n");//#4
	printf("4. Listar departamentos\n");//#5
	printf("5. Excluir departamento\n");//#6
	printf("0. Sair\n");//Saida
	printf("Digite sua resposta: ");
	scanf("%d", &resp);
	return resp;
}
//  #2.1: Criar Departamento
        //Objetivo: Criar um departamento
        //Parametros: contDep que controla os departamentos cadastrados
        //Retorno: retorna o contDep pra fazer incremento
int criarDepartamento(int contDep){
	system("clear || cls");
	printf("\tCriar Departamento\n\n");
	int i;
	do{
		printf("Qual o codigo do departamento? ");
		scanf("%d", &dep[contDep].cod);
	}while (dep[contDep].cod > 10);
	for(i = 1; i <= 11; i++){
		while (controle[0][i] == dep[contDep].cod){
			printf("O departamento %d ja existe!\nDigite 0 para retornar ao menu departamento ou 1 para digitar um novo codigo\n",dep[contDep].cod );
			int resp;
			scanf("%d",&resp);
			if (resp == 1) {
				printf("Qual o codigo do departamento? ");
				scanf("%d", &dep[contDep].cod);
			}
		}
	}
	printf("Qual o nome do departamento? ");
	scanf("%s", &dep[contDep].nome);
	dep[contDep].quant=0;
	controle[0][contDep + 1] = dep[contDep].cod;
	printf("\nDepartamento criado com sucesso. Pronto para cadastrar funcionarios.\n");
	return contDep; //Quando for chamado novamente, esse valor retornado eh incrementado no main
                 	//e volta como parametro.
}
//    #2.2: Alterar nome do Departamento
        //Objetivo:
        //Parametros:
        //Retorno:
void alterarNomeDept(){
	system("clear || cls");
	printf("\tAlterar nome de Departamento\n\n");
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
			}               //y=sim, n=nao. 0 e o valor pra nao e 1 pra sim. COISAS QUE SO O DIEGO ENTENDE :D
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
			printf("O Departamento %d nao existe!\nDigite 0 para retornar ao menu departamento ou 1 para digitar um novo codigo: ", cod);
			scanf("%d", &resp);
		}
	}while(resp==1);
}
//    #2.3: Consultar Departamento
        //Objetivo:
        //Parametros:
        //Retorno:
void consultarDepartamento(){
	system("clear || cls");
	printf("\tConsultar Departamento\n\n");	
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
//    #2.4: Listar Departamentos
        //Objetivo:
        //Parametros:
        //Retorno:
void listarDepartamento(){
	system("clear || cls");
	printf("\tListar Departamento\n\n");
	int i;
	int cont=0;
	for(i=0;i<11;i++){
		if (dep[i].cod>0){		//considerando que os codigos nao sejam negativos
			cont++;             //Esse for serve pra apenas selecionar os departamentos cadastrados na listagem
		}                       //  ja que os departamentos estao no vetor dep de forma contigua :)
	}
	printf("Lista de Departamentos cadastrados: ");
	for(i=0;i<cont;i++){
		printf("\nCodigo: %d\nNome: %s\nQuantidade de funcionarios cadastrados: %d\n", dep[i].cod, dep[i].nome, dep[i].quant);
	}
}
//    #2.5: Excluir Departamento
        //Objetivo:
        //Parametros:
        //Retorno:

int pesquisarExcluirDepartamento(){
	int i, cod, resp;
	do{
		printf("Qual o codigo do departamento? ");
		scanf("%d", &cod);
		for(i=0;i<11;i++){
			if(dep[i].cod==cod){
				return 1; //SIM!
			}
		}
		printf("Departamento %d nao existe!\nDigite 0 para retornar ao menu departamento ou 1 para digitar um novo codigo: ", cod);
		scanf("%d", &resp);
	}while(resp=1);
}
void excluirDepartamento(){
	int resp;
	resp=pesquisarExcluirDepartamento();
	if(resp==1){
		printf("\nDaqui a pouco esse bagulho exclui, blz?\n");
	}
}
//-------------------------------------------------------FIM DAS FUNCOES DE DEPARTAMENTO--------------------------------------------------


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
int alterarFuncionario_CPF(char cpf[12]){
	int i;
	for(i=0;i<150;i++){
		if(strcmp(func[i].cpf, cpf)==0){
			return i;
		}
	}
	return -1;
}
int verificarExistenciaCPF(char cpf[12]){
	int i;
	for(i=0;i<150;i++){
		if(strcmp(func[i].cpf, cpf)==0){
			printf("%s", cpf);
			return 10; //Se existir
		}
	}
	return 5; //Se nao existir
}
int funcao_AlterarFuncionario(){
	char cpf[12];
	int i, j;
	int resp, rsp; //rsp PARA O MENU e resp PARA AS CONDICOES DE REPETICAO
	printf("Qual o CPF do funcionario? ");
	scanf("%s", &cpf);
	if(alterarFuncionario_CPF(cpf) != -1){
		j=alterarFuncionario_CPF(cpf);
		printf("Menu Alterar Funcionario - CPF %s\n", cpf);
		rsp=menu_AlterarFuncionario(cpf);
	}
	if(alterarFuncionario_CPF(cpf) == -1){
		printf("Esse CPF nao esta cadastrado!\n1.digitar outro\n0.Sair\nResposta: ");
		scanf("%d", &resp);
		if (resp==1){
			funcao_AlterarFuncionario();
		}
	}
	if(rsp==1){
		char cpf[12];
		do{
			printf("Digite o novo CPF: ");
			scanf("%s", cpf);
			resp=verificarExistenciaCPF(cpf);
			if(resp==5){
				strcpy(func[j].cpf, cpf);
			}else if (resp==10){
				printf("Esse cpf ja existe.\n1.digitar outro\n2.Sair\nResposta: ");
				scanf("%d", &resp);
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
                  				break;
                  		case 8: if(pesquisarFuncionario()==0){
                  					printf("O funcionario existe :p");
								}
								if(pesquisarFuncionario()==-1){
									printf("O funcionario nao existe :(");
								}
							break;
                        case 0: break; //SAIR
            			default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
					}
   			        break;
            case 2: switch (menuDepartamento()){
						case 1: criarDepartamento(contDep);
								contDep++;
								break; //CRIAR DEPT
						case 2: alterarNomeDept();
								break; //ALTERAR NOME DEPT
						case 3: consultarDepartamento();
								break; //CONSULTAR DEPT
						case 4: listarDepartamento();
								break; //LISTAR DEPT;
						case 5: excluirDepartamento();
								break; //EXCLUIR DEPT
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
