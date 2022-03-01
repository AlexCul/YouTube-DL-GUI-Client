#ifndef TERMINAL_FUNCTIONS_H
#define TERMINAL_FUNCTIONS_H

#include <string>
#include <iostream>
using namespace std;


void installing_function(string link, string directory) {
    string* command = new string("youtube-dl " + link + " -o " + directory + "/" + link);
    cout << system(command->c_str());
    delete command;
}

#endif // TERMINAL_FUNCTIONS_H
