%option noyywrap
%option nounput
%option yylineno
%{
#include <bits/stdc++.h>
using namespace std;
#define YY_DECL extern "C" int yylex()
#include "ast.h"
#include "parser.tab.h"
extern union Node yylval;
%}
string (\\n|\\t|\\'|\\\\|\\\"|[^\\"'])
%%
"codeblock"						{ return code_block;  }
"declblock"						{ return decl_block;  }
"{"								{ return '{';  }
"}"								{ return '}';  }
","								{ return ',';  }
";"								{ return STOP;  }
"for"							{ return FOR;  }
"while"							{ return WHILE;  }
"print"							{ return PRINT;  }
"println"						{ return PRINTLN;  }
"read"							{ return READ;  }
"if"							{ return IF;  }
"else"							{ return ELSE;  }
"void" 							{ return VOID; }
"int" 							{ return INT_TYPE; }
"goto"							{ return GOTO;  }
"and"							{ return AND;  }
"&&"							{ return AND;  }
"or"							{ return OR;  }
"||"							{ return OR;  }
"not"							{ return NOT;  }
"!="							{ return NOT_EQL;  }
"!"								{ return NOT;  }
"["								{ return '[';  }
"]"								{ return ']';  }
"=="							{ return DO_EQL;  }
"="								{ return '=';  }
"<="							{ return LE;  }
">="							{ return GE;  }
"<"								{ return '<';  }
">"								{ return '>';  }
"+"								{ return '+';  }
"-"								{ return '-';  }
"*"								{ return '*';  }
"/"								{ return '/';  }
"%"								{ return '%';  }
":"								{ return ':';  }
[0-9]+							{ yylval.intval = atoi(yytext);return INTEGER;  }
[a-zA-Z][0-9a-zA-Z]*			{ yylval.stringval = strdup(yytext);return ID;   }
\"{string}*\"					{char *s2 = strdup(yytext);int si = strlen(s2);char*s1=(char*)malloc(si-2);s2++;char * te = s1;for(int i=1;i<si-1;i++) {*te=*s2;te++;s2++;} ; yylval.stringval = s1;return STRING; }
[ \t\n]							{ /* Do nothing */ ;  }
. 								{;}
%%