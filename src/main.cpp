#include "ast.h"

#include <bits/stdc++.h>
using namespace std;
ASTProgram * programhead = NULL;
extern "C" FILE *yyin;
extern "C" int yyparse();
extern "C" int yylex();
int main(int argc, char** argv) {
    FILE *filename = fopen(argv[1], "r");
    if (argc == 1 ) {
        fprintf(stderr, "Correct usage: bcc filename\n");
        exit(1);
    }

    if (argc > 2) {
        fprintf(stderr, "Passing more arguments than necessary.\n");
        fprintf(stderr, "Correct usage: bcc filename\n");
    }
    yyin = filename;
    do {
        yyparse();
    } while (!feof(yyin));
    // Interpreter * startvisitor = new Interpreter();
    Codegen * startvisitor = new Codegen();
    programhead->accept(startvisitor);
    // myModule->dump();
}