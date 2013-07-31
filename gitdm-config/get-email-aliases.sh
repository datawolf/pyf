#!/usr/bin/env bash

set -x

GIT=~/git/openstack
PROJECTS="nova glance swift horizon keystone cinder"

for project  in $PROJECTS; 
    do cat $GIT/$project/.mailmap; 
done | \
grep -v '^#' | sed 's/^[^<]*<\([^>]*\)>/\1/' | \
grep -E '<.+>' | \
 awk '{print $1 $NF}' | \
sed -e 's/[<>]/ /g' | \
sort | uniq > aliases
