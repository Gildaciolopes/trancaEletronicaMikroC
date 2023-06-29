#define d1 portc.
#define d2 portc.
#define d3 portc.
#define porta portc.

char keypadPort at PORTB;

sbit LCD_RS at RD5_bit;
sbit LCD_EN at RD4_bit;
sbit LCD_D4 at RD0_bit;
sbit LCD_D5 at RD1_bit;
sbit LCD_D6 at RD2_bit;
sbit LCD_D7 at RD3_bit;

sbit LCD_RS_Direction at TRISD5_bit;
sbit LCD_EN_Direction at TRISD4_bit;
sbit LCD_D4_Direction at TRISD0_bit;
sbit LCD_D5_Direction at TRISD1_bit;
sbit LCD_D6_Direction at TRISD2_bit;
sbit LCD_D7_Direction at TRISD3_bit;

unsigned short kp; //variável que irá receber o comando da tecla
char texto1[]="Bem Vindo";
char texto2[]="Digite sua senha";
char senha[3];
char comparasenha[]={'1','2','3','4'};
int cnt=0, aux=0, aux2=0, i; //contador usado para mudar de coluna na impressão do lcd, variável do for

void main(){
  TRISC = 0b00000001; //definindo rc0 como entrada
  PORTC = 0b00000001; //inicia rc0 com nvl logico alto
    
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Delay_ms(200);
  Lcd_Out(1, 4, texto1); //show_message "bem vindo"
  Delay_ms(200);
    
  for(i = 3; i < 12; i++){    //apaga letra por letra
    Lcd_Out(1,(i+1)," ");
    Delay_ms(10);
  }
  Delay_ms(100);
    
  Keypad_Init();
}
