#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

// Define SoftwareSerial pins for GPS communication
SoftwareSerial gpsSerial(4, 3); // RX=4, TX=3 (connect GPS TX to 4, GPS RX to 3)
TinyGPSPlus gps; // Create TinyGPSPlus object

void setup() {
  // Start the hardware serial for debugging
  Serial.begin(9600);
  // Start the software serial for GPS module (try 38400 if 9600 doesn't work)
  gpsSerial.begin(9600); // Default baud rate for NEO-M8N is often 9600 or 38400
  Serial.println("Starting GPS...");
}


void displayGPSInfo() {
  // Check if location is valid
  if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6); // Latitude in degrees
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6); // Longitude in degrees
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters()); // Altitude in meters
    Serial.print("Speed: ");
    Serial.println(gps.speed.kmph()); // Speed in km/h
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value()); // Number of satellites
    Serial.print("HDOP: ");
    Serial.println(gps.hdop.hdop(), 2); // Horizontal Dilution of Precision
  } else {
    Serial.println("Location: INVALID");
  }

  // Check if date and time are valid
  if (gps.date.isValid() && gps.time.isValid()) {
    Serial.print("Date: ");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.println(gps.date.year());
    Serial.print("Time (UTC): ");
    if (gps.time.hour() < 10) Serial.print("0");
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print("0");
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print("0");
    Serial.println(gps.time.second());
  } else {
    Serial.println("Date/Time: INVALID");
  }

  Serial.println();
  delay(1000); // Update every second
}

void loop() {

  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      displayGPSInfo();
    }
  }

  // If no data is received for 5 seconds, print a warning
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("No GPS data detected. Check wiring or baud rate.");
    while (true); // Halt execution
  }
}
