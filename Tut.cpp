#include <iostream>


using namespace std;

bool Result(int u_i, int c_i, int num) {
    bool res=0; 
    for (int i = 1; i <= num / 2; i++) {
        res = (((u_i + i) % num == c_i) || res);
    }
    return res;
}

void chooseEntitie(string *entites, int N) {
    setlocale(LC_ALL, "ru");
    cout << "Choose your entitie:" << endl; 
    for (int i = 0; i < N; i++)
    {
        cout << (i + 1) << " - " << entites[i] << "\t";
    }
    cout << endl;
}




int main() {
    setlocale(LC_ALL, "ru");

    int N;
    cout << "Input numbers of entities" << endl;
    cin >> N;

    string* entities = new string[N];
    cout << "Enter your characters in such an order that 1 beats 2, 2 beats 3, etc. (until the last one beats 1)" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> entities[i];
    }
    int user_entitie_index, comp_entitie_index, w = 0 , l = 0;

    string exit = " ";

    do {
        chooseEntitie(entities, N);
        cin >> user_entitie_index;
        user_entitie_index = user_entitie_index - 1;
        comp_entitie_index = (rand() % N);


        cout << "You choose - " << entities[user_entitie_index] << endl;
        cout << "Comp choose - " << entities[comp_entitie_index] << endl;

        if (user_entitie_index == comp_entitie_index) { cout << "Noone win!" << endl; }
        else if (Result(user_entitie_index, comp_entitie_index, N)){ cout << "You won!" << endl; w++; }
        else { cout << "Looser! You lose! >:)" << endl; l++;}


        cout << "Statistics: Wins: " << w << "; Loses: " << l << endl;
        cout << "Go again? Input y - yes or n - no." << endl;
        cin >> exit;

    } while (exit == "y");
 
    return 0;
}
