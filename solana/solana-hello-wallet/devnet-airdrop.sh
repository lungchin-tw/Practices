#!/bin/bash

set -x

WALLET=A6Vh7MDPJn67y7wCiQJ82roi3uTeX9gpfJK5AkBSPoSV
ENDPOINT=https://api.devnet.solana.com

solana balance $WALLET --url $ENDPOINT
echo ""
solana airdrop 1 $WALLET --url $ENDPOINT
solana balance $WALLET --url $ENDPOINT
