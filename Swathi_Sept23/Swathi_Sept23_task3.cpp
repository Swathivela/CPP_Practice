How it works

main creates an array {1,2,3,4,5,6,7,8,9,10}.

Calls someFunction(a, 0).

Inside someFunction:

If current < b.size(), it calls itself with current + 1.

This continues until current == b.size() (the base case → recursion stops).

Then, as the recursion unwinds, it prints b[current].

Order of execution

First recursive calls go all the way down: someFunction(b, 10) does nothing.

Then printing happens in reverse:

b[9] → prints 10

b[8] → prints 9

…

b[0] → prints 1

✅ Output
The values in the array are:
10  9  8  7  6  5  4  3  2  1

✅ What this program does

This program prints the elements of the array in reverse order using recursion.