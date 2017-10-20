#include <stdio.h>
using namespace std;

class ASTBlock;
class ASTProgram;
class ASTCallout;
class ASTLiteral;
class ASTIdComma;
class ASTIdCommas;
class ASTArgument;
class ASTLocation;
class ASTStatement;
class ASTMethodCall;
class ASTIntLiteral;
class ASTExpression;
class ASTCharLiteral;
class ASTBoolLiteral;
class ASTIfStatement;
class ASTVarLocation;
class ASTForStatement;
class ASTArrayLocation;
class ASTVarIdentifier;
class ASTNameMethodCall;
class ASTAssignOperator;
class ASTBreakStatement;
class ASTBlockStatement;
class ASTVarDeclaration;
class ASTUnaryExpression;
class ASTIfElseStatement;
class ASTReturnStatement;
class ASTArrayIdentifier;
class ASTCalloutArgument;
class ASTBinaryExpression;
class ASTFieldDeclaration;
class ASTMethodDeclaration;
class ASTContinueStatement;
class ASTAssignmentStatement;
class ASTCalloutArgumentExpr;
class ASTCalloutArgumentString;

class visitor{
  public:
    virtual void * visit (ASTProgram *) = 0;
    virtual void * visit (ASTFieldDeclaration *) = 0;
    virtual void * visit (ASTVarIdentifier *) = 0;
    virtual void * visit (ASTArrayIdentifier *) = 0;
    virtual void * visit (ASTIdCommas *) = 0;
    virtual void * visit (ASTVarDeclaration *) = 0;
    virtual void * visit (ASTReturnStatement *) = 0;
    virtual void * visit (ASTIntLiteral *) = 0;
    virtual void * visit (ASTBinaryExpression*) = 0;
    virtual void * visit (ASTBlock *) = 0;
    virtual void * visit (ASTBlockStatement *) = 0;
    virtual void * visit (ASTContinueStatement*) = 0;
    virtual void * visit (ASTBoolLiteral *) = 0;
    virtual void * visit (ASTCharLiteral *) = 0;
    virtual void * visit (ASTUnaryExpression *) = 0;
    virtual void * visit (ASTNameMethodCall *) = 0;
    virtual void * visit (ASTVarLocation *) = 0;
    virtual void * visit (ASTArrayLocation *) = 0;
    virtual void * visit (ASTBreakStatement*) = 0;
    virtual void * visit (ASTCalloutArgumentExpr *) = 0;
    virtual void * visit (ASTCalloutArgumentString *) = 0;
    virtual void * visit (ASTCallout *) = 0;  
    virtual void * visit (ASTAssignmentStatement *) = 0;
    virtual void * visit (ASTIfStatement *) = 0;
    virtual void * visit (ASTIfElseStatement *) = 0;
    virtual void * visit (ASTForStatement*) = 0;
};