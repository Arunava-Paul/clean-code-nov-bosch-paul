#include <iostream>
using namespace std;

class RC {
    string vehicleRegNo;
public:
    ~RC() {
        cout << "RC Destructed" << endl;
    }
    RC() {
        cout << "RC Constructed" << endl;
    }
};

class TPMS {
public:
    virtual ~TPMS() {
        cout << "TPMS Destructed" << endl;
    }
};


class NexDigitronTPMS : public TPMS {
public:
    ~NexDigitronTPMS() override {
        cout << "NexDigitronTPMS Destructed" << endl;
    }
    NexDigitronTPMS() {
        cout << "NexDigitronTPMS Constructed" << endl;
    }
};

class BoschTPMS : public TPMS {
public:
    ~BoschTPMS() override {
        cout << "BoschTPMS Destructed" << endl;
    }
    BoschTPMS() {
        cout << "BoschTPMS Constructed" << endl;
    }
};


class Engine {
public:
    ~Engine() {
        cout << "Engine Destructed" << endl;
    }
    Engine() {
        cout << "Engine Constructed" << endl;
    }
};

class Car {
    Engine engine;
    TPMS* tpms;
    string regNumber;

public:
    Car(TPMS* ptr) {
        tpms = ptr;
        cout << "Car Constructed" << endl;
    }
    ~Car() {
        cout << "Car Destructed" << endl;
    }

};

void buildCarWithBoschTPMS(BoschTPMS* ptr) {
    Car alto(ptr);
}

void buildCarWithNexDigitronTPMS(NexDigitronTPMS* ptr) {
    Car swift(ptr);
}

int main() {
    BoschTPMS bTpms;
    NexDigitronTPMS ndTpms;
    buildCarWithBoschTPMS(&bTpms);
    buildCarWithNexDigitronTPMS(&ndTpms);
    return 0;
}