/*
Author: Haonan Hu
File: User.h
Date:2/15/2020
Brief:File is header file
*/
#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
	std::string m_userName;
	std::string m_password;
	bool m_deleted = false;

public:
	/**
	* @pre none
	* @post construct an item with given value
	* @param entry,the value of item
	*/
	User() {};
	~User(){};
	/**
	* @pre none
	* @post construct an item with given value
	* @param entry,the value of item
	*/
	User(std::string userName, std::string password);
	/**
	* @pre none
	* @post set the value of existing item
	* @param entry, the value of item
	*/
	void setPassword(std::string password);
	/**
	* @pre none
	* @post get the value of a existing item
	* @return the value of item
	*/
	std::string getPassword()const;
	/**
	* @pre none
	* @post the the next item of
	* @return the next item
	*/
	void setName(std::string userName);
	/**
	* @pre none
	* @post the the next item of
	* @return the next item
	*/
	std::string getName()const;
	bool isEmpty()const;
	bool isDeleted()const;
	void setDeletion(bool deleted);
	void operator=(User user);
};
#endif
