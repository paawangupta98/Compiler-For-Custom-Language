using namespace std;

class Visitors{
public:
	void * visit(class ASTProgram *);
	void * visit(class ASTDeclBlock *);
	void * visit(class ASTidvariable *);
	void * visit(class ASTstatement * );
	bool visit(class ASTexpression * );
	bool visit(class ASTfirstexpr * );
	bool visit(class ASTtermexpr * );
	int  visit(class ASTvalue * );
	int  visit(class ASTsingleexpr * );
	int  visit(class ASTbinaryexpr * );
	void * visit(class ASTforloop * );
	void * visit(class ASTwhileloop * );
	void * visit(class ASTread * );
	void * visit(class ASTprintexpr * ,int fl);
	void * visit(class ASTprint * );
	void * visit(class ASTprintln * );
	void * visit(class ASTassignment * );
	void * visit(class ASTlabel * );
	void * visit(class ASTifelse * );
	void * visit(class ASTif * );
	void * visit(class ASTgoto * );
};