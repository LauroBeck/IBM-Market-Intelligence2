#include <atomic>
#include <vector>
#include <optional>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

struct alignas(64) MarketSignal {
    double price_usd;
    double price_krw;
    double alpha;
    char symbol[16];
};

template<typename T, size_t Capacity>
class SPSCQueue {
    static_assert((Capacity & (Capacity - 1)) == 0, "Capacity power of 2");
public:
    bool enqueue(const T& item) noexcept {
        const size_t t = tail.load(std::memory_order_relaxed);
        const size_t next = (t + 1) & (Capacity - 1);
        if (next == head.load(std::memory_order_acquire)) return false;
        buffer[t] = item;
        tail.store(next, std::memory_order_release);
        return true;
    }
    std::optional<T> dequeue() noexcept {
        const size_t h = head.load(std::memory_order_relaxed);
        if (h == tail.load(std::memory_order_acquire)) return std::nullopt;
        T item = buffer[h];
        head.store((h + 1) & (Capacity - 1), std::memory_order_release);
        return item;
    }
private:
    T buffer[Capacity];
    alignas(64) std::atomic<size_t> head{0};
    alignas(64) std::atomic<size_t> tail{0};
};

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    double ibm_price = 249.25;
    double hynix_krw = 1008500.0;
    double fx_rate = 1335.0; // March 17 Spot Rate

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--ibm" && i + 1 < argc) ibm_price = std::stod(argv[++i]);
        if (arg == "--hynix" && i + 1 < argc) hynix_krw = std::stod(argv[++i]);
    }

    SPSCQueue<MarketSignal, 1024> signal_pipe;
    
    // Normalized Data Point
    MarketSignal global_flow = { ibm_price, hynix_krw, 0.64, "IBM/HYNIX" };
    double hynix_usd = global_flow.price_krw / fx_rate;

    if (signal_pipe.enqueue(global_flow)) {
        auto p = signal_pipe.dequeue();
        if (p) {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "[GLOBAL_V8] IBM: $" << p->price_usd 
                      << " | HYNIX: ₩" << (int)p->price_krw 
                      << " ($" << hynix_usd << ") | Alpha: " << p->alpha << "\n";
        }
    }
    return 0;
}
