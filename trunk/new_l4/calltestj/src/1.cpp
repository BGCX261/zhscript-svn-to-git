//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdarg.h>

unsigned long l_z__(int argc,...){
	cout << "l__("<<argc<<")"/*<<endl*/<<"{";
    va_list argv;
    va_start(argv, argc);
    for (int i = 0; i < argc; ++i){
        //char*s = va_arg(argv, char*);
    	void*s = va_arg(argv, void*);
    	//unsigned long s = va_arg(argv, unsigned long);
		cout << s << ",";
    }
    va_end(argv);
	cout << "}//l__" << endl;
	return 1000+argc;
}

void v__(){
	cout<<"v__ "<<(void*)v__<<endl;
}

unsigned long l_v__(){
	cout<<"l_v__ "<<(void*)l_v__<<endl;
	return 1;
}

unsigned long l_z0__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc);
}
unsigned long l_z1__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1]);
}
unsigned long l_z2__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2]);
}
unsigned long l_z3__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3]);
}
unsigned long l_z4__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4]);
}
unsigned long l_z5__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5]);
}
unsigned long l_z6__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6]);
}
unsigned long l_z7__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7]);
}
unsigned long l_z8__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8]);
}
unsigned long l_z9__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9]);
}
unsigned long l_z10__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10]);
}
unsigned long l_z11__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11]);
}
unsigned long l_z12__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11],argv[12]);
}
unsigned long l_z13__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11],argv[12],argv[13]);
}
unsigned long l_z14__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11],argv[12],argv[13],argv[14]);
}
unsigned long l_z15__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11],argv[12],argv[13],argv[14],argv[15]);
}
unsigned long l_z16__(void*func,bool ret,int argc,unsigned long *argv){
	return ((unsigned long (*)(int argc,...))func)(argc,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],argv[11],argv[12],argv[13],argv[14],argv[15],argv[16]);
}

unsigned long int call_func2__(void*func,bool ret,int argc,unsigned long *argv){
	unsigned long int ax_qi4;
	int i;
	unsigned long sp,sp0;
#ifdef ver_64_
	__asm__ volatile ("mov %%rsp,%0":"=m"( sp0 ));
	sp=sp0;
	/*for(i=argc-1;i>=0;i--,sp-=8)
		__asm__ volatile ("mov %0,%%rsp\n\tmov %1,%%rax\n\tmov %%rax,(%%rsp)"
				::"m"( sp ),"m"( argv[i] ) );
	__asm__ volatile ("mov 0,%%eax\n\tcallq *%1\n\tmov %%rax,%0\n\tmov %2,%%rsp"
			:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));*/
	if(argc==-1){
		if(ret){
			__asm__ volatile (
					"callq *%1" "\n"
					"mov %%rax,%0" "\n"
					"mov %2,%%rsp"
					:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));
		}else{
			__asm__ volatile (
					"callq *%0" "\n"
					"mov %1,%%rsp"
					::"m"( func ),"m"( sp0 ));
		}
	}else{
		sp-=0x20+argc*8;
		__asm__ volatile (
				"push %%rbx\n"
				"mov %1,%%rbx\n"
				"mov %0,%%rax\n"
				"sub $512,%%rsp\n"
				"cmp $64,%%rax\n"
				"je case64\n"
				"cmp $63,%%rax\n"
				"je case63\n"
				"cmp $62,%%rax\n"
				"je case62\n"
				"cmp $61,%%rax\n"
				"je case61\n"
				"cmp $60,%%rax\n"
				"je case60\n"
				"cmp $59,%%rax\n"
				"je case59\n"
				"cmp $58,%%rax\n"
				"je case58\n"
				"cmp $57,%%rax\n"
				"je case57\n"
				"cmp $56,%%rax\n"
				"je case56\n"
				"cmp $55,%%rax\n"
				"je case55\n"
				"cmp $54,%%rax\n"
				"je case54\n"
				"cmp $53,%%rax\n"
				"je case53\n"
				"cmp $52,%%rax\n"
				"je case52\n"
				"cmp $51,%%rax\n"
				"je case51\n"
				"cmp $50,%%rax\n"
				"je case50\n"
				"cmp $49,%%rax\n"
				"je case49\n"
				"cmp $48,%%rax\n"
				"je case48\n"
				"cmp $47,%%rax\n"
				"je case47\n"
				"cmp $46,%%rax\n"
				"je case46\n"
				"cmp $45,%%rax\n"
				"je case45\n"
				"cmp $44,%%rax\n"
				"je case44\n"
				"cmp $43,%%rax\n"
				"je case43\n"
				"cmp $42,%%rax\n"
				"je case42\n"
				"cmp $41,%%rax\n"
				"je case41\n"
				"cmp $40,%%rax\n"
				"je case40\n"
				"cmp $39,%%rax\n"
				"je case39\n"
				"cmp $38,%%rax\n"
				"je case38\n"
				"cmp $37,%%rax\n"
				"je case37\n"
				"cmp $36,%%rax\n"
				"je case36\n"
				"cmp $35,%%rax\n"
				"je case35\n"
				"cmp $34,%%rax\n"
				"je case34\n"
				"cmp $33,%%rax\n"
				"je case33\n"
				"cmp $32,%%rax\n"
				"je case32\n"
				"cmp $31,%%rax\n"
				"je case31\n"
				"cmp $30,%%rax\n"
				"je case30\n"
				"cmp $29,%%rax\n"
				"je case29\n"
				"cmp $28,%%rax\n"
				"je case28\n"
				"cmp $27,%%rax\n"
				"je case27\n"
				"cmp $26,%%rax\n"
				"je case26\n"
				"cmp $25,%%rax\n"
				"je case25\n"
				"cmp $24,%%rax\n"
				"je case24\n"
				"cmp $23,%%rax\n"
				"je case23\n"
				"cmp $22,%%rax\n"
				"je case22\n"
				"cmp $21,%%rax\n"
				"je case21\n"
				"cmp $20,%%rax\n"
				"je case20\n"
				"cmp $19,%%rax\n"
				"je case19\n"
				"cmp $18,%%rax\n"
				"je case18\n"
				"cmp $17,%%rax\n"
				"je case17\n"
				"cmp $16,%%rax\n"
				"je case16\n"
				"cmp $15,%%rax\n"
				"je case15\n"
				"cmp $14,%%rax\n"
				"je case14\n"
				"cmp $13,%%rax\n"
				"je case13\n"
				"cmp $12,%%rax\n"
				"je case12\n"
				"cmp $11,%%rax\n"
				"je case11\n"
				"cmp $10,%%rax\n"
				"je case10\n"
				"cmp $9,%%rax\n"
				"je case9\n"
				"cmp $8,%%rax\n"
				"je case8\n"
				"cmp $7,%%rax\n"
				"je case7\n"
				"cmp $6,%%rax\n"
				"je case6\n"
				"cmp $5,%%rax\n"
				"je case5\n"
				"cmp $4,%%rax\n"
				"je case4\n"
				"cmp $3,%%rax\n"
				"je case3\n"
				"cmp $2,%%rax\n"
				"je case2\n"
				"cmp $1,%%rax\n"
				"je case1\n"
				"cmp $0,%%rax\n"
				"jbe case0\n"
				"case64:\n"
				"mov 504(%%rbx),%%rax\n"
				"mov %%rax,464(%%rsp)\n"
				"case63:\n"
				"mov 496(%%rbx),%%rax\n"
				"mov %%rax,456(%%rsp)\n"
				"case62:\n"
				"mov 488(%%rbx),%%rax\n"
				"mov %%rax,448(%%rsp)\n"
				"case61:\n"
				"mov 480(%%rbx),%%rax\n"
				"mov %%rax,440(%%rsp)\n"
				"case60:\n"
				"mov 472(%%rbx),%%rax\n"
				"mov %%rax,432(%%rsp)\n"
				"case59:\n"
				"mov 464(%%rbx),%%rax\n"
				"mov %%rax,424(%%rsp)\n"
				"case58:\n"
				"mov 456(%%rbx),%%rax\n"
				"mov %%rax,416(%%rsp)\n"
				"case57:\n"
				"mov 448(%%rbx),%%rax\n"
				"mov %%rax,408(%%rsp)\n"
				"case56:\n"
				"mov 440(%%rbx),%%rax\n"
				"mov %%rax,400(%%rsp)\n"
				"case55:\n"
				"mov 432(%%rbx),%%rax\n"
				"mov %%rax,392(%%rsp)\n"
				"case54:\n"
				"mov 424(%%rbx),%%rax\n"
				"mov %%rax,384(%%rsp)\n"
				"case53:\n"
				"mov 416(%%rbx),%%rax\n"
				"mov %%rax,376(%%rsp)\n"
				"case52:\n"
				"mov 408(%%rbx),%%rax\n"
				"mov %%rax,368(%%rsp)\n"
				"case51:\n"
				"mov 400(%%rbx),%%rax\n"
				"mov %%rax,360(%%rsp)\n"
				"case50:\n"
				"mov 392(%%rbx),%%rax\n"
				"mov %%rax,352(%%rsp)\n"
				"case49:\n"
				"mov 384(%%rbx),%%rax\n"
				"mov %%rax,344(%%rsp)\n"
				"case48:\n"
				"mov 376(%%rbx),%%rax\n"
				"mov %%rax,336(%%rsp)\n"
				"case47:\n"
				"mov 368(%%rbx),%%rax\n"
				"mov %%rax,328(%%rsp)\n"
				"case46:\n"
				"mov 360(%%rbx),%%rax\n"
				"mov %%rax,320(%%rsp)\n"
				"case45:\n"
				"mov 352(%%rbx),%%rax\n"
				"mov %%rax,312(%%rsp)\n"
				"case44:\n"
				"mov 344(%%rbx),%%rax\n"
				"mov %%rax,304(%%rsp)\n"
				"case43:\n"
				"mov 336(%%rbx),%%rax\n"
				"mov %%rax,296(%%rsp)\n"
				"case42:\n"
				"mov 328(%%rbx),%%rax\n"
				"mov %%rax,288(%%rsp)\n"
				"case41:\n"
				"mov 320(%%rbx),%%rax\n"
				"mov %%rax,280(%%rsp)\n"
				"case40:\n"
				"mov 312(%%rbx),%%rax\n"
				"mov %%rax,272(%%rsp)\n"
				"case39:\n"
				"mov 304(%%rbx),%%rax\n"
				"mov %%rax,264(%%rsp)\n"
				"case38:\n"
				"mov 296(%%rbx),%%rax\n"
				"mov %%rax,256(%%rsp)\n"
				"case37:\n"
				"mov 288(%%rbx),%%rax\n"
				"mov %%rax,248(%%rsp)\n"
				"case36:\n"
				"mov 280(%%rbx),%%rax\n"
				"mov %%rax,240(%%rsp)\n"
				"case35:\n"
				"mov 272(%%rbx),%%rax\n"
				"mov %%rax,232(%%rsp)\n"
				"case34:\n"
				"mov 264(%%rbx),%%rax\n"
				"mov %%rax,224(%%rsp)\n"
				"case33:\n"
				"mov 256(%%rbx),%%rax\n"
				"mov %%rax,216(%%rsp)\n"
				"case32:\n"
				"mov 248(%%rbx),%%rax\n"
				"mov %%rax,208(%%rsp)\n"
				"case31:\n"
				"mov 240(%%rbx),%%rax\n"
				"mov %%rax,200(%%rsp)\n"
				"case30:\n"
				"mov 232(%%rbx),%%rax\n"
				"mov %%rax,192(%%rsp)\n"
				"case29:\n"
				"mov 224(%%rbx),%%rax\n"
				"mov %%rax,184(%%rsp)\n"
				"case28:\n"
				"mov 216(%%rbx),%%rax\n"
				"mov %%rax,176(%%rsp)\n"
				"case27:\n"
				"mov 208(%%rbx),%%rax\n"
				"mov %%rax,168(%%rsp)\n"
				"case26:\n"
				"mov 200(%%rbx),%%rax\n"
				"mov %%rax,160(%%rsp)\n"
				"case25:\n"
				"mov 192(%%rbx),%%rax\n"
				"mov %%rax,152(%%rsp)\n"
				"case24:\n"
				"mov 184(%%rbx),%%rax\n"
				"mov %%rax,144(%%rsp)\n"
				"case23:\n"
				"mov 176(%%rbx),%%rax\n"
				"mov %%rax,136(%%rsp)\n"
				"case22:\n"
				"mov 168(%%rbx),%%rax\n"
				"mov %%rax,128(%%rsp)\n"
				"case21:\n"
				"mov 160(%%rbx),%%rax\n"
				"mov %%rax,120(%%rsp)\n"
				"case20:\n"
				"mov 152(%%rbx),%%rax\n"
				"mov %%rax,112(%%rsp)\n"
				"case19:\n"
				"mov 144(%%rbx),%%rax\n"
				"mov %%rax,104(%%rsp)\n"
				"case18:\n"
				"mov 136(%%rbx),%%rax\n"
				"mov %%rax,96(%%rsp)\n"
				"case17:\n"
				"mov 128(%%rbx),%%rax\n"
				"mov %%rax,88(%%rsp)\n"
				"case16:\n"
				"mov 120(%%rbx),%%rax\n"
				"mov %%rax,80(%%rsp)\n"
				"case15:\n"
				"mov 112(%%rbx),%%rax\n"
				"mov %%rax,72(%%rsp)\n"
				"case14:\n"
				"mov 104(%%rbx),%%rax\n"
				"mov %%rax,64(%%rsp)\n"
				"case13:\n"
				"mov 96(%%rbx),%%rax\n"
				"mov %%rax,56(%%rsp)\n"
				"case12:\n"
				"mov 88(%%rbx),%%rax\n"
				"mov %%rax,48(%%rsp)\n"
				"case11:\n"
				"mov 80(%%rbx),%%rax\n"
				"mov %%rax,40(%%rsp)\n"
				"case10:\n"
				"mov 72(%%rbx),%%rax\n"
				"mov %%rax,32(%%rsp)\n"
				"case9:\n"
				"mov 64(%%rbx),%%rax\n"
				"mov %%rax,24(%%rsp)\n"
				"case8:\n"
				"mov 56(%%rbx),%%rax\n"
				"mov %%rax,16(%%rsp)\n"
				"case7:\n"
				"mov 48(%%rbx),%%rax\n"
				"mov %%rax,8(%%rsp)\n"
				"mov 40(%%rbx),%%rax\n"
				"mov %%rax,0(%%rsp)\n"
				//"jmp case5\n"
				"case6:\n"
				"mov 40(%%rbx),%%r9\n"
				"case5:\n"
				"mov 32(%%rbx),%%r8\n"
				"case4:\n"
				"mov 24(%%rbx),%%rcx\n"
				"case3:\n"
				"mov 16(%%rbx),%%rdx\n"
				"case2:\n"
				"mov 8(%%rbx),%%rsi\n"
				"case1:\n"
				"mov 0(%%rbx),%%rdi\n"
				"case0:\n"
				"pop %%rbx\n"
				"mov $0x0,%%eax\n"
				::"m"( argc ),"m"( argv ),"m"( sp ));
		if(ret){
			__asm__ volatile (
					"callq *%1" "\n"
					"mov %%rax,%0" "\n"
					"mov %2,%%rsp\n"
					:"=m"( ax_qi4  ):"m"( func ),"m"( sp0 ));
		}else{
			__asm__ volatile (
					"callq *%0" "\n"
					"mov %1,%%rsp\n"
					::"m"( func ),"m"( sp0 ));
		}
	}
#endif
	return ax_qi4;
}

void switch__(int i){
	switch(i){
	default:
		if(i<0)
			break;
	case 3:
		cout<<"...";
	case 2:
		cout<<"c";
	case 1:
		cout<<"b";
	case 0:
		cout<<"a";
	}
	cout<<endl;
}

int main() {
#define len 64
	unsigned long l[len],l1;
	for(int i=1;i<len;i++){
		char*s=new char[8];
		sprintf(s,"%d",i);
		l[i]=(unsigned long)s;
	}

	//switch__(-1);

	/*v__();
	call_func2__((void*)v__,false,-1,0);
	l1=l_v__();cout<<"l1="<<l1<<endl;
	l1=call_func2__((void*)l_v__,true,-1,0);cout<<"l1="<<l1<<endl;*/

	//call_func2__((void*)v__,false,0,l);
	//l1=call_func2__((void*)l_v__,true,0,l);cout<<"l1="<<l1<<endl;

	//l1=l_z0__((void*)l_z__,true,0,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(0);//cout<<"l1="<<l1<<endl;
	//l[0]=0;l1=call_func2__((void*)l_z__,true,0,l);cout<<"l1="<<l1<<endl;
	//l1=l_z1__((void*)l_z__,true,1,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(1,l[1]);//cout<<"l1="<<l1<<endl;
	//l[0]=1;l1=call_func2__((void*)l_z__,true,1,l);cout<<"l1="<<l1<<endl;
	//l1=l_z2__((void*)l_z__,true,2,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(2,l[1],l[2]);//cout<<"l1="<<l1<<endl;
	//l[0]=2;l1=call_func2__((void*)l_z__,true,2,l);cout<<"l1="<<l1<<endl;
	//l1=l_z3__((void*)l_z__,true,3,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(3,l[1],l[2],l[3]);//cout<<"l1="<<l1<<endl;
	//l[0]=3;l1=call_func2__((void*)l_z__,true,3,l);cout<<"l1="<<l1<<endl;
	//l1=l_z4__((void*)l_z__,true,4,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(4,l[1],l[2],l[3],l[4]);//cout<<"l1="<<l1<<endl;
	//l[0]=4;l1=call_func2__((void*)l_z__,true,4,l);cout<<"l1="<<l1<<endl;
	//l1=l_z5__((void*)l_z__,true,5,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(5,l[1],l[2],l[3],l[4],l[5]);//cout<<"l1="<<l1<<endl;
	//l[0]=5;l1=call_func2__((void*)l_z__,true,5,l);cout<<"l1="<<l1<<endl;
	//l1=l_z6__((void*)l_z__,true,6,l);//cout<<"l1="<<l1<<endl;
	l1=l_z__(6,l[1],l[2],l[3],l[4],l[5],l[6]);//cout<<"l1="<<l1<<endl;
	l[0]=6;l1=call_func2__((void*)l_z__,true,6,l);cout<<"l1="<<l1<<endl;
	//l1=l_z7__((void*)l_z__,true,7,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(7,l[1],l[2],l[3],l[4],l[5],l[6],l[7]);//cout<<"l1="<<l1<<endl;
	//l[0]=7;l1=call_func2__((void*)l_z__,true,7,l);cout<<"l1="<<l1<<endl;
	//l1=l_z8__((void*)l_z__,true,8,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(8,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8]);//cout<<"l1="<<l1<<endl;
	//l[0]=8;l1=call_func2__((void*)l_z__,true,8,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z9__((void*)l_z__,true,9,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(9,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9]);//cout<<"l1="<<l1<<endl;
	//l[0]=9;l1=call_func2__((void*)l_z__,true,9,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z10__((void*)l_z__,true,10,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(10,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10]);//cout<<"l1="<<l1<<endl;
	//l[0]=10;l1=call_func2__((void*)l_z__,true,10,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z11__((void*)l_z__,true,11,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(11,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11]);//cout<<"l1="<<l1<<endl;
	//l[0]=11;l1=call_func2__((void*)l_z__,true,11,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z12__((void*)l_z__,true,12,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(12,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11],l[12]);//cout<<"l1="<<l1<<endl;
	//l[0]=12;l1=call_func2__((void*)l_z__,true,12,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z13__((void*)l_z__,true,13,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(13,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11],l[12],l[13]);//cout<<"l1="<<l1<<endl;
	//l[0]=13;l1=call_func2__((void*)l_z__,true,13,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z14__((void*)l_z__,true,14,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(14,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11],l[12],l[13],l[14]);//cout<<"l1="<<l1<<endl;
	//l[0]=14;l1=call_func2__((void*)l_z__,true,14,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z15__((void*)l_z__,true,15,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(15,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11],l[12],l[13],l[14],l[15]);//cout<<"l1="<<l1<<endl;
	//l[0]=15;l1=call_func2__((void*)l_z__,true,15,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z16__((void*)l_z__,true,16,l);//cout<<"l1="<<l1<<endl;
	//l1=l_z__(16,l[1],l[2],l[3],l[4],l[5],l[6],l[7],l[8],l[9],l[10],l[11],l[12],l[13],l[14],l[15],l[16]);//cout<<"l1="<<l1<<endl;
	//l[0]=16;l1=call_func2__((void*)l_z__,true,16,l);//cout<<"l1="<<l1<<endl;

	/*for(int i=1;i<len;i++){
		char*s=(char*)l[i];
		delete s;
	}*/
	return 0;
}
