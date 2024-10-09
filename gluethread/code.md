**Traditional Linked List**
```
    typedef struct dll_node_ {
        void *data;
        struct dll_node_ *left;
        struct dll_node_ *right;
    } dll_node_t;
```

**Glued Doubly Linked List**
```
    typedef struct glthread_node_ {
        struct glthread_node_ *left;
        struct glthread_node_ *right;
    } glthread_node_t;
```

**Note** -> It does not have void *data field.
(Then how does it hold the application data ?)