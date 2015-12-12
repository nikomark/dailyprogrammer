/*
---------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/3twuwf/20151123_challenge_242_easy_funny_plant/
---------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
	
	int people= atoi(argv[1]);
	int plants= atoi(argv[2]);
	int week=1;
	int fruits=0;
	
	while (fruits<people){
		week++;
		fruits+=plants;
		plants+=fruits;
	}

	cout<<week<<endl;
	
	return 0;
}