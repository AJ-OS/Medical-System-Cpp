#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "second.hpp"

/*
Compile: g++ main.cpp second.cpp -o main
Output: ./main
*/

/* Notes
add more secuitry for login (check lastname and age)
be able to change data once login
throw errors when missing info 
complete so I can began rewriting/coping as GUI (test)
*/

int main ()
{
    bool found_first = false;
    char comma; 
    std::string saved_first;
    std::ifstream medFile("Medical-Data.csv");
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

    while (std::getline(medFile, line))
    {
        std::istringstream ss(line);
        std::getline(ss, saved_first, ','); 

        if (saved_first == input_first)
        {
            found_first = true;
        } 

        if (found_first == true)
        {
            std::istringstream ss(line);
            std::string first_name, last_name, age, height, weight, phone_num, e_mail;
            spacing (); 
            std::cout << "Success!" << std::endl;
            std::getline(ss, first_name, ',');
            std::getline(ss, last_name, ',');
            std::getline(ss, age, ',');
            std::getline(ss, height, ',');
            std::getline(ss, weight, ',');
            std::getline(ss, phone_num, ',');
            std::getline(ss, e_mail, ',');

            spacing ();
            std::cout << "First Name: " << first_name << std::endl;
            std::cout << "Last Name: " << last_name << std::endl; 
            std::cout << "Age: " << age << std::endl;
            std::cout << "Height: " << height << " Meters"<< std::endl;
            std::cout << "Weight: " << weight << " Kg" << std::endl; 
            std::cout << "Phone Number: " << phone_num << std::endl; 
            std::cout << "Email: " << e_mail << std::endl;

            // BMI Calc
            double weightKg = std::stod(weight);
            double heightMeter = std::stod(height); 
            double bmi = weightKg / std::pow(heightMeter, 2);
            std::cout << "BMI: " << bmi << std::endl;
            std::cout << "BMI Info: ";  
            if (bmi < 18.5)
            {
                std::cout << "Under Weight" << std::endl;
            } 
            else if (bmi > 18.5 & bmi < 24.9)
            {  
                std::cout << "Healthy Weight" << std::endl;
            } 
            else if (bmi > 25 & bmi < 29.9)
            {
                std::cout << "Overweight" << std::endl;
            }
            else if (bmi > 30)
            {
                std::cout << "Obese" << std::endl; 
            }
            spacing ();
        } 

    }
        break;

        // Create a User (saves data to .csv)
        case 2:
        spacing (); 
        std::cout << "Create a Patient Login Selected." << std::endl;
        if (gatherUserData()) {
        std::ofstream info;
        info.open("Medical-Data.csv", std::ios::app);
        // check if file is open
        if (!info.is_open()) {
            std::cout << "Error!" << std::endl;
        } 
        else 
        {
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

        // admin (clear data)
        case 3:
        spacing (); 
        std::cout << "Clearing Data!" << std::endl; 
        File.open("Medical-Data.csv", std::ios::trunc);
        File.close();

        spacing (); 
        

        break;

        // exit
        case 4:
        spacing (); 
        std::cout << "Closing Program!" << std::endl; 
        spacing (); 

        return 0;
        break;

        default: 
        std::cout << "Invalid Input" << std::endl; 
        return 0;
    }

    return 0;

}