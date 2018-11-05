#include <iostream>
#include <string>
#include "member.h"
using namespace std;

void member :: set_name(string sname){
	name = sname;
}
string member :: get_name(){
	return name;
}

undergraduate :: undergraduate(){
	book_num = 0;
	book_name = "";
	ban_day = "";
	day = "";
	ban = false;
}

undergraduate :: undergraduate(string sname){
	book_num = 0;
	book_name = "";
	ban_day = "";
	day = "";
	ban = false;
	set_name(sname);	
}
void undergraduate :: set_book_num(int sbook_num){
	book_num = sbook_num;
}
int undergraduate :: get_book_num(){
	return book_num;
}
void undergraduate :: set_book_name(string sbook_name){
	book_name = sbook_name;
}
string undergraduate :: get_book_name(){
	return book_name;
}
void undergraduate :: set_ban_day(string sban_day){
	ban_day = sban_day;
}
string undergraduate :: get_ban_day(){
	return ban_day;
}
void undergraduate :: set_day(string sday){
	day = sday;
}
string undergraduate :: get_day(){
	return day;
}
void undergraduate :: set_ban(bool sban){
	ban = sban;
}
bool undergraduate :: get_ban(){
	return ban;
}
