#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws acm request-certificate \
--domain-name "*.jacky-chen-chalice-demo.com" \
--validation-method DNS \
--idempotency-token 1234 \
--options CertificateTransparencyLoggingPreference=DISABLED \
| tee acm-cert.log
