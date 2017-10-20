%{
	#include <bits/stdc++.h>
	#include "ast.h"
	using namespace std;
	extern "C" FILE *yyin;
	extern int yylineno;
	extern "C" int yyparse();
	extern "C" int yylex();
	extern  ASTProgram * programhead;
	void yyerror (char const *s);
	#define YYSTYPE_IS_DECLARED
%}

/*  TOKENS */
%start program
%token <intval> INTEGER
%token <stringval> ID
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

%type <program> program
%type <dec_states> dec_states
%type <dec_state> dec_state
%type <declare_var> declare_var
%type <statement_seg> statement_seg
%type <statement> statement 
%type <expr> expr
%type <expr1> expr1
%type <TERM> TERM
%type <TERM1> TERM1
%type <FIRST_COMP> FIRST_COMP
%type <FINALTERM> FINALTERM
%type <single_expr> single_expr

%%

program:	decl_block '{' dec_states '}'  code_block '{'statement_seg '}' {$$ = new ASTProgram($3 , $7);}

dec_states: {$$ = new std::vector<ASTDeclBlock *> ;}
			| dec_state dec_states {$2->push_back($1); $$=$2;}

dec_state: INT_TYPE declare_var STOP {$$ = new ASTDeclBlock(datatype::int_type , $2);}

declare_var: ID ',' declare_var  {$3->push_back(new ASTidvariable("id" , $1 , 0)); $$=$3;}
			| ID '[' INTEGER']' ',' declare_var {$6->push_back(new ASTidvariable("array" ,$1, $3)); $$=$6;}
			| ID  {$$ = new std::vector<ASTidvariable *>; $$->push_back(new ASTidvariable("id",$1 , 0)); }
			| ID '[' INTEGER ']' {$$ = new std::vector<ASTidvariable *>; $$->push_back(new ASTidvariable("array",$1, $3));}

statement_seg: {$$ = new std::vector<ASTstatement*>;}
			|statement statement_seg {$2->push_back($1); $$=$2;}
statement:	FOR ID '=' INTEGER ',' INTEGER ',' INTEGER '{'statement_seg'}' {$$ = new ASTforloop($2 , $4 , $6 , $8 , $10);}
			|FOR ID '=' INTEGER ',' INTEGER '{'statement_seg'}' {$$ = new ASTforloop($2 , $4 , $6 , 1 , $8);}
			| WHILE expr '{' statement_seg'}' {$$ = new ASTwhileloop($1 , $4); }
			| simple 
			| print_state 
			| println_state 
			| read_state 
			| IF_ELSE 
			| GOTO_EXP 
			| STOP

simple: ID '=' single_expr STOP | ID '[' FINALTERM ']' '=' single_expr STOP | ID STOP | INTEGER STOP

GOTO_EXP: GOTO ID STOP| GOTO ID  IF expr STOP

expr : expr1 {$$ = new ASTexpression($1);}

expr1: 	TERM OR expr1 {$3->push_back($1); $$=$3;} 
		| TERM {$$ = new vector<ASTtermexpr *>; $$->push_back($1);} 
TERM: TERM1 {$$ = new ASTtermexpr($1);}
TERM1: 	FIRST_COMP AND TERM1  {$3->push_back($1);$$=$3;}
		| FIRST_COMP {$$ = new vector<ASTfirstexpr *>; $$->push_back($1);}
FIRST_COMP: single_expr LE single_expr {$$ = new ASTfirstexpr($1 , relative_op::less_than_equal , $3);}
			| single_expr GE single_expr {$$ = new ASTfirstexpr($1 , relative_op::greater_than_equal , $3);}
			| single_expr DO_EQL single_expr {$$ = new ASTfirstexpr($1 , relative_op::double_equal , $3);}
			| single_expr NOT_EQL single_expr {$$ = new ASTfirstexpr($1 , relative_op::not_equal , $3);}
			| single_expr '<' single_expr {$$ = new ASTfirstexpr($1 , relative_op::greater_than , $3);}
			| single_expr '>' single_expr {$$ = new ASTfirstexpr($1 , relative_op::less_than , $3);}
			| single_expr '=' single_expr {$$ = new ASTfirstexpr($1 , relative_op::equal , $3);}

single_expr: single_expr '+' FINALTERM {$$ = new ASTbinaryexpr($1 ,arithematic_op::plus , $3);}
			|single_expr '-' FINALTERM {$$ = new ASTbinaryexpr($1 ,arithematic_op::sub  , $3);}
			|single_expr '*' FINALTERM {$$ = new ASTbinaryexpr($1 ,arithematic_op::mult  , $3);}
			|single_expr '/' FINALTERM {$$ = new ASTbinaryexpr($1 ,arithematic_op::div  , $3);}
			|single_expr '%' FINALTERM {$$ = new ASTbinaryexpr($1 ,arithematic_op::mod  , $3);}
			|FINALTERM {$$ = $1;}
FINALTERM: 	ID {$$ = new ASTValue("id" , $1);}
			| INTEGER {$$ = new ASTValue("int" , $2);}
			| ID '['single_expr']'{$$ = new ASTValue("array" , $1 , $3);}

IF_ELSE: IF expr '{' statement_seg'}' ELSE '{' statement_seg'}' | IF expr '{' statement_seg'}'

print_state: PRINT print_expr STOP
print_expr: print_expr ',' FINALTERM | print_expr ',' STRING | STRING | FINALTERM
println_state: PRINTLN STRING STOP | PRINTLN STOP

read_state: READ ID STOP | READ ID '[' FINALTERM ']' STOP
%%

void yyerror (char const *s)
{
       std::cerr << "Error on Line : " << yylineno <<" "<< "Error : " << s << std::endl;
}
