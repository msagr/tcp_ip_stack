#include "../gluethread/glthread.h"
#include <stdlib.h>
#include <stdio.h>

/* Private function to add a new_node right after curr_node */
static void _glthread_add_next(glthread_node_t *curr_node, glthread_node_t *new_node){
    if(!curr_node->right){
        curr_node->right = new_node;
        new_node->left = curr_node;
        return;
    }

    glthread_node_t *temp = curr_node->right;
    curr_node->right = new_node;
    new_node->left = curr_node;
    new_node->right = temp;
    temp->left = new_node;
}

/* Fn to insert GLnode into a glthread at the first position
 * in a glthread i.e. new node becomes a head
*/

void 
glthread_add (glthread_t *list, glthread_node_t *glnode) {
    glnode->left = NULL;
    glnode->right = NULL;
    if(!list->head){
        list->head = glnode;
        return;
    }
    glthread_node_t *head = list->head;
    glthread_add_next(glnode, head);
    list->head = glnode;
}