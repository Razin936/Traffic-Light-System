class TrafficLightSystem {
private:
    // Define the pins for traffic and pedestrian lights
    const int carGreen = 8;  // Car green light
    const int carYellow = 7; // Car yellow light
    const int carRed = 4;    // Car red light
    const int pedGreen = 11; // Pedestrian green light
    const int pedRed = 12;   // Pedestrian red light
    const int buttonPin = 13; // Pedestrian button

    // Variables to store the button state
    int buttonState = 0;
    bool pedestrianRequest = false;

    // Timing intervals (in milliseconds)
    const int pedestrianGreenTime = 8000; // Pedestrian green light time (8 seconds)
    const int yellowTime = 3000;          // Yellow light time (3 seconds)

public:
    // Constructor
    TrafficLightSystem() {
        // Set up the pins as outputs
        pinMode(carGreen, OUTPUT);
        pinMode(carYellow, OUTPUT);
        pinMode(carRed, OUTPUT);
        pinMode(pedGreen, OUTPUT);
        pinMode(pedRed, OUTPUT);
        pinMode(buttonPin, INPUT_PULLUP); // Button for pedestrian

        // Initialize with car green and pedestrian red
        switchToCarGreen();
    }

    // Method to handle the main traffic system logic
    void update() {
        // Read the state of the pedestrian button
        buttonState = digitalRead(buttonPin);

        if (buttonState == LOW) {
            // Button pressed, request pedestrian light change
            pedestrianRequest = true;
        }

        // Control the traffic light system
        if (pedestrianRequest) {
            // Handle pedestrian crossing request
            switchToPedestrianGreen();
            pedestrianRequest = false;
        } else {
            switchToCarGreen();
        }
        delay(10000);
    }

private:
    // Method to switch to car green light and pedestrian red light
    void switchToCarGreen() {
        digitalWrite(carGreen, HIGH);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, LOW);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

    // Method to switch to car yellow light and pedestrian red light
    void switchToCarYellow() {
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, HIGH);
        digitalWrite(carRed, LOW);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

    // Method to switch to car red light and pedestrian red light
    void switchToCarRed() {
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, HIGH);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

    // Method to switch to pedestrian green light and car red light
    void switchToPedestrianGreen() {
        // First, switch car light to yellow before stopping traffic
        switchToCarYellow();
        delay(yellowTime); // Wait for 3 seconds on yellow

        // Now, switch to pedestrian green and car red
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, HIGH);
        digitalWrite(pedGreen, HIGH);
        digitalWrite(pedRed, LOW);

        // Pedestrian green for 8 seconds
        delay(pedestrianGreenTime);

        // After pedestrian crossing, switch back to car yellow, then car green
        switchToCarYellow();
        delay(yellowTime); // Wait for 3 seconds on yellow

        // Switch back to car green
        switchToCarGreen();
    }
};

TrafficLightSystem trafficSystem; // Instantiate the traffic light system

void setup() {
    // Initialize the traffic light system (constructor handles pin setup)
}

void loop() {
    // Update the traffic light system
    trafficSystem.update();
}
