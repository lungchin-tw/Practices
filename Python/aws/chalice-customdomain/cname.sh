#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

aws route53 change-resource-record-sets \
--hosted-zone-id Z06618633TQOWFB1F6FN \
--change-batch \
'{
	"Changes": [{
		"Action": "CREATE",
		"ResourceRecordSet": {
			"Name": "_7ff4807290b819bd322604fd3fd3d957.jacky-chen-chalice-demo.amber.tw.",
			"Type": "CNAME",
			"TTL": 300,
			"ResourceRecords": [{
				"Value": "_7e98400474bcbaf01bedaa2204bdb410.bwfqbhlrkg.acm-validations.aws."
			}]
		}
	}]
}'

aws acm wait certificate-validated \
--certificate-arn arn:aws:acm:eu-central-1:422686820116:certificate/ec5df977-58dd-43ad-b708-72742c5cc5e1
