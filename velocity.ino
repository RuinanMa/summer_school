#include <MsTimer2.h> //中断库
 
int pinA=2; // 定义2号端口为A脉冲输入端口
int ppsA=0; //记录A脉冲的次数
float velocity=0; //速度
 
float v(float n) //转速计算函数
{
  float vel =n/200; //编码器为200脉冲每转，每隔一秒计算一次
  return vel;
}
 
void flash()
{
  int w=ppsA;
  velocity=v(w); //计算转速
  Serial.print(velocity); // 将获取的数字信号值打印到串口显示
  Serial.print("r/s  ");
  Serial.println(ppsA);
  ppsA=0;  //脉冲A计数归0
  }
 
void setup()
{
  Serial.begin(9600);
  attachInterrupt(0,CountA,FALLING);// 外部中断0，检测脉冲上升沿中断，并转到CountA函数
  MsTimer2::set(1000, flash);  // 中断设置函数，每1秒执行一次flash显示函数
  MsTimer2::start();  //启动中断（开始计时）
}
 
void loop()
{
}
 
void CountA()
{
  ppsA++;
}
