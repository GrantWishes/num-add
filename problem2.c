#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM_LENGTH 10000

void add_and_print(char* num1, char* num2) {
	int index1 = -1; // length of num1 - 1: for indexing
	int index2 = -1; // length of num2 - 1: for indexing
	for(int i = 0; num1[i] != '\0'; i++) {
		index1++;
	}
	for(int i = 0; num2[i] != '\0'; i++) {
		index2++;
	} 
	char c = '4'; char d = '2';
	int e = c - d;


	
	int sum[MAX_NUM_LENGTH+1]; // just incase carry
	int temp;		   // hold the number
	int sumIndex; // indices for num1
	int carry = 0;
	
	while(index1 >= 0 && index2 >= 0) {
		printf("index1 is %d and index2 is %d\n",index1,index2);
		temp =(int)(num1[index1]-'0') +(int)(num2[index2]-'0') + carry;
		printf("Adding %c and %c and %d  = %d\n",num1[index1],num2[index2],carry,temp);
		if(temp >= 10) {
			temp = temp % 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		--index1; --index2;
		sum[sumIndex++] = temp;
}


// STATE OF THE CODE: Right now, your code is wrong. And backwards, but mainly wrong. Figure your shit out
// KDSJFL;SDFJSD;KLFJSD;KFJSD;LFJSDF;SDFJSDF
// JSFKLSDJFKSL;DJFD;SFSDJ;FKLSDFJS;
// FUCK. The backwards thing is probably just a printing error, fix the other shit
//
	int finalIndex;
	char* finalNum;

	if(index1 == index2) {
		sum[sumIndex] = -1;	
	} 
	else {
		if(index1 == 0) {
			finalIndex = index2;
			strcpy(finalNum,num2);
		}
		else {
			finalIndex = index1;
			strcpy(finalNum,num1);
		}
		printf("This should not be zero: %d %d %d\n",index1, index2, finalIndex);
	}
	while(finalIndex > 0) {
		sum[sumIndex++] = finalNum[finalIndex--] + carry;
		carry = 0;
	}
	sum[sumIndex] = -1;

	for(int i = 0; sum[i] != -1; i++){
		printf("%d",sum[i]);
	}
	printf("\n");
	
//	printf("Lengths are %d and %d\n", counter1, counter2);
//	So type conversion isn't really required. Just add last digits, take the second one (somehow), have a carry toggle 1 or 0 to add on next one.
}

int main (int argc , char * argv []) {
//	FILE *file = fopen("problem2.input","r");
	FILE *file = fopen("fakeInput.input","r");
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

