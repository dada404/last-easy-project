#include "head.h"
#include "search.h"
#include "system_info.h"

//功能：信息总系统
//传入：链表头指针 
void system_info (INF *head)
{
	int tip;//主信息系统操作提示
	int back_tip = 0;//退出提示 
	int tip1;//查询操作系统(数字2对应操作)提示 
	
	do 
	{	
		system("cls");
	 
		printf("      |                         IMA信息系统                             |\n");
		printf("      |_________________________________________________________________| \n");
		printf("      |         	                                                    |\n");
		printf("      |                      1.查看所有成员信息                         |\n");
		printf("      |                      2.查询个体成员信息                         |\n");
		printf("      |                      3.退出信息系统                             |\n");
		printf("      |GDUT-IMA                                                         |\n");	       
		printf("      |_________________________________________________________________|\n");
		printf("请选择你需要的操作（填入数字1-3）:\n");
		tip = -1; 
		scanf("%d",&tip);
		
		//输错处理 
		while (tip != 1 && tip != 2 && tip != 3)
		{	
			absorb_char();
			printf("\n请重新输入数字（1-3）\n");
			scanf("%d",&tip);
		}
		
		switch (tip)
		{
			case 1: system("cls"); 
					all_print(head);
					break;
			case 2: system("cls");
					printf("      |                      IMA信息查询系统                            |\n");
					printf("      |_________________________________________________________________|\n");
					printf("      |         	                                                    |\n");
					printf("      |                      1.通过姓名查询                             |\n");
					printf("      |                      2.通过学号查询                             |\n");
					printf("      |GDUT-IMA                                                         |\n");	       
					printf("      |_________________________________________________________________|\n"); 
					printf("\n请输入数字（1-2）\n");
					tip1 = -1;
					scanf("%d",&tip1);
					
					while (tip1 != 1 && tip1 != 2)
					{	
						absorb_char();
						printf("\n请重新输入数字（1-2）\n");
						scanf("%d",&tip1);
					}
					//姓名查询 
					if(tip1 == 1 )
					{	
						system("cls");
						search_byname(head);
					}
					//学号查询 
					if(tip1 == 2 )
					{	
						system("cls");
						search_bystunum(head);
					}	
					break;
			case 3:back_tip = 1;
				   break;		 
		}
	
		
	}while (back_tip == 0); 
			
} 
