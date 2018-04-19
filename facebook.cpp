#include <iostream>
#include <string>
#include <list>

#include<vector>

#include "facebook.h"
using namespace std ;

vector<list<int>> friend_list ;
int ID=0 ;
vector<user> users ;


user::user(int ID ,string name , string password , string email) {

	this -> name = name ;
	this -> password = password ;
	this -> email = email ;
	this -> ID = ID ;
	list <int> new_list ;
	friend_list.push_back(new_list);

	

}


void user::add_friend(string email)
{
	for(int i=0;i<users.size;i++)
	{

		if (users[i].email == email ){
			
			friend_list[i].push_back(this->ID);  
			friend_list[this->ID].push_back(i);  

			
		}

	
	}
}

void creat_account()
{
	string name ;
	string password ;
	string email;
	cout <<"please enter user name : \t";
	cin >>name;
	cout<<endl<<"please enter email : \t" ;
	cin >>email ;
	///////////////////
	//check
	//////////////////
	cout<<endl<<"please enter password : \t"; 
	cin>>password ;

	user m (ID , name, password , email);
	ID++;
	users.push_back(m);
	/////// call the function of display 
}

void sign_in ()
{
	string email ;
	string password ;

	
	cout<<"please enter your email : \t" ;
	cin>>email;
	///////email checking
	cout <<endl << "please enter password : \t" ;
	cin>>password ;
	for (int i ; i <users.size ; i++)
	{
		bool flag = false ;
		if(users[i].email == email )
		{
			while (1)
			{
			if (users[i].password== password)
			{
			
				flag = true ;

//// break for while 
				break ;
			}
			else 
			{
			cout <<endl << "please enter password : \t" ;
			cin>>password ;
			}
			}

			//// break the for loop
		 if (flag == true)
			 break;
		}

		if (flag ==true ){
		///// call the function 
		
		}

	}


}

void home_page()
{
	int x ;
cout<< "welcome to hamada  if you want to creat new account please enter 1 "<<endl << "or to sign in press 0" <<endl;
cin>>x ;
if (x == 1)
{
	creat_account();
}
else if (x==0)
{
sign_in ();
}

}




