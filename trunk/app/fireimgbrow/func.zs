加载lib/gjk4。
加载lib/defi。
加载lib/file4。
赋予.以解释‘目录名’。

赋予【顶】火狐目录以隧道目录、ProfD。
赋予【顶】定制脚本以‘火狐目录’/fireimgbrow.zs。
加载lib/doscmd4。
如果调用‘exist’、‘定制脚本’否则删除【顶】定制脚本。

定义【顶】销毁以“赋予命令以“rm '‘参数1’'”。显示‘命令’↙。执行‘命令’。”。
定义【顶】编辑以“赋予/tmp以隧道目录、TmpD。加载menu.zs、‘参数1’。”。

加载lib/filetype。

定义【顶】搜索以“
赋予几以0 。
循环先
	赋予几以算术‘几’+1。
	如果不存在参数‘几’那么跳出。
	赋予目录以‘参数‘几’’。
	显示‘目录’。
	如果调用‘existdir’、‘目录’否则显示不能访问↙，再来。
	显示↙。
	赋予搜以调用‘dir.begin’、‘目录’、、sal。
	调用‘dir.sort’、‘搜’、0。
	循环先
		赋予文件以调用‘dir.next’、‘搜’。
		如果‘文件’否则跳出。
		赋予文件以‘目录’/‘文件’。
		如果调用‘头匹配方法’、文件类型‘文件’、p/那么隧道“a_.push('‘文件’')”。
	了。
	调用‘dir.end’、‘搜’。
了。
”。

定义【顶】扫描以“
隧道“a_=new Array();”。
如果存在定制脚本那么加载‘定制脚本’否则
	搜索先隧道目录、XDGPict了，
	搜索先隧道目录、Desk了，
	搜索‘火狐目录’/Cache。
隧道rand__()。
”。

扫描。
隧道pic_mask_show__()。