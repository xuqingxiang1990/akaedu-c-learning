#include <stdio.h>
#include <stdlib.h>

struct node {
	int age;
	char item;
	struct node *next;
};


typedef struct node * link;

link head = NULL;

int main(void)
{
	link p;
	printf("size of p = %d\n", sizeof(p));  //指针  4个字节
	printf("size of p = %d\n", sizeof(*p));
	printf("size of p = %d\n", sizeof(struct node));
	
	printf("size of p = %p\n", &(((link)0) -> age));
//	p = malloc(sizeof(*p));
	p = malloc(sizeof(struct node));
	p->item = 'a';
	p->next = NULL;
	printf("p  = %p \n", p);
	head = p;

	p = malloc(sizeof(struct node));
	p->item = 'b';
	p->next = NULL;
	printf("p  = %p\n", p);
	head->next = p;
	
	p = malloc(sizeof(struct node));
	p-> item = 'c';
	p-> next = NULL;
	head->next->next = p;

//***********插入头
#if 0
	p = head;
	p = malloc(sizeof(*p));
	p->item = 'd';
	p->next = head;
	head = p;
#endif

#if 0
//  插入到尾 
	link tail = NULL;
	p = head;
	while(p != NULL)
	{
		if(p->next == NULL)
			tail = p;
		p = p->next;	
	}
	p = malloc(sizeof(*p));
	p->item = 'd';
	p->next = NULL;
	tail->next = p;

#endif
//*****************************************
		
	#if 0
	link pos = head->next;
	 
	p = malloc(sizeof(*p));
	p->item = 'd';
	p->next = pos->next; 
	pos->next = p;
	#endif

	//link pos = head->next;

	#if 0
	link prev = NULL;
	link pos = head->next;
	p = head;
	while(p != NULL)
	{
		if(p->next == pos)
		{
			prev = p;
			break;
		}
		p = p->next;
	}
	p = malloc(sizeof(*p));
	p->item = 'd';
	p->next = prev->next;
	prev->next = p;
	#endif
//********************删除***********************/	
	#if 0
	link pos = head;
	 head = pos->next;
	 free(pos);
	 pos = NULL;
	#endif
	#if 1
	link pos = head->next;
	//link pos = head->next->next;
	link prev = NULL;
	p = head;
	while(p != NULL)
	{
		if(p->next == pos)
		{
			prev = p;
			break;
		}
		p = p->next;
	}
	prev->next = prev->next->next;

	#endif

	p = head;
	while(p != NULL)
	{
		printf("p - > item = %c \n", p -> item);
		//printf("p -> next = %p ", p -> next);
		p = p -> next;
	}

	return 0;
}
