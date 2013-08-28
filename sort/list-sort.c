#include <stdio.h>
#include <stdlib.h>
#define N 10

struct node {
	int id;
	struct node *next;
};

typedef struct node *link;

link head = NULL;
link tail = NULL;

link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;

	return p;
}

void link_list(link t)
{
	link p;
	p = t;
	if(head == NULL)
		tail = head = p;
	tail->next = p;
	tail = p;
		
}

void travers(link p)
{
	
	while(p != NULL)
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}
}

link select_sort(link t)
{
	link p, first = NULL;
	link min, min_p;
	while(head != NULL)
	{
		for(p = head, min = head; p->next != NULL; p = p->next)
			if(p->next->id < min->id)
			{
				min_p = p;
				min = p->next;
			}
		if(first == NULL)
			tail = first = min;
		else
		{
			tail->next = min;
			tail = min;
		}
		if(min == head)
			head = head->next;
		else
			min_p->next = min->next;
	}
	head = first;
	return head;
}

int main(void)
{
	int i, a[N];
	link p;
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		p = make_node(a[i]);
		link_list(p);
	}
	travers(head);
	printf("**********************************************\n");
	p = select_sort(head);
	travers(p);

	return 0;
}
