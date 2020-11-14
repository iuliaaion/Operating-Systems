#!/bin/bash
awk '{x[i++]=$0} END {for(j=i;j>=0;j--) print x[j]}' a.txt b.txt 
