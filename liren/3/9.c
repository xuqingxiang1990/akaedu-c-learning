建立新节点
struct node{
  int value;
  struct node *next;
  }
 插入节点到链表
struct node*add_new_node(struct*list,int n)
{
  struct node *new_node;
  new_node=malloc(sizeof(struct node));
  if(new_node==NULL)
  {
    printf("Eorror");
	exit(EXIT_FAILURE);
  }
  new_node->value=n;
  new_node->next=list;
  return new_node;
}
删除链表中的节点
struct node *dele_node(struct*list,int n)
{
  struct node *cur,*prev;
  for(cur=list,prev=NULL;cur!=NULL&&cur->next!=n;prev=cur,cur=cur->n    ext);
  if(cur=NULL)
    return list;
  if(prev=NULL)
    list=list->next;
  else
    prev->next=cur->next;
  free(cur);
  return list;
}


