加载lib/gjk4。
隧道标题为菜单。
赋予高以算术(‘参数数目’-1)/3*42。
赋予限高以算术先隧道屏幕高了-50。
如果‘高’大于等于‘限高’那么赋予高以‘限高’。
隧道窗口宽高为600、‘高’。
赋予源以‘参数1’。
赋予【主】表格以隧道建立表格为1、100为scrolledwindow1。
（隧道查看模板为frame1。）
加载lib/clpars4。
调用‘命令行加回调’、
	、、3、下代码
		赋予模板以隧道复制模板为frame1。
		如果不‘模板’那么隧道终止，结束。
		隧道设置表格单元为1、‘参数1’为‘模板’为‘表格’。
		隧道设置模板单元为1为‘参数2’为‘模板’。
		隧道设置模板单元为5为‘参数3’为‘模板’。
		赋予命令以调用‘串替换方法’、‘参数4’、*、'‘源’'。
		隧道设置模板单元为4为‘命令’为‘模板’。
	上代码。
调用‘命令行解析带序号’、‘参数栈2’。