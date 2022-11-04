

long tiempo;        // Tiempo de ida y vuelta del sonido
int disparador = 4; // triger
int entrada = 5;    // echo
int led = 10;       // led

int sensor1 = 21; // Sensor1
int sensor2 = 20; // Sensor2
int sensor3 = 19; // Sensor3
int sensor4 = 18; // Sensor4

int valor1 = 0; // valor de almacenamiento del sensor1
int valor2 = 0; // valor de almacenamiento del sensor2
int valor3 = 0; // valor de almacenamiento del sensor3
int valor4 = 0; // valor de almacenamiento del sensor4

int motor1 = 9; // Motor 1
int motor2 = 6; // Motor 2

float distancia; // variable distancia

void setup()
{
    pinMode(disparador, OUTPUT); // Asigna disparador como salida
    pinMode(entrada, INPUT);     // Asigna entrada como entrada
    pinMode(led, OUTPUT);        // Asigna el led como una salida

    // Sensosres
    pinMode(sensor1, INPUT); // Asigna sensor1 como entrada
    pinMode(sensor2, INPUT); // Asigna sensos2 como entrada
    pinMode(sensor3, INPUT); // Asigna sensor3 como entrada
    pinMode(sensor4, INPUT); // Asigna sensor4 como entrada

    Serial.begin(9600); // Inicia serial
}

void loop()
{
    // lanzamos un pulso de diez milisegundo
    digitalWrite(disparador, HIGH);
    delayMicroseconds(10);
    digitalWrite(disparador, LOW);

    // medimos el pulso de respuesta
    tiempo = (pulseIn(entrada, HIGH) / 2); // PulseIn mide el pulso de la entrada
    // como el pulso es de ida y vuelta dividimos entre 2
    // ahora calcularemos la distancia en cm
    // sabiendo que el espacio es igual a la velocidad por el tiempo
    // y que la velocidad del sonido es de 343m/s y que el tiempo lo
    // tenemos en millonesimas de segundo
    distancia = float(tiempo * 0.0343);

    // y lo mostramos por el puerto serie una vez por segundo
    Serial.println(distancia);
    if (distancia < 6)
    {
        analogWrite(motor1, 0);  // VELOCIDAD MOTOR 1
        analogWrite(motor2, 0);  // VELOCIDAD MOTOR 2
        digitalWrite(led, HIGH); // Eenciende el led
        delay(300);
        digitalWrite(led, LOW); // Apagar el led
        delay(300);
        digitalWrite(led, HIGH); // Eenciende el led
        delay(300);
        digitalWrite(led, LOW); // Apagar el led
        delay(300);
    }
    else
    {

        valor1 = digitalRead(sensor1); // lee el valor del sensor 1 y lo guarda en valor1
        valor2 = digitalRead(sensor2); // lee el valor del sensor 2 y lo guarda en valor2
        valor3 = digitalRead(sensor3); // lee el valor del sensor 3 y lo guarda en valor3
        valor4 = digitalRead(sensor4); // lee el valor del sensor 4 y lo guarda en valor4

        // SEGUIDOR DE LINEA

        // PROPUESTA 1
        if (valor1 == 0 && valor2 == 1 && valor3 == 0 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 250); // VELOCIDAD MOTOR 1
            analogWrite(motor2, 50);  // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 1 && valor2 == 0 && valor3 == 0 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 250); // VELOCIDAD MOTOR 1
            analogWrite(motor2, 50);  // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 1 && valor2 == 1 && valor3 == 0 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 250); // VELOCIDAD MOTOR 1
            analogWrite(motor2, 50);  // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 0 && valor2 == 1 && valor3 == 1 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 250); // VELOCIDAD MOTOR 1
            analogWrite(motor2, 250); // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 0 && valor2 == 0 && valor3 == 0 && valor4 == 1) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 50);  // VELOCIDAD MOTOR 1
            analogWrite(motor2, 250); // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 0 && valor2 == 0 && valor3 == 1 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 50);  // VELOCIDAD MOTOR 1
            analogWrite(motor2, 250); // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 0 && valor2 == 0 && valor3 == 1 && valor4 == 1) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 50);  // VELOCIDAD MOTOR 1
            analogWrite(motor2, 250); // VELOCIDAD MOTOR 2
            delay(2);
        }

        // PROPUESTA 1
        else if (valor1 == 0 && valor2 == 0 && valor3 == 0 && valor4 == 0) // COMBINACION DE SENSORES
        {
            analogWrite(motor1, 0); // VELOCIDAD MOTOR 1
            analogWrite(motor2, 0); // VELOCIDAD MOTOR 2
            delay(2);
        }
    }
}
