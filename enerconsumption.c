#include <stdio.h>
#include <stdlib.h>


#define COST_KWH 0.16



void ecInit(float vect[]);
void ecAdd();
void dtSum();


int main(){
	
	float consumption[96];	//96= numero de intervalos em 24H
	 
	ecInit(consumption);
	
	
	
	
	return 0;}


// Funções :

//inicia  todas a posicoes do array com o valor zero
void ecInit(float vect[]){
	
	for(int i=0;i<96;i++){
		
		vect[i]=0;
		}
	
	}	


























