/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: k617r140/Kevin Riverss
 */

#include <stdio.h>

int main(){

    int score;
    int final_score = 0;
     printf("Press 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);
    if(score == 0 || score ==1)
    {
     printf("Invalid Score");
    }
    else{
        for(int s = 0; s <= score/2; s++)
        for (int fg = 0; fg <=(score - s*2)/3; fg++)
            for(int td = 0; td <= (score - s*2 - fg*3)/6; td++)
                for(int tdfg = 0; tdfg <= (score - s*2 - fg*3 - td*6)/7; tdfg++)
                    for(int TD = 0; TD <= (score - s*2 - fg*3 - td*6 - tdfg*7)/8; TD++){
                        final_score = s*2+fg*3+td*6+tdfg*7+TD*8;
                if(final_score == score)
                printf("\tTDs:%d, FGs:%d, SAFETYs:%d, TD+2p:%d, TD+FG:%d\n",td, fg, s, TD, tdfg);
                }
    }
      
}


