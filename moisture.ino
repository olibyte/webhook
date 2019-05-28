int analogIn = A4; //Pin set to A4

void setup() {
    pinMode(analogIn, INPUT);
}

void loop() {
    // Get some data, convert ADC units to percentage, publish to ThingSpeak channel via Particle Webhook event API 

    float moisture_percentage;
    int sensor_analog;
    sensor_analog = analogRead(analogIn); //get moisture reading
    moisture_percentage = (sensor_analog/4095.00) * 100; //Convert
    String data = String(moisture_percentage); //Convert to string

    Particle.publish("moisture", data, PRIVATE); //send data to the web
    // Wait 30 seconds
    delay(30000);
}