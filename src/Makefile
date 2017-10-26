bcc:	parser.tab.c lex.yy.c
	g++ -std=c++11 parser.tab.c lex.yy.c main.cpp interpreter.cpp -lfl -o bcc
parser.tab.c: parser.y 
	bison -d parser.y 
parser.tab.h: parser.y
	bison -d parser.y 
lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

.PHONY: clean 
clean:
	-@rm -rf parser.tab.c parser.tab.h lex.yy.c bcc 2>/dev/null || true
