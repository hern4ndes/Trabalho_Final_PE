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

//***FUN��O MENU***
int menu(){
	int resp;
	printf("\n MENU\n\n1. Cadastrar funcion%crio\n2. Demitir funcion%crio\n3. Transferir funcion%crio de departamento\n\n TESTE \n\n4. Listar geral (Fun%c%co para Testes)\n5. Listar por departamento (Fun%c%co para Testes)\n6. Listar por cargo (Fun%c%co para Testes)\n\n0. Sair\n", 160, 160, 160, 135, 198, 135, 198, 135, 198);
	printf("Digite uma op%c%co do menu: ", 135, 198);
	scanf("%d", &resp);
	system ("cls");
    return resp;
}

//***FUN��O CADASTRAR FUNCION�RIO***
int cadastarFuncionario(tFuncionario func[150], int cont){
	int i; i=cont;
	printf ("1. Cadastrar novo funcion%crio na base de dados\nPreencha os dados que se pedem a seguir\n\n", 160);
	printf ("CPF: ");
	scanf ("%s", &func[i].cpf);
	printf ("Nome Completo: ");
	scanf ("%s", &func[i].nome);
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
