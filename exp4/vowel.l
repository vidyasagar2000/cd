%{
	#include<stdio.h>
    int vowel=0;
    int cons=0;
%}
%%
[aeiouAEIOU] {printf("\n%s is an Vowel", yytext); vowel++;}
[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {printf("\n%s is a Consonant", yytext); cons++;}
%%
int yywrap(){return 1;}
int main()
{
    printf("\nEnter the Character: ");
    yylex();
    printf("\nTotal Vowel=%d & Total Consonant= %d\n", vowel,cons);
    return 0;
}