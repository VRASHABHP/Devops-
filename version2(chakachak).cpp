#include <iostream>
#include <string>

// Forward declaration of classes
class SmartHomeSystem;
class TemperatureSensor;
class BathroomGeyser;
class HeatingSystem;

// Class representing a HomeOwner
class HomeOwner {
private:
    std::string name;

public:
    HomeOwner(const std::string& n) : name(n) {}

    std::string getName() const {
        return name;
    }
};

// Class representing a Smart Home System
class SmartHomeSystem {
public:
    void activateGeyser(BathroomGeyser& geyser, HeatingSystem& heatingSystem);
    void receiveTemperature(BathroomGeyser& geyser, int temperature, HeatingSystem& heatingSystem);
};

// Class representing a Temperature Sensor
class TemperatureSensor {
public:
    int getCurrentTemperature() const {
        // Dummy implementation to return current temperature
        return 20; // Assuming a constant temperature for demonstration
    }
};

// Class representing a Bathroom Geyser
class BathroomGeyser {
public:
    void requestTemperature(SmartHomeSystem& smartHomeSystem, TemperatureSensor& sensor, HeatingSystem& heatingSystem);
    void calculateHeatingTemperature(HeatingSystem& heatingSystem, int currentTemperature);
    void receiveHeatingTemperature(int heatingTemperature);
};

// Class representing a Heating System
class HeatingSystem {
public:
    int calculateRequiredTemperature(int currentTemperature) const {
        // Dummy calculation for demonstration
        return currentTemperature + 10; // Adding 10 degrees for heating
    }
};

// Implementation of SmartHomeSystem::activateGeyser
void SmartHomeSystem::activateGeyser(BathroomGeyser& geyser, HeatingSystem& heatingSystem) {
    geyser.calculateHeatingTemperature(heatingSystem, 20);
}

// Implementation of SmartHomeSystem::receiveTemperature
void SmartHomeSystem::receiveTemperature(BathroomGeyser& geyser, int temperature, HeatingSystem& heatingSystem) {
    geyser.calculateHeatingTemperature(heatingSystem, temperature);
}

// Implementation of BathroomGeyser::requestTemperature
void BathroomGeyser::requestTemperature(SmartHomeSystem& smartHomeSystem, TemperatureSensor& sensor, HeatingSystem& heatingSystem) {
    smartHomeSystem.receiveTemperature(*this, sensor.getCurrentTemperature(), heatingSystem);
}

// Implementation of BathroomGeyser::calculateHeatingTemperature
void BathroomGeyser::calculateHeatingTemperature(HeatingSystem& heatingSystem, int currentTemperature) {
    int requiredTemperature = heatingSystem.calculateRequiredTemperature(currentTemperature);
    receiveHeatingTemperature(requiredTemperature);
}

// Implementation of BathroomGeyser::receiveHeatingTemperature
void BathroomGeyser::receiveHeatingTemperature(int heatingTemperature) {
    std::cout << "Heating temperature calculated: " << heatingTemperature << " degrees.\n";
    // Simulate geyser activation here
    std::cout << "Geyser activated.\n";
}

int main() {
    // Create objects
    HomeOwner john("John");
    SmartHomeSystem smartHomeSystem;
    TemperatureSensor sensor;
    BathroomGeyser geyser;
    HeatingSystem heatingSystem;

    // Perform actions
    smartHomeSystem.activateGeyser(geyser, heatingSystem);

    return 0;
}
