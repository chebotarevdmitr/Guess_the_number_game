#include <iostream> // для ввода и вывода данныых
#include <string>   // для работы со строками
#include <fstream>  // для работы с файлами (чтение изапись)
#include <cstdlib>  // для использования функций сттандартной библиотеки как rand() и srand()
#include <ctime>    // для получения текущего времени 
                    //(для инициализации генератора случайных чисел).

void saveRecord(const std::string& name, int attempts) {
    std::ofstream file("records.txt", std::ios::app);
    if (file.is_open()) {
        file << name << " " << attempts << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

void displayRecords() {
    std::ifstream file("records.txt");
    std::string line;

    std::cout << "Table of records:\n";  //Таблица рекордов
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}
int main() {
    std::srand(std::time(nullptr)); // Инициализация генератора случайных чисел
    const int max_value = 100;
    int random_value = std::rand() % max_value; // Загаданное число
    int user_guess = -1; // Предположение пользователя
    int attempts = 0; // Количество попыток

    std::string player_name;

    // Запрос имени игрока
    std::cout << "Enter your name";
    std::getline(std::cin, player_name);

    std::cout << "I guessed a number from 0 to" << max_value - 1 << ". Try to guess it!" << std::endl;
     //Я загадал число от 0 до  100   Попробуйте угадать его!
    while (user_guess != random_value) {
        std::cout << "Enter your guess: ";  // Введите ваше предположение:
        std::cin >> user_guess;
        attempts++;

        if (user_guess < random_value) {
            std::cout << "less than" << std::endl;
        } else if (user_guess > random_value) {
            std::cout << "greater than" << std::endl;
        } else {
            std::cout << "you win!" << std::endl;
        }
    }

    // Сохранение рекорда
    saveRecord(player_name, attempts);
    
    // Отображение таблицы рекордов
    displayRecords();

    return 0;
}