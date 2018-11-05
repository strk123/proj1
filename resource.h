#include <iostream>
#include <string>
using namespace std;

class resource {
private:
	string name; //resource name
public:
	void set_name(string sname); // set resource name
	string get_name(); // get resource name
};

class book : public resource {
private :
	string member; // member who borrowed resource
	string day_borrow;
	string day_return;

public : 
	book(string member);
	void set_member(string smember);
	string get_member();
	void set_day_borrow(string sday_borrow);
	string get_day_borrow();
	void set_day_return(string sday_return);
	string get_day_return();
};