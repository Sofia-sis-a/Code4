#include "CallTracker.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        ImportantCallTracker VIPTracker("+7-999-111-22-33", "Главный Заказчик");
        
        VIPTracker.addCall(12.4, 5.0);
        VIPTracker.addCall(30.1, 4.5);
        VIPTracker.addCall(5.0, 3.0);

        VIPTracker.printInfo();

        std::cout << "Селектор текущего рейтинга: " << VIPTracker.getCurrentRating() << std::endl;
        std::cout << "Селектор среднего рейтинга: " << VIPTracker.getAverageRating() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
