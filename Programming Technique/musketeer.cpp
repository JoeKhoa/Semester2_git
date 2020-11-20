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
	int mythril; // win Greate White Shark then awarded
	int winGamble3Time; // win gamble over Nina Merchant 3 time => free to stay Inn
}musketeer;

void printMusketeerStatus( musketeer_t theMusketeer);
int fightRule( musketeer_t theMusketeer, int theEvent, int eventIndex);
int fightArmyRuleOnlyForAthos( musketeer_t theMusketeer, int theEvent, int eventIndex);
int soNguyenTo(int soA);

musketeer_t  getDiamond( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  comeInn( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  meetMilady( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  fightAgainstArmy( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  gambleWithNina( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  faceToWhiteShark( musketeer_t theMusketeer, int theEvent, int eventIndex);
musketeer_t  faceToTitan( musketeer_t theMusketeer, int theEvent, int eventIndex);




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
	//~ int start, len, num;

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

	theMusketeer.mythril = 0;
	theMusketeer.winGamble3Time = 0;
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

//~ musketeer_t  getDiamond( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  comeInn( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  meetMilady( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  fightAgainstArmy( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  gambleWithNina( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  faceToWhiteShark( musketeer_t theMusketeer, int theEvent, int eventIndex);
//~ musketeer_t  faceToTitan( musketeer_t theMusketeer, int theEvent, int eventIndex);

	printMusketeerStatus(theMusketeer);


	nPassedEvent = 0;
	while (1) {
		for (i = 0; i < nEvent; i++) {
			cout << "************************** " << " Event no=" << nPassedEvent+1 <<endl;
			//~ theEvent = arrEvent[i];
			//~ for(int i=0; i < nEvent; i++){
				//~ cout << arrEvent[i] << endl;

			//~ }
			//~ cout << endl;
			//~ cout << arrEvent[i] << endl;
				

			/* use First i = 1 not 0 */
			int eventIndex;
			eventIndex = nPassedEvent + 1;
			// Gather Diamond
			theEvent = arrEvent[i];
			if (theEvent == 0){
				cout << i+1<<". "<< theEvent <<" getDiamond" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = getDiamond(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);
			}

			else if (theEvent == 1){
				cout << i+1<<". "<< theEvent <<" comeInn" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = comeInn(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);
			}
			else if (theEvent == 666){
				cout << i+1<<". "<< theEvent <<" meetMilady" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = meetMilady(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);
			}
			else if((100 <= theEvent) && (theEvent < 200)){
				cout << i+1<<". "<< theEvent <<" fightAgainstArmy" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = fightAgainstArmy(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);				 
			}
			else if((200 <= theEvent) && (theEvent < 300)){
				 cout << i+1<<". "<< theEvent <<" gambleWithNina" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = gambleWithNina(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);				 
			}
			else if((300 <= theEvent) && (theEvent  < 400)){
				 cout << i+1<<". "<< theEvent <<" faceToWhiteShark" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = faceToWhiteShark(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);				 
			}
			else if((500 <= theEvent) && (theEvent < 600)){
				cout << i+1<<". "<< theEvent <<" faceToTitan" <<endl;
				printMusketeerStatus(theMusketeer);
				theMusketeer = faceToTitan(theMusketeer, theEvent, eventIndex);
				printMusketeerStatus(theMusketeer);				 
			}
			else{
				 cout << i+1<<". "<< theEvent <<" is invalid code" <<endl;
				 //~ return -111;
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
			if (theMusketeer.nDiamond >= N){
				cout << endl <<endl <<"--- Total R = nHealthPoint + nGoldCoin  = " ;// NO more code here!!!;
				nOut = theMusketeer.nHealthPoint + theMusketeer.nGoldCoin;
			}
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



musketeer_t  getDiamond(musketeer_t theMusketeer, int theEvent, int nPassedEvent){
	theMusketeer.nDiamond ++;
	return theMusketeer;
}



musketeer_t  comeInn( musketeer_t theMusketeer, int theEvent, int nPassedEvent){
	if(theMusketeer.winGamble3Time >=3){
		theMusketeer.nHealthPoint = theMusketeer.HP;
		return theMusketeer;
	}
	int coin = theMusketeer.nGoldCoin;
	theMusketeer.nGoldCoin = 0;

	if (coin > 0){
		if (theMusketeer.ID != PORTHOS)
			theMusketeer.nHealthPoint += coin;
		else
			theMusketeer.nHealthPoint += coin/2;
	}
	if(theMusketeer.nHealthPoint >theMusketeer.HP){
		theMusketeer.nHealthPoint = theMusketeer.HP;
	}
	 
	return theMusketeer;
}	


musketeer_t  meetMilady( musketeer_t theMusketeer, int theEvent, int eventIndex){
	switch (theMusketeer.ID) {
		case DARTAGNAN: // win
				theMusketeer.nHealthPoint = 0;
			break;
		case ATHOS: // Lose
				theMusketeer.nGoldCoin = 999;
			break;
		case ARAMIS: // tie (1-1)
			for(int i = theMusketeer.nHealthPoint; i>0; i--){
				if(soNguyenTo(i) == 1){
					cout <<"so nguyen to: "<< i << endl;
					theMusketeer.nHealthPoint = i;
					break;

				}
				else{
					cout <<"khong nguyen to: " << i << endl;
				}

			}
			break;
		default:
				break;	
	}


	return theMusketeer;
}


musketeer_t  fightAgainstArmy( musketeer_t theMusketeer, int theEvent, int eventIndex){
	int fightWin = 0;
	if (theMusketeer.ID == ATHOS)
		fightWin= fightArmyRuleOnlyForAthos(theMusketeer, theEvent, eventIndex);
	else
		fightWin = fightRule(theMusketeer, theEvent, eventIndex);
	
	switch (fightWin) {
		case 1: // win
			if (theEvent < 999)
				theMusketeer.nGoldCoin +=theEvent;
			else
				theMusketeer.nGoldCoin +=999;
			
			break;
		case -1: // Lose
			if(theMusketeer.mythril == 1)
				theMusketeer.nHealthPoint -=theEvent/10;
			else
				theMusketeer.nHealthPoint -=theEvent;
			break;
		case 0: // tie (1-1)
			cout << "tie game" << endl;
			break;
		default:
				break;	
	}
	return theMusketeer;
}	


musketeer_t  gambleWithNina( musketeer_t theMusketeer, int theEvent, int eventIndex){
	int fightWin = 0;
	fightWin = fightRule(theMusketeer, theEvent, eventIndex);
	switch (fightWin) {
		case 1: // win
			theMusketeer.winGamble3Time +=1;
			theMusketeer.nGoldCoin *=2;
			if(theMusketeer.nGoldCoin > 999){
				theMusketeer.nGoldCoin = 999;
			}
			break;
		case -1: // Lose
			theMusketeer.nGoldCoin /=2;
			break;
		case 0: // tie (1-1)
			cout << "tie game" << endl;
			break;
		default:
				break;	
	}
	return theMusketeer;
}	


musketeer_t  faceToWhiteShark( musketeer_t theMusketeer, int theEvent, int eventIndex){
	if(theMusketeer.mythril == 1){
		return theMusketeer;
	}
	int fightWin = 0;
	fightWin = fightRule(theMusketeer, theEvent, eventIndex);
	switch (fightWin) {
		case 1: // win
		theMusketeer.mythril = 1;
			break;
		case -1: // Lose
			theMusketeer.nDiamond = 0;
			break;
		case 0: // tie (1-1)
			cout << "tie game" << endl;
			break;
		default:
				break;	
	}
	return theMusketeer;
}	


musketeer_t  faceToTitan( musketeer_t theMusketeer, int theEvent, int eventIndex){
	int fightWin = 0;
	if (theMusketeer.ID == PORTHOS)
		return theMusketeer;
	else
		fightWin = fightRule(theMusketeer, theEvent, eventIndex);
	
	switch (fightWin) {
		case 1: // win
			cout << "Titan have no gold" << endl;
			break;
		case -1: // Lose
			if(theMusketeer.mythril == 1)
				theMusketeer.nHealthPoint -=theEvent/10;
			else
				theMusketeer.nHealthPoint -=theEvent;
			break;
		case 0: // tie (1-1)
			cout << "tie game" << endl;
			break;
		default:
				break;	
	}
	return theMusketeer;
}	





void printMusketeerStatus(musketeer_t theMusketeer){
	/* print all attribute */
	cout << "ID : " << theMusketeer.ID <<  endl;
	cout << "nHealthPoint : " << theMusketeer.nHealthPoint <<endl;
	cout << "nGoldCoin : " << theMusketeer.nGoldCoin <<  endl;
	cout << "nDiamond : " << theMusketeer.nDiamond <<endl;
	cout << "mythril : " << theMusketeer.mythril <<  endl;
	cout << "winGamble3Time : " << theMusketeer.winGamble3Time <<endl;
	cout << ": ------------------------ :" <<endl;
	return;
}

int fightRule( musketeer_t theMusketeer, int theEvent, int eventIndex){
	int h1, h2;
	h1 = eventIndex%100;
	h2 = theEvent%100;

	if(h1 > h2){
		cout << "(^-^) win" << endl<< endl;
		return 1;
	}
	else if(h1 < h2){
		cout << "(+_-) lose" << endl<< endl;
		return -1;
	}
		else{
		cout << "(^~^) tie" << endl<< endl;
		return 0;
	}
		
}


int fightArmyRuleOnlyForAthos( musketeer_t theMusketeer, int theEvent, int eventIndex){
	int h1, h2;
	h1 = eventIndex%100;
	h2 = theEvent%100;

	if(h1 > h2){
		cout << "(^-^) win" << endl<< endl;
		return 1;
	}
	else if(h1 < h2){
		if(h2<=5){
		cout << "(^~^) tie" << endl<< endl;
		return 0;
		}
		else{
			cout << "(+_-) lose" << endl<< endl;
			return -1;
		}	
	}
	else{
		cout << "(^~^) tie" << endl<< endl;
		return 0;
	}
}


int soNguyenTo(int soA)
{
    if (soA < 2)    
        return 0;

    for (int i = 2; i <= sqrt((float)soA); i ++)
    {
        if (soA%i==0)
        {
            return 0;
        }
    }
    return 1;
}


/* 
 * 
 *  object stack  + obj_heap(create by "new", e.g: new obj1 ) ???
 * /object trong stack -> het tam vuc -> huy
 * 
 * khoi tao new
 * huy delete
 * shalow copy =  p2 = p1, p3(p1)
 * khoi tao + sao chep : copy contructors

*** if have pointer + user p2(p1) => p2.pt = p1.pt ( delete p1 => p2.pt = dummy) 
* 	=> not copy full ( only memory add) => SHALOW
 
 Q: ???
 * p = class;
 * p = class();
 * 
 STATIC 
 
 class::static_method();
*/

