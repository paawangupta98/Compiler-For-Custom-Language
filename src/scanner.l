%{
#include "parser.tab.h"
%}
%%
"code_block"					{printf("Unexpected token encountered1: %s\n", yytext);return code_block;}
"decl_block"					{printf("Unexpected token encountered1: %s\n", yytext);return decl_block;}
"{"								{printf("Unexpected token encountered1: %s\n", yytext);return '{';}
"}"								{printf("Unexpected token encountered1: %s\n", yytext);return '}';}
","								{printf("Unexpected token encountered1: %s\n", yytext);return ',';}
";"								{printf("Unexpected token encountered1: %s\n", yytext);return STOP;}
"for"							{printf("Unexpected token encountered1: %s\n", yytext);return FOR;}
"while"							{printf("Unexpected token encountered1: %s\n", yytext);return WHILE;}
"print"							{printf("Unexpected token encountered1: %s\n", yytext);return PRINT;}
"println"						{printf("Unexpected token encountered1: %s\n", yytext);return PRINTLN;}
"read"							{printf("Unexpected token encountered1: %s\n", yytext);return READ;}
"if"							{printf("Unexpected token encountered1: %s\n", yytext);return IF;}
"else"							{printf("Unexpected token encountered1: %s\n", yytext);return ELSE;}
"void" 							{printf("Unexpected token encountered1: %s\n", yytext);return VOID; }
"int" 							{printf("Unexpected token encountered1: %s\n", yytext);return INT_TYPE; }
"goto"							{printf("Unexpected token encountered1: %s\n", yytext);return GOTO;}
"and"							{printf("Unexpected token encountered1: %s\n", yytext);return AND;}
"&&"							{printf("Unexpected token encountered1: %s\n", yytext);return AND;}
"or"							{printf("Unexpected token encountered1: %s\n", yytext);return OR;}
"||"							{printf("Unexpected token encountered1: %s\n", yytext);return OR;}
"not"							{printf("Unexpected token encountered1: %s\n", yytext);return NOT;}
"!="							{printf("Unexpected token encountered1: %s\n", yytext);return NOT_EQL;}
"!"								{printf("Unexpected token encountered1: %s\n", yytext);return NOT;}
"["								{printf("Unexpected token encountered1: %s\n", yytext);return '[';}
"]"								{printf("Unexpected token encountered1: %s\n", yytext);return ']';}
"=="							{printf("Unexpected token encountered1: %s\n", yytext);return DO_EQL;}
"="								{printf("Unexpected token encountered1: %s\n", yytext);return '=';}
"<="							{printf("Unexpected token encountered1: %s\n", yytext);return LE;}
">="							{printf("Unexpected token encountered1: %s\n", yytext);return GE;}
"<"								{printf("Unexpected token encountered1: %s\n", yytext);return '<';}
">"								{printf("Unexpected token encountered1: %s\n", yytext);return '>';}
"+"								{printf("Unexpected token encountered1: %s\n", yytext);return '+';}
"-"								{printf("Unexpected token encountered1: %s\n", yytext);return '-';}
"*"								{printf("Unexpected token encountered1: %s\n", yytext);return '*';}
"/"								{printf("Unexpected token encountered1: %s\n", yytext);return '/';}
"%"								{printf("Unexpected token encountered1: %s\n", yytext);return '%';}
":"								{printf("Unexpected token encountered1: %s\n", yytext);return ':';}
[0-9]+							{printf("Unexpected token encountered1: %s\n", yytext);return INTEGER;}
[a-zA-Z][0-9a-zA-Z]*			{printf("Unexpected token encountered1: %s\n", yytext);return ID; }
 \"(\\.|[^\\"])*\"				{printf("Unexpected token encountered1: %s\n", yytext);return STRING; }
[ \t\n]							{printf("Unexpected token encountered1: %s\n", yytext); /* Do nothing */ ;}
. 								{printf("Unexpected token encountered: %s\n", yytext);}
%%