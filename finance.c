#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/************************************************************************
************************************************************************/
int main(int argc, char* argv[])
{
   /*------------------------------------------------------------------------
   
     ------------------------------------------------------------------------*/
	float checkings  = 0.0;
 	float emergency  = 0.0;
	float invested   = 0.0;
	float TIRA       = 0.0;
	float rent    =  650.0;
	float needsTotal = 0.0;
	float wantsTotal = 0.0;
	float CC payment = 0.0;
	char  input; 
	bool end = false;
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
		scanf("%s",input)
		switch (input) {
        		case 'c':
            			printf("Case 1 is Matched.");
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
