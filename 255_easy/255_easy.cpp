/*
-----------------------------------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/46zm8m/20160222_challenge_255_easy_playing_with_light/
-----------------------------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int start_s=clock();
	int n;
	vector <int> edges;
	int x,y;

	fstream fin("lots_of_switches.txt");
	fin>>n;

	while(!fin.eof()){

		fin>>x>>y;
		edges.push_back(min(x,y));
		edges.push_back(max(x,y)+1);
	}

	sort(edges.begin(), edges.end());

	int sum=0;	
	for(int i=0; i<edges.size();i+=2){
		sum+=edges[i+1]-edges[i];
	}
	
	cout<<sum<<endl;
	fin.close();
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	return 0;
}