a) Random walk tour

The knight starts at some square.

At each step, pick one of its valid moves at random.

Mark the square as visited and continue until the knight can no longer move.

Print the board with the order of moves (1 → 64).

Result: usually the knight will only make it 15–25 moves before getting stuck (sometimes fewer, rarely more).

b) 1000 random tours

Run the random walk 1000 times.

Use a 1D array of size 65 (tourLength[65]) to count how many tours ended at each length (from 0 to 64).

At the end, print a table:

Tour Length   Frequency
1             0
2             3
...
24            118
25            230
...
64            0


Best result: maybe ~45–55 moves (depending on luck). A full 64-move tour is extremely unlikely with pure random moves.

c) Run until a full tour

Same as (b), but instead of stopping at 1000 tours, keep running until you hit a complete 64-move tour.

This could take thousands to millions of attempts (and hours of runtime, depending on machine speed).

Print the same statistics table once the first full tour is found:

Tour Length   Frequency
...
62            47
63            12
64            1


Question asked:

How many tours did it take? → Often in the tens or hundreds of thousands.

How much time? → Could be minutes or hours.

d) Comparison: brute force vs. accessibility heuristic

Accessibility heuristic (guided):

Idea: always move the knight to the square with the fewest onward moves.

Much more intelligent and structured.

Requires careful analysis of knight moves.

Runs very efficiently and usually produces full tours quickly.

Cons: not guaranteed 100% (in some variations, heuristic may fail).

Brute force random walk:

Idea: just try moves randomly and hope.

Very easy to code.

Requires huge computing power.

No guarantee of full tour in a reasonable time.

You only stumble on a full tour after many, many tries.

General pros/cons of brute force problem solving:

✅ Pros:

Simple to implement.

Requires little problem-specific knowledge.

Will eventually find a solution (if one exists).

❌ Cons:

Very inefficient, wasteful of time and resources.

No guarantee of solution in acceptable runtime.

Gives no insight into the problem structure.