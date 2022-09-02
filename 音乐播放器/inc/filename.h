#ifndef __FILENAME_H__
#define	__FILENAME_H__


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX	100

typedef char Element;
typedef struct node
{
	Element data[MAX];
	struct node *next;
	struct node *prev;
}Node;
typedef struct list
{
	Node *first;
	Node *last;
	int num;
}List;

List *creat_list();				//创建一个链表
void add_a_node(List *h,Element *str);			//增加一个结点
void print_list(List *h);						//打印一个链表



#endif