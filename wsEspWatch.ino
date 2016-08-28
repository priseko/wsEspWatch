#include <stdbool.h>
#include <NTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "wordClock.h"
#include "webServer.h"

#define PIN (4)

const char *ssid     = "netz";
const char *password = "#netz4all!";

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(12, 10, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

ESP8266WebServer webServer(80);

int color;
int brightness = 60;
int lastDispSec = 0;
String IP;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "de.pool.ntp.org", 7200 /* 2h offset */, 60000 /* Update once per minute*/);

void setup() {
  int x = matrix.width();
  int pass = 0;
  const uint16_t colors[] = {matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255) };
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setTextColor(colors[pass]);
  matrix.setBrightness(brightness);

  while ( WiFi.status() != WL_CONNECTED ) {
    matrix.fillScreen(0);
    matrix.setCursor(x, 1);
    matrix.print(F("Hallo"));
    if(--x < -36) {
      x = matrix.width();
      if(++pass >= 3) pass = 0;
      matrix.setTextColor(colors[pass]);
    }
    matrix.show();
    delay ( 100 );
    Serial.print ( "." );
  }

  if (MDNS.begin("wortuhr")) {
    Serial.println("MDNS responder started");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }

  IPAddress localIP = WiFi.localIP();
  IP = String(localIP[0]);
  IP += ".";
  IP += String(localIP[1]);
  IP += ".";
  IP += String(localIP[2]);
  IP += ".";
  IP += String(localIP[3]);

  webServer.on("/", handleRoot);
  webServer.onNotFound(handleNotFound);
  webServer.begin();
  Serial.println("HTTP server started");

  timeClient.begin();
  
  color = matrix.Color(255, 114, 0);
  matrix.show();

  initWords();
  initWebServer(brightness);
}

void loop() {
  timeClient.update();

  int seconds = timeClient.getSeconds();
  if (lastDispSec != seconds) {
    lastDispSec = seconds;
    Serial.println(timeClient.getFormattedTime());
  }

  if (updateClockDisplay(color, timeClient.getHours(), timeClient.getMinutes(), false)) {
    matrix.show();
  }
  webServer.handleClient();
}

void updateColor(int red, int green, int blue) {
  color = matrix.Color(red, green, blue);
  updateClockDisplay(color, timeClient.getHours(), timeClient.getMinutes(), true);
  matrix.show();
}

void updateBrightness(int newBrightness) {
  brightness = newBrightness;
  matrix.setBrightness(brightness);
  matrix.show();
}


