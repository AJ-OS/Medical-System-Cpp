#include "second.hpp"

// vars
std::string first_name;
std::string last_name;
int age;
float height;
float weight;
std::string phone_num;
std::string e_mail;
std::string input_first;
std::string line;
std::string input_last; 
double bmi;
std::string saved_first;
std::string saved_last; 
bool found_first = false;
bool found_second = false;

void spacing ()
{
    std::cout << "************" << std::endl;
}

int welcomeMsg ()
{
    std::cout << "[1] - Patient Login" << std::endl;
    std::cout << "[2] - Create Patient" << std::endl;
    std::cout << "[3] - Clear Data" << std::endl;
    std::cout << "[4] - Exit Program" << std::endl;
    int userInput;
    std::cin >> userInput;
    return userInput;
}

// function for gathering info
template <typename A>
A get_user_input(const std::string &prompt) {
    A input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}

// collect data
bool gatherUserData() {
    first_name = get_user_input<std::string>("Enter your First Name: ");
    last_name = get_user_input<std::string>("Enter your Last Name: ");
    age = get_user_input<int>("Enter your Age: ");
    height = get_user_input<float>("Enter your Height in Meters: ");
    weight = get_user_input<float>("Enter your Weight in Kilograms: ");
    phone_num = get_user_input<std::string>("Enter your Phone Number: ");
    e_mail = get_user_input<std::string>("Enter your Email: ");
    return true;
}

void bmiCalc()
{
    double bmi;
    bmi = weight / (height * height);
    std::cout << bmi << std::endl; 
}

void bmiCheck ()
{
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
}
