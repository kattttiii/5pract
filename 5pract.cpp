#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <locale>


void reverse_word(std::string word) {
    setlocale(LC_ALL, "Russian");
    std::reverse(word.begin(), word.end());
    std::cout << word << std::endl;
}

void removeVowels(std::string word) {
    setlocale(LC_ALL, "Russian");
    std::string result = "";
    const std::string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    for (char c : word) {
        if (vowels.find(c) == std::string::npos) {
            result += c;
        }
    }
    std::cout << result << std::endl;
}

void removeConsonants(std::string word) {
    setlocale(LC_ALL, "Russian");
    std::string result = "";
    for (char c : word) {
        setlocale(LC_ALL, "Russian");
        if (!isalpha(c) || strchr("ауёияюэоыеАУЁИЯЮЭО", c) == nullptr) {
            result += c;
        }
    }
    std::cout << result << std::endl;
}

void shuffleWord(std::string word) {
    setlocale(LC_ALL, "Russian");
    unsigned seed = time(0);
    std::string shuffled = word;
    std::shuffle(shuffled.begin(), shuffled.end(), std::default_random_engine(seed));
    std::cout << shuffled << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string word;
    std::cout << "Введите слово: ";
    std::cin >> word;

    int choice;
    do {
        std::cout << "\nМеню:\n1. Вывести слово задом наперед\n2. Вывести слово без гласных\n3. Вывести слово без согласных\n4. Рандомно раскидывать буквы заданного слова\nВыберите действие (1-4): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            reverse_word(word);
            break;
        case 2:
            removeVowels(word);
            break;
        case 3:
            removeConsonants(word);
            break;
        case 4:
            shuffleWord(word);
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

    return 0;
}