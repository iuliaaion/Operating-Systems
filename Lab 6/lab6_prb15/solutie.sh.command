#!/bin/bash
touch Tom.txt
echo '7
9
8
10
10' >> Tom.txt
touch Jill.txt
echo '7
6
6
5
7' >> Jill.txt
touch Sally.txt
echo '5
6
9
10
9' >> Sally.txt
touch Emily.txt
echo '5
5
10
6
7' >> Emily.txt
touch note_vara.txt
awk '{sum +=$1} END {print "Tom", sum/5}' Tom.txt >> note_vara.txt
awk '{sum +=$1} END {print "Jill", sum/5}' Jill.txt >> note_vara.txt
awk '{sum +=$1} END {print "Sally", sum/5}' Sally.txt >> note_vara.txt
awk '{sum +=$1} END {print "Emily", sum/5}' Emily.txt >> note_vara.txt
sort -nr -k2,2 note_vara.txt -o note_vara.txt
touch note.txt
paste medii.txt note_vara.txt | awk '{print($2+$4)/2}' >> note.txt
cut -d' ' -f1 medii.txt | paste - note.txt | tee medii.txt
sort -nr -k2,2 medii.txt -o medii.txt
awk -F' ' '$2>8.5{print $1,$2}'< medii.txt | tee medii.txt
