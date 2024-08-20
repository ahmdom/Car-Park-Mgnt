#include <iostream>
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}
void addCar(const std::string& brand, const std::string& model, const std::string& licensePlate) ;


    // Define a structure to represent a car
    struct Car {
        std::string brand;
        std::string model;
        std::string licensePlate;
    };

    // Define an array to store the cars in the park
    const int MAX_CARS = 100;
    Car carPark[MAX_CARS];
    int numCars = 0;

    // Function to add a car to the park
    void addCar(const std::string& brand, const std::string& model, const std::string& licensePlate) 
    {
        if (numCars < MAX_CARS) {
            Car newCar;
            newCar.brand = brand;
            newCar.model = model;
            newCar.licensePlate = licensePlate;

            carPark[numCars] = newCar;
            numCars++;

            std::cout << "Car added successfully!" << std::endl;
        } else {
            std::cout << "Car park is full!" << std::endl;
        }
    }

    // Function to display all cars in the park
    void displayCars() {
        if (numCars > 0) {
            std::cout << "Cars in the park:" << std::endl;
            for (int i = 0; i < numCars; i++) {
                std::cout << "Car " << i+1 << ":" << std::endl;
                std::cout << "Brand: " << carPark[i].brand << std::endl;
                std::cout << "Model: " << carPark[i].model << std::endl;
                std::cout << "License Plate: " << carPark[i].licensePlate << std::endl;
                std::cout << std::endl;
            }
        } else {
            std::cout << "No cars in the park!" << std::endl;
        }
    }

    // Function to remove a car from the park
    void removeCar(int index) {
        if (index >= 0 && index < numCars) {
            for (int i = index; i < numCars - 1; i++) {
                carPark[i] = carPark[i+1];
            }
            numCars--;

            std::cout << "Car removed successfully!" << std::endl;
        } else {
            std::cout << "Invalid car index!" << std::endl;
        }
    }

    // Function to find a car by license plate
    int findCar(const std::string& searchValue) {
        for (int i = 0; i < numCars; i++) {
            if (carPark[i].licensePlate == searchValue || carPark[i].brand == searchValue || carPark[i].model == searchValue) {
                return i;
            }
        }
        return -1; // Car not found
    }

    // Function to modify a car in the park
    void modifyCar(int index, const std::string& brand, const std::string& model, const std::string& licensePlate) {
        if (index >= 0 && index < numCars) {
            carPark[index].brand = brand;
            carPark[index].model = model;
            carPark[index].licensePlate = licensePlate;

            std::cout << "Car modified successfully!" << std::endl;
        } else {
            std::cout << "Invalid car index!" << std::endl;
        }
    }

    // Usage example
    int main() {
        
        addCar("Toyota", "Camry", "ABC123");
        addCar("Honda", "Civic", "XYZ789");
        displayCars();

        while (true) {
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Add a car" << std::endl;
            std::cout << "2. Remove a car" << std::endl;
            std::cout << "3. Display all cars" << std::endl;
            std::cout << "4. Find a car" << std::endl;
            std::cout << "5. Modify a car" << std::endl;
            std::cout << "6. Exit" << std::endl;

            int choice;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    std::string brand, model, licensePlate;
                    std::cout << "Enter the brand: ";
                    std::cin >> brand;
                    std::cout << "Enter the model: ";
                    std::cin >> model;
                    std::cout << "Enter the license plate: ";
                    std::cin >> licensePlate;
                    addCar(brand, model, licensePlate);
                    break;
                }
                case 2: {
                    int index;
                    std::cout << "Enter the index of the car to remove: ";
                    std::cin >> index;
                    removeCar(index);
                    break;
                }
                case 3:
                    displayCars();
                    break;

                case 4: {
                        std::string searchValue;
                        std::cout << "Enter the license plate, brand, or model of the car to find: ";
                        std::cin.ignore(); // Ignore any remaining characters in the input buffer
                        std::getline(std::cin, searchValue); // Read the entire line of input
                        std::cin >> searchValue;
                        int index = findCar(searchValue);
                        if (index != -1) {
                            std::cout << "Car found at index " << index << std::endl;
                        } else {
                            std::cout << "Car not found!" << std::endl;
                        }
                        break;
                    }
                case 5: {
                    int index;
                    std::cout << "Enter the index of the car to modify: ";
                    std::cin >> index;
                    std::string brand, model, licensePlate;
                    std::cout << "Enter the new brand: ";
                    std::cin >> brand;
                    std::cout << "Enter the new model: ";
                    std::cin >> model;
                    std::cout << "Enter the new license plate: ";
                    std::cin >> licensePlate;
                    modifyCar(index, brand, model, licensePlate);
                    break;
                }
                case 6:
                    return 0;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
            }
        }
        return 0;
    }