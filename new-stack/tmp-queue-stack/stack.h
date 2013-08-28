#ifndef __STACK_H_
#define __STACK_H_

struct node {
	char item;
	int l;
	int r;
};
typedef struct node node_t;

extern node_t *stack;
extern int top;
extern int size;

void init_stack(int sz);
void push(node_t item);
node_t pop(void);
void destroy();
int is_empty(void);
int is_full(void);



#endif
