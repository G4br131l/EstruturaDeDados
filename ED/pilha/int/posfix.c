#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Stack.h"
#define SIZE 256

char *posfix(char *in);
int evaluate(char *expression);

int main() {
	char  exp[SIZE] = "((2*3)+(8/4))";
	char *expPos = NULL;
	int   res = 0;
	
	expPos = posfix(exp);
	res    = evaluate(expPos);
	
	printf("Notação posfixa: %s\n", expPos);
	printf("Avaliação: %d\n", res);
	
	return 0;
}

char *posfix(char *in) {
	Stack  *s = Stack_alloc(SIZE);
	char *out = malloc(SIZE);
	int i, j;
	
	for (i = 0; in[i]; i++) {
		if (isdigit(in[i])) {
			out[j++] = in[i];
		}
		else if (strchr("+*-/", in[i])) {
			Stack_push(s, in[i]);
		}
		else if (in[i] == ')') {
			out[j++] = Stack_pop(s);
		}
	}
	out[j] = '\0';
	Stack_free(s);
	
	return out;
}

int evaluate(char *expression) {
	Stack *stack = Stack_alloc(strlen(expression));
	int i, x, y, z;
	
	for (i = 0; expression[i]; i++) {
		if (isdigit(expression[i])) {
			Stack_push(stack, expression[i] - '0');
		}
		else {
			y = Stack_pop(stack);
			x = Stack_pop(stack);
			switch (expression[i]) {
				case '+': Stack_push(stack, x+y); break;
				case '-': Stack_push(stack, x-y); break;
				case '*': Stack_push(stack, x*y); break;
				case '/': Stack_push(stack, x/y); break;
			}
		}
	}
	
	z = Stack_pop(stack);
	Stack_free(stack);
	
	return z;
}
