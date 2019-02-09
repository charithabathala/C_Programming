#include <stdio.h> 
#include <string.h>

void insertion_sort(char *arr, int n);

int main()
{
    char word[20],arr[20];
    printf("Enter the word in uppercase letters= ");
    fgets(word,20,stdin);
    int n = strlen(word);

    //converting the alphabets to ASCII values
    for(int x=0;x<n-1;x++)
    {
        arr[x] = word[x]-'A';
    }
    

    //sort the alphabets using insertion sort 
    insertion_sort(arr,n);
}

void insertion_sort(char *arr, int n)
{
    int i,key,j;
    for (i=1;i<n-1;i++)
    {
        j = i-1;
        key = arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
    
    //Check for the duplicate letters in the word and print them
    int z=0,flag=0;i=0;
    while(i<n-1)
    {
        z=i+1;
        while(z<n-1 && arr[i]==arr[z])
        {
            flag++;z++;
        }
        if(flag>0)
        {
            char duplicate= arr[i]+'A';
            printf("The duplicate character is = %c\n",duplicate);
        }
        flag =0;
        i=z;
    }
 
}