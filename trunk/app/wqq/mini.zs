
定义【主】隐藏左边栏以下代码
	别名藏以参数1。
	赋予栏宽以隧道宽、vbox1。
	如果‘藏’那么先
		隧道可见、vbox1、0。
		隧道窗口宽高、+-‘栏宽’、。
		（隧道移动、+‘栏宽’、。）
	了否则先
		（隧道移动、+-‘栏宽’、。）
		隧道窗口宽高、+‘栏宽’、。
		隧道可见、vbox1、1。
	了。
上代码。

隧道侦听、点击、mini、mini1、下代码
	赋予【主】左边栏隐藏以隧道勾选、‘动作’。
	如果‘左边栏隐藏’那么先
		赋予可见以0。
		赋予可见2以1。
	了否则先
		赋予可见以1。
		赋予可见2以0。
	了。
	隧道勾选、mini、‘左边栏隐藏’。
	隧道勾选、mini1、‘左边栏隐藏’。
	隧道可见、vbox1、‘可见’。
	隧道可见、vbox3、‘可见2’。
上代码。
