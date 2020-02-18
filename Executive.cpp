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
  std::cout.setstate(std::ios_base::failbit);
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
      for(int i = index + 1; i < length; i++)
      {
        password = password + data.at(i);
      }
      if(m_hash.getLambdaLinear() > 0.5 || m_hash.getLambdaQuadratic() > 0.5)
      {
        m_hash.rehash();
      }
      else
      {
        m_hash.addUser(name, password);
      }
      name = "";
      password = "";
    }
    infile.close();
    std::cout.clear();
    std::cout << "\e[1mFile reading done, ready for next step:\e[0m\n";
    std::cout << "..................................\n\n";
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){

}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "make a selection: \n";
    std::cout << "1) Add User\n";
    std::cout << "2) Remove User\n";
    std::cout << "3) Forgot Password\n";
    std::cout << "4) Forgot Username\n";
    std::cout << "5) Print Users\n";
    std::cout << "6) Exit\n";
    std::cin >> choice;
    std::cout << '\n';
    while(1)
    {
      if(std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input!\n\n";
        std::cout << "..................................\n\n";
        std::cout << "Choose one operation from the options below: \n\n";
        std::cout << "make a selection: \n";
        std::cout << "1) Add User\n";
        std::cout << "2) Remove User\n";
        std::cout << "3) Forgot Password\n";
        std::cout << "4) Forgot Username\n";
        std::cout << "5) Print Users\n";
        std::cout << "6) Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {
      std::string name = "";
      std::string pass = "";
      std::cout << "Enter details to be added: \n";
      std::cout << "Name: ";
      std::cin >> name;
      std::cout << "Password: ";
      std::cin >> pass;
      std::cout << "\n\n";
      if(m_hash.getLambdaLinear() > 0.5 || m_hash.getLambdaQuadratic() > 0.5)
      {
        m_hash.rehash();
        m_hash.addUser(name, pass);
      }
      else
      {
        m_hash.addUser(name, pass);
      }
      std::cout << "..................................\n\n";
    }
    else if(choice == 2)
    {
      std::string name = "";
      std::string pass = "";
      std::cout << "Enter username and password to be removed: \n";
      std::cout << "Name: ";
      std::cin >> name;
      std::cout << "Password: ";
      std::cin >> pass;
      std::cout << "\n\n";
      m_hash.removeUser(name, pass);
      std::cout << "..................................\n\n";
    }
    else if(choice == 3)
    {
      m_hash.forgotPassword();
      std::cout << "..................................\n\n";
    }
    else if(choice == 4)
    {
      m_hash.forgotUserName();
      std::cout << "..................................\n\n";
    }
    else if(choice == 5)
    {
      m_hash.printUser();
      std::cout << "..................................\n\n";
    }
    else if(choice == 6)
    {
      std::cout << "Program execution complete!\n";
      break;
    }
    else
    {
      std::cout << " Wrong input!\n\n";
      std::cout << "..................................\n\n";
    }
  }
}
