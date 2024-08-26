/*****************************************************************************************
 *	One of the features i wanted to add was a need/want to differentiate my purchases
 *	The wants needs more a purchasesed bool to so you can see what you have bought
 *	I decided on using structures since it's a fun way to implement the feature i wanted.
 * **************************************************************************************/
struct need {
	char name[255];
	float cost;
};
	
struct want {
	char name[255];
	float cost;
	bool purchased;
};
