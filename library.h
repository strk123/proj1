#include <iostream>
#include <vector>
#include <string>
#include "member.h"
#include "resource.h"

using namespace std;

class library {
private:
	vector<book> books;
	vector<undergraduate> undergraduates;
public:
	library();
	void set_books();
	void input();
	int set_data(string date, string resource_type, string resource_name, string operation, string member_type, string member_name);
	void output(int operation_num, int return_code);
	int day2int(string day);
	string int2day(int day);	
};