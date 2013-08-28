#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define MAX 100

struct node {
	char item;
	struct node *l, *r;
};

typedef struct node *link;

link root = NULL;

link make_node(char item)
{
	link p;
	p = malloc(sizeof(*p));
	p->item = item;
	p->l = NULL;
	p->r = NULL;

	return p;
}

void travel(link t)
{
	if(t == NULL)
	{
		printf("()");
		return ;
	}
	printf("(%c", t->item);
	travel(t->l);
	travel(t->r);
	printf(")");
}


int count(link t)
{
	if(t == NULL)
		return;
	return 1 + count(t->l) + count(t->r);
}

int depth(link t)
{
	int ld, rd;
	if(t == NULL)
		return ;
	ld = depth(t->l);
	rd = depth(t->r);
	return 1 + (ld > rd ? ld : rd);
}

link init(char VLR[], char LVR[], int n)
{
	int k;
	link p;
	if(n <= 0)
		return NULL;
	for(k = 0; VLR[0] != LVR[k]; k++);
	p = make_node(VLR[0]);
	p->l = init(VLR + 1, LVR, k);
	p->r = init(VLR + 1 + k, LVR + 1 + k, n - k - 1);
	return p;
}

int isbalance(link t)
{
	int ld, rd;
	if(t == NULL)
		return 1;
	ld = depth(t->l);
	rd = depth(t->r);
	if(ld - rd >= 2 || rd - ld >= 2)
		printf("t->item %c is not balance\n", t->item);
	if(isbalance(t->l) == 0 || isbalance(t->r) == 0)
		return 0;
	if(ld - rd >= 2 || rd - ld >= 2)
		return 0;
	return 1;
}

link inser_node(link t, char key)
{
	if(t == NULL)
		return make_node(key);
	if(key > t->item)
		t->r = inser_node(t->r, key);
	else if(key < t->item)
		t->l = inser_node(t->l, key);
	else
		printf("EXIT\n");
	
	return t;
}

link delete(link t, char key)
{
	link p;
	if(t == NULL)
		return ;
	if(key > t->item)
		t->r = delete(t->r, key);
	else if(key < t->item)
		t->l = delete(t->l, key);
	else
	{
		if(t->l == NULL && t->r == NULL)
		{
			free(t);
			t = NULL;
		}
		else if(t->l != NULL)
		{
			for(p = t->l; p->r != NULL; p = p->r);
			t->item = p->item;
			t->l = delete(t->l, t->item);
		}
		else
		{
			for(p = t->r; p->l != NULL; p = p->l);
			t->item = p->item;
			t->r = delete(t->r, t->item);
		}
	}
	return t;
}


int main(void)
{
	while(1)
	{
		char ch;
		ch = getchar();
		getchar();
		if(ch == '#')
			break;
		root = inser_node(root, ch);
		printf("\\tree");
		travel(root);
		putchar(10);

	}
	while(1)
	{
		char ch;
		link p;
		ch = getchar();
		getchar();
		if(ch == '#')
			break;
		p = delete(root, ch);
		printf("\\tree");
		travel(p);
		putchar(10);
	}
	#if 0
	char pre_ser[] = "4213657";
	char in_ser[] = "1234567";
	printf("\\tree");
	root = init(pre_ser, in_ser, 7);
	travel(root);
	putchar(10);
	#endif
	#if 0
	link a, b, c, d, e, f, g;
	a = make_node('a');
	b = make_node('b');
	c = make_node('c');
	d = make_node('d');
	e = make_node('e');
	f = make_node('f');
	g = make_node('g');
	root = a;
	a->l = b;
	a->r = c;
	b->l = d;
//	b->r = e;
//	c->l = f;
	c->r = g;
	d->l = e;
	e->r = f;
//	g->r = f;
	printf("\\tree");
	travel(root);
	putchar(10);
	printf("count = %d \n", count(root));
	printf("depth = %d \n", depth(root));
	int tmp;
	tmp = isbalance(root);
	#endif
	
	return 0;
}
