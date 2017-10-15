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

    //set seed value
        srand(time(0));

    //open output file
    FILE*ofp = fopen("numbers.txt", "w");

    //print primary menu
    printf("\t1) Fully-auto\n");
    printf("\t2) Semi-auto\n");
    printf("\t3) Manual\n");
    printf("\nMake your selection: ");
    scanf("%d", &ans);
    printf("\n");
    
    //begin primary switch selection
    switch(ans){

        case 1:

            //randomly generated header value up to 50
            header = rand() % 50 + 1;

            //print header value
            fprintf(ofp, "%d\n", header);

            //randomly generate range no larger than 10000
            low = rand() % 10000;
            up = rand() % 10000;
            range = abs(up - low) + 1; //calculate range
            if(low > up){ //account for potential low/up mix up

                low = up;
            }

            //print random value header times
            for(i = 1; i <= header; i++){

                curVal = rand() % range + low; //map random value to user-specified range
                fprintf(ofp, "%d\n", curVal);
            }

            break;

        case 2:

            //print secondary menu
            printf("\nWhat would you like to define?\n");
            printf("\t1) Range\n");
            printf("\t2) Set size\n");
            printf("\t3) Both\n");
            printf("\nMake your selection: ");
            scanf("%d", &ans);
            printf("\n");

            //begin secondary switch selection
            switch(ans){

                case 1:

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

                    //randomly generated header value up to 50
                    header = rand() % 50 + 1;

                    //print header value
                    fprintf(ofp, "%d\n", header);

                    //print random value header times
                    for(i = 1; i <= header; i++){

                        curVal = rand() % range + low; //map random value to user-specified range
                        fprintf(ofp, "%d\n", curVal);
                    }

                    break;

                case 2:

                    //prompt for header value
                    printf("How many values would you like?\n");
                    scanf("%d", &header);
                    printf("\n");

                    //print header value
                    fprintf(ofp, "%d\n", header);

                    //randomly generate range no larger than 10000
                    low = rand() % 10000;
                    up = rand() % 10000;
                    range = abs(up - low) + 1; //calculate range
                    if(low > up){ //account for potential low/up  mix up

                        low = up;
                    }

                    //print random value header times
                    for(i = 1; i <= header; i++){

                        curVal = rand() % range + low; //map random value to user-specified range
                        fprintf(ofp, "%d\n", curVal);
                    }

                    break;

                case 3:

                    //prompt for header value
                    printf("How many values would you like?\n");
                    scanf("%d", &header);

                    //print header value
                    fprintf(ofp, "%d\n", header);

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

                    //print random value header times
                    for(i = 1; i <= header; i++){

                        curVal = rand() % range + low; //map random value to user-specified range
                        fprintf(ofp, "%d\n", curVal);
                    }

                    break;
            }

            break;

        case 3:

            //prompt for header value
            printf("How many values would you like to input?\n");
            scanf("%d", &header);

            //print header value
            fprintf(ofp, "%d\n", header);

            //user-input
            for(i = 1; i <= header; i++){

                printf("\nWhat is value #%d?\n", i);
                scanf("%d", &curVal);
                fprintf(ofp, "%d\n", curVal);
            }

            printf("\n");

            break;
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
