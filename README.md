# IBM-Market-Intelligence-V2 🚀

![C++ CI Sanity Check](https://github.com/LauroBeck/IBM-Market-Intelligence-V2/actions/workflows/ci.yml/badge.svg)

A high-performance, lock-free C++ engine designed for real-time market signal processing and global tech-heavy correlation. Optimized for the **IBM (NYSE: IBM)** and **SK Hynix (KRW)** scarcity basis.

## 🏗️ Core Architecture: Lock-Free SPSC Queue
The engine utilizes a **Single-Producer Single-Consumer (SPSC)** lock-free queue to minimize latency in the hot path. By avoiding mutexes and context switching, it is built to handle the 1.25M unit batches typical of institutional **JPM China Flow** data.

### ⚡ Memory Ordering Logic
To ensure zero-latency thread synchronization, we implement `std::memory_order`:
* **`std::memory_order_release`**: Used during `enqueue` to ensure all previous writes to the buffer are visible before the tail pointer is updated.
* **`std::memory_order_acquire`**: Used during `dequeue` to synchronize with the producer, ensuring the most recent data is safely read without expensive locking.

## 🌎 Global FX Normalization
The engine dynamically normalizes global tickers to a USD-denominated "Scarcity Basis."
* **Primary Target:** IBM ($252.58 baseline following the $11B Confluent merger).
* **Correlation Target:** SK Hynix (₩1,008,500).
* **FX Engine:** Real-time KRW/USD conversion (Spot: 1,486.33) to identify arbitrage inflection points in the semiconductor supply chain.

## 🚀 Deployment
Quick-start for the macro intelligence suite:
```bash
# Build and Run with custom spot prices
./deploy_fast.sh --ibm 252.58 --hynix 1008500
March 17, 2026 Snapshot

    IBM: Tracking $252.58 post-acquisition close.

    S&P 500: Monitoring the 6,700 line (Current: 6,729.49).

    Release: v1.1.0-fx-ready
    EOF
