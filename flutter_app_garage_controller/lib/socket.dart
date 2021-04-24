import 'dart:io';

import 'package:flutter/material.dart';

void main()
{
  ServerSocket.bind('192.168.4.1:23', 23).then((ServerSocket server){
    server.listen(handleClient);
  }
  );
}

void handleClient(Socket client)
{
  print('Connection from '
      '${client.remoteAddress.address}:${client.remotePort}');

  client.write("Hello from simple server!\n");
  client.close();
}