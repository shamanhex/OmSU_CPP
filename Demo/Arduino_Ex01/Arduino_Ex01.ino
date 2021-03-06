#define TIME_TEST 60000  // Время тестирования функции в милисекундах
#define SIZE_BUF  100  // Размер буфера для тестирования

typedef unsigned char BYTE;
typedef unsigned long ULONG;

// Функция что-то делающая с входными данными.
void func(BYTE *data)
{
  BYTE tmp;

  for (ULONG x = 0; x < SIZE_BUF; x++)
  {
    tmp = data[x];
    data[x] = data[SIZE_BUF - x - 1];
    data[SIZE_BUF - x - 1] = tmp;
  }
}

void process_data() {
  ULONG count = 0;
  long timer;
  BYTE data[SIZE_BUF];

  // Если две следующие строки убрать, то скорость считается неверно!
  timer = millis();  // delete
  while (millis() == timer); //delete

  timer = millis() + TIME_TEST;

  while (millis() < timer)
  {
    func(data);
    count++;
  }
  Serial.print("Speed =  ");
  Serial.print(count / TIME_TEST);
  Serial.println(" kb/sec");
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  process_data();
  delay(3000);
}
