#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "convert.h"

int string_to_int_hex(char c){
	int n;
	
	if(c == 'A' || c == 'a'){
		n = 0;
	}
	if(c == 'B' || c == 'b'){
		n = 1;
	}
	if(c == 'C' || c == 'c'){
		n = 2;
	}
	if(c == 'D' || c == 'd'){
		n = 3;
	}
	if(c == 'E' || c == 'e'){
		n = 4;
	}
	if(c == 'F' || c == 'f'){
		n = 5;
	}
			
	return n + 10;
}

void convert_with_stack(int denominator, int base){
	Stack s;

	start_stack(&s, 32, sizeof(int));
	
	int rest, n;
	
	do{
		rest = denominator % base;
		push(&s, &rest);
		denominator = denominator / base;
	}while(denominator > 0);
	
	while(!empty_stack(s)){
		pop(&s, &n);
		
		if(n == 10){
			printf("%c", 'A');
		}else if(n == 11){
			printf("%c", 'B');
		}else if(n == 12){
			printf("%c", 'C');
		}else if(n == 13){
			printf("%c", 'D');
		}else if(n == 14){
			printf("%c", 'E');
		}else if(n == 15){
			printf("%c", 'F');
		}else{
			printf("%d", n);	
		}
	}
	deallocate_stack(&s);
}

int potentiation_conversion(char num[], int base, int exp){
	int x, result = 0, i;//The "result" variable will store the result of the conversion to decimal
	
	//Loop for "break" the string and convert each char to int
	for(i = 0; i < strlen(num); i++){
		char c = num[i];
		if(c=='A' || c=='a' || c=='B' || c=='b' || c=='D' || c=='d' || c=='E' || c=='e' || c=='F' || c=='f')
			x = string_to_int_hex(c);				
		else
			x = atoi(&c);//Converting num to int
		result += x * pow(base, exp);//Makes the conversion operation
		exp--;//The expoent is decremented
	}
	return result;
}

//This function convert a number in base 10 to any base
int convert_to_dec(char num[], int base){
	int result = 0, i;
	int exp = strlen(num)-1;//Stores the size's string for use as expoent in the calcule
	
	//If is binary number
	if(base == BIN){
		result = potentiation_conversion(num, BIN, exp);
		return result;
	}
	
	if(base == OCT){
		result = potentiation_conversion(num, OCT, exp);
		return result;
	}
	
	if(base == HEX){
		result = potentiation_conversion(num, HEX, exp);
		return result;
	}
}

int convert_to_oct(char num[], int base){
	int n;
	
	if(base == BIN || base == HEX){
		n = convert_to_dec(num, base);//Converting the number to decimal for ease of operation
	}
	
	if(base == DEC){
		n = atoi(num);
	}	
	
	printf("\nOCT: ");
	convert_with_stack(n, OCT);
	
	return 0;
}

int convert_to_bin(char num[], int base){
	int n;
	char result[strlen(num)];
	
	if(base == OCT || base == HEX){
		n = convert_to_dec(num, base);//Converting the number to decimal for ease of operation
	}
	
	if(base == DEC){
		n = atoi(num);
	}	
	
	printf("\nBIN: ");
	convert_with_stack(n, BIN);
	
	return 0;
}

int convert_to_hex(char num[], int base){
	int n;
	
	if(base == BIN || base == OCT){
		n = convert_to_dec(num, base);//Converting the number to decimal for ease of operation
	}
	
	if(base == DEC){
		n = atoi(num);
	}	
	
	printf("\nHEX: ");
	convert_with_stack(n, HEX);
	
	return 0;
}
