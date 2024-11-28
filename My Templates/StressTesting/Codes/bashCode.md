```
// Bash Script for Stress Testing: (checker.sh)

for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > in.txt
    diff -w <(./a < in.txt) <(./b < in.txt) || break
done


