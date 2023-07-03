#define d1 (RC7_bit) //led verde
#define d2 (RC6_bit) //led vermelho
#define porta (RC0_bit)

char keypadPort at PORTB;

//módulo LCD
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
char texto1[]="Tranca do Gil";
char texto2[]="Digite sua senha:";
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
       Delay_ms(20);
    }
    Delay_ms(100);

    Keypad_Init();

    do{
      d1 = 0,cnt = 0,aux = 0;
      Lcd_Cmd(_LCD_CLEAR);
      Lcd_Out(1,1, texto2);
      Delay_ms(50);

      do{ //Inicio de varredura
      
        kp = 0; // a cada ciclo reseta a variável
      
         do{
         
           kp = Keypad_Key_Click(); //armazana em kp a variavel clicada
         }while(!kp);

        switch (kp){
           case 1: kp = 49; break; //teclado 4x3
           case 5: kp = 50; break;
           case 9: kp = 51; break;
           case 2: kp = 52; break;
           case 6: kp = 53; break;
           case 10: kp = 54; break;
           case 3: kp = 55; break;
           case 7: kp = 56; break;
           case 11: kp = 57; break;
           case 4: kp = 42; break;
           case 8: kp = 48; break;
           case 12: kp = 35; break;
           default: kp += 48;
        }
        
        LCD_Chr(2, cnt+1, kp);
        senha[cnt]=kp;
        cnt++;
        
      }while(cnt<4);
      
      Delay_ms(50);
      Lcd_Cmd(_LCD_CLEAR);
      
          for(i=0;i<4;i++){
           if(senha[i]==comparasenha[i]){
           }
          }
      
      if(aux==4){
       Lcd_Out(1, 1, "senha valida");
       Lcd_Out(2, 1, "tranca aberta");
       d1=1;
       porta=0;
       
         do{
         }while(porta==0);
         
       Lcd_Out(2, 1, "tranca fechada");
       Delay_ms(200);
      }else{
        Lcd_Out(1, 1, "senha invalida");
          for(i=0;i<5;i++){
           d2=1;
           Delay_ms(30);
           d2=0;
           Delay_ms(30);
          }
        aux2++;
      }
     }while(aux2<3);
     
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Out(1,1, "tranca travada");
     for(i=0;i<5;i++){
     d2=1;
     //Delay_ms(6000);
     //d2=0;
     }
}

//definição
#define col1 (RD0_bit)
#define col2 (RD1_bit)
#define col3 (RD2_bit)
#define row1 (RD3_bit)
#define row2 (RD4_bit)
#define row3 (RD5_bit)
#define row4 (RD6_bit)
#define dir_keypad (TRISD)


// conexões do modulo LCD
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

char tecla = 'n';


  //prototipo de função
char varrer();
void key_Init();
char espera_tecla();



void main() {
Key_Init();
Lcd_Init();

   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd (_LCD_CURSOR_OFF);
   Lcd_Out (1,7, "IFPI");
   Lcd_Out (1,1,"Inicializando...");
   Lcd_Out (2,1,"Exemplo Keypad");
   Delay_ms(1500);
   Lcd_Cmd (_LCD_CLEAR);
   Lcd_Out (1,1,"Tecla Acionada:");
   Lcd_Cmd (_LCD_SECOND_ROW);
   
   while(1){
   tecla = espera_tecla();
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Chr(2,1, tecla);

     varrer();

     }

     }

char  varrer (){

  col1 = 0; col2 = 1; col3 = 1; Delay_ms(50);
  if (row1 == 0){Delay_ms(50); while( row1==0); return '1';}
  if (row2 == 0){Delay_ms(50); while( row2==0); return '4';}
  if (row3 == 0){Delay_ms(50); while( row3==0); return '7';}
  if (row4 == 0){Delay_ms(50); while( row4==0); return '*';}

   col1 = 1; col2 = 0; col3 = 1; Delay_ms(50);
   if (row1 == 0){Delay_ms(50); while( row1==0); return '2';}
  if (row2 == 0){Delay_ms(50); while( row2==0); return '5';}
  if (row3 == 0){Delay_ms(50); while( row3==0); return '8';}
  if (row4 == 0){Delay_ms(50); while( row4==0); return '0';}

   col1 = 1; col2 = 1; col3 = 0; Delay_ms(50);
     if (row1 == 0){Delay_ms(50); while( row1==0); return '3';}
  if (row2 == 0){Delay_ms(50); while( row2==0); return '6';}
  if (row3 == 0){Delay_ms(50); while( row3==0); return '9';}
  if (row4 == 0){Delay_ms(50); while( row4==0); return '#';}

  return 'n';

}
  char espera_tecla() {

  char key = 'n';
  while(key == 'n') {key = varrer (); }
  return key;

 }
  void key_Init() {

  PORTD = 0X00;
  ADCON1 = 0xFF;
  dir_keypad = 0x78;
  }
