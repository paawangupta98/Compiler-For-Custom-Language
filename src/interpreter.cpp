#include "ast.h"
#include <bits/stdc++.h>
using namespace std;

std::map<string, int> m_int;
std::map<string, vector<int> > m_array;
std::map<string, int > m_array_size;
std::map<string, vector<int> >::iterator ia1;
std::map<string, int>::iterator ii1;
std::vector<string>errors;
string label = "";
void * Visitors::visit (class ASTProgram * node)
{
	vector<ASTDeclBlock*> *vardecls = node->getdeclBlock();
	if(vardecls)
	{
		for (auto it = (*vardecls).rbegin(); it != (*vardecls).rend(); ++it)
		{
			(*it)->accept(this);
		}
	}
	map<string , int>ltable;
	int n = (*node->getcodeBlock()).size();
	if(node->getcodeBlock())
	{
		for (int i=n-1;i>=0;i--)
		{
			if((*node->getcodeBlock())[i].second=="")
			{;}
			else
			{
				ltable.insert(make_pair(((*node->getcodeBlock())[i].second) , i ));
			}
		}
	}
	if(node->getcodeBlock())
	{
		for (int i=n-1;i>=0;)
		{
			int x = (*node->getcodeBlock())[i].first->accept(this);
			// cout<<"x = "<<x<<endl;
			if(x==5)
			{
				if(ltable.find(label)!=ltable.end())
					i = ltable[label];
				else
					i--;
				// cout<<"i = "<<i<<endl;
			}
			else
				i--;
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

int Visitors::visit (class ASTprint * node)
{
	if(node->getsubstate())
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
		{
			(*it)->accept(this , 0);
		}
	}
	return 0;
}

int Visitors::visit (class ASTprintln * node)
{
	if((node->getsubstate())->size()>0)
	{
		for (auto it = (*node->getsubstate()).rbegin(); it != (*node->getsubstate()).rend(); ++it)
		{
			(*it)->accept(this , 1);
		}
	}
	else
	{
		cout<<"\n";
	}
	return 0;
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

int Visitors::visit (class ASTforloop * node)
{
	int step = (node->getstep())->accept(this);
	int s = (node->getstart())->accept(this);
	int e = (node->getend())->accept(this);
	map<string , int>ltable;
	int n = (*node->getsubstate()).size();
	for (int i=n-1;i>=0;i--)
	{
		if((*node->getsubstate())[i].second=="")
		{;}
		else
		{
			ltable.insert(make_pair(((*node->getsubstate())[i].second) , i ));
		}
	}
	for (int i = s; i <= e; i+=step)
	{
		if(node->getsubstate())
		{
			m_int[node->getId()] = i;
			for (int j=n-1;j>=0;)
			{
				int x = (*node->getsubstate())[j].first->accept(this);
				if(x==5)
				{
					if(ltable.find(label)!=ltable.end())
						j = ltable[label];
					else
						j--;
				}
				else
					j--;
			}
		}
	}
	return 0;
}
int Visitors::visit (class ASTwhileloop * node)
{
	map<string , int>ltable;
	int n = (*node->getsubstate()).size();
	for (int i=n-1;i>=0;i--)
	{
		if((*node->getsubstate())[i].second=="")
		{;}
		else
		{
			ltable.insert(make_pair(((*node->getsubstate())[i].second) , i ));
		}
	}
	while((node->getexpr())->accept(this) == true)
	{
		for (int j=n-1;j>=0;)
		{
			int x = (*node->getsubstate())[j].first->accept(this);
			if(x==5)
			{
				if(ltable.find(label)!=ltable.end())
					j = ltable[label];
				else
					j--;
			}
			else
				j--;
		}
	}
	return 0;
}
int Visitors::visit (class ASTread * node)
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
	return 0 ;
}
int Visitors::visit (class ASTassignment * node)
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
	return 0;
}
int Visitors::visit (class ASTgoto * node)
{
	if(node->getexpr()==NULL)
	{
		label = node->getId();
		return 5;
	}
	else
	{
		bool val = (node->getexpr())->accept(this);
		label = node->getId();
		if(val)
			return 5;
		else
			return 0;
	}
	return 0 ;
}
int Visitors::visit (class ASTifelse * node)
{
	if((node->getexpr())->accept(this) == true)
	{
		map<string , int>ltable;
		int n = (*node->getsubstate1()).size();
		for (int i=n-1;i>=0;i--)
		{
			if((*node->getsubstate1())[i].second=="")
			{;}
			else
			{
				ltable.insert(make_pair(((*node->getsubstate1())[i].second) , i ));
			}
		}
		for (int j=n-1;j>=0;)
		{
			int x = (*node->getsubstate1())[j].first->accept(this);
			if(x==5)
			{
				if(ltable.find(label)!=ltable.end())
					j = ltable[label];
				else
					j--;
			}
			else
				j--;
		}
	}
	else
	{
		map<string , int>ltable;
		int n = (*node->getsubstate2()).size();
		for (int i=n-1;i>=0;i--)
		{
			if((*node->getsubstate2())[i].second=="")
			{;}
			else
			{
				ltable.insert(make_pair(((*node->getsubstate2())[i].second) , i ));
			}
		}
		for (int j=n-1;j>=0;)
		{
			int x = (*node->getsubstate2())[j].first->accept(this);
			if(x==5)
			{
				if(ltable.find(label)!=ltable.end())
					j = ltable[label];
				else
					j--;
			}
			else
				j--;
		}
	}	
	return 0;
}
int Visitors::visit (class ASTif * node)
{
	if((node->getexpr())->accept(this) == true)
	{
		map<string , int>ltable;
		int n = (*node->getsubstate()).size();
		for (int i=n-1;i>=0;i--)
		{
			if((*node->getsubstate())[i].second=="")
			{;}
			else
			{
				ltable.insert(make_pair(((*node->getsubstate())[i].second) , i ));
			}
		}
		for (int j=n-1;j>=0;)
		{
			int x = (*node->getsubstate())[j].first->accept(this);
			if(x==5)
			{
				if(ltable.find(label)!=ltable.end())
					j = ltable[label];
				else
					j--;
			}
			else
				j--;
		}
	}
	return 0;
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
