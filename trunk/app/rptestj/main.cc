/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) zzzzzzzzzzz 2010 <zzzzzzzzzzzgg@gmail.com>
 *
 * rptestj is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rptestj is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtkmm.h>
#include <iostream>


#ifdef ENABLE_NLS
#  include <libintl.h>
#endif


/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/rptestj/ui/rptestj.ui" */
#define UI_FILE "src/rptestj.ui"

void init__(Glib::RefPtr<Gtk::Builder> builder,char* a0);

int
main (int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	//Load the Glade file and instiate its widgets:
	Glib::RefPtr<Gtk::Builder> builder;
	try
	{
		builder = Gtk::Builder::create_from_file(UI_FILE);
	}
	catch (const Glib::FileError & ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	Gtk::Window* main_win = 0;
	builder->get_widget("main_window", main_win);
	if (main_win)
	{
		init__(builder,argv[0]);
		kit.run(*main_win);
	}
	return 0;
}

Gtk::Entry* name_;
Gtk::Label* jieguo_;
Gtk::Button* jisuan_;
Gtk::TextView* luoji_;

//#include"l4/l4___.h"
#include "l4/l4___.cc"
#include "l4/err___.cc"
l4___ l4_;
int l4_err_=0;

#include <stdio.h>
void on_jisuan_clicked__(){
	Glib::ustring jieguo;
	Glib::ustring name=name_->get_text();
	name_->set_text("");

	int num=0;
	for(int i=0;i<name.length();i++)
		num+=name[i];
	num%=100;
	char num2[8];
	sprintf(num2,"%d",num);

	if(!l4_err_){
		Glib::ustring luoji=luoji_->get_buffer()->get_text();
		int err;
		const char* ret=l4_.l4_callback__(l4_.l4__(),&err,luoji.c_str(),false,2,num2,name.c_str());
		if(ret)
			jieguo+=ret;
		else{
			jieguo+=l4_.err__();
			jieguo+=l4_.errinfo__(err);
		}
	}else{
		jieguo+=l4_.err_;
		jieguo+=l4_.err__();
		jieguo+=l4_.errinfo__(l4_err_);
	}
	jieguo_->set_markup(jieguo);
	name_->grab_focus();
}

void init__(Glib::RefPtr<Gtk::Builder> builder,char* a0){
	builder->get_widget("jieguo", jieguo_);
	builder->get_widget("name", name_);
	builder->get_widget("jisuan", jisuan_);
	builder->get_widget("luoji", luoji_);

	jisuan_->signal_clicked().connect(sigc::ptr_fun(on_jisuan_clicked__));

	FILE *f;
	f = fopen("src/luoji.zs", "r");
	char buf[512];
	Glib::ustring s;
	if(f){
		for(;;){
			size_t len=fread(buf, 1, sizeof(buf)-1, f);
			if(len==0)
				break;
			buf[len]=0;
			s+=buf;
		}
		fclose(f);
	}
	luoji_->get_buffer()->set_text(s);

	if((l4_err_=l4_.init__(a0,"-S syn-zh -E err-zh")))
		std::cerr <<l4_.err_<<l4_.err__()<<l4_.errinfo__(l4_err_) << std::endl;

	name_->grab_focus();
}
