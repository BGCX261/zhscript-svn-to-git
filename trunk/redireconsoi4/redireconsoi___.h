#ifndef REDIRECONSOI____H_
#define REDIRECONSOI____H_
#include "def1.h"
#include<string>
#include<stdio.h>

class redireconsoi___
{
private:
	bool get_x_r__(char* pResult,int count,int& i,int& i_1);
	void read__(int fd[],char pResult[]);
public:
	redireconsoi___();
	virtual ~redireconsoi___();
	int my_system( const char * pCmd, int message );
	bool char_;

	callback2___	cb2_;
	void*	jsq_;
	void*	shangji_;
	char*		script_;
	callback2___	cb2_r_;
	char*		script_r_;

	const char* out_;
	unsigned int out_len_;
};

#endif /*REDIRECONSOI____H_*/
