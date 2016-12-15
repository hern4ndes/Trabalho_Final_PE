#include <stdio.h>
#include <stdlib.h>

int main (){
	system ("title Gerenciador de Funcion�rios - Trab. Final PE");
	tFuncionario func[150];
	int i;
	int resp;
	int cont=0, cont2;
	do{
		resp=menu();
		switch (resp){
			case 1: cont2 = cadastarFuncionario(func, cont);
					cont++;
   			        break;
            case 2: break; //N�o definido ainda
            case 3: break; //N�o definido ainda
            case 4: printf ("Lista de Funcion%crios cadastrados:\n", 160);
					for (i=0;i<cont;i++){
						printf ("  CPF: %s\n  Nome: %s\n  Data de Admissao: %d/%d/%d\n  Data de Nascimento: %d/%d/%d\n  Codigo do Cargo: %d\n  Departamento: %d\n\n\n", func[i].cpf, func[i].nome, func[i].dt_adm.dia, func[i].dt_adm.mes, func[i].dt_adm.ano, func[i].dt_nasc.dia, func[i].dt_nasc.mes, func[i].dt_nasc.ano, func[i].cargo, func[i].dept);
	   	   	   	   	}
	   	   	   	   	break;
		    case 5: break; //N�o definido ainda
 			case 6: break; //N�o definido ainda
            case 0: break;
            default: printf ("Erro. Por favor, digite novamente. Dessa vez, use uma op%c%co v%clida:\n\n", 135, 198, 160);
		}
	}while(resp!=0);
	return 0;
}
