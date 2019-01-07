/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
        I am trying to create a program that will simply help me
		practice boolean-logic operators. I will design a program
		that will simulate a battle between two "bots" and determine
		the winner using boolean-logic.

    <Reflection 2 Were you successful? Why or Why not?>
        Yes, the program worked as expected and I used boolean-logic
		operators in new and challenging ways.

	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		I think if I could start again, I would do something a little
		less convoluted and confusing, it took me significantly longer
		than I originally thought it would because I didn't know exactly
		how to implement my idea, but I also didn't want to give up on it.
		It is not all bad though, it was still interesting.

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
        I learned that even when you are just messing around and
		making a simple program to fit a couple of objectives,
		it can be very helpful to plan out what you are going
		to do beforehand.

	<Other questions/comments for Instructors>
        Is the use of conditional expressions here considered
		bad taste? Also I was having some issues with Cygwin not
		letting me run my executable after compiling it, which I
		did not previously have an issue with. This caused me to not
		be able to test my program. :/
*/

#include <stdio.h>
#include <math.h>

//function prototypes here
int fightBots(int bot1_health, int bot1_dmg, int bot2_health, int bot2_dmg);
void fightResult(int fightOut);

int main(void){
	
	int bot1_health;
	int bot1_dmg;
	int bot2_health;
	int bot2_dmg;
	
	printf("Enter first robot's health and then damage, seperated by a space.\n");
	scanf("%d %d", &bot1_health, &bot1_dmg);
	printf("Enter second robot's health and then damage, seperated by a space.\n");
	scanf("%d %d", &bot2_health, &bot2_dmg);
	
	while(bot1_health != -1 && bot1_dmg != -1 && bot2_health != -1 && bot2_dmg != -1){
		fightResult(fightBots(bot1_health, bot1_dmg, bot2_health, bot2_dmg));
		printf("Enter first robot's health and then damage, seperated by a space(Enter -1 to end).\n");
		scanf("%d %d", &bot1_health, &bot1_dmg);
		printf("Enter second robot's health and then damage, seperated by a space.\n");
		scanf("%d %d", &bot2_health, &bot2_dmg);
	}
	printf("Thanks for playing! And remember the first rule of bot fighting.\n");
	
	return 0;
}

//define functions here
int fightBots(int bot1_health, int bot1_dmg, int bot2_health, int bot2_dmg){
	if((bot1_health == bot2_health) && (bot1_dmg == bot2_dmg)){
		//if bots have same health and damage, they tie
		return 3;
	}
	else if(bot1_health == bot2_health){
		//if both bots have the same health, the one with the most damage wins
		return (bot1_dmg > bot2_dmg) ? 1 : 2;
	}
	else if(bot1_dmg == bot2_dmg){
		//if both bots have the same damage, the one with the most health wins
		return (bot1_health > bot2_health) ? 1 : 2;
	}
	else{
		//if none has a clear advantage...
		while((bot1_health > 0) && (bot2_health > 0)){
			//have bots attack until one or both dies
			bot1_health -= bot2_dmg;
			bot2_health -= bot1_dmg;
		}
		//then turn which one had the highest health
		return (bot1_health > bot2_health) ? 1 : 2;
	}
	
}

void fightResult(int fightOut){
	//use switch
	//cases for bot 1, bot 2, and a tie
	switch(fightOut){
		
		case 1:
			printf("Bot 1 is the winner!! Congrats m8\n");
			break;
			
		case 2:
			printf("Bot 2 is the winner!! Congrats m8\n");
			break;
			
		case 3:
			printf("The robots were 2 evenly matched 4 each other. It's a tie!!\n");
			break;
			
		default:
			printf("Error occured. You have broken the program. :'(\n");
			break;
	}
}
