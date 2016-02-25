
/*
--------------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/43ouxy/20160201_challenge_252_easy_sailors_and_monkeys/
--------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int n;
	int res;
	cout<<"Number of saylors? ";
	cin>>n;

	if(n%2!=0){
		res= pow(n,n)-(n-1);
	}
	else{
		res= (n-1+n)*pow(n,n)-(n-1);	
	}
	cout<<res<<endl;

	return 0;
}