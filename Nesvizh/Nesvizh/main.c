/*
 * Nesvizh.c
 *
 * Created: 2/11/2022 12:47:40 PM
 * Author : user
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL 
#include <util/delay.h>
#include <avr/interrupt.h>


uint8_t led1=255, led2=255, led3=255, led4=255, led5=255, led6=255, led7=255, led8=255, led9=255, led10=255, flor=0, roof=0, house=255;       //���������� ��� � ���������
uint8_t led1_b, led2_b, led3_b, led4_b, led5_b, led6_b, led7_b, led8_b, led9_b, led10_b, flor_b, roof_b, house_b;                        //������ ���������� ���
uint8_t count, n;                                                                                                       //������� ������� ����������� ����������
uint8_t temp=1;                                                                                                         //��� ����� �����������


void skvazhnost() {                                                                             //������� ��� ������� ���������� ���������
while(1){		  
	if (temp==1)  {if (n    < 255)   {if(flor < 150) flor+=1; if(roof < 130) roof+=1; _delay_us(6600); n++;}    //������ ������� ��� �� 60% � ������� �� 70%                                 
		else temp = 2;}                                                                                          //������� � ���������� ����������
	if (temp==2)  {if (led1 >   0)   {led1 -= 1;  if(flor<255) flor+=1; if(roof<170) roof+=2; if((roof>=170) && (roof<255)) roof+=1; _delay_us(3400); }  //����� ������ ��� � �������, ������� ������ ��������. P.S. ��� if ��� �������� ������������ ��� �������������� ��������� ������� � ����
		else temp = 3; }                                                                         //������� � ���������� ����������	                                           	
	if (temp==3)  {if (led1 < 255)   {led1 += 1;  if(led1>100) led2 -=1; _delay_us(3400);}       //����� ����������� ��������� � ��������� 8 ����������� ��������                                                    
		else temp = 4;}                                                                          //        
	if (temp==4)  {if (led2 >   0)   {led2 -= 1; _delay_us(3400);}                               //                                                        
		else temp = 5; }                                                                         //
	if (temp==5)  {if (led2 < 255)   {led2 += 1;  if(led2>100) led3 -=1; _delay_us(3400);}       //
		else temp = 6; }                                                                         // 
	if (temp==6)  {if (led3 >   0)   {led3 -= 1; _delay_us(3400);}                               //
		else temp = 7; }                                                                         //
	if (temp==7)  {if (led3 < 255)   {led3 += 1;  if(led3>100) led4 -=1; _delay_us(3400);}       //
		else temp = 8; }                                                                         //
	if (temp==8)  {if (led4 >   0)   {led4 -= 1; _delay_us(3400);}                               //
		else temp = 9; }	                                                                     //
	if (temp==9)  {if (led4 < 255)   {led4 += 1;  if(led4>100) led5 -=1; _delay_us(3400);}       //
		else temp = 10; }                                                                        //
	if (temp==10) {if (led5 >   0)   {led5 -= 1; _delay_us(3400);}                               // 
		else temp = 11;}                                                                         //
	if (temp==11) {if (led5 < 255)   {led5 += 1;  if(led5>100) house -=1; _delay_us(3400);}      //
		else temp = 12;}                                                                         //
	if (temp==12) {if (house >   0)  {house -= 1; _delay_us(3400);}                              //
		else {temp = 13; _delay_ms(4000);}}                                           	
	if (temp==13) {if (house < 255)  {house += 1;  if(house>100) led6 -=1; _delay_us(3400);}     //
		else temp = 14;}	                                                                     //
	if (temp==14) {if (led6 >   0)   {led6 -= 1; _delay_us(3400);}                               //
		else temp = 15;}    
	if (temp==15) {if (led6 < 255)   {led6 += 1;  if(led6>100) led7 -=1; _delay_us(3400);}       //
		else temp = 16;}	                                                                     //
	if (temp==16) {if (led7 >   0)   {led7 -= 1; _delay_us(3400);}                               //
		else temp = 17;}                                                                         //
	if (temp==17) {if (led7 < 255)   {led7 += 1;  if(led7>100) led8 -=1; _delay_us(3400);}       //
		else temp = 18;}                                                                         //
	if (temp==18) {if (led8 >   0)   {led8 -= 1; _delay_us(3400);}                               //
		else temp = 19;} 	
	if (temp==19) {if (led8 < 255)   {led8 += 1;  if(led8>100) led9 -=1; _delay_us(3400);}       //
		else temp = 20;}                                                                         //
	if (temp==20) {if (led9 >   0)   {led9 -= 1; _delay_us(3400);}                               //
		else temp = 21;}     
	if (temp==21) {if (led9 < 255)   {led9 += 1;  if(led9>100) led10 -=1; _delay_us(3400);}      //
		else temp = 22;}                                                                         //
	if (temp==22) {if (led10 >   0)   {led10 -= 1; _delay_us(3400);}                             //
		else temp = 23;}  	                                                                     //
	if (temp==23) {if (led10 < 255)   {led10 += 1;  if((roof > 130) && (led10 > 125)) roof -=1; _delay_us(3400);}       //������ �������� ������� �� 70%
		else temp = 24;}	                                                                     //
	if (temp==24) {if (flor >   0)   {flor -= 1;  if(roof>0) roof -=1; _delay_us(6600);}         //������ �������� ��� � ������� �� 100%
		else {temp = 1; n=0; return;}}		                                                     //���������� ��������� �� �������� � ����������� �������
		}
	}
	
void initial_ports() {
DDRA=0xFF;                     //���������� ���� A
PORTA=0;

DDRD=0xFF;                     //���������� ���� D
PORTD|=(1<<3) | (1<<4);

DDRC&=~(1<<6);       DDRC&=~(1<<7);                //���������� ���� � �� ������ 
PORTC|=(1<<6);       PORTC|=(1<<7);                //����������� � 5V
}


ISR (TIMER0_OVF_vect)
{
count++;
if (count == 0){                                  //���� ������� ������������ � ������ �������� 0
        
        led1_b   = led1;                           //��������� �������� ���������� � ����� ���� 8 ����-��, ������, ������� � ����
        led2_b   = led2; 
        led3_b   = led3;
		led4_b   = led4;
		led5_b   = led5;
		led6_b   = led6;
		led7_b   = led7;
		led8_b   = led8;
		led9_b   = led9;
		led10_b  = led10;
		roof_b   = roof;
		flor_b   = flor;
		house_b  = house;
		
       PORTA=0b00000000;                          //������ ���� ������ A � D � ���� 
       PORTD=0b00000000;                          //
        }

if ((led1_b == count)  && (led1_b!=255))  { PORTA|=(1<<0);}             //�� ���������� �������� ���������� ������� ���������� 1 � ��� 
if ((led2_b == count)  && (led2_b!=255))  { PORTA|=(1<<1);}
if ((led3_b == count)  && (led3_b!=255))  { PORTA|=(1<<2);}
if ((led4_b == count)  && (led4_b!=255))  { PORTA|=(1<<3);}
if ((led5_b == count)  && (led5_b!=255))  { PORTA|=(1<<4);}
if ((led6_b == count)  && (led6_b!=255))  { PORTA|=(1<<5);}
if ((led7_b == count)  && (led7_b!=255))  { PORTA|=(1<<6);}
if ((led8_b == count)  && (led8_b!=255))  { PORTA|=(1<<7);}
if ((led9_b == count)  && (led9_b!=255))  { PORTD|=(1<<0);}
if ((led10_b == count) && (led10_b!=255)) { PORTD|=(1<<1);}
if ((roof_b == count)  && (roof_b!=255))  { PORTD|=(1<<2);}
if ((flor_b == count)  && (flor_b!=255))  { PORTD|=(1<<3);}
if ((house_b == count) && (house_b!=255)) { PORTD|=(1<<4);}
}



int main(void) {
  initial_ports();                     //�������������� �����

  TIMSK &= ~(1 << TOIE0);              // �������� ���������� �� ������������ �������
  TCCR0 |= (1 << CS00);                // ��������� �������, ������������ ����
  sei();

  while (1)
  {
    if (PINC & (1 << 7)) {    //��������� ������ �� ���. ����
      TIMSK |= (1 << TOIE0);      //��������� ���������� ��������������
      skvazhnost();               //��������� ����
      TIMSK &= ~(1 << TOIE0);     //��������� ���������� �� ������������
    }
    _delay_ms(500);             //������ �� ��������
  }
}