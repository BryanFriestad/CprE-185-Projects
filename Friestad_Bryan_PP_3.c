/*	Bryan Friestad
        bryanf@iastate.edu
        CPRE 185 Section Z

Programming Practice 2

	<Reflection 1 What were you trying to learn or achieve?>
        I was trying to make a program that can first take in a number
		from the user and then proceed to find all of the perfect numbers
		between zero and that number. A perfect number is defined by a
		number in which all of the factors (except for the number)
		add up to the number itself. Some examples of perfect numbers
		are 6(1 + 2 + 3 = 6) and 28(1 + 2 + 4 + 7 + 14 = 28).

    <Reflection 2 Were you successful? Why or Why not?>
		Yes, it found perfect numbers up to the integer limit if 
		given enough time. I also tested it with and without the
		boolean operators for finding easy already-known perfect
		numbers.
        

	<Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
		I would potentially try and cut down some of the operations 
		or loops to see if I could decrease the amount of time
		needed to find each perfect number. For example I could
		have only gone to num / 2 in the for loop in the function
		called "isPerfectNumber". You know that the biggest whole
		factor any number could have (other than itself) is half
		of the original number, so you don't have to check all 
		of the numbers above it. I also could start at a number
		above 8128 and then just print out the lower perfect numbers
		in order to save time.

	<Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
		The collaboration that is possible between functions, loops,
		boolean logic and nested loops can be very simplistic, yet
		powerful. I truly think that this is an awesome program to
		showcase that fact. I also remembered after a long hour of
		panicing on Monday that the programming practices were due
		midnight on Tuesdays and not on Mondays!

	<Other questions/comments for Instructors>
        
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//function prototypes here
bool isPerfectNumber(int num);

int main(void){
	
	int limit;
	printf("Enter a limit to search for perfect numbers under.\n");
	scanf("%d", &limit);
	
	int i;
	for(i = 1; i <= limit; i++){
		if(isPerfectNumber(i)){
			printf("%d is a perfect number\n", i);
		}
	}
	
	printf("Thank you for furthering science!\n");
	
	return 0;
}

//define functions here
bool isPerfectNumber(int num){
	int i;
	int sum = 0;
	
	//for already known perfect numbers
	if((num == 1) || (num == 6) || (num == 28) || (num == 496) || (num == 8128)){
		return true;
	}
	
	//if not a known perfect number, check 
	for(i = 1; i < num - 1; i++){
		if(num % i == 0){
			sum = sum + i;
		}
	}
	if(sum == num){
		return true;
	}
	else{
		return false;
	}
}
