
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
  digitalWrite(signal_button_out, HIGH); //send power to button
  //set garage source
  pinMode(signal_garage_in, INPUT); //set input to read garage signal
  pinMode(signal_garage_out, OUTPUT); //set as output to control opener
  //reed pin assignment
  pinMode(reed_open, INPUT); //set input to read reed signal
  pinMode(reed_half, INPUT); //set input to read reed signal
  pinMode(reed_closed, INPUT); //set input to read reed signal
}

//////////////////////////////////////////////////////////////
void loop()
{
  // put your main code here, to run repeatedly:
  int val_x = 0;
  int val_y = 0;
  
do
{
 String incoming;
 
  val_x = digitalRead(signal_button_in);
  val_y = digitalRead(signal_garage_in);
  
 //reading phone commands to string incoming
  unsigned int length_incoming;
  
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incoming = Serial.readString();
    incoming.toCharArray(temp,50);
    length_incoming = incoming.length();
  }

  Serial.println("This is direction: ");
  Serial.println(incoming);
  compare = temp[length_incoming-1];
  Serial.println(compare);
  door_operation(compare);
  delay(1500);
}while( val_x == LOW || val_y == LOW);

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
  opening_message();
  power_garage();
  open_message();
}

void half_open_door()
{
  opening_message();
  power_garage();
  
  power_garage();
  half_message();
}

void close_door()
{
  closing_message();
  power_garage();
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
 * read_signal(x,y) will monitor garage open button and 
 * kill signal from trip sensor at the bottom of the garage door.
*/
void power_garage()
{
  digitalWrite(signal_garage_out, HIGH);
  delay(1000);
  digitalWrite(signal_garage_out, LOW);
}

/*int read_signal(int x, int y)
{
  int val_x = 0;
  int val_y = 0;
  val_x = digitalRead(x);
  val_y = digitalRead(y);
  return val_x, val_y;
}*/

/////////////////////////////////////////////////////////////
//reed signal check
/*This section of functions will check the status/position of 
 * garage door.
*/

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
