# 🚀 Oracle Macro Engine (v9)


![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Language](https://img.shields.io/badge/language-C%2B%2B17-blue)
![Status](https://img.shields.io/badge/status-production-black)
![Version](https://img.shields.io/badge/version-v9.0-gold)
![Strategy](https://img.shields.io/badge/strategy-macro--systematic-purple)
![Volatility](https://img.shields.io/badge/regime-low--vol-green)



Multi-layer macroeconomic engine written in C++ for systematic market regime detection.

## 🧠 Features

- 📈 Growth (Capex acceleration)
- 🛢️ Inflation (Oil dynamics)
- 💻 Sector Rotation (Tech vs Industrials)
- 🏦 Interest Rates (US10Y)
- 💵 Dollar Liquidity (DXY)
- 🥇 Gold (Risk sentiment)
- 📉 Yield Curve (2Y–10Y)
- 💳 Credit Spreads (HY)
- 📊 VIX (Volatility regime)

---

## 📡 Latest Engine Output

```text
Alpha: 0.66
Regime: 🟢 Risk-On

Rotation:
→ Industrials ↑
→ Tech ↓

Macro:
FED: Easing
USD: Weak
Gold: Weak

Systemic Risk:
Yield Curve: Inverted ⚠️
Credit: Stable
VIX: Low

Positioning:
→ Partial Long (33%)
→ Scale in (low vol trend)
---


---

# 🧱 ADD ARCHITECTURE (VERY IMPORTANT)

```md
---

## 🏗️ Architecture

data/ → macro inputs (CSV)
src/ → engine core (C++)
build/ → compiled binaries
docs/ → research / models



---

# ⚡ ADD ROADMAP (INVESTOR STYLE)

```md
---

## 🛣️ Roadmap

- v10 → Portfolio allocator
- v11 → Live data (Bloomberg / APIs)
- v12 → Web dashboard (React + Node)
- v13 → AI macro forecasting layer
## ⚙️ Build

```bash
g++ -O3 -march=native -std=c++17 src/macro_engine_v9.cpp -o build/macro_engine_v9
./build/macro_engine_v9
tech,capex,oil,us10y,us2y,dxy,gold,hy_spread,vix
