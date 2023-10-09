#include <sim808.h>
#include <Arduino.h>
#include <DFRobot_sim808.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <HardwareSerial.h>
HardwareSerial mySerial(1); 

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Mobile phone number,need to change
#define PHONE_NUMBER "5547996952009"  
 
//The content of messages sent
#define MESSAGE  "Ultrapassou distancia estabelecida!!! \n localizacao atual via google maps:"
#define MESSAGEspeed  "Ultrapassou velocidade estabelecida!!! \n localizacao atual via google maps:"
char MESSAGE2[40] = "https://www.google.com/maps/@";
char latitude[32]="";
char longitude[32]="";
char speed_sms[32]="";
String latitude6="";
String longitude6="";
const double LATITUDE_REFERENCE = -27.154139; //Latitude de referência para calcular o distanciamento do dispositivo
const double LONGITUDE_REFERENCE = -48.571413; //Longitude de referência para calcular o distanciamento do dispositivo
const double MAX_DISTANCE = 500; //Distância limite usada para disparar SMS de alerta de distanciamento, medida em metros
const double MAX_SPEED = 14; //velocidade limite usada para disparar SMS de alerta de velocidade, medida em km/s
bool flag= true;

DFRobot_SIM808 sim808(&mySerial);

//#include <String.h>

void showDisplay(String latitude, String longitude, float velocidade){
display.clearDisplay();
display.setCursor(0, 1);
display.print("latitude= ");
display.println(latitude);
display.print("longitude= ");
display.println(longitude);
display.print("velocidade= ");
display.println(velocidade);
display.display(); 
}
 
//Calcula a distância em que o dispositivo está, levando em consideração a curvatura da terra (valor retornado em metros)
double getDistance(float lat, float lon)
{
  double dist = 60 * ((acos(sin(LATITUDE_REFERENCE*(PI/180)) * sin(lat*(PI/180)) + cos(LATITUDE_REFERENCE*(PI/180)) * cos(lat*(PI/180)) * cos(abs((lon-LONGITUDE_REFERENCE)) * (PI/180)))) * (180/PI));
  return dist*1852;
}

//Verifica se o dispositivo ultrapassou o limite de distância
bool deviceIsTooFar(float lat, float lon, String *distance)
{
  double dist = getDistance(lat, lon);

  *distance = String(dist);

  if(dist > MAX_DISTANCE)
      return true;
        
  return false;
}

//Verifica se o dispositivo ultrapassou o limite de velocidade
bool deviceIsTooFast(float speed)
{
  if(speed > MAX_SPEED)
      return true;
        
  return false;
}

void setup()
{
  //mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);    // the GPRS baud rate 


  //mySerial.begin(9600);
  mySerial.begin(9600,SERIAL_8N1,13,14);
  delay(200);
  //Serial.print("setup");
  while(!sim808.init()) {
      delay(100);
      Serial.print("Sim808 init error\r\n");
  }  
  Serial.println("Sim808 init success");
  Serial.println("Start to send message ...");
  
//************* Turn on the GPS power************
 sim808.attachGPS();
  //// configuracao display
 if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("display ligado!");
  display.display(); 

}
 
void loop()
{
sim808.getGPS();
//sim808.attachGPS();
if (sim808.getGPS()) {
  Serial.print(sim808.GPSdata.year);
  Serial.print("/");
  Serial.print(sim808.GPSdata.month);
  Serial.print("/");
  Serial.print(sim808.GPSdata.day);
  Serial.print(" ");
  Serial.print(sim808.GPSdata.hour);
  Serial.print(":");
  Serial.print(sim808.GPSdata.minute);
  Serial.print(":");
  Serial.print(sim808.GPSdata.second);
  Serial.print(":");
  Serial.println(sim808.GPSdata.centisecond);
  
  Serial.print("latitude :");
  Serial.println(sim808.GPSdata.lat,6);
  float latitudef=sim808.GPSdata.lat;
  //memcpy(latitude6, &latitudef, sizeof(double));
  latitude6= String(latitudef);
  
  int n = latitude6.length();
  char latitude_char[n + 1];
  
  // copiando conteudo da string para vetor de char
  strcpy(latitude_char, latitude6.c_str());
  strncat(latitude,latitude_char, 6);
  sim808.latitudeConverToDMS();
  Serial.print("latitude :");
  Serial.print(sim808.latDMS.degrees);
  Serial.print("\^");
  Serial.print(sim808.latDMS.minutes);
  Serial.print("\'");
  Serial.print(sim808.latDMS.seconeds,6);
  Serial.println("\"");
  Serial.print("longitude :");
  Serial.println(sim808.GPSdata.lon,6);
  
  float longitudef=sim808.GPSdata.lon;
  longitude6= String(longitudef);
  
  int n2 = longitude6.length();
  char longitude_char[n2 + 1];
  
  // copiando conteudo da string para vetor de char
  strcpy(longitude_char, longitude6.c_str());
  strncat(longitude,longitude_char, 6);
  
  sim808.LongitudeConverToDMS();
  Serial.print("longitude :");
  Serial.print(sim808.longDMS.degrees);
  Serial.print("\^");
  Serial.print(sim808.longDMS.minutes);
  Serial.print("\'");
  Serial.print(sim808.longDMS.seconeds,6);
  Serial.println("\"");
  Serial.print("speed_kph :");
  Serial.println(sim808.GPSdata.speed_kph);
  float speed = sim808.GPSdata.speed_kph;
  SendData(speed, longitudef, latitudef );
  Serial.print("heading :");
  Serial.println(sim808.GPSdata.heading);

  
  char menos[]="-teste";
  strncat(MESSAGE2,menos, 1);
  strncat(MESSAGE2,latitude,10);
  char virgula[]=",15zteste";
  strncat(MESSAGE2,virgula, 1);
  strncat(MESSAGE2,menos, 1);
  strncat(MESSAGE2,longitude,10);
  strncat(MESSAGE2,virgula, 4);
  Serial.print("localizacao via google maps: ");
  Serial.print(MESSAGE2);
  
  ////    mostra display    /////////
  showDisplay(latitude,longitude, speed);
  String distance;
  if(deviceIsTooFar(latitudef, longitudef, &distance)){
      Serial.print("device Is Too Far!! ");
      flag=false;
      ////    envio SMS    /////////
      sim808.sendSMS(PHONE_NUMBER,MESSAGE); 
      sim808.sendSMS(PHONE_NUMBER,MESSAGE2); 
    display.println("device Is Too Far!!!");
    display.display(); 
    
  }
  if(deviceIsTooFast(speed)){
    String MESSAGE3= "velocidade= " + char(speed);
    // copiando conteudo da string para vetor de char
    Serial.print("device Is Too Fast!! ");
    strcpy(speed_sms, MESSAGE3.c_str());
    ////    envio SMS    /////////
    sim808.sendSMS(PHONE_NUMBER,MESSAGEspeed); 
    sim808.sendSMS(PHONE_NUMBER,MESSAGE2); 
    sim808.sendSMS(PHONE_NUMBER,speed_sms);
    display.clearDisplay();
    display.setCursor(0, 1);
    display.println("velocidade acima!!!");
    display.println("velocidade= ");
    display.println(speed);
    display.display(); 
    
  }
  
  //************* Turn off the GPS power ************
  //sim808.detachGPS();
    
}
}
void SendData(float speed, float longitude, float latitude)
{
  mySerial.println("AT");
  delay(1000);

  mySerial.println("AT+CPIN?");
  delay(1000);

  mySerial.println("AT+CREG?");
  delay(1000);

  mySerial.println("AT+CGATT?");
  delay(1000);

  mySerial.println("AT+CIPSHUT");
  delay(1000);

  mySerial.println("AT+CIPSTATUS");
  delay(2000);

  mySerial.println("AT+CIPMUX=0");
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CSTT=\tim.com.br");//start task and setting the APN,
  delay(1000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIICR");//bring up wireless connection
  delay(3000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIFSR");//get local IP adress
  delay(2000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSPRT=0");
  delay(3000);
 
  ShowSerialData();
  
  mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");//start up the connection
  delay(6000);
 
  ShowSerialData();
 
  mySerial.println("AT+CIPSEND");//begin send data to remote server
  delay(4000);
  ShowSerialData();
  
    //String str="GET http://api.thingspeak.com/update?api_key=KTQKNAQEBQAEXZGUH0J&field1=" + String(temp);
     //String getData = "GET /update?api_key="+ API +"&field1="+Latitude+"&field2="+Longitude;
    String str="GET http://api.thingspeak.com/update?api_key=KNAQEBQAEXZGUH0J&field1=" + String(speed)+"&field2=-" + String(longitude)+"&field3=-" + String(latitude);
  mySerial.println(str);//begin send data to remote server

  //String str2="GET http://api.thingspeak.com/update?api_key=KNAQEBQAEXZGUH0J&field2=" + String(longitude);
  //mySerial.println(str2);//begin send data to remote server
  
  delay(4000);
  ShowSerialData();

  mySerial.println((char)26);//sending
  delay(5000);//waitting for reply, important! the time is base on the condition of internet 
  mySerial.println();
 
  ShowSerialData();
  
 
  mySerial.println("AT+CIPSHUT");//close the connection
  delay(100);
  ShowSerialData();
} 
void ShowSerialData()
{
  while(mySerial.available()!=0)
    Serial.write(mySerial.read());
}
