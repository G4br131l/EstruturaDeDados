#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

struct Stack {
	int maxSize;
	int top;
	int *elements;
};

Stack *Stack_alloc(int maxSize) {
	Stack *s = malloc(sizeof(Stack));
	if (s) {
		s->maxSize = maxSize;
		s->top = -1;
		s->elements = calloc(maxSize, sizeof(int));
	}
	return s;
}

void Stack_free(Stack *s) {
	if (s) {
		free(s->elements);
		free(s);
	}
}

int Stack_isEmpty(Stack *s) {
	if (s) {
		return s->top == -1;
	}
	return 1;
}

int Stack_isFull(Stack *s) {
	if (s) {
		return s->top == s->maxSize-1;
	}
	return 0;
}

void Stack_push(Stack *s, int element) {
	if (s) {
		if (!Stack_isFull(s)) {
			s->top++;
			s->elements[s->top] = element;
		}
	}
}

int Stack_pop(Stack *s){
	int element = 0;
	
	if (s) {
		if (!Stack_isEmpty(s)) {
			element = s->elements[s->top];
			s->top--;
		}
	}
	
	return element;
}

int Stack_top(Stack *s) {
	if (s) {
		return s->elements[s->top];
	}
	return 0;
}

void Stack_print(Stack *s) {
	int i;
	
	if (s) {
		for (i=s->top; i>=0; i--) {
			printf("%d\n", s->elements[i]);
		}
	}
}
