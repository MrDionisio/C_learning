#include <iostream>


using namespace std;

bool Result(string *entities, int a, int b, int N) {
    bool res=0; 
    for (int i = 1; i <= N / 2; i++) {
        res = (((entities[(a + i) % N]) == entities[b]) || res);
    }
    return res;
}

void chooseEntitie(string *entites, int N) {
    setlocale(LC_ALL, "ru");
    cout << "Выберите то, что хотите поставить:" << endl; 
    for (int i = 0; i < N; i++)
    {
        cout << (i + 1) << " - " << entites[i] << "\t";
    }
    cout << endl;
}




int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "Введите количество ваших персонажей" << endl;
    cin >> N;

    string* entities = new string[N];
    cout << "Введите ваших персонажей в таком порядке, что 1 бьет 2, 2 бьет 3 и т.д. (до последний бьет 1)" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> entities[i];
    }
    int a, b, w = 0 , l = 0;

    string exit = " ";

    do {
        chooseEntitie(entities, N);
        cin >> a;
        a = a - 1;
        b = (rand() % N);


        cout << "Ты выбрал - " << entities[a] << endl;
        cout << "Компьюетр выбрал - " << entities[b] << endl;

        if (a == b) { cout << "Ничья!" << endl; }
        else if (Result(entities, a, b, N)){ cout << "Ты выиграл, тип!" << endl; w++; }
        else { cout << "Лузер, продул! Ха-ха-ха! >:)" << endl; l++;}


        cout << "Статистика: Wins: " << w << "; Loses: " << l << endl;
        cout << "Хош ещё? Нажми y (игрик) - типо да или n (эн) - типо нет." << endl;
        cin >> exit;

    } while (exit == "y");
 
    return 0;
}