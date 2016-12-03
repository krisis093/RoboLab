//Zadeklarujmy zmienne
char pole11 = ' '; char pole12 = ' '; char pole13 = ' ';
char pole21 = ' '; char pole22 = ' '; char pole23 = ' ';
char pole31 = ' '; char pole32 = ' '; char pole33 = ' ';
int aktywnyGracz = 0;

void setup()
{
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if(digitalRead(2)==LOW)
  {
    if(pole11 == ' ')
    {
      if(aktywnyGracz == 0)
        {
          pole11 = 'X';
          aktywnyGracz = 1;
        }
      else
        {
          pole11 = 'O';
          aktywnyGracz = 0;
        }
    }
  }
  //kod zostal scisniety, gdyz jest powtarzany
  //kopiuj wklej 8 razy i zmien cyferki
  if(digitalRead(3)==LOW)
    if(pole12 == ' '){
      if(aktywnyGracz == 0){pole12 = 'X'; aktywnyGracz = 1;}
      else {pole12 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(4)==LOW)
    if(pole13 == ' '){
      if(aktywnyGracz == 0){pole13 = 'X'; aktywnyGracz = 1;}
      else {pole13 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(5)==LOW)
    if(pole21 == ' '){
      if(aktywnyGracz == 0){pole21 = 'X'; aktywnyGracz = 1;}
      else {pole21 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(6)==LOW)
    if(pole22 == ' '){
      if(aktywnyGracz == 0){pole22 = 'X'; aktywnyGracz = 1;}
      else {pole22 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(7)==LOW)
    if(pole23 == ' '){
      if(aktywnyGracz == 0){pole23 = 'X'; aktywnyGracz = 1;}
      else {pole23 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(8)==LOW)
    if(pole31 == ' '){
      if(aktywnyGracz == 0){pole31 = 'X'; aktywnyGracz = 1;}
      else {pole31 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(9)==LOW)
    if(pole32 == ' '){
      if(aktywnyGracz == 0){pole32 = 'X'; aktywnyGracz = 1;}
      else {pole32 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(10)==LOW)
    if(pole33 == ' '){
      if(aktywnyGracz == 0){pole33 = 'X'; aktywnyGracz = 1;}
      else {pole33 = 'O';aktywnyGracz = 0;}
    }
  if(digitalRead(11)==LOW)
    {
      pole11 = ' '; pole12 = ' '; pole13 = ' ';
      pole21 = ' '; pole22 = ' '; pole23 = ' ';
      pole31 = ' '; pole32 = ' '; pole33 = ' ';
    }
  //ostatni blok kodu drukuje stan gry
  Serial.print("+---+\n|");
  Serial.print(pole11);Serial.print(pole12);Serial.print(pole13);Serial.print("|\n|");
  Serial.print(pole21);Serial.print(pole22);Serial.print(pole23);Serial.print("|\n|");
  Serial.print(pole31);Serial.print(pole32);Serial.print(pole33);Serial.println("|\n+---+");
  delay(100);
}
