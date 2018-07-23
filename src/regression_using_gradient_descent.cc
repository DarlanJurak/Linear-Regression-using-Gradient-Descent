/*

@file           regression_using_gradient_descent.cc
@author         Darlan Alves Jurak 
@date           13/04/2018.
@brief          Implementation of the gradient descent algorithm for regression problems
@version        v1.0_Univariated_Linear_Regression
@improvement    
1 -             Multi-variated Linear Regression
2 -             Multi-variated Linear and Non-Linear Regression

*/

#include <iostream>                     // cout and cin.
#include <vector>
#include <string>                       // String.
#include <boost/algorithm/string.hpp>   // String split.

using namespace std;

struct Sample{

    int x   = 0;
    int f_x = 0;

};

int main () {

    vector<double> thetas;              // Data structure to store regression's coeficients.
    string user_input;                  // Variable to interact with user.
    double learning_rate;

    vector<double>       instance_input_double;  // Intermediary attributes vector.
    vector<std::string> instance_input_string; // Used in the get line split.
    vector<Sample *>      samples;

    int interations;

    // Receive arguments (initial thetas, learning rate, training set and #iterations)
    cout << "\n=================== Initial Thetas Insertion ===================" << endl;

    // Theta 0
    cout << "Please, insert first theta value: " << endl;
    getline(cin, user_input);
    thetas.push_back(stod(user_input));

    // Theta 1
    cout << "Please, insert second theta value: " << endl;
    getline(cin, user_input);
    thetas.push_back(stod(user_input));

    cout << "\n=================== Learning Rate Insertion ===================" << endl;

    // Learning Rate
    cout << "Please, insert the learning rate value: " << endl;
    getline(cin, user_input);
    learning_rate = stod(user_input);

    cout << "\n=================== Showing Inserted Values ===================" << endl;

    // Shows inserted values
    cout    << "\nInserted values:\n"
            << "Theta 0: "          << thetas.at(0) << "\n"
            << "Theta 1: "          << thetas.at(1) << "\n"
            << "Learning rate: "    << learning_rate << "\n"
            << endl;

    cout << "\n=================== Traning Set Insertation ===================" << endl;

    // User interaction. Asks for Instances attributes.
    cout << "\n================ Samples Insertion ================" << endl;
    cout << "Please, insert the training base respecting the following rules: \n"
        << "* Insert numbers only (they CAN be float). \n"
        << "* The FIRST number in a line represents a attribute. \n"
        << "* The SECOND number in a line represents the \"classification\" of the sample. \n"
        << "* Insert all attributes values related to the same instance in one line (ordered and separated by <space>). \n"
        << "* Finish insertion by entering <enter> \n"
        << "Example:    \n"
        << "2 3.6     \n"
        << "17 5      \n"
        << "2.2 15.8  \n" << endl;

    getline(cin, user_input);   // Get first user input related to samples.

    // While receives input, set them as Instances's attributes.
    while(user_input.size() > 0){

        // Splits input string by <space>.
        boost::split(instance_input_string, user_input, [](char c){return c == ' ';});

        // Transforms from string vector to float vector.
        vector<double> instance_input_double(instance_input_string.size());
        transform(instance_input_string.begin(), instance_input_string.end(), instance_input_double.begin(), [](const std::string& val)
        {
            return std::stod(val);
        });

        // Creates new Sample with attributes.
        Sample *sample = new Sample;                                // Creates pointer to the new sample.
        sample->x = (double)*(instance_input_double.begin());       // Gets user info about samples.
        instance_input_double.erase(instance_input_double.begin()); // Removes first value.
        sample->f_x = (double)*(instance_input_double.begin());     // Gets user info about samples.
        samples.push_back(sample);                                  // Add new sample to the data structure.

        getline(cin, user_input);   // Get user input (new attributes set).
    }

    cout << "\n================== Show Samples ==================" << endl;
    // Shows samples and their attributes.
    int count = 0;  // Counter to help user. (Helps to see the ordered list of samples).
    for (std::vector<Sample *>::iterator it = samples.begin(); it != samples.end(); ++it){

        std::cout << "Sample "  <<  count++     << ": "
                    << "x: "    << (*it)->x     << " "
                    << "f(x): " << (*it)->f_x   << " "
                    << endl;

    }

    cout << "\n=================== #Interactions Insertion ===================" << endl;

    // Learning Rate
    cout << "How many interaction of the gradient descent do you want to run? " << endl;
    getline(cin, user_input);
    interations = stoi(user_input);

    // Execute Gradient Descent
    // Output generated thetas
    // Predict new received values
    return 0;
}
