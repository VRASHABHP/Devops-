#include <iostream>
#include <string>

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

// Class representing an EnvironmentSensor
class EnvironmentSensor {
private:
    std::string season;
    int temperature;

public:
    EnvironmentSensor(const std::string& s, int temp) : season(s), temperature(temp) {}

    std::string getSeason() const {
        return season;
    }

    int getTemperature() const {
        return temperature;
    }
};

// Class representing a WaterHeater
class WaterHeater {
private:
    bool isOn;

public:
    WaterHeater() : isOn(false) {}

    void turnOn() {
        isOn = true;
    }

    void turnOff() {
        isOn = false;
    }

    bool isHeaterOn() const {
        return isOn;
    }
};

// Class representing a SmartGeyser
class SmartGeyser {
private:
    HomeOwner* owner;
    EnvironmentSensor* sensor;
    WaterHeater* heater;

public:
    SmartGeyser(HomeOwner* own, EnvironmentSensor* sens, WaterHeater* heat) : owner(own), sensor(sens), heater(heat) {}

    void activateGeyser() {
        if (sensor->getTemperature() < 20 && sensor->getSeason() == "Winter") {
            heater->turnOn();
            std::cout << owner->getName() << "'s geyser activated for a warm shower.\n";
        } else {
            std::cout << "Geyser not activated.\n";
        }
    }
};

int main() {
    // Creating objects
    HomeOwner john("John");
    EnvironmentSensor winterSensor("Winter", 15);
    WaterHeater johnsHeater;

    // Creating SmartGeyser object and activating it
    SmartGeyser johnsGeyser(&john, &winterSensor, &johnsHeater);
    johnsGeyser.activateGeyser();

    return 0;
}
