#!/bin/bash
echo "可能需要输入 apt-get install 时所须密码"
sudo apt-get install g++ pkg-config \
libcurl4-gnutls-dev \
libsqlite3-dev \
libgtkmm-2.4-dev \
libglademm-2.4-dev \
libgtksourceviewmm-2.0-dev \
libwebkit-dev \
libwnck-dev \
libunique-dev

cd "`dirname $0`"
dir="`pwd`/.."

f3="-D ver_64_ -Wall -fmessage-length=0 -MMD -MP"
f2="-O0 -g3 $f3"
#f1=$f2
f1="-O3 $f3"

s2="-fPIC"
s1="-shared $s2"
i1="-I ../new_gg -I ../../new_gg"

gxx_(){
	z="g++ $@"
	echo
	echo $z
	$z
}
gcc_(){
	z="gcc $@"
	echo
	echo $z
	$z
}
gxx_lib_(){
	cd "$dir/$1"
	gxx_ -o ../new_o/lib/$1.so $s1 $f1 $i1 $2 *.cpp
}
gcc_lib_(){
	cd "$dir/$1"
	gcc_ -o ../new_o/lib/$1.so $s1 $f1 $i1 $2 *.c
}
gxx_gtkmm_(){
	gxx_ $@ `pkg-config gtkmm-2.4 libglademm-2.4 --cflags --libs`
}
gxx_gtkmmsh_plugin_(){
	cd "$dir/gtkmmsh-plugin/$1"
	gxx_gtkmm_ -o ../../new_o/gtkmmsh-plugin/$1$3.so $s1 $f1 $i1 -I ../../gtkmmsh $2 *.cpp
}
gxx_l4_(){
	cd "$dir/new_l4/l432_so"
	gxx_ $1 $f1 $s2 -c `echo *.cpp|sed 's/call_func\.cpp//g'`
	gxx_ $1 $f2 $s2 -c call_func.cpp
	gxx_ -o ../../new_o/l4$2.so $s1 $f1 *.o
}

gxx_l4_
gxx_l4_ "-D debug_liucheng_" -d

gxx_lib_ test4
gcc_lib_ gjk4
gxx_lib_ file4 "-D f0zai4_lstat"
gxx_lib_ doscmd4
gxx_lib_ regexpr4
gxx_lib_ gjke4
gxx_lib_ redireconsoi4
gxx_lib_ base64
gxx_lib_ socket4
gxx_lib_ vartable4
gxx_lib_ xml4 "-I /usr/include/libxml2/ -lxml2"
gxx_lib_ txtotxt4
gxx_lib_ curle4 "-lcurl"
gxx_lib_ inotify4
gxx_lib_ sqlite4 "-lsqlite3"
gcc_lib_ md4
gxx_lib_ thread4 -lpthread
gxx_lib_ clpars4
gxx_lib_ wnck4 "-DWNCK_I_KNOW_THIS_IS_UNSTABLE `pkg-config libwnck-1.0 --cflags --libs`"
gxx_lib_ unique4 "`pkg-config --cflags --libs gtk+-2.0 unique-1.0`"
gxx_lib_ mongoose4 "-DINT64_MAX=9223372036854775807 mongoose.c"

cd "$dir/new_l/l32"
gxx_ -o ../../new_o/l $f1 $i1 l.cpp -ldl

cd "$dir/gtkmmsh"
gxx_gtkmm_ -o ../new_o/gtkmmsh $f1 $i1 *.cc *.cpp


gxx_gtkmmsh_plugin_ statusicon
gxx_gtkmmsh_plugin_ iconview
gxx_gtkmmsh_plugin_ tmpl
gxx_gtkmmsh_plugin_ huitu
gxx_gtkmmsh_plugin_ dlg
gxx_gtkmmsh_plugin_ menu
gxx_gtkmmsh_plugin_ nostdw
gxx_gtkmmsh_plugin_ timeout
gxx_gtkmmsh_plugin_ buju
gxx_gtkmmsh_plugin_ common
gxx_gtkmmsh_plugin_ feiqi
gxx_gtkmmsh_plugin_ imagecache
gxx_gtkmmsh_plugin_ treeview
gxx_gtkmmsh_plugin_ textview
gxx_gtkmmsh_plugin_ sourceview "`pkg-config gtksourceviewmm-2.0 --cflags --libs`"
gxx_gtkmmsh_plugin_ webkit "`pkg-config webkit-1.0 --cflags --libs`"
gxx_gtkmmsh_plugin_ dnd

wk=/opt2/src/WebKit-r75891
if [ -d $wk ]
then
	gxx_gtkmmsh_plugin_ webkit "-D ver_3_ -I $wk/WebKit/gtk/ -I $wk/Source/WebCore/platform/network/soup/cache/ -I $wk/DerivedSources/ -Wl,-rpath=./,-rpath=./lib3/,-rpath=/usr/lib/zhscript/lib3/ -L$wk/.libs/ -lwebkitgtk-1.0 `pkg-config webkit-1.0 --cflags --libs`" 3
fi

cd "$dir/new_o/gtkmmsh-plugin"
rm *.d
