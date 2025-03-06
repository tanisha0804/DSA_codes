// fow can we improve BST
/* ex: 30,20,10
                30    left skewed tree
                /
            ___20
            __/
            _10 
*********************rotations - can be done only on 3 nodes*******************************
this can be rotated to ->           20
                                    / \
                                ___10  30
no of possible trees = 30,20,10  &  30,10,20   &  10,30,20  &  10,20,30  &  20,30,10   &  20,10,30
3 elements = 6 trees = 3! trees
***********n elements = n! possible trees **********************

4 types of rotations -> convert BST to balanced BST[AVL tree]
balanced factor = height of left sub tree - height of right sub tree
                = Hl - Hr = {-1,0,1}
            |Bf| = |Hl - Hr| <= 1

ex:                             o  2-2 =0
                            ___/ \
                    1-0=1   __o   o   1-0 = 1
                            _/    /
                    0-0=0   o    o    0-0 = 0


ex:                            o  3-1=2    // not balanced BST [AAVL tree]  bcuz Bf =2 where it should only range between (-1,0,1)
                            __/ \
                0-1 = -1    _o   o  0-0=0
                            __\
                            ___o  1-0 = 1
                            __/
                            _o    0-0 = 0

rotataions in AVL tree
1. LL rotation
        //the 30,20,10 tree is rotated , because the imbalance is on left side the tree is pulled to the right
        30                           30   2-0 = 2                          20    1-1=0
        /    -> insert 10            /                                     / \
    ___20                           20            =>conversion            10  30  0-0=0
                                    /
                                ___10  // this is imbalanced

2. LR rotation [2 rotations first L then R]  
        //first 10,20 tree is rotated left side & then 30,20,10 tree is rotated right side 
        30                           30   2-0 = 2                    30                                20    1-1=0
        /    -> insert 20            /                               /                                 / \
    ___10                           20            =>conversion      20   =>conversion                 10  30  0-0=0   //now this is balanced
                                    _\                              /
                                    __10  // this is imbalanced    10//this is imbalanced aswell


3. RR rotation
        //the 10,20,30 tree is rotated , because the imbalance is on right side the tree is pulled to the left
        10                             10   2-0 = 2                            20    1-1=0
        _\    -> insert 30              \                                      / \
        __20                            20            =>conversion            10  30  0-0=0
                                        _\
                                        __30  // this is imbalanced

44. RL rotation
        //first 10,30 tree is rotated right side & then 10,20,30 tree is rotated left side 
        10                            10   2-0 = 2                    10                                     20    1-1=0
        _\    -> insert 20             \                               \                                     / \
        _30                            30            =>conversion      20  =>conversion                     10  30  0-0=0   //now this is balanced
                                    ___/                                \
                                    __20  // this is imbalanced         30//this is imbalanced aswell


********** single rotations -> LL & RR
********** double rotations -> LR & RL
rotations in greater trees -> JSP notes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
insertion in an AVL tree
elements -> 40,20,10,25,30,22,50

                                    40                             20
                                ___/                               / \
                                __20   =>LL rotation              10 40
                                __/
                                _10

                                20                        20    1-3=-2
                            ___/ \                        / \ 
                            __10 40       =>             10 40  2-0=2
                                _/                          /
                                25                         25
                                                            \
                                                            30
if multiple imbalances found
-> then consider the immediate ancestor of the recently added node
recently added node = 30 -> ancestor = 40
                                                    
                                        _20                 20
                                        / \                 / \
                                    ___10 40       ->      10  30
                                        __/                    / \
                                        _30                   25 40
                                        _/
                                        25
inserting further on 
                        20       1-3=-2                                                  25
                        / \                                                              / \
                    ___10  30       => RL rotation on nodes 20,30,25                    20  30        
                        ___/ \                                                         / \   \
                        __25 40                                                       10 22   40
                        __/
                        _22 
inserting 50
                    25  2-3=-1
                    / \
                ___20 30   0-2=-2
                __ / \  \
                __10 22  40
                        __\
                        __50
RR rotation on 30,40,50
                    _25  
                    /  \
                ___20   40      ==> AVL tree
                __ / \  / \
                __10 22 30 50

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ex: if the tree is balanced then insert 42
                                    40  //2-4=-2   so here we have RLLR  on the nodes below 40 hence just do RL roatation on 40,50,45
                                ___/  \
                                __30  50
                                __/ \  / \                                         rotation would give 
                                _20 35 45 60                                               45
                                    ___/ \  \                                              / \
                                    __41 40  70                                           40 50
                                    __\
                                    __42

                                    45  
                                ___/  \
                                __40   50
                                __/ \  / \
                                _30 41 42 60   
                                _/  ___/ \  \
                                20  __41 40  70
                                    __\
                                    __42
//insert into AVL tree -> 9,15,20,8,7,13,10
*/

/* AVL tree - deletion
1. same as deletion in BST
if leaf node = just remove the node as it has no links
if only one child = replace child value with the node that is to be deleted
if 2 child = 1. inorder predecessor -> take max value of left sub tree
            2. inorder successor -> take min value from right sub tree
2. check for balance factor in all nodes
3. if its not satisfied then perform rotations until all nodes have satisfactory balance factor
tree-                                           14
                                                / \
                                            ___11  19
                                            __/ \  / \
                                            _7  12 17  53
                                            / \  \  /   / \
                                            4 8  13 16 20 60 //it is a AVL tree(balanced binary search tree) 
1. delete 8 -> just remove the node as it has no child
                                                14
                                                / \
                                            ___11  19
                                            __/ \  / \
                                            _7  12 17  53
                                            /    \  /   / \
                                            4    13 16 20 60   // this is also balanced
2. delete 7 -> has only left child 4 -> so copy 4 to 7 and delete the 7 node
                                                14
                                                / \
                                            ___11  19
                                            __/ \  / \
                                            _4  12 17  53
                                            _    \  /   / \
                                            _    13 16 20 60  // this is also balanced
3. delete 11 -> has both the children -> has both the children -> following inorder predeccesor -> max element of LST is considered - it has only 1 node 4 hence 4 is copied to 11 and 11 is deleted
                                                14
                                                / \
                        bf = 0-2 = -2        ___4  19  //imbalance occured
                                            __  \  / \
                                            _   12 17  53
                                            _    \  /   / \
                                            _    13 16 20 60
//rotation required -> RR rotation on 4,12,13 and now the tree becomes
                                                14
                                                / \
                                            ___12  19
                                            __/ \  / \
                                            _4  13 17  53
                                            _       /   / \
                                            _       16 20 60 
following inorder successor hence minimum of right sub tree is replaced with that number and 11 is deleted
                                                14
                                                / \
                                            ___12  19
                                            __/ \  / \
                                            _4  13 17  53
                                            _       /   / \
                                            _       16 20 60 //its balanced no rotations required
4. delete 14 -> following inorder predecessor -> find max of LST = 13 and replace with 14                                        
                                                13
                                                / \
                                            ___12  19
                                            __/    / \
                                            _4    17  53
                                            _       /   / \
                                            _       16 20 60  // its balanced
if inorder successor performed -> find min of RST and replace with 14
                                                16
                                                / \
                                            ___12  19
                                            __/ \  / \
                                            _4  13 17  53
                                            _          / \
                                            _          20 60  // its balanced
// NOTE: ********************** after inorder predecessor or sucessor the trees can be different but all that matters is it in BST ************************************                                            
*/