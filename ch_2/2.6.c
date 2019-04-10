/*
 * Write a function setbits(x, p, n, y) that returns x with the n bits that begin at position p
 * inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
 *
 * notes:
 *   - example, pg. 49: x = x & ~077
 *     - integer literals that start with 0 are intepreted in octal base (base 8), which means
 *       each digit corresponds to three bits in binary: 000 111 111.
 *     - 077 stored in 16 bits: 0000 0000 0011 1111.
 *     - ~ is the one's complement: it flips 0 to 1 and 1 to 0.
 *       - ~ 0000 0000 0000 1111 == 1111 1111 1100 000
 *     - & returns 1 if both bits are 1, 0 otherwise
 *     - x & ~077 compares each pair of bits with bitwise-and
 *       - xxxx xxxx xxxx xxxx
 *         1111 1111 1100 0000
 *       - this effectively 'masks off' the lowest 6 bits because they can only be 0 from &
 *       - so, xxxx xxxx xx00 0000 is the result (who knows what x is)
 * */

#include <stdio.h>

void setbits(unsigned x, int p, int n, int y); // why unsigned?

void main () {
}

void setbits (unsigned x, int p, int n, int y) {

}

