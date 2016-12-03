#define BUFFERSIZE 700
#define MEASUREMENTBUFFERSIZE 64
#include <EtherCard.h>
#include <TimeAlarms.h>
static byte macAddress[] = {0x01,0x02,0x03,0x05,0x08,0x0d};
static byte ipAddress[] = {192,168,0,59};
byte Ethernet::buffer[BUFFERSIZE];
byte lastMeasurement = 0;
int measurementTable[MEASUREMENTBUFFERSIZE];
int secondsBetweenMeasurements = 30;

//if it is defined, then use microcontroller
#define TERMISTOR
#ifndef TERMISTOR
int measure()
{
  return 0; //microchip thermometer
}
#else
int measure()
{
  int m = analogRead(A0);
  return;
}
#endif

void measurement()
{
  lastMeasurement++;
  if(lastMeasurement>=MEASUREMENTBUFFERSIZE)
    lastMeasurement=0;
  measurementTable[lastMeasurement] = measure(); //wstawic prawdziwe pomiary
  Alarm.timerOnce(secondsBetweenMeasurements,measurement);
}

void temperatureView()
{
  BufferFiller response = ether.tcpOffset();
  response.emit_p(PGM_P("HTTP/1.0 200 OK\r\n"
                       "Content-Type: text/html\r\n\r\n"
                       "<html><header><meta charset='utf-8'></header>"
                       "<body><div=m><ul><li><a href=/settings>Ustawienia</a></li>"
                       "<li><a href=/history>Historia</a></li></ul>"
                       "<div id=t>Temperatura</div>"
                       "<div id=h>Wilgotnosc</div></div></body></html>"));
  ether.httpServerReply(response.position());
}

void settingsView()
{
  BufferFiller response = ether.tcpOffset();
  response.emit_p(PGM_P("HTTP/1.0 200 OK\r\n"
                       "Content-Type: text/html\r\n\r\n"
                       "<html><header><meta charset='utf-8'></header>"
                       "<body><div=m><ul><li><a href=/>Strona glowna</a></li>"
                       "<li><a href=/history>Historia</a></li></ul>"
                       "<div id=t>Temperatura</div>"
                       "<div id=h>Wilgotnosc</div></div></body></html>"));
  ether.httpServerReply(response.position());
}

void settingsPost(char* request)
{
  char*
  settingsView();
}

void historyView()
{
  BufferFiller response = ether.tcpOffset();
  response.emit_p(PGM_P("HTTP/1.0 200 OK\r\n"
                       "Content-Type: text/html\r\n\r\n"
                       "<html><header><meta charset='utf-8'></header>"
                       "<body><div=m><ul><li><a href=/>Strona glowna</a></li>"
                       "<li><a href=/history>Historia</a></li></ul>"
                       "<div id=t>Temperatura</div>"
                       "<div id=h>Wilgotnosc</div></div></body></html>"));
  ether.httpServerReply(response.position());
}

void badRequest()
{
  BufferFiller response = ether.tcpOffset();
  response.emit_p(PGM_P("HTTP/1.0 404 Not found\r\n"
                       "Content-Type: text/html\r\n\r\n"
                       "<html><header><meta charset='utf-8'></header>"
                       "<body>404 - nie znaleziono lub zly request</body></html>"));
  ether.httpServerReply(response.position());
}

void setup()
{
  //debugging
  Serial.begin(9600);
  //ustawianie sieci
  if(!ether.begin(sizeof Ethernet::buffer, macAddress[], 10))
    Serial.println("Ethernet is not accessible");
  else
    Serial.println("Ethernet - ok!")
  if(!ether.dhcpSetup())
  {
    Serial.println("DHCP setup unavailable - falling back to static IP");
    if(!ether.staticSetup(ipAddress))
      Serial.println("IP address is not available");
  }
  else
    Serial.println("DHCP - ok!");
  //ten tutaj linijek ustawia odczyt co sekunde
  measurement();
}

void loop()
{
  word pos = ether.packetLoop(ether.packetReceive());
  if(pos)
  {
    if(strstr((char *)Ethernet::buffer+pos),"GET / HTTP")
      temperatureView();
    else if(strstr((char *)Ethernet::buffer+pos),"GET /settings HTTP")
      settingsView();
    else if(strstr((char *)Ethernet::buffer+pos),"POST /settings HTTP")
      settingsPost((char *)Ethernet::buffer+pos));
    else if(strstr((char *)Ethernet::buffer+pos),"GET /history HTTP")
      historyView();
    else badRequest();
  }
}
