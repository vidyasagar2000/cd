%{
    /* Definition section */
    #include<stdio.h>
    extern int yylex();
    int flag=0;
    void yyerror(){
        printf("\nEntered arithmetic expression is Invalid\n\n");
        flag=1;
    }
%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

/* Rule Section */
%%
ArithmeticExpression: E{
	printf("\nResult=%d\n", $$);
	return 0;
};
E : E'+'E {$$=$1+$3;} | E'-'E {$$=$1-$3;} | E'*'E {$$=$1*$3;} | E'/'E {$$=$1/$3;} | E'%'E {$$=$1%$3;} | '('E')' {$$=$2;} | NUMBER {$$=$1;};
%% 

#include "lex.yy.c"
//driver code
int main(){ 
    printf("\nEnter Any Arithmetic Expression:\n");
    yyparse();
    if(flag==0)
        printf("\nEntered arithmetic expression is Valid\n\n");
    return 0;
} 