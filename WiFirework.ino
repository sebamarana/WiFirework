#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//Our HTML webpage contents in program memory
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Esplosivo</title>
      <style>
        html, body {
            width: 100%;
            height: 100%;
            margin: 0px; 
            background-color: #042A02;
            background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 2000 1500'%3E%3Cdefs%3E%3Ccircle stroke='%2311DD1A' vector-effect='non-scaling-stroke' id='a' fill='none' stroke-width='5' r='315'/%3E%3Cuse id='f' href='%23a' stroke-dasharray='100 100 100 9999'/%3E%3Cuse id='b' href='%23a' stroke-dasharray='250 250 250 250 250 9999'/%3E%3Cuse id='e' href='%23a' stroke-dasharray='1000 500 1000 500 9999'/%3E%3Cuse id='g' href='%23a' stroke-dasharray='1500 9999'/%3E%3Cuse id='h' href='%23a' stroke-dasharray='2000 500 500 9999'/%3E%3Cuse id='j' href='%23a' stroke-dasharray='800 800 800 800 800 9999'/%3E%3Cuse id='k' href='%23a' stroke-dasharray='1200 1200 1200 1200 1200 9999'/%3E%3Cuse id='l' href='%23a' stroke-dasharray='1600 1600 1600 1600 1600 9999'/%3E%3C/defs%3E%3Cg transform='translate(1000 750)' stroke-opacity='0.7'%3E%3Cg transform='rotate(0 0 0)' %3E%3Ccircle fill='%2311DD1A' fill-opacity='0.7' r='10'/%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23f' transform='scale(.1) rotate(50 0 0)' /%3E%3Cuse href='%23f' transform='scale(.2) rotate(100 0 0)' /%3E%3Cuse href='%23f' transform='scale(.3) rotate(150 0 0)' /%3E%3C/g%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23b' transform='scale(.4) rotate(200 0 0)' /%3E%3Cuse href='%23z' transform='scale(.5) rotate(250 0 0)' /%3E%3C/g%3E%3Cg id='z' transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23b'/%3E%3Cuse href='%23b' transform='scale(1.2) rotate(90 0 0)' /%3E%3Cuse href='%23b' transform='scale(1.4) rotate(60 0 0)' /%3E%3Cuse href='%23e' transform='scale(1.6) rotate(120 0 0)' /%3E%3Cuse href='%23e' transform='scale(1.8) rotate(30 0 0)' /%3E%3C/g%3E%3C/g%3E%3Cg id='y' transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23e' transform='scale(1.1) rotate(20 0 0)' /%3E%3Cuse href='%23g' transform='scale(1.3) rotate(-40 0 0)' /%3E%3Cuse href='%23g' transform='scale(1.5) rotate(60 0 0)' /%3E%3Cuse href='%23h' transform='scale(1.7) rotate(-80 0 0)' /%3E%3Cuse href='%23j' transform='scale(1.9) rotate(100 0 0)' /%3E%3C/g%3E%3C/g%3E%3Cg transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23h' transform='scale(2) rotate(60 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.1) rotate(120 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.3) rotate(180 0 0)'/%3E%3Cuse href='%23h' transform='scale(2.4) rotate(240 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.5) rotate(300 0 0)'/%3E%3C/g%3E%3Cuse href='%23y' transform='scale(2) rotate(180 0 0)' /%3E%3Cuse href='%23j' transform='scale(2.7)'/%3E%3Cuse href='%23j' transform='scale(2.8) rotate(45 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.9) rotate(90 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.1) rotate(135 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.2) rotate(180 0 0)'/%3E%3C/g%3E%3Cuse href='%23k' transform='scale(3.3) rotate(225 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.5) rotate(270 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.6) rotate(315 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.7)'/%3E%3Cuse href='%23k' transform='scale(3.9) rotate(75 0 0)'/%3E%3C/g%3E%3C/g%3E%3C/g%3E%3C/svg%3E");
            background-attachment: fixed;
            background-repeat: no-repeat;
            background-size: cover;
            background-position: center;
        }
        .title {
            color: white; 
            background-color: rgba(24, 24, 24, 0.6);
            padding: 10px 0px;
        }

        .title1 {
            font-size: 28px; 
            font-weight: bold; 
        }

        .all {
            width: 100%;
            max-width: 400px;
        }

        .element {
            width: 95%;
        }

        .detonateButton {
            transition: 0.1s;
            border-radius: 100%;
            background-color: rgb(221, 22, 22);
            font-size: 24px; 
            font-weight: bold;
            box-shadow: 0px 7px 10px rgb(0, 0, 0);
            border-width: 2px 7px 12px 7px;
            border-style: solid;
            border-color: rgb(58, 58, 58);
            -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: black;
            color: white;
            width: 200px;
            height: 200px;
        }

        .detonateButton:active {
            transition: 0.1s;
            box-shadow: 0px 5px 7px rgb(0, 0, 0);
            border-width: 5px 7px 9px 7px;
        }

        .detonateButtonDiv {
            position: absolute;
            top: 0px;

            width: 100%;
            height: 100%;

            display: flex;
            align-items: center;
            justify-content: center;
        }
      </style>
  </head>
  <body style="font-family: 'Roboto', sans-serif;">
    <center>
      <div class="all"> 
        <div class="element title">
          <div class="title1">WiFirework project</div>
          <div class="title2">by sebamarana</div>
        </div><br>
      </div>
    </center>
    <div class="detonateButtonDiv">
        <a href="ledOn" class="aButton"><button class="detonateButton">DETONATE!</button></a>
    </div>
  </body>
</html>
)=====";

const char DETONATION_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
      <meta charset="UTF-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Esplosivo</title>
      <style>
        html, body {
          width: 100%;
          height: 100%;
          margin: 0px; 
          background-color: #042A02;
          background-image: url("data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 2000 1500'%3E%3Cdefs%3E%3Ccircle stroke='%2311DD1A' vector-effect='non-scaling-stroke' id='a' fill='none' stroke-width='5' r='315'/%3E%3Cuse id='f' href='%23a' stroke-dasharray='100 100 100 9999'/%3E%3Cuse id='b' href='%23a' stroke-dasharray='250 250 250 250 250 9999'/%3E%3Cuse id='e' href='%23a' stroke-dasharray='1000 500 1000 500 9999'/%3E%3Cuse id='g' href='%23a' stroke-dasharray='1500 9999'/%3E%3Cuse id='h' href='%23a' stroke-dasharray='2000 500 500 9999'/%3E%3Cuse id='j' href='%23a' stroke-dasharray='800 800 800 800 800 9999'/%3E%3Cuse id='k' href='%23a' stroke-dasharray='1200 1200 1200 1200 1200 9999'/%3E%3Cuse id='l' href='%23a' stroke-dasharray='1600 1600 1600 1600 1600 9999'/%3E%3C/defs%3E%3Cg transform='translate(1000 750)' stroke-opacity='0.7'%3E%3Cg transform='rotate(0 0 0)' %3E%3Ccircle fill='%2311DD1A' fill-opacity='0.7' r='10'/%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23f' transform='scale(.1) rotate(50 0 0)' /%3E%3Cuse href='%23f' transform='scale(.2) rotate(100 0 0)' /%3E%3Cuse href='%23f' transform='scale(.3) rotate(150 0 0)' /%3E%3C/g%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23b' transform='scale(.4) rotate(200 0 0)' /%3E%3Cuse href='%23z' transform='scale(.5) rotate(250 0 0)' /%3E%3C/g%3E%3Cg id='z' transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23b'/%3E%3Cuse href='%23b' transform='scale(1.2) rotate(90 0 0)' /%3E%3Cuse href='%23b' transform='scale(1.4) rotate(60 0 0)' /%3E%3Cuse href='%23e' transform='scale(1.6) rotate(120 0 0)' /%3E%3Cuse href='%23e' transform='scale(1.8) rotate(30 0 0)' /%3E%3C/g%3E%3C/g%3E%3Cg id='y' transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23e' transform='scale(1.1) rotate(20 0 0)' /%3E%3Cuse href='%23g' transform='scale(1.3) rotate(-40 0 0)' /%3E%3Cuse href='%23g' transform='scale(1.5) rotate(60 0 0)' /%3E%3Cuse href='%23h' transform='scale(1.7) rotate(-80 0 0)' /%3E%3Cuse href='%23j' transform='scale(1.9) rotate(100 0 0)' /%3E%3C/g%3E%3C/g%3E%3Cg transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cg transform='rotate(0 0 0)'%3E%3Cuse href='%23h' transform='scale(2) rotate(60 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.1) rotate(120 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.3) rotate(180 0 0)'/%3E%3Cuse href='%23h' transform='scale(2.4) rotate(240 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.5) rotate(300 0 0)'/%3E%3C/g%3E%3Cuse href='%23y' transform='scale(2) rotate(180 0 0)' /%3E%3Cuse href='%23j' transform='scale(2.7)'/%3E%3Cuse href='%23j' transform='scale(2.8) rotate(45 0 0)'/%3E%3Cuse href='%23j' transform='scale(2.9) rotate(90 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.1) rotate(135 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.2) rotate(180 0 0)'/%3E%3C/g%3E%3Cuse href='%23k' transform='scale(3.3) rotate(225 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.5) rotate(270 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.6) rotate(315 0 0)'/%3E%3Cuse href='%23k' transform='scale(3.7)'/%3E%3Cuse href='%23k' transform='scale(3.9) rotate(75 0 0)'/%3E%3C/g%3E%3C/g%3E%3C/g%3E%3C/svg%3E");
          background-attachment: fixed;
          background-repeat: no-repeat;
          background-size: cover;
          background-position: center;
        }
        .title {
          color: white; 
          background-color: rgba(24, 24, 24, 0.6);
          padding: 10px 0px;
        }

        .title1 {
          font-size: 28px; 
          font-weight: bold; 
        }

        .all {
          width: 100%;
          max-width: 400px;
        }

        .element {
          width: 95%;
        }

        .detonateButton {
            transition: 0.1s;
            border-radius: 100%;
            background-color: rgb(0, 180, 180);
            font-size: 24px; 
            font-weight: bold;
            box-shadow: 0px 7px 10px rgb(0, 0, 0);
            border-width: 2px 7px 12px 7px;
            border-style: solid;
            border-color: rgb(58, 58, 58);
            -webkit-text-stroke-width: 1.5px;
            -webkit-text-stroke-color: black;
            color: white;
            width: 200px;
            height: 200px;
        }

        .detonateButton:active {
          transition: 0.1s;
          box-shadow: 0px 5px 7px rgb(0, 0, 0);
          border-width: 5px 7px 9px 7px;
        }

        .detonateButtonDiv {
            position: absolute;
            top: 0px;

            width: 100%;
            height: 100%;

            display: flex;
            align-items: center;
            justify-content: center;
        }
      </style>
  </head>
  <body style="font-family: 'Roboto', sans-serif;">
    <center>
      <div class="all"> 
        <div class="element title">
          <div class="title1">WiFirework project</div>
          <div class="title2">by sebamarana</div>
        </div><br>
      </div>
    </center>
    <div class="detonateButtonDiv">
        <a href="/" class="aButton"><button class="detonateButton">RESET</button></a>
    </div>
  </body>
</html>
)=====";
//---------------------------------------------------------------
//DEFINE OUTPUT SIGNAL PIN
#define PIN D7  

//SSID and Password of your WiFi router
const char* ssid = "WiFirework";
const char* password = "ILoveFireworks";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 Serial.begin(115200);
 Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon() { 
 Serial.begin(115200);
 Serial.println("PIN on");
 digitalWrite(PIN,LOW); //LED is connected in reverse
 server.send(200, "text/html", "LED is ON"); //Send ADC value only to client ajax request
}

void handleLEDoff() {
 Serial.begin(115200); 
 Serial.println("PIN off");
 digitalWrite(PIN,HIGH); //LED off
 server.send(200, "text/html", "LED is OFF"); //Send ADC value only to client ajax request
}

void handleDetonation() {
 Serial.begin(115200); 
 String d = DETONATION_page;
 Serial.println("Detonation Started");
 delay(5000);
 digitalWrite(PIN,HIGH); //Cable ON
 delay(10000);
 digitalWrite(PIN,LOW); //Cable OFF
 server.send(200, "text/html", d); //Send web page
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
  WiFi.softAP(ssid,password);     //Create Wifi
  Serial.println("");

  //Onboard LED port Direction output
  pinMode(PIN,OUTPUT); 
  //Power on LED state off
  digitalWrite(PIN,HIGH); //Da modificare se non si vuole farsi saltare in aria
 
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/ledOn", handleLEDon); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/ledOff", handleLEDoff);
  server.on("/detonation", handleDetonation);

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
