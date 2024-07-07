#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/************************************************************************
************************************************************************/
int main(int argc, char* argv[])
{
/*----------------------------------------------------------------------
 *	The Wallet[]! This is what holds all our fixed Qn number system.
 *
 *
 * -------------------------------------------------------------------*/  

									
    static int Checking     =  0;
 	static int Emergency    =  1;
	static int Invested     =  2;
	static int T-IRA        =  3;
	static int CC payment   =  4;
	static int NeedsTotal   =  5;
	static int WantsTotal   =  6;
	static int RENT/Morgage =  7;	
	
	char  input; 
	bool end = false;
   /*------------------------------------------------------------------------
  	wallet.txt will be read and set the diffrent amounts in the wallet array.
	if no file found then it will create and initilize the wallet array.
     ------------------------------------------------------------------------*/
	struct need {
		char name[255];
		float cost;
	}
	
	struct want {
		char name[255];
		float cost;
		int date;
		bool purchased;
	}	
	while(end){
		printf("Please enter a letter.\n");
		scanf("%s",input);
		switch (input) {
        		case 'c':
            			printf("Your Checking is at :%d\n", checkings);
            		break;

        		case 'e':
            			printf("Case 2 is Matched.");
           		break;

        		case 'i':
            			printf("Case 3 is Matched.");
            		break;

        		case 't':
            			printf("Case 3 is Matched.");
            		break;
        		
			case 'r':
            			printf("Case 3 is Matched.");
            		break;

        		case 'n':
            			printf("Case 3 is Matched.");
            		break;

        		case 'w':
            			printf("Case 3 is Matched.");
            		break;

        		case 'q':
            			printf("Case 3 is Matched.");
            		break;

        		default:
            			printf("C is checking \n
				        E is emergency\n
					I is investments\n
					T is traditional IRA\n
					R to set Rent\n
					N to add essential need\n
					W to add want\n
				        Q to quit\n");
            		break;

   		}
	}
}
