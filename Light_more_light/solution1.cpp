#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void primo(unsigned long int number){
    for (unsigned long int i=2; i < number - 1; i++){
        if(number % i == 0){
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
}

int main() {
    string cadena;
    unsigned long int number;

    ifstream fe("data.in");
    while(!fe.eof()) {
        getline(fe, cadena);
        number = (unsigned long int) stol(cadena);

        if (number == 0) break;

        primo(number);
    }
    fe.close();

    return 0;
}
