using namespace std;

class Visitors{
public:
	void * visit(class ASTProgram *);
	void * visit(class ASTDeclBlock *);
	void * visit(class ASTidvariable *);
	int visit(class ASTstatement * );
	bool visit(class ASTexpression * );
	bool visit(class ASTfirstexpr * );
	bool visit(class ASTtermexpr * );
	int  visit(class ASTvalue * );
	int  visit(class ASTsingleexpr * );
	int  visit(class ASTbinaryexpr * );
	int visit(class ASTforloop * );
	int visit(class ASTwhileloop * );
	int visit(class ASTread * );
	void * visit(class ASTprintexpr * ,int fl);
	int visit(class ASTprint * );
	int visit(class ASTprintln * );
	int visit(class ASTassignment * );
	int visit(class ASTlabel * );
	int visit(class ASTifelse * );
	int visit(class ASTif * );
	int visit(class ASTgoto * );
};