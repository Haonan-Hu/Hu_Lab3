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
private:
  User* m_arr; // User objects array
  int m_size; // HashTable size
  int m_arrObjs; // number of items in the array
  double load_factor = 0.0; // m_arrObjs / m_size
  int linerProbing(std::string password);
  int quadraticProbing(std::string password);
};
#endif
