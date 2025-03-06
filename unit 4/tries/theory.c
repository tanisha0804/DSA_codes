/* TRIE TREE
digital search tree which need not be implemented as binary tree
each node contains m pointers corresponding to m possible symbols in each position of key 
used to store strings
each node stores a bit indicating if string is spelled out at this point in set
if the keys are numeric - there would be 10 pointers in node
if keys are alphabets there would be 26 pointers
also contains extra pointer indicating end of key/flag (symbol $ used)

tries are implemented based on prefix of a string*/

/* SUFFIX TRIE - compressed trie tree
simple data structure for string searching
space-efficient data structure to store strings that allows many kind of queries to be answered quickly
properties: 
- suffix tree to text(X) of size(n) from alphabet of size(d)
stores n(n-1) suffixes of x
supports arbitary pattern matching & prefix matching queries

APPLICATIONS
english dictionary, predictive texts, auto complete dictionary
ADVANTAGES 
faster that bst, printing strings in alphabetical order gets easy
prefix search can be done(autom complete)
DISADVANTAGE 
need a lott of memory space
stores too many node pointers  */