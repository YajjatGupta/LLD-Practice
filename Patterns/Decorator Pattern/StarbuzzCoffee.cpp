#include <iostream>
#include <string>

using namespace std;

// ================= Component =================
class Beverage {
protected:
    string description = "Unknown Beverage";

public:
    virtual string getDescription() {
        return description;
    }

    virtual double cost() = 0;

    virtual ~Beverage() = default;
};

// ================= Concrete Components =================
class Espresso : public Beverage {
public:
    Espresso() {
        description = "Espresso";
    }

    double cost() override {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend() {
        description = "House Blend Coffee";
    }

    double cost() override {
        return 0.89;
    }
};

// ================= Decorator =================
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;

public:
    CondimentDecorator(Beverage* bev) : beverage(bev) {}
};

// ================= Concrete Decorators =================
class Milk : public CondimentDecorator {
public:
    Milk(Beverage* bev) : CondimentDecorator(bev) {}

    string getDescription() override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() override {
        return beverage->cost() + 0.10;
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* bev) : CondimentDecorator(bev) {}

    string getDescription() override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() override {
        return beverage->cost() + 0.20;
    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage* bev) : CondimentDecorator(bev) {}

    string getDescription() override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() override {
        return beverage->cost() + 0.15;
    }
};

// ================= Client =================
int main() {

    // Simple Espresso
    Beverage* beverage1 = new Espresso();
    cout << beverage1->getDescription()
         << " $" << beverage1->cost() << endl;

    // HouseBlend with Mocha + Milk + Whip
    Beverage* beverage2 = new HouseBlend();
    beverage2 = new Mocha(beverage2);
    beverage2 = new Milk(beverage2);
    beverage2 = new Whip(beverage2);

    cout << beverage2->getDescription()
         << " $" << beverage2->cost() << endl;

    // Cleanup (important)
    delete beverage1;
    delete beverage2;

    return 0;
}
