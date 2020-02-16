/*
Author: Haonan Hu
File: User.cpp
Date:2/10/2020
Brief:File is cpp file
*/
#include "User.h"

User::User(std::string userName, std::string password)
{
	m_userName = userName;
	m_password = password;
	m_deleted = false;
}

void User::setPassword(std::string password)
{
	m_password = password;
}

std::string User::getPassword()const
{
	return m_password;
}

void User::setName(std::string userName)
{
	m_userName = userName;
}

std::string User::getName()const
{
	return m_userName;
}

bool User::isEmpty()
{
	if(m_userName.length() == 0 || m_password.length() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void User::setDeletion(bool deleted)
{
	m_deleted = deleted;
}

bool User::isDeleted()
{
	return m_deleted;
}

void User::operator=(User user)
{
	m_userName = user.getName();
	m_password = user.getPassword();
}
