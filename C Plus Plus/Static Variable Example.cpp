#include<iostream>
#include<string.h>
using namespace std;
class Student{
private:
	int roll;
	static string dress_color;
public:
	Student(){
		roll=0;
	}
	Student(int a){
		roll=a;
	}
	~Student(){
	}
	int get_roll(){
		return roll;
	}
	string get_dress(){
		return dress_color;
	}
	void set_roll(int r){
		roll=r;
	}
	void set_dress(string c){
		dress_color=c;
	}
	void display(){
		cout<<"Roll No.: "<<roll<<" Dress Color: "<<dress_color;
	}
};

string Student::dress_color="Black";

int main(){
	Student s1(1);
	Student s2(2);
	s1.set_dress("Red");
	s2.set_dress("Blue");
	cout<<s1.get_dress()<<"\n";
	cout<<s2.get_dress()<<"\n";

	s1.set_roll(10);
	s2.set_roll(20);
	cout<<s2.get_roll()<<"\n";
	return 0;
}
