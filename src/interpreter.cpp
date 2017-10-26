#include "ast.h"
#include <bits/stdc++.h>
using namespace std;

std::map<string, int> m_int;
std::map<string, vector<int> > m_array;
std::map<string, int > m_array_size;
std::map<string, vector<int> >::iterator ia1;
std::map<string, int>::iterator ii1;
std::vector<string>errors;
void * Visitors::visit (class ASTProgram * node)
{
	vector<ASTDeclBlock*> *vardecls = node->getdeclBlock();
    vector<ASTstatement*> *mystatements = node->getcodeBlock();
    if(vardecls)
    {
    	for (auto it = (*vardecls).rbegin(); it != (*vardecls).rend(); ++it)
    	{
    		(*it)->accept(this);
    	}
    }
    if(mystatements)
    {
    	for (auto it = (*mystatements).rbegin(); it != (*mystatements).rend(); ++it)
    	{
    		if(*it)
    			(*it)->accept(this);
    	}
    }
    for (int i = 0; i < errors.size(); ++i)
    {
    	cout<<"ERROR : "<<errors[i]<<endl;
    }
}

void * Visitors::visit (class ASTDeclBlock * node)
{
	if(node->getIdList())
	{
		for (auto it = (*node->getIdList()).rbegin(); it != (*node->getIdList()).rend(); ++it)
    	{
    		(*it)->accept(this);
    	}
	}
}

void * Visitors::visit (class ASTidvariable * node)
{
	string id = node->getId();
	string type = node->getTyped();
	if(type=="id")
	{
		ii1 = m_int.find(id);
		if(ii1!=m_int.end())
			errors.push_back("Redeclaration of " + id);
		m_int.insert(make_pair(id , 0));
	}
	else if(type=="array")
	{
		vector<int> v(node->getSize(),0);
		m_array.insert(make_pair(id ,v ));
		m_array_size.insert(make_pair(id , node->getSize() ));
	}
}

void * Visitors::visit (class ASTprint * node)
{
	if(node->getsubstate())
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
    	{
    		(*it)->accept(this , 0);
    	}
	}
}

void * Visitors::visit (class ASTprintln * node)
{
	if(node->getsubstate())
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
    	{
    		(*it)->accept(this , 1);
    	}
	}
}

void * Visitors::visit (class ASTprintexpr * node , int fl)
{
	if(node->getstring()=="")
	{
		int val = (node->getval())->accept(this);
		if(fl==0)
			cout<<val<<" ";
		else
			cout<<val<<"\n";
	}
	else if(node->getval()==NULL)
	{
		string val = node->getstring();
		if(fl==0)
			cout<<val<<" ";
		else
			cout<<val<<"\n";
	}
}

void * Visitors::visit (class ASTlabel * node)
{
	// string st =  node->getstring();
	cout<<"hahah"<<endl;
}
void * Visitors::visit (class ASTforloop * node)
{
	int step = (node->getstep())->accept(this);
	int s = (node->getstart())->accept(this);
	int e = (node->getend())->accept(this);
	for (int i = s; i <= e; i+=step)
	{
		if(node->getsubstate())
	    {
	    	m_int[node->getId()] = i;
	    	for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
	    	{
	    		if(*it)
	    			(*it)->accept(this);
	    	}
	    }
	}
}
void * Visitors::visit (class ASTwhileloop * node)
{
	while((node->getexpr())->accept(this) == true)
	{
		if(node->getsubstate())
	    {
	    	for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
	    	{
	    		if(*it)
	    			(*it)->accept(this);
	    	}
	    }
	}
}
void * Visitors::visit (class ASTread * node)
{
	int val;cin>>val;
	if(node->getTyped()=="int")
	{
		m_int[node->getId()] = val;
	}
	else if(node->getTyped()=="array")
	{
		int index = (node->getval())->accept(this);
		m_array[node->getId()][index] = val;
	}
}
void * Visitors::visit (class ASTassignment * node)
{
	if(node->getTyped()=="id")
	{
		int val = (node->getexpr())->accept(this);
		m_int[node->getId()] = val;
	}
	else if(node->getTyped()=="array")
	{
		int val = (node->getexpr())->accept(this);
		int index = (node->getval())->accept(this);
		m_array[node->getId()][index] = val;
	}
}
void * Visitors::visit (class ASTgoto * node)
{
	// string st =  node->getstring();
	cout<<"hahah"<<endl;
}
void * Visitors::visit (class ASTifelse * node)
{
	if((node->getexpr())->accept(this) == true)
	{
		if(node->getsubstate1())
	    {
	    	for (auto it = (*node->getsubstate1()).rbegin(); it != (*node->getsubstate1()).rend(); ++it)
	    	{
	    		if(*it)
	    			(*it)->accept(this);
	    	}
	    }
	}
	else
	{
		if(node->getsubstate2())
	    {
	    	for (auto it = (*node->getsubstate2()).rbegin(); it != (*node->getsubstate2()).rend(); ++it)
	    	{
	    		if(*it)
	    			(*it)->accept(this);
	    	}
	    }
	}	
}
void * Visitors::visit (class ASTif * node)
{
	if((node->getexpr())->accept(this) == true)
	{
		if(node->getsubstate())
	    {
	    	for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
	    	{
	    		if(*it)
	    			(*it)->accept(this);
	    	}
	    }
	}
}

bool Visitors::visit (class ASTexpression * node)
{
	bool ans = 0;
	if(node->getterm())
	{
		for (auto it = (*node->getterm()).rbegin(); it != (*node->getterm()).rend(); ++it)
    	{
    		ans = ans | ((*it)->accept(this));
    	}
	}
	else
		ans=1;
	// cout<<"for expr"<<ans<<endl;
	return ans;
}

bool Visitors::visit (class ASTtermexpr * node)
{
	bool ans = 1;
	if(node->getfirstexpr())
	{
		for (auto it = (*node->getfirstexpr()).rbegin(); it != (*node->getfirstexpr()).rend(); ++it)
    	{
    		ans = ans & ((*it)->accept(this));
    	}
	}
	else
		ans=1;
	// cout<<"for term"<<ans<<endl;
	return ans;
}

bool Visitors::visit (class ASTfirstexpr * node)
{
	int lhs = (node->getleft())->accept(this);
	int rhs = (node->getright())->accept(this);
	// cout<<lhs<<" rhs = "<<rhs<<endl;
	if(node->getrelop()==relative_op::less_than)
	{
		// cout<<"less_than\n";
		if(lhs<rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::less_than_equal)
	{
		// cout<<"less_than_equal\n";
		if(lhs<=rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::greater_than)
	{
		// cout<<"greater_than\n";
		if(lhs>rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::greater_than_equal)
	{
		// cout<<"greater_than_equal\n";
		if(lhs>=rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::double_equal)
	{
		// cout<<"double_equal\n";
		if(lhs==rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::not_equal)
	{
		// cout<<"not_equal\n";
		if(lhs!=rhs)
			return true;
		else 
			return false;
	}
	else if(node->getrelop()==relative_op::equal)
	{
		// cout<<"equal\n";
		return true;
	}
}

int Visitors::visit (class ASTvalue * node)
{
	int val;
	if(node->getTyped()=="int")
		val = node->getval();
	else if(node->getTyped()=="id")
		val = m_int[node->getId()];
	else if(node->getTyped()=="array")
	{
		int newval = (node->getexpr())->accept(this);
		val = m_array[node->getId()][newval];
	}
	return val;
}

int Visitors::visit (class ASTbinaryexpr * node)
{
	int lhs = (node->getleft())->accept(this);
	int rhs = (node->getright())->accept(this);
	int val;
	if(node->getariop()==arithematic_op::plus)
	{
		val = lhs+rhs;
	}
	else if(node->getariop()==arithematic_op::mult)
	{
		val = lhs*rhs;
	}
	else if(node->getariop()==arithematic_op::div)
	{
		val = lhs/rhs;
	}
	else if(node->getariop()==arithematic_op::sub)
	{
		val = lhs-rhs;
	}
	else if(node->getariop()==arithematic_op::mod)
	{
		val = lhs%rhs;
	}
	return val;
}