#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
using namespace std;

library :: library() {
	set_books();
	input();
}
void library :: set_books(){
	ifstream input;
	input.open("resource.dat");
	string temp;
	input >> temp;
	input >> temp;
	while(input >> temp){
		input >> temp;
		book book_temp(temp);
		books.push_back(book_temp);
	}
	input.close();
}
void library :: input(){
	ifstream i_dat;
	ofstream o_dat;
	int tempi = 1;
	int cnt = 1;
	string date, resource_type, resource_name, operation, member_type, member_name;
	i_dat.open("input.dat");
	o_dat.open("output.dat");
	string temp;
	for(int i = 0; i<6 ; i++){
		i_dat >> temp;
	}
	o_dat << "Op_#\tReturn_code\tDescription" << endl;
	while(i_dat >> date) {
		i_dat >> resource_type;
		i_dat >> resource_name;
		i_dat >> operation;
		i_dat >> member_type;
		i_dat >> member_name;
		tempi = set_data(date, resource_type, resource_name, operation, member_type, member_name);
		output(cnt,tempi);
		cnt++;
	}
	i_dat.close();
	o_dat.close();
}
int library :: set_data(string date, string resource_type, string resource_name, string operation, string member_type, string member_name){
	int state;
	string temp;
	int i = 0;
	state = 0;
	for(auto a : books){
		if(a.get_name() == resource_name) state = 1;
	}
	if(state == 0){
		return 1;
	}
	if(operation == "B"){
		state = 0;
		for(auto a : undergraduates){
			if(a.get_name() == member_name){
				if(a.get_book_num() > 0){
					return 2;
				}
			}
		}
		for(auto a: undergraduates){
			if(a.get_name() == member_name){
				if(a.get_book_name() == resource_name){
					return 4 + day2int(a.get_day())*10;
				}
			}
		}
		for(auto a : books){
			if(a.get_name() == resource_name){
				if(a.get_member() != member_name && a.get_member() != ""){
					return 5 + day2int(a.get_day_return())*10;
				}
			}
		}
		for(auto a : undergraduates){
			if(a.get_name() == member_name){
				if(a.get_ban() == true && day2int(a.get_ban_day()) >= day2int(date)){
					return 6 + day2int(a.get_ban_day())*10;
				}
			}
		}
		i = 0;
		for(auto a :undergraduates){
			if(a.get_name() == member_name){
			
				a.set_day(date);
				a.set_ban(false);
				a.set_ban_day("");
				a.set_book_name(resource_name);
				a.set_book_num(a.get_book_num()+1);
				undergraduates.push_back(a);
				undergraduates.erase(undergraduates.begin()+i);
				state = 1;
			}
			i++;
		}
		if(state == 0){
			undergraduate b(member_name);
			b.set_day(date);
			b.set_ban(false);
			b.set_ban_day("");
			b.set_book_name(resource_name);
			b.set_book_num(1);
			undergraduates.push_back(b);
		}
		i = 0;
		for(auto a : books){
			if(a.get_name()==resource_name){
				a.set_member(member_name);
				a.set_day_borrow(date);
				a.set_day_return(int2day(day2int(date)+13));
				books.push_back(a);
				books.erase(books.begin()+i);
			}
			i++;
		}
		return 0;
	}
	else if(operation == "R"){
		state = 0;
		for(auto a : undergraduates){
			if(a.get_name() == member_name){
				state = 1;
				if(a.get_book_name() != resource_name){
					return 3;
				}
			}
		}
		if(state == 0){
			return 3;
		}
		for(auto a : undergraduates){
			if(a.get_name() == member_name){
				if(day2int(a.get_day())+13 < day2int(date)){
					temp = "Delayed return. You'll be restricted until " + int2day(2*day2int(date) - day2int(a.get_day())-13);
					a.set_ban_day(int2day(2*day2int(date) - day2int(a.get_day())-13));
					a.set_day("");
					a.set_ban(true);
					a.set_book_name("");
					a.set_book_num(a.get_book_num()-1);
					undergraduates.push_back(a);
					undergraduates.erase(undergraduates.begin()+i);
					i = 0;
					for (auto a : books){
						if(a.get_name() == resource_name){
							a.set_member("");
							a.set_day_borrow("");
							a.set_day_return("");
							books.push_back(a);
							books.erase(books.begin()+i);
						}
						i++;
					}
					return 7 + day2int(a.get_ban_day())*10;
				}
			}
		}
		state = 0;
		i = 0;
		for (auto a : undergraduates) {
			if(a.get_name() == member_name) {
				a.set_day("");
				a.set_ban(false);
				a.set_ban_day("");
				a.set_book_name("");
				a.set_book_num(a.get_book_num()-1);
				undergraduates.push_back(a);
				undergraduates.erase(undergraduates.begin() + i);
			}
			i++;
		}
		i = 0;
		for (auto a : books) {
			if(a.get_name() == resource_name) {
				a.set_member("");
				a.set_day_borrow("");
				a.set_day_return("");
				books.push_back(a);
				books.erase(books.begin() + i);
			} 
			i++;
		}
		return 0;
	}
}

void library :: output(int operation_num, int return_code){
	ofstream out;
	out.open("output.dat", ios::app);
	string temp;
	if(return_code == 0) out << operation_num << "\t" << return_code << "\tSuccess." << endl;
	else if(return_code == 1) out << operation_num << "\t" << return_code << "\tNon exist resource." << endl;
	else if(return_code == 2) out << operation_num << "\t" << return_code << "\tExceeds your possible number of borrow. Possible # of borrows: 1" << endl;
	else if(return_code == 3) out << operation_num << "\t" << return_code << "\tYou did not borrow this book."<< endl;
	else if(return_code%10 == 4) out << operation_num << "\t" << return_code%10 << "\tYou already borrow this book at " <<int2day(return_code/10)<< endl;
	else if(return_code%10 == 5) out << operation_num << "\t" << return_code%10 << "\tOther member already borrowed this book. This book will be returned at " << int2day(return_code/10) << endl;
	else if(return_code%10 == 6) out << operation_num << "\t" << return_code%10 << "\tRestricted member until " << int2day(return_code/10) << endl;
	else if(return_code%10 == 7) out << operation_num << "\t" << return_code%10 << "\tDelayed return. You'll be restricted until " << int2day(return_code/10) << endl;
	out.close();
}

int library :: day2int(string day){
	string y, m, d;
	y = day[0];
	y = y + day[1];
	m = day[3];
	m = m + day[4];
	d = day[6];
	d = d + day[7];
	return stoi(y) * 360 + stoi(m)*30 + stoi(d);;	
}
string library :: int2day(int day){
	string y, m, d;
	y = to_string(day/360);
	if(y.length()==1) y = "0" + y;
	m = to_string((day%360)/30);
	if(m.length()==1) m = "0" + m;
	d = to_string((day%360)%30);
	if(d.length()==1) d = "0" + d;
	return y + "/" + m + "/" + d;	
}