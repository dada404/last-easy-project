#include "head.h"
#include "info_print.h"
#include "add.h"
#include "del_byname.h"
#include "del_bystunum.h"
#include "del_byphonum.h"
#include "del_SYSTEM.h"
#include "system_member.h"
#include "change_info.h" 


INF* system_member (INF*head)
{
	int tip; //做操作的提示作用 
	do 
	{
		system("cls");
		printf("      |                        IMA部员管理系统                          |\n");
		printf("      |_________________________________________________________________| \n");
		printf("      |                        1.信息系统                               |\n");
		printf("      |                        2.更改自身信息                           |\n");
		printf("      |                        3.退出系统                               |\n");
		printf("      |GDUT-IMA                                                         |\n");	       
		printf("      |_________________________________________________________________|\n");
		printf("请选择你需要的操作(填入数字1-3):\n");

		tip = -1;
		scanf("%d",&tip);
	
		while(tip != 1 && tip != 2 && tip != 3 )
		{	
			absorb_char();
			printf("\n操作错误请重新输入数字（1-3）:");
			scanf("%d",&tip); 
		}
		
		//系统操作 
		switch (tip)
		{
			case 1 : system("cls");
					  system_info(head);
					  break;
			case 2 :  system("cls");
					  head = self_change_info(head);
					  break;
			case 3 :  tip = 3;
					  system("cls");
					  printf("退出系统成功...\n");
					  break;	
		}
	}while (tip != 3); 
	return head;	 
}
 	
