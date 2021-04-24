import 'package:flutter/material.dart';
import 'socket.dart';
void main() =>  runApp(ControllerApp());

class ControllerApp extends StatelessWidget
{
  @override
  Widget build(BuildContext context)
  {
    return MaterialApp(
      home: Scaffold(
       appBar: AppBar(
          title: Text('CSE Garage Controller'),
         centerTitle: true,
      ),
        body:
        Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: <Widget>[
                ElevatedButton(
                onPressed: ()
                {
                print('OPEN');
                },
                child: Text('Open Door'),
                ),
                ElevatedButton(
                onPressed: ()
                {
                print('HALF OPEN');
                },
                child: Text('Half Open'),
                ),
                ElevatedButton(
                    onPressed: ()
                    {
                      print('CLOSED');
                    },
                    child: Text('Close Door'),
                  ),
                ]
                ),

                ),
                );
  }


}






