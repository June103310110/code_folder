#include <HX711.h> // 包含库的头文件
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

HX711 hx(9, 10, 128, 0.0021812); // 数据接脚定义 
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup() {
  
  hx.set_offset(-164851);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.begin(16,2);
  Serial.begin(9600);

}
void loop()
{
  int count = 1;
  double sum0 = 0;    // 为了减小误差，一次取出10个值后求平均值。
  double sum1 = 0;
  for (int i = 0; i < count; i++){ // 循环的越多精度越高，当然耗费的时间也越多
    sum0 -= hx.read();  // 累加
    sum1 -= hx.bias_read();
    
  }
  sum1 /= count;
//   Serial.print(sum0/count);
//  Serial.print(" ");
//  Serial.println(sum1/count);
  lcd.clear();  
  lcd.setCursor(2,0);
  lcd.print("key");
  lcd.setCursor(3,0);
  lcd.print("e");
  lcd.setCursor(4,0);
  lcd.print("y");
//  //delay(100);
  
  int a = 1000;
  double ori_sum1 = sum1;
  //Serial.println(sum1/1000);
  lcd.setCursor(4, 1);
  if( (sum1/1000) > 0){lcd.print(int(sum1/1000)); sum1 -= int(sum1/1000)*1000;}
  lcd.setCursor(5, 1);
  if((sum1/100) > 0){lcd.print(int(sum1/100)); sum1 -= int(sum1/100)*100;}
  lcd.setCursor(6, 1);
  if((sum1/10) > 0){lcd.print(int(sum1/10)); sum1 -= int(sum1/10)*10;}
  lcd.setCursor(7, 1);
  Serial.println(ori_sum1);
  lcd.print(sum1);

//  //lcd.print(sum1/count);
//  lcd.print("g");
delay(100);

}
//210275 187352
