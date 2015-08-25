/*
 * clpars___.cpp
 *
 *  Created on: 2011-7-10
 *      Author: zzzzzzzzzzz
 */

#include "clpars___.h"
#include <algorithm>
#include <stdio.h>
#include "../new_gg/def1.h"
#include "../new_gg/l4/keyword.h"
#include "../new_gg/call_util.cpp"

static void* jsq_;
static callback3_2___ cb2_;
dlle___ void init__(void* jsq,callback3_2___ cb2){
	jsq_=jsq;
	cb2_=cb2;
}

clpars___::clpars___() {
}

clpars___::~clpars___() {
}

void clpars___::set__(char*buf,int*err,bool add,int argc,va_list& argv,int* sp){
	if(!add)
		item_.clear();

	const char*flag;
	const char*info;
	const char*code;
	const char*s;
	int argc1;
    for (int i = 0; i < argc; ){
        flag = va_arg(argv, const char*); i++;
        if(i <= argc){
			if(sp){
				if(flag[0]=='-'&&flag[1]=='-'&&flag[2]=='-'&&flag[3]=='-'&&!flag[4]){
					*sp=i;
					break;
				}
			}
        }
        info = va_arg(argv, const char*); i++;
        s = va_arg(argv, const char*); i++;
        code = va_arg(argv, const char*); i++;
        if(i>argc){
        	sprintf(buf,"no arg");
        	*err=1;
        	return;
        }
        if(!flag||!code||!s){
        	sprintf(buf,"is null");
        	*err=10;
        	return;
        }
        if(sscanf(s,"%d",&argc1)!=1){
        	sprintf(buf,"no int");
        	*err=2;
        	return;
        }
		clpars_item___* item=new clpars_item___(flag,info,code,argc1);
		item_.push_back(item);
    }
}

int clpars___::cb__(char*buf,int* err,void*ce,void* shangji,const char*flag,const char*flag2,
		int argc,va_list& argv,int&i,char**argv2,int i2,int start){
	int has=0;
    for(list<clpars_item___*>::iterator cii=item_.begin();cii!=item_.end();cii++){
    	clpars_item___* ci=*cii;
    	bool b=(ci->flag_==flag2);
    	if(!b){
    		list<string>::iterator si=find(ci->flags_.begin(),ci->flags_.end(),flag2);
    		b=(si!=ci->flags_.end());
    	}
    	if(b){
    		has++;
    		const char*code;
    		if(ci->code_.empty())
    			code=ci->info_.c_str();
    		else
    			code=ci->code_.c_str();
    		/*if(!*code){
    			sprintf(buf,"'%s' no code",flag2);
    	    	*err=2;
    	    	break;
    		}*/
    		if(has==1){
        		int argc2=ci->argc_+start;
        		if(argc2>16)
        			argc2=16;
				for(;i2<argc2;i2++,i++){
					argv2[i2] = va_arg(argv, char*);
				}
				if(i>argc){
					sprintf(buf,"'%s' no arg",flag2);
					*err=1;
					break;
				}
    		}
    		cb2_(jsq_,shangji,err,ce,code,false,flag,i2,(const char**)argv2,0);
    		switch(*err){
    		case jieshiqi_err_go_+keyword_continue_:
				*err=0;
    			break;
    		}
    		if(*err)
    			break;
    	}
    }
	return has;
}

void clpars___::par__(char*buf,int* err,void*ce,void* shangji,int argc,va_list& argv,int from,bool no){
	char*flag;
	char*argv2[16];
	int has;
	int start;
	if(no)
		start=1;
	else
		start=0;
	char no1[16];
	int i1=0;
    for (int i = from; i < argc; ){
        flag = va_arg(argv, char*);
        if(!flag){
        	sprintf(buf,"is null");
        	*err=10;
        	return;
        }
        i++;

        has=cb__(buf,err,ce,shangji,flag,flag,argc,argv,i,argv2,0,0);
		if(*err)
			return;
        if(has)
        	continue;

		if(no){
			sprintf(no1,"%d",++i1);
			argv2[0]=no1;
		}
		argv2[start]=flag;
		has=cb__(buf,err,ce,shangji,flag,"",argc,argv,i,argv2,start+1,start);
		if(*err)
			return;
        if(has)
        	continue;

    	sprintf(buf,"no parse");
    	*err=3;
    	return;
    }
}

void clpars___::info__(char**&addr_ret,const char* t1,const char* t2,const char* n,bool yange){
	string info;
	list<clpars_item___*>::iterator cii;
	clpars_item___* ci;
	for(cii=item_.begin();cii!=item_.end();cii++){
		ci=*cii;
		info+=t1;
		info+=ci->flag_;
		if(yange||!ci->flag_.empty())
			info+=t2;
		info+=ci->info_;
		info+=n;
    }
	*addr_ret=dup__(info.c_str());
}

dlle___ void del__(clpars___* clp){
	if(clp)
		delete clp;
}

dlle___ void one__(int*err,char*buf,void*ce,void* shangji,bool no,int argc,...){
	clpars___ clp;
    va_list argv;
    va_start(argv, argc);
    int sp;
	clp.set__(buf,err,false,argc,argv,&sp);
	if(!*err)
		clp.par__(buf,err,ce,shangji,argc,argv,sp,no);
	va_end(argv);
}

static clpars___ clpars_;

dlle___ clpars___* set__(int*err,char*buf,bool need_new,bool add,int argc,...){
	clpars___* clp;
	if(need_new)
		clp=new clpars___();
	else
		clp=&clpars_;
    va_list argv;
    va_start(argv, argc);
    clp->set__(buf,err,add,argc,argv,NULL);
	va_end(argv);
	return clp;
}

dlle___ void par__(int* err,char*buf,void*ce,void* shangji,clpars___* clp,bool no,int argc,...){
	if(!clp)
		clp=&clpars_;
    va_list argv;
    va_start(argv, argc);
    clp->par__(buf,err,ce,shangji,argc,argv,0,no);
	va_end(argv);
}

dlle___ void info__(char**addr_ret,clpars___* clp,const char* t1,const char* t2,const char* n,bool yange){
	if(!clp)
		clp=&clpars_;
	clp->info__(addr_ret,t1,t2,n,yange);
}
