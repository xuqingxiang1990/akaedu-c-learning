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
}

void insert_tail(link t)
{
  link p;
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

void print_node(link t)
{
  link p;
  if(t == NULL)
	return ;
  p = t;

  while(p != NULL)
  {
	printf("%d\n", p->id);
	p = p->next;
  }
}

link convert_Node(link head)
{
	link p1, p2, p3;
	p1 = head;
	p2 = p1->next;
	p3 = p2->next;
	if(head == NULL || head->next == NULL)
		return head;
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
	link frist, min, p_min;
	link p;
	frist = NULL;
	while(head != NULL)
	{	
		for(p = head, min = head; p->next != NULL; p->next)
		{
			if(p->next->id > min->id)
			{
				p_min = p;
				min = p->next;
			}
		}
		if(frist == NULL)
		{
			frist = min;
			tail = min;
		}
		else
		{
			tail->next = min;
			tail = min;
		}
		if(min == head)
			head = head->next;
		else
			p_min->next = min->next;
		head = head->next;
	}
	if(frist != NULL)
		tail->next = NULL;
	head = frist;
	return head;

}

int main(void)
{
  link p;
  int i;
  for(i = 0; i < N; i++)
  {
	p = make_node(i + 1);
	insert_tail(p);
  }
  p = NULL;
  p = convert_Node(head);
  print_node(p);

  return 0;
}
