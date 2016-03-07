/*
-----------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/45k70o/20160213_challenge_253_hard_working_like_a/
-----------------------------------------------------------------------------------------------------
^c	clear the entire screen; the cursor row and column do not change
^h	move the cursor to row 0, column 0; the image on the screen is not changed
^b	move the cursor to the beginning of the current line; the cursor row does not change
^d	move the cursor down one row if possible; the cursor column does not change
^u	move the cursor up one row, if possible; the cursor column does not change
^l	move the cursor left one column, if possible; the cursor row does not change
^r	move the cursor right one column, if possible; the cursor row does not change
^e	erase characters to the right of, and including, the cursor column on the cursor's row; the cursor row and column do not change
^i	enter insert mode
^o	enter overwrite mode
^^	write a circumflex (^) at the current cursor location, exactly as if it was not a special character; this is subject to the actions of the current mode (insert or overwrite)
^DD	move the cursor to the row and column specified; each D represents a decimal digit; the first D represents the new row number, and the second D represents the new column number
*/
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

#define COLS 10
#define ROWS 10
#define MAX 10

string terminal[MAX][MAX];
int row=0;
int col=0;
bool insert=false;

void parse_str(string);
void parse_tok(string);
void print_teminal();
void write(char);


int main(int argc, char const *argv[])
{
	fstream fin("input.txt");
	string line;
	while(!fin.eof())
	{
		getline(fin,line);
		parse_str(line);
	}
	print_teminal();
	return 0;
}

void parse_str(string line)
{
	for(int i=0;i<line.size();)
	{
		char ch=line[i];
		if(ch=='^' && (line[i+1]<58 && line[i+1]>47))
		{
			parse_tok(line.substr(i+1,2));			
			i+=3;
		}
		else if(ch=='^' && (line[i+1]>96 && line[i]<123))
		{
			parse_tok(line.substr(i+1,1));			
			i+=2;
		}
		else 
		{
			parse_tok(line.substr(i,1));			
			i++;
		}			
	}
}

void parse_tok(string token)
{	
	if(token.size()==2)
	{
		row=token[0]-'0';
		col=token[1]-'0';
	}
	else{
		char ch = token[0];
		switch(ch){
			case 'c':
				for(int i=0;i<ROWS; i++)
				{
					for(int j=0; j<COLS;j++)
					{
						terminal[i][j]=" ";
					}
				}
			break;
			
			case 'h':
				row=0;
				col=0;
			break;
			
			case 'b':
				col=0;
			break;
			
			case 'd':
				if(row<ROWS-1)
					row++;						
			break;
			
			case 'u':
				if(row>0){ 
					row--;
				}
				else
					row=0;						
			break;
			
			case 'l':	
				if(col>0) 
					col--;
			break;
			
			case 'r':	
				if(col<COLS-1) 
					col++;
			break;
			
			case 'e':
				for(int i=col; i<COLS; i++){
					terminal[row][i]=' ';
				} 
			break;
			
			case 'i': 
				insert=true;
			break;
			
			case 'o': 					
				insert=false;
			break;
			
			case '^':
				write('^');
			break;
			
			default:
				write(ch);
			break;
		}
	}
}

void write(char c)
{	
	if(insert)
	{
		for(int i=COLS-2; i>=col; i--){
			terminal[row][i+1]=terminal[row][i];
		}
	}
	terminal[row][col]=c;
	if(col<COLS-1)
		col++;
}

void print_teminal()
{
	for(int i=0;i<ROWS; i++)
	{
		for(int j=0; j<COLS;j++)
		{
			cout<<terminal[i][j];
		}
		cout<<endl;
	}
}