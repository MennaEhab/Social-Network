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

		if (users[i].email == email )
		{
			
			friend_list[i].push_back(this->ID);  
			friend_list[this->ID].push_back(i); 
			cout<<"now you are friend with"<< users[i].name<<endl ;
		}
	}
	
	this->display();
}

void creat_account()
{
	string name ;
	string password ;
	string email;
	cout <<"please enter user name : ";
	cin.ignore();
	getline(cin ,name);
	cout<<endl<<"please enter email : " ;




	while(1)
	{ 
		cin >> email;
		bool flag = true;
		for (int c = 0; c < users.size(); c++)
		{
			 if (email == users[c].email)
			 {
				 cout << "email is existing...please enter another email" << endl;
				 flag = false;
				 break;
			 }
		}
		if (flag == true)break;
	}
	 

	cout<<endl<<"please enter password : "; 
	cin>>password ;

	user m (global_ID , name, password , email);
	global_ID++;
	users.push_back(m);
	
	system("CLS");
	cout <<"welcome "<<m.name<<endl<<endl;

	m.display();

}

void sign_in ()
{
	string email ;
	string password ;
	int i=0 ;
	bool flag = false ;
	cout<<"please enter your email :  " ;



	///////email checking

	while (1)
	{
		cin >> email;
		bool flag =false;
		for (int c = 0; c < users.size(); c++)
		{
			if (email == users[c].email)
			{
				  flag = true;
				break;
			}
		}
		if (flag == true)break;
		cout << "please enter another email...if you want to sign up please enter 1" << endl<<
			"if you want to repeat entering email plese enter 0"<<endl;
		int no;
		cin >> no;
		switch (no) { 
		case(1):  
			home_page(); 
		case(0):
			cout<<"please enter your email : " ;
			break; }
		
	}
	


	cout <<endl << "please enter password : " ;
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
			cout <<endl << "please enter password : " ;
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
cout<< "        Welcome to Our social media network"<<endl <<endl 
	<< " if you want to creat new account please enter  ( 0 ) "<<endl 
	<< " if you want to sign in please enter ( 1 ) " <<endl;

cin>>x ;
if (x == 0)
{
	creat_account();
}
else if (x==1)
{
sign_in ();
}

}

void user::display()
{
	int no ;
	string email ;
	label :

	cout<<"if want to write posts please press ( 0 )" <<endl<<endl 
		<<"if you what to show  your posts press ( 1 )"<<endl<<endl
		<<"if you want to show your friend's posts press ( 2 )"<<endl
		<<"if you want to add friend press ( 3 )"<<endl
		<<"if you want to show your friends list please press ( 4 )"<<endl
		<<"if want to sign out press ( 5 )" <<endl
		;


	cin>>no ;
	switch (no)
	{
	case 1:
		this->show_my_posts();
		break;
	case 2 :
		this->show_posts();
		break;
	case 0 :
		this->write_post();
		break;
	case 5 :
		this->sign_out();
		break;
	case 4 :
		this->show_my_friends_list();
		break;
	case 3 :
		cout<<"please enter the friend email"<<endl;
		cin>>email ;
		this->add_friend(email) ;
		break;
	default :
		cout<<"please enter the correct no." << endl ;
		goto label ;
		
					
	}
}

void user::show_my_posts(){
    
     for(int i=0;i<this->my_posts.size();i++)
		 cout<<"index :"<<i<<endl<<users[this->ID].my_posts[i].txt <<endl <<"likes : " 
			<< users[this->ID].my_posts[i].no_likes << endl;

	 label :
	 cout<<"if you want to like please enter 0  "<<endl 
		 <<"if you want to go back please enter 2 "<<endl
		 <<"if you want to write a a comment please enter 1 "<<endl
		 <<"if you want to show comment please enter 3 "<<endl
		 <<"if you want to show likers please enter  "<<endl;
	 int y ;
	int b;
	 cin>> b;
	 switch(b){
	 case 0 :
		 cout <<"please enter the index of the post you want to like "<<endl;
		 
		 cin>>y;
		 this ->like_post(this->my_posts[y]) ;
		 break ;
	 case 1  :
		 // int y ;
		 cout<<"please enter index of the post : ";
		 cin>>y;
		 this->comment_post(this->my_posts[y]);
		 break ;
	 case 3 :
		 cout<<"please enter index of the post : ";
		 cin>>y;
		 this->show_comments(this->my_posts[y]);
		 break;
	 case 2: 
		 display();
		 break ;
	 default :
		 cout<<"enter the correct no. " <<endl ;
		 goto label ;
     }

	 goto label ;
}

void user::like_post(post x)
{

	
	int owner ;
	string liker_name ;
	owner=x.owner_ID;
	
	for (int i =0 ; i<users[owner].my_posts.size() ; i++)
	{

		if(users[owner].my_posts[i].txt==x.txt)
		{
			users[owner].my_posts[i].no_likes++;
			users[owner].my_posts[i].name_likes.push_back(this->name);
		}
	}


}

void user::comment_post(post x)
{
	comment newcomment;
	int owner=x.owner_ID;
	
	for (int i = 0; i<users[owner].my_posts.size(); i++)
	{
		

		if (users[owner].my_posts[i].txt == x.txt)
		{
			cout << "type your comment..."<<endl ;

			cin.ignore();
	        getline(cin,newcomment.text);
			
			newcomment.owner =owner ;
			users[owner].my_posts[i].comments.push_back(newcomment);
			
			break;
		}
	}


	
	
	
}

void user::show_comments(post x)
{
	for(int i =0 ; i<x.comments.size(); i++)

		cout << x.comments[i].owner <<":"<<x.comments[i].text<<endl ;

}

void user::show_posts()
{
	vector <post> all_posts ;
	for (auto i=friend_list[this->ID].begin(); i != friend_list[this->ID].end(); ++i)
	{
	int ID_friend=*i ;

	all_posts.reserve(all_posts.size()+users[ID_friend].my_posts.size());
	all_posts.insert(all_posts.end(),users[ID_friend].my_posts.begin() ,users[ID_friend].my_posts.end());
	}

	for(int i =0 ; i<all_posts.size() ; i++)
	{
		cout<<"index no."<<i <<":" <<endl <<all_posts[i].txt <<endl  <<"likes : "<<all_posts[i].no_likes<<endl ;
	}
	label :
	cout<<"if you want to like please enter 0 "<<endl
		<<"if you want to write a comment please enter 1 "<<endl
		<<"if you want to show comment please enter 2 "<<endl
		<<"if you want to go back please enter 3 "<<endl;
	int y;
	int b;
	 cin>> b;
	 switch(b){
	 case 0 :
		 cout<<"please enter index of the post : ";
		 cin>>y;
		 this->like_post(all_posts[y]) ;
		 break ;
	 case 1  :
		 cout<<"please enter index of the post : ";
		 cin>>y;
		 this->comment_post(all_posts[y]);
		 break;
	 case 2 :
		 cout<<"please enter index of the post : ";
		 cin>>y;
		 this->show_comments(all_posts[y]);
		 break;
	 case 3: 
		 display();
		 break ;
	 default : 
		 cout << "please enter the correct no. " << endl ;
		 goto label ;
	 }

	 goto label ;
	
}

void user::show_likers(post x)
{
	for(int i =0 ; i<x.comments.size(); i++)

		cout << x.name_likes[i]<<endl;
}

void user:: write_post(){

	string my_new_post ;
	cout<<"enter your post "<<endl ;
	cin.ignore();
	getline(cin,my_new_post);
	post new_post ;
	new_post.txt= my_new_post;
	new_post.no_likes=0;
	new_post.owner_ID=this->ID ;

	users[this->ID].my_posts.push_back(new_post) ;

	this->my_posts.push_back(new_post) ;

	


	this->display();
}

void user::sign_out(){

	system("CLS");
	home_page();
}

void user::show_my_friends_list()
{
	for(auto i=friend_list[this->ID].begin(); i != friend_list[this->ID].end(); ++i)
	{
		 int friend_ID =*i ;
		 cout<< users[friend_ID].name<<endl ;	
	
	}
	this->display();


}

int main ()
{

	home_page();

	system("pause");
	return 0;

}
