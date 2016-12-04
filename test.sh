#!bin/sh
echo ""
echo "Process group A\n"
time ./a.out 0 &
echo ""
echo "Process group B\n"
time ./a.out 1 &
echo ""
echo "Process group C\n"
time ./a.out 2 &
echo ""

