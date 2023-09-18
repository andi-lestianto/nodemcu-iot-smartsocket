#include <Arduino.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "smart-electricsocket-default-rtdb.asia-southeast1.firebasedatabase.app"
#define FIREBASE_AUTH "AIzaSyCuur0IA__hKe-VQQeL0eQ36BNl20bt08M"
#define WIFI_SSID "CatCave"
#define WIFI_PASSWORD "PasswordWifi12"
 
FirebaseData firebaseData;
 
int relay1 = 0;
int relay2 = 4;
int relay3 = 5;
int relay4 = 16;

int lamp1 = 14;
int lamp2 = 12;
int lamp3 = 13;
int lamp4 = 15;

int lampwifi = 2;


void setup() {
  Serial.begin(115200);

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);

  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH); 
  
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, HIGH); 

  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, HIGH); 

  pinMode(lamp1, OUTPUT);
  digitalWrite(lamp1, LOW);

  pinMode(lamp2, OUTPUT);
  digitalWrite(lamp2, LOW); 
  
  pinMode(lamp3, OUTPUT);
  digitalWrite(lamp3, LOW); 

  pinMode(lamp4, OUTPUT);
  digitalWrite(lamp4, LOW); 

  pinMode(lampwifi, OUTPUT);
  digitalWrite(lampwifi, LOW);
  
  konekWifi();
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}
 
void konekWifi() {
  Serial.println("Konek ke wifi");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    digitalWrite(lampwifi, HIGH);
    Serial.print(".");
      delay(250);
    digitalWrite(lampwifi, LOW);
    Serial.print(".");
   
  }
  Serial.println("Sukses terkoneksi wifi!");
  digitalWrite(lampwifi, HIGH);
  Serial.println("IP Address:");
  Serial.println(WiFi.localIP());
  
}
 
void loop() {

  if(Firebase.getBool(firebaseData, "/data/socket1/value")) {
    bool status = firebaseData.boolData();
    if (status) {
      Serial.println("relay 1 true");
      digitalWrite(relay1, LOW);
      digitalWrite(lamp1, HIGH);
    } else {
      Serial.println("relay 1 false");
      digitalWrite(relay1, HIGH);
      digitalWrite(lamp1, LOW);

    }
  }

  if(Firebase.getBool(firebaseData, "/data/socket2/value")) {
    bool status = firebaseData.boolData();
    if (status) {
      Serial.println("relay 2 true");
      digitalWrite(relay2, LOW);
      digitalWrite(lamp2, HIGH);
    } else {
      Serial.println("relay 2 false");
      digitalWrite(relay2, HIGH);
      digitalWrite(lamp2, LOW);
    }
  }

  if(Firebase.getBool(firebaseData, "/data/socket3/value")) {
    bool status = firebaseData.boolData();
    if (status) {
      Serial.println("relay 3 true");
      digitalWrite(relay3, LOW);
      digitalWrite(lamp3, HIGH);
    } else {
      Serial.println("relay 3 false");
      digitalWrite(relay3, HIGH);
      digitalWrite(lamp3, LOW);
    }
  }

  if(Firebase.getBool(firebaseData, "/data/socket4/value")) {
    bool status = firebaseData.boolData();
    if (status) {
      Serial.println("relay 4 true");
      digitalWrite(relay4, LOW);
      digitalWrite(lamp4, HIGH);
    } else {
      Serial.println("relay 4 false");
      digitalWrite(relay4, HIGH);
      digitalWrite(lamp4, LOW);
    }
  }
}


