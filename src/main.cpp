#include <BH1750.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Define pin numbers
#define DHTPIN 4
#define LED_PIN 2
#define BH1750_ADDRESS 0x23
#define BAUD_RATE 9600

// Initialize sensors
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter(BH1750_ADDRESS);


void setup() {
  // Start serial communication
  Serial.begin(BAUD_RATE);

  // Initialize DHT sensor
  dht.begin();

  // Initialize BH1750 sensor
  Wire.begin(21,22); //SCL, SDA
  lightMeter.begin();

  //initialize the LED pin as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Get temperature data every X seconds
  int delayX = 5; // Replace with the 3rd digit of your student ID
  float temperature = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" oC");
  delay(delayX * 1000);

  // Get humidity data every Y seconds
  int delayY = 0; // Replace with the 2nd digit of your student ID
  float humidity = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" RH");
  delay(delayY * 1000);

  // Get light sensor data every Z seconds
  int delayZ = 0; // Replace with the last digit of your student ID
  float lux = lightMeter.readLightLevel();
  Serial.print("Light = ");
  Serial.print(lux);
  Serial.println(" Lux");

  // Turn on LED if lux is above 400
  if (lux > 400) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Box opened forcefully!"); // Turn on LED if box is opened
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(delayZ * 1000);
}
