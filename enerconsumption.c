#include <stdio.h>
#include <stdlib.h>


#define COST_KWH 0.16



void ecInit(float vect[]);
void ecAdd();
void dtSum();


int main(){
	
	float consumption[96];	//96= numero de intervalos em 24H
	float peak, dailyValue, dailyCost;
	 
	ecInit(consumption);
	
	ecAdd(consumption);
	ecAdd(consumption);
	
	
		for(int i=0;i<96;i++){
		
			fprintf(stdout, "%f \n", consumption[i]);
		}
	
	return 0;}


// Funções :

//inicia  todas a posicoes do array com o valor zero
void ecInit(float vect[]){
	
	for(int i=0;i<96;i++){
		
		vect[i]=0;
		}
	
	}	

//adiciona um novo valor que e pedido ao utilizador
void ecAdd(float vect[]){
	
	static int index=95;
	float new_val=0;
	
	if(index >=96){
		index=0;
		}
	
	
	fprintf(stdout, "insira um novo valor: ");
	scanf("%f", &new_val);
	
	vect[index]= new_val;
	
	index++;
	
	}




























