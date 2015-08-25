/*
 * dir___.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#include "dir___.h"
#include<dirent.h>
#include<sys/stat.h>
#include"doscmd.h"
#include "for_arg_.h"
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "l4/keyword.h"

dir___::dir___() {
}

dir___::~dir___() {
}

void dir___::dir__(int*err1,char*buf,long siz,char*dir,char*tongpei,char*opt1,
		const char* src,void*ce,void*qu,callback2_2___ cb)
{
	string oldir;
	{
		#define MAXDIR 260
		char cwd[MAXDIR];
		oldir=getcwd(cwd,MAXDIR);
	}

	dir_opt___ opt;
	opt.a_file_=opt.a_lnk_=true;
	for(;*opt1;opt1++){
		switch(*opt1){
		case's':
			opt.subdir_=true;
			continue;
		/*
	T（头匹配）
	A（全匹配）
		 */
		case'T':
		case'A':
			opt.tongpei_=*opt1;
			continue;
		case'l':
			opt.icase_=!opt.icase_;
			continue;
		case'd':
			opt.dir_=!opt.dir_;
			continue;
		case'n':
			opt.lnk_=!opt.lnk_;
			continue;
		case'o':
			opt.sort_=*++opt1-'0';
			if(!(opt.sort_>=0&&opt.sort_<=3))
				break;
			continue;
		case'a':
			switch(*++opt1){
			case'h':
				opt.a_hidden_=!opt.a_hidden_;
				continue;
			case'd':
				opt.a_dir_=!opt.a_dir_;
				continue;
			case'f':
				opt.a_file_=!opt.a_file_;
				continue;
			case'l':
				opt.a_lnk_=!opt.a_lnk_;
				continue;
			}
		}
		buf[0]=*opt1;
		buf[1]=0;
		*err1='o';
		return;
	}

	regex_t reg;
	switch(opt.tongpei_){
	case 0:
	{
		int cflags=REG_EXTENDED|REG_NEWLINE|REG_NOSUB;
		if(opt.icase_)
			cflags|=REG_ICASE;
		int err=regcomp(&reg, tongpei, cflags);
		if(err){
		   regerror(err, &reg, buf, siz);
		   *err1='r';
		   return;
		}
		break;
	}
	}

	*err1=dir2__(dir,0,"",&reg,tongpei,&opt,src,false,ce,qu,cb);

	chdir(oldir.c_str());
	switch(opt.tongpei_){
	case 0:
		regfree(&reg);
		break;
	}

	sort__(opt.sort_);
}

int dir___::dir2__(char*dir,int depth,string dir2,regex_t* reg,char*tongpei,dir_opt___*opt,const char* src,bool src_is_file,void*ce,void*qu,callback2_2___ cb){
	DIR* d;
	if((d=opendir(dir))==NULL)
		return 0;//'d'
	chdir(dir);
	if(dir2.length()>0)
		dir2+='/';
	struct dirent* entry;
	struct stat64 statbuf64;
	struct stat statbuf;
	int exec_max=opt->subdir_?2:1;
	int err;
	for(int exec=0;exec<exec_max;exec++){
		if(exec>0)
			rewinddir(d);
		while((entry=readdir(d))!=NULL){
			char* name=entry->d_name;
			//printf("\n%s %s",dir,name);
			__mode_t st_mode;
			if(lstat64(name,&statbuf64)==-1){
				if(lstat(name,&statbuf)==-1){
					//printf(" %s",strerror(errno));
					continue;
				}else
					st_mode=statbuf.st_mode;
			}else
				st_mode=statbuf64.st_mode;
			if(name[0]=='.'){
				if(!name[1]||(name[1]=='.'&&!name[2]))
					continue;
				if(!opt->a_hidden_)
					continue;
			}
			bool is_dir=false;
			if(S_ISDIR(st_mode))
				is_dir=true;
			else if(S_ISLNK(st_mode)){
				if(opt->a_lnk_){
					if(opt->lnk_){
						DIR* d2;
						if((d2=opendir(name))){
							closedir(d2);
							is_dir=true;
						}
					}
				}else
					continue;
			}
			switch(exec){
			case 0:
				if(is_dir){
					if(opt->a_dir_){
						if((err=exec__(reg,tongpei,opt,dir2,name,true,src,src_is_file,ce,qu,cb))){
							break;
						}
					}
					continue;
				}
				if(opt->a_file_){
					if((err=exec__(reg,tongpei,opt,dir2,name,false,src,src_is_file,ce,qu,cb))){
						break;
					}
				}
				continue;
			case 1://子目录时
				if(is_dir){
					if((err=dir2__(name,depth+1,dir2+name,reg,tongpei,opt,src,src_is_file,ce,qu,cb))){
						closedir(d);
						return err;
					}
					chdir("..");
				}
				continue;
			}
			if(err){
				if(err==jieshiqi_err_go_+keyword_continue_)
					continue;
				closedir(d);
				if(err==jieshiqi_err_go_+keyword_break_)
					return 0;
				return err;
			}
		}
	}
	closedir(d);
	return 0;
}

int dir___::exec__(regex_t* reg,char*tongpei,dir_opt___*opt,string dir2,char* name,bool is_dir,const char* src,bool src_is_file,void*ce,void*qu,callback2_2___ cb){
	bool b=false;
	string name1=name;
	if(is_dir&&opt->a_file_){
		name1+='/';
	}
	if(is_dir&&opt->dir_){
		b=true;
	}else{
		switch(opt->tongpei_){
		case 0:
			b=(regexec(reg, name1.c_str(), 0, 0, 0)==0);
			break;
		case'T':
			{
				size_t i=name1.find(tongpei);
				b=(i==0);
			}
			break;
		case'A':
			b=(strcmp(name,tongpei)==0);
			break;
		}
	}
	//printf(" %d(%s)",b,name1.c_str());
	if(b){
		int err=0;
		string path=dir2+name1;
		if(!src)
			cb(this,qu,&err,ce,src,src_is_file,NULL,1,path.c_str());
		else
			cb(jsq_,qu,&err,ce,src,src_is_file,NULL,1,path.c_str());
		if(err)
			return err;
	}
	return 0;
}

void dir___::sort__(int sort1){
	switch(sort1){
	case 3:
	{
		vector<string>* ls=&list_;
		size_t i1=0;
		for(;;){
			bool b=true;
			for( vector<string>::iterator i=ls->begin()+i1; i != ls->end(); ++i ) {
				string& s=*i;
				size_t i2;
				i2=s.find("index");
				if(i2==0){
				}else{
					/*i2=s.find("/index");
					if(i2!=string::npos)
						if(s.rfind("/")!=i2)*/
							i2=string::npos;
				}
				if(i2!=string::npos){
					string s1=s;
					ls->erase(i);
					ls->insert(ls->begin(),s1);
					b=false;
					i1++;
					break;
				}
			}
			if(b)
				break;
		}
		if(i1>0)
			sort(ls->begin(),ls->begin()+i1);
		sort(ls->begin()+i1,ls->end());
		break;
	}
	case 0:
		sort(list_.begin(),list_.end());
		break;
	case 1:
		sort(list_.rbegin(),list_.rend());
		break;
	case 2:
		i_=list_.size()-1;
		ii_=-1;
		break;
	}
}

dlle___ void dlln___(dir__)(int*err1,char*buf,long siz,char*dir,char*tongpei,char*ctrl,const char* src,void*ce,void*qu){
	dir___ d;
	d.dir__(err1,buf,siz,dir,tongpei,ctrl,src,ce,qu,cb_);
}

const char* cb__(void* jsq,void* shangji,int* err,void*ce,const char* src,bool src_is_file,const char* src2,int argc,...){
	dir___* d=(dir___*)jsq;
	_for_args( argc )
		d->list_.push_back(s);
	//printf("{%s|%d}",s,d->list_.size());
		break;
	_next_args
	return NULL;
}

dlle___ dir___* dlln___(dir_begin__)(int*err1,char*buf,long siz,int argc,...){
	char*dir=".";
	char*tongpei="";
	char*opt="";
	_for_args( argc )
		switch(i){
		case 0:
			dir=s;
			break;
		case 1:
			tongpei=s;
			break;
		case 2:
			opt=s;
			break;
		}
	_next_args
	dir___* d=new dir___();
	d->i_=0;
	d->ii_=1;
	d->dir__(err1,buf,siz,dir,tongpei,opt,0,0,0,cb__);
	return d;
}

dlle___ void dlln___(dir_end__)(dir___*d){
	if(!d)
		return;
	d->list_.clear();
	delete d;
}

dlle___ void dlln___(dir_next__)(char*buf,dir___*d){
	if(!d)
		return;
	if(d->i_>=d->list_.size()||d->i_<0)
		return;
	const char*s=d->list_.at(d->i_).c_str();
	//printf("{%d/%d|%s}",d->i_,d->list_.size(),s);
	strcpy(buf,s);
	d->i_+=d->ii_;
}

dlle___ void dlln___(dir_sort__)(dir___*d,int sort1){
	if(!d)
		return;
	d->sort__(sort1);
}

dlle___ int dlln___(dir_count__)(dir___*d){
	if(!d)
		return -1;
	return d->list_.size();
}
