int criarDepartamento(int contDep){

	system("clear || cls");
	printf("\tCriar Departamento\n\n");
	int i;
	do{
		printf("Qual o codigo do departamento? ");
		scanf("%d", &dep[contDep].cod);
	}	while (dep[contDep].cod > 10);
	for(i = 1; i <= 11; i++){
		while (controle[0][i] == dep[contDep].cod){
			printf("departamento %d ja existe! Digite 0 para retornar ao menu departamento ou 1 para digitar um novo codigo\n",dep[contDep].cod );
			int resp;
			scanf("%d",&resp);
			if (resp == 1) {
				printf("Qual o codigo do departamento? ");
				scanf("%d", &dep[contDep].cod);

			}else if(resp == 0){

				menuDepartamento();
				break;
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
