#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


vector<int> split(const string &s, char delim) {
    vector<int> elems;
    stringstream ss;
    string item;

    ss.str(s);
    while (getline(ss, item, delim)) {
        elems.push_back(stoi(item));
    }

    return elems;
}

void solution(string cadena, int inputs){
    int cost, after, index = 2, max = inputs - 1;
    vector<int> arr = split(cadena, ' ');

    cost = arr[0] + arr[1];
    after = cost;

    while (index < max){
        cost += arr[index];
        after += cost;
        index++;
    }

    cout << cost + arr[index] +  after << endl;
}

int main() {
    string cadena;
    int inputs;

    ifstream fe("data.in");
    while(!fe.eof()) {
        getline(fe, cadena);
        inputs = stoi(cadena);

        if (inputs == 0) break;

        getline(fe, cadena);

        solution(cadena, inputs);
    }
    fe.close();

    return 0;
}
