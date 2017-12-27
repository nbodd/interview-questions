# Tree Flattening

### Problem
To Convert a binary tree into a linked list.

### Description
Imagine a binary tree with a node representation of 
```
using ValueType = char;

struct Node {
    Node*       next;
    Node*       down;
    ValueType   value;
};
```

Rules to flatten the tree

* No new nodes can be created, only reassinging of pointers is allowed.
* While flattening, the down node takes priority over the next node (see examples).

### Example

#### Input

A -> B <br>
|<br>
+<br>
C

#### Output

A -> C -> B


#### Input

A -> B <br>
|<br>
+<br>
C -> D -> F <br>
|<br>
+<br>
E

#### Output

A -> C -> E -> D -> F -> B
