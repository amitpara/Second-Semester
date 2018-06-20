//C++ Program to convert Binary Numbers to Decimal
#include<iostream>
#include<cmath>
using namespace std;

// Function for finding the length of number
int length(int bi){
		int len=0, num=bi;
		while (num!=0) {
			len++;
			num=num/10;
		}
		return len;
	}
//function for converting binary number to decimal
int convertdeci(int binary){ 			
		int i, sum=0, j;
		int len=length(binary);
		int num=binary;
		for(i=0;i<len;i++){
			j=num%10;
			sum+=j*(pow(2,i));
			num=num/10;
		}
		return sum;
	}

class Convert {
private:
	//attributes
	int binary;
	int decimal;
public:
	//Default Constructor
	Convert(){ 					
		binary=0;
		decimal=0;
	}
	//Getters
	//Binary Getter
	int get_bin() {			
		return binary;
	}
	//Decimal Getter
	int get_deci(){ 			
		return decimal;
	}
	//Setters
	//Binary Setter
	void set_bin(int b){ 	
		binary=b;
	}
	//Decimal Setter
	void set_deci(int d){ 	
		decimal=d;
	}
	//Display Function
	void display(){ 			
		cout<<"Binary: "<<binary<<"\n";
		cout<<"Decimal: "<<decimal<<"\n";
	}
	//Default Destructor
	~Convert(){
	}
};

int main()
{
	Convert deci;
	int bin;
	re:
	//Taking Binary Input
	cout<<"Enter the binary number:";
	cin>>bin;
	//Checking the possible errors in the entered binary number
	if (bin<0) {
			cout<<"Error! Enter positive numbers!!\n";
			goto re;
		}
	int j, num=bin;
	for(int i=0;i<length(bin);i++){
			j=num%10;
			if (j>1){
				cout<<"Error! Enter Binary Number Only!!\n";
			goto re;
			}
		}
	deci.set_bin(bin);						//setting th value of binary
	deci.set_deci(convertdeci(bin));		//calling the convert function and setting the converted value of decimal
	deci.display();							//calling display function
	return 0;
}
