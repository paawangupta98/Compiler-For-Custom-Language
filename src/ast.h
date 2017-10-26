#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "visitor.h"
#define TAB 1

using namespace std;

// Classes Declaration 
class ASTidvariable;
class ASTDeclBlock;
class ASTProgram;
class ASTforloop;
class ASTstatement;
class ASTwhileloop;
class ASTexpression;
class ASTsingleexpr;
class ASTfirstexpr;
class ASTvalue;
class ASTtermexpr;
class ASTbinaryexpr;
class ASTassignment;
class ASTprint;
class ASTprintln;
class ASTprint;
class ASTgoto;
class ASTread;
class ASTif;
class ASTifelse;
class ASTprintexpr;
class ASTlabel;

union Node{
    int intval;
    bool boolval;
    char charval;
    char *stringval;
    ASTProgram* program;
    vector<ASTDeclBlock*>* dec_states;
    ASTDeclBlock* dec_state;
    vector<ASTidvariable *>* declare_var;
    vector<ASTstatement *>* statement_seg;
    ASTstatement * statement;
    ASTexpression * expr;
    vector<ASTtermexpr *>* expr1;
    ASTtermexpr * TERM;
    vector<ASTfirstexpr *>* TERM1;
    ASTfirstexpr * FIRST_COMP;
    ASTsingleexpr * single_expr;
    ASTvalue * FINALTERM;
    std::vector<ASTprintexpr * >* print_expr;
    ASTread * read_state;
    ASTstatement * IF_ELSE;
};
typedef union Node YYSTYPE;

// arithematic operations
enum class arithematic_op {
    plus,  
    sub, 
    mult,
    div,  
    mod
};
//relation operations
enum relative_op
{
    less_than,
    greater_than,
    less_than_equal,
    greater_than_equal,
    double_equal,
    not_equal,
    equal
};

// assignment orperators
enum class assign_op {
    equal,
    plus_equal,
    minus_equal
};

// datatypes 
enum class datatype {
    int_type,
    bool_type
};


class ASTProgram {
    vector<ASTDeclBlock*> *declBlock;
    vector<ASTstatement*> *codeBlock;
    public:
        ASTProgram(vector<ASTDeclBlock*>* declBlock, vector<ASTstatement*>* codeBlock) 
        {
            this->declBlock = declBlock;
            this->codeBlock = codeBlock;
        }
        ~ASTProgram() {}
        vector<ASTDeclBlock*>* getdeclBlock(){return this->declBlock;}
        vector<ASTstatement*>* getcodeBlock(){ return this->codeBlock; }
        void * accept(Visitors  * v) {
            return v->visit(this);
        }
};


class ASTDeclBlock {
    datatype type;
    vector < ASTidvariable *> * idvector;
    public:
        ASTDeclBlock(datatype type, vector < ASTidvariable *> * idvector){this -> type = type;this -> idvector = idvector;}
        ~ASTDeclBlock(){}

        datatype getType(){ return this -> type; }
        vector < ASTidvariable *> * getIdList(){ return this -> idvector; }
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTidvariable{
    string id;
    int size;
    string typed;
    public:
        ASTidvariable(string typed , string id , int size) { this -> id = id; this->typed=typed;this->size=size;}
        ~ASTidvariable(){}

        string getId(){ return this -> id; }
        string getTyped(){return this->typed;}
        int getSize(){return this->size;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTstatement{
    public:
        ASTstatement() {}
        ~ASTstatement(){}
        virtual void * accept(Visitors *v) = 0;
};

class ASTlabel : public ASTstatement{
    string label;
    public:
        ASTlabel(string label) {this->label=label;}
        ~ASTlabel(){}
        string getlabel(){return this->label;} 
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTforloop : public ASTstatement{
    string id;
    ASTvalue * step;
    ASTvalue * start;
    ASTvalue * end;
    std::vector<ASTstatement*>* substate;
    public:
        ASTforloop(string id , ASTvalue * start , ASTvalue * end , ASTvalue * step , vector <ASTstatement*>* substate) {this->id = id;this->start = start; this->end = end; this->step=step;this->substate=substate;}
        ~ASTforloop() {}
        string getId(){ return this->id;}
        ASTvalue * getstep(){ return this->step;}
        ASTvalue * getstart(){ return this->start;}
        ASTvalue * getend(){ return this->end;}
        vector <ASTstatement*>* getsubstate(){ return this->substate;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTwhileloop : public ASTstatement{
    ASTexpression * expr;
    std::vector<ASTstatement*>* substate;
    public:
        ASTwhileloop(ASTexpression * expr, vector <ASTstatement*>* substate) {this->expr=expr;this->substate=substate;}
        ~ASTwhileloop() {}
        ASTexpression* getexpr(){ return this->expr;}
        vector <ASTstatement*>* getsubstate(){ return this->substate;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTassignment : public ASTstatement{
    string typed;
    string id;
    ASTsingleexpr * finalterm;
    ASTsingleexpr * expr1;
    public:
        ASTassignment(string typed , string id , ASTsingleexpr * finalterm ,ASTsingleexpr * expr1 ){this->typed = typed; this->id=id;this->expr1=expr1;this->finalterm=finalterm;}
        ASTassignment(string typed , string id , ASTsingleexpr * expr1 ){this->typed = typed; this->id=id;this->expr1=expr1;}
        ~ASTassignment(){}
        string getTyped(){return this->typed;}
        string getId(){return this->id;}
        ASTsingleexpr * getexpr(){return this->expr1;}
        ASTsingleexpr * getval(){return this->finalterm;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTgoto : public ASTstatement{
    string id;
    ASTexpression * expr1;
    public:
        ASTgoto(string id , ASTexpression * expr1 ){this->id=id;this->expr1=expr1;}
        ~ASTgoto(){}
        string getId(){return this->id;}
        ASTexpression * getexpr(){return this->expr1;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTread : public ASTstatement{
    string typed;
    string id;
    ASTsingleexpr * finalterm;
    public:
        ASTread(string typed , string id , ASTsingleexpr * finalterm ){this->typed=typed;this->id=id;this->finalterm=finalterm;}
        ASTread(string typed , string id ){this->typed=typed;this->id=id;this->finalterm=NULL;}
        ~ASTread(){}
        string getTyped(){return this->typed;}
        string getId(){return this->id;}
        ASTsingleexpr * getval(){return this->finalterm;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTif : public ASTstatement{
    ASTexpression * expr;
    std::vector<ASTstatement*>* substate;
    public:
        ASTif(ASTexpression * expr, vector <ASTstatement*>* substate) {this->expr=expr;this->substate=substate;}
        ~ASTif() {}
        ASTexpression* getexpr(){ return this->expr;}
        vector <ASTstatement*>* getsubstate(){ return this->substate;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTifelse : public ASTstatement{
    ASTexpression * expr;
    std::vector<ASTstatement*>* substate1;
    std::vector<ASTstatement*>* substate2;
    public:
        ASTifelse(ASTexpression * expr, vector <ASTstatement*>* substate1 , vector <ASTstatement*>* substate2) {this->expr=expr;this->substate1=substate1;this->substate2=substate2;}
        ~ASTifelse() {}
        ASTexpression* getexpr(){ return this->expr;}
        vector <ASTstatement*>* getsubstate1(){ return this->substate1;}
        vector <ASTstatement*>* getsubstate2(){ return this->substate2;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTprint : public ASTstatement{
    std::vector<ASTprintexpr*>* substate;
    public:
        ASTprint(std::vector<ASTprintexpr*>* substate) {this->substate=substate;}
        ~ASTprint() {}
        vector <ASTprintexpr*>* getsubstate(){ return this->substate;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTprintexpr{
    ASTvalue * val;
    string str;
    public:
        ASTprintexpr(ASTvalue * val,string str){this->val = val;this->str=str;}
        ~ASTprintexpr(){}
        ASTvalue * getval(){return this->val;}
        string getstring(){return this->str;}
        void * accept(Visitors *v , int x) {
            return v->visit(this , x);
        }
};

class ASTprintln : public ASTstatement{
    std::vector<ASTprintexpr*>* substate;
    public:
        ASTprintln(std::vector<ASTprintexpr*>* substate) {this->substate=substate;}
        ~ASTprintln() {}
        vector <ASTprintexpr*>* getsubstate(){ return this->substate;}
        void * accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTexpression {
    std::vector<ASTtermexpr *>* term;
    public:
        ASTexpression(std::vector<ASTtermexpr*>* term) {this->term = term;}
        ~ASTexpression() {}
        std::vector<ASTtermexpr*>* getterm(){return this->term;}
        bool accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTtermexpr {
    std::vector<ASTfirstexpr*>*firstexpr;
    public:
        ASTtermexpr(std::vector<ASTfirstexpr*>* v){this->firstexpr=v;}
        ~ASTtermexpr(){}
        std::vector<ASTfirstexpr*>* getfirstexpr(){return this->firstexpr;}
        bool accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTfirstexpr {
    ASTsingleexpr * left;
    ASTsingleexpr * right;
    relative_op op;
    public:
        ASTfirstexpr(ASTsingleexpr * left , relative_op op , ASTsingleexpr * right){this->left = left;this->op=op;this->right=right;}
        ~ASTfirstexpr(){}
        ASTsingleexpr * getleft(){return this->left;}
        ASTsingleexpr * getright(){return this->right;}
        relative_op getrelop(){return this->op;}
        bool accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTsingleexpr {
    public:
        ASTsingleexpr(){}
        ~ASTsingleexpr(){}
        virtual int  accept(Visitors *v) = 0 ;
};

class ASTvalue : public ASTsingleexpr{
    string typed;
    string id;
    int val;
    ASTsingleexpr * expr1;
    public:
        ASTvalue(string typed , string id){this->typed = typed; this->id=id;}
        ASTvalue(string typed , int val){this->typed = typed; this->val=val;}
        ASTvalue(string typed , string id , ASTsingleexpr * expr1 ){this->typed = typed; this->id=id;this->expr1=expr1;}
        ~ASTvalue(){}
        string getTyped(){return this->typed;}
        string getId(){return this->id;}
        int getval(){return this->val;}
        ASTsingleexpr * getexpr(){return this->expr1;}
        int  accept(Visitors *v) {
            return v->visit(this);
        }
};

class ASTbinaryexpr : public ASTsingleexpr{
    ASTsingleexpr * left;
    ASTsingleexpr * right;
    arithematic_op op;
    public:
        ASTbinaryexpr(ASTsingleexpr * left , arithematic_op op , ASTsingleexpr * right){this->left = left;this->op=op;this->right=right;}
        ~ASTbinaryexpr(){}
        ASTsingleexpr * getleft(){return this->left;}
        ASTsingleexpr * getright(){return this->right;}
        arithematic_op getariop(){return this->op;}
        int  accept(Visitors *v) {
            return v->visit(this);
        }
};

