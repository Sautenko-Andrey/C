#ifndef STACK_ADT_H
#define STACK_ADT_H

#include<stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack data);
void make_empty(Stack data);
bool is_empty(Stack data);
bool is_full(Stack data);
void push(Stack data, int i);
int pop(Stack data);

#endif