/* MULTILIST:
    sparse matrix = matrix in which most of the values are zero
        if stored compltely can waste a lot of memory space
        ~~> alternate representations:
        1. triple notation - matrix represented as an array of tuple values which consists of row no,column no and value
        2. multilist representation - 2 nodes created -header and data node
         */

/* SKIPLIST 
    probabilistic data structure that allows efficient search,insertion,deletion of elements in a sorted list.
    average time complexity determined through probabilistic analysis
    elements are organised in layers,with each having a smaller no of elements than the one below it
    bottom layer -consists all elements = regular LL
    level i links every 2^i th node
    each level has half the nodes of the one below it
    layers above contain skipping links that allows faster navigation(quick traversal to the desired element)
    average time complexity of skiplist = O(log n) 
    searching  starts in sparsest subsequence until 2 consecutive elements have been found
    one small and one large or equal to element to be searched for 
    element to search = x , current position = p , y = key after p
    x=y = return the element
    x>y = we 'scan forward'
    x<y = we 'srop down'
*/
