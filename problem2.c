#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_LENGTH 10000

void add_and_print(char* num1, char* num2) {
	int index1 = -1; // length of num1 - 1: for indexing later on
	int index2 = -1; // length of num2 - 1: for indexing later on
	for(int i = 0; num1[i] != '\0'; i++) { // getting the length of both numbers
		index1++;
	}
	for(int i = 0; num2[i] != '\0'; i++) {
		index2++;
	} 
	

	int *sum;  // the final sum array. I think just declaring sum[MAX_NUM_LENGTH+1] works too
	           // but I tried to fix a bug this way and just left it as is.
	sum = calloc(MAX_NUM_LENGTH+1,sizeof(int));

	int temp;	  // hold the digit to be added
	int sumIndex = 0; // the index of where to add the number (will go into array backwards)
	int carry = 0;
	
	// This while loop adds numbers up until the smaller number runs out of digits
	while(index1 >= 0 && index2 >= 0) {
		temp =(int)(num1[index1]-'0') +(int)(num2[index2]-'0') + carry; // casting black magic
		if(temp >= 10) {                 // if there is a carry
			temp = temp % 10;
			carry = 1;
		}
		else {                           // if there is no carry
			carry = 0;
		}
		--index1; --index2;
		sum[sumIndex++] = temp;          // add the number in the backwards array
	}	


	// If both numbers were the same length, we're pretty much done here.
	if(index1 == index2) {
		sum[sumIndex] = -1;	
	} 
	// ... if not, we need to add the rest of the digits (plus maybe a carry) to the sum
	else {
		if(index1 == -1 ) {              // if the second number is bigger (don't ask about the order)
			while(index2 >= 0) {
				temp = (int)(num2[index2]-'0') + carry;
				sum[sumIndex++] = temp;
				carry = 0;
				--index2;
			}
		}
		else {                           // if the first number is bigger
			while(index1 >=0) {
				temp = (int)(num1[index1]-'0') + carry;
				sum[sumIndex++] = temp;
				carry = 0;
				--index1;
			}
		}
	}

	sum[sumIndex] = -1;                      // add this marker so we know where the front is (regretting not making a stack right now)

	int endIndex = 0;                       

	while(sum[endIndex] != -1){              // find the end of the array, save it.
		endIndex++;
	}

	for(int i = endIndex-1; i>=0; i--){      // print out the numbers, this time, in the correct order.
		printf("%d",sum[i]);
	}

	free(sum);
	printf("\n");
//	printf("Lengths are %d and %d\n", counter1, counter2);
//	So type conversion isn't really required. Just add last digits, take the second one (somehow), have a carry toggle 1 or 0 to add on next one.
}

int main (int argc , char * argv []) {
	FILE *file = fopen("problem2.input","r");
	if (file == NULL) {
		printf("Input file not found.\n");
		return 1;
	}
	char num1[MAX_NUM_LENGTH];
	char num2[MAX_NUM_LENGTH];
	while(fscanf(file, "%s %s", num1, num2) == 2) {
		add_and_print(num1, num2);
	}
	fclose(file);	
	return 0 ;
}

