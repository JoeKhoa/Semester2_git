//Faculty of Computer Science and Engineering
//Ho Chi Minh City University of Technology
//Initial code for Assignment- Programming Fundamentals
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <iostream>

const int EVENT_SIZE = 1001;
const int MAX_CHARACTER_EACH_LINE = 5001;

#define DARTAGNAN  1
#define ATHOS 2
#define PORTHOS 3
#define ARAMIS 4

typedef struct musketeer_t
{
	int ID;
	int HP; // the initial health point
	int nHealthPoint; // the current heath point
	int nGoldCoin; // the current number of gold coins
	int nDiamond; // the current number of diamonds
}musketeer;

using namespace std;

/*	Read input data from file
 *	Return value:
 *		0: fail
 *		1: successful
 */
char filename[80];

int readFile(musketeer* theMusketeer, int* M, int* N, int* nEvent, int arrEvent[])
{
	FILE* f = 0;

	char* str = (char*)malloc(MAX_CHARACTER_EACH_LINE);
	int start, len, num;

	f = fopen(filename, "r");
	if (f == NULL)
		return 0;

	//read M
	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	*M = atoi(str);

	//read N
	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	*N = atoi(str);

	//read ID
	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	theMusketeer->ID = atoi(str);

	//read nGoldCoin
	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	theMusketeer->nGoldCoin = atoi(str);

	//read nEvent, arrEvent
	*nEvent = 0;
	arrEvent[0] = 0;
    fgets(str, MAX_CHARACTER_EACH_LINE, f);

	char seps[]   = " ,\t\n";
    char *token;

    token = strtok( str, seps );
    while( token != NULL )
    {
        /* While there are tokens in "string" */
        arrEvent[*nEvent] = atoi(token);
        (*nEvent)++;
        /* Get next token: */
        token = strtok( NULL, seps );
    }

	fclose(f);

	free(str);

	return 1;
}

int calculate(char fname[])
{
	musketeer theMusketeer;
	int M, N;
	int nEvent; // the number of events
	int arrEvent[EVENT_SIZE]; // used to save events
	int theEvent, nPassedEvent; // the current event and the number of passed events
	int nOut; // output value
	int i;
    strcpy(filename, fname);
	readFile(&theMusketeer, &M, &N, &nEvent, arrEvent);
    
	theMusketeer.nDiamond = 0;
	switch (theMusketeer.ID) {
		case DARTAGNAN: // d'Artagnan
			theMusketeer.HP = 999;
			theMusketeer.nHealthPoint = 999;
			break;
		case ATHOS: // Atho
			theMusketeer.HP = 900;
			theMusketeer.nHealthPoint = 900;
			break;
		case PORTHOS: // Porthos
			theMusketeer.HP = 888;
			theMusketeer.nHealthPoint = 888;
			break;
		case ARAMIS: // Aramis
			theMusketeer.HP = 777;
			theMusketeer.nHealthPoint = 777;
			break;
		default:
			break;
	}


	nPassedEvent = 0;

	while (1) {
		for (i = 0; i < nEvent; i++) {
			theEvent = arrEvent[i];
			cout <<"the Event-"<<i+0<<" " << theEvent << '\n';
			/* use First i = 1 not 0 */
		
			if (theEvent == 0) // Gather Diamond
				theMusketeer.nDiamond++;
			else if (theEvent == 1){
				 cout << theEvent <<" ComeToInn" <<endl;
			}
			else if (theEvent == 666){
				 cout << theEvent <<" meetMilady" <<endl;
			}
			else if ( 100 <= theEvent < 200) {
				 cout << theEvent <<" fightAgainstArmy" <<endl;
			}
			else if ( 200 <= theEvent < 300) {
				 cout << theEvent <<" gambleWithNina" <<endl;
			}
			else if ( 300 <= theEvent < 400) {
				 cout << theEvent <<" faceToWhiteShark" <<endl;
			}
			else if ( 500 <= theEvent < 600) {
				 cout << theEvent <<" faceToTitan" <<endl;
			}
			else{
				 cout << theEvent <<"Error code" <<endl;
				 return -111;
			}
				
						
			///////////////////////
			// TO DO - Other Cases //
			///////////////////////
			nPassedEvent++;
			if (theMusketeer.nDiamond >= N || theMusketeer.nHealthPoint <= 0 || i >= nEvent)
				break;
		}

		if (theMusketeer.nDiamond >= N || theMusketeer.nHealthPoint <= 0 || M == 0)
			break;
	}

	switch (M) {
		case 0: // Mode 0
			if (theMusketeer.nDiamond >= N)
				nOut = theMusketeer.nHealthPoint + theMusketeer.nGoldCoin;
			else if (theMusketeer.nHealthPoint <= 0)
				nOut = -1;
			else if (i >= nEvent)
				nOut = 0;
			break;
		////////////////////////
		// TO DO - Other Modes //
		////////////////////////
		default:
			break;
	}


	return nOut;
}
int main()
{

    int nOut = calculate("input.txt");

    printf("%d\n", nOut);

    return 1;
}
