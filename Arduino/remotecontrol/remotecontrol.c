/*
   Web client sketch for IDE v1.0.1 and w5100/w5200
   Uses GET method.
   Posted October 2012 by SurferTim
   Last modified August 23, 2013
*/

#include <SPI.h>
#include <Ethernet.h>

// this must be unique
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// change to your network settings
IPAddress ip(192,168,1,147);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// change to your server
//IPAddress server(74,125,227,16); // Google
//IPAddress server(61,135,169,105); // Baidu
//IPAddress server(50,31,152,47);
IPAddress server(192,168,1,112);
//IPAddress server(192,168,1,103); // Google
//Change to your domain name for virtual servers
//char serverName[] = "www.geeknimo.com";
// If no domain name, use the ip address above
char serverName[] = "192.168.1.112";

// change to your server's port
int serverPort = 80;

EthernetClient client;
int remote_data=1;
int loopCount = 0;
char pageAdd[64];

void setup() {
  Serial.begin(9600);

  // disable SD SPI
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);

  // Start ethernet
  Serial.println(F("Starting ethernet..."));
  Ethernet.begin(mac, ip, gateway, gateway, subnet);

  // If using dhcp, comment out the line above 
  // and uncomment the next 2 lines

  // if(!Ethernet.begin(mac)) Serial.println(F("failed"));
  // else Serial.println(F("ok"));
  digitalWrite(10,HIGH);

  Serial.println(Ethernet.localIP());

  delay(2000);
  Serial.println(F("Ready"));
}

void loop()
{
  if(loopCount < 30)
  {
    // if loopCount is less than 30, just delay a second
    delay(1000);
  }
  else
  {
    // every thirty seconds this runs
    loopCount = 0;

    // Modify next line to load different page
    // or pass values to server
    //sprintf(pageAdd,"/",totalCount);

    //sprintf(pageAdd,"/arduino.php?test=%u",totalCount);
    //sprintf(pageAdd,"/question2answer/index.php",totalCount);
    sprintf(pageAdd,"/remotecontrol/index.php?data=%u",remote_data);
    Serial.print(pageAdd);
    if(!getPage(server,serverPort,pageAdd)) Serial.print(F("Fail "));
    else Serial.print(F("Pass "));
  }    

  loopCount++;
}

byte getPage(IPAddress ipBuf,int thisPort, char *page)
{
  int inChar;
  char outBuf[128];

  Serial.print(F("connecting..."));

  if(client.connect(ipBuf,thisPort))
  {
    Serial.println(F("connected"));

    sprintf(outBuf,"GET %s HTTP/1.1",page);
    client.println(outBuf);
    sprintf(outBuf,"Host: %s",serverName);
    client.println(outBuf);
    client.println(F("Connection: close\r\n"));
  } 
  else
  {
    Serial.println(F("failed"));
    return 0;
  }

  // connectLoop controls the hardware fail timeout
  int connectLoop = 0;

  while(client.connected())
  {
    while(client.available())
    {
      inChar = client.read();
      //Serial.write(inChar);
      // set connectLoop to zero if a packet arrives
      connectLoop = 0;
    }

    connectLoop++;

    // if more than 10000 milliseconds since the last packet
    if(connectLoop > 10000)
    {
      // then close the connection from this end.
      Serial.println();
      Serial.println(F("Timeout"));
      client.stop();
    }
    // this is a delay for the connectLoop timing
    delay(1);
  }

  Serial.println();

  Serial.println(F("disconnecting."));
  // close client end
  client.stop();

  return 1;
}
