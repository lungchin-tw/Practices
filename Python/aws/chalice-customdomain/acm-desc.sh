#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws acm describe-certificate \
--certificate-arn "arn:aws:acm:eu-central-1:422686820116:certificate/77fc8cc2-a922-4b49-be3b-2d46ae3dcdde" \
--query Certificate.DomainValidationOptions[0] \
| tee acm-desc.log