Row 0: [ (0,0)=1   (0,1)=2   (0,2)=3   (0,3)=4   (0,4)=5  ]
Row 1: [ (1,0)=6   (1,1)=7   (1,2)=8   (1,3)=9   (1,4)=10 ]
Row 2: [ (2,0)=11  (2,1)=12  (2,2)=13  (2,3)=14  (2,4)=15 ]
Explanation
sales[0][0] is set to 0 first.

Then sales[0][1], sales[0][2], sales[0][3], sales[0][4].

Then the loop moves to row 1 → sales[1][0], sales[1][1] … sales[1][4].

Finally, row 2 → sales[2][0] … sales[2][4].

So the initialization order is row-major:
(0,0) → (0,1) → (0,2) → (0,3) → (0,4) → (1,0) → … → (2,4)