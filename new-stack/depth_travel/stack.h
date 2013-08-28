#ifndef __STACK_H_
#define __STACK_H_

struct node {
	char iterm;
	int l;
	int r;
};

void push(struct node iterm);
struct node pop(void);
int is_empty(void);
int is_full(void);
int init_stack(int sz);
void destroy_stack(void);

#endif
