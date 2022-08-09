void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        WAIT_TIMEOUT
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan
    // su valor entre llamadas a task1)
    static uint8_t btn1StateOld = LOW;
    static uint8_t btn2StateOld =  LOW;


    // Constantes

    constexpr uint32_t INTERVAL = 1000;
    constexpr uint8_t button1Pin = 12;
    constexpr uint8_t button2Pin = 13;
    constexpr uint8_t ledRed = 14;
    constexpr uint8_t ledGreen = 25;
    constexpr uint8_t ledBlue = 26;
    constexpr uint8_t ledYellow = 27;

    // MÁQUINA de ESTADOS

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        pinMode(button1Pin, INPUT_PULLUP);
        pinMode(button2Pin, INPUT_PULLUP);
        pinMode(ledRed, OUTPUT);
        pinMode(ledGreen, OUTPUT);
        pinMode(ledBlue, OUTPUT);
        pinMode(ledYellow, OUTPUT);
        task1State = Task1States::WAIT_TIMEOUT;

        break;
    }
    case Task1States::WAIT_TIMEOUT:
    {
        uint8_t btn1State = digitalRead(button1Pin);
        uint8_t btn2State = digitalRead(button2Pin);
        uint32_t currentTime = millis();


        if( (btn1State != btn1StateOld) || (btn2State != btn2StateOld) ){
                    btn1StateOld = btn1State;
                    btn2StateOld = btn2State;


                    // Evento 2
                    if ( (btn1State == LOW) && (btn2State == LOW)){
                        digitalWrite(ledGreen, LOW);
                        digitalWrite(ledBlue, LOW);
                        digitalWrite(ledYellow, LOW);
                        digitalWrite(ledRed, HIGH);
                        printf("Red ON\n");
                    }
                    // Evento 3
                    if ( (btn1State == LOW) && (btn2State == HIGH)){
                        digitalWrite(ledGreen, HIGH);
                        digitalWrite(ledBlue, LOW);
                        digitalWrite(ledYellow, LOW);
                        digitalWrite(ledRed, LOW);
                        printf("Green ON\n");
                    }
                    if ( (btn1State == HIGH) && (btn2State == LOW)){
                        digitalWrite(ledGreen, LOW);
                        digitalWrite(ledBlue, HIGH);
                        digitalWrite(ledYellow, LOW);
                        digitalWrite(ledRed, LOW);
                        printf("Blue ON\n");
                    }
                    if ( (btn1State == HIGH) && (btn2State == HIGH)){
                        digitalWrite(ledGreen, LOW);
                        digitalWrite(ledBlue, LOW);
                        digitalWrite(ledYellow, HIGH);
                        digitalWrite(ledRed, LOW);
                        printf("Yellow ON\n");
                    }

        }
        
        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}