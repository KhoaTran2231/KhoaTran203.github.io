#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
//==========AP info=======================//
char* ssid = "KhoaTran";
char* pass = "1234567890";
//=========Biến chứa mã HTLM Website==//
const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <titleGIAO DIEN TEST>E-SMART HOME</title> 
       <style> 
          body {text-align:center;background-color:#222222; color:white}
          input {
            height:25px; 
            width:270px;
            font-size:20px;
            margin: 10px auto;
          }
          #content {
            border: white solid 1px; 
            padding:5px;  
            height:375px; 
            width:330px; 
            border-radius:20px;
            margin: 0 auto
          }
          .ledstatus{
              outline: none;
              margin: 15px 5px;
              width: 60px;
              height: 60px;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
              color:white;
              font-size:20px;
              font-weight: bold;
          }
          #ledstatus1{
              border: solid 2px #23C48E;
              background: #23C48E;
          }
          #ledstatus2{
              border: solid 2px #ED9D00;
              background: #ED9D00;
          }
          #ledstatus3{
              border: solid 2px #5F7CD8;
              background: #5F7CD8;
          }
          #ledconnect{
              outline: none;
              margin: 0px 5px -1px 5px;
              width: 15px;
              height: 15px;
              border: solid 1px #00EE00;
              background-color: #00EE00;
              border-radius: 50%;
              -moz-border-radius: 50%;
              -webkit-border-radius: 50%;
          }
          .button {
            height:65px; 
            width:70px; 
            margin:10px 0;
            background-color:#3C89BC;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:25px;
            font-weight: bold;
          }
          .button_all{
            height:70px; 
            width:140px; 
            margin:10px 0;
            outline:none;
            color:white;
            font-size:20px;
            font-weight: bold;
          }
          #button_on {
            background-color:#00BB00;
            border-radius:10px;
          }
          #button_off {
            background-color:#CC3300;
            border-radius:10px;
          }
          .button_setup {
            height:30px; 
            width:280px; 
            margin:10px 0;
            background-color:#3C89BC;
            border-radius:10px;
            outline:none;
            color:white;
            font-size:20px;
            font-weight: bold;
          }
          .button_wifi{
            height:50px; 
            width:90px; 
            margin:10px 0;
            outline:none;
            color:white;
            font-size:15px;
            font-weight: bold;
          }
       </style>
       <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
      <div><h1>GIAO DIỆN TEST</h1></div>
      <div id="content"> 
        <div id="homecontrol" style="height:340px";>
          <div>
            <input id="ledstatus1" class="ledstatus" type="button" value="ON"/>
            <input id="ledstatus2" class="ledstatus" type="button" value="ON"/>
            <input id="ledstatus3" class="ledstatus" type="button" value="ON"/>
          </div>
           <div>
            <button class="button" onclick=getbutton(1)>1</button>
            <button class="button" onclick=getbutton(2)>2</button>
            <button class="button" onclick=getbutton(3)>3</button>
          </div>
          <div>
            <button id="button_on" class="button_all" onclick="getbuttonall('on')">Turn on all</button>
            <button id="button_off" class="button_all"onclick="getbuttonall('off')">Turn off all</button>
          </div>
          <div><input class="button_setup" type="button" onclick="configurewifi()" value="Configure WiFi"/></div>
          <div>IP connected: <b><pan id="ipconnected"></pan></b></div>
        </div>
        
        
        //===========Tạo và gửi request khi ấn button============================
        //-----------Thiết lập dữ liệu và gửi request ON/OFF D4---
        function getbutton(n){
          switch (n){
            case 1:
                var ledstatus1 = document.getElementById("ledstatus1").value;
                if(ledstatus1 == "ON"){
                  xhttp_statusD.open("GET","/D1off",true);
                }else{
                  xhttp_statusD.open("GET","/D1on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                x http_statusD.send();
                break;
            case 2:
                var ledstatus2 = document.getElementById("ledstatus2").value;
                if(ledstatus2 == "ON"){
                  xhttp_statusD.open("GET","/D2off",true);
                }else{
                  xhttp_statusD.open("GET","/D2on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 3:
                var ledstatus3 = document.getElementById("ledstatus3").value;
                if(ledstatus3 == "ON"){
                  xhttp_statusD.open("GET","/D3off",true);
                }else{
                  xhttp_statusD.open("GET","/D3on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 4:
               var ledstatus4 = document.getElementById("ledstatus4").value;
                if(ledstatus4 == "ON"){
                  xhttp_statusD.open("GET","/D4off",true);
                }else{
                  xhttp_statusD.open("GET","/D4on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
          }
        }
        function getbuttonall(m){
          if(m == "on"){
            xhttp_statusD.open("GET","/Allon",true);
          }else if(m=="off"){
            xhttp_statusD.open("GET","/Alloff",true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }
        //===========Configure WiFi=====================================
        function configurewifi(){
          document.getElementById("homecontrol").style.display = "none";
          document.getElementById("wifisetup").style.display = "block";
        }
        //-----------Thiết lập dữ liệu và gửi request ssid và password---
        function writeEEPROM(){
          if(Empty(document.getElementById("ssid"), "Please enter ssid!")&&Empty(document.getElementById("pass"), "Please enter password")){
            var ssid = document.getElementById("ssid").value;
            var pass = document.getElementById("pass").value;
            xhttp.open("GET","/writeEEPROM?ssid="+ssid+"&pass="+pass,true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function clearEEPROM(){
          if(confirm("Do you want to delete all saved wifi configurations?")){
            xhttp.open("GET","/clearEEPROM",true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function restartESP(){
          if(confirm("Do you want to reboot the device?")){
            xhttp.open("GET","/restartESP",true);
            xhttp.send();
            alert("Device is restarting! If no wifi is found please press reset!");
          }
        }
        //-----------Kiểm tra response -------------------------------------------
        function process(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data sử dụng javascript----------
            ketqua = xhttp.responseText; 
            document.getElementById("reponsetext").innerHTML=ketqua;       
          }
        }
       //============Hàm thực hiện chứ năng khác================================
       //--------Cập nhật trạng thái tự động sau 2000 giây----------------------
        setInterval(function() {
          getstatusD();
        },2000);
       //--------Load lại trang để quay về Home control-------------------------
        function backHOME(){
          window.onload();
        }
       //----------------------------CHECK EMPTY--------------------------------
       function Empty(element, AlertMessage){
          if(element.value.trim()== ""){
            alert(AlertMessage);
            element.focus();
            return false;
          }else{
            return true;
          }
       }
       //------------------------------------------------------------------------
      </script>
   </body> 
  </html>
)=====";
//=========================================//
void setup() {
  Serial.begin(9600);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
   WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

  webServer.on("/",mainpage);
  webServer.on("/onD1",D1_on);
  webServer.on("/offD1",D1_off);
  webServer.on("/onD2",D2_on);
  webServer.on("/offD2",D2_off);
    webServer.on("/onD3",D3_on);
  webServer.on("/offD3",D3_off);
  webServer.begin();
  
}
void loop() {
  webServer.handleClient();
}
//==========Chương trình con=================//
void mainpage(){
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}

//--------------Điều khiển chân D1----------------
void D1_on(){
  digitalWrite(D1,LOW);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void D1_off(){
   digitalWrite(D1,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
//--------------Điều khiển chân D2----------------
void D2_on(){
  digitalWrite(D2,LOW);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void D2_off(){
  digitalWrite(D2,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
//--------------Điều khiển chân D3----------------
void D3_on(){
 digitalWrite(D3,LOW);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
void D3_off(){
  digitalWrite(D3,HIGH);
  String s = FPSTR(MainPage);
  webServer.send(200,"text/html",s);
}
//--------------Điều khiển chân D----------------
void All_on(){
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);

}
void All_off(){
  digitalWrite(D1,HIGH);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,HIGH);
}


