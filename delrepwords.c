#include<stdio.h>
#include<string.h>
int main()
{
    //declare variables here as we need ; no need to preassume whether 3 or 4 variables we will use
    int i=0,j=0,k=0;

    char str1[100],substr[100][100];
    printf("Enter a sentence\n");

    //we want a string of any type; it may or may not contain spaces
    //scanf accpets string only till it finds 1st space
    //gets accept what form we require
    gets(str1);


    //split sentence into words
    //words itself is an array of characters 
    //so we need 2d array
    /**
     * ex: Tall Ram Tall
      0 1 2 3 4
    0 T a l l \0
    1 R a m \0
    2 T a l l \0
    */

   //loop till sentence/string end
    while(str1[k]!='\0')
    {
        j=0;
        //loop till word ends or sentence ends
        while(str1[k]!=' '&&str1[k]!='\0')
        {
            //fill each ith row of substr with a word
            substr[i][j]=str1[k];
            k++;
            j++;
        }

        //end word with null character
        substr[i][j]='\0';

        //move to next row for next word
        i++;

        if(str1[k]!='\0')
        {
            k++;
        }
    }


    //no of all words
    
    int len=i;
    //Removing repeated words same as removing repeated elements in arrays
    for(i=0;i<len;i++)
    {
    
        //start with a word at ith index

        //pick all other words one by one
        //like start comparing 2nd,3rd,4th etc all with 1st
        //similarly then 3rd,4th,5th all with 2nd in next i

      for(j=i+1;j<len;) //with j we pick up next word to i
       {
        //compare with both words equal
         if(strcmp(substr[i],substr[j])==0)
          {
            //if equal we have to delete current word 
            //for that we have to shift all words next to current words by a position
            // eg: Tall Ram Tall -> Ram Tall Tall
            //this shifting is done by copying
             for(k=j;k<len;k++)
              {
                strcpy(substr[k],substr[k+1]);
              }
                len--; //length decreased as we have got one repetition 
                //since we can't just delete we will ignore an element
           }
          else
           {
            //if not matched then move for next comparison
             j++;
           }
        }
     }

     //at last len has no of unique elements
     //and substr till len index has all unique elements
     //repested ones are present after that
     //so we run loop from 0 till len-1 and print
 for(i=0;i<len;i++)
 {
  printf("%s ",substr[i]);
 }
 printf("\n");

}