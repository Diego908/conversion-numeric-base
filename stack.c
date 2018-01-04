#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void start_stack(Stack *s, int c, int info_size){
	s->data = (void**)malloc(sizeof(void*)*c);
	s->capacity = c;
	s->top = -1;
	s->info_size = info_size;
}
int empty_stack(Stack s){
	return s.top == -1;
}
int full_stack(Stack s){
	return s.top == s.capacity - 1;
}

int push(Stack *s, void *info){
	if(full_stack(*s))
		return ERROR_FULL_STACK;

	s->top++;
	s->data[s->top] = (void*)malloc(s->info_size);
	memcpy(s->data[s->top], info, s->info_size);
	
	return 1; //Sucess
}
int pop(Stack *s, void *info){
	if(empty_stack(*s))
		return ERROR_EMPTY_STACK;
		
	memcpy(info, s->data[s->top], s->info_size);
	free(s->data[s->top]);
	s->top--;
	
	return 1; //Sucess
}
void show_stack(Stack s, void(*show_info)(void*) ){
	if(empty_stack(s))
		printf("Empty!");
	else{
		printf("Stack Data:\n");
		int i;
		for(i=0;i<=s.top;i++){
			show_info(s.data[i]);
		}
	}	
}
void deallocate_stack(Stack *s){
	free(s->data);
}
