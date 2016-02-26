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

#define COLUM 10
#define ROW 10
#define MAX 9

bool isDigit(char c){
	return ('0'<=c && '9'<=c);
}

string terminal [MAX][MAX] ;
int row=0;
int col=0;
bool insert=false;
bool overwrite=false;
void parse_str(string);

int main(){
	
	fstream fin("input.txt");
	string line;

	while(!fin.eof()){
		getline(fin,line);
		parse_str(line);
	}

	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			cout<<terminal[i][j];
		}
		cout<<endl;
	}
	fin.close();
	return 0;
}
void parse_str(string line){

	vector <string> tokens;																																																																																																																					
	
	for(int i=0; i<line.size(); i++){

		char c= line[i];
		if(line[i]=='^'){
			switch(line[i+1]){
				case 'c': 
					for(int j=0;j<MAX;j++){
						for(int k=0; k<MAX;k++){
							terminal[j][k]=" ";
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
					row++;
					if(row>=10)
						row=9;
						
					break;
				case 'u': 
					row--;
					if(row<0)
						row=0;
						
					break;
				case 'l':	//move col left 
					if(col>0) col--;
					break;
				case 'r':	//move col right 
					if(col<10) col++;
					break;
				case 'e': 

					break;
				case 'i': 
					insert=true;
					break;
				case 'o': 					
					insert=false;
					break;
				case '^':
					if(insert){
						for(int j=COLUM-2;j>=col;j--){
							terminal[row][j+1]=terminal[row][j];
						}
					}
					terminal[row][col]=line[i];
					//terminal[row][col]='^';
					
					break;
				default: 		
					row= line[i+1]-'0';
					col= line[i+2]-'0';
					i++;
					break;
			}
			i++;
		}
		else{
			if(insert){
				for(int j=MAX; j>col; j--){
					terminal[row][j]=terminal[row][j-1];
				}
			}
			terminal[row][col]=line[i];
			col=min(col+1,MAX);
		}
	}
}


