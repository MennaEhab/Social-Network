#include <iostream>
#include <string>
#include <list>
using namespace std;

#include<vector>

class user {

private:

    
    string name ;
    string password ;
    string email ;
	int ID ;
    vector <string> post ;

public :
	user (int ID  ,string name , string password , string email) ;
	
	void add_friend (string email);
	
	friend void sign_in ();
};

struct post 
{

	string post ;
	int no_likes ;
    vector <string >name_likes ;
    string owner ;
};
void creat_account ();

void home_page();
void sign_in ();




