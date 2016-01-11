/*
---------------------------------------------------------------------------------------------------
https://www.reddit.com/r/dailyprogrammer/comments/3wshp7/20151214_challenge_245_easy_date_dilemma/
---------------------------------------------------------------------------------------------------

*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

/*vector <string> split(string str, char delim){
	vector <string> tmp;
	stringstream ss(str);//turn the string into stream
	string tok;

	while(getline(ss,tok,'/')){
		tmp.push_back(tok);
	}
	return tmp;
}*/

int main(){

	ifstream in("input.txt");
	
	vector <string> sepdate;

	while(!in.eof()){
		char indate[12];
		string isodate;
		string month;
		string date;
		string year;
		in>>date;
		char *token = strtok(indate," -/");//get the first token
		month= token;
		while(token != NULL){//walk through the other tokens
			//sepdate.push_back(token);
			//cout<<token<<endl;
			if (month>12){
				int tmp
			}			
			token=strtok(NULL, " -/");
		}
	}
	for(int i=0;i<sepdate.size(); i++){
			cout<<sepdate[i]<<endl;
	}
}
//
public abstract class GeometricObject{
	private String color = "white";
	privateboolean filled;
	private java.util.Date dateCreated;
	protected GeometricObject(){
		dataCreated= new java.util.Date();
	};
	protected GeometricObject(String color, boolean filled){
		dateCreated = new java.util.Date();
		this.color=color;
		this.filled=filled;
	}
	public String getColor(){
		return color;
	}
	public boolean setColor(){
		this.color=color;
	}
	public boolean isFilled(){
		return filled;
	}
	public void getFilled(boolean filled){
		this.filled = filled;
	}
	pubilic java.util Date getDateCreated(){
		return dateCreated;
	}
	public String toString(){
		return "created on "+dateCreated+" \ncolor: "+color+" and filled "+filled);
	}
	public abstract double getArea();
	public abstract double getPerimeter();

}