#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

//Vector que armazena as letras, cada item do vector grande "texto"
//representa o número do botão do celular, ou seja, são vetores que possuem as letras.
vector < vector<char> > texto{ {'a', 'b', 'c'}, //Letras do numero 2 - item 0 no vector
                            {'d', 'e', 'f'}, //Letras do numero 3 - item 1 no vector
                            {'g', 'h', 'i'}, //Letras do numero 4 - item 2 no vector
                            {'j', 'k', 'l'}, //Letras do numero 5 - item 3 no vector
                            {'m', 'n', 'o'}, //Letras do numero 6 - item 4 no vector
                            {'p', 'q', 'r', 's'}, //Letras do numero 7 - item 5 no vector
                            {'t', 'u', 'v'}, //Letras do numero 8 - item 6 no vector
                            {'w', 'x', 'y', 'z'} //Letras do numero 9 - item 7 no vector
                        }; 




bool verificador(string code){
    if (code[0] == '#' and code[2] == '='){
        if ((code[1] >= 50) and (code[1] <= 57)){
            for (int i = 3; i < code.length(); i++){
                if ((code[i] < 48) or (code[i] > 57)){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        } 
    }else{
        return false;
    }
}

string formadorDepalavra(int tamanho){
    int n1, n2;
    string aux, codigo = "", palavra = "";
    cout << "Digite o(s) código(s)(Um por vez): " << endl; 
    for(int i = 0; i < tamanho; i++){     
        cin >> codigo;
        if(verificador(codigo) == true){
            aux = codigo[1];
            n1 = stoi(aux) - 2;

            //Essa parte permite que o usuário aperte o "botão" mais vezes
            //Como exemplo caso o usuário escolha o numero 2 e no código peça para apertar 4
            //Vezes, ao invés de ocasionar um bug por ser um numero maior que o tamanho do vector,
            //Irá simplesmente fazer que ele volte para o inicio, ou seja, se ele colocar 4 irá para
            //letra "a" de novo, 5 ira para a "b" e assim por diante, deixando a experiência mais
            //parecida com um celular da época.
            //Inicio
            aux = "";
            for (int n = 3; n < codigo.length(); n++){
                aux += codigo[n];
            }
            n2 = stoi(aux) - 1;
            if (n1 != 5 and n1 != 7){
                n2 %= 3;
            }else{
                n2 %= 4;
            }
            //Fim

            palavra += texto[n1][n2];    
        }else{
            cout << "código invalido, tente de novo\n";
            i--;
        }
    }
    return palavra;
}

void inicio(){
    int tamanhoPalavra, n;
    bool start = true;
    cout << "\033[2J\033[1;1H";
    cout << "Para utilizar o SMS virtual, primeiro você deve escrever o tamanho da palavra que quer, depois " << endl;
    cout << "digite o número onde sua letra se encontra ";
    cout << "antecendido por um '#', depois coloque um '='\ne o numero de vezes que";
    cout << "você deseja apertar aquela tecla. Ex: para a letra 'a' #2=1 sendo:\n2: O numero onde a letra";
    cout << " se encontra\n1: O numero de vezes que a tecla é apertada." << endl;
    cout << "\nTeclas: " << endl;
    cout << "\t2.(a, b, c)\n\t3.(d, e, f)\n\t4.(g, h, i)\n\t5.(j, k, l)\n\t6.(m, n, o)\n\t7.(p, q, r, s)\n\t8.(t, u, v)" << endl;
    cout << "\t9.(w, x, y, z)";

    cout << "\nDigite o tamanho da palavra para começar:" << endl;
    cin >> tamanhoPalavra;
    while (start == true){
        if (tamanhoPalavra == 0){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Tente de novo";
            cin >> tamanhoPalavra;
        }else{
            start = false;
        }
    }
    cout << formadorDepalavra(tamanhoPalavra) << endl;
    cout << "Digite 1 para voltar ao menu ou qualquer coisa para sair do programa" << endl;
    cin >> n;
    if (n == 1){
        return;
    }else{
        exit(1);
    }
}

int main() {
    bool start = true;
    int comandoMenu = 0;
    while (start == true){
        cout << "digite 1 para iniciar ou 0 para sair:\n";
        cin >> comandoMenu;
        switch(comandoMenu){
            case 1: inicio();
            break;
            case 0: start = false;
            break;
        }
        cout << "\033[2J\033[1;1H";
    }
    return 0;
}