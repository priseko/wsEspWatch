#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webServer.h"

extern ESP8266WebServer webServer;
extern String IP;

void updateBrightness(int newBrightness);
void updateColor(int red, int green, int blue);

String thisColor = "#123456"; //default color for color wheel
String rawColor;  //raw color to differentiate if the color has changed
String rawBright; // raw brightness to differentiate if the brightness level has changed
const char* html = // this is the webpage served to the client

  "<!DOCTYPE html><html><head><meta http-equiv='X-UA-Compatible' content='IE=Edge'><meta charset='utf-8'><title>Normans WortUhr</title><script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.js'></script><script type='text/javascript' src='http://gilbertsincobh.com/wp-content/plugins/revslider/js/farbtastic/farbtastic.js'></script><link rel='stylesheet' href='http://gilbertsincobh.com/wp-content/plugins/revslider/js/farbtastic/farbtastic.css' type='text/css' /><script type='text/javascript'>$(document).ready(function() {$('#demo').hide();$('#picker').farbtastic('#color');});"
  "function ResetWebpage(){if (window.location.href != 'http://#IPADDRESS/'){window.open ('http://#IPADDRESS/','_self',true)}};" //change the website value here to your static website
  "function myFunction(){document.getElementById('brightnessLevel').submit();}</script>"
  "<style type='text/css'>.bt{display:block;width:250px;height:100px;padding:10px;margin:10px;text-align:center;border-radius:5px;color:white;font-weight:bold;font-size:40px;text-decoration:none;}"
  "body{background:#fff;}.red{background:red;color:white;}.green{background:#0C0;color:white;}.blue{background:blue;color:white;}"
  ".white{background:white;color:black;border:1px solid black;}.off{background:#666;color:white;}.colorPicker{background:white;color:black;}.colorWipe{font-size:40px;  background:linear-gradient(to right, red, #0C0, blue);}"
  ".y{background:#EE0;height:100px;width:100px;border-radius:50px;}.b{background:#fff;height:100px;width:100px;border-radius:50px;}.a{font-size:35px;}td{vertical-align:middle;}</style></head>"
  "<body onload='ResetWebpage()'><h1>Helligkeit</h1><table>"
  "<tr><td><form id='brightnessLevel'><input type='range' name='bright' max='255' min='1' value='#bright' onchange='myFunction()'class='bt off'></form></td></tr></table>"
  "<h1>Farbe</h1><form name='color' value='#123456'><label for='color'><font color='Black' style='padding-left:100px'>Color:</font></label><input type='text' id='color' name='color' value='#colors' /><input type='submit' id='colorPost' name='colorPost' value='SUBMIT' /></form><table><tr><td width = '100'><div class='TGT_13'></div></td> <td width = '400'><div id='picker'></div></td></tr></table></body></html>";

void initWebServer(int brightness) {
  
}

void handleRoot() {
  String toSend = html;

  if ((webServer.argName(0) == "color") && (webServer.arg(0) != rawColor)) //if the first argument name is "color" and it has changed from the last color
  {
    rawColor = webServer.arg(0);//save the argument data as the variable rawColor
    thisColor = rawColor;
    handle_color();//run the handle_color() function
  }
  if ((webServer.argName(0) == "bright") && (webServer.arg(0) != rawBright))//if the first argument is bright and it has changed from the last brightness level
  {
    rawBright = webServer.arg(0);
    handle_bright();
  }

  toSend.replace("#IPADDRESS", IP); //replace the "#IPADDRESS" in the HTML above with the string IP
  toSend.replace("#colors", thisColor); //replace "#colors" in the html with the color value
  toSend.replace("#bright", rawBright);//same as above with the brightness value
  webServer.send(200, "text/html", toSend); //send the html code to the client
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += webServer.uri();
  message += "\nMethod: ";
  message += (webServer.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += webServer.args();
  message += "\n";
  for (uint8_t i=0; i<webServer.args(); i++){
    message += " " + webServer.argName(i) + ": " + webServer.arg(i) + "\n";
  }
  webServer.send(404, "text/plain", message);
}

void handle_color()
{
  if (rawColor.indexOf("%23") >= 0)//if the string has %23 which is "#"
  {
    thisColor = "#";//add it in as a usable character
    thisColor += rawColor.substring((rawColor.indexOf("%23") + 3));//add in the color code
  }
  
  String r = "0x" + thisColor.substring(1, 3);//sets string r to a string of the byte value
  String g = "0x" + thisColor.substring(3, 5);//same as above
  String b = "0x" + thisColor.substring(5, 7);

  const char *r1 = r.c_str(); //converts the string to a const char to convert to RGB values below
  const char *g1 = g.c_str(); //same as above
  const char *b1 = b.c_str();
  int red = RGBValue(r1);//converts to RGB value
  int green = RGBValue(g1);
  int blue = RGBValue(b1);

  Serial.printf("Red: %d, Green: %d, Blue: %d \n", red, green, blue);

  updateColor(red, green, blue);
}

void handle_bright()
{
  Serial.println(rawBright);
  updateBrightness(webServer.arg(0).toInt());
}

unsigned int RGBValue(const char * s)//converts the value to an RGB value
{
  unsigned int result = 0;
  int c ;
  if ('0' == *s && 'x' == *(s + 1)) {
    s += 2;
    while (*s) {
      result = result << 4;
      if (c = (*s - '0'), (c >= 0 && c <= 9)) result |= c;
      else if (c = (*s - 'A'), (c >= 0 && c <= 5)) result |= (c + 10);
      else if (c = (*s - 'a'), (c >= 0 && c <= 5)) result |= (c + 10);
      else break;
      ++s;
    }
  }
  return result;
}
