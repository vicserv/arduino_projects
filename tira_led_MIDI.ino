
#define DO 5
#define RE 6
#define MI 7
#define FA 8
#define SOL 9
#define LA 10
#define SI 11
#define DO2 12

long NOTA;

bool SDO = 1;
bool SRE = 1;
bool SMI = 1;
bool SFA = 1;
bool SSOL = 1;
bool SLA = 1;
bool SSI = 1;
bool SDO2 = 1;

void setup()

{
    Serial.begin(19200);

    pinMode(DO, OUTPUT);
    pinMode(RE, OUTPUT);
    pinMode(MI, OUTPUT);
    pinMode(FA, OUTPUT);
    pinMode(SOL, OUTPUT);
    pinMode(LA, OUTPUT);
    pinMode(SI, OUTPUT);
    pinMode(DO2, OUTPUT);

    while (NOTA != 64)
    {
        NOTA = Serial.read();
    }
    digitalWrite(MI, LOW);
}

void loop()

{
    NOTA = Serial.read();

    // DO
    if (NOTA == 60)

    {
        digitalWrite(DO, SDO);
        SDO = !SDO;
    }
    // RE
    if (NOTA == 62)

    {
        digitalWrite(RE, SRE);
        SRE = !SRE;
    }
    // MI
    if (NOTA == 64)

    {
        digitalWrite(MI, SMI);
        SMI = !SMI;
    }
    // FA
    if (NOTA == 65)

    {
        digitalWrite(FA, SFA);
        SFA = !SFA;
    }
    // SOL
    if (NOTA == 67)

    {
        digitalWrite(SOL, SSOL);
        SSOL = !SSOL;
    }
    // LA
    if (NOTA == 69)

    {
        digitalWrite(LA, SLA);
        SLA = !SLA;
    }
    // SI
    if (NOTA == 71)

    {
        digitalWrite(SI, SSI);
        SSI = !SSI;
    }
    // DO2
    if (NOTA == 72)

    {
        digitalWrite(DO2, SDO2);
        SDO2 = !SDO2;
    }
}
