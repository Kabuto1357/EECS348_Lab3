/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: k617r140/Kevin Riverss
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_PLAYS 3
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

    while (score != 0 && score !=1)
    {
        for (int TD = 0; TD < MAX_TD; TD++)
        {
            for (int FG = 0; FG < MAX_FG; FG++)
            {
                for (int safety = 0; safety < MAX_SAFETY; safety++)
                {
                    for (int TD2P = 0; TD2P < MAX_TD2P; TD2P++)
                    {
                        for (int TDFG = 0; TDFG < MAX_FG; TDFG++)
                        {   
                        final_score = MAX_TD*TD + MAX_FG*FG + MAX_SAFETIES*safety + MAX_TD2P*TD2P + MAX_FG*TDFG;
                        if(final_score == score){
                            printf("\tTDs:%d, FGs:%d, SAFETYs:%d, TD+2p:%d, TD+FG:%d\n",TD, FG_points, safety, TD2P, TDFG);

                        }
                        }
                    }
                    
                }
                
            }
        }
        
        }
        
        printf("Press 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
    }


