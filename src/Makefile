bcc:	parser.tab.c lex.yy.c ast.h visitor.h main.cpp interpreter.cpp Codegen.cpp
	g++ -std=c++11 -w parser.tab.c lex.yy.c main.cpp interpreter.cpp Codegen.cpp -lfl `llvm-config-3.8 --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl -o bcc
parser.tab.c: parser.y 
	bison -d parser.y 
parser.tab.h: parser.y
	bison -d parser.y 
lex.yy.c: scanner.l parser.tab.h
	flex scanner.l

.PHONY: clean 
clean:
	-@rm -rf parser.tab.c parser.tab.h lex.yy.c bcc 2>/dev/null || true
