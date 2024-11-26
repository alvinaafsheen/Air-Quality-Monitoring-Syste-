#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/db77626f-4b35-47ce-9dfd-d4852a3afec5 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  String message;
  CloudTemperatureSensor temp;
  int air;
  CloudRelativeHumidity humi;
  bool buzzer;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
#include "DHT.h"
#define DHTPIN D2    
#define DHTTYPE DHT11 
#include "thingProperties.h"
DHT dht(D2, DHT11);
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  dht.begin();
  pinMode(D1,OUTPUT);//buzzer
  pinMode(A0,INPUT);//air 
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection); setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
}
void loop() {
   ArduinoCloud.update();
   float h = dht.readHumidity();
   float t = dht.readTemperature();
  Serial.println("Humidity: ");
  Serial.println(h);
  Serial.println("Temperature: ");
  Serial.println(t);
  temp=t;
  humi=h;
  long a=analogRead(A0);
  Serial.println("Air Quality: ");
  Serial.println(a); air=a;
if(a<=250)  {
     message="Air quality is good";
  }
  else if(a>250)  {
     message="Air quality is bad";
     for(int i=0;i<10;i++)     {
     digitalWrite(D1,1);
     delay(500);
      digitalWrite(D1,0); 
     }
}
}



/*
  Since Air is READ_WRITE variable, onAirChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAirChange()  {
  // Add your code here to act upon Air change
}

/*
  Since Buzzer is READ_WRITE variable, onBuzzerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBuzzerChange()  {
  // Add your code here to act upon Buzzer change
}


/*
  Since Humi is READ_WRITE variable, onHumiChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumiChange()  {
  // Add your code here to act upon Humi change
}



/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}

