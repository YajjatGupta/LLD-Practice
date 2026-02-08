#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ================= Observer Interface =================
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() = default;
};

// ================= Subject Interface =================
class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

// ================= Display Interface =================
class DisplayElement {
public:
    virtual void display() = 0;
    virtual ~DisplayElement() = default;
};

// ================= WeatherData (Concrete Subject) =================
class WeatherData : public Subject {

private:
    vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void measurementsChanged() {
        notifyObservers();
    }

    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        measurementsChanged();
    }
};

// ================= Concrete Observers =================
class CurrentConditionsDisplay : public Observer, public DisplayElement {

private:
    float temperature;
    float humidity;
    Subject* weatherData;

public:
    CurrentConditionsDisplay(Subject* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }

    void update(float temp, float hum, float pres) override {
        temperature = temp;
        humidity = hum;
        display();
    }

    void display() override {
        cout << "Current conditions: "
             << temperature << "C degrees and "
             << humidity << "% humidity" << endl;
    }
};

class StatisticsDisplay : public Observer, public DisplayElement {

private:
    float maxTemp = 0.0f;
    float minTemp = 100.0f;
    float tempSum = 0.0f;
    int numReadings = 0;
    Subject* weatherData;

public:
    StatisticsDisplay(Subject* wd) : weatherData(wd) {
        weatherData->registerObserver(this);
    }

    void update(float temp, float hum, float pres) override {
        tempSum += temp;
        numReadings++;

        maxTemp = max(maxTemp, temp);
        minTemp = min(minTemp, temp);

        display();
    }

    void display() override {
        cout << "Avg/Max/Min temperature = "
             << (tempSum / numReadings) << "/"
             << maxTemp << "/"
             << minTemp << endl;
    }
};

// ================= Main (Simulation) =================
int main() {

    WeatherData weatherData;

    CurrentConditionsDisplay currentDisplay(&weatherData);
    StatisticsDisplay statisticsDisplay(&weatherData);

    weatherData.setMeasurements(25.0f, 65.0f, 1013.0f);
    weatherData.setMeasurements(28.0f, 70.0f, 1012.0f);
    weatherData.setMeasurements(22.0f, 90.0f, 1011.0f);

    return 0;
}
