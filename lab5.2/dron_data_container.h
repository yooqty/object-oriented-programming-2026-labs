#ifndef DRON_DATA_CONTAINER_H
#define DRON_DATA_CONTAINER_H

#include <iostream>
#include <fstream>
#include <string>

const int MAX_DATA = 100; // maximum possible amount of data

template <class T>
class DronDataContainer {
public:
    T data[MAX_DATA]; // array for storing data
    int dataCounter; // current number of data items in the container

    DronDataContainer(); // constructor
    void addData(T data); // add a data item to the container
    void cleanContainer(); // clear the container
    void sortData();
    T maxData(); // return the maximum element
    T minData(); // return the minimum element
    void info(); // print container contents to console
    void saveToFile(std::string filename); // write to file
};

template <class T>
DronDataContainer<T>::DronDataContainer() : dataCounter(0) {}

template <class T>
void DronDataContainer<T>::addData(T newData) {
    if (dataCounter >= MAX_DATA) {
        std::cerr << "Container is full! Data not added." << std::endl;
        return;
    }
    data[dataCounter++] = newData;
}

template <class T>
void DronDataContainer<T>::cleanContainer() {
    dataCounter = 0;
}

template <class T>
void DronDataContainer<T>::sortData() {
    // insertion sort
    for (int i = 1; i < dataCounter; ++i) {
        T key = data[i];
        int j = i - 1;
        while (j >= 0 && key < data[j]) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }
}

template <class T>
T DronDataContainer<T>::maxData() {
    if (dataCounter == 0) {
        std::cerr << "Container is empty! Returning default value." << std::endl;
        return T();
    }
    T maxVal = data[0];
    for (int i = 1; i < dataCounter; ++i) {
        if (maxVal < data[i]) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

template <class T>
T DronDataContainer<T>::minData() {
    if (dataCounter == 0) {
        std::cerr << "Container is empty! Returning default value." << std::endl;
        return T();
    }
    T minVal = data[0];
    for (int i = 1; i < dataCounter; ++i) {
        if (data[i] < minVal) {
            minVal = data[i];
        }
    }
    return minVal;
}

template <class T>
void DronDataContainer<T>::info() {
    if (dataCounter == 0) {
        std::cout << "Container is empty." << std::endl;
        return;
    }
    std::cout << "Container contents (" << dataCounter << " items):" << std::endl;
    for (int i = 0; i < dataCounter; ++i) {
        std::cout << "  " << (i + 1) << ") " << data[i] << std::endl;
    }
}

template <class T>
void DronDataContainer<T>::saveToFile(std::string filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }
    out << "Data count: " << dataCounter << std::endl;
    for (int i = 0; i < dataCounter; ++i) {
        out << data[i] << std::endl;
    }
    out.close();
    std::cout << "Data saved to file: " << filename << std::endl;
}

#endif // DRON_DATA_CONTAINER_H
