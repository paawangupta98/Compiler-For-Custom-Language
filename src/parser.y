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
%token STRING
%token PRINT
%token PRINTLN
%token READ
%token IF
%token ELSE
%token GOTO

%%

program:	declblock codeblock

declblock: decl_block '{' dec_state '}'

dec_state: |INT_TYPE declare_var STOP dec_state

declare_var: many_ways ',' declare_var|many_ways

many_ways: ID | ID '[' INTEGER ']'

codeblock: code_block '{'statement_seg '}'

statement_seg: |statement statement_seg
statement: ID ':' | FOR_LOOP |  WHILE_LOOP |  simple |  print_state |  println_state |  read_state |  IF_ELSE | GOTO_EXP |STOP

simple: ID '=' single_expr STOP | ID '[' FINALTERM ']' '=' single_expr STOP | ID STOP | INTEGER STOP
single_expr: single_expr '+' FINALTERM | single_expr '*' FINALTERM| FINALTERM

GOTO_EXP: GOTO ID STOP| GOTO ID  IF expr STOP

FOR_LOOP: FOR syntaxforloop '{'statement_seg'}'
syntaxforloop: ID '=' INTEGER ',' INTEGER ',' INTEGER | ID '=' INTEGER ',' INTEGER

WHILE_LOOP: WHILE expr '{' statement_seg'}'
expr: TERM OR expr | TERM
TERM: FIRST_COMP AND TERM | FIRST_COMP
FIRST_COMP: SIM EX_OP SIM
SIM: SIM OP FINALTERM | FINALTERM
FINALTERM: ID | INTEGER | ID '['FINALTERM ']'

OP: '+'|'-'|'*'|'/'|'%'
EX_OP: LE | GE | DO_EQL | NOT_EQL | '<' | '>' | '='

IF_ELSE: IF expr '{' statement_seg'}' ELSE '{' statement_seg'}' | IF expr '{' statement_seg'}'

print_state: PRINT print_expr STOP
print_expr: print_expr ',' FINALTERM | print_expr ',' STRING | STRING | FINALTERM
println_state: PRINTLN STRING STOP | PRINTLN STOP

read_state: READ ID STOP | READ ID '[' FINALTERM ']' STOP
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
