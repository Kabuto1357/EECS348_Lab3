/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: k617r140/Kevin Rivers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Month[15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

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
		printf("%-10s", Month[i]);
		fgets(line, 255, fpointer);
		printf("$%s", line);
	}
	fclose(fpointer);
    printf("\n");
}

void sales_summary(){

    float min_sale; //empty var to store the min sale
    float max_sale; //empty var to store the max sale
    float avg_sale = 0; //empty var to calculate average

    char max_month[255];
    char least_month[255];

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
            strcpy(max_month,Month[i]);
        }
    }
    

    for(i=0; i < 12; i++){
        //for loop used to figure what the mix sale is. 
        min_sale = sales[0];
        if(sales[i] < min_sale){
            min_sale = sales[i];
            strcpy(least_month, Month[i]);
        }

    }

    for(i = 0; i < 12; i++){
        //for loop to calculate average
        avg_sale += sales[i];
    }

    printf("Sales summary:\n");
    printf("Minimum sales: $%10.2f (%s) \n", min_sale, least_month); //Not sure why January doesn't show.
	printf("Maximum sales: $%10.2f (%s) \n", max_sale, max_month); //But this works.
	printf("Average sales: $%10.2f\n", avg_sale/12);
}

void six_month_avg(){

    float sales[12]; //Empty array used to hold each month.
	int i; // to assist with for loops. 
	char line[255]; //Sets the amount of characters that the 'char' can hold (aka string, this is an array of chars)
    float six_month_calc; // Initializing var to hold calc

	FILE * fpointer = fopen("sale_numbers.txt", "r"); //Opens given file.

    for(i = 0; i < 12; i++){
		fscanf(fpointer, "%f", &sales[i]);
        //Appends each monthly sale amount to a sales array
	}

    printf("Six-Month Moving Average Report:\n");
    six_month_calc = 0;

    //The following for loops below are calculating each 6 month period and displaying the average.

    for(i = 0; i < 7; i++){
        //January - June Avg
        six_month_calc = (sales[i]+ sales[i+1]+sales[i+2]+sales[i+3]+sales[i+4]+sales[i+5])/6;
        printf("%-10s- %-10s $%.2f\n", Month[i],Month[i+5], six_month_calc);
    }

}

void sales_report(){

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    char line[255]; //Sets the amount of characters that the 'char' can hold (aka string, this is an array of chars)
    float sales[12]; //Holds the month of every sale.
    float final_sales[12];
	FILE * fpointer = fopen("sale_numbers.txt", "r");

	char *Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    // ^ Above array holds every single month.
    int i,j;
    float temp;
    int temp_month; 

    for (i = 0; i < 12; i++){
        fscanf(fpointer, "%f", &sales[i]);
    }
    fclose(fpointer);
    int final_months[12];
    for(i = 0; i < 12; i++){
        //Appending each monthly sale to an array
        final_sales[i] = sales[i];
        final_months[i] = i;
    }
        for(i = 0; i < 12; i++){
        for(j = i+1; j < 12; j++){
        //Can't figure out how to sort in acending order.
        if (final_sales[i] < final_sales[j]){
            temp = final_sales[i];
            final_sales[i] = final_sales[j];
            final_sales[j] = temp; 

            temp_month = final_months[i];
            final_months[i] = final_months[j];
            final_months[j] = temp_month; 
        }
    }
    }

    for(i=0; i<12; i++){
       
        printf("%-10s\t%.2f\n",Month[final_months[i]],final_sales[i]);
    }
    
    

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