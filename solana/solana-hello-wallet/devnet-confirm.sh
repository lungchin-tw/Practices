#!/bin/bash

set -x

TRANSACTION=5uYZxj3K8Qxo9QMsFjh2xtmnCLjbTphhNxTWmAFZHdRpi1w1Dsw4gKL2FEnHRjQkAPYdhZeYYomxobCKyaLGiSJy
ENDPOINT=https://api.devnet.solana.com

solana confirm -v $TRANSACTION --url $ENDPOINT
