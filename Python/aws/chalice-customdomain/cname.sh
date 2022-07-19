#! /usr/bin/bash

set -x

echo '[dirname $0]:' $(dirname $0)
echo '[pwd]:' $(pwd)
pushd $(dirname $0)

pipenv run aws route53 change-resource-record-sets \
--hosted-zone-id Z1008064K841EQ94S3NG \
--change-batch \
'{
	"Changes": [{
		"Action": "CREATE",
		"ResourceRecordSet": {
			"Name": "_a8c76fc82ed66bf49ce335c81a574c93.jacky-chen-chalice-demo.com.",
			"Type": "CNAME",
			"TTL": 300,
			"ResourceRecords": [{
				"Value": "_bedfc3e7d64d8761532b8e1716d16cb6.bwfqbhlrkg.acm-validations.aws."
			}]
		}
	}]
}' | tee cname.log
