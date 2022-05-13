#pragma once


const int MAX = 41;
const char database_file[] = "userinfo.db";

class User {
    char username[MAX];
    char password[MAX];
    char email[MAX];
    char dbname[MAX+3];

public:
    User(const char* name, const char* password, const char* email); // constructor-- create file



    void setUsername(const char* name);
    void setPassword(const char* password);
    void setEmail(const char* email);

    const char* getUsername() const;
    const char* getPassword() const;
    const char* getEmail() const;

    void openDB(const char* name);

    void recordUser(const char* name, const char* password, const char* email);
};