#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;

void create(){
    string name,month;
    short int pass,year,date;
    int balance;

    cout<<"KINDLY ENTER YOUR NAME: "; cin>>name;
    cout<<"\nKINDLY ENTER YOUR ONLY THE DATE OF BIRTH: "; cin>>date;
    cout<<"\nKINDLY ENTER YOUT YEAR OF BIRTH: "; cin>>year;
    cout<<"\nKINDLY ENTER YOUR MONTH OF BIRTH: "; cin>>month;
    if(2022-year<18){
        cout<<"UNDER AGED! CANT CREATE ACCOUNT"<<endl;
    }
    else{
        cout<<"ENTER YOUR PASSWORD: ";cin>>pass;
        cout<<"\nENTER YOUR INITIAL BALANCE: "; cin>>balance;
        
        fstream file;
        file.open(name.c_str(),ios_base::out);
        file<<balance<<endl;
        file<<name<<endl;
        file<<pass<<endl;
        file<<date<<month<<year<<endl;
        file.close();
        cout<<"\nACCOUNT CREATED SUCCESSFULLY"<<endl;
    }
}

void display(int balance)
{
	cout<<"The current balance in your account is : "<<balance<<endl;
}

void reset(){
	int balance,pass,p;
	string dob,d,name;
	system("cls");
	cout<<"Enter your name: "; cin>>name;
	cout<<"Please enter your Date of Birth in format ddmonyear: "; cin>>dob;
	ifstream file(name.c_str());
	file>>balance;
	file>>name;
	file>>pass;
	file>>d;
	cout<<d;
	if(dob==d){
		cout<<"\nEnter your new password: "; cin>>p;
		ofstream file(name.c_str());
		file<<balance<<endl;
		file<<name<<endl;
		file<<p<<endl;
		file<<dob<<endl;
		file.close();
		cout<<"\nPassword reset successfully"<<endl;
	}
	else{
		ofstream file(name.c_str());
		file<<balance<<endl;
		file<<name<<endl;
		file<<pass<<endl;
		file<<d<<endl;
		file.close();
		cout<<"Incorrect Date of Birth!"<<endl;
	}
}

int deposit(int balance,string name)
{
	int d;
	char show;
	cout<<"Enter the amount to be deposited : "<<endl;
	cin>>d;
	balance=balance+d;
	cout<<"Amount deposited \nPress 's' to display the current balance "<<endl;
	cin>>show;
	switch(show)
	{
		case 's':
			display(balance);
			break;
		default :
			break;
	}
    return balance;
}

int withdrawl(int balance,string name)
{  
	int w;
    int min_balance=500;
	char show;
	if(balance<=min_balance)
	{
		cout<<"Insufficient balance!"<<endl;
	}
	else
	{
		cout<<"Enter the amount to be withdrawn :"<<endl;
		cin>>w;
		if(balance-w<=min_balance){
			cout<<"Cant withdraw!"<<endl;
		}
		else
		{
			balance=balance-w;
            ofstream file(name.c_str());
            file<<balance;
            file.close();
			cout<<"Amount withdraw \nPress 's' to display current balance on the screen :"<<endl;
			cin>>show;
			switch(show)
			{
				case 's':
					display(balance);
					break;
				default :
					break;
			}
		}
	}
    return balance;
}

void login(){
    int balance,b;
    char choice;
    string name,n,dob;
    short int pass,p;

    cout<<"KINDLY ENTER YOUR USERNAME: "; cin>>name;
    cout<<"\nKINDLY ENTER YOUR PASSWORD: "; cin>>pass;
    ifstream file(name.c_str());
    file>>balance;
    file>>n;
    file>>p;
    file>>dob;
    if(pass != p || name != n){
    	char choice;
        cout<<"INCORRECT USERNAME OR PASSWORD!"<<endl;;
        file.close();
        cout<<"Press r to reset the Password: "; cin>>choice;
        if(choice=='r'){
        	reset();
		}
		else
		return;
    }
    else{
        file.close();
        system("cls");
        fstream file;
        file.open(name.c_str());
        cout<<"Press 'a' to display the balance\nPress 'b' to deposit money\nPress 'c' to withdraw money"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 'a':
				display(balance);
                file<<balance<<endl;
                file<<n<<endl;
                file<<p<<endl;
                file<<dob<<endl;
                file.close();
				break;
			case 'b':
				b = deposit(balance,name);
                file<<b<<endl;
                file<<n<<endl;
                file<<p<<endl;
                file<<dob<<endl;
                file.close();
				break;
			case 'c':
				b = withdrawl(balance,name);
                file<<b<<endl;
                file<<n<<endl;
                file<<p<<endl;
                file<<dob<<endl;
                file.close();
				break;
			default :
				cout<<"Enter the correct choice!"<<endl;
				break;
		}
    }
}

int main(){
    int choice;
    cout<<"1: REGISTER"<<endl;
    cout<<"2: LOGIN"<<endl;
    cout<<"3: PIN CHANGE"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        create();
        system("cls");
        break;
    case 2:
        login();
        break;
    case 3:
    	reset();
    	break;
    
    default:
        cout<<"Please choose from the following"<<endl;
        main();
        break;
    }
    return 0;
}
