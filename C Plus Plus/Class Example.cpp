#include<iostream>
using namespace std;
class Time {
private:
	int hour;
	int min;
	int sec;
public:
	void display() {
		cout<<hour<<":"<<min<<":"<<sec<<"\n";
			}
};

int main() {
	Time t;
	t.display();
	return 0;
}
