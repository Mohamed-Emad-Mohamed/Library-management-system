#ifndef User_H
#define User_H

#include <string.h>
#include <regex>
#include "SHA256.h"

class User{
    private:
    unsigned int userID;
    string name;
    string email;
    string password;
    virtual bool checkPassValidation(string pass) final{
        regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
        return regex_match(pass, pattern);
    }
    virtual bool checkEmailValidation(string email_user) final{
        regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
        return regex_match(email_user, pattern);
    }
    virtual bool checkNameValidation(string name_user) final{
        regex pattern("^[A-Z][a-zA-Z ]*$");
        return regex_match(name_user, pattern);
    }
    virtual string hashPassword(string pass) final{
        return sha256(pass);
    }
    public:
    bool registerUser(string name_of_user , string email_of_user , string password_of_user);
};
 

#endif