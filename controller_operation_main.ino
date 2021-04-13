
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
//chars used for incoming commands from Phone Application
char temp[50];
char compare;

void setup()
{
  // put your setup code here, to run once:
  //set baudrate
  Serial.begin(115200);
  //set button source
  pinMode(signal_button_in, INPUT); //set input to read when button is pushed
  pinMode(signal_button_out, OUTPUT); //set as output
  digitalWrite(signal_button_out, HIGH); //send power to button
  pinMode(signal_garage_in, INPUT); //set input to read garage signal
  pinMode(signal_garage_out, OUTPUT); //set as output to control opener
}

void loop()
{
  // put your main code here, to run repeatedly:

String incoming;
  
 //reading phone commands to string incoming
  unsigned int length;
  
    if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incoming = Serial.readString();
    incoming.toCharArray(temp,50);
    length = incoming.length();
  }

  Serial.println("This is direction: ");
  Serial.println(incoming);
  compare = temp[length-1];
  Serial.println(compare);
  delay(1500);
}

void door_operation()
{
  switch (compare)
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
  
}

void half_open_door()
{
  open_message();
  
}

void close_door()
{
  close_message();
}

//Next two functions are messages to serial to give indications what is happening open and close
void open_message()
{
  Serial.println("open door");

}

void close_message()
{
  Serial.println("close door");
}
