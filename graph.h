#include "gluethread/glthread.h"

/* constants */
#define NODE_NAME_SIZE  16
#define IF_NAME_SIZE    16
#define MAX_INTF_PER_NODE   10

/* Forward Declarations */
typedef struct node_ node_t;
typedef struct link_ link_t;

typedef struct interface_ {
    char if_name[IF_NAME_SIZE]; // interface name
    struct node_ *att_node; // owning node
    struct link_ *link;
} interface_t;

struct link_ {
    interface_t intf1; // interface 1
    interface_t intf2; // interface 2
    unsigned int cost;
};

struct node_ {
    char node_name[NODE_NAME_SIZE];
    interface_t *intf[MAX_INTF_PER_NODE]; // if null then no interface, otherwise it will contain interface address
    glthread_t graph_glue; // to add node to graph
};

typedef struct graph_{
    char topology_name[32]; // topology name
    glthread_t node_list; // doubly-linked list
};