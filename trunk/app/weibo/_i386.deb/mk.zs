#!../../../new_o/gtkmmsh lib2/window1.glade ---。
加载lib/defi。
加载lib/doscmd4。

如果存在参数1那么先
	别名文件以参数1。
	隧道标题、‘文件’。
	隧道窗口宽高、300、300。
	隧道内容、text、先调用‘type’、‘文件’了。
	隧道文本框、已修改、text、0。
	隧道可见、exec、0。
	隧道可见、save、1。
	隧道侦听、点击、save、【代码】“调用‘echo’、先隧道内容、text了、隧道标题”。
	隧道代码为【代码】“如果‘参数0’等于销毁并且隧道文本框、已修改、text那么隧道点击、save”。
	退出。
了。
隧道可见、exec2、exec3、1。
隧道提示文字、exec2、setting.zs。
隧道提示文字、exec3、ver.zs。
隧道侦听、点击、exec2、exec3、下代码
	执行“‘参数0【主】’ ‘参数’&”。
上代码。

加载lib/file4。
加载lib/regexpr4。
加载lib/gjk4。
加载lib/stdc。

赋予目录【主】以解释下代码
	赋予目录以调用‘得目录名’、‘参数1’。
	显示‘目录’→。
	如果‘目录’等于./那么先
		赋予目录以先调用‘得当前目录函数’了/。
		显示‘目录’→。
	了。
	显示↙。
	‘目录’
上代码、‘参数0’。
如果迭代正则‘目录’、.*/([^/]+)/(_)(-)([^_]+)_([^\.]+)(\.[^/]+)/、下代码
	显示‘参数’↙。
	赋予应用名【主】以‘参数1’。
	赋予_【主】以‘参数2’。
	赋予-【主】以‘参数3’。
	赋予副版本【主】以‘参数4’。
	赋予平台【主】以‘参数5’。
	赋予后缀【主】以‘参数6’。
上代码否则
迭代正则‘目录’、.*/([^/]+)/(_)([^\.]+)(\.[^/]+)/、下代码
	显示‘参数’↙。
	赋予应用名【主】以‘参数1’。
	赋予_【主】以‘参数2’。
	赋予平台【主】以‘参数3’。
	赋予后缀【主】以‘参数4’。
上代码。
赋予根目录【主】以‘目录’root。
赋予control【主】以DEBIAN/control。
（/usr/lib/zhscript）
赋予{zs}【主】以调用‘移除..’、‘目录’../../../new_o。
赋予临时目录【主】以/tmp/‘后缀’‘_’‘应用名’‘_’‘平台’。
赋予步骤【主】以.。

隧道标题、制作‘应用名’的deb包。
隧道窗口宽高、800、400。
隧道窗口居中。

隧道内容、text、先调用‘type’、‘根目录’/‘control’了。
隧道文本框、已修改、text、0。

隧道侦听、点击、exec、下代码
	加载setting.zs。
	加载ver.zs。
	赋予包名【主】以先如果存在前缀那么‘前缀’了‘应用名’‘_’‘版本号’先如果存在副版本那么‘-’‘副版本’了‘_’‘平台’‘后缀’。
	显示‘临时目录’/‘包名’↙。

	定义并日志以下代码
		隧道插入、text、↙‘参数1’。
		‘参数1’。
		隧道不堵塞。
	上代码。
	
	赋予步骤【主】以‘步骤’.。
	如果‘步骤’等于..那么先
		如果隧道文本框、已修改、text那么先
			调用‘echo’、先隧道内容、text了、‘根目录’/‘control’。
			隧道内容、text、修改已写入。
		了否则
			隧道内容、text、未修改。
	了否则
		隧道内容、text、。
	隧道不堵塞。

	定义“加管执行”以下代码
		赋予果以执行“gksudo "‘参数1’"”。显示‘果’↙。
		如果‘果’等于0那么1否则0。
	上代码。

	如果不加管执行“rm -rf '‘临时目录’'”那么并日志放弃，退出。
	
	执行并日志“cp -r -p '‘根目录’' ‘临时目录’”。
		
	定义复制文件以下代码
		别名源以参数1。
		别名标以参数2。
		赋予标目录以调用‘得目录名’、‘标’。
		如果‘标目录’那么先
			如果调用‘existdir’、‘标目录’否则
				执行显示“mkdir -p '‘标目录’'”↙。
		了。
		执行并日志“cp -p '‘源’' '‘标’'”。
	上代码。
	
	赋予安装目录以‘临时目录’/‘安装目录’。
	执行显示“mkdir -p '‘安装目录’'”↙。
	
	赋予上目录以调用‘移除..’、如果存在源目录那么‘源目录’否则‘目录’..。
	解释‘dir’、下代码
		别名标以参数1。
		如果调用‘头匹配方法’、‘标’、_那么显示忽略‘标’↙，再来。
		赋予源以‘上目录’/‘参数1’。
		赋予标以‘安装目录’/‘标’。
		复制文件‘源’、‘标’。
	上代码、‘上目录’、、s。

	调用‘改变目录函数’、‘安装目录’。
	并日志改变目录到‘安装目录’。

	迭代数组下代码
		别名源以参数1。
		别名标以参数2。
		如果不‘标’那么赋予标以‘源’。
		赋予标以调用‘串替换方法’、‘标’、{zs}、.。
		赋予源以调用‘串替换方法’、‘源’、{zs}、‘{zs}’。
		复制文件‘源’、‘标’。
	上代码、宾文件。

	调用‘改变目录函数’、‘临时目录’。
	并日志改变目录到‘临时目录’。
	
	调用‘echo’、“
Package: ‘应用名’字符10
Source: ‘应用名’字符10
Version: ‘版本号’字符10
Architecture: ‘平台’字符10
		”先调用‘type’、‘control’了、‘control’。
	
	执行并日志“find \( -type d -name .svn -o -name '*.d' -o -name .project -o -name .settings \) -printf "rm -rf '%p'\n" | sh”。
	执行并日志“find -type d -printf "chmod 755 '%p'\n" | sh”。（DEBIAN必须）
	执行并日志“find -type f -printf "chmod 644 '%p'\n" | sh”。
	执行并日志“chmod 755 
		'./‘安装目录【主】’/ui' 
		'./‘安装目录【主】’/‘应用名’' 
		'./‘安装目录【主】’'/*.sh 
		usr/share/applications/*.desktop”。
	如果存在另外那么执行并日志‘另外’。
	
	如果不加管执行“chown -R root:root '‘临时目录’'”（staff）那么并日志放弃，退出。
	
	执行并日志“dpkg -b . ~/桌面/‘包名’”。
	
	并日志完。
	加管执行“rm -rf '‘临时目录’'”。
上代码。
