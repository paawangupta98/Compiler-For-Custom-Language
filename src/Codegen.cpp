#include "ast.h"
#include <bits/stdc++.h>
using namespace std;
using namespace llvm;

std::map<string, int> m_int1;
std::map<string, vector<int> > m_array1;
std::map<string, int > m_array_size1;
std::map<string, vector<int> >::iterator ia11;
std::map<string, int>::iterator ii11;
std::vector<string>errors1;
string label1 = "";
Function * createFunc(IRBuilder<>&Builder,	string	Name)	{
	FunctionType *funcType = FunctionType::get(Builder.getInt32Ty(),false);
	Function *fooFunc = Function::Create(funcType,Function::ExternalLinkage,Name,myModule);
	return	fooFunc;
}
BasicBlock	*createBB(Function	*fooFunc,string	Name)	{
	return	BasicBlock::Create(myContext,Name,fooFunc);
}
Function * mainFunc = createFunc(Builder,"main");
Constant * printFunc = myModule->getOrInsertFunction("printf",FunctionType::get(IntegerType::getInt32Ty(myContext), true) );
Constant * readFunc = myModule->getOrInsertFunction("scanf",FunctionType::get(IntegerType::getInt32Ty(myContext), true) );
std::vector<Value*> v_space;
std::vector<Value*> v_new;
std::vector<Value*> v_int;
std::vector<Value*> v_string;
Value * Codegen::visit (class ASTProgram * node)
{
	BasicBlock	*entry	=	createBB(mainFunc,	"entry");
	Builder.SetInsertPoint(entry);
	Value * newline = Builder.CreateGlobalStringPtr("\n");
	Value * spacechar = Builder.CreateGlobalStringPtr(" ");
	Value * intprint = Builder.CreateGlobalStringPtr("%d");
	Value * strprint = Builder.CreateGlobalStringPtr("%s");
	v_space.push_back(strprint);
	v_space.push_back(spacechar);
	v_new.push_back(strprint);
	v_new.push_back(newline);
	v_int.push_back(intprint);
	v_string.push_back(strprint);
	Value* v = ConstantInt::get(myContext, APInt(32,1));
	vector<ASTDeclBlock*> *vardecls = node->getdeclBlock();
	if(vardecls)
	{
		for (auto it = (*vardecls).rbegin(); it != (*vardecls).rend(); ++it)
		{
			v = (*it)->accept(this);
		}
	}
	
	int n = (*node->getcodeBlock()).size();
	if(node->getcodeBlock())
	{
		for (int i=n-1;i>=0;i--)
		{
			v = (*node->getcodeBlock())[i].first->accept(this);
		}
	}
	v = ConstantInt::get(myContext, APInt(32,1));
	Builder.CreateRet(v);
	verifyFunction(*mainFunc);
	// cout<<"Generating IR CODE\n";
	// std::error_code EC;
	// llvm::raw_fd_ostream OS("module.bcc", EC, llvm::sys::fs::F_None);
	// WriteBitcodeToFile(myModule, OS);
	// OS.flush();
	// fstream file ;
	// file.open("haha.bcc" , ios::out|ios::in);
	// file<<(myModule->dump());
	// file.close();
	myModule->dump();
	return v;
}
Value * Codegen::visit (class ASTDeclBlock * node)
{
	Value* v = ConstantInt::get(myContext, APInt(32,1));
	if(node->getIdList())
	{
		for (auto it = (*node->getIdList()).rbegin(); it != (*node->getIdList()).rend(); ++it)
		{
			v = (*it)->accept(this);
		}
	}
	return v;
}
Value * Codegen::visit (class ASTidvariable * node)
{
	Type * type = Type::getInt32Ty(myContext);
	string id = node->getId();
	string type1 = node->getTyped();
	ConstantInt* const_int_val = ConstantInt::get(myModule->getContext(), APInt(32,0));
	if(type1=="id")
	{
		myModule->getOrInsertGlobal(id,	Builder.getInt32Ty());
		GlobalVariable	*gv_id	=	myModule->getNamedGlobal(id);
		gv_id->setLinkage(GlobalValue::CommonLinkage);
		gv_id->setInitializer(const_int_val);
		gv_id->setAlignment(4);
	}
	else if(type1=="array")
	{
		ArrayType* arrType = ArrayType::get(type,node->getSize());
		PointerType* arrayptr = PointerType::get(ArrayType::get(type,node->getSize()),0);
		GlobalVariable* gv = new GlobalVariable(*myModule,arrType,false,GlobalValue::CommonLinkage,0,id);
		gv->setAlignment(4);
		gv->setInitializer(ConstantAggregateZero::get(arrType));
	}
	Value* v = ConstantInt::get(myContext, APInt(32,1));
	return v;
}
Value * Codegen::visit (class ASTassignment * node)
{
	Value* v = ConstantInt::get(myContext, APInt(32,1));
	Value* var = myModule->getGlobalVariable(node->getId());
	string typed = node->getTyped();
	if(typed=="array")
	{
		Value * index = (node->getval())->accept(this);
		index = Builder.CreateLoad(index);
	    vector<Value*> ar_index;
	    ar_index.push_back(Builder.getInt32(0));
	    ar_index.push_back(index);
	    var = Builder.CreateGEP(var, ar_index, node->getId()+"_Index");
	}
	Value * val = (node->getexpr())->accept(this);
	v =  Builder.CreateStore(val,var);
	return v;
}
Value * Codegen::visit (class ASTprint * node)
{
	std::vector<Value *> argsV;
	std::vector<Value *> newV;
	Value * v = ConstantInt::get(myContext, APInt(32,1));
	if(node->getsubstate())
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
		{
			newV = (*it)->accept(this , 0);
		}
	}
	return v;
}

Value * Codegen::visit (class ASTprintln * node)
{
	std::vector<Value *> newV;
	Value * v = ConstantInt::get(myContext, APInt(32,1));
	if(node->getsubstate())
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
		{
			newV = (*it)->accept(this , 1);
		}
	}
	// v = Builder.CreateCall(printFunc, argsV, "printfCall");
	return v;
}
std::vector<Value *> Codegen::visit (class ASTprintexpr * node , int fl)
{
	std::vector<Value *> args;
	Value * v = ConstantInt::get(myContext, APInt(32,1));
	
	if(node->getstring()=="")
	{
		v = (node->getval())->accept(this);
		v_int.push_back(v);
		v = Builder.CreateCall(printFunc, v_int, "printfCall");
		v_int.pop_back();
		if(fl==0)
		{
			v = Builder.CreateCall(printFunc, v_space, "printfCall");
		}
		else
		{
			v = Builder.CreateCall(printFunc, v_new, "printfCall");
		}
	}
	else if(node->getval()==NULL)
	{
		v = Builder.CreateGlobalStringPtr(node->getstring());
		v_string.push_back(v);
		v = Builder.CreateCall(printFunc, v_string, "printfCall");
		v_string.pop_back();
		if(fl==0)
		{
			v = Builder.CreateCall(printFunc, v_space, "printfCall");
		}
		else
		{
			v = Builder.CreateCall(printFunc, v_new, "printfCall");
		}
	}
	return args;
}

Value * Codegen::visit (class ASTforloop * node)
{
	Value * var = myModule->getGlobalVariable(node->getId());
	Value * val = (node->getstart())->accept(this);
	Value * rhs = (node->getend())->accept(this);
	Value * ans = node->getstep()->accept(this);
	BasicBlock * ForBB = createBB(mainFunc,"for");
	BasicBlock * ForcontBB = createBB(mainFunc,"forcont");
	BasicBlock * ContBB = createBB(mainFunc,"forcontinue");
	Value * v =  Builder.CreateStore(val,var);
	Builder.CreateBr(ForBB);
	Builder.SetInsertPoint(ForBB);
	Value * var1 = Builder.CreateLoad(var);
	Value * cond = Builder.CreateICmpULE(var1,rhs,"lecomparetmp");
	Builder.CreateCondBr(cond,	ForcontBB ,	ContBB);
	Builder.SetInsertPoint(ForcontBB);
	Value* ForVal = ConstantInt::get(myContext, APInt(32,1));
	int n = (*node->getsubstate()).size();
	for (int j=n-1;j>=0;j--)
	{
		ForVal = (*node->getsubstate())[j].first->accept(this);
	}
	var1 = Builder.CreateAdd(var1,ans,"addtmp");
	v =  Builder.CreateStore(var1,var);
	Builder.CreateBr(ForBB);
	Builder.SetInsertPoint(ContBB);
	ans = ConstantInt::get(myContext, APInt(32,1));
	return ans;
}
Value * Codegen::visit (class ASTwhileloop * node)
{
	BasicBlock * WhileBB = createBB(mainFunc,"while");
	BasicBlock * WhilecontBB = createBB(mainFunc,"whilecont");
	BasicBlock * ContBB = createBB(mainFunc,"whilecontinue");
	Builder.CreateBr(WhileBB);
	Builder.SetInsertPoint(WhileBB);
	Value * cond = (node->getexpr())->accept(this);
	Builder.CreateCondBr(cond,	WhilecontBB ,	ContBB);
	Builder.SetInsertPoint(WhilecontBB);
	Value* WhileVal = ConstantInt::get(myContext, APInt(32,1));
	int n = (*node->getsubstate()).size();
	for (int j=n-1;j>=0;j--)
	{
		WhileVal = (*node->getsubstate())[j].first->accept(this);
	}
	Builder.CreateBr(WhileBB);
	Builder.SetInsertPoint(ContBB);
	Value* ans = ConstantInt::get(myContext, APInt(32,1));
	return ans;
}
Value * Codegen::visit (class ASTgoto * node)
{}
Value * Codegen::visit (class ASTread * node)
{
	Value * var = myModule->getGlobalVariable(node->getId());
	v_int.push_back(var);
	Value *v = Builder.CreateCall(readFunc, v_int, "readCall");
	v_int.pop_back();
	return v;
}
Value * Codegen::visit (class ASTif * node)
{
	Value * cond = (node->getexpr())->accept(this);
	BasicBlock * IFBB = createBB(mainFunc,"if");
	BasicBlock * ContBB = createBB(mainFunc,"ifcontinue");
	Builder.CreateCondBr(cond,	IFBB , ContBB);
	Builder.SetInsertPoint(IFBB);
	Value* IFVal = ConstantInt::get(myContext, APInt(32,1));
	int n = (*node->getsubstate()).size();
	for (int j=n-1;j>=0;j--)
	{
		IFVal = (*node->getsubstate())[j].first->accept(this);
	}
	Builder.CreateBr(ContBB);
	// unsigned PhiBBSize = 1;
	Builder.SetInsertPoint(ContBB);
	// PHINode	*Phi = Builder.CreatePHI(Type::getInt32Ty(getGlobalContext()),PhiBBSize,"iftmp");
	// Phi->addIncoming(IFVal,IFBB);
	Value* ans = ConstantInt::get(myContext, APInt(32,1));
	return ans;
}
Value * Codegen::visit (class ASTifelse * node)
{
	Value * cond = (node->getexpr())->accept(this);
	BasicBlock * IFBB = createBB(mainFunc,"if");
	BasicBlock * ElseBB = createBB(mainFunc,"else");
	BasicBlock * ContBB = createBB(mainFunc,"ifelsecontinue");
	Builder.CreateCondBr(cond,	IFBB ,	ElseBB);
	Builder.SetInsertPoint(IFBB);
	Value* IFVal = ConstantInt::get(myContext, APInt(32,1));
	int n = (*node->getsubstate1()).size();
	for (int j=n-1;j>=0;j--)
	{
		IFVal = (*node->getsubstate1())[j].first->accept(this);
	}
	Builder.CreateBr(ContBB);
	Builder.SetInsertPoint(ElseBB);
	Value* ElseVal = ConstantInt::get(myContext, APInt(32,1));
	int m = (*node->getsubstate2()).size();
	for (int j=m-1;j>=0;j--)
	{
		ElseVal = (*node->getsubstate2())[j].first->accept(this);
	}
	Builder.CreateBr(ContBB);
	// unsigned PhiBBSize = 2;
	Builder.SetInsertPoint(ContBB);
	// PHINode	*Phi = Builder.CreatePHI(Type::getInt32Ty(getGlobalContext()),PhiBBSize,"ifelsetmp");
	// Phi->addIncoming(IFVal,IFBB);
	// Phi->addIncoming(ElseVal,ElseBB);
	Value* ans = ConstantInt::get(myContext, APInt(32,1));
	return ans;
}

Value * Codegen::visit (class ASTexpression * node)
{
	Value* ans = ConstantInt::get(myContext, APInt(1,0));
	if(node->getterm())
	{
		for (auto it = (*node->getterm()).rbegin(); it != (*node->getterm()).rend(); ++it)
		{
			ans = Builder.CreateOr(ans , (*it)->accept(this) , "OR");
		}
	}
	else
		ans=ConstantInt::get(myContext, APInt(1,1));
	return ans;
}

Value * Codegen::visit (class ASTtermexpr * node)
{
	Value* ans = ConstantInt::get(myContext, APInt(1,1));
	Value * v;
	if(node->getfirstexpr())
	{
		for (auto it = (*node->getfirstexpr()).rbegin(); it != (*node->getfirstexpr()).rend(); ++it)
		{
			v = (*it)->accept(this);
			ans = Builder.CreateAnd(ans , v , "AND");
		}
	}
	else
		ans=ConstantInt::get(myContext, APInt(1,1));
	return ans;
}

Value * Codegen::visit (class ASTfirstexpr * node)
{
	Value * lhs = (node->getleft())->accept(this);
	Value * rhs = (node->getright())->accept(this);
	// cout<<lhs<<" rhs = "<<rhs<<endl;
	Value * v;
	if(node->getrelop()==relative_op::less_than)
	{
		v = Builder.CreateICmpULT(lhs,rhs,"ltcomparetmp");
	}
	else if(node->getrelop()==relative_op::less_than_equal)
	{
		v = Builder.CreateICmpULE(lhs,rhs,"lecomparetmp");
	}
	else if(node->getrelop()==relative_op::greater_than)
	{
		v = Builder.CreateICmpUGT(lhs,rhs,"gtcomparetmp");
	}
	else if(node->getrelop()==relative_op::greater_than_equal)
	{
		v = Builder.CreateICmpUGE(lhs,rhs,"gecomparetmp");
	}
	else if(node->getrelop()==relative_op::double_equal)
	{
		v = Builder.CreateICmpEQ(lhs,rhs,"equalcomparetmp");
	}
	else if(node->getrelop()==relative_op::not_equal)
	{
		v = Builder.CreateICmpNE(lhs,rhs,"notequalcomparetmp");
	}
	else if(node->getrelop()==relative_op::equal)
	{
		v = ConstantInt::get(myContext, APInt(1,1));
	}
	return v;
}

Value * Codegen::visit (class ASTvalue * node)
{
	string typed = node->getTyped();
	Value* v = ConstantInt::get(myContext, APInt(32,1));
	// cout<<"haha1\n";
	Value* var = ConstantInt::get(myContext, APInt(32,node->getval()));
	// cout<<"haha2\n";
	if(typed=="id")
	{
		var = myModule->getGlobalVariable(node->getId());
		var = Builder.CreateLoad(var);
	}
	else if(typed=="array")
	{
		Value * index = (node->getexpr())->accept(this);
		index = Builder.CreateLoad(index);
	    vector<Value*> ar_index;
	    ar_index.push_back(Builder.getInt32(0));
	    ar_index.push_back(index);
	    var = Builder.CreateGEP(var, ar_index, node->getId()+"_Index");
	}
	return var;
}

Value * Codegen::visit (class ASTbinaryexpr * node)
{
	Value * lhs = (node->getleft())->accept(this);
	Value * rhs = (node->getright())->accept(this);
	Value * v;
	if(node->getariop()==arithematic_op::plus)
	{
		v = Builder.CreateAdd(lhs,rhs,"addtmp");
	}
	else if(node->getariop()==arithematic_op::mult)
	{
		v = Builder.CreateMul(lhs,rhs,"multtmp");
	}
	else if(node->getariop()==arithematic_op::div)
	{
		v = Builder.CreateUDiv(lhs,rhs,"divtmp");
	}
	else if(node->getariop()==arithematic_op::sub)
	{
		v = Builder.CreateSub(lhs,rhs,"subtmp");
	}
	else if(node->getariop()==arithematic_op::mod)
	{
		v = Builder.CreateURem(lhs,rhs,"modtmp");
	}
	return v;
}