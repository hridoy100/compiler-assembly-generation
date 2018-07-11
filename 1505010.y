%{
#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cstring>
#include<string>
#include<cmath>
#include<fstream>
//#include "symbol.h"
#include "1505010.h"
#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE *fp2, *fp3;
extern int line_num;
extern int error;
extern FILE *logout, *tokenout;
//extern SymbolTable *sym;
int flag =0;
int errFlag=0;
SymbolTable *table;
extern char* yytext;
//extern YYSTYPE yylval;

void yyerror(const char *s)
{
	printf("myerror: %s\n",s);
	error++;
	return;
	//write your code
}

void printError(string s, int line_num){
	if(errFlag==0){
	fprintf(fp3, "Error at Line %d: %s\n\n", line_num, s.c_str()); 
	errFlag=1;
	error++;
	}
}



int labelCount=0;
int tempCount=0;


string newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return string(lb);
}

string newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return string(t);
}



%}

%token IF ELSE FOR WHILE
%token INT FLOAT DOUBLE CHAR RETURN VOID
%token PRINTLN ADDOP MULOP ASSIGNOP RELOP LOGICOP NOT
%token SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP
%token CONST_INT CONST_FLOAT ID MAIN
%token DO SWITCH DEFAULT BREAK CASE CONTINUE CONST_CHAR BITOP

%left '+' '-'
%left '*' '/' 
//%right

%nonassoc '|'
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%error-verbose

%%

start : program
	{
		//printf("At line no: %d start : program\n\n", line_num);
		//fprintf(fp2,"At line no: %d start : program\n\n", line_num);		
		//printf("\t%.10g\n",$1->getName()); 	
		//write your code in this block in all the similar blocks below
		//printf("%s\n", $1->getName().c_str());
		$$->setType("start");
		//fprintf(fp2,"%s\n\n",$$->getName().c_str());	
		
		fprintf(fp2,"\tSymbol Table: \n\n");		
		table->printAllScope(fp2); 
		fprintf(fp2,"Total Lines: %d\n\n", line_num);
		fprintf(fp2,"Total Errors: %d\n\n", error);	
		
		if(error>0) {
			fprintf(fp3, "Total Errors: %d\n\n", error);
		}	
		
		ofstream codeOut;
		codeOut.open("code.asm");
		codeOut << $1->code;
		
	}
	;

program : program unit {
			//printf("At line no: %d program : program unit\n\n", line_num);
			fprintf(fp2, "At line no: %d program : program unit\n\n", line_num);
	
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("program");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
	
			}
	| unit {
		//printf("At line no: %d program : unit\n\n", line_num);
		fprintf(fp2, "At line no: %d program : unit\n\n", line_num);
	
		//printf("%s\n\n", $1->getName().c_str());
		//$$->setType("program");
		fprintf(fp2,"%s\n\n",$$->getName().c_str());
		}
	;
	
unit : var_declaration {
			//printf("At line no: %d unit : var_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : var_declaration\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			$$->setType($1->getType());
			$$->type = $1->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
     | func_declaration {
			//printf("At line no: %d unit : func_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : func_declaration\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
	
			}
     | func_definition {
			//printf("At line no: %d unit : func_definition\n\n", line_num);
			fprintf(fp2, "At line no: %d unit : func_definition\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unit");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
	
			}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
			//printf("At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n", line_num);
	
			//printf("%s %s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str());	
			
			string b = $2->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, $2->getType().c_str(), fp2);
				 s = table->lookUp(b);
				 s->type = $1->getType().c_str();
				 s->type = $1->type.c_str();
				 
				 //s->functionParameters = $4->getName().c_str();
			}
			else{
				string err = "Multiple Declaration of ";
				err.append(b);
				printError(err, line_num);
			}
			
			vector <string> tokens;
			stringstream check1($4->getName().c_str());
			string intermediate;
			string intermediate2;
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, ',')){
					tokens.push_back(intermediate2);
					//s->functionParameters.push_back(intermediate2);
				}
				else {
				tokens.push_back(intermediate);
				//s->functionParameters.push_back(intermediate);
				
				}
			}
			
			for(int i=0; i<tokens.size(); i++) {
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float"))
			{	
				SymbolInfo *s2 = table->lookUp(tokens[i]);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					//table->insert(b, "ID",  fp2);
					//s2 = table->lookUp(b);
					size_t foundArray = tokens[i].find('[');
					if(!tokens[i-1].compare("int")){
						if(foundArray!=string::npos)
						{
							//s2->type = "INT_ARRAY";
							s->functionParameters.push_back("INT_ARRAY");
							//fprintf(fp3, "added to function parameters INT_ARRAY\n");
							
						}
						else {
							//s2->type = "INT";
							s->functionParameters.push_back("INT");
							//fprintf(fp3, "added to function parameters INT\n");
						
						}
					}
					else if(!tokens[i-1].compare("double"))
					{	
						//s2->type = "DOUBLE";
						s->functionParameters.push_back("DOUBLE");
						//fprintf(fp3, "added to function parameters DBL\n");
					}
					else if(!tokens[i-1].compare("FLOAT"))
					{
						//s2->type = "FLOAT";
						s->functionParameters.push_back("FLOAT");
						//fprintf(fp3, "added to function parameters FLT\n");
						
					}
					//s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
			}
			}
	
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append($6->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("func_declaration");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			
			errFlag=0;
			}
		| type_specifier ID LPAREN RPAREN SEMICOLON {
			//printf("At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON \n\n", line_num);
	
			//printf("%s %s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());	
	
			string b = $2->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, $2->getType().c_str(), fp2);
				 s = table->lookUp(b);
				// s->type = $1->getType().c_str();
				 s->type = $1->type.c_str();
				 
				 //s->functionParameters = " ";
			}
			else{
				string err = "Multiple Declaration of ";
				err.append(b);
				printError(err, line_num);
			}
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("func_declaration");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			errFlag=0;
			}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN {
		
		
		/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1")) 
		table->insert($2->getName().c_str(), $2->getType().c_str(), fp2); 
		*/
		int declared=0;
		string b = $2->getName().c_str();
		b.append(" ");
		SymbolInfo *s = table->lookUp(b);
		
		if(!s->getName().compare("-1"))
		{				
			 table->insert(b, $2->getType().c_str(), fp2);
			 s = table->lookUp(b);
			 s->type = $1->getType().c_str();
			 s->defined = true;
			 //s->functionParameters = $4->getName().c_str();
		}
		else
		{
			s->defined = true;
			declared=1;
			//if($1->getType().compare(s->type)) //declaration type and definition type not same..
			if($1->type.compare(s->type)) //declaration type and definition type not same..
			
			{
				string er = "Return Type Mismatch With Declaration Conflicting Type For: ";
				er.append(s->getName().c_str());
				//er.append("'");
				
				printError(er, line_num);
			}
		}
		
			
		//function age theke declare kora thakle new kore kichu add krbe na scope table e..
		
		table->enterScope(fp2);
		flag=1;
		SymbolInfo *para = $4;
		string pList = para->getName().c_str();
		//fprintf(fp2, "parameterList: %s , %s\n\n", pList.c_str(), s->getType().c_str());
		//int spaces = count(pList.begin(), pList.end(), ' ' );
		
		vector <string> tokens;
		stringstream check1(pList);
		string intermediate;
		string intermediate2;
		
		while(getline(check1, intermediate, ' ')){
			stringstream check2(intermediate);
			string intermediate2;
			if(getline(check2, intermediate2, ',')){
				tokens.push_back(intermediate2);
				while(getline(check2, intermediate2, ',')){
					tokens.push_back(intermediate2);
				}
			
				//s->functionParameters.push_back(intermediate2);
			}
			else {
			tokens.push_back(intermediate);
			//s->functionParameters.push_back(intermediate);
			
			}
		}
		int j=0;
		
		for(int i=0; i<tokens.size(); i++) {
			
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float"))
			{	
				string var = tokens[i];
				var.append(" ");
				//SymbolInfo *s2 = table->lookUp(tokens[i]);
				//look up on current scope
				SymbolInfo *s2 = table->lookUpCur(var);
				
				
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					size_t foundArray = tokens[i].find('[');
					if(!tokens[i-1].compare("int"))
					{
						if(foundArray!=string::npos)
						{
							s2->type = "INT_ARRAY";
							//s->functionParameters.push_back("INT_ARRAY");
							if(declared==0) s->functionParameters.push_back("INT_ARRAY");
							//fprintf(fp3, "added to function parameters INT_ARRAY\n");
							
						}
						else {
							s2->type = "INT";
							//s->functionParameters.push_back("INT");
							if(declared==0) s->functionParameters.push_back("INT");
							
							//fprintf(fp3, "added to function parameters INT\n");						
						}
					}
					else if(!tokens[i-1].compare("double"))
					{	
						s2->type = "DOUBLE";
						//s->functionParameters.push_back("DOUBLE");
						if(declared==0) s->functionParameters.push_back("DOUBLE");
							
						//fprintf(fp3, "added to function parameters DBL\n");
					}
					else if(!tokens[i-1].compare("FLOAT"))
					{
						s2->type = "FLOAT";
						//s->functionParameters.push_back("FLOAT");
						if(declared==0) s->functionParameters.push_back("FLOAT");
							
						//fprintf(fp3, "added to function parameters FLT\n");
					}
					//s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
				else
				{
					string err = "Multiple Declaration of ";
					err.append(var);
					printError(err,line_num);
					break;
				}
				//compare for type match.
				if(s2->type.compare(s->functionParameters[j])){
					string err = "Type Mismath";
					printError(err, line_num);
				}
				j++;
				//fprintf(fp2, "token: %s  type: %s\n", s2->getName().c_str(), s2->type.c_str());
			}
			
			
			
			/*
			
			if(tokens[i].compare("int") && tokens[i].compare("double") && tokens[i].compare("float") && tokens[i].compare(","))
			{	
				SymbolInfo *s2 = table->lookUp(tokens[i]);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					string b = tokens[i];
					b.append(" ");
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
					//fprintf(fp2,"lookup: %s , %s\n\n", s2->getName().c_str(), s2->getType().c_str());
				}
			}*/
		
		}
		} compound_statement {
			
			
			string checkForReturn = $7->getName().c_str();
			size_t returncheck = checkForReturn.find("return");
			//if(returncheck!=string::npos && !$1->getName().compare("VOID"))
			vector<string> compoundTokens;
			stringstream check1(checkForReturn);
			string intermediate;
			//string intermediate2;
			//fprintf(fp3, "%s \n",checkForReturn.c_str());
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '\n'))
				{
					compoundTokens.push_back(intermediate2);
					while(getline(check2, intermediate2, '\n')){
						compoundTokens.push_back(intermediate2);
					}
				}
				else {
					compoundTokens.push_back(intermediate);
				}
			}
			
			///checking return variable type
			for(int i=0; i<compoundTokens.size(); i++){
				//fprintf(fp3, "token: %s \n",compoundTokens[i].c_str());
				if(!compoundTokens[i].compare("return")){
					//fprintf(fp3, "found return %s :%s",compoundTokens[i].c_str(), compoundTokens[i+1].c_str());
					//if(i+2==compoundTokens.size() && $1->getType().compare("VOID")) //return void or nothing but return type different;
					if(i+2==compoundTokens.size() && $1->type.compare("VOID")) //return void or nothing but return type different;
					{
						string err = "warning: ‘return’ with no value, in function returning non-void";
						printError(err, line_num);
					}
					else{
					i++;
					string returnVar = compoundTokens[i].c_str();
					returnVar.erase(returnVar.end()-1);
					//fprintf(fp2, "returnVar: s'%s'sp\n", returnVar.c_str());
					returnVar.append(" ");
					//fprintf(fp2, "lookup: s'%s'sp\n", returnVar.c_str());
					SymbolInfo *variable = table->lookUp(returnVar);
					/*if(!variable->getName().compare("-1")) // variable not found which means not declared
					{
						string err = "Undeclared Variable: ";
						err.append(returnVar);
						printError(err, line_num);
					}
					else
					{*/
						//if(variable->type.compare($1->getType()))
						//fprintf(fp3, "type: %s (%s)\n", returnVar.c_str() ,$7->getType().c_str());
						if($7->type.compare($1->type))
						
						{
							string err = "Return Type Mismatch ";
							//err.append(variable->type.c_str());
							//err.append(" ");
							//err.append($1->getType());
							printError(err, line_num-1);
						}
					//}
 					
					}
				}
			}
			
			//scope part added..
			table->printAllScope(fp2);
			//if(flag==1) 
			table->exitScope(fp2);
			//..
			
			//printf("At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_num);
			fprintf(fp2, "At line no: %d func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n", line_num);
	
			//printf("%s %s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $7->getName().c_str());	
			
			
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append($7->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("func_definition");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			
			//fprintf(fp2,"from parameter list: %s\n\n",$4->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				
					 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			errFlag=0;
			
			
			}
		| type_specifier ID LPAREN RPAREN { 
			
			
			string b = $2->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			
			if(!s->getName().compare("-1"))
			{				
				 table->insert(b, $2->getType().c_str(), fp2);
				 s = table->lookUp(b);
				 s->type = $1->getType().c_str();
				 s->defined = true;
				 //s->functionParameters = " ";
			}
			else{
				s->defined = true;
				//if(s->type.compare($1->getType()))
				if(s->type.compare($1->type))
				{
					string er = "Return Type Mismatch With Declaration";
					printError(er, line_num);
				}
			}
		
			/*
			if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1")) 
			table->insert($2->getName().c_str(), $2->getType().c_str(), fp2); 
			*/
			flag=1;
			table->enterScope(fp2);
			
			} compound_statement  {
			
			
			
			
			string checkForReturn = $6->getName().c_str();
			size_t returncheck = checkForReturn.find("return");
			//if(returncheck!=string::npos && !$1->getName().compare("VOID"))
			vector<string> compoundTokens;
			stringstream check1(checkForReturn);
			string intermediate;
			//string intermediate2;
			//fprintf(fp3, "%s \n",checkForReturn.c_str());
		
			while(getline(check1, intermediate, ' ')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '\n'))
				{
					compoundTokens.push_back(intermediate2);
					while(getline(check2, intermediate2, '\n')){
						compoundTokens.push_back(intermediate2);
					}
				}
				else {
					compoundTokens.push_back(intermediate);
				}
			}
			
			///checking return variable type
			for(int i=0; i<compoundTokens.size(); i++){
				//fprintf(fp3, "token: %s \n",compoundTokens[i].c_str());
				if(!compoundTokens[i].compare("return")){
					//fprintf(fp3, "found return %s :%s",compoundTokens[i].c_str(), compoundTokens[i+1].c_str());
					//if(i+2==compoundTokens.size() && $1->getType().compare("VOID")) //return void or nothing but return type different;
					if(i+2==compoundTokens.size() && $1->type.compare("VOID")) //return void or nothing but return type different;
					{
						string err = "warning: ‘return’ with no value, in function returning non-void";
						printError(err, line_num);
					}
					else{
					i++;
					string returnVar = compoundTokens[i].c_str();
					returnVar.erase(returnVar.end()-1);
					//fprintf(fp2, "returnVar: s'%s'sp\n", returnVar.c_str());
					returnVar.append(" ");
					//fprintf(fp2, "lookup: s'%s'sp\n", returnVar.c_str());
					SymbolInfo *variable = table->lookUp(returnVar);
					/*if(!variable->getName().compare("-1")) // variable not found which means not declared
					{
						string err = "Undeclared Variable: ";
						err.append(returnVar);
						printError(err, line_num);
					}
					else
					{*/
						//if(variable->type.compare($1->getType()))
						//fprintf(fp3, "type: %s (%s)\n", returnVar.c_str() ,$7->getType().c_str());
						if($6->type.compare($1->type))
						
						{
							string err = "Return Type Mismatch ";
							//err.append(variable->type.c_str());
							//err.append(" ");
							//err.append($1->getType());
							printError(err, line_num-1);
						}
					//}
 					
					}
				}
			}
			
			
			//scope added..
			table->printAllScope(fp2);
			//if(flag==1) 
			table->exitScope(fp2);
			//...
			//printf("At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_num);
			fprintf(fp2, "At line no: %d func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n", line_num);
	
			//printf("%s %s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $6->getName().c_str());	
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($6->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("func_definition");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				
				 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			errFlag=0;
			
			}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID {
			//printf("At line no: %d parameter_list : parameter_list COMMA type_specifier ID \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : parameter_list COMMA type_specifier ID \n\n", line_num);
			
			//printf("%s%s%s %s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());	
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append(" ");
			allConcat.append($4->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("parameter_list");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			/*if(!(table->lookUp($4->getName().c_str()))->getName().compare("-1"))
			{				

				 table->insert($4->getName().c_str(), $4->getType().c_str(), fp2);
			}*/
			
			
			//new command
			/*string concat;
			concat.append($1->getName().c_str());
			concat.append(" ");
			concat.append($4->getName().c_str());
			$$->setName(concat);
			fprintf(fp2,"paralist: %s\n\n",$$->getName().c_str());
			$$->setType("parameter_list");
			*/
			}
		| parameter_list COMMA type_specifier {
			//printf("At line no: %d parameter_list : parameter_list COMMA type_specifier \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : parameter_list COMMA type_specifier \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());	
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("parameter_list");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			$$->setType($1->getType());
			$$->type = $1->type;
			
			}
 		| type_specifier ID {
			//printf("At line no: %d parameter_list : type_specifier ID \n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : type_specifier ID \n\n", line_num);
			
			//printf("%s %s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("parameter_list");
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			/*if(!(table->lookUp($2->getName().c_str()))->getName().compare("-1"))
			{				

				 table->insert($2->getName().c_str(), $2->getType().c_str(), fp2);
			}*/
			
			
			
			//new command
			/*$$->setName($2->getName().c_str());
			$$->setType("parameter_list");
			
			fprintf(fp2,"paraList: %s\n\n",$$->getName().c_str());
			*/
			$$->setType($1->getType());
			$$->type = $1->type;
			
			}
		| type_specifier {
			//printf("At line no: %d parameter_list : type_specifier\n\n", line_num);
			fprintf(fp2, "At line no: %d parameter_list : type_specifier\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("parameter_list");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
 		;

 		
compound_statement : LCURL { //fprintf(fp2,"found LCURL\n"); /*if(flag==0) {table->enterScope(fp2);}*/ 
			} 
			statements RCURL {
			//printf("At line no: %d compound_statement : LCURL statements RCURL \n\n", line_num);
			fprintf(fp2, "At line no: %d compound_statement : LCURL statements RCURL \n\n", line_num);
			
			//printf("%s\n%s%s\n\n", $1->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());	
			
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append("\n");
			//allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			//allConcat.append("\n");
			allConcat.append($4->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("compound_statement");
			
			$$->setType($3->getType());
			$$->type = $3->type;
			
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());			
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			//table->printAllScope(fp2); 
			//table->exitScope(fp2);
			flag=0;
			//table->printAllScope(fp2);
			//table->exitScope(fp2);
			
			}
 		    | LCURL { //fprintf(fp2,"found LCURL\n"); /*if(flag==0) {table->enterScope(fp2);}*/
 		    } RCURL {
			//printf("At line no: %d compound_statement : LCURL RCURL \n\n", line_num);
			fprintf(fp2, "At line no: %d compound_statement : LCURL RCURL \n\n", line_num);
			
			//printf("%s %s\n\n", $1->getName().c_str(), $3->getName().c_str());	
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append("\n");
			allConcat.append($3->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("compound_statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//{table->printAllScope(fp2); table->exitScope(fp2);}
			//table->printAllScope(fp2);
			//table->exitScope(fp2);
			flag=0;
			
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON {
			//printf("At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d var_declaration : type_specifier declaration_list SEMICOLON\n\n", line_num);
			
			//printf("%s %s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());	
			
			
			vector <string> tokens;
			stringstream check1($2->getName().c_str());
			string intermediate;
			string intermediate2;
		
			while(getline(check1, intermediate, ',')){
				stringstream check2(intermediate);
				string intermediate2;
				if(getline(check2, intermediate2, '[')){
					stringstream check3(intermediate2);
					string intermediate3;
					if(getline(check3, intermediate3, ']')){
						tokens.push_back(intermediate3);
					}
					else { tokens.push_back(intermediate2); }
				}
				else tokens.push_back(intermediate);
			}
		
			for(int i=0; i<tokens.size(); i++) {	
				string b = tokens[i];
				b.append(" ");
				///fprintf(fp2, "Tokens: %s\n", b.c_str());
				SymbolInfo *s2 = table->lookUp(b);
				if(!s2->getName().compare("-1"))
				{				
					//s2 = new SymbolInfo (tokens[i], "ID");
					//string b = s2->getName().c_str();
					
					table->insert(b, "ID",  fp2);
					s2 = table->lookUp(b);
					if(s2->type.compare("INT_ARRAY"))
						s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
				}
				else
				{
					s2 = table->lookUp(b);
					if(s2->type.compare("INT_ARRAY"))
						s2->type = $1->getType().c_str();
					//fprintf(fp2,"Inserted bfr cmpnd stmnt %s\n\n", s2->getName().c_str());
				}
		
			}
			
			///check every token type
			for(int i=0; i<tokens.size(); i++) {	
				string b = tokens[i];
				b.append(" ");
				
				SymbolInfo *s2 = table->lookUp(b);
				//fprintf(fp2, "T: %s (%s) \n", s2->getName().c_str(), s2->type.c_str());
		
			}
			
			
			
			
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("var_declaration");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			
			errFlag=0;
			
			}
 		 ;
 		 
type_specifier	: INT {
			//printf("At line no: %d type_specifier : INT\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : INT\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("type_specifier");
			$$->setType("INT");
			$$->type = "INT";
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
 		| FLOAT {
			//printf("At line no: %d type_specifier : FLOAT\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : FLOAT\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("FLOAT");
			$$->type = "FLOAT";
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
 		| VOID {
			//printf("At line no: %d type_specifier : VOID\n\n", line_num);
			fprintf(fp2, "At line no: %d type_specifier : VOID\n\n", line_num);

			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("VOID");
			$$->type = "VOID";
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
	
			}
 		;
 		
declaration_list : declaration_list COMMA ID {
			//printf("At line no: %d declaration_list : declaration_list COMMA ID \n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : declaration_list COMMA ID \n\n", line_num);
		
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			string allConcat ;
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("declaration_list");
			
			
			
			
			///fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			
			
			
			/*SymbolInfo *s = table->lookUp($3->getName().c_str());
			if(!s->getName().compare("-1") )
			{
				s = new SymbolInfo($3->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			/*else {
				error++;
				fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}*/
			
			
			string b = $3->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append($3->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
			//printf("At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD \n\n", line_num);
			
			//printf("%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append($6->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("declaration_list");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			/*SymbolInfo *s = table->lookUp($3->getName().c_str());
			if(!s->getName().compare("-1") )
			{
				s = new SymbolInfo($3->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			*/
			
			string b = $3->getName().c_str();
			b.append(" ");
			//SymbolInfo *s = table->lookUp(b);
			
			SymbolInfo *s = table->lookUpCur(b);
			
			
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($3->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				s->type = "INT_ARRAY";
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append($3->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $3->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			}
 		  | ID {
			//printf("At line no: %d declaration_list : ID\n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : ID\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("ID");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			string b = $1->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUp(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			else {
				//yyerror(
				string err = "Multiple Declaration of ";
				err.append($1->getName().c_str());
				printError(err, line_num);
				
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $1->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			
			}
 		  | ID { /*SymbolInfo *s = table->lookUp($1->getName().c_str());
			if(!s->getName().compare("-1") )
			{	
				string tmp = $1->getName().c_str();
				s = new SymbolInfo($1->getName().c_str(), "ID");
				string b = s->getName().c_str();
				b.append(" ");
				table->insert(b, "ID",  fp2);
			}
			*/
			
			string b = $1->getName().c_str();
			b.append(" ");
			SymbolInfo *s = table->lookUpCur(b);
			if(!s->getName().compare("-1") )
			{
				//s = new SymbolInfo($1->getName().c_str(), "ID");
				//string b = s->getName().c_str();
				//b.append(" ");
				table->insert(b, "ID",  fp2);
				s = table->lookUp(b);
				s->type = "INT_ARRAY";
			}
			else {
				//yyerror(
				
				string err = "Multiple Declaration of ";
				err.append($1->getName().c_str());
				printError(err, line_num);
				//fprintf(fp3, "Error at Line %d: Multiple Declaration of %s \n\n", line_num, $1->getName().c_str());
				//Error at Line 6: Multiple Declaration of c
			}
			
			} LTHIRD CONST_INT RTHIRD {
			//printf("At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", line_num);
			fprintf(fp2, "At line no: %d declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n", line_num);
		
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("declaration_list");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			}
 		  ;
 		  
statements : statement {
			//printf("At line no: %d statements : statement\n\n", line_num);
			fprintf(fp2, "At line no: %d statements : statement\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statements");
			
			$$->setType($1->getType());
			$$->type = $1->type;
			fprintf(fp2, "%s\n\n", $1->getName().c_str());
			
			}
	   | statements statement {
			//printf("At line no: %d statements : statements statement\n\n", line_num);
			fprintf(fp2, "At line no: %d statements : statements statement\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			
			$$->setName(allConcat);
			//$$->setType("statements");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	   ;
	   
statement : var_declaration {
			//printf("At line no: %d statement : var_declaration\n\n", line_num);
			fprintf(fp2, "At line no: %d statement : var_declaration\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | expression_statement {
			//printf("At line no: %d statement : expression_statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : expression_statement \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | compound_statement {
			//printf("At line no: %d statement : compound_statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : compound_statement \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
			//printf("At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str(), $7->getName().c_str());
			string allConcat ;
	
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append($6->getName().c_str());
			allConcat.append($7->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
			//printf("At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | IF LPAREN expression RPAREN statement ELSE statement {
			//printf("At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : IF LPAREN expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str(), $6->getName().c_str(), $7->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append($6->getName().c_str());
			allConcat.append($7->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | WHILE LPAREN expression RPAREN statement {
			//printf("At line no: %d statement : WHILE LPAREN expression RPAREN statement \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : WHILE LPAREN expression RPAREN statement \n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON {
			//printf("At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n", line_num);
			
			//printf("%s%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str(), $5->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
			allConcat.append($5->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			errFlag=0;
			
			}
	  | RETURN expression SEMICOLON {
			//printf("At line no: %d statement : RETURN expression SEMICOLON \n\n", line_num);
			fprintf(fp2, "At line no: %d statement : RETURN expression SEMICOLON \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append(" ");
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append("\n");
			$$->setName(allConcat);
			//$$->setType("statement");
			
			$$->setType($2->getType());
			$$->type = $2->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			
			//errFlag=0;
			
			}
	  ;
	  
expression_statement 	: SEMICOLON	{
			
			//printf("At line no: %d expression_statement : SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d expression_statement : SEMICOLON\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append("\n");
			
			$$->setName(allConcat);
			//$$->setType("expression_statement");
			
			errFlag=0;
			
			}
				
			| expression SEMICOLON {
			
			//printf("At line no: %d expression_statement : expression SEMICOLON\n\n", line_num);
			fprintf(fp2, "At line no: %d expression_statement : expression SEMICOLON\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append("\n");
			
			$$->setName(allConcat);
			//$$->setType("expression_statement");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			errFlag=0;
			
			}	
			;
	  
variable : ID {
			//printf("At line no: %d variable : ID \n\n", line_num);
			fprintf(fp2, "At line no: %d variable : ID \n\n", line_num);
			
			//table->printAllScope(fp2);
			
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("variable");
			$$->setType($1->getType());
			
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			$$->setName($1->getName().c_str());
			string id = $1->getName().c_str();
			id.append(" ");
			SymbolInfo *s = table->lookUp(id);
			if(!s->getName().compare("-1"))
			{				
				string err = "Undeclared Variable: ";
				err.append(id);
				printError(err, line_num);
				 //table->insert($1->getName().c_str(), $1->getType().c_str(), fp2);
			}
			else
			{
				$$->type = s->type;
			}
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s(%s)\n\n",$$->getName().c_str(), s->type.c_str());
			
			}			
	 | ID LTHIRD expression RTHIRD {
			//printf("At line no: %d variable : ID LTHIRD expression RTHIRD \n\n", line_num);
			fprintf(fp2, "At line no: %d variable : ID LTHIRD expression RTHIRD \n\n", line_num);
	
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			
			
			//if($3->getType().compare("INT"))
			if($3->type.compare("INT"))
			{
				string s = "Non-integer Array Index" ;
				printError(s, line_num);
			}
			
			
			
			
			
			string id = $1->getName().c_str();
			id.append(" ");
			SymbolInfo *s = table->lookUp(id);
			if(!s->getName().compare("-1"))
			{				
				string err = "Undeclared Variable: ";
				err.append(id);
				printError(err, line_num);
				 //table->insert($1->getName().c_str(), $1->getType().c_str(), fp2);
			}
			else if(s->type.compare("INT_ARRAY")){
				string err = "Not an array type variable ";
				err.append(s->getName().c_str());
				printError(err, line_num);
			}
			
			
			string allConcat ;
	
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
		
			$$->setName(allConcat);
			//$$->setType("variable");
			$$->setType(s->getType());
			$$->type = s->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s) \n\n",$$->getName().c_str(), s->type.c_str());
			
			}
	 ;
	 
 expression : logic_expression	 {
			//printf("At line no: %d expression : logic_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d expression : logic_expression \n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("expression");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
	   | variable ASSIGNOP logic_expression 	{
			//printf("At line no: %d expression : variable ASSIGNOP logic_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d expression : variable ASSIGNOP logic_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			//fprintf(fp2, "\n\n vartype: (%s) %s, exprs_type:(%s) %s\n\n", $1->getName().c_str(), varType.c_str(),  $3->getName().c_str(),logic_expressionType.c_str());
			
			size_t found = $1->getName().find("[");
			if(found==string::npos)
			{
				string b = $1->getName().c_str();
				b.append(" ");
				SymbolInfo *s = table->lookUp(b);
				
				string varType = s->type.c_str();
				//string logic_expressionType = $3->getType().c_str();
				string logic_expressionType = $3->type.c_str();
				
				
				
				//fprintf(fp2, "\n\n vartype: (%s) %s, exprs_type:(%s) %s\n\n", $1->getName().c_str(), varType.c_str(),  $3->getName().c_str(),logic_expressionType.c_str());
				if(!varType.compare("INT_ARRAY") && logic_expressionType.compare("INT_ARRAY"))
				{	
					string err = "Type Mismatch ";
					//err.append(varType);
					printError(err, line_num);
				}
				
				
				if(!logic_expressionType.compare("INT_ARRAY"))
				{
					logic_expressionType = "INT";
				}
				
				if(varType.compare(logic_expressionType))
				{
					string err = "Type Mismatch ";
					//err.append(varType);
					//err.append(" ");
					//err.append(logic_expressionType);
					printError(err, line_num);
				}
				
				/*
				if(!varType.compare("INT") && !logic_expressionType.compare("INT")){
			
				}
				else if(!varType.compare("FLOAT") && !logic_expressionType.compare("FLOAT")){	
				
				}
				else if(!varType.compare("INT_ARRAY") && found==string::npos)
				{	
					string err = "Type Mismatch ";
					//err.append(varType);
					printError(err, line_num);
				}
				else if(!varType.compare(logic_expressionType) && found!=string::npos )
				{ 
					//this command never runs
				}
				/*else if(!varType.compare("-1"))
				{ 
					
				}*/
				/*else
				{
					string err = "Type Mismatch ";
					err.append(varType);
					err.append(" ");
					err.append(logic_expressionType);
					printError(err, line_num);
				}*/
			}
			else
			{
				string varType = "INT_ARRAY";
				string logic_expressionType = $3->type.c_str();
				//if(varType.compare(logic_expressionType)!=0 )
				
				//fprintf(fp2, "%s\n",logic_expressionType.c_str());
				
				if(logic_expressionType.compare("INT") && logic_expressionType.compare("INT_ARRAY") )
				{
					string err = "Type Mismatch (added 22-june)";
					//err.append(varType);
					printError(err, line_num);
				}
				
			}
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
		
			$$->setName(allConcat);
			//$$->setType("expression");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			}
	   ;
			
logic_expression : rel_expression 	{
			//printf("At line no: %d logic_expression : rel_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d logic_expression : rel_expression \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("logic_expression");
			$$->setType($1->getType());
			$$->type = $1->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
		 | rel_expression LOGICOP rel_expression 	{
			//printf("At line no: %d logic_expression : rel_expression LOGICOP rel_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d logic_expression : rel_expression LOGICOP rel_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			//$$->setType("logic_expression");
			
			if($1->type.compare($3->type) && $1->type.compare("INT")){
				//error 
				string err = "Integer operand on logic operator ";
				printError(err, line_num);
				$$->setType("error");
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			
			//$$->setType("logic_expression");
			
			
			string concatType = $1->getType().c_str();
			concatType.append(" ");
			concatType.append($3->getType().c_str());
			
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
		 ;
			
rel_expression	: simple_expression  {
			//printf("At line no: %d rel_expression : simple_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d rel_expression : simple_expression \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("rel_expression");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
		| simple_expression RELOP simple_expression	{
			//printf("At line no: %d rel_expression : simple_expression RELOP simple_expression \n\n", line_num);
			fprintf(fp2, "At line no: %d rel_expression : simple_expression RELOP simple_expression \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			if($1->type.compare($3->type))
			{
				string err = "Type Mismatch: Both side of RELOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("rel_expression");
			
			
			
			string concatType = $1->getType().c_str();
			concatType.append(" ");
			concatType.append($3->getType().c_str());
			
			
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			}
		;
				
simple_expression : term  {
			//printf("At line no: %d simple_expression : term\n\n", line_num);
			fprintf(fp2, "At line no: %d simple_expression : term\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType($1->getType());
			$$->type = $1->type;
			//$$->setType("simple_expression");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}
		  | simple_expression ADDOP term  {
			//printf("At line no: %d simple_expression : simple_expression ADDOP term \n\n", line_num);
			fprintf(fp2, "At line no: %d simple_expression : simple_expression ADDOP term \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			///fprintf(fp2,"$1:%s $3:%s\n\n",$1->type.c_str(), $3->type.c_str());
			
			
			if(!$1->type.compare("FLOAT") && !$3->type.compare("INT"))
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}
			else if(!$1->type.compare("INT") && !$3->type.compare("FLOAT"))
			{
				$$->setType($3->getType());
				$$->type = $3->type;
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}
			
			
			
			/*
			
			if($1->type.compare($3->type)){
				string err = "Type Mismatch: Both side of ADDOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}*/
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("simple_expression");
			//fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			string concatType = $1->getType().c_str();
			concatType.append(" ");
			concatType.append($3->getType().c_str());
			
			
			
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			}	
		  ;
					
term :	unary_expression {
			//printf("At line no: %d term : unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d term : unary_expression\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("term");
			$$->setType($1->getType());
			$$->type = $1->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			}
     |  term MULOP unary_expression {
			//printf("At line no: %d term : term MULOP unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d term : term MULOP unary_expression\n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			
			
			///string a = $1->getType();
			///string b = $3->getType();
			
			string a = $1->type;
			string b = $3->type;			
			
			///fprintf(fp2, "types: %s %s\n", a.c_str(), b.c_str());
			
			if(!a.compare("CONST_INT"))
			{
				a = "INT";
			}
			else if(!a.compare("CONST_FLOAT"))
			{
				a = "FLOAT";
			}
			
			if(!b.compare("CONST_INT"))
			{
				b = "INT";
			}
			else if(!b.compare("CONST_FLOAT"))
			{
				b = "FLOAT";
			}
			
			/*if(!$2->getName().compare("%") && $3->getType().compare("CONST_INT")){
				string err = "Integer operand on modulus operator";
				printError(err, line_num);				
			}
			
			if($1->getType().compare($3->getType())){
				string err = "Type Mismatch: Both side of MULOP should be same type";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}*/
			
			
			if(!$2->getName().compare("%") && b.compare("INT")){
				string err = "Integer operand on modulus operator ";
				//err.append(a);
				//err.append(" ");
				//err.append(b);
				printError(err, line_num);				
			}
			/*if((!a.compare("FLOAT") && !b.compare("INT")) || (!b.compare("FLOAT") && a.compare("INT")))
			{
				
			}
			
			if(a.compare(b)){
				string err = "Type Mismatch: Both side of MULOP should be same type ";
				
				err.append(a);
				err.append(" ");
				err.append(b);
				printError(err, line_num);
			}
			else
			{*/
				//$$->setType($1->getType());
				//$$->type = $1->type;
			//}
			
			
			if(!a.compare("FLOAT") && !b.compare("INT"))
			{
				$$->setType($1->getType());
				$$->type = a;
			}
			else if(!a.compare("INT") && !b.compare("FLOAT"))
			{
				$$->setType($3->getType());
				$$->type = b;
			}
			else
			{
				$$->setType($1->getType());
				$$->type = a;
			}
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("term");
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			
			
			//string concatType = $1->getType().c_str();
			//concatType.append(" ");
			//concatType.append($3->getType().c_str());
			
			
			
			}
     ;

unary_expression : ADDOP unary_expression  {
			//printf("At line no: %d unary_expression : ADDOP unary_expression  \n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : ADDOP unary_expression  \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("unary_expression");
			$$->setType($2->getType());
			$$->type = $2->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
		 | NOT unary_expression  {
			//printf("At line no: %d unary_expression : NOT unary_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : NOT unary_expression\n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			$$->setName(allConcat);
			//$$->setType("unary_expression");
			$$->setType($2->getType());
			$$->type = $2->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			
			string temp=newTemp();
			$$->code="mov ax, " + $2->getName() + "\n";
			$$->code+="not ax\n";
			$$->code+="mov "+temp+", ax";
						
			cout << $$->code.c_str();
			
			}
		 | factor {
			//printf("At line no: %d unary_expression : factor \n\n", line_num);
			fprintf(fp2, "At line no: %d unary_expression : factor \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("unary_expression");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			// fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			}
		 ;
	
factor	: variable {
			//printf("At line no: %d factor : variable\n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("factor");
			$$->setType($1->getType());
			$$->type= $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->type.c_str());
			
			if($$->type=="INT_ARRAY"){
				string temp= newTemp();
				$$->code+="mov ax, " + $1->getName() + "[bx]\n";
				$$->code+= "mov " + temp + ", ax\n";
				$$->setName(temp);
			}
			else{
				
			}
			
			//cout << $$->code.c_str();
			
			
			}
	| ID LPAREN argument_list RPAREN {
			//printf("At line no: %d factor : ID LPAREN argument_list RPAREN\n\n", line_num);
			fprintf(fp2, "At line no: %d factor : ID LPAREN argument_list RPAREN\n\n", line_num);
			
			//printf("%s%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str(), $4->getName().c_str());
			
			
			string argList = $3->getName().c_str();
			string funcName = $1->getName().c_str();
			funcName.append(" ");
			SymbolInfo *funcNameSym = table->lookUp(funcName);
			
			
			if(!funcNameSym->getName().compare("-1"))
			{
				string err = "Undeclared Function ";
				err.append(funcName);
				printError(err, line_num);
			}
			else if(!funcNameSym->defined){
				string err = "Undfined Function ";
				err.append(funcName);
				printError(err, line_num);
			}
			else{
			
			
			vector<string> typeTokens;
			stringstream check2($3->getType().c_str());
			string intermediate2;
		
			while(getline(check2, intermediate2, ' ')){
				typeTokens.push_back(intermediate2);
			}
		
			
						
			
			///fprintf(fp2, "argList: %s\n",$3->getName().c_str());
			///fprintf(fp2, "funcPara: %s\n",funcNameSym->getName().c_str());
			vector<string> tokens;
			stringstream check1(argList.c_str());
			string intermediate;
		
			while(getline(check1, intermediate, ',')){
				tokens.push_back(intermediate);
			}
			
			if(tokens.size()!=funcNameSym->functionParameters.size())
			{
				string err = "Parameter number doesn't match!";
				printError(err, line_num);
			}
			else{
		
			for(int i=0, j=0; i<tokens.size(); i++, j++) {	
				string b = tokens[i];
				b.append(" ");
				///fprintf(fp2, "Looking:%s (%s %s) 'typeTokens': %s \n",b.c_str(), $3->type.c_str(), $3->getType().c_str(), typeTokens[i].c_str());
				SymbolInfo *s2 = table->lookUp(b);
				if(!s2->getName().compare("-1"))
				{				
					
					if(!typeTokens[i].compare("CONST_INT"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("INT"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							$3->setName("error");
							break;
						}
					}
					else if(!typeTokens[i].compare("CONST_FLOAT"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("FLOAT"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							$3->setName("error");
							break;
						}
					}
					else if(!typeTokens[i].compare("CONST_CHAR"))
					{
						string parameterType = funcNameSym->functionParameters[j];
						if(parameterType.compare("CHAR"))
						{
							string err = "Type Mismatch";
							printError(err, line_num);
							$3->setName("error");
							break;
						}
					}
					else
					{
						string err = "Undeclared Variable: ";
						err.append(b);
						printError(err, line_num);
						break;
					}
					
					
				}
				else
				{
					string argType = s2->type;
					string parameterType = funcNameSym->functionParameters[j];
					if(parameterType.compare(argType))
					{
						string err = "Type Mismatch";
						printError(err, line_num);
						$3->setName("error");
						break;
					}
				}
		
			}
			}
			}
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
			allConcat.append($4->getName().c_str());
		
			$$->setName(allConcat);
			$$->setType(funcNameSym->type);
			$$->type = funcNameSym->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			
			}
	| LPAREN expression RPAREN {
			//printf("At line no: %d factor : LPAREN expression RPAREN \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : LPAREN expression RPAREN \n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
		
			$$->setName(allConcat);
			
			$$->setType($2->getType());
			$$->type = $2->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	| CONST_INT  {
			//printf("At line no: %d factor : CONST_INT \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_INT \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("CONST_INT");
			$$->type = "INT";
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	| CONST_FLOAT {
			//printf("At line no: %d factor : CONST_FLOAT \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_FLOAT \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("CONST_FLOAT");
			$$->type = "FLOAT";
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	| CONST_CHAR {
			//printf("At line no: %d factor : CONST_CHAR \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : CONST_CHAR \n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			$$->setType("CONST_CHAR");
			$$->type = "CHAR";
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	| variable INCOP  {
			//printf("At line no: %d factor : variable INCOP \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable INCOP \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			
			
			//write type checking..
			if($1->type.compare("INT") && $1->type.compare("INT_ARRAY") )
			{
				string err = "Type Mismatch: INCOP applicable only with INT";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}

			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			//$$->setType("factor");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	| variable DECOP {
			//printf("At line no: %d factor : variable DECOP \n\n", line_num);
			fprintf(fp2, "At line no: %d factor : variable DECOP \n\n", line_num);
			
			//printf("%s%s\n\n", $1->getName().c_str(), $2->getName().c_str());
			
			
			//write type checking..
			
			if($1->type.compare("INT") && $1->type.compare("INT_ARRAY") )
			{
				string err = "Type Mismatch: INCOP applicable only with INT";
				printError(err, line_num);
			}
			else
			{
				$$->setType($1->getType());
				$$->type = $1->type;
			}
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			//$$->setType("factor");
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	;
	
argument_list : arguments {
			//printf("At line no: %d argument_list : arguments\n\n", line_num);
			fprintf(fp2, "At line no: %d argument_list : arguments\n\n", line_num);
			
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("argument_list");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str() ,$$->getType().c_str());
			
			}
			  |
			  {
			  	$$ = new SymbolInfo("", "");
			  	$$->setName("");
			  	
			  }
			  ;
	
arguments : arguments COMMA logic_expression {
			//printf("At line no: %d arguments : arguments COMMA logic_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d arguments : arguments COMMA logic_expression\n\n", line_num);
			
			//printf("%s%s%s\n\n", $1->getName().c_str(), $2->getName().c_str(), $3->getName().c_str());
			
			
			
			string allConcat ;
			
			allConcat.append($1->getName().c_str());
			allConcat.append($2->getName().c_str());
			allConcat.append($3->getName().c_str());
		
			$$->setName(allConcat);
			//$$->setType("arguments");
			
			
			string typeConcat;
			
			typeConcat.append($1->getType().c_str());
			typeConcat.append(" ");
			typeConcat.append($3->getType().c_str());
		
			$$->setType(typeConcat);
			
			//$$->setType($1->getType());
			$$->type = $1->type;
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			//fprintf(fp2,"%s (%s)\n\n",$$->getName().c_str(), $$->getType().c_str());
			
			}
	 | logic_expression {
			//printf("At line no: %d arguments : logic_expression\n\n", line_num);
			fprintf(fp2, "At line no: %d arguments : logic_expression\n\n", line_num);
	
			//printf("%s\n\n", $1->getName().c_str());
			//$$->setType("arguments");
			$$->setType($1->getType());
			$$->type = $1->type;
			
			fprintf(fp2,"%s\n\n",$$->getName().c_str());
			}
	      ;
 

%%

int main(int argc,char *argv[])
{
	table = new SymbolTable;	
	table->setCapacity(20);
	//sym = new SymbolTable;
	//sym->setCapacity(10);
	
	logout= fopen("1505010_logScanner.txt","w");
	tokenout= fopen("1505010_tokenScanner.txt","w");

	FILE *fp;
	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	fp2= fopen(argv[2],"w");
	fclose(fp2);
	fp3= fopen(argv[3],"w");
	fclose(fp3);
	
	fp2= fopen(argv[2],"a");
	fp3= fopen(argv[3],"a");
	

	yyin=fp;
	yyparse();
	

	fclose(fp2);
	fclose(fp3);
	
	return 0;
}

