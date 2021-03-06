 
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
  digitalWrite(signal_button_out, LOW); //send power to button
  pinMode(signal_garage_in, INPUT); //set input to read garage signal
  pinMode(signal_garage_out, OUTPUT); //set as output to control opener
}

//////////////////////////////////////////////////////////////
void loop()
{
  // put your main code here, to run repeatedly:
  String incoming;

 //reading phone commands to string incoming
  unsigned int length;
    int val_x = 0;
  int val_y = 0;
  val_x = digitalRead(signal_button_in);
  val_y = digitalRead(signal_garage_in);

  if(val_x == HIGH)
  {
    Serial.println("Door opening on button");
    digitalWrite(signal_garage_out, HIGH);
    delay(5000);
    digitalWrite(signal_garage_out, LOW);
  }
  else if(val_y == HIGH)
  {
    Serial.println("Door opening on garage");
    digitalWrite(signal_garage_out, HIGH);
    delay(5000);
    digitalWrite(signal_garage_out, LOW);
  }
    if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incoming = Serial.readString();
    incoming.toCharArray(temp,50);
    length = incoming.length();
  }

  Serial.println("Operation is: ");
  Serial.println(incoming);
  compare = temp[0];
  Serial.println(compare);
  door_operation(compare);
  delay(1500);
}


/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

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

//Three function to control door operation
void full_open_door()
{
  open_message();
  power_garage();
}

void half_open_door()
{
  open_message();
  power_garage();
  delay(5500);
  power_garage();
  power_garage();
}

void close_door()
{
  close_message();
  power_garage();
}

//Next functions are messages to serial to give indications what is happening open and close
void open_message()
{
  Serial.println("Door Open");

}
void opening_message()
{
  Serial.println("Door Opening");
  
}

void close_message()
{
  Serial.println("Door Closed");
}
void closing_message()
{
  Serial.println("Door Closing");
}

void half_message()
{
  Serial.println("Door Half Open");
}

String clear_string(String x)
{
  x= "";
  return x;
}

char clear_char(char x)
{
  x="";
  return  x;
}
//operation
void power_garage()
{
  digitalWrite(signal_garage_out, HIGH);
  delay(2000);
  digitalWrite(signal_garage_out, LOW);
}

void reed_check(int x)
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
