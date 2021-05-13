import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';
import 'dart:io';

void main() async{
  Socket sock = await Socket.connect('192.168.4.1', 23);
  runApp(ControllerApp(sock));
}

class ControllerApp extends StatelessWidget
{
  Socket socket;
  ControllerApp(Socket s){
    this.socket = s;
  }
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
        channel: _socket,
                ),
                );
  }
class myHomePage extends StatefulWidget
  {
    final Socket channel;
    myHomePage({Key key, this.title, this.channel}) : super(key: key);
  }

}






