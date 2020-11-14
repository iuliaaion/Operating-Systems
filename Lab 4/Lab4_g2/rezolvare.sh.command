#!/bin/bash
echo 'word:'
read word
grep -l "$word" a.txt b.txt
echo 'no of files:'
grep -l "$word" a.txt b.txt | wc -l
