// simple example of scope resolution
#include<iostream>
#include<string.h>
using namespace std;
class WorldCup{
private:
	int no_of_teams;
	int year;
	string winner;
public:
	WorldCup();
	WorldCup(int, int, string);
	string get_winner();
	int get_year();
	int get_teams();
	void set_winner(string);
	void set_year(int);
	void set_teams(int);
	void display();
};
//Scope Resolution

WorldCup::WorldCup() {
	no_of_teams=0;
	year=0;
	winner="";
}
WorldCup::WorldCup(int a, int b, string c) {
	no_of_teams=a;
	year=b;
	winner=c;
}
string WorldCup::get_winner(){
	return winner;
}
int WorldCup::get_year(){
	return year;
}
int WorldCup::get_teams(){
	return no_of_teams;
}
void  WorldCup::set_winner(string win){
	winner=win;
}
void WorldCup::set_year(int yr){
	year=yr;
}
void WorldCup::set_teams(int t){
	no_of_teams=t;
}
void WorldCup::display(){
	cout<<"\nWinner: "<<winner<<"\n";
	cout<<"Year: "<<year<<"\n";
	cout<<"No. of teams: "<<no_of_teams<<"\n";
}
	int main() {
	WorldCup wc2006, wc2010, wc2014;
	wc2006.set_winner("Italy");
	wc2006.set_teams(32);
	wc2006.set_year(2006);
	wc2006.display();

	wc2010.set_winner("Spain");
	wc2010.set_teams(32);
	wc2010.set_year(2010);
	wc2010.display();

	wc2014.set_winner("Germany");
	wc2014.set_teams(32);
	wc2014.set_year(2014);
	wc2014.display();

	int diffyear= wc2014.get_year()-wc2010.get_year();
	cout<<"Difference in year is "<<diffyear<<"\n";
	return 0;
} 
