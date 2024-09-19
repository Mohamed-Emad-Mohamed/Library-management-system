#include "User.h"

bool User :: registerUser(string name_of_user , string email_of_user , string password_of_user){
       bool name_state =  checkNameValidation(name_of_user);
       bool email_state = checkEmailValidation(email_of_user); 
       bool pass_state =  checkPassValidation(password_of_user);
       if (pass_state && email_state && name_state){
        name = name_of_user;
        email = email_of_user;
        password = hashPassword(password_of_user);
       }
       else {
       }
    }