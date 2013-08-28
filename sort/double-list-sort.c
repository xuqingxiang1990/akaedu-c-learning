#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

struct node {
	int id;
	struct node *prev, *next;
};

typedef struct node *link;

link head = NULL;
link tail = NULL;



link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->prev = NULL;
	p->next = NULL;

	return p;
}

void link_list(link t)
{
	link p;
	p = t;
	if(head == NULL)
	{
		head = tail = p;
	//	head->next = p;
	//	tail->prev = p;
		head->prev = NULL;
		tail->next = NULL;
		return ;
	}

	tail->next = p;
	p->prev = tail;
	tail = p;
}

void traverse_over(link t)
{
	link p;
	p = tail;
	do
	{
		printf("p->id = %d\n", p->id);
		p = p->prev;	
	}while(p != NULL);
}

void traverse(link t)
{
	link p;
	p = head;
	while(p != NULL)
	{
		printf("p->id = %d\n", p->id);
		p = p->next;
	}
}

#if 1
link list_sort(void)
{
	link first, last, min, min_p;
	first = last = NULL;
	link p;
	while(head != NULL)
	{
		for(p = head, min = head; p->next != NULL; p = p->next)   //查找最小点
			if(p->id < min->id)
				min = p;	

		if(min == head)          // 删除min节点
			head = head->next;

		else if (min == tail)
		{
		//	tail->prev->next = NULL;
			  tail = tail->prev;
		}
		else
		{
			min->prev->next = min->next;
			min->next->prev = min->prev;
		}

		if(first == NULL)      //把min插入到first链表中
		{
			//first = min;
			first = last = min;
			first->next = NULL;
			last->prev = NULL;
		}
		else
		{
			last->next = min;
			min->prev = last;
			last = min;
		}

	}
		head = first;
		tail = last;
		tail->next =NULL;
		first->prev = NULL;
		return head;
}
#endif

void sweap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

#if 0
link partion(link low, link high)
{
	int tmp = 0;
	if(head->next == NULL)
		return head;
	tmp = low->id;
	while(low != high)
	{
		while(low != high && high->id >= tmp)
			high = high->prev;
		sweap(&low->id, &high->id);
		while(low != high && low->id <= tmp)
			low = low->next;
		sweap(&low->id, &high->id);
	}

	return low;
}

void quick_sort(link low, link high)
{
	link tmp = NULL;
	tmp = partion(low, high);
	if(low != tmp)
	{
		quick_sort(low, tmp->prev); 
	}
	if(high != tmp)
	{
		quick_sort(tmp->next, high);
	}
}
#endif

link reverse(link p)
{
	link p1, p2, p3;
	if(head == NULL || head->next == NULL)
		return head;
	p1 = head;
	p2 = p1->next;
	p3 = p2->next;
	p1->next = NULL;
	while(p3 != NULL)
	{
		p2->next = p1;
		p1->prev = p2;
		p1 = p2;
		p2 = p3;
		p3 = p3->next;
	}
	p2->next = p1;
	p1->prev = p2;
	head = p2;
	return head;
}

link position(link low, link high)
{
	int tmp;
	if(head->next == NULL)
		return head;
	tmp = low->id;
	while(low != high)
	{
		while(low != high && high->id >= tmp)
			high = high->prev;
		sweap(&low->id, &high->id);
		while(low != high && low->id <= tmp)
			low = low->next;
		sweap(&low->id, &high->id);
	}
	return low;
}

void quick_sort(link low, link high)
{
	link k;
	k = position(low, high);
	if(k != low)
	{
		quick_sort(low, k->prev);
	}
	if(k != high)
	{
		quick_sort(k->next, high);
	}
}

int main(void)
{
	int i, a[N];
	link p;
	#if 0
	p = make_node(10);
	link_list(p);
	p = make_node(4);
	link_list(p);
	p = make_node(8);
	link_list(p);
	p = make_node(6);
	link_list(p);
	#endif
	#if 1
	for(i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		p = make_node(a[i]);
		link_list(p);
	}
	#endif
	printf("*****************************\n");
	traverse(head);
	printf("*****************************\n");
	traverse_over(head);
	printf("*****************************\n");
	//p = reverse(head);
	traverse(p);
	printf("*****************************\n");
//	p = list_sort();
	quick_sort(head, tail);
	printf("*****************************\n");
	printf("%d\n", head->id);
	printf("%d\n", tail->id);
	printf("*****************************\n");
	traverse(p);


	return 0;
}
