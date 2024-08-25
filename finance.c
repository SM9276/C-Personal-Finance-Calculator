#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/************************************************************************
 * Welcome to GroSal or Grow Salary. This is a finace Calculator designed 
 * to save you money. Currently this is the backend C version of my finance app.
 * Thank you! :)
************************************************************************/
int main(int argc, char* argv[])
{
/*----------------------------------------------------------------------------
 *	The Wallet[]! This is what holds all the  values of the accounts.
 *      Below you can see which index in the wallet array
 * --------------------------------------------------------------------------*/  
    static int ARRAY_SIZE   =  64; // The Max size of the double array

    static int CHECKING     =  0;  // Standard Checking account balance
 	static int EMERGENCY    =  1;  // Emergency Fund Balance
	static int INVESTED     =  2;  // Investment Balance
	static int T_IRA        =  3;  // Traditonal IRA amount  
	static int IRA_YEAR     =  4;  // How much has been invested into IRA this year
	static int CREDITCARD   =  5;  // Credit Card Balance 
	static int NEEDSTOTAL   =  6;  // The total of all the cost of your essential needs
	static int WANTSTOTAL   =  7;  // The total of all the cost of your non-essential wants
	static int RENT_MORGAGE =  8;  // The cost of your living situation  
	static int WAGE         =  9;  // Extra income after expensises. 
		

	
	static int IRA_CAP = 7000;
	char KeyboardInput; 
	bool ProgramEnd = false;
   /*------------------------------------------------------------------------
  	wallet.txt will be read and set the diffrent amounts in the wallet array.
	if no file found then it will create and initilize the wallet array.
     ------------------------------------------------------------------------*/
	File *walletFile;
	walletFile = fopen("wallet.txt", "r");
	if(walletFile != NULL){
		double number;
		int index = 0;
		while( (number = fgetf(walletFile)) != EOF){
			Wallet[index]  = number;
			index++	
		}
	}
	else{
		for(int x = 0; x <= 64; x++){
			Wallet[x] = 0.0;
		}
	}
	fclose(walletFile);		
/**************************************************************************************
 *	One of the features i wanted to add was a need/want to differentiate my purchases
 *	The wants needs more a purchasesed bool to so you can see what you have bought
 *	I decided on using structures since it's a fun way to implement the feature i wanted.
 * **************************************************************************************/
	struct need {
		char name[255];
		float cost;
	}
	
	struct want {
		char name[255];
		float cost;
		bool purchased;
	}	
	while(ProgramEnd){
		printf("Please enter a letter.\n");
		scanf("%s",input);
		switch (input) {
        		case 'c':
				/**********************************************************************
				 * Check mode 
				 * Prints out the values of the Wallet.
				 * *******************************************************************/
            			printf("Your Checking Account is at :%d\n", Wallet[Checking] );
				printf("Your Emeregency Fund is at :%d\n",  Wallet[EmergencyFund]);
            		 break;

        		case 'i':
			 	/**************************************************************
				 * Income mode 
				 * This is the main feature that I designed this finace calculator for.
				 * First the Emergency Fund will be full which is a cap of
				 * however much the User Decides. Once that is full
				 * we move on to the years IRA ammount which is 7000 per year
				 * as of 2024. At the same time 40% of your not essentials are
				 * going to be invested. Once both are full then we will invest 80%
				 * of the extra funds. 
				 *
				 ************************************************************/
            			printf("Enter this Month Income ammount\n");
				double UserIncome;
				scanf("%f", &UserIncome);
				Wallet[Wage] = UserIncome - Wallet[Rent/Morgage] - Wallet[NeedsTotal] ; //Wage is the amount of extra income that is not spent on rent and essentials.
				
				if(EmergencyFull == true){
					if(IRAFull == true){
						Wallet[Invest] += Wallet[Wage] * .8;
						Wallet[WantsTotal] += Wallet[Wage] * .2;	
					}
					else{	
						double extra = 0.0;
						if((Wallet[IRA-Year] += Wallet[Wage] * .5) > IRA-CAP){{
							extra = Wallet[IRA-Year] - IRA-CAP;
							Wallet[IRA-Year] = IRA-CAP;
							Wallet[Checking] += extra;
						}
						Wallet[Invest] += Wallet[Wage] * .4
						Wallet[WantsTotal] += Wallet[Wage] * .1
					}
				}
				else{
					
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
				ProgramEnd = true;
			 break;

        		default:
            			printf("C is checking \n
					I is investments\n
					E add want\n
				        Q to quit\n");
            		 break;

   		}
	}
	/*************************************************************
	 * Save the values of the Wallet so it can be used next time 
	 * the User uses the calculator.
	 *************************************************************/
	
	return 0;
}
