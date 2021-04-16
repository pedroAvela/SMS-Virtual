#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector < vector<char> > texto{ {'a', 'b', 'c'}, //Letras do numero 2 - item 0 no vector
                            {'d', 'e', 'f'}, //Letras do numero 3 - item 1 no vector
                            {'g', 'h', 'i'}, //Letras do numero 4 - item 2 no vector
                            {'j', 'k', 'l'}, //Letras do numero 5 - item 3 no vector
                            {'m', 'n', 'o'}, //Letras do numero 6 - item 4 no vector
                            {'p', 'q', 'r', 's'}, //Letras do numero 7 - item 5 no vector
                            {'t', 'u', 'v'}, //Letras do numero 8 - item 6 no vector
                            {'w', 'x', 'y', 'z'} //Letras do numero 9 - item 7 no vector
                        }; 

int main() {
    int mestre, n1, n2;
    string aux;
    string codigo = "";
    string palavra = "";
    cin >> mestre;
    for(int i = 0; i < mestre; i++){
        cin >> codigo;
        aux = codigo[1];
        n1 = stoi(aux) - 2;
        aux = codigo[3];
        n2 = stoi(aux) - 1;
        palavra += texto[n1][n2];
    }
    
    cout << palavra;

    }