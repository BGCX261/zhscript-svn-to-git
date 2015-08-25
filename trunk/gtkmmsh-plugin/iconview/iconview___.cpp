/*
 * iconview___.cpp
 *
 *  Created on: 2010-9-12
 *      Author: zzzzzzzzzzz
 */

#include "iconview___.h"
#include"util.cpp"
#include"plugin_def.h"

class columnrecord___:public Gtk::TreeModel::ColumnRecord{
public:
	columnrecord___(){
		add(s_);
		add(title_);
		add(icon_);
		add(icon_path_);
		add(s2_);
		add(child_);
	}
	Gtk::TreeModelColumn <Glib::ustring> s_;
	Gtk::TreeModelColumn <Glib::ustring> title_,icon_path_,s2_;
	Gtk::TreeModelColumn <Glib::RefPtr<Gdk::Pixbuf> > icon_;
	Gtk::TreeModelColumn <std::deque<Glib::ustring>*> child_;
};

#define id_status_use_	0
#define id_status_edit_	1

class iconview_data___{
private:
	Glib::RefPtr<Gtk::ListStore> ls_;
	columnrecord___* cr_;
	Gtk::IconView* iv_;

	shell___* sh_;
	direct___ d_;
	const char* zhao_;

	iconview___* iv1_;

public:
	Glib::ustring code_;
	Glib::ustring dong_;
	Gtk::Menu* menu_;
	Gtk::Menu* menu1_;

	int status_;

	iconview_data___(Gtk::IconView* iv,std::deque<Glib::ustring>* p,iconview___* iv1){
		menu_=menu1_=NULL;
		status_=id_status_use_;

		iv1_=iv1;
		sh_=iv1->sh_;
		d_=iv1->d_;
		dong_=(*p)[1];
		zhao_=iv1->name__();
		iv_=iv;
		cr_=new columnrecord___();
		ls_=Gtk::ListStore::create(*(cr_));
		iv->set_model(ls_);
		iv->set_markup_column (cr_->title_);
		iv->set_pixbuf_column (cr_->icon_);
		//释放用关联？
		iv->set_data("ctl",this);

		/*iv->set_text_column (id->cr_->s_);
		iv->set_text_column (id->cr_->icon_path_);
		iv->set_text_column (id->cr_->s2_);*/

		iv->set_events(Gdk::BUTTON_PRESS_MASK);
		iv->signal_button_press_event().connect(sigc::mem_fun(*this,&iconview_data___::on_press__),false);
		iv->signal_item_activated().connect(sigc::mem_fun(*this,&iconview_data___::on_activated__));
		iv->signal_selection_changed().connect(sigc::mem_fun(*this,&iconview_data___::on_select__));
	}
	int option__(std::deque<Glib::ustring>* p,size_t& i){
		char c;
		if((*p)[i]=="命名")
			c='n';
		else if((*p)[i]=="代码")
			c='c';
		else if((*p)[i]=="菜单")
			c='m';
		else if((*p)[i]=="外菜单")
			c='M';
		else if((*p)[i]=="编辑状态"){
			status_=id_status_edit_;
			return 0;
		}
		else{
			return -1;
		}
		if(++i>=p->size()){
			d_(sh_,err_show_buzu_,p);
			return 1;
		}
		switch(c){
		case 'n':
			dong_=(*p)[i];
			break;
		case'c':
			code_=(*p)[i];
			break;
		case'm':
		case'M':
			Gtk::Menu* m;
			sh_->builder_->get_widget((*p)[i], m);
			if(!m){
				d_(sh_,err_show_wufa_,3,p,i,i-1);
				return 2;
			}
			switch(c){
			case'm':
				menu_=m;
				break;
			case'M':
				menu1_=m;
				break;
			}
			/*Gtk::Menu_Helpers::MenuList& ml=id->menu_->items();
			for(size_t i1=0; i1<ml.size(); i1++){
				if(dynamic_cast<Gtk::SeparatorMenuItem*>(&ml[i1]))
					continue;
				menu_item___* imi=new menu_item___
						(ml[i1].get_label(),id);
				ml[i1].signal_button_press_event().connect
						(sigc::mem_fun(*imi, &menu_item___::on__));
			}*/
			break;
		}
		return 0;
	}
	void clear__(){
		ls_->clear();
	}
	/*void on_menu__(const Glib::ustring& dong){
		on_path__(menu_path_,"菜单",dong.c_str());
	}*/
	bool on_press__(GdkEventButton* event){
		if( (event->type == GDK_BUTTON_PRESS) && (event->button == 3) ) {
			Gtk::CellRenderer* cell(0);
			iv_->get_item_at_pos(int(event->x),int(event->y),menu_path_,cell);
			if (menu_path_.get_depth()){
				Gtk::TreeModel::iterator iter = ls_->get_iter(menu_path_);
				if(iter){
					if(menu_){
						iv_->unselect_all();
						iv_->select_path(menu_path_);

						menu_->popup(event->button, event->time);
						return true;
					}
				}
			}else{
				if(menu1_){
					menu1_->popup(event->button, event->time);
					return true;
				}
			}
		}
		return false;
	}
	void on_select__(){
		sel_ = iv_->get_selected_items();
		if(!sel_.empty())
			on_path__(*sel_.begin());
	}
	void on_activated__(const Gtk::TreeModel::Path& path){
		on_path__(path,"活性");
	}
	void add__(std::deque<Glib::ustring>* p){
		Gtk::TreeModel::iterator iter;
		bool sel_hou=false;
		if(p->size()>7){
			//sel_hou=sh_->bool__((*p)[6]);
			sel_hou=d_(sh_,bool_,(*p)[6].c_str());
		}
		if(sel_hou){
			sel_ = iv_->get_selected_items();
			if(sel_.empty())
				iter = ls_->append();
			else
				iter = ls_->insert_after(ls_->get_iter(*--sel_.end()));
		}else
			iter = ls_->append();
		Gtk::TreeModel::Row r = *iter;
		set__(r,p,2,true);
		dir__(iter,r,r[cr_->title_],r[cr_->s_],true);
	}
	void del__(deque<Glib::ustring>* p,void*shangji){
		list<Gtk::TreeModel::Path> sel = iv_->get_selected_items();
		if(sel.size()<1){
			on__(NULL,"0","",(*p)[1].c_str());
			return;
		}
		if(p->size()>4)
			shangji=(void*)x2lu__((*p)[3]);
		for(list<Gtk::TreeModel::Path>::iterator li=sel.begin();li!=sel.end();li++){
			Gtk::TreeModel::iterator ti=ls_->get_iter(*li);
			if(p->size()>3){
				string ret=call4__(ti,(*p)[2],shangji);
				//if(!sh_->bool__(ret))
				if(!d_(sh_,bool_,ret.c_str()))
					continue;
			}
			ls_->erase(ti);
		}
	}
	void move__(const char*oper,Glib::ustring& fangxiang){
		sel_ = iv_->get_selected_items();
		if(sel_.size()<2){
			on__(NULL,"2","",oper);
			return;
		}
		Gtk::TreeModel::iterator ti1,ti2;
		list<Gtk::TreeModel::Path>::iterator li;
		int max=sel_.size()-1;
		for(int i=0;i<max;i++){
			ti1=ls_->get_iter(*sel_.begin());
			ti2=ls_->get_iter(*--sel_.end());
			if(fangxiang=="向前")
				ls_->move(ti1,ti2);
			else
				ls_->move(ti2,ti1);
			sel_ = iv_->get_selected_items();
		}
	}
	void for__(deque<Glib::ustring>* p,void*shangji){
		Glib::ustring& code=(*p)[2];
		if(p->size()>4)
			shangji=(void*)x2lu__((*p)[3]);
		Gtk::TreeNodeChildren nc=ls_->children();
		for(Gtk::TreeIter ti=nc.begin();ti!=nc.end();ti++)
			call4__(ti,code,shangji);
	}
	void select__(deque<Glib::ustring>* p){
		/*Gtk::TreeModel::Path path((*p)[2]);
		iv_->select_path(path);*/
		bool s2p=false,duo=false,is_s=false;
		if(p->size()>3){
			if((*p)[3].find("唯一")!=string::npos)
				iv_->unselect_all();
			if((*p)[3].find("滚至")!=string::npos)
				s2p=true;
			if((*p)[3].find("多选")!=string::npos)
				duo=true;
			if((*p)[3].find("是实")!=string::npos)
				is_s=true;
		}
		Gtk::TreeNodeChildren cr=ls_->children();
		for(Gtk::TreeIter ti=cr.begin();ti!=cr.end();ti++){
			Gtk::TreeModel::Row r=*ti;
			bool b;
			if(is_s)
				b=(*p)[2]==r[cr_->s_];
			else
				b=r[cr_->title_]==(*p)[2];
			if(b){
				Gtk::TreeModel::Path path(ti);
				iv_->select_path(path);
				if(s2p)
					iv_->scroll_to_path(path,false,gfloat(0.0),gfloat(0.0));
				if(!duo)
					return;
			}
		}
		on__(NULL,"0","",(*p)[1].c_str());
	}
	void get__(deque<Glib::ustring>* p,void*shangji,char*buf){
		const char*oper=(*p)[1].c_str();
		Glib::ustring& code=(*p)[2];
		if(p->size()>4)
			shangji=(void*)x2lu__((*p)[3]);
		sel_ = iv_->get_selected_items();
		if(sel_.size()<1){
			on__(NULL,"0","",oper);
			return;
		}
		for(std::list<Gtk::TreeModel::Path>::iterator pi=sel_.begin();pi!=sel_.end();pi++)
			call4__(ls_->get_iter(*pi),code,shangji,buf);
	}
	void update__(std::deque<Glib::ustring>* p){
		Gtk::TreeModel::Row r;
		list<Gtk::TreeModel::Path> sel;
		if(p->size()>7){
			Gtk::TreeIter* ti=(Gtk::TreeIter*)x2lu__((*p)[6]);
			if(!ti){
				//sh_->err_show_wufa__(p,1);
				d_(sh_,err_show_wufa_,2,p,1);
				return;
			}
			r = **ti;
		}else{
			sel = iv_->get_selected_items();
			if(sel.size()<1){
				on__(NULL,"0","",(*p)[1].c_str());
				return;
			}
			r=*ls_->get_iter(*--sel.end());
		}
		set__(r,p,2,false);
	}
#define id_dir_open_	"| "
#define id_dir_close_	"* "
#define id_type_chouti_	"抽屉"
	static void type__(const Glib::ustring& t,char* buf,long siz){
		if(t.find(id_dir_open_)==0||t.find(id_dir_close_)==0){
			cpy__(buf,id_type_chouti_,siz);
			return;
		}
	}
private:
	int dir__(Gtk::TreeModel::iterator& iter,Gtk::TreeModel::Row& r,
			const Glib::ustring& t,const Glib::ustring& s,bool is_add){
		bool is_o=t.find(id_dir_open_)==0;
		if(is_o||t.find(id_dir_close_)==0){
			if(status_==id_status_use_){
				Gtk::TreeNodeChildren nc=ls_->children();
				std::deque<Glib::ustring>* child;
				Glib::ustring t2=t;
				char*s1;
				if((is_add&&!is_o)||(!is_add&&is_o)){
					child=new deque<Glib::ustring>();
					if(iter!=nc.begin()){
						int i=s2i__(s);
						for(Gtk::TreeIter ti=--iter;;i--){
							if(i<=0)
								break;
							Gtk::TreeModel::Row r2 = *ti;
							child->push_back(r2[cr_->s_]);
							child->push_back(r2[cr_->title_]);
							child->push_back(r2[cr_->icon_path_]);
							child->push_back(r2[cr_->s2_]);
							bool b=ti==nc.begin();
							Gtk::TreeIter ti2=ti;
							if(!b)
								--ti;
							ls_->erase(ti2);
							if(b)
								break;
						}
					}
					r[cr_->child_]=child;
					s1=id_dir_close_;
				}else{
					if(!is_add){
						child=r[cr_->child_];
						for(int i=child->size();(i-=4)>=0;){
							Gtk::TreeModel::iterator tmi;
							tmi = ls_->insert(iter);
							Gtk::TreeModel::Row r2 = *tmi;
							set__(r2,child,i,true);
						}
						child->clear();
						delete child;
						r[cr_->child_]=NULL;
					}
					s1=id_dir_open_;
				}
				r[cr_->title_]=t2.replace(0,2,s1);
				return 1;
			}
			if(status_==id_status_edit_){
				return 2;
			}
		}
		return 0;
	}

	void set__(Gtk::TreeModel::Row& r,std::deque<Glib::ustring>* p,int from,bool is_add){
		Glib::ustring& p1=(*p)[from];
		Glib::ustring& p2=(*p)[from+1];
		Glib::ustring& p3=(*p)[from+2];
		Glib::ustring& p4=(*p)[from+3];
		r[cr_->s_] = p1;
		r[cr_->title_] = p2;
		icon__(r,p3);
		r[cr_->icon_path_]=p3;
		r[cr_->s2_] = p4;
		if(is_add)
			r[cr_->child_]=NULL;
	}

	Gtk::TreeModel::Path menu_path_;
	std::list<Gtk::TreeModel::Path> sel_;
	void on_path__(const Gtk::TreeModel::Path& path,const char*arg3=NULL,const char*arg4=NULL){
		Gtk::TreeModel::iterator iter = ls_->get_iter(path);
		Gtk::TreeModel::Row r = *iter;
		Glib::ustring t=r[cr_->title_];
		Glib::ustring s=r[cr_->s_];
		switch(dir__(iter,r,t,s,false)){
		case 2:
			arg4=id_type_chouti_;
			break;
		case 1:
			return;
		}
		Glib::ustring s2=r[cr_->s2_];
		on__(NULL,s.c_str(),s2.c_str(),NULL,arg3,arg4);
	}
	void on__(void*shangji,const char*s,const char*s2,const char*oper=NULL,const char*arg3=NULL,const char*arg4=NULL){
		if(arg4){
			d_(sh_,on_,code_.c_str(),shangji,6,zhao_,dong_.c_str(),s,s2,arg3,arg4);
			return;
		}
		if(arg3){
			//sh_->on__(code_.c_str(),shangji,5,zhao,dong_.c_str(),s,s2,oper2);
			d_(sh_,on_,code_.c_str(),shangji,5,zhao_,dong_.c_str(),s,s2,arg3);
			return;
		}
		if(oper){
			//sh_->on__(NULL,shangji,5,"提示",oper,zhao,dong_.c_str(),s,s2);
			d_(sh_,on_,NULL,shangji,6,"提示",oper,zhao_,dong_.c_str(),s,s2);
			return;
		}
		//sh_->on__(code_.c_str(),shangji,4,zhao,dong_.c_str(),s,s2);
		d_(sh_,on_,code_.c_str(),shangji,4,zhao_,dong_.c_str(),s,s2);
	}
	string call4__(Gtk::TreeModel::iterator ti,Glib::ustring& code,void*shangji,char*buf1=NULL){
		Gtk::TreeModel::Row r=*ti;
		Glib::ustring s=r[cr_->s_];
		Glib::ustring t=r[cr_->title_];
		Glib::ustring ip=r[cr_->icon_path_];
		Glib::ustring s2=r[cr_->s2_];
		char buf0[32];
		char*buf=(buf1?buf1:buf0);
		l2x__((long)&ti,buf);

		const char*argv[5]={s.c_str(),t.c_str(),ip.c_str(),s2.c_str(),buf};
		return d_(sh_,call4_,code.c_str(),shangji,NULL,NULL,NULL,5,argv,0);
	}
	void icon__(Gtk::TreeModel::Row& r,Glib::ustring& p3){
		if(p3.size()<1)
			return;
		r[cr_->icon_] = iv1_->pix__(p3);
	}
};

/*class menu_item___{
public:
	menu_item___(const Glib::ustring& dong,iconview_data___* id){
		dong_=dong;
		id_=id;
	}
	bool on__(GdkEventButton* eb){
		id_->on_menu__(dong_);
		return true;
	}
private:
	Glib::ustring dong_;
	iconview_data___* id_;
};*/

iconview_data___* get_id__(std::deque<Glib::ustring>* p,size_t i,iconview___*iv,bool err_show=true){
	if(p->size()>i){
		iconview_data___* id=(iconview_data___*)s2l__((*p)[i],0);
		if(!id&&err_show){
			//sh->err_show__((*p)[0].c_str(),(*p)[1].c_str(),(*p)[i].c_str());
			iv->d_(iv->sh_,err_show_,3,(*p)[0].c_str(),(*p)[1].c_str(),(*p)[i].c_str());
		}
		return id;
	}
	if(err_show){
		//sh->err_show_buzu__(p);
		iv->d_(iv->sh_,err_show_buzu_,p);
	}
	return NULL;
}
iconview_data___* get_id__(std::deque<Glib::ustring>* p,iconview___*sh,size_t i,size_t i2,size_t i3=0){
	iconview_data___* id=get_id__(p,i,sh,false);
	if(!id){
		if(i3){
			id=get_id__(p,i2,sh,false);
			if(!id)
				id=get_id__(p,i3,sh);
		}else
			id=get_id__(p,i2,sh);
	}
	return id;
}

int iconview___::proc__(std::deque<Glib::ustring>* p,char*buf,long siz,char**addr_ret,void*shangji) {
	if((*p)[0]==name__()){
		if(siz==-1)return 1;
		if((*p)[1]=="增加"){
			iconview_data___* id=get_id__(p,this,7,6);
			if(!id)
				return 1;
			id->add__(p);
			return 1;
		}
		if((*p)[1]=="更新"){
			iconview_data___* id=get_id__(p,this,7,6);
			if(!id)
				return 1;
			id->update__(p);
			return 1;
		}
		if((*p)[1]=="移除"){
			iconview_data___* id=get_id__(p,this,4,3,2);
			if(!id)
				return 1;
			id->del__(p,shangji);
			return 1;
		}
		if((*p)[1]=="移动"){
			iconview_data___* id=get_id__(p,3,this);
			if(!id)
				return 1;
			id->move__((*p)[1].c_str(),(*p)[2]);
			return 1;
		}
		if((*p)[1]=="选择"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->select__(p);
			return 1;
		}
		if((*p)[1]=="遍历"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->for__(p,shangji);
			return 1;
		}
		if((*p)[1]=="获取"){
			iconview_data___* id=get_id__(p,this,4,3);
			if(!id)
				return 1;
			id->get__(p,shangji,buf);
			return 1;
		}
		if((*p)[1]=="清空"){
			iconview_data___* id=get_id__(p,2,this);
			if(!id)
				return 1;
			id->clear__();
			return 1;
		}
		if((*p)[1]=="类型"){
			if(p->size()<=2){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			iconview_data___::type__((*p)[2],buf,siz);
			return 1;
		}
		Gtk::IconView* iv;
		sh_->builder_->get_widget((*p)[1], iv);
		if(!iv){
			d_(sh_,err_show_fei_,p);
			return 1;
		}
		iconview_data___* id=new iconview_data___(iv,p,this);
		for(size_t i=2;i<p->size();i++){
			switch(id->option__(p,i)){
			case 0:
				continue;
			case -1:
				break;
			default:
				return 1;
			}
			char c;
			if((*p)[i]=="图片缓存")
				c='i';
			else{
				d_(sh_,err_show_buzhichi_,2,p,i);
				return 1;
			}
			if(++i>=p->size()){
				d_(sh_,err_show_buzu_,p);
				return 1;
			}
			switch(c){
			case'i':
				get_imagecache__((*p)[i].c_str(),ic_,ic_arg1_);
				continue;
			}
		}
		l2s__((long)id,buf);
		return 1;
	}
	if((*p)[0]=="读图片限制"){
		switch(p->size()){
			case 4:
				pix_limit_aspect_=s2i__((*p)[3],pix_limit_aspect_);
			case 3:
				pix_limit_height_=s2i__((*p)[2],pix_limit_height_);
			case 2:
				pix_limit_width_=s2i__((*p)[1],pix_limit_width_);
				break;
		}
		return 2;
	}
	return 0;
}

extern "C" plugin_base___* create__(shell___* sh,direct___ d){return new iconview___(sh,d);}
extern "C" void destroy__(plugin_base___* p){delete p;}
