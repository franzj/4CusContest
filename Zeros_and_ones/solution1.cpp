#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


void setMinAndMax(const string &s, int &min, int &max) {
    stringstream ss;
    string item;

    ss.str(s);
    getline(ss, item, ' ');
    min = stoi(item);

    getline(ss, item, ' ');
    max = stoi(item);

    if (min > max){
        int tmp = min;
        min = max;
        max = tmp;
    }
}

void solution(string cadena, int queries, ifstream &fe){
    int index = 0, min, max;
    string query;
    vector<int> elemt;

    while(index < queries){
        getline(fe, query);
        setMinAndMax(query, min, max);

        if(cadena[min] == cadena[max]){
            char tmp = cadena[min];
            bool yes = true;

            for(int i=min+1; i<=max-1; i++) {
                if(cadena[i] != tmp) {
                    cout << "No" << endl;
                    yes = false;
                    break;
                }
            }

            if(yes) cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        index++;
    }

}

int main() {
    string line, cadena;
    int cont = 1;

    ifstream fe("data.in");
    while(true) {
        getline(fe, line);
        cadena = line;

        if(fe.eof()) break;

        getline(fe, line);
        cout << "Case " << cont << endl;
        solution(cadena, stoi(line), fe);
        cont++;
    }
    fe.close();

    return 0;
}
