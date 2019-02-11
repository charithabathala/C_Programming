#include <stdio.h>
#include <string.h> 

void reverse_string(char *arr,int n);

int main()
{
	char arr[20];
	printf("Enter the word = ");
	fgets(arr,20,stdin);
	int n = strlen(arr);
	reverse_string(arr,n);
	return 0;
}

void reverse_string(char *arr,int n)
{
    int i=0;
    int j=n-2;
    char word[20];
    for(i=0;i<n-1;i++)
    {
        word[i]=arr[j];
        j=j-1;
    }
    for(i=0;i<n-1;i++)
    {
        printf("%c\t",word[i]);
    }
}