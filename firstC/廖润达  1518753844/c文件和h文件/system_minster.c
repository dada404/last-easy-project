#include "head.h"
#include "info_print.h"
#include "add.h"
#include "del_byname.h"
#include "del_bystunum.h"
#include "del_byphonum.h"
#include "del_SYSTEM.h"
#include "system_minster.h"
#include "system_info.h"
#include "change_info.h"
#include "memberinfo_change.h" 



INF* system_minister (INF*head)
{
	int tip; //做操作的提示作用 

	do 
	{
		system("cls");	
		printf("      |                        IMA部长管理系统                          |\n");
		printf("      |_________________________________________________________________| \n");
		printf("      |                        1.信息系统                               |\n");
		printf("      |                        2.更改部员信息                           |\n");
		printf("      |                        3.更改自身信息                           |\n");
		printf("      |                        4.增加部员                               |\n");
		printf("      |                        5.删除部员                               |\n");
		printf("      |                        6.部员部门转换操作                       |\n");
		printf("      |                        7.退出系统     	                        |\n");	
		printf("      |GDUT-IMA                                                         |\n");	       
		printf("      |_________________________________________________________________|\n");
		printf("请选择你需要的操作（填入数字1-7）:\n"); 
		 
		tip = -1;
		scanf("%d",&tip);
		while(tip <1 && tip >8)
		{	
			absorb_char();
			printf("\n操作错误请重新输入数字（1-8）\n");
			scanf("%d",&tip); 
		}
		
		//系统操作 
		switch (tip)
		{
			case 1 : system("cls");
					 system_info(head);
					 break;
			case 2 : system("cls");
					 head = memberinfo_change (head);
					 break;
			case 3 : system("cls");
					 head = self_change_info(head);
					 break;
			case 4 : system("cls");
					 head = add (head);
					 break;
			case 5 : system("cls");
					 head = del_SYSTEM (head);
					 break;
			case 6 : system("cls");
					 dep_change(head);
					 break;
			case 7 : tip = 8;
					 system("cls");
					 printf("退出系统成功...\n");
					 break;	
		}
	}while (tip != 8); 
	return head;	 
}
 	
