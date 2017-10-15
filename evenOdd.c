/*
    Patrick Blackmore
    Generates random values in a text document then
    determines whether each number is even or odd
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){

    //variables
    int up = 0, low = 0, range = 0, i, curVal = 0, header = 0;
    char ans;

    //prompt for number of values
    printf("Random or predetermined # of values? R/P\n");
    scanf(" %c", &ans);
    if(ans == 'P' || ans == 'p'){

        //user specified header value
        printf("How many random values would you like?\n");
        scanf("%d", &header);
    }else{

        //randomly generated header value
        srand(time(0));
        header = rand() % 25 + 1;
    }

    //prompt for range
    printf("Lower range?\n");
    scanf("%d", &low);
    printf("Upper range?\n");
    scanf("%d", &up);
    printf("\n");
    range = abs(up - low) + 1; //calculate range
    if(low > up){ //account for potential user-input error

        low = up;
    }

    //open output file
    FILE*ofp = fopen("numbers.txt", "w");

    //print header value
    fprintf(ofp, "%d\n", header);

    //print random number header times
    for(i = 1; i <= header; i++){

        curVal = rand() % range + low; //map random value to user-specified range
        fprintf(ofp, "%d\n", curVal);
    }

    //close output file
    fclose(ofp);

    //reset variables, just for shits and giggles
    curVal = 0;
    header = 0;

    //open input file and read header value
    FILE*ifp = fopen("numbers.txt", "r");
    fscanf(ifp, "%d", &header);

    //evaluate header number of values as even or odd
    for(i = 1; i <= header; i++){

        fscanf(ifp, "%d", &curVal);
        if(curVal % 2 == 0){

            printf("Value %4d: %4d is even\n", i, curVal);
        }else{

            printf("Value %4d: %4d is odd\n", i, curVal);
        }
    }

    //close input file
    fclose(ifp);

    return 0;
}
