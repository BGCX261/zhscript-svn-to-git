/*
 * gjke.h
 *
 *  Created on: 2010-5-9
 *      Author: zzzzzzzzzzz
 */

#ifndef GJKE_H_
#define GJKE_H_
#include<string>
#include<iostream>
using namespace std;

#include "def1.h"
#include"call_util.h"

extern callback2_2___ callback_;
extern callback3_2___ callback3_;
extern var_new___ var_new_;
extern var_get___ var_get_;
extern var_del___ var_del_;
extern void* jsq_;
extern string kw_length_,kw_dian_;

char* i2s__(int i,char buf[]);
unsigned long x2lu__(char*s);
int s2i__(const char* s);
bool startswith__(const char*src,const char*tag);
#endif /* GJKE_H_ */
