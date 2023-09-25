#include<stdio.h>
#include<math.h>

void subtraction(float spacex,float spacey,float distance);
void unitario1(float spacex,float spacey,float distance_x);
void campoElectric1(float spacex,float spacey,float distance_x,float charge);

int main() {
	
	// variables a trabajar
	float charge,distance1,distance2,spacex,spacey;
	
	
	//datos por entrada al usuario
	printf("1.Enter the electric charge:");
	scanf("%f",&charge);
	fflush(stdin);
	printf("2.Enter the charging distance in the positive x coordinate:");
	scanf("%f",&distance1);
	fflush(stdin);
	printf("3.Enter the charging distance in the negative x coordinate:");
	scanf("%f",&distance2);
	fflush(stdin);
	printf("4.Enter the x coordinate:");
	scanf("%f",&spacex);
	fflush(stdin);
	printf("5.Enter the y coordinate:");
	scanf("%f",&spacey);
	fflush(stdin);
	
	printf("\n\t\tResulting Vectors:\n");
	subtraction(spacex,spacey,distance1);
	printf("\n");
	subtraction(spacex,spacey,distance2);
	
	printf("\n\t\tValues of the magnitudes:\n");
	unitario1(spacex,spacey,distance1);
	printf("\n");
	unitario1(spacex,spacey,distance2);
	
	printf("\n\t\tThe electric field of the charges is:\n");
	campoElectric1(spacex,spacey,distance1,charge);
	printf("\n");
	campoElectric1(spacex,spacey,distance2,charge);
	
	
	
	return 0;
}

void subtraction(float spacex,float spacey,float distance_x){
	//convertir las coordenas del campo electrico en vector
	//				0     1
	float vec[2] = {spacex,spacey};
	
	//operacion para hacer la resta de las coordenas y sacar el vector R-R1
	for(int i=0 ; i < 2 ; i++){
		if(i==0){
			vec[0] -= distance_x ;
		}
		else{
			vec[1] -= distance_x;	
		}
	}
	//Imprimiendo el vector R-R1
	for(int i=0 ; i < 2 ; i++){
		if(i==0){
			printf("R-R1 = <%.0f,",vec[i]);
		}else {
			printf("%.0f>",vec[i]);
		}
	}
}
void unitario1(float spacex,float spacey,float distance_x){
	//convertir las coordenas del campo electrico en vector
	//				0     1
	float vec[2] = {spacex,spacey};
	
	//operacion para hacer la resta de las coordenas y sacar el vector R-R1
	for(int i=0 ; i < 2 ; i++){
		if(i==0){
			vec[0] -= distance_x ;
		}
		else{
			vec[1] -= distance_x;	
		}
		
		
	}
	float uni = sqrt(pow(vec[0],2) + pow(vec[1],2));
	printf("|R-R1|:%.2f",uni);
}
void campoElectric1(float spacex,float spacey,float distance_x,float charge){
	//convertir las coordenas del campo electrico en vector
	//				0     1
	float vec[2] = {spacex,spacey};
	
	//operacion para hacer la resta de las coordenas y sacar el vector R-R1
	for(int i=0 ; i < 2 ; i++){
		if(i==0){
			vec[0] -= distance_x ;
		}
		else{
			vec[1] -= distance_x;	
		}
		
		
	}
	//Calculmos la magnitud del vector
	float uni = sqrt(pow(vec[0],2) + pow(vec[1],2));
	//calculamos el campo electrico
	float vec2[2];
	for(int i=0 ; i < 2 ; i++){
		vec2[i] = ((pow(9*10,9))*(pow(charge*10,-6))/(pow(uni,3))) * vec[i]; 
	}
	//imprimimos el campo electrico
	for(int i=0 ; i < 2 ; i++){
		if(i==0){
			printf("<%.2f , ",vec2[i]);
		}else {
			printf("%.2f>",vec2[i]);
		}
	}
	
}
