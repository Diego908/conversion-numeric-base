//HEADER
#define ERROR_FULL_STACK -1
#define ERROR_EMPTY_STACK -2

typedef struct{
	void **data;
	int capacity, top;
	int info_size;
}Stack;

void start_stack(Stack *s, int c, int info_size);
int push(Stack *s, void *info);
int pop(Stack *s, void *info);
void show_stack(Stack, void(*show_info)(void*));
void deallocate_stack(Stack *s);
int full_stack(Stack s);
int empty_stack(Stack s);
