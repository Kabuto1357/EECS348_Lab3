/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: k617r140/Kevin Riverss
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_PLAYS 50
#define MAX_TOUCHDOWNS MAX_PLAYS;
#define MAX_FIELDGOALS MAX_PLAYS
#define MAX_SAFETIES MAX_PLAYS

int main(){

    //Defining Constants
    const int TD_points = 6;
    const int FG_points = 3;
    const int safety_points = 2;
    const int TD2P_Conversion_pts = 8;
    const int TDFG_points = 7;

    // Max plays per game to check for
    const int MAX_TD = MAX_TOUCHDOWNS;
    const int MAX_FG = MAX_FIELDGOALS;
    const int MAX_SAFETY = MAX_SAFETIES;
    const int MAX_TD2P = MAX_TOUCHDOWNS;
    const int MAX_TDFG = MAX_TOUCHDOWNS;

    int score;
    int final_score = 0;

    printf("Press 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    
    
    do
    {
        /* code */
    } while (score != 0 || score != 1);
        printf("Goodbye.");
}
