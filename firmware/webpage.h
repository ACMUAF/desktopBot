const char webpage[] PROGMEM="HTTP/1.1 200 OK\r\n\r\n"
	"<html><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><style>html,head,body"
	"{margin:0px;padding:0px;background-color:#555555}"
	"h1"
	"{color:#4CFF51;font-family:\"Helvetica Neue\",Helvetica,Arial,sans-serif;font-size:48px;font-weight:900;-webkit-text-fill-color:#4CFF51;-webkit-text-stroke-width:1px;-webkit-text-stroke-color:black}.key"
	"{--width:64px;--height:32px;--spacing:1px;width:var(--width);height:var(--height);background-color:#333333;border:1px solid #4CFF51;color:#4CFF51;padding:0px;margin:var(--spacing);font-size:12px}.key:hover"
	"{background-color:#4CAF50;border:1px solid white;color:white}.key.sp"
	"{width:196}.debug"
	"{color:#4CFF51;font-family:\"Helvetica Neue\",Helvetica,Arial,sans-serif;font-size:12px}</style><head><title>Bumper Bot</title><center><h1>Bumper Bot</h1><div><input class='key' id='bfw' type='button' value='W' onclick='cons.w();'/><br/><input class='key' id='bl' type='button' value='A' onclick='cons.a();'/><input class='key' id='bbw' type='button' value='S' onclick='cons.s();'/><input class='key' id='br' type='button' value='D' onclick='cons.d();'/><br/><input class='key sp 'id='bstp' type='button' value='Space' onclick='cons.stop();'/><br/><br/><div id='key_div'></div><br/><div class='debug' id='disABG'></div></div></center></head><body><script>function drive(L,R,C=0)"
	"{var req='?C,C!'+C+'&';if(C==0)"
	"req='?'+L+','+R+'!';var xhr=new XMLHttpRequest();xhr.open('GET',req,!0);xhr.send()}"
	"var orient_interval=null;var orient_x=0;var orient_y=0;var maxspeed=75;var tilt=!1;var center_gamma=-45;var center_beta=0;function toggleTilt()"
	"{tilt=!tilt;if(tilt)"
	"{this.value='Tilt ON';orient_interval=setInterval(function(){drive(orient_x,orient_y)},300)}"
	"else{this.value='Tilt OFF';clearInterval(orient_interval);orient_interval=null}}"
	"var cons={' ':function(){drive(0,0)},stop:function(){drive(0,0)},w:function(){drive(75,75)},s:function(){drive(-40,-40)},d:function(){drive(-35,35)},a:function(){drive(35,-35)},LED:function(){drive(0,0,1)},D3:function(){drive(0,0,2)},'Tilt OFF':toggleTilt};window.addEventListener('keydown',function(event)"
	"{var k=event.key;if(k in cons)"
	"cons[k]();else console.log('nokey: '+k)},!0);window.addEventListener('deviceorientation',function(event)"
	"{var beta=event.beta;if(beta<-45)"
	"beta=-45;if(beta>45)"
	"beta=45;if(tilt)"
	"{orient_x=Math.floor(event.gamma-center_gamma)-event.beta;orient_y=Math.floor(event.gamma-center_gamma)+event.beta}"
	"document.getElementById('disABG').innerHTML='A:'+Math.floor(event.alpha)+'<br/>'+'B:'+Math.floor(event.beta)+'<br/>'+'G:'+Math.floor(event.gamma)+'<br/>'+'betaOff:'+Math.floor(center_beta-event.beta)+'<br/>'+'gammaOff:'+Math.floor(center_gamma-event.gamma)},!0);for(var key in cons)"
	"{if(['w','a','s','d',' ','stop'].indexOf(key)<0)"
	"{var input=document.createElement('input');key_div.appendChild(input);input.type='button';input.className='key';input.value=key;input.addEventListener('click',cons[key])}}</script></body></html>";