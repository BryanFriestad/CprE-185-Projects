/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
		I was trying to make a text based rpg game that took
		advantage of reference passing.

    <Reflection 2 Were you successful? Why or Why not?>
		I do believe I was successful. I made multiple classes
		that took advantage of this strategy. While some of them
		were not %100 necessary, I believe that it set up a good
		infrastructure for the future.
		
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		I would probably just make the player stats a single array
		of integers.

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		I learned that when incrementing and using the de-reference
		symbol, you must put parenthesis around the star and the
		variable name.

	<Other questions/comments for Instructors>
        I accidentally did program practice 7 and I didn't realize
		until midnight. I stayed up extra late to make this program
		slightly fun and interesting (it's 3:05 am). I was having
		tons of issues with the string arrays in programming 
		practice #7, I will try to ask about them in class/ lab.
*/

#include <stdio.h>
#include <math.h>

//function prototypes here
void increaseMaxHealth(int *health, int *maxHeatlh, int amount);
void increaseHealth(int *health, int maxHeatlh, int amount);
void increaseXP(int *xp, int *level, int amount);
void levelUp(int *level);
void increaseAttack(int *attack, int amount);

int main(void){
	
	//player name
	char name[30];
	//player level
	int p_level = 0;
	//player xp
	int p_xp = 0;
	//player attack
	int p_att = 1;
	//player armor
	int p_armor = 0;
	//player maxHeatlh
	int p_maxHealth = 20;
	//player health
	int p_health = p_maxHealth;
	
	//welcome to the future
	printf("Welcome to the future!\n");
	
	printf("What is your name?\n");
	//scan name
	scanf(" %s", name);
	printf("Well, %s, you have just arrived in a time machine from the year 2017.\n", name);
	printf("The year is 2067 and not much has changed!\n");
	
	printf("Where would you like to visit first? (Inputs: 1 - Library, 2 - Prison, 3 - Hospital)\n");
	//scan in choice
	int choice;
	scanf("%d", &choice);
	if(choice == 1){
		printf("Not much to tell about the library. Seriously! People still read in the future...\n");
		printf("What? Doesn't everyone casually read in 2017?\n");
		printf("Just kidding *laughs hardily* reading is for nerds.\n");
		printf("Anyways, here is a free level for being a nerd, Nerd.\n");
		increaseXP(&p_xp, &p_level, 10);
	}
	else if(choice == 2){
		printf("Welcome to the prison. In 2067, a majority of crime claims are disputed and solved in a large arena called \"The City\".\n");
		printf("It may not be the prettiest solution to our problems, but it definitely keeps the prisons empty! Hah ha...\n");
		printf("Here, you'll need this bat.\n --Received Wooden Bat--\n");
		increaseAttack(&p_att, 1);
	}
	else if(choice == 3){
		printf("So, this is the hospital. And before you say anything, yes it is very run down.\n");
		printf("Public health care was abolished around 30 years ago.\n");
		printf("Just go ahead and take that health pack over there. First come first serve, right!\n");
		printf("--You take a health pack--\n");
		increaseMaxHealth(&p_health, &p_maxHealth, 5);
	}
	
	printf("Alrighty then, I'm going to cut you loose now.\n");
	printf("*Through his headset* Teleport Subject 34 to The City.\n");
	printf("Goodluck %s. Enjoy the future.\n", name);
	
	//welcome to the City, you have three options any given day
	//1: search for food, 2: fight, 3: 
	printf("\nTo be continued...\nGoodbye for now!\n");
	
	
	return 0;
}

//define functions here
void increaseMaxHealth(int *health, int *maxHeatlh, int amount){
	*maxHeatlh += amount;
	*health = *maxHeatlh;
	printf("Your maximum health is now %d\n", *maxHeatlh);
}

void increaseHealth(int *health, int maxHeatlh, int amount){
	*health += amount;
	if (*health > maxHeatlh) *health = maxHeatlh;
	printf("Your health is now %d\n", *health);
}

void increaseXP(int *xp, int *level, int amount){
	*xp += amount;
	printf("XP increase by %d.\n");
	if(*xp >= ((*level) * 10) + 10){
		*xp -= ((*level) * 10) + 10;
		levelUp(level);
	}
}

void levelUp(int *level){
	(*level)++;
	printf("\nCongrats! You are now level %d!\n\n", *level);
}

void increaseAttack(int *attack, int amount){
	*attack += amount;
	printf("Your attack is now %d\n", *attack);
}