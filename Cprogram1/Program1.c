/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: k617r140
 */

#include <stdio.h>
#include <stdlib.h>

void monthly_report(){

	char line[255];
	FILE * fpointer = fopen("sale_numbers.txt", "r");

	char *Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int i;

	printf("Monthly Sales Report for 2022:");
	printf("\n");
	printf("\n");
	printf("Month");
	printf("%10s", "Sales");
	printf("\n");
	for(i = 0; i < 12; i++){
		printf("%s", Month[i]);
		fgets(line, 255, fpointer);
		printf("%10s", line);
		printf("\n");

	}
	fclose(fpointer);
}

void sales_summary(){

	printf("Sales summary:\n");
	printf("Minimum sales:\n");
	printf("Maximum sales:\n");
	printf("Average sales:\n");

	double sales[12];
	int i;
	char line[255];
	FILE * fpointer = fopen("sale_numbers.txt", "r");

	for(i = 0; i < 12; i++){
		fscanf(fpointer, "%lf", &sales[i]);
	}
	for(i=0; i < 12; i++){
		printf("%f\n",sales[i]);
	}
}

int main(){
	//monthly_report();
	sales_summary();


	return 0;

}


