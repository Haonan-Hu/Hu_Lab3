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
  double getLambdaLinear();
  double getLambdaQuadratic();
  void rehash();
  int asciiToInt(std::string password);
  bool checkDup(std::string userName);

private:
  User* m_arrLinear; // linear probing method hash table
  User* m_arrQuadratic; // quadratic probing method hash table
  int m_size_L = 11; // HashTable size for Linear probing method
  int m_size_Q = 11 ; // HashTable size for Quadratic probing method
  double lambdaLinear = 0.0;
  double lambdaQuadratic = 0.0;
  int linerProbing(std::string password, User* user);
  int quadraticProbing(std::string password, User* user);
  int nextPrime(int num);
  bool isPrime(int num);
};
#endif
