/*
Author: Haonan Hu
File: Executive.h
Date:2/15/2020
Brief:File is header file
*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include "User.h"

class HashTable
{
public:
  HashTable();
  ~HashTable();
  void addUser(std::string userName, std::string password);
  void removeUser(std::string userName, std::string password);
  void printUser();
  int getLambda();
private:
  User* m_arrLinear; // linear probing method hash table
  User* m_arrQuadratic; // quadratic probing method hash table 
  int m_size; // HashTable size
  double lambda = 0.0; // m_arrObjs / m_size
  int linerProbing(std::string password);
  int quadraticProbing(std::string password);
};
#endif
