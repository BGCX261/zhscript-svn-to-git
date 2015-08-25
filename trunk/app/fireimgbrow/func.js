function $(id){
	return document.getElementById(id);
}
function set_html__(id,html){
	$(id).innerHTML=html;
}
function rnd__(max){
	return Math.floor(Math.random()*max);
}
function set_pic_mask_rect__(left,top,width,height){
	if(!left)
		left=0;
	if(!top)
		top=0;
	if(!width)
		width=document.body.clientWidth;
	if(!height)
		height=document.body.clientHeight;
	//距顶、底
	var i_t=0,i_b=20;
	var i_l=50,i_r=i_l+i_b;
	/*var mask=$("pic_mask_");
	mask.style.left=(left+i_l)+"px";
	mask.style.top=(top+i_t)+"px";
	mask.style.width=(width-i_l-i_r)+"px";
	mask.style.height=(height-i_t-i_b)+"px";*/
	var w=width;
	var i3=700;
	if(w>i3)
		w=i3;
	w=w-i_l-i_r;
	//居中
	i3=(width-w)/2;
	if(i3>i_l)
		i_l=i3;
	var mask;
	//上面占三分之一 (height-i_t-i_b)/3
	var h0=50;
	//间隙、纵
	var jianxi=20,jianxiz=20;
	var n,w1,h1,t1;
	n=4;
	w1=(w-(n-1)*jianxi)/n;
	t1=top+i_t;
	for(var i4=0;i4<n;i4++){
		mask=$("pic_mask_"+i4+"_");
		mask.style.left=(left+i_l+i4*w/n)+"px";
		mask.style.top=t1+"px";
		mask.style.width=w1+"px";
		mask.style.height=h0+"px";
	}
	n=3;
	w1=(w-(n-1)*jianxi)/n;
	t1=i_t+h0+jianxiz;
	h1=height-t1-i_b;
	t1+=top;
	for(var i4=0;i4<n;i4++){
		mask=$("pic_mask_"+(7-n+i4)+"_");
		mask.style.left=(left+i_l+i4*w/n)+"px";
		mask.style.top=t1+"px";
		mask.style.width=w1+"px";
		mask.style.height=h1+"px";
	}
	for(var i4=0;i4<7;i4++){
		mask=$("pic_mask_"+i4+"_");
		mask.onmouseover=i4>=4?function(){
			this.style.opacity=0.25;
		}:function(){
			this.style.opacity=0.87;
		}
		mask.onmouseout=function(){
			this.style.opacity=0;
		}
	}
}
var pic_mask_show_i_,pic_mask_show_timer_;
function pic_mask_show__(i){
	var mask;
	if(i){
		if(pic_mask_show_i_<=0){
			clearTimeout(pic_mask_show_timer_);
			return;
		}
		pic_mask_show_i_-=i;
	}else
		pic_mask_show_i_=1;
	for(var i4=0;i4<7;i4++){
		mask=$("pic_mask_"+i4+"_");
		mask.style.opacity=pic_mask_show_i_;
	}
	pic_mask_show_timer_=setTimeout("pic_mask_show__(0.1)",300);
}
function set_toolbar_loc__(){
	$("toolbar_").style.top=(document.body.clientHeight-70)+"px";
}
window.onresize=function(){
	//set_toolbar_loc__();
	set_pic_mask_rect__();
}
var a_=new Array();
var i_=0;
function set_pic__(){
	if(a_.length<1){
		$("pic").src="about:blank";
		return;
	}
	if(i_<0)
		i_=a_.length-1;
	if(i_>=a_.length)
		i_=0;
	var s=a_[i_];
	$("pic").src="file:///"+s;
	document.title=s+" "+i_+"/"+a_.length;
}
var i1_=1;
function back__(){i1_=-1;i_+=i1_;set_pic__();}
function next__(){i1_=1;i_+=i1_;set_pic__();}
function rand__(){i_=rnd__(a_.length);set_pic__();}
function del__(){
	var s="销毁“\n"+a_[i_]+"\n”";
	if(!confirm(s))
		return;
	if(zs_(s)!='0'){
		alert(s+"失败");
		return;
	}
	a_.splice(i_,1);
	set_pic__();
}
function edit__(){
	var res=zs_("编辑“"+a_[i_]+"”");
	switch(res){
	case "0":
		break;
	case "1":
		a_.splice(i_,1);
		if(i1_==-1)
			i_+=i1_;
		set_pic__();
		break;
	default:
		if(res.charAt(0)==':'){
			alert(res);
			break;
		}
		a_[i_]=res;
		if(i1_==-1)
			back__();
		else
			next__();
		break;
	}
}
document.onkeypress=function(event){
	switch(String.fromCharCode(event.charCode)){
	case'r':
		rand__();
		break;
	case'b':
		back__();
		break;
	case'n':
		next__();
		break;
	case'f':
		set_pic__();
		break;
	case'e':
		edit__();
		break;
	case'x':
		del__();
		break;
	case't':
		pic_mask_show__();
		break;
	}
}
