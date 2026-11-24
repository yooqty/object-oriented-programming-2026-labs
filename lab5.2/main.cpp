#include <iostream>
#include "dron_data_container.h"
#include "dron_data.h"
#include "time.h"

int main() {
    std::cout << "===== Scenario 1: temperature (int) =====" << std::endl;
    DronDataContainer<int> tempContainer;
    tempContainer.addData(18);
    tempContainer.addData(22);
    tempContainer.addData(15);
    tempContainer.addData(25);
    tempContainer.addData(19);
    tempContainer.info();
    tempContainer.sortData();
    std::cout << "After sorting:" << std::endl;
    tempContainer.info();
    std::cout << "Maximum: " << tempContainer.maxData() << std::endl;
    std::cout << "Minimum: " << tempContainer.minData() << std::endl;
    tempContainer.saveToFile("temperature.txt");

    std::cout << "\n===== Scenario 2: depth (double) =====" << std::endl;
    DronDataContainer<double> depthContainer;
    depthContainer.addData(12.5);
    depthContainer.addData(7.3);
    depthContainer.addData(25.8);
    depthContainer.addData(3.1);
    depthContainer.info();
    depthContainer.sortData();
    std::cout << "After sorting:" << std::endl;
    depthContainer.info();
    std::cout << "Maximum: " << depthContainer.maxData() << std::endl;
    std::cout << "Minimum: " << depthContainer.minData() << std::endl;
    depthContainer.saveToFile("depth.txt");

    std::cout << "\n===== Scenario 3: DronData (time, temperature, depth) =====" << std::endl;
    DronDataContainer<DronData> dronContainer;
    dronContainer.addData(DronData(Time(10, 0, 5),  18, 12.5));
    dronContainer.addData(DronData(Time(10, 0, 15), 22,  7.3));
    dronContainer.addData(DronData(Time(10, 0, 10), 15, 25.8));
    dronContainer.addData(DronData(Time(10, 0, 25), 25,  3.1));
    dronContainer.addData(DronData(Time(10, 0, 20), 19, 10.0));

    std::cout << "Initial data:" << std::endl;
    dronContainer.info();

    dronContainer.sortData();
    std::cout << "After sorting:" << std::endl;
    dronContainer.info();

    std::cout << "Maximum (by comparison criterion): " << dronContainer.maxData() << std::endl;
    std::cout << "Minimum (by comparison criterion): " << dronContainer.minData() << std::endl;

    dronContainer.saveToFile("dron_data.txt");

    // verify container cleaning
    dronContainer.cleanContainer();
    std::cout << "After cleaning:" << std::endl;
    dronContainer.info();

    return 0;
}