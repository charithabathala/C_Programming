#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_space(char *word);

int main()
{
	char word[100];
    printf("Enter the string = ");
	fgets(word,100,stdin);
	replace_space(word);
	return 0;
}

void replace_space(char *word)
{

	int n = strlen(word);
	char arr[100];
	int i=0,j=0,x=0,y=0;
	j=n-1;

	//eliminate leading spaces
	while(isspace(word[i]))
        i = i+1;

	//eliminate trailing spaces
	while(isspace(word[j]))
        j = j-1;
	    
	x=i;
	while(x<=j)
	{
	    while(isalpha(word[x]))
	    {
	        arr[y]=word[x];
	        y=y+1;
	        x=x+1;
	    }
	    
	    while(isspace(word[x]))
	    { 
	        x=x+1;
	    }
	    
	    if(x<=j)
	    {
	        arr[y]='%';
	        arr[y+1]='2';
	        arr[y+2]='0';
	        y=y+3;
	    }
	    
	}
	arr[y]='\0';
    printf("Output = %s",arr);
}

