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
  m_arrLinear = new User[11];
  m_arrQuadratic = new User[11];
}

HashTable::~HashTable()
{
  delete[] m_arrLinear;
}

int HashTable::getLambda()
{
  int factor = 0;
  for(int i = 0; i < m_size; i++)
  {
    if(m_arrLinear[i].getName() != "")
    {
      factor++;
    }
  }
  lambda = factor / m_size;
  return lambda;
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
  if(m_arrLinear[index1].getName() == "")
  {
    return index1;
  }
  else
  {
    // case 2: Have collision
    index2 = index1;
    while(m_arrLinear[index2].getName() != "")
    {
      index2 = (index1 + hashNum) % 11;
      hashNum++;
    }
  //  std::cout << index2 << '\n';
    return index2;
  }
}

int HashTable::quadraticProbing(std::string password)
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
  if(m_arrLinear[index1].getName() == "")
  {
    return index1;
  }
  else
  {
    // case 2: Have collision
    index2 = index1;
    while(m_arrLinear[index2].getName() != "")
    {
      index2 = (index1 + hashNum * hashNum) % 11;
      hashNum++;
    }
  //  std::cout << index2 << '\n';
    return index2;
  }
}

void HashTable::addUser(std::string userName, std::string password)
{
  int indexLinear = linerProbing(password);
  int indexQuadratic = quadraticProbing(password);
//  std::cout << index << '\n';
  m_arrLinear[indexLinear].setName(userName);
  m_arrLinear[indexLinear].setPassword(password);
  m_arrQuadratic[indexQuadratic].setName(userName);
  m_arrQuadratic[indexQuadratic].setPassword(password);
//  std::cout << m_arrLinear[index].getName() << ',' << m_arrLinear[index].getPassword();
}

void HashTable::printUser()
{
  std::cout << "\e[4mLinear Probing:\e[0m\n";
  for(int i = 0; i < m_size; i++)
  {
    std::cout << i << ':';
    if(m_arrLinear[i].getName() == "")
    {
      std::cout << "\n";
    }
    else
    {
      std::cout << m_arrLinear[i].getName() << ':';
      std::cout << m_arrLinear[i].getPassword() << '\n';
    }
  }
  std::cout << "\n\n\n";
  std::cout << "\e[4mQuadratic Probing:\e[0m\n";
  for(int i = 0; i < m_size; i++)
  {
    std::cout << i << ':';
    if(m_arrQuadratic[i].getName() == "")
    {
      std::cout << "\n";
    }
    else
    {
      std::cout << m_arrQuadratic[i].getName() << ':';
      std::cout << m_arrQuadratic[i].getPassword() << '\n';
    }
  }
}
