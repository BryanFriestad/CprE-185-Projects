/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
		I was attempting to make a program for a teacher that
		can find common and useful statistics about a set of
		test scores.

    <Reflection 2 Were you successful? Why or Why not?>
        Yes, the program seems capable of determining the average
		and the range of the set of test scores. I could not
		however get the sorting method done in time, which was
		needed by the median function. This leads the function to
		simply return the middle number that was inputed rather than
		the actual median.
		
	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		Not really

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		I learned about some of the different types of sorting
		available as I searched through information in online
		articles about bubble sorts, merge sorts, etc.

	<Other questions/comments for Instructors>
        What is the fastest form of sorting?
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//function prototypes here
float getAverage(int array[], int num);
float getMedian(int array[], int num);
int getRange(int array[], int num);

int main(void){
	
	/*
	function 1 = test averaging
	function 2 = test median
	function 3 = test range
	*/
	
	int num;
	printf("Welcome to the Teacher-O-Matic. How many tests today?\n");
	scanf("%d", &num);
	int array[num];
	
	int max;
	printf("And how many points are the tests out of?\n");
	scanf("%d", &max);
	
	printf("Thank you, now please input test scores.\n");
	int i;
	for(i = 0; i < num; ++i){
		int temp;
		scanf("%d", &temp);
		if(temp <= max){
			array[i] = temp;
		}
		else{
			while(!(temp <= max)){
				printf("Not a valid test score. Please try again.\n");
				scanf("%d", &temp);
			}
			array[i] = temp;
		}
		
	}
	
	float average, median;
	int range;
	
	average = getAverage(array, num);
	median = getMedian(array, num);
	range = getRange(array, num);
	
	//print out avg, med, range--
	printf("The average test score was: %f.\n", average);
	//**FIXME**//
	printf("The median test score was: %f.\n", median);
	printf("With the test score's range being: %d\n", range);
	
	return 0;
}

//define functions here
float getAverage(int array[], int num){
	int i;
	int sum = 0;
	for(i = 0; i < num; ++i){
		sum += array[i];
	}
	return ((float) sum / (float) num);
}

float getMedian(int array[], int num){
	
	float median;
	if(num % 2 == 0){
		median = (array[num / 2] + array[(num / 2) - 1]) /2; 
	}
	else{
		median = array[num / 2];
	}
	
	return median;
}

int getRange(int array[], int num){
	
	int max = array[0];
	int min = array[0];
	int i;
	
	for(i = 0; i < num; ++i){
		if(array[i] > max){
			max = array[i];
		}
		if(array[i] < min){
			min = array[i];
		}
	}
	
	return max - min;
}
