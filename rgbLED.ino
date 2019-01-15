int RED_PIN = D1;
int GREEN_PIN = D2;
int BLUE_PIN = D3;

int color = 100;

void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}


void loop() {
    showRGB(color);
}

void showRGB(int color) {
    int redIntensity;
    int greenIntensity;
    int blueIntensity;
    
    if (color <= 255)          // zone 1
    {
        redIntensity = 255 - color;    // red goes from on to off
        greenIntensity = color;        // green goes from off to on
        blueIntensity = 0;             // blue is always off
    }
    else if (color <= 511)     // zone 2
    {
        redIntensity = 0;                     // red is always off
        greenIntensity = 255 - (color - 256); // green on to off
        blueIntensity = (color - 256);        // blue off to on
    }
    else // color >= 512       // zone 3
    {
        redIntensity = (color - 512);         // red off to on
        greenIntensity = 0;                   // green is always off
        blueIntensity = 255 - (color - 512);  // blue on to off
    }
    
    analogWrite(RED_PIN, redIntensity);
    analogWrite(BLUE_PIN, blueIntensity);
    analogWrite(GREEN_PIN, greenIntensity);
}
