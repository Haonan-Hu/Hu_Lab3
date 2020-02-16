/*
Author: Haonan Hu
File: Executive.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "Executive.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <limits>

executive::executive(std::string fileName)
{
  std::ifstream infile;
  infile.open(fileName);
  std::string data;
  std::string name;
  std::string password;
  int length;
  if(infile.is_open())  //  file read successful
  {
    while(std::getline(infile, data)) // make sure file input is valid
    {
      length = data.length();
      int index = data.find(',');
      for(int i = 0; i < index; i++)
      {
        name = name + data.at(i);
      }
//      std::cout << "name: " << name << '\n';
      for(int i = index + 1; i < length; i++)
      {
        password = password + data.at(i);
      }
//      std::cout << "password: " << password << '\n';
      m_hash.addUser(name, password);
      name = "";
      password = "";
    }
    std::cout << "\n\n\n\n\n\n";
    infile.close();
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  m_hash.addUser("dotnet", "onl223");
  m_hash.printUser();
}
