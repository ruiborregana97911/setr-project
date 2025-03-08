#include <stdio.h>
#include <stdlib.h>


#define COST_KWH 0.16



void ecInit(float vect[]);
void ecAdd(float vect[]);
void dtSum(float vect[], float *peak, float *dailyValue, float *dailyCost);


int main(){
	
	float consumption[96];	//96= numero de intervalos em 24H
	float peak=0, dailyValue=0, dailyCost=0;
	 
	ecInit(consumption);
	
	char res;
	do{
		ecAdd(consumption);
		fprintf(stdout, "\nPretende adionar mais valores? (y/n): ");
		scanf(" %c", &res);	
			
			
	}while(res == 'y');
	
	
	dtSum(consumption, &peak, &dailyValue, &dailyCost);
	fprintf(stdout, "\nvalor de pico de consumo: %.3f",peak);
	fprintf(stdout, "\nvalor de consumo total: %.3f",dailyValue);
	fprintf(stdout, "\nvalor de custo de consumo: %.2f Euros\n",dailyCost);
	
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
	
	static int index=0;
	float new_val=0;
	
	if(index >=96){
		index=0;
		}
	
	
	fprintf(stdout, "\ninsira um novo valor: ");
	scanf("%f", &new_val);
	
	vect[index]= new_val;
	
	index++;
	
	}

//funcao de computacao de varios valores
void dtSum(float vect[], float *peak, float *dailyValue, float *dailyCost){
	
	//encontar maximo
	for(int i=0;i<96;i++){
		if(vect[i] >= *peak){
			*peak= vect[i];
			}
		}
	
	

	//consumo total
	for(int i=0;i < 96;i++){
		
		*dailyValue= *dailyValue + vect[i];
		}

	//custo total num dia
	
	*dailyCost= *dailyValue * COST_KWH;
}




















