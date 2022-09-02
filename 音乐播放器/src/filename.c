#include "filename.h"



/*
	创建一个链表
	返回值为创建链表的头结点
*/
List *creat_list()
{
	List *h = malloc(sizeof(List));
	h->first = NULL;
	h->last = NULL;
	h->num = 0;
	return h;
}


/*
	增加一个结点
	@h:头结点
	@str:添加路径的首地址
*/
void add_a_node(List *h,Element *str)
{
	if(h == NULL)
	{
		return;
	}
	Node *pnew = malloc(sizeof(Node));
	strcpy(pnew->data,str);
	pnew->next = NULL;
	pnew->prev = NULL;
	if(h->first == NULL)
	{	
		h->first = pnew;
		h->last = pnew;
	}
	else
	{
		h->last->next = pnew;
		pnew->prev = h->last;
		h->last = pnew;
	}
	h->num++;
	h->last->next = h->first;
	h->first->prev = h->last;
}


/*
	打印一个链表
	@h:头结点
*/
void print_list(List *h)
{
	if(h == NULL)
	{
		return;
	}
	int flag = 0;
	Node *p = h->first;
	while(p && flag == 0)
	{
		if(p == h->last)
		{
			flag = 1;
		}
		printf("%s\n",p->data);
		p = p->next;
	}
	printf("%d\n",h->num);
}
