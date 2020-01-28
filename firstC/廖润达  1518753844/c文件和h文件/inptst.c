#include "head.h"
#include "inptst.h" 

void inptst (char *array,int length)
{	
	int i;
	int tip = 0;
	
	do
	{	
		for(i = 0; i < length; i++) //清空内容 
		{
			array[i] = '\0';
		}
		 
		for (i = 0; i < length; i++ )
		{
			char c;
			c = getchar();
	
			if( c == '\n' && i == 0 )//防止第一个是回车键 
			{
				break;
			}

			if ( c =='\n' && i != 0 )
			{
				tip = 1 ;
				break;
			}
		
			if ( i == length-1 )
			{
				printf("\n操作错误，请重新输入:");
				
				//吸收字符 
				while( c != '\n')
				{
					c = getchar();
				} 
				break; 
			}	
			array[i] = c;
		}
	}while (tip != 1);

 } 
 
void absorb_char()
{
	char c;
	while( (c = getchar())!= '\n');
} 
