#include <Adafruit_NeoPixel.h>

#define PIN 13
#define NUMLIN 24
#define NUMCOL 4
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLIN * NUMCOL, PIN, NEO_GRB + NEO_KHZ800);
int botao1 = 12;
int botao2 = 11;
int botao3 = 10;
int botao4 = 9;
int botao5 = 8;
int botao6 = 7;
int botao7 = 6;
int botao8 = 5;
int botao9 = 4;

int estado_botao1 = 0;
int estado_botao2 = 0;
int estado_botao3 = 0;
int estado_botao4 = 0;
int estado_botao5 = 0;
int estado_botao6 = 0;
int estado_botao7 = 0;
int estado_botao8 = 0;
int estado_botao9 = 0;

int estado_botao1_anterior = 0;
int estado_botao2_anterior = 0;
int estado_botao3_anterior = 0;
int estado_botao4_anterior = 0;
int estado_botao5_anterior = 0;
int estado_botao6_anterior = 0;
int estado_botao7_anterior = 0;
int estado_botao8_anterior = 0;
int estado_botao9_anterior = 0;

int botao1_ativo = 0;
int botao2_ativo = 0;
int botao3_ativo = 0;
int botao4_ativo = 0;
int botao5_ativo = 0;
int botao6_ativo = 0;
int botao7_ativo = 0;
int botao8_ativo = 0;
int botao9_ativo = 0;

int contador = 0;
int num_da_coluna;
int i_inicial;
int numerosensor;
char matriz_jogo[9];
int jog_atual;
int num_jogadas;
int j;
// Variaveis controle Jogo
int placa_jogo[]={0,0,0,0,0,0,0,0,0};// guarda dados 0 e vazio, 1 jogador, 2 jogador
int vencedor=0;
int jogadas=1;

void setup() {
    pinMode(botao1, INPUT);
    pinMode(botao2, INPUT);
    pinMode(botao3, INPUT);
    pinMode(botao4, INPUT);
    pinMode(botao5, INPUT);
    pinMode(botao6, INPUT);
    pinMode(botao7, INPUT);
    pinMode(botao8, INPUT);
    pinMode(botao9, INPUT);
    Serial.begin(9600);
    Serial.println("Iniciar...");
    strip.begin(); //Inicia o sistema que controla a fita de LED
    strip.show(); //Manda os valores para a fita
}

void controle_botoes() { /*
        //############# botao 1 ##################

        estado_botao1 = digitalRead(botao1);

        if (estado_botao1 == 1 && estado_botao1_anterior == 0) {
            contador++;
            botao1_ativo = 1;
            Serial.println("contou clique1");
            numerosensor = 1;
        } else if (estado_botao1 == 0 && estado_botao1_anterior == 0) {
            botao1_ativo = 0;
        }

        //############# botao 2 ##################

        estado_botao2 = digitalRead(botao2);

        if (estado_botao2 == 1 && estado_botao2_anterior == 0) {
            contador++;
            botao2_ativo = 1;
            Serial.println("contou clique2");
            numerosensor = 2;
        } else if (estado_botao2 == 0 && estado_botao2_anterior == 0) {
            botao2_ativo = 0;
        }

        //############# botao 3 ##################

        estado_botao3 = digitalRead(botao3);

        if (estado_botao3 == 1 && estado_botao3_anterior == 0) {
            contador++;
            botao3_ativo = 1;
            Serial.println("contou clique3");
            numerosensor = 3;
        } else if (estado_botao3 == 0 && estado_botao3_anterior == 0) {
            botao3_ativo = 0;
        }

        //############# botao 4 ##################

        estado_botao4 = digitalRead(botao4);

        if (estado_botao4 == 1 && estado_botao4_anterior == 0) {
            contador++;
            botao4_ativo = 1;
            Serial.println("contou clique4");
            numerosensor = 4;
        } else if (estado_botao4 == 0 && estado_botao4_anterior == 0) {
            botao4_ativo = 0;
        }

        //############# botao 5 ##################

        estado_botao5 = digitalRead(botao5);

        if (estado_botao5 == 1 && estado_botao5_anterior == 0) {
            contador++;
            botao5_ativo = 1;
            Serial.println("contou clique5");
            numerosensor = 5;
        } else if (estado_botao5 == 0 && estado_botao5_anterior == 0) {
            botao5_ativo = 0;
        }

        //############# botao 6 ##################

        estado_botao6 = digitalRead(botao6);

        if (estado_botao6 == 1 && estado_botao6_anterior == 0) {
            contador++;
            botao6_ativo = 1;
            Serial.println("contou clique6");
            numerosensor = 6;
        } else if (estado_botao6 == 0 && estado_botao6_anterior == 0) {
            botao6_ativo = 0;
        }

        //############# botao 7 ##################

        estado_botao7 = digitalRead(botao7);

        if (estado_botao7 == 1 && estado_botao7_anterior == 0) {
            contador++;
            botao7_ativo = 1;
            Serial.println("contou clique7");
            numerosensor = 7;
        } else if (estado_botao7 == 0 && estado_botao7_anterior == 0) {
            botao7_ativo = 0;
        }

        //############# botao 8 ##################

        estado_botao8 = digitalRead(botao8);

        if (estado_botao8 == 1 && estado_botao8_anterior == 0) {
            contador++;
            botao8_ativo = 1;
            Serial.println("contou clique8");
            numerosensor = 8;
        } else if (estado_botao8 == 0 && estado_botao8_anterior == 0) {
            botao8_ativo = 0;
        }

        //############# botao 9 ##################

        estado_botao9 = digitalRead(botao9);

        if (estado_botao9 == 1 && estado_botao9_anterior == 0) {
            contador++;
            botao9_ativo = 1;
            Serial.println("contou clique9");
            numerosensor = 9;
        } else if (estado_botao9 == 0 && estado_botao9_anterior == 0) {
            botao9_ativo = 0;
        }

        estado_botao1_anterior = estado_botao1;
        estado_botao2_anterior = estado_botao2;
        estado_botao3_anterior = estado_botao3;
        estado_botao4_anterior = estado_botao4;
        estado_botao5_anterior = estado_botao5;
        estado_botao6_anterior = estado_botao6;
        estado_botao7_anterior = estado_botao7;
        estado_botao8_anterior = estado_botao8;
        estado_botao9_anterior = estado_botao9;

        //############# botao 1 ativado ##################

        if (contador % 2 == 1 && botao1_ativo == 1 && numerosensor == 1) //impares -> quadrado
        {
            Serial.println("entrei no quadrado sensor 1");
            matriz_jogo[0] = 'Q';
            int i_inicial = (numerosensor - 1) * 8;
            int i_final = (numerosensor - 1) * 8 + 3;
            for (int i = i_inicial; i <= i_final; i++) //############
            {
                strip.setPixelColor(i, strip.Color(0, 255, 0));
                strip.show();
                delay(100); // pausa de 100 milesegundos
            } else if (contador % 2 == 0 && contador != 0 && botao1_ativo == 1 && numerosensor == 1) //pares -> cruz
            {

                Serial.println("entrei na cruz do sensor 1");
                matriz_jogo[0] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);

                }
            }
            //############# botao 2 ativado ##################

            if (contador % 2 == 1 && botao2_ativo == 1 && numerosensor == 2) //impares -> quadrado
            {
                matriz_jogo[1] = 'Q';
                Serial.println("entrei no quadrado sensor 2");

                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos

                }
            } else if (contador % 2 == 0 && contador != 0 && botao2_ativo == 1 && numerosensor == 2) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 2");
                matriz_jogo[1] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 3 ativado ##################

            if (contador % 2 == 1 && botao3_ativo == 1 && numerosensor == 3) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 3");
                matriz_jogo[2] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao3_ativo == 1 && numerosensor == 3) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 3");
                matriz_jogo[2] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 4 ativado ##################

            if (contador % 2 == 1 && botao4_ativo == 1 && numerosensor == 4) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 4");
                matriz_jogo[3] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao4_ativo == 1 && numerosensor == 4) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 4");
                matriz_jogo[3] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 5 ativado ##################

            if (contador % 2 == 1 && botao5_ativo == 1 && numerosensor == 5) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 5");
                matriz_jogo[4] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao5_ativo == 1 && numerosensor == 5) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 5");
                matriz_jogo[4] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 6 ativado ##################

            if (contador % 2 == 1 && botao6_ativo == 1 && numerosensor == 6) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 6");
                matriz_jogo[5] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos 
                }
            } else if (contador % 2 == 0 && contador != 0 && botao6_ativo == 1 && numerosensor == 6) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 6");
                matriz_jogo[5] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 7 ativado ##################

            if (contador % 2 == 1 && botao7_ativo == 1 && numerosensor == 7) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 7");
                matriz_jogo[6] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao7_ativo == 1 && numerosensor == 7) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 7");
                matriz_jogo[6] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 8 ativado ##################

            if (contador % 2 == 1 && botao8_ativo == 1 && numerosensor == 8) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 8");
                matriz_jogo[7] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao8_ativo == 1 && numerosensor == 8) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 8");
                matriz_jogo[7] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

            //############# botao 9 ativado ##################

            if (contador % 2 == 1 && botao9_ativo == 1 && numerosensor == 9) //impares -> quadrado
            {
                Serial.println("entrei no quadrado sensor 9");
                matriz_jogo[8] = 'Q';
                int i_inicial = (numerosensor - 1) * 8;
                int i_final = (numerosensor - 1) * 8 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(0, 255, 0));
                    strip.show();
                    delay(100); // pausa de 100 milesegundos
                }
            } else if (contador % 2 == 0 && contador != 0 && botao9_ativo == 1 && numerosensor == 9) //pares -> cruz
            {
                Serial.println("entrei na cruz do sensor 9");
                matriz_jogo[8] = 'C';
                int i_inicial = (numerosensor - 1) * 8 + 4;
                int i_final = (numerosensor - 1) * 8 + 4 + 3;
                for (int i = i_inicial; i <= i_final; i++) //############
                {
                    strip.setPixelColor(i, strip.Color(255, 0, 0));
                    strip.show();
                    delay(100);
                }
            }

        }
        */
}

// Inicio do Codigo do JOGO
//--------------------------
void Joga_nr1()
{
    if(placa_jogo[3]==0)
        {
         Serial.println("detetada jogada no: 3");
          placa_jogo[3]=1;
          //Codigo para acender fita com o numero
          //Jogador 1 pode ser O
        }
}
void Joga_nr2() 
{
     if(placa_jogo[4]==0)
        {
         Serial.println("detetada jogada: 4");
          placa_jogo[4]=2;
          // Aqui vamos colocar o codigo para acender os leds
          //Jogador 2 pode ser X
        }   
}

void desenha_placa()
{
  int i=0;
  Serial.print("Placa Jogo: [");
  for(i=0;i<9;i++)
  {
    Serial.print(placa_jogo[i]);
    Serial.print(",");
  }
  Serial.println("]");
}

void VerificaVencedor() 
// verifica vencedor
// coloca resulta na variavel 'vencedor'
{
  int qq=0;
  // bolas ganham?
  if (placa_jogo[0]==1 && placa_jogo[1]==1 && placa_jogo[2]==1) { 
    vencedor=1; 
  }
  if (placa_jogo[3]==1 && placa_jogo[4]==1 && placa_jogo[5]==1) { 
    vencedor=1; 
  }
  if (placa_jogo[6]==1 && placa_jogo[7]==1 && placa_jogo[8]==1) { 
    vencedor=1; 
  }  
  if (placa_jogo[0]==1 && placa_jogo[3]==1 && placa_jogo[6]==1) { 
    vencedor=1; 
  }
  if (placa_jogo[1]==1 && placa_jogo[4]==1 && placa_jogo[7]==1) { 
    vencedor=1; 
  }
  if (placa_jogo[2]==1 && placa_jogo[5]==1 && placa_jogo[8]==1) { 
    vencedor=1; 
  }  
  if (placa_jogo[0]==1 && placa_jogo[4]==1 && placa_jogo[8]==1) { 
    vencedor=1; 
  }
  if (placa_jogo[2]==1 && placa_jogo[4]==1 && placa_jogo[6]==1) { 
    vencedor=1; 
  }
  // cruzes ganham?
  if (placa_jogo[0]==2 && placa_jogo[1]==2 && placa_jogo[2]==2) { 
    vencedor=2; 
  }
  if (placa_jogo[3]==2 && placa_jogo[4]==2 && placa_jogo[5]==2) { 
    vencedor=2; 
  }
  if (placa_jogo[6]==2 && placa_jogo[7]==2 && placa_jogo[8]==2) { 
    vencedor=2; 
  }  
  if (placa_jogo[0]==2 && placa_jogo[3]==2 && placa_jogo[6]==2) { 
    vencedor=2; 
  }
  if (placa_jogo[1]==2 && placa_jogo[4]==2 && placa_jogo[7]==2) { 
    vencedor=2; 
  }
  if (placa_jogo[2]==2 && placa_jogo[5]==2 && placa_jogo[8]==2) { 
    vencedor=2; 
  }  
  if (placa_jogo[0]==2 && placa_jogo[4]==2 && placa_jogo[8]==2) { 
    vencedor=2; 
  }
  if (placa_jogo[2]==2 && placa_jogo[4]==2 && placa_jogo[6]==2) { 
    vencedor=2; 
  }
 
}

void VamosJogar()
{
  do
  {
    if(jogadas%2==1)
    {
     Joga_nr1(); 
     desenha_placa();
     VerificaVencedor();
    }else
    {
      Joga_nr2(); 
      desenha_placa();
      VerificaVencedor();  
    }
    jogadas++;
  }
  while (vencedor==0 && jogadas<10); 
  if(vencedor == 1)
  {
    Serial.println("Jogador 1 ganhou");
    delay(3000);
  }else if(vencedor ==2)
  {
     Serial.println("Jogador 2 ganhou");
     delay(3000);
  }else
  {
    Serial.println("EMPATE");
    delay(3000);
  }
  
}
//Fim codigo JOGO
//--------------
void loop()
{
VamosJogar(); //Inicia o Jogo

}
