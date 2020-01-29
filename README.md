# perm

**perm** turns tetris pieces into numbers.

If you take a 16-bit integer and represent it as a square four bits long, you can mark down the shape of a tetris piece anywhere within it and come up with some number representation of that shape.

You could even normalize those representations, rather than have (for example) four unique values for a vertical line piece, leaving a single int value for each legitimate shape.

You could *even* generate all these numbers ahead of time, since they won't change or anything, and include them as magic numbers elsewhere instead of deriving them each time.

**perm** was written in part as an exercise in bitwise manipulation.

**perm** was written mostly to prove a point elsewhere.