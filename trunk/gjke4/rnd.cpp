/*
 * rnd.cpp
 *
 *  Created on: 2011-4-16
 *      Author: zzzzzzzzzzz
 */

#include "gjke.h"
#include <stdlib.h>

dlle___ void srand__(long l){
	unsigned int seed;
	if(l==-1)
        seed=time(0);
	else
		seed=l;
    srand(seed);
}

#define var_new__(name,val) var_new_(jsq_,qu,name.c_str(),val,false,false,false)

dlle___ int rand__(void* qu,char*head1,int min,int max){
	if(!head1)
		return -1;
	string head=head1;
	string name;
	char buf[32];
	int err;
	int len=max-min+1;
	if(len>0){
		int* num=new int[len];
		if(!num)
			return -1;
		char buf2[32];
		for(int i=0;i<len;i++){
			for(;;){
				num[i]=random()%len+min;
				bool has=false;
				for(int i1=0;i1<i;i1++){
					if(num[i1]==num[i]){
						has=true;
						break;
					}
				}
				if(!has)
					break;
			}
			name=head+kw_dian_+i2s__(i+1,buf);
			if((err=var_new__(name,i2s__(num[i],buf2))))
				return err;
		}
		delete num;
	}
	name=head+kw_length_;
	if((err=var_new__(name,i2s__(len,buf))))
		return err;
	name=head+kw_length_+"2";
	if((err=var_new__(name,i2s__(1,buf))))
		return err;
	return 0;
}
