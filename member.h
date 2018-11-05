#include <iostream>
#include <string>
using namespace std;

class member {
private:
	string name; // member name
public:
	void set_name(string sname);
	string get_name();
};

class undergraduate : public member{
private:
	int book_num; // number of borrowed books
	string book_name;
	string ban_day;
	string day;
	bool ban;
public:
	undergraduate();
	undergraduate(string sname);
	void set_book_num(int sbook_num);
	int get_book_num();
	void set_book_name(string sbook_name);
	string get_book_name();
	void set_ban_day(string sban_day);
	string get_ban_day();
	void set_day(string sday);
	string get_day();
	void set_ban(bool sban);
	bool get_ban();
};