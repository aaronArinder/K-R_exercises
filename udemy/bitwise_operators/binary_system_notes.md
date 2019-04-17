#### Representing negative numbers

There are a few ways of representing negative numbers:

##### With a sign bit
The bit place that would normally be the most significant bit place is reserved for representing sign. This requires us to know how many bits the machine uses in order to determine a number's sign.

Problems with this method: if there are 4 bits, e.g., to represent a number, then 1000 and 0000 represent -0 and 0, respectiely. That means that were we to add 5 to -5, we'd get -2 rather than the expected 0 because 0101 (i.e., 5) added to 1101 (-5) is 0010, or 2.

So, weird that we have both -0 and 0, but also that addition gets wonky.

##### With one's complement
With 4 bits, 0 is 0000, -0 is 1111, 5 is 0101, and -5 is 1010. 0101 + 1010 = 1111, which is -0, not -2. For x - x, we'll get 1111. But for x + y, where y is both negative and not x, we get some funky results. E.g., 5 + -3 is 0101 + 1100, giving 0001 (or 1 in decimal). Another example: 6 + -2: 0110 + 1101 = 0011 (or 3). The result is always 1 off.

Problems with this method: we still have -0, and our addition is still wonky.

##### With two's complement
Rather than letting 1111 represent -0, let it represent -1. That is, remove -0 as a thing represented. This fixes our math: 0101 + 1011 = 0000 because each place sums to 2 (i.e., 10), so we put the 0 in the current bit place and carry the 1. Each 1 gets carried until the bit falls off the end of the msb; so, 0000.

Consider a previous example: 6 + -2: 0110 + 1110, which is 0100 (or 4). The math works out!

There's no sign bit, which is nice because that bit place gains mathematical meaning past signifying what side of 0 the number lives on. In a 4 bit representation, 1000 is -8 rather than what the first option, the simple sign bit, would have it be, -0, or what the one's complement would have it be, -7.

###### Important for two'complement: going from a positive number, x, to its negative counterpart, -x, requires first taking the one's complement, ~x, and then adding 1: ~x + 1. That gives the two's complement.
