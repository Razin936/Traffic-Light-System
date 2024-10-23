class TrafficLightSystem {
private:
    
    const int carGreen = 8;  
    const int carYellow = 7; 
    const int carRed = 4;    
    const int pedGreen = 11; 
    const int pedRed = 12;   
    const int buttonPin = 13; 

    
    int buttonState = 0;
    bool pedestrianRequest = false;

   
    const int pedestrianGreenTime = 8000; 
    const int yellowTime = 3000;          

public:
   
    TrafficLightSystem() {
        
        pinMode(carGreen, OUTPUT);
        pinMode(carYellow, OUTPUT);
        pinMode(carRed, OUTPUT);
        pinMode(pedGreen, OUTPUT);
        pinMode(pedRed, OUTPUT);
        pinMode(buttonPin, INPUT_PULLUP); 

       
        switchToCarGreen();
    }

    
    void update() {
      
        buttonState = digitalRead(buttonPin);

        if (buttonState == LOW) {
            ange
            pedestrianRequest = true;
        }

      m
        if (pedestrianRequest) {
            
            switchToPedestrianGreen();
            pedestrianRequest = false;
        } else {
            switchToCarGreen();
        }
        delay(10000);
    }

private:
   
    void switchToCarGreen() {
        digitalWrite(carGreen, HIGH);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, LOW);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

  
    void switchToCarYellow() {
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, HIGH);
        digitalWrite(carRed, LOW);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

    
    void switchToCarRed() {
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, HIGH);
        digitalWrite(pedGreen, LOW);
        digitalWrite(pedRed, HIGH);
    }

    
    void switchToPedestrianGreen() {
       
        switchToCarYellow();
        delay(yellowTime); 

       
        digitalWrite(carGreen, LOW);
        digitalWrite(carYellow, LOW);
        digitalWrite(carRed, HIGH);
        digitalWrite(pedGreen, HIGH);
        digitalWrite(pedRed, LOW);

       
        delay(pedestrianGreenTime);

        
        switchToCarYellow();
        delay(yellowTime); 

       
        switchToCarGreen();
    }
};

TrafficLightSystem trafficSystem; 

void setup() {
    
}

void loop() {
    
    trafficSystem.update();
}
