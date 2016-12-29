/*                ESTRTURA DO CODIGO-FONTE
 * - Estruturas
 * - Variaveis/Matrizes/Vetores Globais
 * - Funcoes
 *   - Funcao Menu Relatorio
 *     - Funcao Menu Funcionario
 *       - Cadastar
 *       - Alterar
 *       - Transferir
 *       - Demitir
 *       - Listar Geral
 *       - Listar por departamento
 *     - Funcao Menu Funcionario
 *       - Criar
 *       - Alterar
 *       - Listar
 *       - Consultar
 *       - Excluir
 * - Outras funcoes
 *   - Valida Datas
 *   - Mostrar Dados
 * - Main
 */
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
	printf("\n\t\tMenu Relatorio\n\n");
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
int cadastarFuncionario(tFuncionario func[150], int cont){
	int i, j;
	i=cont;
	int resp;

	printf ("1. Cadastrar novo funcionario\n");
	printf("Preencha os dados que se pedem a seguir\n\n");
	printf ("CPF: ");
	scanf ("%s", &func[i].cpf);
	printf ("Nome Completo: ");
	scanf (" %100[^\n]s", &func[i].nome);
 	do{
		printf ("Data de Admiss%co: ", 198);
		scanf ("%d%d%d", &func[i].dt_adm.dia, &func[i].dt_adm.mes, &func[i].dt_adm.ano);
		if (valida_data(func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano) == 0){
			printf ("Data inv%clida! Digite novamente\n", 160);
		}
	} while (valida_data(func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano) == 0);
	do{
		printf ("Data de Nascimento: ");
		scanf ("%d%d%d", &func[i].dt_nasc.dia, &func[i].dt_nasc.mes, &func[i].dt_nasc.ano);
		if (valida_data(func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano)==0){
			printf ("Data inv%clida! Digite novamente\n", 160);
		}
	} while (valida_data(func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano)==0);
	printf ("Codigo do cargo a ser designado: ");
	scanf ("%d", &func[i].cargo);
	printf ("Departamento a ser designado: ");
	scanf ("%d", &func[i].dept);
	printf ("%d\n", func[i].dept);
	system ("clear||cls");

	printf ("\nFuncionario cadastrado com sucesso. Confira os dados:\n");
	mostrarDados(i);
	matrizControle(func[i].dept, i);


	return cont;
}
/*
 *     1.2 Funcao Alterar dados do funcionario: Alterar dados do funcionario
 */
          //
		  //IMPLEMENTACAO
		  //
/*
 *     1.3 Funcao Transferir Funcionario de Departmento: Altera o departamento
 */
          //
		  //IMPLEM8ENTACAO
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
void  mostrarDados(int i) {
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
/*
 *     2.1 Funcao Criar Departamento: Cria um Departamento
 */
/*
void criarDept(){
	printf ("Criar Departamento\n\n");
	printf ("Qual o codigo do departamento? ");
	scanf ("%d", &dep[]);
	printf ("");
	scanf ("");
}
*/
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

/*               OUTRAS FUNCOES

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
/*
 * Funcao Listar Todos: Quando eh chamada, lista todos os funcionarios
 */
void listarTodos(int cont){
	int i;
	printf ("Lista de funcion%crios cadastrados:\n", 160);
	for (i=0;i<cont;i++){
		mostrarDados(i);
	}
}
/*
int menuAlterarFuncionario(){
	char cpf[12];
	int i;
	int resp;
	printf("Qual o CPF do funcionario? ");
	scanf("%s", cpf);
	for(i=0;i<150;i++){
		strcmp(if (strcmp(func[i].cpf, cpf)==0){
			do{
				printf("MENU ALTERAR FUNCIONARIO (CPF: %s)\n\n", cpf);
				printf("1. CPF\n");
				printf("2. Nome\n");
				printf("3. Data de Nascimento\n");
				printf("4. Data de Admissao na Empresa\n");
				printf("5. Cargo\n");
				printf("0. Sair\n");
				printf("Digite uma opcao: ");
				scanf("%d", &resp);
				switch (resp){
					case 1: do{
								printf("Qual o novo CPF? ");
								scanf("%s", cpf);
								for(i=0;i<150;i++){
									strcmp(if (strcmp(func[i].cpf, cpf)==0){
										printf("CPF %s ja cadastrado! Digite 0 para retornar ao menu alterar funcionario ou 1 para digitar um novo cpf: ", cpf);
										scanf("%d", resp);
										break;
									}
									else{
										func[i].cpf=cpf;
										printf("CPF alterado com sucesso!");
									}
								}
							}while(resp==1);
				}
					case 2: printf("Qual o novo nome? ");
							scanf("%s", &func[i].nome);
							print("Nome alterado com sucesso!");	
					case 3: do{
								printf ("Qual a nova data de nascimento? ");
								scanf ("%d%d%d", &func[i].dt_nasc.dia, &func[i].dt_nasc.mes, &func[i].dt_nasc.ano);
								if (valida_data(func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano)==0){
									printf ("“Data invalida! Digite novamente: ");
								}else{	
									printf("Data de nascimento alterada com sucesso!");
								}
							}while (valida_data(func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano)==0);
					case 4: do{
								printf ("Qual a nova data de admissao? ");
								scanf ("%d%d%d", &func[i].dt_adm.dia, &func[i].dt_adm.mes, &func[i].dt_adm.ano);
								if (valida_data(func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano) == 0){
									printf ("Data invalida! Digite novamente:");
								}else{
									printf("Data de admissao alterada com sucesso!");
								}
							}while (valida_data(func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano) == 0);	
					case 5: print("Qual o novo cargo? ");
					   	   	scanf("%d", &func[i].cargo);
							printf("Cargo alterado com sucesso!");   		
			}while(resp=0);
		}else{
			printf("CPF %s não cadastrado! Digite 0 para retornar ao menu funcionario ou 1 para digitar um novo cpf: ", cpf);
			scanf("%d", &resp);
			if (resp=1){
				menuAlterarFuncionario();
			}
		}
	}
}
*/	
int menuAlterarFuncionario(){
	char cpf[12];
	//printf("Qual o CPF do funcionario? ");
	//scanf("")
}
/*               MAIN               */
int main (){

	int cont=0;
	char cpf[12];
	//Atribuicoes incials
	int i = 0;
	controle[0][0]=-1;
	for(i=1;i <= 10;i++){
		controle[0][i] = i;
	}
	do{
		switch (menuRelatorio()){
			case 1:
					switch (menuFuncionario()){
						case 1: cadastarFuncionario(func, cont);
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
            			case 7: testecontrole();
									break; //SAIR
            			default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
					}
   			        break;
            case 2:
            		switch (menuDepartamento()){
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
	}while(menuRelatorio()!=0);
	return 0;
}