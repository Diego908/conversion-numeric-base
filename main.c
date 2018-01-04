#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "convert.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int op, x;
	char *number;
	
	
	do{
		printf("Choose a option:\n1-Type a bin number\n2-Type a oct number\n3-Type a dec number\n4-Type a hex number\n5-Sair\n\n");
		scanf("%d", &op);
		
		system("cls");
		
		number = (char*)malloc(sizeof(char) * 30);
			
		fflush(stdin);
		
		switch(op){
			case 1:
				printf("Type the number: ");
				gets(number);
				x = convert_to_dec(number, BIN);
				printf("DEC: %d", x);
				convert_to_oct(number, BIN);
				convert_to_hex(number, BIN);
				free(number);
				getch();
				system("cls");
				break;
				
			case 2:
				printf("Type the number: ");
				gets(number);
				x = convert_to_dec(number, OCT);
				printf("DEC: %d", x);
				convert_to_bin(number, OCT);
				convert_to_hex(number, OCT);
				free(number);
				getch();
				system("cls");	
				break;
				
			case 3:
				printf("Type the number: ");
				gets(number);
				convert_to_bin(number, DEC);
				convert_to_oct(number, DEC);
				convert_to_hex(number, DEC);
				free(number);
				getch();
				system("cls");
				break;
				
			case 4:
				printf("Type the number: ");
				gets(number);
				x = convert_to_dec(number, HEX);
				printf("DEC: %d", x);
				convert_to_bin(number, HEX);
				convert_to_oct(number, HEX);
				free(number);
				getch();
				system("cls");
				break;
			
			case 5:
				
				break;
				
			default:
				printf("Invalid option!");
				system("cls");
				break;
		}
	}while(op != 5);
	
	return 0;
}
