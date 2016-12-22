#include <stdio.h>
int main (){
	int d, m, a, validade;
	do{
		printf ("Digite uma data: ");
		scanf ("%d %d %d", &d, &m, &a);
		if((a>=1900)&&(a<=2100)){
			if((m>=1)&&(m<=12)){
				//validade de meses com 31 dias
				if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)){
					if((d>=1)&&(d<=31)){
						validade=1;
					}
				}
				//validade de meses com 30 dias
				if((m==4)||(m==6)||(m==9)||(m==11)){
					if((d>=1)&&(d<=30)){
						validade=1;
					}
				}
				//validade dos dias de Fevereiro
				if((m==2)&&(a%4!=0)){
					if((d>=1)&&(d<=28)){
						validade=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100!=0)){
					if((d>=1)&&(d<=29)){
						validade=1;
					}
				}
				if((m==2)&&(a%4==0)&&(a%100==0)&&(a%400==0)){
					if((d>=1)&&(d<=29)){
						validade=1;
					}
				} else{
					if((d>=1)&&(d<=28)){
						validade=1;
					}
				}
			}
		}
	}while( validade!=1 );
	
	if(validade==1){
		printf ("Uma data v%clida foi digitada. Ela %c %d/%d/%d.\n\n", 160, 130, d, m, a);
	}
	return 0;
}