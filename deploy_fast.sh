#!/bin/bash
# 1. Environment Check
if [[ -z "$VIRTUAL_ENV" ]]; then
    echo "Warning: [VENV_INACTIVE] - Please activate your Python 3.13.7 environment."
else
    echo "Environment: [VENV_ACTIVE] - Python 3.13.7"
fi

# 2. Performance Constants (March 17, 2026 Spot Prices)
readonly IBM_SPOT=252.58
readonly HYNIX_SPOT=1008500
readonly JPM_BATCH_VOL=1250000

# 3. Execution Logic
if [[ -f "./build/macro_engine_v8" ]]; then
    ./build/macro_engine_v8
else
    echo "Error: macro_engine_v8 binary not found in ./build/"
    exit 1
fi

# 4. Signal Logging
printf "[%s] SIGNAL: BATCH_COMPLETE | IBM: $%.2f | Hynix: ₩%d\n" \
    "$(date +%H:%M:%S)" "$IBM_SPOT" "$HYNIX_SPOT"
