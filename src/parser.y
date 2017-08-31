%{
  #include <stdio.h>
  #include <stdlib.h>
  FILE *yyin;
  int yylex (void);
  void yyerror (char const *s);
%}

/*  TOKENS */
%token INTEGER
%token ID
%token INT_TYPE
%token VOID
%token code_block
%token decl_block
%token STOP
%token AND
%token OR
%token NOT
%left '+'
%left '-'
%left '*'
%left '/'
%left '%'
%token LE
%token GE
%token DO_EQL
%token NOT_EQL
%token FOR
%token WHILE

%%

program:	declblock codeblock

declblock: decl_block '{' dec_state '}'

dec_state: INT_TYPE declare_var STOP dec_state | INT_TYPE declare_var STOP

declare_var: many_ways ',' declare_var|many_ways

many_ways: ID | ID '[' INTEGER ']'

codeblock: code_block '{' statement '}'

statement: FOR_LOOP | WHILE_LOOP | simple | print_state

simple: ID '=' single_expr STOP | ID STOP | INTEGER STOP
single_expr: single_expr '+' FINALTERM | single_expr '*' FINALTERM| ID | INTEGER

FOR_LOOP: FOR syntaxforloop '{'statement'}'
syntaxforloop: ID '=' INTEGER ',' INTEGER ',' INTEGER | ID '=' INTEGER ',' INTEGER

WHILE_LOOP: WHILE expr '{' statement'}'
expr: TERM OR expr | TERM
TERM: SIM AND TERM | SIM
SIM: SIM '%' FINALTERM |SIM '+' FINALTERM |SIM '-' FINALTERM |SIM '*' FINALTERM | SIM '/' FINALTERM| ID | INTEGER
FINALTERM: ID | INTEGER

print_state: PRINT 
%%

void yyerror (char const *s)
{
       fprintf (stderr, "%s\n", s);
}

int main(int argc, char *argv[])
{
	if (argc == 1 ) {
		fprintf(stderr, "Correct usage: bcc filename\n");
		exit(1);
	}

	if (argc > 2) {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: bcc filename\n");
	}

	yyin = fopen(argv[1], "r");

	yyparse();
}
