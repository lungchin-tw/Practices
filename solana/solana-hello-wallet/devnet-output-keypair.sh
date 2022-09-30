#!/bin/bash

set -x

solana-keygen recover 'prompt:?key=0/0' -o sender-keypair.json
