#include <stdio.h>
#include <stdlib.h>

#define N 100 
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
		head->next = head;  //环形
		return ;
	}
	tail->next = p;
	tail = p;
	tail->next = head;


	return ;	
}

void traverse(link t)
{
	link p;
	if(t == NULL)
		return ;
	p = t;
	#if 1
	do
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}while(p != t);
	#endif
}
void delete(link p)
{
	link pre;
	if(head->next == head)
	{
		head = tail = NULL;
		free(p);
		return ;
	}
	if(p == head)
	{
		head = p->next;
		tail->next = head;
	}
	else
	{
		link pre;
		pre = head;
		while(1)
		{
			if(pre->next == p)
			{
				pre->next = p->next;
				if(p == tail)
					tail = pre;
				break;
			}
			pre = pre->next;
			if(pre == tail)
				break;
		}
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
	while(head != NULL)
	{
		link out;
		link save;
		step++;
		countoff++;
		printf("step %d : %d countoff:%d\n", step, p->id, countoff);

	#if 1
	save = p;
	p = p->next;	
	if(countoff == OUT)
		{
			countoff = 0;
			printf("who is OUR %d\n", save->id);
			delete(save);
		}
	#endif

	}
	
	return 0;
}
