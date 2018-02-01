
#include <iostream>
#include <cassert>

#define ASSERT(x) assert(x)

namespace treeflattening
{

struct Node
{
    char  value;
    Node *next;
    Node *down;

    Node(char ch) : value(ch), next(NULL), down(NULL)
    {
    }
};

bool isNull(Node *n)
{
    return NULL == n;
}

Node* tree_flatten_helper(Node *n)
{
    if (isNull(n))
        return NULL;

    if (isNull(n->down) && isNull(n->next))
    {
        return n;
    }
    else if (isNull(n->down) && !isNull(n->next))
    {
        return tree_flatten_helper(n->next);
    }
    else if (!isNull(n->down) && isNull(n->next))
    {
        Node *flattened_down_end = tree_flatten_helper(n->down);
        n->next = n->down;
        n->down = NULL;
        return flattened_down_end;
    }
    else
    {
        Node *previous_next = n->next;
        Node *flattened_down_end = tree_flatten_helper(n->down);
        n->next = n->down;
        n->down = NULL;
        flattened_down_end->next = previous_next;

        return tree_flatten_helper(previous_next);
    }

}

void tree_flatten(Node *n)
{
    tree_flatten_helper(n);
}

}

int main()
{
	treeflattening::Node A('A'), B('B'), C('C'), D('D'), E('E'), F('F'), G('G'), H('H'), I('I'), J('J');
	A.next = &B;
	B.down = &C;
	B.next = &G;
	C.next = &F;
	C.down = &D;
	D.next = &E;
	G.next = &H;
	H.down = &I;
	I.next = &J;

	treeflattening::tree_flatten(&A);

	treeflattening::Node *n = &A;
	while (false == treeflattening::isNull(n))
	{
		ASSERT(n->down == NULL);
		std::cout << n->value << " ";
		n = n->next;
	}


	std::getchar();
	return 0;
}
