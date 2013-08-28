#include <stdio.h>
#include <stdlib.h>
#define N 6
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
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}

void traversal(link p)
{
	while(p != NULL)
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}
}

link reverse(link p)
{
	link p1, p2, p3;
	if(p == NULL || p->next == NULL)
		return p;
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
	return head;
}

link sort(link head)
{
	link first;
	link min, min_p;
	link p;
	first = NULL;
	while(head != NULL)
	{
		for(p = head, min = head; p->next != NULL; p = p->next)
		{
			if(p->next->id < min->id)
			{
				min_p = p;
				min = p->next;
			}
		}
		if(first == NULL)
			first = tail = min;
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
	return;
}

int main(void)
{
	link p;
	link q;


#if 1
	p = make_node(9);
	link_list(p);
	p = make_node(3);
	link_list(p);
	p = make_node(12);
	link_list(p);
	q = p;
	p = make_node(124);
	link_list(p);
	p = make_node(33);
	link_list(p);
	p = make_node(22);

	printf("原链表:\n");
	traversal(head);

	printf("倒序输出链表:\n");
	p = reverse(head);
	traversal(p);

	printf("排序输出链表:\n");
	p = sort(head);
	traversal(p);
link_list(p);
#endif
	
	free(p);

	return 0;
}
