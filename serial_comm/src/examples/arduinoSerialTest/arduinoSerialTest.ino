//Arduino program to test CserialComm class

// Use pin 13 to flash on-baord led when receiving data
int led = 13;

// for incoming serial data
unsigned char inByte = 0;	

//set up
void setup() 
{
        Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
        pinMode(led, OUTPUT); // initialize the digital pin as an output.
        digitalWrite(led, LOW);
}

void loop() 
{
	// Wait for arrival of serial data 	
	if (Serial.available() > 0) 
      {
		// read the incoming byte:
		inByte = Serial.read();
            
		// say what you got:
		Serial.print("Arduino-Echo: ");
            Serial.println(inByte, DEC);
            
            //blink a led
            if ( inByte == 'a' )
            {
                  digitalWrite(led, HIGH); 
                  delay(500);
                  digitalWrite(led, LOW);
            }            
       }
}
