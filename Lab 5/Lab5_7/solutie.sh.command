#!/bin/bash
awk 'length>30 {print "File-", FILENAME, ",line-", FNR, ",first word-", $1, ",last word-", $NF}' a.txt b.txt c.txt
