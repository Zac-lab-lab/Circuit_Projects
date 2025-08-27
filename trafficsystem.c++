// Setup up constants
const int carRed = 3; 
const int carYellow = 4; 
const int carGreen = 5; 

const int pedRed = 6;
const int pedGreen = 7;
const int buttonPed = 8;

bool buttonPressed = false; 

void setup() {
    pinMode(carRed, OUTPUT);
    pinMode(carYellow, OUTPUT);
    pinMode(carGreen, OUTPUT);
    pinMode(pedRed, OUTPUT);
    pinMode(pedGreen, OUTPUT);
    pinMode(buttonPed, INPUT_PULLUP); 
    // Initial State for Pedestrians and Cars
    digitalWrite(carGreen, HIGH);
    digitalWrite(carRed, LOW);
    digitalWrite(carYellow, LOW);
    digitalWrite(pedRed, HIGH);
    digitalWrite(pedGreen, LOW);
}

void loop() {
    // Read button state
    if (digitalRead(buttonPed) == LOW) { 
        buttonPressed = true; 
    }

    // Normal Car Cycle
    digitalWrite(carGreen, HIGH);
    digitalWrite(carYellow, LOW);
    digitalWrite(carRed, LOW);
    delay(10000);
    digitalWrite(carGreen, LOW);

    digitalWrite(carYellow, HIGH); 
    delay(1000); 
    digitalWrite(carYellow, LOW); 

    // Make sure car green is OFF before turning car red ON
    digitalWrite(carGreen, LOW);
    digitalWrite(carRed, HIGH);

    if (buttonPressed) {
        // Pedestrian Cycle
        digitalWrite(pedRed, LOW); 
        digitalWrite(pedGreen, HIGH);
        delay(3000);
    
        // Blink ped green for warning 
        for (int i = 0; i < 3; i++) { 
            digitalWrite(pedGreen, LOW);
            delay(300);
            digitalWrite(pedGreen, HIGH);
            delay(300);
        }

        // Make sure to turn ped green OFF and ped red ON after cycle
        digitalWrite(pedGreen, LOW); 
        digitalWrite(pedRed, HIGH); 
    } else {
        // If no button pressed, keep pedestrian red
        digitalWrite(pedRed, HIGH);
        digitalWrite(pedGreen, LOW);
    }

    buttonPressed = false; // reset button pressed
    delay(2000); // Cars red time
    digitalWrite(carRed, LOW); 
}
