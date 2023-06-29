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
}
