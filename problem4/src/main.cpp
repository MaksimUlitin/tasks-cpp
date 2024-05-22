#include "Film.h"

int main() {
    DocumentaryFilm doc("Бухта", 2009, "США");
    AnimatedFilm anim("Игрушечная история", 1995, "США", Drawn);
    FeatureFilm feature("Побег из Шоушенка", 1994, "США", "Фрэнк Дарабонт");

    doc.printInfo();
    anim.printInfo();
    feature.printInfo();

    return 0;
}