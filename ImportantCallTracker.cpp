#include "ImportantCallTracker.h"
#include <iostream>
#include <stdexcept>

ImportantCallTracker::ImportantCallTracker(const char* phone, const char* name) 
    : CallTracker(phone, name), totalRating(0.0), currentRating(0.0) {}

double ImportantCallTracker::getTotalRating() const { return totalRating; }
double ImportantCallTracker::getCurrentRating() const { return currentRating; }

double ImportantCallTracker::getAverageRating() const {
    if (totalCalls == 0) {
        return 0.0;
    }
    return totalRating / totalCalls;
}

void ImportantCallTracker::addCall(double duration, double rating) {
    if (rating < 0 || rating > 5) {
        throw std::out_of_range("Error: Rating must be between 0 and 5!");
    }
    CallTracker::addCall(duration);
    currentRating = rating;
    totalRating += rating;
}

void ImportantCallTracker::printInfo() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Абонент (ВАЖНЫЙ): " << subscriberName << std::endl;
    std::cout << "Телефон: " << phoneNumber << std::endl;
    std::cout << "Всего звонков: " << totalCalls << std::endl;
    std::cout << "Общая длительность: " << totalDuration << " мин." << std::endl;
    std::cout << "Макс. звонок: " << maxCallDuration << " мин." << std::endl;
    std::cout << "Мин. звонок: " << minCallDuration << " мин." << std::endl;
    std::cout << "Последний рейтинг звонка: " << currentRating << std::endl;
    std::cout << "Средний рейтинг абонента: " << getAverageRating() << std::endl;
    std::cout << "========================================" << std::endl;
}
