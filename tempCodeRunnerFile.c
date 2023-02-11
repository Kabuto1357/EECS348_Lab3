#include <stdio.h>
#include <stdlib.h>

int main(){

char *Month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char my_month[35];

my_month = Month[5];

printf("%s", my_month);
}

