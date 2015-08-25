#!/bin/bash
cd "`dirname $0`"
dir="`pwd`/.."

f3="-D ver_64_ -Wall -fmessage-length=0 -MMD -MP"
f1="-O0 -g3 $f3"

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

gxx_lib_ test4
gcc_lib_ md4

