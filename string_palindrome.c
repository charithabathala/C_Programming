#include <stdio.h>
#include <string.h>


void palindrome(char *str);

int main ()
{  
	char str[100] = "noition";
	printf("input = %s\n",str);
	palindrome(str);
	return 0;
}

void palindrome(char *str1)
{
	char str2[100]="\0";
	char r_str2[100]="\0";
	int i_1,i_2,i_3,x=0;

	//printing single characters 
	printf("output = ");
	for(i_1=0;i_1<strlen(str1);i_1++)
	{
			printf("%c ",str1[i_1]);
	}

	//printing all other partitions of palindrome
	printf("\n");
	int win_size = 2;
	while(win_size<=strlen(str1))
	{   
		while(x<=(strlen(str1)+1-win_size))
		{   
			i_1=0;i_2=0;i_3=0;
			for(i_1=x;i_1<x+win_size;i_1++)
			{
				str2[i_2]=str1[i_1];
				i_2++;
			}
			//reverse str2 to get r_str2
			i_2 = win_size-1;
			while(i_2>=0)
			{
				r_str2[i_3]=str2[i_2];
				i_2--;
				i_3++;
			} 
			if(!(strcmp(str2,r_str2)))
				printf("output = %s\n",str2);
			x=x+1;
		}
		win_size++;
		x=0;
	}
}