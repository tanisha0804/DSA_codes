/* SPLAY TREES = self adjusting BST 
recently accessed nodes are moved to the root thru rotations
*******************helps frequently occuring nodes to stay closer to root, making future access faster**********************
ex: spotify playlist -> frequently played songs are always kept on top
applications = 1. cache (recently accessed ones are on cache for memory management)
2. data management(adaptive huffman coding)
3. garbage collection
4. network routers/fireworks (session tracking)
5. scheduling tasks


working: when u search for a node in splay tree,the tree rearranges itself so that the accessed node becomes the root
operation: insert,delete,search
bringing the node to the root = splaying

rotations: 
1. zig  [right]         1 & 2 collectively called = zig [zig-left = zag]    //single rotations   ---> done on the nodes that do not have any grandparents[child of the root]
2. zag  [left]
3. zig-zig              3 & 4 collectively called = zig-zig [zig-zig left = zag-zag]   //double rotations of same side   --> done on nodes that have parents & grandparents & both in same direction
4. zag-zag
5. zig-zag              5 & 6 collectively called = zig-zag [zig-zag left = zag-zig]    //double rotations of opp side  --> done on nodes that have parents & grandparents & both in opposite direction
6. zag-zig


1. zig 
                                            10
                                            / \
                                        ___7   20
                                        __/ \   \
                                        _1  9   30
search 7 -> so 7 shd be made as root -> rotate 7 to right
                                            _7
                                            / \
                                        ___1   10
                                        __     / \
                                            ___9  20
                                                _ \
                                                _  30
2. zag
search 20 -> so 20 shd be made root -> rotate 20 to left
                                            20
                                            / \
                                        __10  30
                                        __/
                                        __7
                                        _/ \  
                                        1  9      
3. zig zig 
search 1 -> so 1 shd become the root -> double rotate -> first 7 becomes root then 1 becomes root
rotation starts from the grandparent
                                            10
                                            / \
                                        ___7   15
                                        __/ \  / \
                                        _1  9 13  20 
                                        /          \
                                        -1         30
rotating grandparent = 
                                            _7
                                            / \
                                        ___1   10
                                        __/    / \
                                        _-1   9  15 
                                                _/ \
                                                13 20
                                                    \
                                                    30
parent rotation = 
                                            _1
                                            / \
                                        __-1   7 
                                                \
                                                10
                                        _      / \
                                        _     9  15 
                                                _/ \
                                                13 20
                                                    \
                                                    30

4. zag-zag rotation = search 20 -> make 15 root  first then 20
                                            15
                                            / \
                                        ___10  20
                                        __/ \   \
                                        __7 13  30 
                                        _/ \  
                                        1  9  
                                        /         
                                        -1    
parent rotation =                                             
                                            20
                                            / \
                                        ___15    30
                                        ___/
                                        __10  
                                        _/ \  
                                        7 13  
                                    ___/ \  
                                    __1  9  
                                    _/         
                                    -1 

5. zig-zag rotation
search 8
                                            10
                                            / \
                                        ___7   15
                                        __/ \  / \
                                        _1  9 13  20 
                                        _  /  / \        
                                        _  8  11 14
parent(9) on right grandaprent(7) on left
**************************parent rotation first**********************************8
1. parent rotation
                                            10
                                            / \
                                        ___7   15
                                        __/ \  / \
                                        _1   8 13  20 
                                        _    \  / \        
                                        _    9  11 14
2. grandparent rotation
                                            10
                                            / \
                                        ___8   15
                                        __/ \  / \
                                        _7   9 13  20 
                                        _/       / \        
                                        _1      11 14
one more rotation to make 8 the root
                                            _8
                                            / \
                                        ___7   10
                                        _ /    / \
                                        _1    9   15
                                        __        / \
                                        _        13  20 
                                        _       / \        
                                        _      11 14
\

6. zag-zig rotation
search 9
                                            10
                                            / \
                                        ___7   15
                                        __/ \  / \
                                        _1   9 13  20 
                                        _    /  / \        
                                        _    8  11 14
1. parent(7) rotation
                                            10
                                            / \
                                        ___9   15
                                        __/    / \
                                        _7    13  20 
                                        / \   / \        
                                        1  8  11 14
2. grandparent rotation(10)
                                            _9
                                            / \
                                        ___7   10
                                        __/ \   \
                                        _1   8  15 
                                        _      / \        
                                        _     13  20
                                        _     / \ 
                                        _    11 14
*/

//insertion of splay tree
/* insert the following elements in the splay tree
15,10,17,7,13,16
add every tree and make it the root
//see notes
*/

/* deletion of node
delete the node and the parent of node(the node that was recently accessed to the find the node that is to be deleted) is to be splayed to the root
//ex: see in notes */




