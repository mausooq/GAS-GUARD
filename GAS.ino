#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define MQ135_PIN A0
#define BUZZER_PIN D1
#define LED_PIN D2
#define THRESHOLD 300  // Define the threshold value

const char* ssid = "Thameem";       // Replace with your network SSID
const char* password = "11111111";  // Replace with your network password

ESP8266WebServer server(80);

void handleRoot() {
  int gasValue = analogRead(MQ135_PIN);
  String html = "<html><body>";
  html += "<h1>Gas Value: " + String(gasValue) + "</h1>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleGasValue() {
  int gasValue = analogRead(MQ135_PIN);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", String(gasValue));
}

void setup() {
  Serial.begin(115200);
  pinMode(MQ135_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the IP address to the Serial Monitor
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.on("/", handleRoot);
  server.on("/gas", handleGasValue);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  int gasValue = analogRead(MQ135_PIN);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
    digitalWrite(LED_PIN, HIGH);     // Turn on the LED
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
    digitalWrite(LED_PIN, LOW);      // Turn off the LED
  }

  server.handleClient();
  delay(1000);  // Wait for a second before the next read
}
