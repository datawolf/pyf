#!/usr/bin/env bash
#
#  This script can find all patches about an sppecific file
#  Version : The impoved version
#  Author  : Wang Long <long.wanglong@huawei.com>
#  Date    : 2014.07.16
set -x

FILE=$1
TEMP=tmp_commit.txt
COMMIT=ok_commit.txt
count=1

git blame  $FILE  >>  $TEMP

cat $TEMP  |  awk '{print $1, $5}' | sort -k 2 | uniq | awk '{print $1}'  >> $COMMIT

while read commit 
do
        echo $commit
        git format-patch -1 $commit     --start-number $count
        let  count=$count+1
done < $COMMIT

rm -fr $TEMP $COMMIT
