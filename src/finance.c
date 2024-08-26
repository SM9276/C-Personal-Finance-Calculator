#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

#include "fileio.h"

/*********************************************************************************
 * Welcome to GroSal or Grow Salary. This is a finace Calculator designed 
 * to save you money. Currently this is the backend C version of my finance app.
 * Thank you! :)
*********************************************************************************/
int main(int argc, char* argv[])
{
/*********************************************************************************
 *	The Wallet[]! This is what holds all the  values of the accounts.
 *      Below you can see which index in the wallet array
 * ******************************************************************************/  
    static const int   ARRAY_SIZE   =  64;              // The Max size of the double array
    static const char* FILE_NAME    =  "wallet.txt";    // The File Name where wallet will be stored

    static const int CHECKING     =  0;  // Standard Checking account balance
 	static const int EMERGENCY    =  1;  // Emergency Fund Balance
	static const int INVESTED     =  2;  // Investment Balance
	static const int T_IRA        =  3;  // Traditonal IRA amount  
	static const int IRA_YEAR     =  4;  // How much has been invested into IRA this year
	static const int CREDITCARD   =  5;  // Credit Card Balance 
	static const int NEEDSTOTAL   =  6;  // The total of all the cost of your essential needs
	static const int WANTSTOTAL   =  7;  // The total of all the cost of your non-essential wants
	static const int RENT_MORGAGE =  8;  // The cost of your living situation  
	static const int WAGE         =  9;  // Extra income after expensises. 
	

	static const int IRA_CAP = 7000; // The IRS cap on the IRA
	
    //Variable Declaration
    char KeyboardInput;
	bool ProgramEnd     = true;
    bool emergencyFull  = false;
    bool iraFull        = false; 
    
    //Wallet Initialization
    double* Wallet = readMemoryDoubleArray(ARRAY_SIZE, FILE_NAME);
    if (Wallet == NULL){
        fprintf(stderr, "Error reading the array from Memory\nCreating a empty Wallet\n");
        
        Wallet = declareDoubleArray(ARRAY_SIZE);
        if(Wallet == NULL){
            fprintf(stderr,"Error Creating Array at line:%d",__LINE__);
            exit(1);
        } 
        for(int i = 0; i < ARRAY_SIZE; i++){
            Wallet[i] = 0.0;
        }
    }

	while(ProgramEnd){
		printf("Please enter a letter.\n");
		scanf("%c",&KeyboardInput);
		switch(KeyboardInput) {
                /**********************************************************************
                 * Check mode:
                 * Prints out the values of the Wallet.
                 * *******************************************************************/
        		case 'c':
            	    printf("Your Checking Account is at :%lf\n", Wallet[CHECKING] );
				    printf("Your Emeregency Fund is at :%lf\n",  Wallet[EMERGENCY]);
                    
                   break;
                
                /**************************************************************
                 * Income mode: 
                 * This is the main feature that I designed this finace calculator for.
                 * First the Emergency Fund will be full which is a cap of
                 * however much the User Decides. Once that is full
                 * we move on to the years IRA ammount which is 7000 per year
                 * as of 2024. At the same time 40% of your not essentials are
                 * going to be invested. Once both are full then we will invest 80%
                 * of the extra funds. 
                 *
                 ************************************************************/
        		case 'i':
            	printf("Enter this Month Income ammount\n");
				double UserIncome;
				scanf("%lf", &UserIncome);
				Wallet[WAGE] = UserIncome - Wallet[RENT_MORGAGE] - Wallet[NEEDSTOTAL] ; //Wage is the amount of extra income that is not spent on rent and essentials.
				
				if(emergencyFull == true){
					if(iraFull == true){
						Wallet[INVESTED] += Wallet[WAGE] * .8;
						Wallet[WANTSTOTAL] += Wallet[WAGE] * .2;	
					}
					else{	
						double extra = 0.0;
						if((Wallet[IRA_YEAR] += Wallet[WAGE] * .5) > IRA_CAP){
							extra = Wallet[IRA_YEAR] - IRA_CAP;
							Wallet[IRA_YEAR] = IRA_CAP;
							Wallet[CHECKING] += extra;
						    }
						Wallet[INVESTED] += Wallet[WAGE] * .4;
						Wallet[WANTSTOTAL] += Wallet[WAGE] * .1;
					}
				    
                }
           		break;

        		case 'e':
			 	/******************************************************************
				 * Edit mode 
				 * You can add and remove needs/wants at will
				 * This is also useful when first initilizing all the values of the Wallet.
				 ****************************************************************/
            			printf("Edit the Wallet!");
            		 break;

			    case 'q': 
			 	/****************************************
				 * Quit mode
				 * *************************************/
				    printf("See you later! You can do it! ");
				    ProgramEnd = false;
			       break;

        		default:
            		printf("c is checking\ni is investments\ne edit Wallet\nq to quitn");
            	   break;

   		    }
	    }
	/*************************************************************
	 * Save the values of the Wallet so it can be used next time 
	 * the User uses the calculator.
	 *************************************************************/
    writeMemoryDoubleArray(Wallet, ARRAY_SIZE, FILE_NAME);
    free(Wallet);
	return 0;
}
