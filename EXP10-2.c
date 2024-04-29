/* 				EXP10

Aim : To implement naive string matching algorithm.
Name : Khan Saad Alikhan
Roll no : 22CO24
Academic Year : 2023-2024
Batch : 2
*/

/*
Theory : 
The naive string matching algorithm, also known as the brute-force or straightforward string matching
algorithm, is a simple pattern matching technique used to find all occurrences of a pattern within a
text. The algorithm compares the pattern with substrings of the text, moving one character at a time,
and checking for a match.
*/

/*
Algorithm :- 
    1.START
    2. Let n be the length of the text and m be the length of the pattern.
    3. Iterate through each starting position i in the text where the pattern can potentially match.
      3.1. For each starting position i:
           Initialize a variable j to 0.
           While j is less than m and text[i + j] equals pattern[j],Increment j by 1.
           If j equals m:
           Print "Pattern found at index i" indicating that the pattern is found starting at index i in the text.
    4. Repeat steps 3 until all possible starting positions are checked.
    5. END

*/
#include<stdio.h>
#include<string.h>
void naive_string_matcher(char text[],char pat[])
{
 char temp[100];
 int n=strlen(text);
 int m=strlen(pat);
 int i,j,s,k,count=0;
 for(s=0;s<=n;s++)
 {
  for(j=s,k=0;j<m;j++,k++)
   temp[k]=text[s+k];
  temp[k]='\0';
  if(strcmp(pat,temp)==0)
  {
  printf("\n Pattern found at index : %d ",s);
  count++;
  }
  m++;
 }
  printf("\n\n No Of Times Pattern Occurs  %d:",count);
}
int main()
{
 char text[100],pat[100];
 printf("\n ENTER THE TEXT    : ");
 gets(text);
 printf("\n ENTER THE PATTERN : ");
 gets(pat);
 naive_string_matcher(text,pat);
   return 0;
}
/*Output:-
 ENTER THE TEXT    : THIS IS A TEST TEXT

 ENTER THE PATTERN : TEST

 Pattern found at index : 10 

 No Of Times Pattern Occurs  1:
*/
/*
 Time complexity:-
    Best Case: 
		O(n)
        When the pattern is found at the very beginning of the text (or very early on).
        The algorithm will perform a constant number of comparisons, typically on the order of O(n)
        comparisons, where n is the length of the pattern.

    Worst Case: 
		O(n^2)
        When the pattern doesn’t appear in the text at all or appears only at the very end.
        The algorithm will perform O((n-m+1)*m) comparisons, where n is the length of the text and
        m is the length of the pattern.
        In the worst case, for each position in the text, the algorithm may need to compare the entire
        pattern against the text.

  Conclusion:- 
  The naive string matching algorithm is a brute force algorithm that performs exact string matching.
  It checks every character in the main string against the pattern. The algorithm reads the text from
  left to right and only moves the pattern one character to the right, regardless of how many
  characters in the pattern match. 

 */