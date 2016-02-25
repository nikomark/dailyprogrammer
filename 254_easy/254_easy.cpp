/*
----------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/45w6ad/20160216_challenge_254_easy_atbash_cipher/
----------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){

	string input="";
	while(getline(cin,input)){
		for(int i=0; i<input.length(); i++)
		{
			if(input[i]>='A' && input[i]<='Z'){	
				cout<<char('A'+'Z'-input[i]);
			}
			if(input[i]>='a' && input[i]<='z'){
				cout<<char('a'+'z'-input[i]);
			}
			else{
				cout<<input[i];
			}
		}
		cout<<endl;
	}
	
	return 0;
}