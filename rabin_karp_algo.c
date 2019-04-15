#include <stdio.h>
#include <string.h>
#include <math.h>

void search(char pat[],char txt[],int PRM)
{
	int pat_len = strlen(pat);
	int txt_len = strlen(txt);
	long pat_hash =0;
	long txt_hash =0;
	int i,j,k;

	//hash value of pattern and first window
	for(i=0;i<pat_len;i++)
	{
		pat_hash = pat_hash + ((int)pat[i]*pow(PRM,i)) ;
		txt_hash = txt_hash + ((int)txt[i]*pow(PRM,i)) ;

	}

	for (j=0; j<=txt_len - pat_len; j++)
	{
		if(pat_hash == txt_hash)
		{
			//check if characters match 
			for(k = 0;k<pat_len;k++)
			{
				if(pat[k]!=txt[k+j])
					break;
			}
			//printf("txt_hash = %ld\n",txt_hash);
			//printf("pat_hash = %ld\n",pat_hash);
			printf("Pattern found at %d\n",j);
		}

		txt_hash = ((txt_hash-(int)txt[j])/PRM) + ((int)txt[j+pat_len]*(pow(PRM,pat_len-1)));
		//printf("txt_hash = %ld\n",txt_hash);
		//printf("value of j = %d\n",j);
	}
}

int main()
{
	char txt[]="abceabcdeabcde";
	char pat[]="abc";
	int PRM = 101;
	search(pat,txt,PRM);
	return 0;
}