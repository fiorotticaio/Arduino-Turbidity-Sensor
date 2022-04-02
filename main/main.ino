#define VERMELHO 12
#define AMARELO 11
#define VERDE 10
#define AZUL 9
#define BRANCO 8

#define LDR A0

int rtn = 0; 
  
void setup() {
  Serial.begin(9600);
  pinMode(VERMELHO, OUTPUT);
  pinMode(BRANCO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  
  pinMode(LDR, INPUT);
  
  // todos os leds comecam desligados
  digitalWrite(VERMELHO, LOW);
  digitalWrite(BRANCO, LOW);
  digitalWrite(AMARELO, LOW);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
}

int ledAceso = 0;
int ledsApagados[5] = { VERMELHO,BRANCO,AMARELO,VERDE,AZUL };
int parametros[] = {950, 970, 980, 990};
int calibrado=0;

void loop() {    
  rtn = analogRead(LDR);
  Serial.println(rtn); // so para debugar
  
  for(int i=0;i<5;i++) digitalWrite(ledsApagados[i], LOW);
  
  if (!calibrado) calibrado = calibra();
  acendeLED(rtn, parametros);
  

  digitalWrite(ledAceso, HIGH);
  
  delay(100);
}

void acendeLED(int voltagem, int parametros[]){

  // os valores condicionais sao para o caso de um resistor de
  // 2KOhms ligado ao LDR (vão precisar de ajustes quando for
  // finalizada a montagem presencial)
  if(voltagem <= parametros[0]){ ledAceso = BRANCO; } //limpissima
  else if(voltagem > parametros[0] && voltagem <= parametros[1]){ ledAceso = AZUL; }      //limpa
  else if(voltagem > parametros[1] && voltagem <= parametros[2]){ ledAceso = VERDE; }     //semi-limpa
  else if(voltagem > parametros[2] && voltagem <= parametros[3]){ ledAceso = AMARELO; }   //semi-turva
  else if(voltagem > parametros[3]){ ledAceso = VERMELHO; }                               //turva
  else ledAceso = 0;
}


int calibra(){
  double lido = analogRead(LDR);
  double anterior=0;
  double diferenca=0;


  int vezes=0;

  while(vezes<1000){
    lido = analogRead(LDR);
    diferenca = anterior-lido;
    
    if (diferenca < 100) {
      vezes++;
    } else vezes=0;

    anterior = lido;
  }
  
  parametros[0] = lido;
  parametros[1] = lido+10;
  parametros[2] = lido+20;
  parametros[3] = lido+30;

  Serial.print("P1: ");
  Serial.print(parametros[0]);
  Serial.print("P2: ");
  Serial.print(parametros[1]);
  Serial.print("P3: ");
  Serial.print(parametros[2]);
  Serial.print("P4: ");
  Serial.print(parametros[3]);

  return 1;
}
