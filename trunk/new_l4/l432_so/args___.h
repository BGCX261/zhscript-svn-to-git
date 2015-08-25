/*
 * args___.h
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#ifndef ARGS____H_
#define ARGS____H_
#include <string>
#include <list>
#include<deque>
#include <iostream>
using namespace std;

#include"err___.h"
#include"errinfo.h"

class args___ {
private:
	list<string> args_;
	bool get_arg_str__(unsigned char c1,unsigned char c,const string& s,size_t& i,string& buf);
	void args_push_back__(const string& s);

	//string path_;

	list<string>::iterator li_;
	int get_arg__(const string& s1,string& s2);
public:
	args___();
	virtual ~args___();

	void set_path__(const string& s);

	string syn_file_,err_file_;
	string src_,src2_;
	bool src_is_file_;
	deque<string> params_;

	void add_arg__(int argc,char** argv,int from=0);
	void add_arg__(const string& cmdline);
	void params_push_back__(const string& s);
	int get_ini_file__(const string& filename);
	int parse_args__();

	err___ err_;
};

#endif /* ARGS____H_ */
