#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MaxChar 20


void swap(int &a, int &b){
	
	int aux;
	
	aux = a;
	a = b;
	b = aux;
}

void show(char senha[]){
	
	for(int cont=0; cont<MaxChar; cont++){
		printf("%c",senha[cont]);
	}
}

void substituicao(char senha[]){
	
	for(int cont=0; cont<MaxChar; cont++){
		if(senha[cont]==0){
		}else{
			if(senha[cont]==127){
			senha[cont]=1;
			}else{
			senha[cont]++;
			}
		}
	}
}

void unsubstituicao(char senha[]){
	
	for(int cont=0; cont<MaxChar; cont++){
		if(senha[cont]==0){
		}else{
			if(senha[cont]==1){
			senha[cont]=127;
			}else{
			senha[cont]--;
			}
		}
	}
}

void transposicao(char senha[]){
	
	char senhaaux[MaxChar];
	
	for(int cont=0; cont<MaxChar; cont++){
		senhaaux[cont] = senha[cont];
	}
	
	int aux = 0;
		
	if(MaxChar%2==0){
		for(int cont=0; cont<MaxChar; cont++){
			if((cont+2)>=MaxChar){
				senha[cont]= senhaaux[aux];
				aux = 1;
			}else{
				senha[cont]= senhaaux[cont+2];
			}
		}
	}else{
		for(int cont=0; cont<(MaxChar-1); cont++){
			if((cont+2)>MaxChar){
				senha[cont]= senhaaux[aux];
				aux = 1;
			}else{
				senha[cont]= senhaaux[cont+2];
			}
		}
	}	
}

void untransposicao(char senha[]){
	
	char senhaaux[MaxChar];
	
	for(int cont=0; cont<MaxChar; cont++){
		senhaaux[cont] = senha[cont];
	}
		
	if(MaxChar%2==0){
		int aux = MaxChar-2;
		for(int cont=0; cont<MaxChar; cont++){
			if((cont-2)< 0){
				senha[cont]= senhaaux[aux];
				aux++;
			}else{
				senha[cont]= senhaaux[cont-2];
			}
		}
	}else{
		int aux = MaxChar-3;
		for(int cont=0; cont<(MaxChar-1); cont++){
			if((cont-2)< 0){
				senha[cont]= senhaaux[aux];
				aux++;
			}else{
				senha[cont]= senhaaux[cont-2];
			}
		}
	}	
}



int main(){
	
	char senha[MaxChar];
	int aux=0;
	
	printf("digite a senha com ate %i characteres: ", MaxChar);
	fgets(senha, MaxChar, stdin);
	
	do{
		printf("\n\n Selecione uma opcao:\n\n 1- Criptografia(Substituicao)\n 2- Decriptografia(Substituicao)\n 3-Criptografia(transposicao)\n 4-Decriptografia(transposicao)\n 5-Sair\n\n");
	
		scanf("%i", &aux);
		printf("\n");
		
		if(aux==1){
			printf("antes:\n\n");
			show(senha);
			printf("\ndepois:\n\n");
			substituicao(senha);
			show(senha);	
		}
		if(aux==2){
			printf("antes:\n\n");
			show(senha);
			printf("\ndepois:\n\n");
			unsubstituicao(senha);
			show(senha);
		}
		if(aux==3){
			printf("antes:\n\n");
			show(senha);
			printf("\ndepois:\n\n");
			transposicao(senha);
			show(senha);
		}
		if(aux==4){
			printf("antes:\n\n");
			show(senha);
			printf("\ndepois:\n\n");
			untransposicao(senha);
			show(senha);
		}
		
	}while(aux!=5);
	
	
	return 0;
}
