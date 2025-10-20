
#include <Adafruit_NeoPixel.h>

 // Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN 9

 // How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int delayval = 333; // delay

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

void setup() {
  // Initialize TCS3200 pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set TCS3200 frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
  pixels.begin(); // Initialize the NeoPixels.

  pixels.setBrightness(64);
}

void loop() {
  int frequency = 0;
  int red, green, blue;

  // Select Red channel from the sensor
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Read the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25, 72, 255, 0);
  // Clamp the color strength to the range [0, 255]
  red = constrain(frequency, 0, 255);

  // Print the RED color strength to the serial monitor
  Serial.print("R = "); // print name
  Serial.print(red);    // print RED color strength
  Serial.print(", ");   // print seperator
  delay(100);

  // Select Green channel from the sensor
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Read the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 30, 90, 255, 0);
  // Clamp the color strength to the range [0, 255]
  green = constrain(frequency, 0, 255);

  // Print the GREEN color strength to the serial monitor
  Serial.print("G = "); // print name
  Serial.print(green);  // print GREEN color strength
  Serial.print(", ");   // print seperator
  delay(100);

  // Select Blue channel from the sensor
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Read the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Remap the value of the frequency to the RGB Model of 0 to 255
  frequency = map(frequency, 25,70,255,0);
  // Clamp the color strength to the range [0, 255]
  blue = constrain(frequency, 0, 255);

  // Print the BLUE color strength to the serial monitor
  Serial.print("B = ");    // print name
  Serial.print(frequency); // print RED color frequency
  Serial.println();        // print a newline

  // Set the pixel colors
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show(); // send the updated pixel colors to the led strip.

  delay(100);
}
