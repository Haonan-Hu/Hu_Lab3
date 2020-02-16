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
  m_arrLinear = new User[m_size_L];
  m_arrQuadratic = new User[m_size_Q];
  lambdaLinear = 0.0;
  lambdaQuadratic = 0.0;
}

HashTable::~HashTable()
{
  delete[] m_arrLinear;
  delete[] m_arrQuadratic;
}

double HashTable::getLambdaLinear()
{
  double factor = 0;
  for(int i = 0; i < m_size_L; i++)
  {
    if(m_arrLinear[i].getName() != "")
    {
      factor++;
    }
  }
  lambdaLinear = factor / m_size_L;
  return lambdaLinear;
}

double HashTable::getLambdaQuadratic()
{
  double factor = 0;
  for(int i = 0; i < m_size_Q; i++)
  {
    if(m_arrQuadratic[i].getName() != "")
    {
      factor++;
    }
  }
  lambdaQuadratic = factor / m_size_Q;
  return lambdaQuadratic;
}

int HashTable::asciiToInt(std::string password)
{
  int sum = 0;
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
  }
  return sum;
}

int HashTable::linerProbing(std::string password, User* user)
{
  int index = 0;
  int x = asciiToInt(password);
  int k = m_size_L;
  for(int i = 0; i < k; i++)
  {
    int temp = 0;
    if(i == 0)
    {
      temp = x % m_size_L;
    }
    else
    {
      temp = (x % m_size_L + i) % m_size_L;
    }
    if(user[temp].isEmpty())
    {
      index = temp;
      break;
    }
  }
  return index;
}

int HashTable::quadraticProbing(std::string password, User* user)
{
  int index = 0;
  int x = asciiToInt(password);
  int k = m_size_Q;
  for(int i = 0; i < k; i++)
  {
    int temp = 0;
    if(i == 0)
    {
      temp = x % m_size_Q;
    }
    else
    {
      temp = (x % m_size_Q + i*i) % m_size_Q;
    }
    if(user[temp].isEmpty())
    {
      index = temp;
      break;
    }
  }
  return index;
}

bool HashTable::isPrime(int num)
{
  if (num <= 1)
  {
    return false;
  }
  if (num <= 3)
  {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0)
  {
    return false;
  }

  for (int i=5; i * i <= num; i=i+6)
  {
    if (num % i == 0 || num % (i + 2) == 0)
    {
      return false;
    }
  }
  return true;
}

int HashTable::nextPrime(int num)
{
  if (num <= 1)
  {
    return 2;
  }
  int prime = num;
  bool found = false;
  while (!found)
  {
    prime++;
    if (isPrime(prime))
    found = true;
  }
  return prime;
}

void HashTable::rehash()
{
  int prevSize_L = m_size_L;
  int prevSize_Q = m_size_Q;
  int newSize_L = nextPrime(2 * prevSize_L);
  int newSize_Q = nextPrime(2 * prevSize_Q);
  if(getLambdaLinear() > 0.5 || getLambdaQuadratic() > 0.5)
  {
    m_size_L = newSize_L;
    m_size_Q = newSize_Q;
    User* temp_Q = new User[newSize_Q];
    User* temp_L = new User[newSize_L];
    for(int i = 0; i < prevSize_L; i++)
    {
      if(!m_arrLinear[i].isEmpty())
      {
        int rehashIndex_L = 0;
        rehashIndex_L = linerProbing(m_arrLinear[i].getPassword(), temp_L);
        temp_L[rehashIndex_L].setName(m_arrLinear[i].getName());
        temp_L[rehashIndex_L].setPassword(m_arrLinear[i].getPassword());
      }
    }
    for(int i = 0; i < prevSize_Q; i++)
    {
      if(!m_arrQuadratic[i].isEmpty())
      {
        int rehashIndex_Q = 0;
        rehashIndex_Q = quadraticProbing(m_arrQuadratic[i].getPassword(), temp_Q);
        temp_Q[rehashIndex_Q].setName(m_arrQuadratic[i].getName());
        temp_Q[rehashIndex_Q].setPassword(m_arrQuadratic[i].getPassword());
      }
    }
    m_arrQuadratic = temp_Q;
    m_arrLinear = temp_L;
  }
  else
  {
    std::cout << "Dont need to rehash yet\n";
  }
}


void HashTable::addUser(std::string userName, std::string password)
{
  int indexLinear = linerProbing(password, m_arrLinear);
  int indexQuadratic = quadraticProbing(password, m_arrQuadratic);
  m_arrLinear[indexLinear].setName(userName);
  m_arrLinear[indexLinear].setPassword(password);
  m_arrQuadratic[indexQuadratic].setName(userName);
  m_arrQuadratic[indexQuadratic].setPassword(password);
}

void HashTable::printUser()
{
  std::cout << "\e[4mLinear Probing:\e[0m\n";
  for(int i = 0; i < m_size_L; i++)
  {
    std::cout << i << ':';
    if(m_arrLinear[i].isEmpty())
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
  for(int i = 0; i < m_size_Q; i++)
  {
    std::cout << i << ':';
    if(m_arrQuadratic[i].isEmpty())
    {
      std::cout << "\n";
    }
    else
    {
      std::cout << m_arrQuadratic[i].getName() << ':';
      std::cout << m_arrQuadratic[i].getPassword() << '\n';
    }
  }
  std::cout << "\n\n\n";
}
