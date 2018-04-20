#include <iostream>
#include <string>
#include <list>

#include<vector>

#include "facebook.h"
using namespace std ;

vector<list<int>> friend_list ;
int global_ID=0 ;
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
	for(int i=0;i<users.size();i++)
	{

		if (users[i].email == email ){
			
			friend_list[i].push_back(this->ID);  
			friend_list[this->ID].push_back(i);  

			
		}

	
	}

	cout <<"add friend done"<<endl;
	this->display();
}

void creat_account()
{
	string name ;
	string password ;
	string email;
	cout <<"please enter user name :";
	cin.ignore();
	getline(cin ,name);
	cout<<endl<<"please enter email : \t" ;
	cin >>email ;
	///////////////////
	//check
	//////////////////
	cout<<endl<<"please enter password : \t"; 
	cin>>password ;

	user m (global_ID , name, password , email);
	global_ID++;
	users.push_back(m);
	/////// call the function of display
	m.display();

}

void sign_in ()
{
	string email ;
	string password ;
	int i=0 ;
	bool flag = false ;
	cout<<"please enter your email : \t" ;
	cin>>email;
	///////email checking
	cout <<endl << "please enter password : \t" ;
	cin>>password ;
	for (i ; i <users.size() ; i++)
	{
		
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
		}
	if (flag ==true ){
		///// call the function 
	
			users[i].display();

	////////////

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

void user::display(){
	int no ;
	cout <<"if you what to show  your posts press 0"<<endl
		<<" if you want to show friends posts press 1"<<endl
		<<" if want to write posts press 2" <<endl
	<<" if want to sign out press 3" <<endl
	<<"if you want to add friend press 4"<<endl;

	cin>>no ;
	switch (no)
	{
	case 0:
		this->show_my_posts();
	case 1 :
		this->show_posts();
	case 2 :
		this->write_post();
	case 3 :
		this->sign_out();
	case 4 :
		string email ;
		cout<<"please the enter the friend email"<<endl;
		cin>>email ;
		this->add_friend(email) ;
	}
}
void user::show_my_posts(){
    
     for(int i=0;i<this->post.size();i++)cout<<"index :"<<i<<endl<<this->post[i]<<endl;
	 cout<<" press 0 if you want to like or press 1 if you want to go back "<<endl;
	int b;
	 cin>> b;
	 switch(b){
	 case 0 : cout<<"rbna m3aky"<<endl;
	 case 1: display();
	 
	 }
     }


void user::show_posts()
{
	////////////
	cout <<"ana gwa show posts " << endl;
	////////////
	vector <string> all_posts ;
	for (auto i=friend_list[this->ID].begin(); i != friend_list[this->ID].end(); ++i)
	{
	int ID_friend=*i ;

	all_posts.reserve(all_posts.size()+users[ID_friend].post.size());
	all_posts.insert(all_posts.end(),users[ID_friend].post.begin() ,users[ID_friend].post.end());

	}

	for(int i =0 ; i<all_posts.size() ; i++)
	{
		cout<<"index no."<<i <<":" <<endl <<all_posts[i] <<endl  ;
	
	}


	 cout<<" press 0 if you want to like or press 1 if you want to go back "<<endl;
	int b;
	 cin>> b;
	 switch(b){
	 case 0 : cout<<"rbna m3aky"<<endl;
	 case 1: display();

	 }
}

void user:: write_post(){

	string my_post ;
	cout<<"enter your post "<<endl ;
	cin.ignore();
	getline(cin,my_post);
	this->post.push_back(my_post) ;
	
	this->display();





}

void user::sign_out(){
	home_page();
}

int main ()
{

	home_page();

	system("pause");
	return 0;

}



