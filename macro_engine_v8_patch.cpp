#include <iostream>
#include <iomanip>

int main() {
    // Current state from your v8 output
    double alpha = 0.666667;
    double capex_accel = 1.0;
    double vol = 0.00812465;
    
    // NEWS INJECTION: SK Hynix 2030 Memory Crunch
    // Impact: High Scarcity = High Hardware Cost = Capex Headwind
    double scarcity_index = 0.88; // 0 to 1 scale
    double hardware_inflation = scarcity_index * 0.15;
    
    // Adjusting Alpha for persistent supply-side constraints
    double adjusted_alpha = alpha * (1.0 - (hardware_inflation * 0.5));

    std::cout << "\033[1;34m=== MACRO ENGINE v8: 2030 CHIP CRUNCH PATCH ===\033[0m" << std::endl;
    std::cout << "Original Alpha  : " << alpha << std::endl;
    std::cout << "Adjusted Alpha  : " << std::fixed << std::setprecision(6) << adjusted_alpha << std::endl;
    std::cout << "Hardware Risk   : " << hardware_inflation << " (SK Hynix 2030 Factor)" << std::endl;
    
    if (adjusted_alpha < 0.60) {
        std::cout << "\033[1;31m→ ALERT: Scarcity eroding Goldilocks setup. De-risk SaaS.\033[0m" << std::endl;
    } else {
        std::cout << "\033[1;32m→ REGIME STABLE: Semi-conductor pricing power remains.\033[0m" << std::endl;
    }

    return 0;
}
