//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~HOSPITAL MANAGEMENT SYSTEM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* doctors = column header node
patients = row header node
appointments = data nodes of the rows and columns */
typedef enum {head,data} TYPEFIELD;

struct entryNode
{
    int row;
    int col;
    int val;    //dummy variable having appointment details 
    char time[10];  //for the appointment timing
};

typedef struct multilist
{
    struct multilist *right;   //both header node and data node has right and down pointers hence they are wriiten common
    struct multilist *down;
    TYPEFIELD tag;
    union    //union - user defined data structure in which only 1 element can be chosen at once
    {
        struct multilist *next;  //either accessing header node to move to next node
        struct entryNode *entry;  //either accessing data node which contains row,col,val and time using pointer entry
    };
    
}MULTILIST;