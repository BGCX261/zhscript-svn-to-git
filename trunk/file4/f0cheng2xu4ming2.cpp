#ifndef WIN32
#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>
#include<string>
#endif
using namespace std;
#include"f0lu4shang4.h"

#include"def1.h"

#define bufsiz 512
string buf__;

dlle___
const char *cheng2xu4ming2___(char*ming2){
  char* buf=new char[bufsiz];
#ifdef WIN32
	if(f0zai4(ming2)!=NULL){
		int i;
		for(i=0;ming2[i];i++){
			if(i==0 && ming2[i]=='.')
				break;
			if(ming2[i]=='\\' || ming2[i]=='/'){
				i=-1;
				break;
			}
		}
		if(i==-1)
			buf[0]=0;
		else{
			GetCurrentDirectory(bufsiz,buf);
			lstrcat(buf,"\\");
		}
		lstrcat(buf,ming2);
	}else{
		ming2=f0lu4shang4("PATH",ming2,buf);
		if(ming2==NULL){
			delete buf;
			return NULL;
		}
	}
#else
	struct stat info;
	if (lstat(ming2, &info) == 0) {
		ming2 = realpath(ming2, buf);
	} else {
		ming2 = f0lu4shang4("PATH", ming2, buf);
	}
	if (ming2 == NULL) {
		delete buf;
		return NULL;
	}
	lstat(ming2, &info);
	if (S_ISLNK(info.st_mode)) {
		int i = readlink(ming2, buf, bufsiz);
		if (i < 0) {
			//perror("readlink() error");
			delete buf;
			return NULL;
		}
		buf[i] = 0;
	}
#endif
	buf__=buf;
	delete buf;
	return buf__.c_str();
}
