#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Выбираем инициализацию дисплея (оставь ту, которая подходит):
//U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
//U8G2_SSD1306_128X64_ALT0_1_HW_I2C  u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //а вдруг сработает АНЛАК

// Самый распространённый вариант:
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// "_F_" — это "full buffer". Проще рисовать, чуть больше памяти кушает, но обычно норм.
#define face_width 128
#define face_height 64
// 'cuty', 128x64px

void setup() {
  u8g2.begin();        // запускаем дисплей ААА БЛЯТЬ ТАК ВОТ ЧЕ Я ЗАБЫВАЛА
}

void loop() {

  u8g2.clearBuffer();

  // закрываем глаза (сверху вниз)
  for (int h = 40; h >= 4; h -= 4) {
    u8g2.clearBuffer();
    u8g2.drawBox(20, 10 + (40 - h) / 2, 20, h);
    u8g2.drawBox(90, 10 + (40 - h) / 2, 20, h);
    u8g2.sendBuffer();
    delay(30);
  }

  delay(200); // пауза, глаза закрыты

  // открываем глаза (снизу вверх)
  for (int h = 4; h <= 40; h += 4) {
    u8g2.clearBuffer();
    u8g2.drawBox(20, 10 + (40 - h) / 2, 20, h);
    u8g2.drawBox(90, 10 + (40 - h) / 2, 20, h);
    u8g2.sendBuffer();
    delay(30);
  }

  (delay(random(1000, 3000))); // пауза, глаза открыты

  
  /*u8g2.drawXBMP(
    (128 - face_width) / 2,   // по центру экрана
    (64 - face_height) / 2,
    face_width, face_height,
    epd_bitmap_cuty
  );
  u8g2.sendBuffer();
  delay(2000);*/

}