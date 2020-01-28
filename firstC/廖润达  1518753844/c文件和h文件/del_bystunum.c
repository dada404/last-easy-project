#include "head.h"
#include "del_bystunum.h"
#include "info_print.h"


/*
删除函数2 ：通过学号删除
传入链表头指针  传出链表头指针
*/ 
INF *del_bystunum (INF *head)
{	
	char del_stunum[12]; 
	INF *p1,*p2; 
	p1 = head ;
	
	printf("请输入部员或部长的学号：");
	inptst(del_stunum,12);
	
	
	while (strcmp(del_stunum,p1->stu_number) != 0 && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	
	//找到的情况 
	if (strcmp(del_stunum,p1->stu_number) == 0)
	{
		//列出被注销的成员的信息 
		printf("\n查找到学号为%s的成员信息如下：",del_stunum);
		info_print(p1);
		
		int tip;     //做标志判断是否确认注销成员账户 
		printf("\n确认注销该成员账户信息？");
		printf("\n确认注销请按1,取消注销请按0\n");
		tip = -1;
		scanf("%d",&tip);
		
		//输错处理 
		while( tip != 0 && tip != 1)
		{	
			absorb_char();
			printf("\n操作出错，请重新输入1或者0\n");
			scanf("%d",&tip);		
		}
		
		//确认注销 
		if( tip == 1)
		{
			//判断该成员的位点位置来做删除操作
			if (p1 == head)
			{
				head = head->next;
			}
			else
			{
				p2->next = p1->next;
			}
			
		 	//总人数减 1 
			n--; 
			
			//对删除成员的对应部门人数处理 
			switch (p1->dep_tip)  
			{
			case 0 : n_network--;
					 break;
			case 1 : n_game--; 
					 break;
			case 2 : n_produce--;
					 break;
			case 3 : n_hardware--;
					 break;
			case 4 : n_design--;
					 break;
			} 
			
			free(p1); 
			printf("\n账户信息注销完毕，请按下任意键请返回上一层...\n");
			getch(); 
		}
		//取消注销
		else 
		{
			printf("\n已取消注销账户信息，请按下任意键返回上一层...\n");
			getch(); 
		}	
	
	}
	
	//没找到的情况 
	else
	{
		printf("\n未找到学号为%s的成员的信息....\n",del_stunum);
		printf("\n请按下任意键返回上一层");
		getch();
	}
	
	return (head); 	 
 }
 
