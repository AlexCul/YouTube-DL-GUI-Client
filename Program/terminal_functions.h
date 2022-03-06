#ifndef TERMINAL_FUNCTIONS_H
#define TERMINAL_FUNCTIONS_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;


void installing_function(string command) {
    cout << system(command.c_str());
}

string installing_command_creating(string link, string directory, vector<string> parameters) {
    string* command_without_parameters = new string("youtube-dl " + link + " -o " + directory + "/" + link);
    string* command_with_parameters = new string(*command_without_parameters);
    delete command_without_parameters;
    for (unsigned long i = 0; i < parameters.size(); ++i) {
        *command_with_parameters += parameters[i];
    }
    return *command_with_parameters;
    delete command_with_parameters;
}

#endif // TERMINAL_FUNCTIONS_H
