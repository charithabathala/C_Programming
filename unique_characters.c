#include <stdio.h>
#include <string.h>

void insertion_sort(char *arr,int n);
void unique_chars(char *arr,int n);

int main()
{
	char word[20],arr[20]; 
	printf("Enter the word in uppercase letters = ");
	fgets(word,20,stdin);
	int n = strlen(word);
	int i=0;
	for(i=0;i<n-1;i++)
	{
		arr[i]=word[i]-'A';
	}
	insertion_sort(arr,n);
	return 0;
}

void insertion_sort(char *arr,int n)
{
	int i,j,key=0;
	for(i=1;i<n-1;i++)
	{
		j=i-1;
		key = arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j = j-1;
		}
		arr[j+1]=key;
	}
    unique_chars(arr,n);
}

void unique_chars(char *arr,int n)
{
    int i,j=0,flag=0;;
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        if(arr[i]==arr[j])
        {
            flag++;
        }
        
    }
    if(flag)
        printf("The word does not have unique characters");
    else
        printf("The word has unique characters");
}
