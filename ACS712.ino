//*******************            Medicao de corrente eletrica com sensor ACS 712       **********//
//*******************               Codigo desenvolvido por Guilherme Hollweg          **********//
//*******************                        Ultima modificacao:                       **********//
//*******************                         07/2015    21:30h                        **********//
//*******************                 Disponível em github.com/Hollweg                 **********//
//***********************************************************************************************//
//***********************************************************************************************//

short int mV = 185;                                      
short int valorBruto= 0;
short int offsetSensor = 2500; 
double tensao = 0, corrente = 0;

void setup(){
    Serial.begin(9600);
    pinMode (7, OUTPUT);     
}

void loop(){
  
   valorBruto = analogRead(A0);
   tensao = (valorBruto / 1023.0) * 5000;           //le o valor de entrada da porta A0
   corrente = ((tensao - offsetSensor) / mV);       //converte esse valor para mV e faz a leitura de corrente
   
   digitalWrite (7, HIGH);                          //caso queira usar o proprio pino 7 do uc
                                                    //como circuito de potencia
   Serial.print("Valor Bruto = " );                 //transmite entao os dados pela serial
   Serial.print(valorBruto); 
   Serial.print("\t Tensao em [mV] = "); 
   Serial.print(tensao, 3);
   Serial.print("\t Corrente em [A] = "); 
   Serial.println(corrente, 3);
   delay(1500);  
}
