
定义【主】应该忽略以下代码
	当‘登录目标’先
		等于w.qq那么先
			别名内容以参数1。
			循环先
				如果调用‘正则攫’、‘内容’、>([^<"]+)<br>那么先
					如果调用‘正则攫’、‘之1’、(.+)\(([0-9]+)\)那么先
						别名名以之1。
						别名号以之2。
						跳出。
					了。
				了。
				如果调用‘正则攫’、‘内容’、uin=([0-9]+)".+class="messageBoxNick">([^<]+)</span>那么先
					别名名以之2。
					别名号以之1。
					跳出。
				了。
				退出。
			了。
			赋予果以迭代数组下代码
				如果‘参数3’等于-那么再来。
				如果‘参数1’等于‘名’并且‘参数2’等于‘号’那么1，跳出。
			上代码、群静默。
			如果不‘果’那么
				赋予果以迭代数组下代码
					如果‘参数3’等于-那么再来。
					如果‘参数1’等于‘名’并且
						调用‘子串方法’、‘参数2’、-6等于调用‘子串方法’、‘号’、-6那么1，跳出。
				上代码、群静默。
			‘果’。
			跳出。
		了。
		等于web.qq那么先
			别名名以参数1。
			赋予果以迭代数组下代码
				如果‘参数3’等于-那么再来。
				如果‘参数1’等于‘名’那么显示群静默--‘参数’↙，1，跳出。
			上代码、群静默。
			‘果’。
			跳出。
		了。
	了。
上代码。

隧道侦听、点击、quno、quno1、下代码
	当‘登录目标’先
		等于w.qq那么先
			赋予内容以隧道webkit3、元素、chatWinHeader、内容、浏览器#0。
			如果不‘内容’那么退出。
			如果调用‘正则攫’、‘内容’、>([^<"]+)<br>小于1那么退出。
			调用‘正则攫’、‘之1’、(.+)\(([0-9]+)\)。
			赋予号以搜索数组群静默、‘之1’、‘之2’。
			如果‘号’小于1那么先
				增至数组【顶】群静默、3、‘之1’、‘之2’、。
				赋予号以‘群静默数目’。
			了。
			跳出。
		了。
		等于web.qq那么先
			赋予1以隧道webkit3、元素、“window window_current”、1、1、1、2、1、2、2、1、1、得、浏览器#0。
			如果不‘1’那么退出。
			赋予2以隧道webkit3、元素、‘1’、属性、class、浏览器#0。
			显示‘2’↙。
			如果‘2’不等于chatBox_mainName那么退出。
			赋予之1以隧道webkit3、元素、‘1’、内容、浏览器#0。
			显示‘之1’↙。
			如果不‘之1’那么退出。
			赋予号以搜索数组群静默、‘之1’。
			如果‘号’小于1那么先
				增至数组【顶】群静默、3、‘之1’、、。
				赋予号以‘群静默数目’。
			了。
			跳出。
		了。
	了。
	序迭代数组下代码
		显示‘参数’↙。
	上代码、群静默。
	加载lib2/msgbox。
	当隧道提示、“对“‘之1’”使用吗”、‘参数1’、‘询问’、‘是否按钮’先
		等于‘是’那么
			赋予【顶】群静默之‘号’之3以，跳出。
		等于‘否’那么
			赋予【顶】群静默之‘号’之3以-，跳出。
		那么退出。
	了。
	保存配置文件。
上代码。