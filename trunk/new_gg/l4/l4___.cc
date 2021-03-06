/*
 * l4___.cpp
 *
 *  Created on: 2009-11-8
 *      Author: zzzzzzzzzzz
 */

#include "l4___.hh"
#include <sys/stat.h>
#ifndef S_ISLNK
extern "C"{
#endif
#include<dlfcn.h>
#ifndef S_ISLNK
}
#endif
#include <unistd.h>
#include<stdlib.h>

l4___::l4___() {
	dl_=NULL;
	l4_=NULL;
}

l4___::~l4___() {
#ifndef ver_loongson_
	uninit__();
#endif
}

int l4___::uninit__(){
	int err;
	if(l4_){
		l4_delete__(l4_);
		l4_=NULL;
	}
	if((err=unload__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,int argc,char** argv,int from){
	string ex;
	get_ex__(argc,argv,from,ex);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg3__(l4_,argc,argv,from);
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,const char* cmdline){
	string s=cmdline;
	string ex;
	get_ex__(s,ex,true);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg__(l4_,s.c_str());
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init__(const char* path,const char* cmdline,int argc,char** argv,int from){
	string ex;
	get_ex__(argc,argv,from,ex);
	int err;
	if((err=init1__(path,ex.c_str())))
		return err;
	l4_add_arg__(l4_,cmdline);
	l4_add_arg3__(l4_,argc,argv,from);
	if((err=init3__()))
		return err;
	return 0;
}

int l4___::init1__(const char* path,const char* ex){
	int err;
	if((err=load__(path,ex)))
		return err;
	if((err=get_funcs__()))
		return err;
	l4_=l4_new__();
	l4_set_path__(l4_,path_.c_str());
	return 0;
}

void l4___::get_ex__(int argc,char** argv,int from,string& ex){
	for(int i=from;i<argc;i++){
		string s=argv[i];
		int i2=get_ex__(s,ex,false);
		if(i2>0){
			argv[i][i2]=0;
		}
	}
}

int l4___::get_ex__(string& s,string& ex,bool chuli){
	static string _ex="--ex";
	static size_t iex=_ex.size();
	size_t i=s.find(_ex);
	if(i!=string::npos){
		size_t i2=i+iex;
		size_t i3=s.find(' ',i2);
		if(i3==string::npos)
			i3=s.size();
		size_t i1;
		i1=s.find("--",i2/*,i3-i2*/);
		if(i1!=string::npos&&i1<i3){
			ex=s.substr(i+iex,i1-i2);
			if(chuli){
				for(size_t i4=i+2;i4<i3;i4++)
					s[i4]=' ';
			}
			return i+2;
		}
	}
	return 0;
}

int l4___::init3__(){
	int err;
	if((err=l4_parse_args__(l4_)))
		return err;
	return 0;
}

#ifndef S_ISLNK
#define lstat stat
#endif
string realpath__(const char* s){
#ifdef S_ISLNK
	char buf[1024];
#endif
	string buf2;
	struct stat info;
	if (lstat(s, &info) == 0) {
	} else {
		char*PATH=getenv("PATH");
		if(PATH){
			for(int i=0;;){
				char c=PATH[i++];
				if(c==':'||!c){
					if(buf2.size()>0){
						c=buf2[buf2.size()-1];
						if(c=='/'||c=='\\'){
						}else
							buf2+='/';
						buf2+=s;
						if (lstat(buf2.c_str(), &info) == 0) {
							s=buf2.c_str();
							break;
						}
						buf2.clear();
					}
				}else
					buf2+=c;
				if(!c)
					break;
			}
		}
	}
#ifdef S_ISLNK
	if (S_ISLNK(info.st_mode)) {
		ssize_t len;
		if ((len = readlink(s, buf, sizeof(buf)-1)) >= 0){
			buf[len] = '\0';
			s=buf;
		}
	}
	//s = realpath(s, buf);
	if(s[0]!='/'){
		string s2=s;
		buf2=getcwd(buf,sizeof(buf));
		buf2+='/';
		buf2+=s2;
		s=buf2.c_str();
	}
#endif
	return s;
}

void get_path__(string& path){
	unsigned int i=path.rfind('/');
	if(i==string::npos)
		i=path.rfind('\\');
	if(i==string::npos)
		path.clear();
	else
		path=path.substr(0,i+1);
}

int l4___::load__(const char* s,const char* ex){
	string path=realpath__(s);
	get_path__(path);

	path_=path+"l4"+ex;
#ifdef S_ISLNK
	path_+=".so";
#else
	path_+=".dll";
#endif

	dl_=dlopen(path_.c_str(),RTLD_LAZY);
	if(dlerr__())
		return errinfo_open_;
	return 0;
}

int l4___::unload__(){
	if(!dl_)
		return 0;

	dlclose(dl_);
	if(dlerr__())
		return errinfo_close_;
	dl_=0;
	return 0;
}

void* l4___::get_func__(const char* s){
	void*v=dlsym(dl_, s);
	if(dlerr__())
		return 0;
	return v;
}

bool l4___::dlerr__(){
	const char*dlerr=dlerror();
	if(dlerr){
		err_<<dlerr;
		return true;
	}
	return false;
}

#define get_func2__(n,p)	\
	if(!(n=(p)get_func__(#n)))	\
		return errinfo_get_;
int l4___::get_funcs__(){
	get_func2__(l4_new__,void*(*)());
	get_func2__(l4_delete__,void (*)(void* l4));
	get_func2__(l4_set_path__,void (*)(void* l4,const char* s));
	get_func2__(l4_add_path__,void (*)(const char* s));
	get_func2__(l4_del_path__,void (*)(const char* s));
	get_func2__(l4_add_arg3__,void (*)(void* l4,int argc,char** argv,int from));
	get_func2__(l4_add_arg__,void (*)(void* l4,const char* cmdline));
	get_func2__(l4_parse_args__,int (*)(void* l4));
	get_func2__(l4_jieshi__,int (*)(void* l4,void* shangji));
	get_func2__(l4_jieshi2__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void* shangji));
	get_func2__(l4_callback__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void*shangji,int argc,...));
	get_func2__(l4_callback3__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,void* shangji,int argc,const char**argv,int from));
	get_func2__(l4_callback_1__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void*shangji,int argc,...));
	get_func2__(l4_callback3_1__,const char* (*)(void* l4,int* err,const char* src,bool src_is_file,const char* src2,void* shangji,int argc,const char**argv,int from));
	get_func2__(l4_err__,const char* (*)(void* l4));
	get_func2__(l4_errinfo__,const char* (*)(void* l4,int err));
	get_func2__(l4_err_clear__,void (*)(void* l4));
	get_func2__(l4_var_new__,int (*)(void* l4,void* qu,const char* name,const char* val,bool readonly,int type,bool is_noparam));
	get_func2__(l4_keyword__,const char* (*)(void* l4,int kw));
	get_func2__(l4_new_main_qu__,void* (*)(void* l4));
	get_func2__(l4_new_qu__,void* (*)(void* shangji));
	get_func2__(l4_delete_qu__,void (*)(void* qu));
	get_func2__(l4_exit_code__,int (*)(void* l4));
	return 0;
}
