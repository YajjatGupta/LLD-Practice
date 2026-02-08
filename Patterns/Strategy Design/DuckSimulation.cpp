#include <iostream>
#include <memory>

using namespace std;

// ================= Strategy Interfaces =================
class FlyBehavior
{
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};

class QuackBehavior
{
public:
    virtual void quack() = 0;
    virtual ~QuackBehavior() = default;
};

// ================= Fly Behaviors =================
class FlyWithWings : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I am flying with wings" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly() override
    {
        cout << "I can't fly" << endl;
    }
};

// ================= Quack Behaviors =================
class Quack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "Quack" << endl;
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "Squeak" << endl;
    }
};

class MuteQuack : public QuackBehavior
{
public:
    void quack() override
    {
        cout << "<< Silence >>" << endl;
    }
};

// ================= Duck (Context) =================
class Duck
{
protected:
    unique_ptr<FlyBehavior> flyBehavior;
    unique_ptr<QuackBehavior> quackBehavior;

public:
    virtual ~Duck() = default;

    virtual void display() = 0;

    void performFly()
    {
        flyBehavior->fly();
    }

    void performQuack()
    {
        quackBehavior->quack();
    }

    void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }

    // Runtime behavior change
    void setFlyBehavior(unique_ptr<FlyBehavior> fb)
    {
        flyBehavior = move(fb);
    }

    void setQuackBehavior(unique_ptr<QuackBehavior> qb)
    {
        quackBehavior = move(qb);
    }
};

// ================= Concrete Ducks =================
class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        flyBehavior = make_unique<FlyWithWings>();
        quackBehavior = make_unique<Quack>();
    }

    void display() override
    {
        cout << "I'm a real Mallard duck" << endl;
    }
};

class RubberDuck : public Duck
{
public:
    RubberDuck()
    {
        flyBehavior = make_unique<FlyNoWay>();
        quackBehavior = make_unique<Squeak>();
    }

    void display() override
    {
        cout << "I'm a rubber duck" << endl;
    }
};

// ================= Simulator (Main) =================
int main()
{

    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    cout << "------" << endl;

    Duck *rubberDuck = new RubberDuck();
    rubberDuck->display();
    rubberDuck->performFly();
    rubberDuck->performQuack();

    cout << "------ Runtime Change ------" << endl;

    rubberDuck->setFlyBehavior(make_unique<FlyWithWings>());
    rubberDuck->performFly();

    delete mallard;
    delete rubberDuck;

    return 0;
}
