import 'package:flutter/material.dart';
void main() => runApp(MyApp());
class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  Widget mainWidget = ControllerApp();@override
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
                  setState(() {
                    mainWidget = ControllerApp();
                  });
                  Navigator.pop(context);
                },
              ),
              ListTile(
                title: Text('Network'),
                onTap: () {
                  // What happens after you tap the navigation item
                  setState(() {
                    mainWidget = Network();
                  });
                  Navigator.pop(context);
                },
              ),
            ],
          ),
        ),
        body: mainWidget, // Here
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
  String network = 'None';
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
                      child: Text (network, style: TextStyle(fontSize:(20)) ,textAlign: TextAlign.center,),
                      color: Color.fromRGBO(120, 120, 120, 1.0),
                    ),

                    ElevatedButton(
                      onPressed: ()
                      {
                        print('Disconnected');
                      },
                      child: Text('Disconnect'),
                    ),
                  ]
              ),

            ]),
      ),
    );
  }
}






