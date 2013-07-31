#!/usr/bin/env  bash
set -x

GIT=~/git/openstack
PROJECTS="nova glance swift horizon keystone cinder"

for project  in $PROJECTS; 
    do cd  $GIT/$project; \
    git log |  grep  '^Author:' | grep '@' | sed -e 's/[<>]/ /g' | awk '{print $NF}';
done | \
sort | uniq | grep -v '\((none)\|\.local\)$' > tmp
