#!/bin/sh
cd `dirname $0`
s=$PWD
t=/tmp/deb-zhscript
z=usr/lib/zhscript

nano root/DEBIAN/control
echo "可能需要输入 rm -rf $t 时所须密码"
sudo rm -rf $t
cp -r -p root $t
cd $t
mkdir -p usr/bin
ln -sf /$z/l usr/bin/zhscript
mkdir -p usr/local/lib
ln -sf /$z usr/local/lib/zhscript
mkdir -p $z
mkdir -p $z/lib3
cd $z/lib3
w=/opt2/src/WebKit-r75891/.libs
cp $w/libwebkitgtk-1.0.so.0.* libwebkitgtk-1.0.so.0 
cp $w/libjavascriptcoregtk-1.0.so.0.* libjavascriptcoregtk-1.0.so.0 
cd $t
cp -r -p $s/../../new_o/* $z
find \( -type d -name .svn -o -name '*.d' -o -name 'mk*.sh' -o -name 'tb*.sh' -o -name '*.exe' -o -name '*.dll' -o -name .project -o -name .settings \) -printf 'rm -rf %p\n' | sh

#DEBIAN
find -type d -printf "chmod 755 '%p'\n" | sh
find -type f -printf "chmod 644 '%p'\n" | sh
cd $z
chmod 755 l gtkmmsh
find demo* -name '*.zs' -printf "chmod 755 '%p'\n" | sh
cd $t
#staff
sudo chown -R root:root .

dpkg -b . ~/桌面/zhscript_1.0_amd64.deb

