const char webpage[] PROGMEM="HTTP/1.1 200 OK\r\n\r\n<html><style>div.wm{position:relative;left:2%;height:1px}</style><head><title>Bumper Bot Controls</title><script>function drive(L,R,C=0){if(C==0){var req='?'+L+','+R+'!'}else{var req='?C,C!'+C+'&'}var xhr=new XMLHttpRequest();xhr.open('GET',req,!0);xhr.send()}"
	"var orient_interval=null;var orient_x=0;var orient_y=0;function toggleTilt()"
	"{tilt=!tilt;if(tilt)"
	"{orient_interval=setInterval(function(){drive(orient_x,orient_y)},300);document.getElementById('ttog').innerHTML='on'}"
	"else{clearInterval(orient_interval);orient_interval=null;document.getElementById('ttog').innerHTML='off'}}"
	"var maxspeed=75;var tilt=!1;var center_gamma=-45;var center_beta=0;var cons={' ':function(){drive(0,0)},stop:function(){drive(0,0)},w:function(){drive(75,75)},s:function(){drive(-40,-40)},d:function(){drive(-35,35)},a:function(){drive(35,-35)},f:{f:function(){drive(0,0,1)},disc:\"sends command 1 (toggles builtin LED\"},g:{f:function(){drive(0,0,2)},disc:\"sends command 2 (toggles pin D3)\"}};window.addEventListener('keydown',function(event){if(event.defaultPrevented){return}"
	"var k=event.key;if(k in cons){cons[k]()}else{console.log('nokey: '+k)}"
	"event.preventDefault()},!0);window.addEventListener('deviceorientation',function(event)"
	"{if(tilt)"
	"{orient_x=Math.floor(event.gamma-center_gamma)-event.beta;orient_y=Math.floor(event.gamma-center_gamma)+event.beta;console.log('throt: '+(event.gamma-center_gamma)+event.beta)}"
	"document.getElementById('disABG').innerHTML='A:'+Math.floor(event.alpha)+' B:'+Math.floor(event.beta)+' G:'+Math.floor(event.gamma)+' betaOff:'+Math.floor(center_beta-event.beta)+'gammaOff:'+Math.floor(center_gamma-event.gamma)},!0);</script></head><body><!--controll buttons--><div class='wm'><input id='bfw' type='button' value='w' onclick='cons.w();'/></div><br><input id='bl' type='button' value='a' onclick='cons.a();'/><input id='bbw' type='button' value='s' onclick='cons.s();'/><input id='br' type='button' value='d' onclick='cons.d();'/><br><input id='bstp' type='button' value='space' onclick='cons.stop();'/><table id='extraFuncs'></table><!--toggle tilt controll button--><br>Tilt controll works but is not 100%<br>Tilt toggle:<button id='ttog' onclick='toggleTilt()'>off</button><!--space to display alpha beta gamma rotation data--><br><br><span id='disABG'></span></body><script>var table=document.getElementById('extraFuncs');function makeExtraButtons(){for(var key in cons){if(key!=\"a\"&&key!=\"s\"&&key!=\"stop\"&&key!=\"w\"&&key!=\"d\"&&key!=\" \"){var tr='<tr>';tr+=\"<td>\"+\"<input type='button' value='\"+key+\"' onclick='cons.\"+key+\"();'/></td><td>\"+cons[key].disc+\"</td></tr>\";table.innerHTML+=tr;console.log(table);console.log(tr)}}}"
	"makeExtraButtons();</script></html>";