int ir = 7;
int led = 8;
int x;

void setup()
{
    Serial.begin(9600);
    pinMode(7, INPUT);
    pinMode(8, OUTPUT);
}

void loop()
{
    x = digitalRead(ir);
    Serial.println(x);
    delay(50);
    if (x == 0)
    {
        digitalWrite(8, LOW);
    }
    else
    {
        digitalWrite(8, HIGH);
    }
}