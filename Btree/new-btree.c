#include <stdio.h>
#include <stdlib.h>

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
	return ;
}

int count(link t)
{
	if(t == NULL)
		return ;
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

int mypow(int base, int pow)
{
	int ret = 1;
	int i;
	for(i = 0; i < pow; i++)
		ret *= base;
	return ret;
}

int isbalance(link t)
{
	int ld, rd;
	if(t == NULL)
		return 1;
	ld = depth(t->l);
	rd = depth(t->r);
	if(ld - rd >= 2 || rd - ld >= 2)
		printf("not balance is %c\n", t->item);
	if(isbalance(t->l) == 0 || isbalance(t->r) == 0)
		return 0;
	if(ld - rd >= 2 || rd - ld >= 2)
		return 0;
	return 1;
}

link init(char VLR[], char LVR[], int n)
{
	int k;
	link t;
	if(n <= 0)
		return NULL;
	for(k = 0; VLR[0] != LVR[k]; k++);
	t = make_node(VLR[0]);
	t->l = init(VLR + 1, LVR, k);
	t->r = init(VLR + 1 + k, LVR + k + 1, n -k -1);

	return t;
}

link inser(link t, char key)
{
	if(t == NULL)
		return make_node(key);
	if(key > t->item)
		t->r = inser(t->r, key);
	else if(key < t->item)
		t->l = inser(t->l, key);
	else
		printf("t->item = %c is EXIT\n", t->item);
	
	return t;
}

link search(link t, char key)
{
	if(t == NULL)
		return NULL;
	if(key > t->item)
		return search(t->r, key);
	else if(key < t->item)
		return search(t->l, key);
	
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
	link p;
	while(1)
	{
		char ch;
		ch = getchar();
		getchar();
		if(ch == '#')
			break;
		root = inser(root, ch);	
		printf("\\tree");
		travel(root);
		putchar(10);
	}
	char ch;
	ch = getchar();
	getchar();
	root = delete(root, ch);
	printf("\\tree");
	travel(root);
	putchar(10);
	
	#if 0
	while(1)
	{
		char ch;
		ch = getchar();
		getchar();
		if(ch == '#')
			break;
		p = search(root, ch);
		if(p)
			printf("YES find the %c \n", ch);
		else
			printf("NO find the %c \n", ch);
	}
	#endif
		

	#if 0
	char pre_seq[] = "4213657";
	char in_seq[] = "1234567";
	root = init(pre_seq, in_seq, 7);
	printf("\\tree");
	travel(root);
	putchar(10);
	#endif
	#if 0
	link a, b, c, d, e, f, g;
	printf("\\tree");
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
	b->r = f;
	d->l = e;
	e->l = g;
	//b->r = e;
//	c->l = f;
//	c->r = g;
	travel(root);
	putchar(10);
	printf("count = %d\n", count(root));
	printf("depth = %d\n", depth(root));
	if(mypow(2, depth(root)) == count(root) + 1)
		printf("this is full tree\n");
	else
		printf("this is Not full tree\n");
	int temp;
	temp = isbalance(root);
	#endif
		

	return 0;	
}
