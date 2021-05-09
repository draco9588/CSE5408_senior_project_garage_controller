import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';
import 'dart:io';

void main() async {
  Socket sock = await Socket.connect( '76.171.95.127', 80);
  runApp(MyApp(sock));
}
class MyApp extends StatelessWidget {
  Socket _socket;
  MyApp(Socket s) {
    this._socket = s;
  }
  @override

  Widget build(BuildContext context){
    return MaterialApp(
        initialRoute: '/home',
        routes: {
          '/home': (context) => ControllerApp(),
          '/network': (context) => Network(),
        },
      home: _MyHomePage(
        channel: _socket,

      ),

    );
  }
}
class _MyHomePage extends StatefulWidget{
  final Socket channel;
  _MyHomePage({Key key, this.channel}) : super(key: key);
  _MyHomePageState createState() => _MyHomePageState();
}
class _MyHomePageState extends State<_MyHomePage> {

  void _open() {
    widget.channel.write("OPEN\n");
  }
  void _halfOpen() {
    widget.channel.write("HALF OPEN\n");
  }
  void _close() {
    widget.channel.write("CLOSED\n");
  }
  @override
  void dispose() {
    widget.channel.close();
    super.dispose();
  }
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Menu',
      home: Scaffold(
        appBar: AppBar(
          backgroundColor: const Color.fromRGBO(180, 40, 20, 1.0),
          title: Text('Menu'),
        ),
        drawer: Drawer(
          child: ListView(
            padding: EdgeInsets.only(top: 55),
            children: <Widget>[
              ListTile(
                title: Text('Home'),
                onTap: () {
                  // What happens after you tap the navigation item
                  Navigator.pushNamed(context, '/home');
                },
              ),
              ListTile(
                title: Text('Network'),
                onTap: () {
                  // What happens after you tap the navigation item
                  Navigator.pushNamed(context, '/network');
                },
              ),
            ],
          ),
        ),
       /* body:
        Column(
            mainAxisAlignment: MainAxisAlignment.end,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: <Widget>[
              Container(
                height: MediaQuery.of(context).size.height * 55/100,
                width: MediaQuery.of(context).size.width,
                child: Text ('Placeholder for IMG', style: TextStyle(fontSize:(20)) ,textAlign: TextAlign.center,), // Remove line when adding IMG below
                decoration: BoxDecoration(
                  color: Color.fromRGBO(120, 120, 120, 1.0),
                  /*   image: DecorationImage(
                    image: AssetImage('Image location here'),
                    fit: BoxFit.fill,
                  ), */
                  shape: BoxShape.rectangle,
                ),
              ),
              SizedBox(height: 50),
              Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    ElevatedButton(
                      onPressed: ()
                      {
                        _open();
                        print('OPEN');
                      },
                      child: Text('Open Door'),
                    ),
                    ElevatedButton(
                      onPressed: ()
                      {
                        _halfOpen();
                        print('HALF OPEN');
                      },
                      child: Text('Half Open'),
                    ),
                    ElevatedButton(
                      onPressed: ()
                      {
                        _close();
                        print('CLOSED');
                      },
                      child: Text('Close Door'),
                    ),
                  ]
              ),
            ]), */
      ),
    );
  }
}
class ControllerApp extends StatelessWidget {
  @override
  Widget build(BuildContext context)
  {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('CSE Garage Controller'),
          centerTitle: true,
          toolbarHeight: 30,
        ),
        body:
        Column(
            mainAxisAlignment: MainAxisAlignment.end,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: <Widget>[
              Container(
                height: MediaQuery.of(context).size.height * 55/100,
                width: MediaQuery.of(context).size.width,
                child: Text ('Placeholder for IMG', style: TextStyle(fontSize:(20)) ,textAlign: TextAlign.center,), // Remove line when adding IMG below
                decoration: BoxDecoration(
                  color: Color.fromRGBO(120, 120, 120, 1.0),
                  /*   image: DecorationImage(
                    image: AssetImage('Image location here'),
                    fit: BoxFit.fill,
                  ), */
                  shape: BoxShape.rectangle,
                ),
              ),
              SizedBox(height: 50),
              Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
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
            ]),
      ),
    );
  }
}
class Network extends StatelessWidget {
  TextEditingController _textOut = TextEditingController();
  String network = 'none';
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Network Connection'),
          centerTitle: true,
          toolbarHeight: 30,
        ),
        body:
        Column(
            mainAxisAlignment: MainAxisAlignment.start,
            children: <Widget>[
              Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  crossAxisAlignment: CrossAxisAlignment.center,
                  children: <Widget>[
                    Container(

                      height: 25,
                      width: 240,
                      color: Color.fromRGBO(120, 120, 120, 1.0),
                      child: TextField(
                        controller: _textOut,
                        decoration: InputDecoration(
                          border: OutlineInputBorder(),
                          labelText: 'IP Address',
                          hintText: 'Enter IP Address here',
                        ),
                      ),
                    ),
                    ElevatedButton(
                      onPressed: ()
                      {
                        network = _textOut.text;
                        print('connect');
                      },
                      child: Text('connect'),
                    ),
                  ]
              ),

            ]),
      ),
    );
  }
}






