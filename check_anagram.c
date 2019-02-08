#include <stdio.h>
#include <string.h> 

int sort_word(char *word1, char *word2);
void insertion_sort(char *word1,char *word2,int n);
void verify_anagram(char *word1,char *word2,int n);


int main()
{
  char word1[20],word2[20];

    printf("Enter first word in uppercase letters= ");
    fgets(word1,20,stdin);
    printf("Enter second word in uppercase letters = ");
    fgets(word2,20,stdin);
    sort_word(word1,word2);
    
}

int sort_word(char *word1, char *word2)
{
  int n = strlen(word1);
  char n_word1[20],n_word2[20];
  for(int i=0;i<n-1;i++)
  {
    n_word1[i] = word1[i]-'A';
  }
  for(int i=0;i<n-1;i++)
  {
    n_word2[i] = word2[i]-'A';
  }

  insertion_sort(n_word1,n_word2,n);
  

}

void insertion_sort(char *word1,char *word2,int n)
{
   //sorting first word using insertion sort algorithm 
   int i=1, key;
   for (i=1;i<n-1;i++)
   {
    key = word1[i];
    int j = i-1;
    while(j>=0 && word1[j]>key)
    {
      word1[j+1] = word1[j];
      j = j-1;
    }
    word1[j+1] = key;
   }

   //sorting second word using insertion sort algorithm  
   for (i=1;i<n-1;i++)
   {
    key = word2[i];
    int j = i-1;
    while(j>=0 && word2[j]>key)
    {
      word2[j+1] = word2[j];
      j = j-1;
    }
    word2[j+1] = key;
   }

   verify_anagram(word1,word2,n);
  
}

void verify_anagram(char *word1,char *word2,int n)
{
    int x = 0;
    int count=0;
    while(word1[x]==word2[x] && x<n-1)
        {
            count = count+1;
            x=x+1;
        }
    if(count==n-1)
        printf("The words are anagrams");
    else
        printf("The words are not anagrams");
    
}
