#include <iostream>
#include <fstream>
#include <cstring>
//#include "event.h"
//#include "date.h"
#include "user.h"
#include "user.cpp"

const int MAXLEN = 41;

//char* loginUser(char* name, char* password) {
    //return database;
//}

bool validateName(const char* name) {
    unsigned int lenght = strlen(name);

    for(int i = 0; i < lenght; i++) 
    {
        if(name[i]>='A' && name[i]<='Z' || name[i]>='a' && name[i]<= 'z') {}
        else
        {
            return false;
        }
    }
    return true;
}

void createobject(const char* name, const char* password, const char* email) 
{
    User currentUser(name, password, email);
}

int main() {
    char name[MAXLEN];
    char password[MAXLEN];
    char email[MAXLEN];
    int option;
    std::cout<<"Program started."<<std::endl;
    std::cout<<"Choose one of three:"<<std::endl;
    std::cout<<"1. Login"<<std::endl;
    std::cout<<"2. Register"<<std::endl;
    std::cout<<"3. Search for an event by destination"<<std::endl;
    std::cin>>option;
    while(option<1 || option>3) {
        std::cout<<"Try again:";
        std::cin>>option;
    }
    
    switch(option) 
    {
        case 1:
            //Login User
            std::cout<<"Enter username:";
            std::cin.getline(name, MAXLEN);
            std::cout<<"Enter password:";
            std::cin.getline(password, MAXLEN);
            break;
        
        case 2:
            //Register User
            std::cin.ignore();
            std::cout<<"Enter username:";
            std::cin.getline(name, MAXLEN+1);
            while(!validateName(name) && strlen(name)==MAXLEN) 
            {
                std::cout<<"Username can only contain latin characters and must be up to 40 characters!"<<std::endl;
                std::cout<<"Enter username:";
                std::cin.getline(name, MAXLEN+1);
            }
            std::cout<<"Enter password:";
            std::cin.getline(password, MAXLEN+1);
            while(strlen(password)==MAXLEN) 
            {
                std::cout<<"Passwords must be up to 40 characters!"<<std::endl;
                std::cout<<"Enter password:";
                std::cin.getline(password, MAXLEN+1);
            }
            std::cout<<"Enter email:";
            std::cin.getline(email, MAXLEN+1);
            while(strlen(email)==MAXLEN) 
            {
                std::cout<<"Emails must be up to 40 characters!"<<std::endl;
                std::cout<<"Enter email:";
                std::cin.getline(email, MAXLEN+1);
            }
            createobject(name, password, email);
            //create object user!
            break;

        case 3:
            //Search for events
            break;
    }
    //User currentUser(name, password, email);
    return 0;
}
