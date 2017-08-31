%{
#include "parser.tab.h"
%}
%%
"code_block"					{return code_block;}
"decl_block"					{return decl_block;}
"{"								{return '{';}
"}"								{return '}';}
","								{return ',';}
";"								{return STOP;}
"for"							{return FOR;}
"while"							{return WHILE;}
"void" 							{return VOID; }
"int" 							{return INT_TYPE; }
"and"							{return AND;}
"&&"							{return AND;}
"or"							{return OR;}
"||"							{return OR;}
"not"							{return NOT;}
"!="							{return NOT_EQL;}
"!"								{return NOT;}
"["								{return '[';}
"]"								{return ']';}
"=="							{return DO_EQL;}
"="								{return '=';}
"<="							{return LE;}
">="							{return GE;}
"<"								{return '<';}
">"								{return '>';}
"+"								{return '+';}
"-"								{return '-';}
"*"								{return '*';}
"/"								{return '/';}
"%"								{return '%';}
[0-9]+							{return INTEGER;}
[a-zA-Z][0-9a-zA-Z]*			{return ID; }
""
[ \t\n]							{ /* Do nothing */ ;}
. 								{printf("Unexpected token encountered: %s\n", yytext);}
%%