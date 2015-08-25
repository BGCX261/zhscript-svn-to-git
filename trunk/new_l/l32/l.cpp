#include "l4/l4___.cc"

static l4___ l4_;
void err__(int err){
	if(err)
		cout<<endl<<l4_.err_<<l4_.err__()<<l4_.errinfo__(err)<<endl;
}

int main(int argc,char** argv) {
	int err;
	if(!(err=l4_.init__(argv[0],"-S syn-zh -E err-zh",argc,argv,1))){
		err=l4_.jieshi__();
		if(err==errinfo_src_file_){
			err=0;
			for(;;){
				string s;
				cin>>s;
				if(cin.eof())
					break;
				cout<<l4_.jieshi2__(&err,s.c_str(),false)<<endl;
				err__(err);
				l4_.err_clear__();
			}
		}
	}
	err__(err);
	if(err)
		return 255;
	return l4_.exit_code__();
}
