
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
				false。
				退出。
			了。
			赋予果以迭代数组下代码
				如果‘参数3’等于-那么再来。
				如果‘参数1’等于‘名’并且‘参数2’等于‘号’那么true，跳出。
			上代码、群静默。
			如果不‘果’那么先
				赋予果以迭代数组下代码
					如果‘参数3’等于-那么再来。
					如果‘参数1’等于‘名’并且
						调用‘子串方法’、‘参数2’、-6等于调用‘子串方法’、‘号’、-6那么true，跳出。
				上代码、群静默。
				如果不‘果’那么false，跳出。
			了。
			‘果’。
			跳出。
		了。
		等于web.qq那么先
			别名名以参数1。
			赋予果以迭代数组下代码
				如果‘参数3’等于-那么再来。
				如果‘参数1’等于‘名’那么true，跳出。
			上代码、群静默。
			如果不‘果’那么false，跳出。
			‘果’。
			跳出。
		了。
	了。
上代码。

隧道侦听、点击、quno、quno1、下代码
	赋予群静默取号【主】以。
	当‘登录目标’先
		等于w.qq那么先
			隧道webkit、插脚、‘js函数集’下代码
				var h=htm__("chatWinHeader");
				if(h){
					z$("
						如果调用‘正则攫’、‘参数1’、>([^<\"]+)<br>小于1那么退出。
						调用‘正则攫’、‘之1’、(.+)\\(([0-9]+)\\)。
						赋予之1以调用‘html2text’、‘之1’、0、0。
						赋予号以搜索数组群静默、‘之1’、‘之2’。
						如果‘号’小于1那么先
							增至数组【顶】群静默、3、‘之1’、‘之2’、。
							赋予号以‘群静默数目’。
						了。
						赋予群静默取名【主】以‘之1’。
						赋予群静默取号【主】以‘号’。
					",h);
				}
			上代码、浏览器#0。
			跳出。
		了。
		等于web.qq那么先
			（
				var wc=__("window window_current");
				if(wc){
					/*test_e__(wc);*/
					var e=wc.childNodes;
					var e1=e[1].childNodes;
					var e2=e1[1].childNodes;
					var e3=e2[3].childNodes;
					var e4=e3[1].childNodes;
					var e5=e4[3].childNodes;
					var e6=e5[2].childNodes;
					var e7=e6[0].childNodes;
					var e8=e7[1];
			）
			隧道webkit、插脚、‘js函数集’下代码
				var e8=e__(__("window window_current"),1,1,3,1,3,2,0,1);
				if(e8){
					if(e8.className=="chatBox_mainName"){
						z$("
							赋予之1以调用‘html2text’、‘参数1’、0、0。
							如果不‘之1’那么退出。
							赋予号以搜索数组群静默、‘之1’。
							如果‘号’小于1那么先
								增至数组【顶】群静默、3、‘之1’、、。
								赋予号以‘群静默数目’。
							了。
							赋予群静默取名【主】以‘之1’。
							赋予群静默取号【主】以‘号’。
						",e8.innerHTML);
					}
				}
			上代码、浏览器#0。
			跳出。
		了。
	了。
	加载lib2/msgbox。
	如果不‘群静默取号’那么隧道提示、、‘参数1’、‘停止’，退出。
	序迭代数组下代码
		显示‘参数’↙。
	上代码、群静默。
	当隧道提示、“对“‘群静默取名’”使用吗”、‘参数1’、‘询问’、‘是否按钮’先
		等于‘是’那么
			赋予【顶】群静默之‘群静默取号’之3以，跳出。
		等于‘否’那么
			赋予【顶】群静默之‘群静默取号’之3以-，跳出。
		那么退出。
	了。
	保存配置文件。
上代码。