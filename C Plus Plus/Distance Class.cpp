//Example of class that uses setter, getter and display and then prints the total distance
#include<iostream>
using namespace std;
class Distance {
private:
	//attribute
	int meter;
	int cm;
public:
	//display
	void display() {
		cout<<meter<<"m "<<cm<<"cm"<<"\n";
	}
	//setter
	//set meter
	void set_meter(int m) {
		meter=m;
	}
	//set cm
	void set_cm(int centi) {
		cm=centi;
	}
	//getter
	//get meter
	int get_meter() {
		return meter;
	}
	//get cm
	int get_cm(){
		return cm;
	}
};

int main()
{
	Distance d1,d2,total;
	d1.set_meter(25);
	d1.set_cm(15);
	d1.display();

	d2.set_meter(19);
	d2.set_cm(67);
	d2.display();

	int totalm=d1.get_meter()+d2.get_meter();
	int totalcm=d1.get_cm()+d2.get_cm();
	total.set_meter(totalm);
	total.set_cm(totalcm);

	cout<<"Total Distance:";

	total.display();

	return 0;
}
