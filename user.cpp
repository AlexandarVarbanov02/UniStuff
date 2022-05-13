#include <iostream>
#include <cstring>
#include <fstream>
#include "user.h"

User::User(const char* name, const char* password, const char* email)
{
    setUsername(name);
    setPassword(password);
    setEmail(email);
    openDB(name);
    recordUser(name, password, email); //for now -- later needs to check if there is a user already!!!
}

void User::setUsername(const char* username) 
{
    strcpy(this->username, username);
}
void User::setPassword(const char* password)
{
    strcpy(this->password, password);
}
void User::setEmail(const char* email)
{
    strcpy(this->email, email);
}

void User::openDB(const char* username)
{
    strcpy(dbname, username);
    strcat(dbname, ".db");
    std::ofstream user_database;
    user_database.open(dbname);
    user_database.close();
}

const char* User::getUsername() const {
    return username;
}

const char* User::getPassword() const {
    return password;
}

const char* User::getEmail() const
{
    return email;
}

void User::recordUser(const char* name, const char* password, const char* email)
{
    std::ofstream main_database;
    main_database.open(database_file, std::ios::out | std::ios::app);
    if(main_database.is_open())
    {
        main_database << "Username::" << name << "\n";
        main_database << "Password::" << password << "\n";
        main_database << "Email::" << email << "\n";
        main_database.close();
    }
    else
    {
        std::cout<<"Unable to save user info!";
    }


}