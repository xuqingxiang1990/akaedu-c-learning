#ifndef __QUEUE_H_
#define __QUEUE_H_

struct node {
	char item;
	int l;
	int r;
};

typedef struct node node_t;

extern node_t *queue;
extern int size;
extern int qc;
extern int head;
extern int tail;

void init_queue(int sz);

void enter_queue(node_t ch);

node_t out_queue(void);

int is_empty(void);

int is_full(void);

void destroy(void);



#endif
