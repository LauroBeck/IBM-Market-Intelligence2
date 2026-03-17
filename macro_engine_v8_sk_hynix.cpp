#include <iostream>
#include <iomanip>
#include <string>

struct ScarcityMultiplier {
    double base_alpha = 0.666667;
    double hbm4_dominance = 0.57;      // SK Hynix Market Share
    double wafer_deficit = 0.20;       // 20% industry shortfall (Bloomberg/GTC)
    int year_target = 2030;
};

void run_sk_hynix_multiplier(ScarcityMultiplier &m) {
    // Logic: Capex is no longer efficient. 
    // "Inflationary Capex" = Spending 1.0 but getting 0.8 worth of compute.
    double capex_efficiency = 1.0 - m.wafer_deficit; 
    
    // SaaS/Cloud Margin Compression Factor (Costs rising faster than revenue)
    double saas_drag = m.wafer_deficit * 1.5; 
    
    // Infrastructure Alpha (IBM/SK Hynix/NVIDIA) capturing scarcity premium
    double infra_alpha_boost = m.hbm4_dominance * 1.2;

    double final_alpha = (m.base_alpha + infra_alpha_boost) - saas_drag;

    std::cout << "\033[1;33m=== SK HYNIX: SCARCITY MULTIPLIER (GTC 2026) ===\033[0m" << std::endl;
    std::cout << "Structural Deficit until : " << m.year_target << std::endl;
    std::cout << "Capex Efficiency         : " << std::fixed << std::setprecision(2) 
              << capex_efficiency << " [INFLATIONARY]" << std::endl;
    std::cout << "Infrastructure Boost     : +" << infra_alpha_boost << std::endl;
    std::cout << "SaaS/Cloud Drag          : -" << saas_drag << std::endl;
    std::cout << "\033[1;32mFinal Adjusted Alpha     : " << std::setprecision(6) << final_alpha << "\033[0m" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "STRATEGY: LONG Infrastructure (IBM/SKH) | SHORT General Cloud" << std::endl;
}

int main() {
    ScarcityMultiplier m;
    run_sk_hynix_multiplier(m);
    return 0;
}
