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

void traverse(link t)
{
	if(t == NULL)       //  recorsion  finish condition
	{
		printf("()");
		return ;
	}
	printf("(%c", t->item);
	traverse(t->r);
	traverse(t->l);
	printf(")");

	return ;
}

int count(link t)
{
	if(t == NULL)
		return 0 ;
	return 1 + count(t->l) + count(t->r);
}

int depth(link t)
{
	if(t == NULL)
		return 0;
	int lc = depth(t->l);
	int rc = depth(t->r);
	return 1 + (lc > rc ? lc :rc);
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
	t->r = init(VLR + k + 1, LVR + 1 + k, n - k  - 1);

	return t;
}

int mypow(int base, int pow)
{
	int i;
	int ret = 1;
	for(i = 0; i < pow; i++)
		ret *= base; 
	return ret;
}

int isbalanced(link t)
{
	int lc, rc;
	if(t == NULL)
		return 1;
	lc = depth(t->l);
	rc = depth(t->r);

	if(lc - rc >=2 || rc - lc >= 2)
		printf("t->item = %c is not balanced\n", t->item);
	if(isbalanced(t->l) == 0 || isbalanced(t->r) == 0)
		return 0;
	if(lc - rc >=2 || rc - lc >= 2)
		return 0;
	return 1;
}

link insert(link t, char key)
{
	if(t == NULL)
		return make_node(key);
	if(t->item > key)
		t->l = insert(t->l, key);
	else if(t->item < key)
		t->r = insert(t->r, key);
	else if(t->item == key)
		printf("EXITE\n");

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

int main(void)
{
	#if 0
	while(1)
	{
		
		char ch;
		ch = getchar();
		if(ch == 'q')
			break;
		root = insert(root, ch);
		printf("\\tree");
		traverse(root);
		printf("\n\n");
		fflush(stdout);
	}
	printf("input digit succeed\n");
//	return 0;

	while(1)
	{
		char ch = getchar();
		getchar();
		link p = search(root, ch);
		if(p != NULL)
			printf("%c is found \n", ch);
		else
			printf("%c is not found\n", ch);
	}
	#endif
	#if 0
	char pre_seq[] = "4213657";
	char in_seq[] = "1234567";
	root = init(pre_seq, in_seq, 7);
	printf("\\tree");
	traverse(root);
	putchar(10);
	printf("count = %d\n", count(root));
	printf("depth = %d\n", depth(root));
	#endif

	#if 1
	link a, b, c, d, e, f;
	printf("\\tree");
	a = make_node('4');
	b = make_node('2');
	c = make_node('5');
	d = make_node('1');
	e = make_node('3');
	f = make_node('6');

	a->l = b;
//	a->r = c;
	b->l = d;
//	d->r = e;
	c->r = f;
	root = a;

	traverse(root);
	putchar(10);
	#endif
	putchar(10);
	if(mypow(2, depth(root)) == count(root) + 1)
		printf("it is a FULL btree\n");
	else
		printf("it is not a FULL btree\n");
	int tmp;
	tmp = isbalanced(root);

	return 0;
}
