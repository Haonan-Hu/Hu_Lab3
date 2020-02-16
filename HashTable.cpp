/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/
#include "HashTable.h"
#include <stdlib.h>

HashTable::HashTable()
{
  m_size = 11;
  m_arrObjs = 0;
  m_arr = new User[11];
}

HashTable::~HashTable()
{
  delete[] m_arr;
}
int HashTable::linerProbing(std::string password)
{
  int index1 = 0;
  int index2 = 0;
  int sum = 0;
  int hashNum = 0;
  int passwordLength = password.length();
  //base case 1: No collision after first try
  for (int i = 0; i < passwordLength; i++)
  {
      int value = (int)password.at(i);
      if( value >= 48 && value <= 57)
      {
        value = value - (int)'0'; // convert char to int
      }
      sum = sum + value;
//     std::cout << sum << '\n';
  }
  hashNum++;
  index1 =sum % 11;
//  std::cout << index1 << '\n';
  if(m_arr[index1].getName() == "")
  {
    return index1;
  }
  else
  {
    // case 2: Have collision
    index2 = index1;
    while(m_arr[index2].getName() != "")
    {
      index2 = (index1 + hashNum) % 11;
      hashNum++;
    }
  //  std::cout << index2 << '\n';
    return index2;
  }
}

void HashTable::addUser(std::string userName, std::string password)
{
  int index = linerProbing(password);
//  std::cout << index << '\n';
  m_arr[index].setName(userName);
  m_arr[index].setPassword(password);
//  std::cout << m_arr[index].getName() << ',' << m_arr[index].getPassword();
}

void HashTable::printUser()
{
  for(int i = 0; i < m_size; i++)
  {
    std::cout << i << ':';
    if(m_arr[i].getName() == "")
    {
      std::cout << "\n";
    }
    else
    {
      std::cout << m_arr[i].getName() << ':';
      std::cout << m_arr[i].getPassword() << '\n';
    }
  }
}
