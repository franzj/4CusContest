#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct Tree{
	char *name;
	Tree *lefth;
	Tree *right;
}*tree;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss;
    string item;

    ss.str(s);
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }

    return elems;
}

int main() {
    string cadena;
    vector<string> beverages;

    ifstream fe("data.in");
    while(!fe.eof()) {
        getline(fe, cadena);
        beverages = split(cadena, ' ');
    }
    fe.close();

    return 0;
}
