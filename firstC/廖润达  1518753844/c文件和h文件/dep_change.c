#include "head.h"
#include "dep_change.h"
#include "info_print.h"
#include "search.h"




INF* dep_change(INF *head)
{	
	int tip;
	INF *p;
	printf("欢迎来到部门修改系统\n");
	printf("\n首先查询您所需要修改的成员的信息：\n");
	printf("输入1通过姓名查找，输入0通过学号查找\n");
	tip = -1; 
	scanf("%d",&tip);
	
	//输错处理 
	while(tip != 1 &&tip != 0)
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
	
	
	if(p != NULL)
	{
		int tip2;//保留原先部门对应数
		tip2 = p->dep_tip;
		int tip1; 
		
		printf("\n\n您需要将该成员从%s部门转换到何部门\n",p->department);
		
		printf("0.移动互联网部   1.游戏部  2.产品部   3.硬件部  4.设计部\n");
		printf("-----------------------------------------------------------\n");	
		printf("\(输入0-4数字)\n"); 
		p->dep_tip = -1;
		scanf("%d",&p->dep_tip);
		
		while(p->dep_tip!=0 && p->dep_tip!=1 && p->dep_tip!=2 && p->dep_tip!=3 &&p->dep_tip!=4)
		{	
			absorb_char();
			printf("\n部门转换错误，请重新输入数字（0-4）\n");
			scanf("%d",&p->dep_tip); 
		}
		
		printf("\n请输入1确认部门转换，输入0取消转换\n");
		tip1 = -1;
		scanf("%d",&tip1);
		while(tip1!=0 && tip1!=1)
		{
			absorb_char();
			printf("\n确认失败，请重新输入（1或0）\n");
			scanf("%d",&tip1); 
		}
		
		
		//更换后的部门加一 
		switch (p->dep_tip)
		{
			case 0 : strcpy(p->department,"移动互联网部");
					 n_network++;
					 break;
			case 1 : strcpy(p->department,"游戏部");
					 n_game++;
					 break;
			case 2 : strcpy(p->department,"产品部");
					 n_produce++;
					 break;
			case 3 : strcpy(p->department,"硬件部");
					 n_hardware++;
					 break;
			case 4 : strcpy(p->department,"设计部");
					 n_design++;
					 break;
		}
		//先前部门人数减一 
		switch (tip2)
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
		printf("\n请按下任意键退出\n");
		getch();
	}
	return 0;
	
	 
 } 
