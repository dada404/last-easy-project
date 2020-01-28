#include "head.h"
#include "memberinfo_change.h"
#include "change_info.h"
#include "search.h" 

INF *memberinfo_change (INF*head)
{	
	int tip;
	INF* p;
	
	printf("欢迎来到信息修改系统\n");
	printf("\n首先查询您所需要修改的成员的信息：\n");
	printf("输入1通过姓名查找，输入0通过学号查找\n");
	tip = -1;
	scanf("%d",&tip);
	
	//输错处理 
	while(tip != 1 && tip != 0)
	{	
		absorb_char();
		printf("\n请重新输入数字（0或1）\n");
		scanf("%d",&tip); 
	}
	 
	if(tip == 1)
	{
	 	p = search_byname(head);
	}
	if(tip == 0)
	{
		p = search_bystunum(head);
	}
	
	if( p == NULL)
	{
		return head;
	}
	 

	  
	printf("\n     _________________________________________________________________ \n");
	printf("      |       1.修改姓名          2.修改学号       3.修改电话号码       |\n");
	printf("      |       4.修改专业和班级    5.回到主页面                          |\n");
	printf("      |GDUT-IMA                                                         |\n");	       
	printf("      |_________________________________________________________________|\n");
	printf("请输入操作对应数字数字（1-5）:");
	
	int tip1;
	tip1 = -1; 
	scanf("%d",&tip1);
	
	while(tip1 != 1 && tip1 != 2 && tip1 != 3 && tip1 != 4 && tip1 != 5)
	{	
		absorb_char();
		printf("输入错误，请重新输入数字（1-5）");
		scanf("%d",&tip1); 
	}
				
	//选择操作 
	if( tip1 != 5)
	{
		p = info_change_select(p,head,tip1);
	}
	
	return head;
 } 
