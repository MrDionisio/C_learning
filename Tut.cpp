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
    cout << "�������� ��, ��� ������ ���������:" << endl; 
    for (int i = 0; i < N; i++)
    {
        cout << (i + 1) << " - " << entites[i] << "\t";
    }
    cout << endl;
}




int main() {
    setlocale(LC_ALL, "ru");
    int N;
    cout << "������� ���������� ����� ����������" << endl;
    cin >> N;

    string* entities = new string[N];
    cout << "������� ����� ���������� � ����� �������, ��� 1 ���� 2, 2 ���� 3 � �.�. (�� ��������� ���� 1)" << endl;
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


        cout << "�� ������ - " << entities[a] << endl;
        cout << "��������� ������ - " << entities[b] << endl;

        if (a == b) { cout << "�����!" << endl; }
        else if (Result(entities, a, b, N)){ cout << "�� �������, ���!" << endl; w++; }
        else { cout << "�����, ������! ��-��-��! >:)" << endl; l++;}


        cout << "����������: Wins: " << w << "; Loses: " << l << endl;
        cout << "��� ���? ����� y (�����) - ���� �� ��� n (��) - ���� ���." << endl;
        cin >> exit;

    } while (exit == "y");
 
    return 0;
}