#include "head.h" 
#include "all_print.h"

//输出所有成员基本信息  以及部门人数
//传入链表的头指针 
void all_print (INF *head)
{
	int tip = 0;   //做不同部门输出的标志  0为移动互联网部  1为游戏部  2为产品部   3为硬件部  4为设计部   

	
	//不需要用到链表的输出 
	system("cls");
	printf("欢迎来到总信息库\n");
	boundary(43);
	printf("IMA总人数:%d人\n",n);
	 
	//需要用到链表的输出
	//zhi's 
	while(tip < 5)
	{	
		INF *p;    //遍历链表所需指针
		p = head ;
		
		switch(tip)
		{	
			//移动互联网部 
			case 0 : boundary(71);
					 printf("移动互联网部                                          人数:%d",n_network);
					 boundary(71);
					 printf("姓名        学号           专业和班级      电话号码           身份      \n");
					 break;	
			//游戏部 
			case 1 : boundary(71);
					 printf("游戏部                                                人数:%d",n_game);
					 boundary(71);
					 printf("姓名        学号           专业和班级      电话号码           身份      \n");
					 break;	
			//产品部
			case 2 : boundary(71);
					 printf("产品部                                                人数:%d",n_produce);
					 boundary(71);
					 printf("姓名        学号           专业和班级      电话号码           身份      \n");
					 break;	
			//硬件部 
			case 3 : boundary(71);
					 printf("硬件部                                                人数:%d",n_hardware);
					 boundary(71);
					 printf("姓名        学号           专业和班级      电话号码           身份      \n");
					 break;			 
			//设计部 
			case 4 : boundary(71);
					 printf("设计部                                                人数:%d",n_design);
					 boundary(71);	
					 printf("姓名        学号           专业和班级      电话号码           身份      \n");
					 break;		
		} 
		

			 
			 
		do
		{
			//成员信息输出
			if ( p->dep_tip == tip )
			{
				printf("%-12s%-15s%-16s%-19s%-10s\n",p->name,p->stu_number,p->major_class,p->phone_number,p->identity);
					
			}
			
			
			p = p->next ;
		}while (p != NULL);
		
		printf("\n\n");
		 
		//到下一部门输出 
		tip++; 
		
	} 
	
	printf("\n按下任意键返回一层"); 
	getch();
	
}

void boundary(int cnt)
{	
	int i;
	printf("\n");
	for(i = 0; i < cnt; i++ )printf("_");
	printf("\n");
}
