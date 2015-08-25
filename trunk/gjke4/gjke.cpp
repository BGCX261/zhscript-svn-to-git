/*
 * gjke.cpp
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#include"gjke.h"

callback2_2___ callback_;
callback3_2___ callback3_;
var_new___ var_new_;
var_get___ var_get_;
var_del___ var_del_;
void* jsq_;
void* qu_;
string kw_length_,kw_dian_;

dlle___ void dlln___(init__)(void* jsq,
		callback2_2___ cb,
		callback3_2___ cb3,
		var_new___ var_new,var_get___ var_get,var_del___ var_del,
		char*len,char*dian)
{
	jsq_=jsq;
	callback_=cb;
	callback3_=cb3;
	var_new_=var_new;
	var_get_=var_get;
	var_del_=var_del;
	kw_length_=len;
	kw_dian_=dian;
}

#include<stdio.h>

char* i2s__(int i,char buf[]){
	sprintf(buf,"%d",i);
	return buf;
}
unsigned long x2lu__(char*s){
	unsigned long l=0;
	sscanf(s,"%lx",&l);
	return l;
}
int s2i__(const char* s){
	int i;
	sscanf(s,"%d",&i);
	return i;
}

#include"call_util.cpp"
