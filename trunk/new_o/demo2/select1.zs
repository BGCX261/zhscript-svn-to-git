#!../gtkmmsh lib2/select1.glade --。
（#!/usr/lib/zhscript/gtkmmsh lib2/select1.glade --。）

赋予【顶】目录以如果存在参数1那么‘参数1’否则/usr/share/icons/gnome/48x48。

隧道定时器、启动、100、【代码】“
	隧道定时器、启动、移除。
	
	隧道标题为请等候，获取‘目录’里的图标……。
	
	加载lib/doscmd4。
	赋予搜以调用‘dir.begin’、‘目录’、、s。
	调用‘dir.sort’、‘搜’、0。
	赋予号以1。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果不‘名’那么跳出。
		加载lib/gjk4。
		如果调用‘尾匹配方法’、‘名’、.png等于0那么再来。
		如果‘名’等于animations/gnome-spinner.png或者等于animations/process-working.png那么再来。
		赋予路径以‘目录’/‘名’。
		赋予【顶】项目之‘号’之1以‘号’。
		赋予【顶】项目之‘号’之2以‘路径’。
		赋予【顶】项目之‘号’之3以‘名’。
		赋予号以算术‘号’+1。
	了。
	调用‘dir.end’、‘搜’。

	隧道内容为源码为【代码】“隧道标题为‘参数’。”。
	刷新图标夹。
	隧道标题为。
”。