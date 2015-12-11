/*
------------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/3uuhdk/20151130_challenge_243_easy_abundant_and/

A Deficient Number is greater than the sum of its proper divisors; that is, s(N)<n.
An Abundant Number is less than the sum of its proper divisors; that is, s(N)>n.
A Perfect Number equals the sum of its proper divisors; that is, s(N)=n.
------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){

	int num;
	vector <int> v;
	
	while(cin>>num && num>0)
		v.push_back(num);
	
	for(int i=0; i<v.size(); i++){
		
		num=v[i];
		int sigma=num;
	
		for(int i=1; i<= num/2+1; i++){
			if(num%i==0)
				sigma+=i;		
		}

		if(sigma==2*num)
			cout<<num<<" perfect"<<endl;//neighter
		else if(sigma>2*num)
			cout<<num<< " abundant by "<<sigma-2*num<<endl;
		else if(sigma<2*num)
			cout <<num<<" deficient"<<endl;
	}

	return 0;
}

