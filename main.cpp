#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random() 
{
    int start = 1, end = 36;
    std::srand(std::time(0));
    
    int num = std::rand() % (end - start + 1) + start;


    return num;
}


int main ()
{
    int n;
    string result;
    cout << "Выберите на что поставить 1-Зеленое, 2-Красное, 3-Черное: ";
    cin >> n;
    int roll = random();
    if (roll == 1) {
        result = "зеленое";
    } else if (roll % 2 == 0) {
        result = "черное";
    } else {
        result = "черное";
    }



    if (n == 1 && roll == 1) {
        cout << "Поздравляю! Зеленое";
    } else if (n == 2 && roll % 2 == 0) {
        cout << "Поздравляю! Красное";
    } else if (n == 3 && roll % 2 != 0) {
        cout << "Поздравляю! Черное";
    } else {
        cout << "Вы проиграли, выпало " << result;
    }
    return 0;
}   
