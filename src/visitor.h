using namespace std;
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>
using namespace llvm;

static LLVMContext &myContext = getGlobalContext();
static IRBuilder<> Builder(myContext);
static Module *myModule = new Module("IR Generator",myContext);

// typedef llvm::Value Value ;
// class Visitors{
// public:
// 	virtual void * visit(class ASTProgram *)=0;
// 	virtual void * visit(class ASTDeclBlock *)=0;
// 	virtual void * visit(class ASTidvariable *)=0;
// 	virtual int visit(class ASTstatement * )=0;
// 	virtual bool visit(class ASTexpression * )=0;
// 	virtual bool visit(class ASTfirstexpr * )=0;
// 	virtual bool visit(class ASTtermexpr * )=0;
// 	virtual int  visit(class ASTvalue * )=0;
// 	virtual int  visit(class ASTsingleexpr * )=0;
// 	virtual int  visit(class ASTbinaryexpr * )=0;
// 	virtual int visit(class ASTforloop * )=0;
// 	virtual int visit(class ASTwhileloop * )=0;
// 	virtual int visit(class ASTread * )=0;
// 	virtual void * visit(class ASTprintexpr * ,int fl)=0;
// 	virtual int visit(class ASTprint * )=0;
// 	virtual int visit(class ASTprintln * )=0;
// 	virtual int visit(class ASTassignment * )=0;
// 	virtual int visit(class ASTlabel * )=0;
// 	virtual int visit(class ASTifelse * )=0;
// 	virtual int visit(class ASTif * )=0;
// 	virtual int visit(class ASTgoto * )=0;
// };

class Interpreter {
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

class Codegen {
	public:
	Value * visit(class ASTProgram *);
	Value * visit(class ASTDeclBlock *);
	Value * visit(class ASTidvariable *);
	Value * visit(class ASTstatement * );
	Value * visit(class ASTexpression * );
	Value * visit(class ASTfirstexpr * );
	Value * visit(class ASTtermexpr * );
	Value * visit(class ASTvalue * );
	Value * visit(class ASTsingleexpr * );
	Value * visit(class ASTbinaryexpr * );
	Value * visit(class ASTforloop * );
	Value * visit(class ASTwhileloop * );
	Value * visit(class ASTread * );
	Value * visit(class ASTprintexpr * ,int fl);
	Value * visit(class ASTprint * );
	Value * visit(class ASTprintln * );
	Value * visit(class ASTassignment * );
	Value * visit(class ASTlabel * );
	Value * visit(class ASTifelse * );
	Value * visit(class ASTif * );
	Value * visit(class ASTgoto * );
};