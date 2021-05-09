//completed Arduino source ready for presentation
/*
CSE 5408 Senior Project
Garage Door Controller
Created by Ricardo Torres, Cameron Wood, Pablo Fernando
This Application is to be used with:
Ardiuno Uno, ESP-01, Reed switch, and Garage Door Opener.
The function of this file is to have the Ardiuno Uno 
controller the functionalty of the Garage Door opener.
With the Aid of ESP01 the controller will interact with 
a home network to beable to use a phone to open or close the garage.
*/

//button signal from garage door opener 
const int signal_button_in = 9;
const int signal_button_out = 10;
//signals for garage opener
const int signal_garage_in = 6;
const int signal_garage_out= 7;
//reed switch pins
const int reed_closed = 3;
const int reed_half = 4;
const int reed_open = 5;
//chars used for incoming commands from Phone Application
char temp[50];
char compare;
//prototyping
//Green LED will represent motor of garage when lit motor on
const int motor = 13;
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
void setup()
{
  // put your setup code here, to run once:
  // set baudrate
  Serial.begin(115200);
  // set button source
  pinMode(signal_button_in, INPUT); //set input to read when button is pushed
  pinMode(signal_button_out, OUTPUT); //set as output
  digitalWrite(signal_button_out, HIGH); //send power to button
  //set garage source
  pinMode(signal_garage_in, INPUT); //set input to read garage signal
  pinMode(signal_garage_out, OUTPUT); //set as output to control opener
  //reed pin assignment
  pinMode(reed_open, INPUT); //set input to read reed signal
  pinMode(reed_half, INPUT); //set input to read reed signal
  pinMode(reed_closed, INPUT); //set input to read reed signal

  //comment out when not on bread board
  pinMode(motor, OUTPUT);
  digitalWrite(motor, LOW);
}

//////////////////////////////////////////////////////////////
void loop()
{
  // put your main code here, to run repeatedly:
  int val_x = 0;
  int val_y = 0;
  
do
{
 String incoming = "";
 val_x = digitalRead(signal_button_in); //button being read to see if garage button is pushed to open or close
 val_y = digitalRead(signal_garage_in);// reading garage signal to see if there is feed back from the opener

 //reading phone commands to string incoming
  unsigned int length_incoming = 0;
  
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incoming = Serial.readString();
    incoming.toCharArray(temp,50);
    length_incoming = incoming.length();
  }

  Serial.println("This is direction: ");
  Serial.println(incoming);
  compare = temp[0];
  Serial.println(compare);
  door_operation(compare);
//  delay(1500);
 // incoming.remove(0,length_incoming);
  //compare='/0';
  temp[0] = '/0';
}while( val_x == LOW || val_y == LOW);
Serial.println("broke loop");
power_garage();

}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
//calling operation
/*Based on characters received from phone statement will call door 
 * operation. This operation uses a case statement to determine
 * function.
*/
void door_operation(char letter)
{
  switch (letter)
  {
    case 'f':
    {
      full_open_door();
      break;
    }
    case 'h':
    {
      half_open_door();
      break;
    }
    case 'c':
    {
      close_door();
      break;
    }
  }
}
//////////////////////////////////////////////////////////////
//door operation
/*Operations will include full_open, half_open, and close.
 * These functions will implenment message functions and 
 * and power_garage. Which will open or close the garage accordingly.
*/
void full_open_door()
{
  int x = 0;
  opening_message();
  power_garage();
  do {
    x = digitalRead(reed_open);
  }while(x == HIGH);
   open_message();
  
  
}

void half_open_door()
{
  int x=0;
  opening_message();
  power_garage();
   do {
    x = digitalRead(reed_half);
  }while(x == HIGH);
  power_garage();
   half_message();
}

void close_door()
{
  int x = 0;
  closing_message();
  power_garage();
    do {
    x = digitalRead(reed_closed);
  }while(x == HIGH);
  close_message();
}
////////////////////////////////////////////////////////////
//messages
/*Next two functions are messages to serial to give indications 
 * what is happening open and close.
*/
void open_message()
{
  Serial.println("open door");

}
void opening_message()
{
  Serial.println("Door Opening");
  
}

void close_message()
{
  Serial.println("close door");
}
void closing_message()
{
  Serial.println("Door Closing");
}

void half_message()
{
  Serial.println("Door Half Open");
}

////////////////////////////////////////////////////////////
//operations
/*Functions include:
 * power_garage() will send a power signal to the opener.
 * signal HIGH for 1 second than return LOW.
 * 
*/
void power_garage()
{
  digitalWrite(signal_garage_out, HIGH);
  delay(500);
  digitalWrite(signal_garage_out, LOW);
  //comment out aftwer proto
  digitalWrite(motor,HIGH);
  delay(1500);
  digitalWrite(motor,LOW); 
}

/////////////////////////////////////////////////////////////
//reed signal check
/*This section of functions will check the status/position of 
 * garage door.
*/

void reed_check()
{

  if ( reed_closed == HIGH)
  {
    close_message();
  }
   else if (reed_half == HIGH)
   {
     half_message();
   }
  else if (reed_open == HIGH)
  {
    open_message();
  }
}
