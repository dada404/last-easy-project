#include "head.h"
#include "del_byname.h"
#include "del_bystunum.h"
#include "del_byphonum.h"
#include "del_SYSTEM.h"
#include "info_print.h"

INF *del_SYSTEM (INF *head)
{
	int back_tip = 0;//作为是否返回上一层的标志  
	
	//删除操作系统主部 
	do  
	{	
		system("cls");
		 
		int operation_tip;  //作为判断需要进行哪种操作 
		
		printf("      |                        IMA成员删除系统                          |\n");
		printf("      |_________________________________________________________________| \n");
		printf("      |删除方式 	                                                    |\n");
		printf("      |                        1.通过姓名删除                           |\n");
		printf("      |                        2.通过学号删除                           |\n");
		printf("      |                        3.通过电话号码删除                       |\n");
		printf("      |                        4.返回主操作系统                         |\n");
		printf("      |GDUT-IMA                                                         |\n");	       
		printf("      |_________________________________________________________________|\n");			
		printf("\n请输入数字（1-4）：");
		
		operation_tip = -1; 
		scanf("%d",&operation_tip); 
		
		//输错处理 
		while (operation_tip != 1 && operation_tip != 2 
				&& operation_tip != 3 && operation_tip != 4 )
		{	
			absorb_char();
			printf("操作出错，请重新输入数字（1-4）:");
			scanf("%d",&operation_tip); 
		} 
		
		switch (operation_tip)
		{
			case 1 : system("cls");//通过名字删除 
					 head = del_byname(head);
					 break;
			case 2 : system("cls");//通过学号删除 
					 head = del_bystunum(head);
					 break;
			case 3 : system("cls");//通过电话号码删除 
					 head = del_byphonum(head);
					 break;
			case 4 : back_tip = 1;//返回上一层 
					 break; 
	
		}  
		

	}while (back_tip == 0);
	
	return head;
	
}
