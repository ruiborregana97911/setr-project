/** \file enerconsumption.c 
 * 	\brief Funções para registrar e calcular o consumo de energia elétrica.
 * 
 * 	Este arquivo contém funções para inicializar um vetor de consumo,
 * 	adicionar leituras e calcular valores como pico de consumo, consumo
 * 	total diário e custo diário.
 * 	\author Rui Borregana
 * 	\date 08/03/2025
 */


#include <stdio.h>
#include <stdlib.h>


#define COST_KWH 0.16


/**
 * \brief Inicializa o vetor de consumo com zeros
 * \param vect Vetor que armazena o consumo de energia a cada 15 minutos.
 */
void ecInit(float vect[]);

/**
 * \brief Adiciona uma nova leitura de consumo ao vetor.
 *
 * A função solicita ao usuário que insira um valor de consumo e o adiciona
 * ao vetor na posição adequada.
 *
 * \param vect Vetor que armazena o consumo de energia a cada 15 minutos.
 */
void ecAdd(float vect[]);

/**
 * \brief Calcula o pico de consumo, consumo total diário e custo diário.
 *
 * \param vect Vetor que armazena o consumo de energia a cada 15 minutos.
 * \param peak Ponteiro para armazenar o valor do pico de consumo.
 * \param dailyValue Ponteiro para armazenar o consumo total diário.
 * \param dailyCost Ponteiro para armazenar o custo total diário.
 */
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

void ecInit(float vect[]){
	
	for(int i=0;i<96;i++){
		
		vect[i]=0;
		}
	
	}	


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




















