/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
		I was attempting to create a bot that creates poetry
		and outputs it to a text file. The bot does a lot of 
		random calculations for different things.

    <Reflection 2 Were you successful? Why or Why not?>
		Yes, the robot creates beautiful art with many
		different sentence types
		
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		Not really, I actually love it

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		C makes many thing very convoluted and a learned a lot
		about char*'s and 2D char arrays in general. Also pointers

	<Other questions/comments for Instructors>
		

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DEBUG 0


//function prototypes here
void generateLine(char line[], char* nouns[], int numNouns, char* adjs[], int numAdjs, char* verbs[], int numVerbs);
void printPoem(char poem[][100], int numOfLines);
int isVowel(char c);

int main(void){
	
	//seed the random function
	srand(time(NULL));
	
	//number of lines in the poem. minimum of 5 lines plus 2 for the title and empty line
	int numOfLines = (rand() % 20) + 5 + 2;
	if(DEBUG) printf("Number of lines: %d\n", numOfLines);
	
	const int numNouns = 50;
	char* nouns[] = {"dog", "cat", "bird", "frog", "love", "bus", "sun", "moon", "earth", "heart", "eye", "death",
					 "satellite", "salmon", "safety", "sage", "anxiety", "anteater", "beast", "battle", "war",
					 "beach", "breath", "brain", "lung", "breeze", "actress", "act", "affair", "addiction", "apparatus",
					 "captain", "picture", "photograph", "town", "tramp", "trade", "key", "lock", "toilet", "tear",
					 "valley", "wheelchair", "walker", "crutch", "plane", "tombstone", "wall", "vessel", "thunderstorm"};
	
	const int numVerbs = 32;
	char* verbs[] = {"expound", "expand", "assume", "justify", "ironize", "multiply", "denounce", "account",
						   "illuminate", "review", "perceive", "link", "address", "diagnose", "agree", "censure",
						   "expose", "problematize", "detect", "manipulate", "contend", "position", "guide",
						   "configure", "depict", "descend", "inform", "instruct", "isolate", "succeed", "maintain",
						   "persuade"};

	const int numAdjs = 24;
	char* adjectives[] = {"blue", "red", "dead", "lonely", "sad", "happy", "pretty", "fast", "adamant", "adriot",
						  "amatory", "contumacious", "incendiary", "hubristic", "limpid", "pendulous", "risible",
						  "tenacious", "zealous", "voracious", "withering", "loud", "nefarious", "mendacious"};
	
	if(DEBUG) printf("word lists created\n");
	
	//poem with numOfLines lines
	char poem[numOfLines][100];
	
	int i;
	//for each line, starting at line i = 2 (to leave room for title)
	//generate line by line'
	for(i = 2; i < numOfLines; ++i){
		generateLine(poem[i], nouns, numNouns, adjectives, numAdjs, verbs, numVerbs);
	}
	
	if(DEBUG) printf("poem generated successfully.\n");
	
	//find most common word
	//add title as "The ____"
	strcpy(poem[0], "The Robot by Robot\n");
	strcpy(poem[1], "\n");
	
	printPoem(poem, numOfLines);
	
	return 0;
}

//define functions here
void generateLine(char line[], char* nouns[], int numNouns, char* adjs[], int numAdjs, char* verbs[], int numVerbs){
	
	int lineType = rand() % 50;
	int nounIndex, verbIndex, adjIndex;
	
	//odds of getting this are 14 in 50
	if(lineType >= 0 && lineType < 14){
		
		nounIndex = rand() % numNouns;
		adjIndex = rand() % numAdjs;
		
		if(DEBUG) printf("noun index: %d\n", nounIndex);
		
		strcpy(line, nouns[nounIndex]);
		strcat(line, " is like a ");
		strcat(line, adjs[adjIndex]);
		nounIndex = rand() % numNouns;
		if(DEBUG) printf("noun index: %d\n", nounIndex);
		strcat(line, " ");
		strcat(line, nouns[nounIndex]);
		strcat(line, "\n");
	}
	//odds of getting this are 2
	else if(lineType >= 14 && lineType < 16){
		
		nounIndex = rand() % numNouns;
		if(DEBUG) printf("noun index: %d\n", nounIndex);
		strcpy(line, nouns[nounIndex]);
		strcat(line, "\n");
	}
	//odds of getting this are 8 in 50
	else if(lineType >= 16 && lineType < 24){
		nounIndex = rand() % numNouns;
		strcpy(line, "the ");
		strcat(line, nouns[nounIndex]);
		strcat(line, " ");
		verbIndex = rand() % numVerbs;
		strcat(line, verbs[verbIndex]);
		strcat(line, "s\n");
	}
	//odds of getting this are 10 in 50
	else if(lineType >= 24 && lineType < 34){
		strcpy(line, "and the ");
		nounIndex = rand() % numNouns;
		strcat(line, nouns[nounIndex]);
		strcat(line, ", it is ");
		verbIndex = rand() % numVerbs;
		strcat(line, verbs[verbIndex]);
		strcat(line, "ing\n");
	}
	//odds of getting this are 6 in 50
	else if(lineType >= 34 && lineType < 40){
		adjIndex = rand() % numAdjs;
		strcpy(line, adjs[adjIndex]);
		strcat(line, ": ");
		nounIndex = rand() % numNouns;
		char temp = nouns[nounIndex][0];
		if(isVowel(temp) == 1){
			strcat(line, "an ");
		}
		else{
			strcat(line, "a ");
		}
		strcat(line, nouns[nounIndex]);
		strcat(line, " feels like ");
		nounIndex = rand() % numNouns;
		temp = nouns[nounIndex][0];
		if(isVowel(temp) == 1){
			strcat(line, "an ");
		}
		else{
			strcat(line, "a ");
		}
		strcat(line, nouns[nounIndex]);
		strcat(line, ", ");
		strcat(line, adjs[adjIndex]);
		strcat(line, "\n");
	}
	//odds of getting this are 2 in 50
	else if(lineType >= 40 && lineType < 42){
		nounIndex = rand() % numNouns;
		strcpy(line, nouns[nounIndex]);
		strcat(line, "? no, we all ");
		verbIndex = rand() % numVerbs;
		strcat(line, verbs[verbIndex]);
		strcat(line, "...\n");
	}
	//odds of getting this are 8 in 50
	else if(lineType >= 42){
		strcpy(line, "\n");
	}
}

void printPoem(char poem[][100], int numOfLines){
	
	int i;
	for(i = 0; i < numOfLines; ++i){
		printf("%s", poem[i]);
	}
	fflush(stdout);
}

//returns 1 if character is a vowel, 0 if else
int isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
		return 1;
	}
	else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
		return 1;
	}
	else{
		return 0;
	}
}
