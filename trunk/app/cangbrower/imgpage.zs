加载lib/defi。
加载lib/clpars4。
加载lib/doscmd4。
加载lib2/js.zs。
加载lib/filetype。

（
div align='left' style="position:fixed;left:2px;top:10px;"
<a href='javascript:set_pic__()'><img src='/icons/gnome/32x32/actions/view-refresh.png' title='刷新'></a>
 onclick="javascript:rand__()"
）
赋予==以“ &nbsp; &nbsp; ”。
显示“<span id=ctlbar_>
<a href='javascript:first__()'>‘==’<img src='/icons/gnome/32x32/actions/go-first.png' title='第一张'>‘==’</a>
<a href='javascript:back__()'>‘==’<img src='/icons/gnome/32x32/actions/go-previous.png' title='上一张'>‘==’</a>
<a href='javascript:next__()'>‘==’<img src='/icons/gnome/32x32/actions/go-next.png' title='下一张'>‘==’</a>
<a href='javascript:rand__()'>‘==’<img src='/icons/gnome/32x32/actions/go-jump.png' title='随机一张'>‘==’</a>
<span><span id=num_>等候……</span><br>
<img id=pic_>”↙。

显示“<script>‘js函数集’
var a_=new Array();
var i_=-1;
function set_pic__(){
	if(a_.length<1){
		return;
	}
	if(i_<0)
		i_=a_.length-1;
	if(i_>=a_.length)
		i_=0;
	__("pic_").src=a_[i_];
	htm__("num_",i_+"-"+a_.length);
}
function first__(){i_=0;set_pic__();}
function back__(){i_--;set_pic__();}
function next__(){i_++;set_pic__();}
function rand__(){i_=Math.floor(Math.random()*a_.length);set_pic__();}
”↙。

别名root以参数1。
调用‘参数处理’、、、1、下代码
	别名目录以参数1。
	赋予搜以调用‘dir.begin’、‘root’‘目录’、、so0。
	循环先
		赋予名以调用‘dir.next’、‘搜’。
		如果‘名’等于“”那么跳出。
		如果文件类型‘root’‘目录’/‘名’等于p/png或者等于p/gif或者等于p/jpg那么
			显示a_.push("‘目录’/‘名’");↙。
	了。
	调用‘dir.end’、‘搜’。
上代码、----、‘参数栈2’。

显示rand__()</script>↙。
