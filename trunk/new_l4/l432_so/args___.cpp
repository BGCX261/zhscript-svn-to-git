/*
 * args___.cpp
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#include "args___.h"
#include "file___.h"
#include "path.h"

args___::args___() {
	src_is_file_=true;
}

args___::~args___() {
}

void args___::args_push_back__(const string& s){
	args_.push_back(s);
}

void args___::params_push_back__(const string& s){
	params_.push_back(s);
}

void args___::add_arg__(int argc,char** argv,int from){
	if(from<0)
		return;
	for(int i=from;i<argc;i++){
		string s=argv[i];
		if(i==from){
			size_t i1=s.rfind("--");
			if(i1!=string::npos){
				if(i1>0&&s[i1-1]==' '){
					add_arg__(s.substr(0,i1-1));
					continue;
				}
				if(s.length()>2){
					if((s[2]>='0'&&s[2]<='9')||(s[2]>='a'&&s[2]<='z')||(s[2]>='A'&&s[2]<='Z')||s[2]=='-')
						;
					else
						s.resize(2);
				}
			}
		}
		args_push_back__(s);
	}
}

void args___::add_arg__(const string& cmdline){
	string buf;
	bool empty=true;
	for(size_t i=0;i<cmdline.length();i++){
		unsigned char c=cmdline[i];
		if(c<=' '){
			if(!empty){
				args_push_back__(buf);
				buf.clear();
				empty=true;
			}
			continue;
		}
		empty=false;
		if(get_arg_str__('"',c,cmdline,i,buf))
			continue;
		if(get_arg_str__('\'',c,cmdline,i,buf))
			continue;
		buf+=c;
	}
	if(!empty)
		args_push_back__(buf);
}

bool args___::get_arg_str__(unsigned char c1,unsigned char c,const string& s,size_t& i,string& buf){
	if(c==c1){
		for(;;){
			if(++i>=s.length()){
				break;
			}
			c=s[i];
			if(c==c1)
				break;
			buf+=c;
		}
		return true;
	}
	return false;
}

void args___::set_path__(const string& s){
	file_.add_path1__(s);
	/*//path_没用，但不如此在loongson会报“总线错误”
	path_=s;
	file_.add_path1__(path_);*/
}

int args___::get_arg__(const string& s1,string& s2){
	if(*li_==s1){
		if(++li_==args_.end()){
			err_<<s1;
			return 1;
		}
		s2=*li_;
		return 2;
	}
	return 0;
}

int args___::get_ini_file__(const string& filename){
	string buf;
	int err=file_.get__(filename,buf);
	if(err){
		err_<<file_.err_;
		return err;
	}
	add_arg__(buf);
	return 0;
}

int args___::parse_args__(){
	bool all_is_param=false;
	for(li_=args_.begin();li_!=args_.end();++li_) {
		string s=*li_;

		if(s=="----"){
			all_is_param=!all_is_param;
			continue;
		}
		if(all_is_param){
			params_push_back__(s);
			continue;
		}

		switch(get_arg__("-S",syn_file_)){
		case 1:	return errinfo_param_num_;
		case 2:	continue;
		}
		switch(get_arg__("-E",err_file_)){
		case 1:	return errinfo_param_num_;
		case 2:	continue;
		}
		if(s=="-I"){
			if(++li_==args_.end())
				return errinfo_param_num_;
			int err=get_ini_file__(*li_);
			if(err)
				return err;
			continue;
		}
		if(s=="-P"){
			if(++li_==args_.end())
				return errinfo_param_num_;
			params_push_back__(*li_);
			continue;
		}
		//极大灵活性地接收参数
		if(s.length()>0&&s[0]!='-'&&src_.empty()){
			src_=s;
			continue;
		}
		if(s=="--")
			continue;
		/*err_<<src_<<" "<<s;
		return errinfo_param_err_;*/
		params_push_back__(s);
	}
	return 0;
}
