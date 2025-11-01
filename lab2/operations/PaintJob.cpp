#include "PaintJob.h"
#include <iostream>

PaintJob::PaintJob(std::string desc, Car* c, std::string col, double area)
        : Service(desc), car(c), color(col), paintAreaSqM(area), isComplete(false) {}

void PaintJob::perform() {
    std::cout << "Painting car " << car->getVin() << " with color " << color << std::endl;
    isComplete = true;
}

void PaintJob::schedule() {
    std::cout << "Paint job scheduled for car " << car->getVin() << std::endl;
}

std::string PaintJob::getColor() const {
    return color;
}

bool PaintJob::getIsComplete() const {
    return isComplete;
}