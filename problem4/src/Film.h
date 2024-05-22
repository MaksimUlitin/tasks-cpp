#ifndef FILM_H
#define FILM_H

#include <string>

enum AnimationType { Drawn, Puppet, Other };

class Film {
protected:
    std::string name;
    int yearOfRelease;
    std::string country;
    int vowelCount;

public:
    Film(const std::string& name, int yearOfRelease, const std::string& country);
    virtual void printInfo() = 0;
    int getVowelCount() const;

private:
    int countVowels(const std::string& str);
};

class DocumentaryFilm : public Film {
public:
    DocumentaryFilm(const std::string& name, int yearOfRelease, const std::string& country);
    void printInfo() override;
};

class AnimatedFilm : public Film {
private:
    AnimationType animationType;

public:
    AnimatedFilm(const std::string& name, int yearOfRelease, const std::string& country, AnimationType animationType);
    void printInfo() override;
};

class FeatureFilm : public Film {
private:
    std::string director;

public:
    FeatureFilm(const std::string& name, int yearOfRelease, const std::string& country, const std::string& director);
    void printInfo() override;
};

#endif 
