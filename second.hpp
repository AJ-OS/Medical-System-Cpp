#ifndef SECOND_HPP
#define SECOND_HPP

#include <iostream>
#include <string>

int welcomeMsg (); 

void spacing (); 

// temp func
template <typename A>
A get_user_input(const std::string &prompt);

bool gatherUserData();

// External Vars
extern std::string first_name;
extern std::string last_name;
extern int age;
extern float height;
extern float weight;
extern std::string phone_num;
extern std::string e_mail;


#endif