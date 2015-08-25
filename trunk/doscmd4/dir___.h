/*
 * dir___.h
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#ifndef DIR____H_
#define DIR____H_
#include <regex.h>
#include "def1.h"
#include<string>
#include <vector>
using namespace std;

class dir_opt___{
public:
	bool subdir_;
	bool a_hidden_,a_dir_,a_file_,a_lnk_;
	char tongpei_;
	bool icase_;
	int sort_;
	bool dir_;
	bool lnk_;
	dir_opt___(){
		subdir_=false;
		a_hidden_=a_dir_=a_file_=a_lnk_=false;
		tongpei_=0;
		icase_=false;
		sort_=-1;
		dir_=true;
		lnk_=true;
	}
};

class dir___ {
private:
	int dir2__(char*dir,int depth,string dir2,regex_t* reg,char*tongpei,dir_opt___*opt,const char* src,bool src_is_file,void*ce,void*qu,callback2_2___ cb);
	int exec__(regex_t* reg,char*tongpei,dir_opt___*opt,string dir2,char* name,bool is_dir,const char* src,bool src_is_file,void*ce,void*qu,callback2_2___ cb);
public:
	dir___();
	virtual ~dir___();
	void dir__(int*err1,char*buf,long siz,char*dir,char*tongpei,char*opt1,const char* src,void*ce,void*qu,callback2_2___ cb);
	void sort__(int sort1);

	vector<string> list_;
	int i_,ii_;
};

#endif /* DIR____H_ */
