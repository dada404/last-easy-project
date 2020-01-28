#include "head.h"
#include "info_print.h"
#include "search.h"

//功能:查询部员个人信息
//传入：链表头指针 
INF* search_byname (INF *head)
{
	INF *p ; 
	p = head;
	char search_name[9];
	
	 
	printf("请输入您需查询的成员姓名：");
	inptst(search_name,9);
	
	while (p != NULL)
	{
		if(strcmp(search_name,p->name) == 0)
		{
			printf("\n该成员信息如下：");
			info_print(p);
			break; 
		}
		
		p = p->next;
		
	}
	if(p != NULL)
	{
		printf("查询完毕...\n\n请按下任意键");
		getch();
	}
	else 
	{
		printf("\n未查询到相应信息\n");
		printf("请按下任意键退出");
		getch(); 
	 } 
	return p; 
 } 
 
INF* search_bystunum (INF *head)
{
	INF *p ; 
	p = head;
	char search_stunum[12];
	 
	printf("请输入您需查询的成员学号：");
	inptst(search_stunum,12);
	
	while (p != NULL)
	{
		if(strcmp(search_stunum,p->stu_number) == 0)
		{
			printf("\n该成员信息如下：");
			info_print(p);
			break; 
		}
		
		p = p->next;
		
	}
	if(p != NULL)
	{
		printf("查询完毕...\n\n请按下任意键");
		getch();
	}
	else 
	{
		printf("\n未查询到相应信息\n");
		printf("请按下任意键退出");
		getch(); 
	 } 
	return p; 
 } 
