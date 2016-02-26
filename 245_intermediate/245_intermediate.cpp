/*
---------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/3x3hqa/20151216_challenge_245_intermediate_ggggggg_gggg/
---------------------------------------------------------------------------------------
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



int main()
{
	fstream in("input.txt");
	string line;
	getline(in, line);
	stringstream ss(line);
	//map key->value
	map<string, char> mapa;
	std::map<string, char>::iterator it;

	
	//read keys
	while(!ss.eof()){
		string k;
		string v;
		ss>>v>>k;
		mapa[v]=k[0];
		cout<<k<<" "<<v <<" "<<endl;
	}

	//decoding
	//getline(in, line2);	//get second line
	
	int i=0;
	int cnt=0;
	string alien_w;
	string human_w;
	char ch;
	while(in>>ch){
		if(ch =='g' || ch =='G'){
			
			alien_w+=ch;
			if(mapa.find(alien_w)==mapa.end()){
				
				human_w+= mapa[alien_w];
				alien_w=" ";
			}
		}
		else{
			human_w+=ch;
		}		
	}
	cout<<human_w<<endl;
	cout<<alien_w<<endl;
	return 0;
}
//string arser implementation:
/*void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = "^")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}*/
