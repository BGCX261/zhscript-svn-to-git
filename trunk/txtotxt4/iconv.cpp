/*
 * iconv.cpp
 *
 *  Created on: 2011-1-31
 *      Author: zzzzzzzzzzz
 */

#include"txtotxt.h"
#include <iconv.h>
#include"for_arg_.h"
#include <string.h>
#include <errno.h>

#define bufsiz_ 512

dlle___ void iconv__(char**addr_ret,char *src,int argc,...){
	if(!src)
		return;
	const char *from="gb18030";
	const char *to="utf8";
	_for_args( argc )
	switch(i){
	case 0:
		from=s;
		break;
	case 1:
		to=s;
		break;
	}
	_next_args

	iconv_t cd;
	if((iconv_t)-1 == (cd = iconv_open(to, from)))
		return;

	size_t len=strlen(src);
	char* buf=new char[bufsiz_];
	char *inbuf=src;
	size_t inbytesleft=len;
	char *outbuf;
	size_t outbytesleft;

	string ret;
	while(inbytesleft > 0){
		outbuf=buf;
		outbytesleft=bufsiz_;
		size_t i=iconv (cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
		int err = errno;
		if(outbuf!=buf){
			ret.append(buf, outbuf-buf);
		}
		if(i != (size_t)-1){
			outbuf=buf;
			outbytesleft=bufsiz_;
			iconv (cd, NULL, NULL, &outbuf, &outbytesleft);
			if(outbuf!=buf){
				ret.append(buf, outbuf-buf);
			}
			break;
		}
		if(err){
			if(err==E2BIG)
				;
			else if(err==EILSEQ){
			    inbytesleft = len-(inbuf-src);
			    inbytesleft--;
			    inbuf++;
			}
			else
				break;
		}
	}
	iconv_close(cd);
	delete buf;
	*addr_ret=dup__(ret.c_str());
}
