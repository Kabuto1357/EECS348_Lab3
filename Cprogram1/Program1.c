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
	printf("Month");
	printf("%10s", "Sales");
	printf("\n");
	for(i = 0; i < 12; i++){
        //For loop prints every month and sales for that month.
		printf("%s\t", Month[i]);
		fgets(line, 255, fpointer);
		printf("$%10s", line);
	}
	fclose(fpointer);
    printf("\n");
}

void sales_summary(){

    double min_sale; //empty var to store the min sale
    double max_sale; //empty var to store the max sale
    double avg_sale = 0; //empty var to calculate average

	double sales[12]; //empty array to store nums from sale_nums file.
	int i; // to assist with for loops. 
	char line[255];
	FILE * fpointer = fopen("sale_numbers.txt", "r"); 

	for(i = 0; i < 12; i++){
		fscanf(fpointer, "%lf", &sales[i]);
        //Appends sale from input file to sales array
	}

	for(i=0; i < 12; i++)
    {
        //for loop used to figure what the max sale is.
        max_sale = 0;
        if(sales[i] > max_sale){
            max_sale = sales[i];
        }
    }
    
    min_sale = sales[0];

    for(i=0; i < 12; i++){
        //for loop used to figure what the mix sale is. 
        if(sales[i] < min_sale){
            min_sale = sales[i];
        }

    }

    for(i = 0; i < 12; i++){
        //for loop to calculate average
        avg_sale += sales[i];
    }

    printf("Sales summary:\n");
	printf("Maximum sales: $%10lf\n", max_sale);
	printf("Minimum sales: $%10lf\n", min_sale);
	printf("Average sales: $%10lf\n", avg_sale/12);
}

void six_month_avg(){

    double sales[12]; //Empty array used to hold each month.
	int i; // to assist with for loops. 
	char line[255]; //Sets the amount of characters that the 'char' can hold (aka string, this is an array of chars)
    double six_month_calc; // Initializing var to hold calc

	FILE * fpointer = fopen("sale_numbers.txt", "r"); //Opens given file.

    for(i = 0; i < 12; i++){
		fscanf(fpointer, "%lf", &sales[i]);
        //Appends each monthly sale amount to a sales array
	}

    printf("Six-Month Moving Average Report:\n");
    six_month_calc = 0;

    //The following for loops below are calculating each 6 month period and displaying the average.

    for(i = 0; i < 6; i++){
        //January - June Avg
        six_month_calc += sales[i];
    }
    printf("January - June   \t$%10lf\n", six_month_calc/=6);
    six_month_calc = 0;
    for(i = 1; i < 7; i++){
        //February - July Avg
        six_month_calc += sales[i];
    }
    printf("February - July \t$%10lf\n", six_month_calc/=6);
    
    six_month_calc = 0;
    for(i = 2; i < 8; i++){
        //March - August Avg
        six_month_calc += sales[i];
    }
    printf("March - August  \t$%10lf\n", six_month_calc/=6);

    six_month_calc = 0;
    for(i = 3; i < 9; i++){
        //April - September Avg
        six_month_calc += sales[i];
    }
    printf("April - September \t$%10lf\n", six_month_calc/=6);

    six_month_calc = 0;
    for(i = 4; i < 10; i++){
        //May - October Avg
        six_month_calc += sales[i];
    }
    printf("May - October    \t$%10lf\n", six_month_calc/=6);

    six_month_calc = 0;
    for(i = 5; i < 11; i++){
        //June - November Avg
        six_month_calc += sales[i];
    }
    printf("June - November \t$%10lf\n", six_month_calc/=6);

    six_month_calc = 0;
    for(i = 6; i < 12; i++){
        //July - December Avg
        six_month_calc += sales[i];
    }
    printf("July - December \t$%10lf\n", six_month_calc/=6);

}

void sales_report(){

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    char line[255]; //Sets the amount of characters that the 'char' can hold (aka string, this is an array of chars)
    double sales[12]; //Holds the month of every sale.

	FILE * fpointer = fopen("sale_numbers.txt", "r");

	char *Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    // ^ Above array holds every single month.
	int i,j; //Initiallizing i/j variables for loops

    for(i = 0; i < 12; i++){
        //Appending each monthly sale to an array
        fscanf(fpointer, "%lf", &sales[i]);
    }

    for(i = 11; i > -1; i--){
        //Can't figure out how to sort in acending order.
        printf("%s\t%s\n",Month[i],"Sale goes here.");
    }
    
fclose(fpointer); //Closes file.
}
int main(){
    printf("=====================================\n");
	monthly_report(); // Calls monthly_report function
    printf("====================================");
    printf("\n");

	sales_summary(); //Calls sales summary function
    printf("====================================");
    printf("\n");

    six_month_avg(); //Calls 6_month_avg function
    printf("=====================================");
    printf("\n");

    sales_report(); //Calls sales report function
    printf("=====================================");
    printf("\n");

	return 0;

}