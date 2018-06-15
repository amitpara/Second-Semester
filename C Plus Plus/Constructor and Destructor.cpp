//simple example of constructor and destructor
#include<iostream>
#include<string.h>
using namespace std;
class Student {
private:
	//attribute
	string name;
	int roll;
public:
	Student(){ 					//default constructor
		name="Anonymous";
		roll=0;
	}
	Student(int r,string n) {
		roll=r;
		name=n;
	}
	string get_name() {			//name getter
		return name;
	}
	int get_roll(){ 			//roll no. getter
		return roll;
	}
	void set_name(string n){ 	//name setter
		name=n;
	}
	void set_roll(int r){ 		//roll no. setter
		roll=r;
	}
	void display(){ 			//display function
		cout<<"Name:"<<name<<"\n";
		cout<<"Roll no.:"<<roll<<"\n";
	}
	~Student(){					//destructor
		cout<<name<<" destroyed"<<"\n";
	}
};

int main()
{
	int a=20;
	string b="abc";
	if (true) {
		Student st2(a,b);
	}
	Student st1;
	st1.set_name("Hari");
	st1.set_roll(10);
	string stname = st1.get_name();
	int stroll= st1.get_roll();
	st1.display(); 
	return 0;
}
