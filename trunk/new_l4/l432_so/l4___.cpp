/*
 * l4___.cpp
 *
 *  Created on: 2009-10-5
 *      Author: zzzzzzzzzzz
 */

#include "jieshiqi___.h"
#include"defi.h"
#include "file___.h"
#include"util.h"
#include "jieshiqi_callback.h"

dlle___ jieshiqi___* l4_new__(){
	return new jieshiqi___();
}
dlle___ void l4_delete__(jieshiqi___* l4){
	delete l4;
}
dlle___ void l4_set_path__(jieshiqi___* l4,const char* s){
	l4->args_.set_path__(s);
}
dlle___ void l4_add_path__(const char* s){
	file_.add_path__(s);
}
dlle___ void l4_del_path__(const char* s){
	file_.del_path__(s);
}
dlle___ void l4_add_arg3__(jieshiqi___* l4,int argc,char** argv,int from){
	l4->args_.add_arg__(argc,argv,from);
}
dlle___ void l4_add_arg__(jieshiqi___* l4,const char* cmdline){
	l4->args_.add_arg__(cmdline);
}
dlle___ int l4_parse_args__(jieshiqi___* l4){
	int err;
	if((err=l4->args_.parse_args__()))
		return err;
	if((err=l4->syn_.get_file__(l4->args_.syn_file_)))
		return err;
	return 0;
}
dlle___ int l4_jieshi__(jieshiqi___* l4,qu___* shangji){
	if(!l4)
		return errinfo_open_;
	string buf;//虽然浪费，但效率、使用度……
	return l4->jieshi__(shangji,buf);
}
dlle___ const char* l4_jieshi2__(jieshiqi___* l4,int* err,const char* src,bool src_is_file,qu___* shangji){
	string& buf=cb_buf__();
	if(l4){
		if(src){
			l4->args_.src_=src;
			l4->args_.src_is_file_=src_is_file;
		}
		*err=l4->jieshi__(shangji,buf);
	}
	return buf.c_str();
}
dlle___ qu___* l4_new_main_qu__(jieshiqi___* l4){
	return l4->new_main_qu__();
}
dlle___ qu___* l4_new_qu__(qu___* shangji){
	qu___* qu=new qu___();
	qu->shangji_=shangji;
	return qu;
}
dlle___ void l4_delete_qu__(qu___* qu){
	if(qu)
		delete qu;
}
dlle___ const char* l4_err__(jieshiqi___* l4){
	if(l4){
		if(l4->args_.err_.has__())
			return l4->args_.err_;
		if(l4->syn_.err_.has__())
			return l4->syn_.err_;
		if(l4->err_.has__())
			return l4->err_;
	}
	return "";
}
dlle___ void l4_err_clear__(jieshiqi___* l4){
	if(!l4)
		return;
	l4->args_.err_.del__();
	l4->syn_.err_.del__();
	l4->err_.del__();
	l4->exit_code_=0;
}
dlle___ int l4_exit_code__(jieshiqi___* l4){
	return l4->exit_code_;
}
dlle___ const char* l4_errinfo__(jieshiqi___* l4,int err){
	if(!l4)
		return "";
	//不必错误判断，因为[]里会
	l4->errinfo_.get_file__(l4->args_.err_file_);
	return l4->errinfo_[err];
}

dlle___ const char* l4_keyword__(jieshiqi___* l4,int kw){
	return l4->syn_[kw].c_str();
}

dlle___ const char* l4_callback3__(jieshiqi___* l4,int* err,const char* src,bool src_is_file,qu___* shangji,int argc,const char**argv,int from){
    return callback3__(l4,shangji,err,false,NULL,src,src_is_file,NULL,argc,argv,from);
}
dlle___ const char* l4_callback3_1__(jieshiqi___* l4,int* err,const char* src,bool src_is_file,const char* src2,qu___* shangji,int argc,const char**argv,int from){
    return callback3__(l4,shangji,err,false,NULL,src,src_is_file,src2,argc,argv,from);
}

dlle___ const char* l4_callback__(jieshiqi___* l4,int* err,const char* src,bool src_is_file,qu___* shangji,int argc,...){
    va_list argv;
    va_start(argv, argc);
    const char* ret=callback1__(l4,shangji,err,false,NULL,src,src_is_file,NULL,argc,argv);
    va_end(argv);
    return ret;
}
dlle___ const char* l4_callback_1__(jieshiqi___* l4,int* err,const char* src,bool src_is_file,const char* src2,qu___* shangji,int argc,...){
    va_list argv;
    va_start(argv, argc);
    const char* ret=callback1__(l4,shangji,err,false,NULL,src,src_is_file,src2,argc,argv);
    va_end(argv);
    return ret;
}
