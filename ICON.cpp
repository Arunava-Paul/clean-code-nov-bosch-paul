#include <iostream>

class Icon {
protected:
    float speed, glow, energy;
    int x, y;
    Icon() {}
public:
    virtual void move() = 0;
    virtual void flair() = 0;
};

class Spin : public Icon {
    bool clockwise; // need for spinner
    bool expand; // need for spinner
    bool vertical; // need for slider
public:
    void move() override {
        // spin
    }
    void flair() override {
        // spin
    }
};

class Slide : public Icon {
    int distance; // need for slider
public:
    void move() override {
        // slide
    }
    void flair() override {
        // slide
    }
};

class Hop : public Icon {
    bool visible; // need for hopper
    int xcoord, ycoord; // need for hopper
public:
    void move() override {
        // hop
    }
    void flair() override {
        // hop
    }
};

int main() {
    Icon* icon = new Spin();
    icon->speed = 1.0f;
    icon->glow = 0.5f;
    icon->energy = 100.0f;
    icon->x = 10;
    icon->y = 20;
    dynamic_cast<Spin*>(icon)->clockwise = true;
    dynamic_cast<Spin*>(icon)->expand = false;
    dynamic_cast<Spin*>(icon)->vertical = true;
    icon->move();
    icon->flair();
    delete icon;
    return 0;
}
