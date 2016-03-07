#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector <int> Row;
typedef vector <Row> Matrix;

int r,c;

void oblique(Matrix m){
	/*for(int i=0; i<r;i++){
		for(int j=0; j<c; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0; i<r+c-1; i++){
		
		int start=
		for(int j=0; j<c; j++){

		}
	}

}

int main(){
	
	fstream fin("input0.txt");
	fin>>r>>c;
	Matrix matr (r, Row(c));
	cout<<r<<" "<<c<<endl;
	
	while(!fin.eof()){
		for(int i=0; i<r;i++){
			for(int j=0; j<c; j++){
				fin>>matr[i][j];
			}
		}
	}
	
	oblique(matr);

	return 0;
}