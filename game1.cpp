#include <iostream> //Для ввод вывод
#include <cstdlib> // Для функции rand() и srand()
#include <ctime>   // Для функции time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    int secretNumber = rand() % 100 + 1; // Генерация случайного числа от 1 до 100
    int guess = 0;     // Переменная игрока
    int attempts = 0;  // Переьенная попыток

    cout << " Guess the number from 1 to 100! " << endl;// Угадайте число от 1 до 100!


    // Основной цикл игры
    while (guess != secretNumber) {
        cout << "Enter your guess: ";
        //Введите ваше предположение:
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << " The number is too small! Try again. " << endl;
            //Слишком маленькое число! Попробуйте снова.
        } else if (guess > secretNumber) {
            cout << "The number is too high! Try again." << endl;
            //Слишком большое число! Попробуйте снова.
        } else {
            cout << " Congratulations! You guessed the number." << secretNumber 
            << " za " << attempts << " попыток!" << endl;
            // Поздравляем! Вы угадали  попыток!
        }
    }
    return 0;
}
