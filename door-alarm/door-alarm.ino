int ir = 7;
int buzz = 11;
int x;

void setup()
{
    Serial.begin(9600);
    pinMode(ir, INPUT);
    pinMode(buzz, OUTPUT);
}

void loop()
{
    x = digitalRead(ir);
    Serial.println(x);
    delay(1000);
    if (x == 0)
    {
        digitalWrite(buzz, LOW);
    }
    else
    {
        digitalWrite(buzz, HIGH);
        delay(50);
        digitalWrite(buzz, LOW);
        delay(50);
    }
}