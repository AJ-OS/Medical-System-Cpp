#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "second.hpp"

/*
Compile: g++ main.cpp second.cpp -o main
Output: ./main
*/

int main ()
{
    std::string saved_user;
    std::ifstream classFile("Medical-Data.csv");
    std::string line;
    std::ofstream File;
    switch (welcomeMsg())
    {
        // patient 
        case 1: 
        spacing (); 
        std::cout << "Patient Selected." << std::endl; 
        spacing ();  
        
        std::cout << "Enter your First Name: " << std::endl;
        std::cin >> input_first; 

        bool valueFile; 
            // refer to stack - https://stackoverflow.com/questions/19936483/c-reading-csv-file?rq=3
            while (std::getline(classFile, line)) 
            {
                // finish later
                return 0;
            }
        

        if (valueFile == true)
        {
            std::cout << "Information Found!" << std::endl; 
        } 
        else 
        {
            std::cout << "Error finding Info." << std::endl;
            return 0;
        }
        
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
            info << first_name << "," << last_name << "," << age << "," << height << "," << weight << "," << phone_num << "," << e_mail << std::endl;
            
            std::cout << "Profile Created Successfully!" << std::endl; 

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
        std::cout << "Clearing Data!" << std::endl; 
        File.open("Medical-Data.csv", std::ios::trunc);
        File.close();

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