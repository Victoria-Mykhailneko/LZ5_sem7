#include <iostream>
#include <string>

using namespace std;

struct Train {
    string destination;
    int trainNumber;
    string departureTime;
};

int main() {
    const int numTrains = 8;
    Train trains[numTrains];

    for (int i = 0; i < numTrains; ++i) {
        Train* trainPtr = &trains[i]; // Вказівник на структуру Train

        cout << "Введіть дані для потягу " << i + 1 << ":" << endl;
        cout << "Пункт призначення: ";
        cin >> trainPtr->destination;
        cout << "Номер потягу: ";
        cin >> trainPtr->trainNumber;
        cout << "Час відправлення (наприклад, 14:30): ";
        cin >> trainPtr->departureTime;
        cout << endl;
    }

    for (int i = 0; i < numTrains - 1; ++i) {
        for (int j = i + 1; j < numTrains; ++j) {
            if (trains[i].trainNumber > trains[j].trainNumber) {
                // Обмін елементів місцями
                Train temp = trains[i];
                trains[i] = trains[j];
                trains[j] = temp;
            }
        }
    }

    cout << "--- Список потягів після сортування за номером ---" << endl;
    for (int i = 0; i < numTrains; ++i) {
        cout << "Номер: " << trains[i].trainNumber 
             << ", Пункт призначення: " << trains[i].destination 
             << ", Час відправлення: " << trains[i].departureTime << endl;
    }
    cout << endl;

    string targetTime;
    cout << "Введіть час для пошуку (у форматі ЧХ:ХХ, наприклад, 15:00): ";
    cin >> targetTime;

    cout << "\nПотяги, які відбувають до " << targetTime << ":" << endl;
    bool found = false;
    
    for (int i = 0; i < numTrains; ++i) {

        if (trains[i].departureTime <= targetTime) {
            cout << "Номер: " << trains[i].trainNumber 
                 << ", Пункт призначення: " << trains[i].destination 
                 << ", Час відправлення: " << trains[i].departureTime << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає потягів, які відбувають до цього часу." << endl;
    }

    return 0;
}