#include <Keypad.h>

const byte filas = 4;
const byte columnas = 4;
const int buzzer = 12;
const int radar = 2;
  int lee;
char letras[filas][columnas]= {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}

};

byte pinesf[filas] = {7,8,9,10};
byte pinesc[columnas] = {3,4,5,6};
Keypad teclado = Keypad(makeKeymap(letras),pinesf,pinesc,filas,columnas);
char estado;

char pass[6]="2561A"; //Poner en el arreglo 1 posicion mas a la que tendra la contraseña correcta
char ponercontra[6]; // tiene que tener el mismo tamaño del arreglo de la contraseña correcta
int indice=0;
#define salida(pin) pinMode(pin,OUTPUT);
#define entrada(pin) pinMode(pin,INPUT);
#define encender_b(pin) tone(pin,100);
#define apagar_b(pin) noTone(pin);


void setup()
{ 
Serial.begin(9600);
entrada(radar);
salida(buzzer);

apagar_b(buzzer);
}

void loop(){
  estado = teclado.getKey(); //detecta que en el teclado se pulso un boton
if(estado){
ponercontra[indice] = ponercontra[indice]; // le asigna lo que ingresamos a el arreglo que va a ser comparado
indice++; //cambiara la posicion del arreglo para poder asignar los caracteres
Serial.print(estado);
}
  
  lee=digitalRead(radar);
if (lee == 1)
{
encender_b(buzzer);
}

if(indice==5){ //cuando se llegue al limite del arreglo verificara si esta correcta o no la contraseña
if(strcmp(pass,ponercontra)==0){ //Verifica que la contraseña esta correcta
apagar_b(buzzer);
Serial.println(" Acceso permitido");
}
indice=0;
}
}