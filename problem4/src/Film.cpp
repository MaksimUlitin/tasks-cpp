#include "Film.h"
#include <iostream>

Film::Film(const std::string& name, int yearOfRelease, const std::string& country)
    : name(name), yearOfRelease(yearOfRelease), country(country), vowelCount(countVowels(name)) {}

int Film::getVowelCount() const {
    return vowelCount;
}

int Film::countVowels(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

DocumentaryFilm::DocumentaryFilm(const std::string& name, int yearOfRelease, const std::string& country)
    : Film(name, yearOfRelease, country) {}

void DocumentaryFilm::printInfo() {
    std::cout << "Документальный фильм: " << name << " (" << yearOfRelease << "), " << country << std::endl;
}

AnimatedFilm::AnimatedFilm(const std::string& name, int yearOfRelease, const std::string& country, AnimationType animationType)
    : Film(name, yearOfRelease, country), animationType(animationType) {}

void AnimatedFilm::printInfo() {
    std::cout << "Анимационный фильм: " << name << " (" << yearOfRelease << "), " << country << ", ";
    switch (animationType) {
        case Drawn:
            std::cout << "Нарисовано";
            break;
        case Puppet:
            std::cout << "Кукольный";
            break;
        default:
            std::cout << "Другое";
            break;
    }
    std::cout << std::endl;
}

FeatureFilm::FeatureFilm(const std::string& name, int yearOfRelease, const std::string& country, const std::string& director)
    : Film(name, yearOfRelease, country), director(director) {}

void FeatureFilm::printInfo() {
    std::cout << "Художественный фильм: " << name << " (" << yearOfRelease << "), " << country << ", режиссер " << director << std::endl;
}