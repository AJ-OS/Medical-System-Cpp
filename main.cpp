#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "second.hpp"

/*
Compile: g++ main.cpp second.cpp -o main
Output: ./main
*/

int main ()
{
    switch (welcomeMsg())
    {
        // patient 
        case 1: 
        spacing (); 
        std::cout << "Patient Selected." << std::endl; 
        spacing (); 
        break;

        // Create a User
        case 2:
        spacing (); 
        std::cout << "Create a Patient Login Selected." << std::endl;
        if (gatherUserData()) {
        std::ofstream info;
        info.open("Medical-Data.csv", std::ios::app);

        // check if file is open
        if (!info.is_open()) {
            std::cout << "Error!" << std::endl;
        } else {
            // write headers & checks for previous header 
            if (info.tellp() == 0) 
            { 
                // set headers
            info << "First Name" << "," << "Last Name" << "," << "Age" << "," << "Height (M)" << "," << "Weight (lbs)" << "," << "Phone Number" << "," << "Email" << std::endl;
            }
                //set given info
            info << first_name << "," << last_name << "," << age << "," << height << "," << weight << "," << phone_num << "," << e_mail <<  std::endl;

            info.close();
        }
    } else {
        // error
        std::cout << "Error! No Info" << std::endl;
    } 
        spacing (); 
        break;

        // Doctor
        case 3: 
        spacing (); 
        std::cout << "Doctor Selected." << std::endl; 
        spacing (); 
        break;

        // admin
        case 4:
        spacing (); 
        std::cout << "Admin Selected." << std::endl; 
        spacing (); 
        break;

        // exit
        case 5:
        spacing (); 
        std::cout << "Closing Program!" << std::endl; 
        spacing (); 
        return 0;
        break;

        default: 
        std::cout << "Invalid Input" << std::endl; 
        return 0;
    }
}