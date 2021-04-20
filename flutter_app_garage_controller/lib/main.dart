import 'dart:html';

import 'package:flutter/material.dart';

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
        body: Center(
          child: RaisedButton(
            onPressed: ()
            {
              print('Click');
            },
            child: Text('A button '),
          ),
      ),

      ),
      );


  }
}





