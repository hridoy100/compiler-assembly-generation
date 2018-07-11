%{
#define YYSTYPE SymbolInfo*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

#include "1505010.h"
#include "y.tab.h"
//#define YYSTYPE SymbolInfo*
int MAX_STR_CONST = 1000;
char *string_buf_ptr;
char *tokStr;
int line_num = 1;
int error = 0;
int prevline = 0;
FILE *logout;
FILE *tokenout;
//SymbolTable *sym; // = new SymbolTable;
//#include "SymbolTable.h"
//#include "SymbolInfo.h"

using namespace std;

extern YYSTYPE yylval;
extern SymbolTable *table;
extern FILE *fp2;
void yyerror(char *);

%}

delim [ \t]
ws {delim}+
digit [0-9]
digits {digit}+
number ({digit}*\.?{digits}|{digits}\.)(E[+-]?{digits})?
letter [A-Za-z]
character  \'{letter}\'|\'(\\)[ntaf0brv"\\]\'
identifier [a-zA-Z_][a-zA-Z0-9_]*
%x str
%x cmnt
%x comment
%x test
%x multichar
%%
[\n] {line_num++;}

"//" {
	string_buf_ptr = (char*) malloc(MAX_STR_CONST * sizeof(char));
	char *ch = (char*) malloc(sizeof(char)*2); 
	//ch = '/';
	strcpy(string_buf_ptr, "//");
	prevline = line_num;
	BEGIN(cmnt);
}
<cmnt>[^\n]	{
	char *yptr = yytext;
	if(strlen(yptr)>MAX_STR_CONST)
	{	
		MAX_STR_CONST += strlen(yptr);
		MAX_STR_CONST*=2;
		string_buf_ptr = (char*) realloc(string_buf_ptr, MAX_STR_CONST);
	}
	strcat(string_buf_ptr, yptr);
}
<cmnt>\\\n  {
	line_num++;
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "\\\n";
	strcat(string_buf_ptr, "\\\n");
	}
<cmnt>\n {
	//error++; 
	//printf("Single Comment\n");
	line_num++;
	//fprintf(tokenout,"<COMMENT,%s>\n",string_buf_ptr);
	fprintf(logout,"Line No. %d: Token <COMMENT> Lexeme %s found\n\n",prevline,string_buf_ptr);
	free(string_buf_ptr);
	BEGIN(INITIAL);
	}


"/*"         {
	string_buf_ptr = (char*) malloc(MAX_STR_CONST * sizeof(char));
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "/*";
	strcpy(string_buf_ptr, "/*");
	prevline = line_num;
	//printf("comment begin\n");
	BEGIN(comment);
	
	}

<comment>[^*\n]*        {
	/* eat anything that's not a '*' */
	char *yptr = yytext;
	if(strlen(yptr)>MAX_STR_CONST)
	{	
		MAX_STR_CONST += strlen(yptr);
		MAX_STR_CONST*=2;
		string_buf_ptr = (char*) realloc(string_buf_ptr, MAX_STR_CONST);
	}
	strcat(string_buf_ptr, yptr);
	}
<comment>"*"+[^*/\n]*   {
		/* eat up '*'s not followed by '/'s */
	char *yptr = yytext;
	if(strlen(yptr)>MAX_STR_CONST)
	{	
		MAX_STR_CONST += strlen(yptr);
		MAX_STR_CONST*=2;
		string_buf_ptr = (char*) realloc(string_buf_ptr, MAX_STR_CONST);
	}
	strcat(string_buf_ptr, yptr);
	}
<comment>\n     {
		line_num++;
		char *ch = (char*) malloc(sizeof(char)); 
		//ch = "\n"; 
		strcat(string_buf_ptr, "\n");
		}
<comment>"*"+"/"        {
		//printf("comment End\n"); 
		char *yptr = yytext;
		strcat(string_buf_ptr, yptr);
		//fprintf(tokenout,"<COMMENT,%s>\n",string_buf_ptr);
		fprintf(logout,"Line No. %d: Token <COMMENT> Lexeme %s found\n\n",prevline,string_buf_ptr);
		free(string_buf_ptr);
		BEGIN(INITIAL);
	}
<comment><<EOF>>	{
		fprintf(logout,"Error at line %d: Unfinished comment %s\n\n",line_num,string_buf_ptr);
		error++;
		free(string_buf_ptr);
		//printf("comment begin\n");
		BEGIN(INITIAL);

	}
"if" 	{
	//printf("<IF>");
	fprintf(tokenout,"<IF>  ");
	fprintf(logout,"Line No. %d: Token <IF> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"IF");
	yylval = (YYSTYPE)s;
	return IF;
	}
"for" 	{
	//printf("<FOR>");
	fprintf(tokenout,"<FOR>  ");
	fprintf(logout,"Line No. %d: Token <FOR> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"FOR");
	yylval = (YYSTYPE)s;
	return FOR;
	}
"do" 	{
	//printf("<DO>");
	fprintf(tokenout,"<DO>  ");
	fprintf(logout,"Line No. %d: Token <DO> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"DO");
	yylval = (YYSTYPE)s;
	return DO;
	}
"int" 	{
	//printf("<INT>");
	fprintf(tokenout,"<INT>  ");
	fprintf(logout,"Line No. %d: Token <INT> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"INT");
	yylval = (YYSTYPE)s;
	//cout << "\n\nyylval: " << yylval->getName() <<endl <<endl;
	return INT;
	}
"float" 	{
	//printf("<FLOAT>");
	fprintf(tokenout,"<FLOAT>  ");
	fprintf(logout,"Line No. %d: Token <FLOAT> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"FLOAT");
	yylval = (YYSTYPE)s;
	return FLOAT;
	}
"void" 	{
	//printf("<VOID>");
	fprintf(tokenout,"<VOID>  ");
	fprintf(logout,"Line No. %d: Token <VOID> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"VOID");
	yylval = (YYSTYPE)s;
	return VOID;
	}
"switch" {
	//printf("<SWITCH>");
	fprintf(tokenout,"<SWITCH>  ");
	fprintf(logout,"Line No. %d: Token <SWITCH> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"SWITCH");
	yylval = (YYSTYPE)s;
	return SWITCH;
	}
"default" {
	//printf("<DEFAULT>");
	fprintf(tokenout,"<DEFAULT>  ");
	fprintf(logout,"Line No. %d: Token <DEFAULT> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"DEFAULT");
	yylval = (YYSTYPE)s;
	return DEFAULT;
	}
"else"	{
	//printf("<ELSE>");
	fprintf(tokenout,"<ELSE>  ");
	fprintf(logout,"Line No. %d: Token <ELSE> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ELSE");
	yylval = (YYSTYPE)s;
	return ELSE;
	
	}
"while" {
	//printf("<WHILE>");
	fprintf(tokenout,"<WHILE>  ");
	fprintf(logout,"Line No. %d: Token <WHILE> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"WHILE");
	yylval = (YYSTYPE)s;
	return WHILE;
	}
"break" {
	//printf("<BREAK>");
	fprintf(tokenout,"<BREAK>  ");
	fprintf(logout,"Line No. %d: Token <BREAK> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"BREAK");
	yylval = (YYSTYPE)s;
	return BREAK;
	}
"char" 	{
	//printf("<CHAR>");
	fprintf(tokenout,"<CHAR>  ");
	fprintf(logout,"Line No. %d: Token <CHAR> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CHAR");
	yylval = (YYSTYPE)s;
	return CHAR;
	}
"double" {
	//printf("<DOUBLE>");
	fprintf(tokenout,"<DOUBLE>  ");
	fprintf(logout,"Line No. %d: Token <DOUBLE> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"DOUBLE");
	yylval = (YYSTYPE)s;
	return DOUBLE;
	}
"return" {
	//printf("<RETURN>");
	fprintf(tokenout,"<RETURN>  ");
	fprintf(logout,"Line No. %d: Token <RETURN> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RETURN");
	yylval = (YYSTYPE)s;
	return RETURN;
	}
"case" 	{
	//printf("<CASE>");
	fprintf(tokenout,"<CASE>  ");
	fprintf(logout,"Line No. %d: Token <CASE> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CASE");
	yylval = (YYSTYPE)s;
	return CASE;
	}
"continue" {
	//printf("<CONTINUE>");
	fprintf(tokenout,"<CONTINUE>  ");
	fprintf(logout,"Line No. %d: Token <CONTINUE> Lexeme %s found\n\n",line_num,yytext);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"CONTINUE");
	yylval = (YYSTYPE)s;
	return CONTINUE;
	}
{ws} {}
{digits} {
	//printf("<%s CONST_INT>\n", yytext);
	fprintf(tokenout,"<CONST_INT,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <CONST_INT> Lexeme %s found\n\n",line_num,yytext);
	
	/*
	
	sym->insert(yytext, "CONST_INT");
	sym->printCurScope(logout);
	
	*/
	SymbolInfo *s= new SymbolInfo(yytext, (char *)"CONST_INT");
	yylval = (YYSTYPE)s;
	return CONST_INT;
	}
{number} {
	//printf("<%s CONST_FLOAT>\n", yytext);
	fprintf(tokenout,"<CONST_FLOAT,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <CONST_FLOAT> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_FLOAT");
	sym->printCurScope(logout);
	
	*/
	SymbolInfo *s= new SymbolInfo(yytext, (char *)"CONST_FLOAT");
	yylval = (YYSTYPE)s;
	return CONST_FLOAT;
	}
{character} {
	switch(yytext[2])
	{
	
	case 'n' : //printf("<CONST_CHAR %c>\n", 10);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",10);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 't' : //printf("<CONST_CHAR %c>\n", 9);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",9);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case '\\' : //printf("\n<CONST_CHAR %c>\n", 92);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",92);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case '"' : //printf("<CONST_CHAR %c>\n", 34);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",34);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 'a' : //printf("<CONST_CHAR %c>\n", 7);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",7);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 'f' : //printf("<CONST_CHAR %c>\n", 12);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",12);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 'r' : //printf("<CONST_CHAR %c>\n", 13);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",13);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 'b' : //printf("<CONST_CHAR %c>\n", 8);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",8);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case 'v' : //printf("<CONST_CHAR %c>\n", 11);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",11);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;
	
	case '0' : //printf("<CONST_CHAR %c>\n", 0);	
	fprintf(tokenout,"<CONST_CHAR,%c>  ",0);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);
	
	*/
	break;

	}

	if(yytext[1]!='\\')
	{
	//printf("<CONST_CHAR, %c>\n", yytext[1]);
	fprintf(tokenout,"<CONST_CHAR,%c>  ",yytext[1]);
	fprintf(logout,"Line No. %d: Token <CONST_CHAR> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	sym->insert(yytext, "CONST_CHAR");
	sym->printCurScope(logout);	
	
	*/
	SymbolInfo *s= new SymbolInfo((char*) yytext[1], (char *)"CONST_CHAR");
	yylval = (YYSTYPE)s;
	return CONST_CHAR;
	}
	SymbolInfo *s= new SymbolInfo(yytext, (char *)"CONST_CHAR");
	yylval = (YYSTYPE)s;
	return CONST_CHAR;	
}
"*"|"/"|"%" {
	//printf("<MULOP %s>\n",yytext);
	fprintf(tokenout,"<MULOP,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <MULOP> Lexeme %s found\n\n",line_num,yytext);
	//sym->insert(yytext, "MULOP");
	//sym->printCurScope(logout);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"MULOP");
	yylval = (YYSTYPE)s;
	return MULOP;
	
	}
"++" 	{
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"INCOP");
	yylval = (YYSTYPE)s;
	return INCOP;
	}
"--" 	{
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"DECOP");
	yylval = (YYSTYPE)s;	
	return DECOP;
	}
"+"|"-" {
		//printf("<ADDOP, %s>\n", yytext);
		fprintf(tokenout,"<ADDOP,%s>  ",yytext);
		fprintf(logout,"Line No. %d: Token <ADDOP> Lexeme %s found\n\n",line_num,yytext);
		//sym->insert(yytext, "ADDOP");
		//sym->printCurScope(logout);
		SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ADDOP");
		yylval = (YYSTYPE)s;
		return ADDOP;
			
	}
"<"|"<="|">"|">="|"=="|"!=" {
	//printf("<RELOP, %s>\n",yytext);
	fprintf(tokenout,"<RELOP,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <RELOP> Lexeme %s found\n\n",line_num,yytext);
	//sym->insert(yytext, "RELOP");
	//sym->printCurScope(logout);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RELOP");
	yylval = (YYSTYPE)s;
	return RELOP;
	
}
"=" 	{ 
	//printf("<ASSIGNOP, %s>\n", yytext); 
	fprintf(tokenout,"<ASSIGNOP,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <ASSIGNOP> Lexeme %s found\n\n",line_num,yytext);
	//sym->insert(yytext, "ASSIGNOP");
	//sym->printCurScope(logout);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ASSIGNOP");
	yylval = (YYSTYPE)s;
	return ASSIGNOP;
	
	}
"&&"|"||" {
	//printf("<LOGICOP, %s>\n", yytext);
	fprintf(tokenout,"<LOGICOP,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <LOGICOP> Lexeme %s found\n\n",line_num,yytext);
	//sym->insert(yytext, "LOGICOP");
	//sym->printCurScope(logout);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LOGICOP");
	yylval = (YYSTYPE)s;
	return LOGICOP;
	
	}
"&"|"|"|"^"|"<<"|">>" { 
	//printf("<BITOP, %s>\n", yytext); 
	fprintf(tokenout,"<BITOP,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <BITOP> Lexeme %s found\n\n",line_num,yytext);
	//sym->insert(yytext, "BITOP");
	//sym->printCurScope(logout);
	SymbolInfo *s= new  SymbolInfo(yytext, (char *)"BITOP");
	yylval = (YYSTYPE)s;
	return BITOP;
	}
"!"|"("|")"|"{"|"}"|"["|"]"|","|";" {
	SymbolInfo *s= new  SymbolInfo();
	switch(yytext[0])
	{
	//SymbolInfo *s= new  SymbolInfo();
	case '!' : //printf("<NOT, %s>\n", yytext); 
	fprintf(tokenout,"<NOT,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <NOT> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"NOT");
	s->setName(yytext);
	s->setType((char *)"NOT");
	yylval = (YYSTYPE)s;
	return NOT;
	break;
	
	case '(' : //printf("<LPAREN, %s>\n", yytext); 
	fprintf(tokenout,"<LPAREN,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <LPAREN> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LAPREN");
	s->setName(yytext);
	s->setType((char *)"LPAREN");
	yylval = (YYSTYPE)s;
	return LPAREN;
	break;
	
	case ')' : //printf("<RPAREN, %s>\n", yytext); 
	fprintf(tokenout,"<RPAREN,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <RPAREN> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RPAREN");
	s->setName(yytext);
	s->setType((char *)"RPAREN");
	yylval = (YYSTYPE)s;
	return RPAREN;
	break;
	
	case '{' : //printf("<LCURL, %s>\n", yytext); 
	fprintf(tokenout,"<LCURL,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <LCURL> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LCURL");
	s->setName(yytext);
	s->setType((char *)"LCURL");
	yylval = (YYSTYPE)s;
	//table->enterScope(fp2);
	//sym->enterScope();
	return LCURL;
	break;
	
	case '}' : //printf("<RCURL, %s>\n", yytext); 
	fprintf(tokenout,"<RCURL,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <RCURL> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RCURL");
	s->setName(yytext);
	s->setType((char *)"RCURL");
	yylval = (YYSTYPE)s;
	//table->printAllScope(fp2);
	//table->exitScope(fp2);
	//sym->exitScope();
	return RCURL;
	break;
	
	case '[' : //printf("<LTHIRD, %s>\n", yytext); 
	fprintf(tokenout,"<LTHIRD,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <LTHIRD> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"LTHIRD");
	s->setName(yytext);
	s->setType((char *)"LTHIRD");
	yylval = (YYSTYPE)s;
	return LTHIRD;
	break;
	
	case ']' : //printf("<RTHIRD, %s>\n", yytext); 
	fprintf(tokenout,"<RTHIRD,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <RTHIRD> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"RTHIRD");
	s->setName(yytext);
	s->setType((char *)"RTHIRD");
	yylval = (YYSTYPE)s;
	return RTHIRD;
	break;
	
	case ',' : //printf("<COMMA, %s>\n", yytext); 
	fprintf(tokenout,"<COMMA,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <COMMA> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"COMMA");
	s->setName(yytext);
	s->setType((char *)"COMMA");
	yylval = (YYSTYPE)s;
	yylval = (YYSTYPE)s;
	return COMMA;
	break;
	
	case ';' : //printf("<SEMICOLON, %s>\n", yytext); 
	fprintf(tokenout,"<SEMICOLON,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <SEMICOLON> Lexeme %s found\n\n",line_num,yytext);
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"SEMICOLON");
	s->setName(yytext);
	s->setType((char *)"SEMICOLON");
	yylval = (YYSTYPE)s;
	return SEMICOLON;
	break;
	
	}
}

{identifier} {
	//printf("<%s, INDENTIFIER>\n",yytext);
	fprintf(tokenout,"<ID,%s>  ",yytext);
	fprintf(logout,"Line No. %d: Token <ID> Lexeme %s found\n\n",line_num,yytext);
	/*
	
	if(sym->insert(yytext, "ID"))
		sym->printCurScope(logout);
	//sym->printCurScope(logout);
	
	*/
	//SymbolInfo *s= new  SymbolInfo(yytext, (char *)"ID");
	SymbolInfo *s= table->lookUp(yytext);
	
	if(!s->getName().compare("-1"))
	{	
		//cout << "inside if\n\n";				
		s= new SymbolInfo(yytext, (char *)"ID");
	}
	yylval = (YYSTYPE)s;
	return ID;
	
}

\" {
	string_buf_ptr = (char*) malloc(MAX_STR_CONST * sizeof(char));
	tokStr = (char*) malloc(MAX_STR_CONST * sizeof(char));
	strcpy(string_buf_ptr, "\"");
	strcpy(tokStr, "\0");
	prevline = line_num;
	BEGIN(str);
}
<str>\" {
	/*saw closing quote - all done */

	//printf("<STRING, %s>\n", string_buf_ptr);
	//fprintf(tokenout,"<STRING,%s>  ",string_buf_ptr);
	strcat(string_buf_ptr, "\"");
	fprintf(logout,"Line No. %d: Token <STRING> Lexeme %s found\n\n",prevline,string_buf_ptr);
	fprintf(tokenout,"<STRING, \"%s\">  ",tokStr);
	
	if(string_buf_ptr) free(string_buf_ptr);//='\0';
	if(tokStr) free(tokStr);
	BEGIN(INITIAL);
}
<str>\n        {
	fprintf(logout,"Error at line %d: Unfinished string %s\n\n",line_num,string_buf_ptr);
	error++;
	line_num++;
	if(string_buf_ptr) free(string_buf_ptr);
	if(tokStr) free(tokStr);
	BEGIN(INITIAL);
	//printf("\n\n---error %s error---\n\n", yytext);
        /* error - unterminated string constant */
        /* generate error message */
        }


<str>\\[0-9]+ {
        /* generate error - bad escape sequence; something
         * like '\48' or '\0777777'
         */
        }

<str>\\n  {
	char *ch =(char*) malloc(sizeof(char)); 
	//ch = "\n"; 
	strcat(string_buf_ptr, "\\n");
	strcat(tokStr, "\n");
	line_num++;
}
<str>\\t  {
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "\t"; 
	strcat(string_buf_ptr, "\\t");
	strcat(tokStr, "\t");
}
<str>\\r  {
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "\r"; 
	strcat(string_buf_ptr, "\\r");
	strcat(tokStr, "\r");
}
<str>\\b  {
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "\b"; 
	strcat(string_buf_ptr, "\\b");
	strcat(tokStr, "\b");
}
<str>\\f  {
	char *ch = (char*) malloc(sizeof(char)); 
	//ch = "\f"; 
	strcat(string_buf_ptr, "\\f");
	strcat(tokStr, "\f");
	}

<str>\\(.|\n) {
	char *ch = (char*) malloc(sizeof(char)); 
	//ch[0] = yytext[1]; 
	//printf("slash %s newline\n", yytext);
	strcat(string_buf_ptr, yytext);
	if(yytext[2]=='\n' || yytext[1]=='\n') line_num++;
	if(yytext[1]=='\\') {
		strcat(tokStr, "\\");
	}
}

<str>[^\\\n\"]+        {
        char *yptr = yytext;
	if(strlen(yptr)+strlen(string_buf_ptr)>MAX_STR_CONST)
	{	
		MAX_STR_CONST += strlen(yptr);
		MAX_STR_CONST*=2;
		string_buf_ptr = (char*) realloc(string_buf_ptr, MAX_STR_CONST);
		tokStr = (char*) realloc(tokStr, MAX_STR_CONST);
	}
	strcat(string_buf_ptr, yptr);
	strcat(tokStr, yptr);
}
({digit}*\.?{digits}|{digits}\.)({digits})?({digit}*\.?{digits}|{digits}\.)({digits})? {
	//printf("Too many Decimal point error\n");
	//fprintf(tokenout,"<MULOP,%s>\n",yytext);
	fprintf(logout,"Error at line %d: Too many Decimal point %s\n\n",line_num,yytext);
	error++;
	//printf("\n\n---error---\n\n");
	}
{digits}E{digits}?\.{digits} {
	//printf("Ill formed number\n");
	fprintf(logout,"Error at line %d: Ill formed number %s\n\n",line_num,yytext);
	error++;
	//printf("\n\n---error---\n\n");
	}
{digits}{identifier} {
	//printf("Invalid Suffix on numeric constant or Invalid prefix on identifier\n");
	fprintf(logout,"Error at line %d: Invalid Suffix on numeric constant or Invalid prefix on identifier %s\n\n",line_num,yytext);
	error++;
	//printf("\n\n---error---\n\n");
	}
\'\\[^ntbfv]\' {

	fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_num,yytext);
	error++;
}

\'(\\)?{letter}+{ws}*(\\[nfbv]({letter}+)?|{letter}+)\' 	{
	//printf("Multi character constant error\n");
	fprintf(logout,"Error at line %d: Multi character constant error %s\n\n",line_num,yytext);
	error++;
	//printf("\n\n---error---\n\n");
	}
	
"."  	{
		//printf("Unrecognized Character\n"); 
		fprintf(logout,"Error at line %d: Unrecognized Character %s\n\n",line_num,yytext);
		error++;
		//printf("error..\n");
	}

\'{letter}*(\n)?|(\'(\\)?\') {
	//printf("Unfinished Character\n"); 
	fprintf(logout,"Error at line %d: Unfinished Character %s\n\n",line_num,yytext);
	error++;
	//printf("\n\n---error---\n\n");
	}
<<EOF>> {
	//printf("Total Line Number: %d and word number: %d\n",line_count,word_count); 
	/*
	
	sym->printAllScope(logout);
	
	*/
	fprintf(logout,"Total Lines: %d\n",line_num);
	fprintf(logout,"Total Errors: %d\n",error);
	//printf("error %d\n",error);	
	return 0;
	}
	
<test>\n { strcat(string_buf_ptr, yytext);BEGIN(str);}
<test>[^\n] BEGIN(str);

%%

int yywrap(void)
{
	return 1;
}


/*
int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	sym = new SymbolTable;
	sym->setCapacity(10);
	
	logout= fopen("1505010_log.txt","w");
	tokenout= fopen("1505010_token.txt","w");

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
*/
