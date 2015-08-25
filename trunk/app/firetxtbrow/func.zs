加载lib/defi。

定义【顶】读取文件以下代码
	赋予文件以‘参数1’。
	如果‘参数2’那么先
		如果不存在转换临时文件那么先
			赋予1以隧道目录、Home。
			加载lib/file4。
			赋予1以调用‘得文件主名’、‘1’。
			赋予【顶】转换临时文件以/tmp/tmp-ftb-‘1’.html。
		了。
		赋予文件以‘转换临时文件’。
		赋予0以执行显示“iconv -f gb18030 -t utf8 -o ‘文件’ '‘参数1’'”↙。
		显示‘0’↙。
	了。
	加载lib/txtotxt4。
	调用‘html2text’、‘文件’、1、1。
上代码。
定义【顶】扫描目录以下代码
	赋予目录以‘参数1’。
	‘目录’<br/>。
	当‘参数2’先
		等于1那么赋予【顶】层以0，跳出。
		等于0那么赋予【顶】层以算术‘层’+1，跳出。
		等于2那么赋予【顶】层以算术‘层’-1，跳出。
	了。
	如果‘参数2’不等于1那么先
		“<a href="‘目录’" onclick="return redir__('‘目录’');">.</a><br/>”。
		如果存在层并且‘层’大于0那么先
			加载lib/file4。
			赋予..以调用‘移除..’、‘目录’../。
			赋予代码以dir__(2,'‘..’')。
		了否则先
			赋予..以javascript:void(0)。
			赋予代码以root__()。
		了。
		“<a href="‘..’" onclick="return ‘代码’;">..</a><br/>”。
	了。
	加载lib/doscmd4。
	加载lib/gjk4。
	如果调用‘existdir’、‘目录’等于0那么退出。
	加载lib/filetype。
	赋予搜以调用‘dir.begin’、‘目录’、、adah。
	调用‘dir.sort’、‘搜’、3。
	赋予span以“<span onclick="this.style.backgroundColor='#ccc';">”。
	循环先
		赋予文件以调用‘dir.next’、‘搜’。
		如果不‘文件’那么跳出。
		赋予路径以‘目录’‘文件’。
		如果调用‘头匹配方法’、文件类型‘路径’、p/那么
			‘span’“<a href="‘路径’" onclick="return show2__('‘路径’');">‘文件’</a>”</span>。
		否则先
			赋予是目录以调用‘尾匹配方法’、‘文件’、/。
			赋予路径2以如果‘是目录’那么调用‘子串方法’、‘路径’、0、-1否则‘路径’。
			“ <a href="‘路径2’" onclick="return del__('‘路径2’');">X</a>”
			如果不‘是目录’那么
				“ <a href="‘路径’" onclick="return edit__('‘路径’');">E</a>”
				“ ‘span’<a href="‘路径’" target=text>源</a>”（onclick="return show2__('‘路径’');"）
				“ <a href="‘路径’" onclick="return show__(1,'‘路径’');">gb</a>”
				。
			“ <a href="‘路径’" onclick="return ”先如果‘是目录’那么dir否则show了“__(0,'‘路径’');">‘文件’</a>”。
			如果不‘是目录’那么
				</span>。
		了。
		<br/>。
	了。
	调用‘dir.end’、‘搜’。
上代码。

定义【顶】得根目录以下代码
	赋予定制脚本以先隧道目录、Home了/firetxtbrow.zs。
	显示‘定制脚本’字符10。
	['先隧道目录、XDGDocs了/',。
	加载lib/doscmd4。
	如果调用‘exist’、‘定制脚本’那么加载‘定制脚本’。
	]。
上代码。
