如果不存在登录目标那么
	赋予【主】登录目标以w.qq。
如果不存在最小化到托盘那么
	赋予【主】最小化到托盘以1。

定义【主】开始登录以下代码
	别名数据以参数1。
	如果调用‘正则攫’、‘数据’、(\?|&)?([^=]+)=([^&]*)那么先
		赋予【主】隐身以0。
		赋予【主】窗口最小化以0。
		赋予【主】最小化到托盘以0。
		迭代数组下代码
			当‘参数2’先
				等于u那么赋予【顶】qq帐号以‘参数3’，跳出。
				等于p那么赋予【顶】qq密码以调用‘urldecode’、‘参数3’，跳出。
				等于yin那么先
					赋予【主】隐身以1。
					赋予【主】在线图标以‘应用目录’/yinshen.png。
					跳出。
				了。
				等于xiao那么赋予【主】窗口最小化以1，跳出。
				等于tuo那么赋予【主】最小化到托盘以1，跳出。
				等于tag那么先
					赋予【主】登录目标以‘参数3’。
					赋予【上】目标以
						http://ui.ptlogin2.qq.com/cgi-bin/login?
						style=4&
						appid=1002101&
						no_verifyimg=1&
						先当‘登录目标’先
							等于w.qq那么
								s_url=http%3A%2F%2Fw.qq.com%2Fmain.shtml%3F816&
								f_url=loginerroralert，
								跳出。
							等于web.qq那么
								s_url=http://web.qq.com&
								enable_qlogin=0，
								隧道窗口最大化，
								跳出。
						了了。
					跳出。
				了。
			了。
		上代码、。
		如果‘最小化到托盘’那么
			隧道最小化到托盘、驻留、图标为‘离线图标’。
		否则
			隧道托盘应用、图标为‘离线图标’。

		赋予号以搜索数组qq帐号、‘qq帐号’。
		如果‘号’小于1那么
			增至数组【顶】qq帐号、2、‘qq帐号’、加密密码‘qq密码’。
		否则先
			赋予【顶】qq帐号之‘号’之2以加密密码‘qq密码’。
			赋予【主】登入设置之‘号’之1以‘登录目标’。
			赋予【主】登入设置之‘号’之2以‘隐身’。
			赋予【主】登入设置之‘号’之3以‘窗口最小化’。
			赋予【主】登入设置之‘号’之4以‘最小化到托盘’。
		了。

		保存配置文件。
		
		加载lib/unique4。
		赋予应用【主】以调用‘unique_app_new’、zhscript.webqq.no‘qq帐号’、NULL。
		显示应用‘应用’↙。
		如果调用‘unique_app_is_running’、‘应用’那么先
			如果tencent:处理
			否则
				调用‘发消息【unique4】’、、‘UNIQUE_ACTIVATE’、‘应用’。
			隧道终止。1。退出。
		了否则先
			调用‘unique_app_watch_window’、‘应用’、隧道窗。
			调用‘加回调【unique4】’、下代码
				当‘参数2’先
					等于‘UNIQUE_OPEN’那么先
						解释‘参数1’。
						跳出。
					了。
					那么先
						隧道窗口恢复。
						跳出。
					了。
				了。
			上代码、‘应用’。
			tencent:处理2。
		了。

		隧道webkit、访问、‘目标’、浏览器#0。
		隧道托盘提示、“‘qq帐号’ - ‘应用名’”。
		1。退出。
	了。
上代码。

隧道代码、下代码
	如果‘肇事者’等于窗口并且‘动作’等于销毁那么先
		如果存在应用【主】那么
			调用‘断开【unique4】’、‘应用【主】’。
		退出。
	了。
上代码。

定义【主】进行登录以下代码
	如果隧道内容、notebook1不等于1那么退出。
	别名网址以参数1。
	
	如果调用‘正则配’、‘网址’、^http://ui\.ptlogin2\.qq\.com/cgi-bin/login\?、l那么先
		如果‘窗口最小化’那么
			隧道窗口最小化。
		隧道标题、“马上自动登入 - ‘应用名’”。
		隧道webkit、插脚、‘js函数集’
			if(z$("g","隐身")==1)
				click__("webqq_type");
			__("u").focus();val__("u","‘qq帐号’");
			__("p").focus();val__("p","‘qq密码’");
			、浏览器#1。

		隧道一次定时器、延后登入、2s、下代码
			隧道webkit、插脚、‘js函数集’click__("login_button");、浏览器#0。

			隧道定时器、是否在线检查、30s、下代码
				如果‘登录目标’等于w.qq那么
				如果不‘在线’那么
					隧道窗口恢复。
					
				隧道webkit、插脚、“‘js函数集’
					var e=__("tipArea");
					if(e&&e.style.display=="block"){
						z$("”下代码
							赋予提示以调用‘正则替’、‘参数1’、([→↙]+)、。
							如果‘提示’那么先
								如果不存在旧提示或者‘旧提示’不等于‘提示’那么先
									赋予【主】旧提示以‘提示’。
									进行通知‘提示’。
								了。
								如果调用‘正则配’、‘提示’、“与服务器失去联系”那么设置在线0。
							了。
						上代码",e.innerText);
					}
					e=__("webos_eqq_tipsBox");
					if(e&&e.style.display=="block"){
						z$("下代码
							别名提示以参数1。
							如果‘提示’那么先
								如果不存在旧提示或者‘旧提示’不等于‘提示’那么先
									赋予【主】旧提示以‘提示’。
									进行通知‘提示’。
								了。
								（设置在线0。）
							了。
						上代码",e.innerText);
					}、浏览器#0。
			上代码。
		上代码。
		1。退出。
	了。
上代码。
