#include <stdio.h>
#include <stdlib.h>
#define N	9 
#define OUT 3

struct node {
	int id;
	struct node *next;
};

typedef struct node *link;

link head = NULL;
link tail = NULL;

link make_node(int id)
{
	link p ;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;

	return p;
}

void insert_tail(link t)
{
	link p = NULL;	
	p = t;
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
	while( p != NULL)
	{
		printf("%d\n", p->id);
		p = p->next;
	}	
}

void delete(link p)
{
	link pre;
	if(p == head)
		head = p->next;
	else
	{
		for(pre = head; pre != NULL; pre = pre->next)
			if(pre->next == p)
				pre->next = p->next;
	}

	free(p);
	return ;
}

link reverselist(link head)
{
	link p1, p2, p3;
	if(head == NULL || head->next == NULL)
		return NULL;
	p1 = head;
	p2 = p1->next;
	p3 = p2->next;
	p1->next = NULL;
	while(p3 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}

	p2->next = p1;
	head = p2;
	#if 0
	while(head != NULL)
	{
		printf("head->id = %d\n", head->id);
		head = head->next;
	}
	#endif
	return head;

}


int main(void)
{
	link p;
	link out;
	int step = 0;
	int counter = 0;
	int i;
	for(i = 0; i < N; i++)
	{
		p = make_node(i + 1);
		insert_tail(p);
	}
	traverse(head);
	printf("倒序后\n");

	p = NULL;
	p = reverselist(head);
	traverse(p);
	//p = head;
	#if 0
	while(1)
	{
		link out;
		step++;
		counter++;
		printf("step = %3d  : %3d counter = %d\n", step, p->id, counter);
		if(counter == 3)
		{
			counter = 0;
			out = p;
			printf("out is = %d\n", p->id);
		}

		p = p->next;
		if(counter == 0)
			delete(out);
		if(p == NULL)
			p = head;

		if(head == NULL)
			break;
	}
	#endif

	return 0;
}
