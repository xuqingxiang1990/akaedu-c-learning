#include <stdio.h>
#include <stdlib.h>

#define N  10 
#define OUT 3

struct node {
	int id;
	struct node *next;
};
typedef struct node *link;


link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;

	return p;
}

link head = NULL;
link tail = NULL;

void insert_tail(link p)
{
	
	if(head == NULL)
	{
		head = tail = p;
		return ;
	}
	tail->next = p;
	tail = p;


	return ;	
}

void traverse(link t)
{
	link p;
	p = t;
	while(p != NULL)
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}
}
void delete(link p)
{
	if(p == head)
		head = p->next;
	else
	{
		link pre;
		for(pre = head; pre != NULL; pre = pre->next)
			if(pre->next == p)
				pre->next = p->next;
	}

	free(p);
	return ;
}

int main(void)
{
	link p;
	int i, step = 0;
	int countoff = 0;
	for(i = 0; i < N; i++)
	{
		p = make_node(i + 1);
		insert_tail(p);
	}

	traverse(head);
	p = head;
	while(1)
	{
		link out;
		link save;
		step++;
		countoff++;
		printf("step %d : %d countoff:%d\n", step, p->id, countoff);
	#if 0	
		if(countoff == OUT)
		{
			countoff = 0;
			out = p;
			printf("OUR %d\n", p->id);
		}
		p = p->next;	
		if(p == NULL)
			p = head;
		if(countoff == 0)
			delete(out);
	#endif

	#if 1
	save = p;
	p = p->next;	
	if(p == NULL)
		p = head;
	if(countoff == OUT)
		{
			countoff = 0;
			printf("OUR %d\n", save->id);
			delete(save);
		}
	#endif

		if(head == NULL)
			break;
	}
	
	return 0;
}
