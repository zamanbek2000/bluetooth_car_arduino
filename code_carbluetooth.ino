//https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller

 
//L298N Драйвер двигателей
  const int motorA1  = 5;  // L298N'in IN3
  const int motorA2  = 6;  // L298N'in IN1
  const int motorB1  = 10; // L298N'in IN2
  const int motorB2  = 9;  // L298N'in IN4


  int i=0; //Случайная переменная, назначенная циклам
  int j=0; //Случайная переменная, назначенная циклам
  int state; //Переменная сигнала от устройства Bluetooth
  int vSpeed=255;     // Стандартная скорость может принимать значение от 0-255

void setup() {
    // Давайте определим наши контакты
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
    // Давайте откроем последовательный порт со скоростью 9600
    Serial.begin(9600);
}
 
void loop() {
  //Остановите автомобиль, когда соединение Bluetooth отключено.
 //(Удалите "//" подстроки для активации.)
//     if(digitalRead(BTState)==LOW) { state='S'; }

  //Сохранить входящие данные в переменную " состояние
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  // 4 уровня скорости, которые можно регулировать из приложения.(Значения должны быть между 0-255)
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************İleri****************************/
  //Если входящие данные "F" автомобиль идет вперед.
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /**********************İleri Sol************************/
  //Автомобиль идет вперед влево(по диагонали), если входящие данные " G.
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); analogWrite(motorA2, 0);  
        analogWrite(motorB1, 100);    analogWrite(motorB2, 0); 
    }
  /**********************İleri Sağ************************/
  //Если входящие данные' I ' автомобиль идет вперед вправо(по диагонали).
    else if (state == 'I') {
        analogWrite(motorA1, 100); analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /***********************Geri****************************/
  //Автомобиль возвращается, если входящие данные " B.
    else if (state == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
    }
  /**********************Geri Sol************************/
  //Если данные из ' H ' автомобиль возвращается влево(по диагонали) 
    else if (state == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 100); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    }
  /**********************Geri Sağ************************/
  //Если входящие данные 'J' автомобиль возвращается вправо(по диагонали)
    else if (state == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 100); 
    }
  /***************************Sol*****************************/
  //Если входящие данные 'L' автомобиль идет влево.
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
  /***************************Sağ*****************************/
  //Если входящие данные 'R' автомобиль идет вправо
    else if (state == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150);     
    }
  
  /************************Stop*****************************/
  //Остановить автомобиль, если входящие данные' s.
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }  
}
