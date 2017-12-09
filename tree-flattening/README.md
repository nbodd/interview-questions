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

Input

A &#2192; B
<br>&#2193; <br>
C

Output

A &#2192; C &#2192; B


Input

A &#2192; B
<br>&#2193; <br>
C &#2192; D &#2192; F
<br>&#2193; <br>
E

Output

A &#2192; C &#2192; E &#2192; D &#2192; F &#2192; B
