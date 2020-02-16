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
  std::string temp;
  int score;

  if(infile.is_open())  //  file read successful
  {
    while(std::getline(infile, data)) // make sure file input is valid
    {
    }
    infile.close();
  }
  else
    std::cout << "Unable to open file\n";
}

executive::~executive(){}

void executive::run()
{
  int choice;
  for(;;)
  {
    std::cout << "make a selection: \n";
    std::cout << "1) AddPlayer\n";
    std::cout << "2) RemovePlayer\n";
    std::cout << "3) PrintPlayerList\n";
    std::cout << "4) PlayerWithGoalCountEqualTo(g)\n";
    std::cout << "5) PlayerWithNumGoalsGreaterThan(h)\n";
    std::cout << "6) PlayerWithNumGoalsLessThan(h)\n";
    std::cout << "7) Exit\n";
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
        std::cout << "1) AddPlayer\n";
        std::cout << "2) RemovePlayer\n";
        std::cout << "3) PrintPlayerList\n";
        std::cout << "4) PlayerWithGoalCountEqualTo(g)\n";
        std::cout << "5) PlayerWithNumGoalsGreaterThan(h)\n";
        std::cout << "6) PlayerWithNumGoalsLessThan(h)\n";
        std::cout << "7) Exit\n";
        std::cin >> choice;
        std::cout << '\n';
      }
      if(!std::cin.fail())
        break;
    }
    if(choice == 1)
    {

    }
    else if(choice == 2)
    {

    }
    else if(choice == 3)
    {

    }
    else if(choice == 4)
    {

    }
    else if(choice == 5)
    {

    }
    else if(choice == 6)
    {
      
    }
    else if(choice == 7)
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
