/*
--------------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/3nkanm/20151005_challenge_235_easy_ruthaaron_pairs/
--------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 100

bool is_prime( int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int factorize_and_sum(int n)
{
	int sum=0;
	for(int i=2; i<=n;++i){
		if(n%i==0){
			if(is_prime(i)){
				sum+=i;
			}
		}
	}
	return sum;
}

int main(){
	
	int N;
	int fst;
	cout<<"Number of pairs: ";
	cin>>N;

	vector< pair<int,int> > par;
	par.resize(MAX);

	cout<<"Give me first number of each "<<N<<" pairs:\n";
	for(int i=0;i<N; i++){
		cin>>fst;
		par[i]=make_pair(fst,fst+1);
	}
	cout<<"Input pairs are:\n";
	for(int i=0;i<N; i++){
		cout<<par[i].first<<" "<<par[i].second<<endl;
	}

	
	for(int i=0; i<N;i++){
		
		if(factorize_and_sum(par[i].first)==factorize_and_sum(par[i].second))
			cout<<"("<<par[i].first<<","<<par[i].second<<") VALID\n";
		else
			cout<<"("<<par[i].first<<","<<par[i].second<<") NOT VALID\n";

		/*cout<<factorize_sum(par[i].first)<<endl;
		cout<<factorize_sum(par[i].second)<<endl;*/
	}


} 