//hashing = technique used in data structures for efficient retrieval of data
/* involves converting an input key into a 'fixed-numerical value' called the hash code/hash value using hash function
hash function -> converts input key to hash code
hash code that is genrated is used as index in hash table(array like structure), which actually stores the data

hashing enshures that different input/key map to unique indices(hash code)allowing constant time complexity of the oder 1 [o(1)]

*/

/* ex: keys to be inserted -> 24,52,91,67,48,83
hash function -> (most used)*k mod 10 or *k mod n also.... mid square function , folding function

collision occurs when 2 keys point to same hash code to be used in hash table
COLLISION RESOLUTION TECHNIQUES:  //can be for GATE
1. open addressing(closed hashing)
-> 1. linear probing
-> 2. quadratic probing
-> 3. double hashing
2. seperate addressing(open hashing) 
3. rehashing[hash again] (dynamic resizing the hash table)*/


/* seperate addressing -
keys = 24,19,32,44,58
hash function - k mod 6
the hash table exists from 0 to [n-1]5

hash table    index
24              0
19              1
32              2
now 44%6 = 2 -> collision [do insert at front]
the collision node becomes the head of the linked list and gets linked to the other nodes
hash table    index
24              0
19              1
44,32           2   //in linked list the head node 32 goes forward at 44 becomes the head node and point to the node 32
                3
58              4
 */


/* LINEAR PROBING
this technique avoids collision by placing the data in the next available space of the sequence
generic = k mod n
then ((k mod n)+i)%n -> i = 0 at initial
                    -> i = no of collisions
key = 5,15,25,49,59    n=10

hash table       index
....                ...
5                   5        ((5%10)+0)%10 = 5
15                  6        ((15%10)+1)%10 = 6     now i = 1 because collision would occur
25                  7        ((25%10)+1)%10  = 6    but this place is already occupied hence collision occurs again take i = 2
                            ((25%10)+2)%10  = 7   
..                  ..
49                  9
59                  0          ((59%10)+1)%10 = 0*/

/*hash table         index
59                     0
....                   ...
5                      5
15                     6
25                     7
..                     ..
59                     9
*/

/* QUADRATIC PROBING
hash function = ((k mod n) + i^2)%n    i = no of collisions*/

/* DOUBLE HASHING
uses two hash functions to calculate hashcode(indices of hash table)
effective in distributing key more evenly across the hash table where as linear probing sequentially inserts elements when collision occurs
reduces cluster format at certain areas in table
primary hash = usual hash function that we use
key % n
secondary hash =  any functopn preferably prime number
const - (key%const)

probing sequence to resolve collision
index = (primary hash + (i*secondary hash))% n
benifits:
to avoid collision
reduce cluster computed in linear/quadratic probing
allows better distribution and utilisation of hash table
*/

/* rehashing
essential in growing hash table dynamically
similar to dynamic array allocation but a lil complex
to increase size of hash table - you cant just double it
use the next prime after doubling the size and thats how u increase size of hash table 
create new array and new size , go thru old array and insert each element in new array and delete the old array
set indices using hash function to use the new array
*/