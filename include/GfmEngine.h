#pragma once

#include <string>

class GfmEngine {
public:
    // Constructor & Destructor
    GfmEngine();
    ~GfmEngine();

    bool run();

    // Getter Setter
    bool isRunning() const { return running; }
    
private:
    bool running { false };
};