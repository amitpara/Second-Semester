//Simple program to demonstrate copy constructor
#include<iostream>
using namespace std;
	class Plant{
	private:
		int height;
		string color;
	public:
		// Default COnstructor
		Plant(){
			height=0;
			color="Green";
		}
		// Parameterized Constructor
		Plant(int height, string color){
			this->height=height;
			this->color=color;
		}
		Plant(Plant&a){
			height=a.height;
			color=a.color;
		}
		void set_height(int height){
			this->height=height;
		}
		void set_color(string color){
			this->color=color;
		}
		int get_height(){
			return height;
		}
		string get_color(){
			return color;
		}
		void display(){
			cout<<"\n Height: "<<height<<"\n Color: "<<color;
		}
};
	int main()
	{
		Plant p1;
		Plant p2(20,"Blue");
		p2.set_height(100);
		p2.set_color("Yellow");
		Plant p3(p2);
		Plant p4=p3;
		p1=p4;
		p1.display();
		p2.display();
		p3.display();
		p4.display();
		return 0;
	}
