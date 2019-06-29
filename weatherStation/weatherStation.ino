#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11

#define RS  7
#define E   6
#define D4  5
#define D5  4
#define D6  3
#define D7  2

#define DELAY 10000

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
DHT sensor(DHTPIN,DHTTYPE);

float temperature,humidity;

void setup() {
  lcd.begin(16,2);
  sensor.begin();
  Serial.begin(9600);
  Serial.println("Setup finished");
}

void loop() {
    readSensor();
    serialPort();
    displayLCD();
    delay(DELAY);
}

/**
 * Read temperature and humidity from DHT11 sensor
 */
void readSensor(){
  temperature = sensor.readTemperature();
  humidity = sensor.readHumidity();
}

/**
 * Send temperature and humidity to serial port
 */
void serialPort(){
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" ºC");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

/**
 * Display temperature and humidity on LCD
 */
void displayLCD(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.setCursor(6,0);
  lcd.print(temperature);
  lcd.setCursor(12,0);
  lcd.print("C");

  lcd.setCursor(0,1);
  lcd.print("HUMR:");
  lcd.setCursor(6,1);
  lcd.print(humidity);
  lcd.setCursor(12,1);
  lcd.print("%");
}
