#include <iostream>
#include <vector>

using namespace std;

// ================= Observer Interface =================
class ActionListener {
public:
    virtual void actionPerformed() = 0;
    virtual ~ActionListener() = default;
};

// ================= Subject =================
class Button {
private:
    vector<ActionListener*> listeners;

public:
    void addActionListener(ActionListener* listener) {
        listeners.push_back(listener);
    }

    void click() {
        cout << "Button clicked!" << endl;
        for (auto listener : listeners) {
            listener->actionPerformed();
        }
    }
};

// ================= Concrete Observers =================
class AngelListener : public ActionListener {
public:
    void actionPerformed() override {
        cout << "Don't do it, you might regret it!" << endl;
    }
};

class DevilListener : public ActionListener {
public:
    void actionPerformed() override {
        cout << "Come on, do it!" << endl;
    }
};

// ================= Client =================
int main() {

    Button button;

    AngelListener angel;
    DevilListener devil;

    button.addActionListener(&angel);
    button.addActionListener(&devil);

    // Simulate button click
    button.click();

    return 0;
}
