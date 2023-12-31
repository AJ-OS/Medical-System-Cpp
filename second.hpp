#ifndef SECOND_HPP
#define SECOND_HPP

#include <iostream>
#include <string>

int welcomeMsg (); 

void spacing (); 

void randomKey (); 

bool gatherUserData();

void bmiCheck (); 

// temp function
template <typename A>
A get_user_input(const std::string &prompt);

// External Vars
extern std::string first_name;
extern std::string last_name;
extern int age;
extern float height;
extern float weight;
extern std::string phone_num;
extern std::string e_mail;
extern std::string input_first; 
extern std::string line;
extern std::string input_last; 
extern double bmi;
extern std::string saved_first;
extern std::string saved_last; 
extern bool found_first = false;
extern bool found_second = false;

#endif
