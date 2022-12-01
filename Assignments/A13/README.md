# 1749 - Airport Construction

## Summary
Essentially, the backstory behind this problem is that this small tourist island is in need of creating an airstrip. However, this airstrip must be as big as possible so that they can bring in bigger planes which means more people. Put simply, the problem is one that requires us to take a polygon, and calculate the longest line segment that can fit within its bounds.

## Problem Break Down
The algorithms to solve this depend on how precise of an answer you need. As described in the PDF, the answer must have an absolute or relative error of at most 10<sup>-6</sup>. That's a lot of decimal places. On top of that, if we are given a polygon only containing, three vertices, then there isn't a whole lot of data to work with. 

### Potential Solution 1 (My way which probably sucks)
One way is to create all combinations of points, and use the distance formula to calculate which pair of points generates the biggest line. The only problem with that is what happens when it is clear that there is a line going from edge to edge that is bigger than what the vertices can produce.

### Potential Solution 2 (Some way I found online which is definitely way better)
[Longest Line in Polygon](https://github.com/BradleyWood/Longest-Line-In-Polygon)
