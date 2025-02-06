#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct node {
   char *str;
   int nb;
   struct node * parent, * left, * right;
} node_t;

#define DEBUG false

void tree_render_node( node_t * node ) {
	if ( ! node )
		return;
	tree_render_node ( node->left );
	printf("* %20s   / ", node->str );
	if ( node->parent ) {
		printf("parent = %s, ", node->parent->str );
	}
	if ( node->left ) {
		printf("left = %s, ", node->left->str );
	}
	if ( node->right ) {
		printf("right = %s, ", node->right->str );
	}
	printf("\n");
	tree_render_node ( node->right );
}

void tree_render( node_t * tree ) {
	printf("Tree:\n");
	tree_render_node( tree );
	printf("\n");
}

int tree_depth( node_t * node ) {
	if ( node )
		return 1 + max( tree_depth( node->left ), tree_depth( node->right ) );
	else
		return 0;
}

int tree_balance_factor( node_t * node ) {
	int left = tree_depth( node->left );
	int right = tree_depth( node->right );
	int balance = left - right;
	//printf("%p (%s) / left = %d (%s), right = %d (%s) / balance = %d\n", node, node->str, left, node->left ? node->left->str : NULL, right, node->right ? node->right->str : NULL, balance );
	return balance;
}

void tree_rotate_left( node_t ** node ) {
	node_t * top = *node;
	node_t * right = top->right;
	node_t * x = right->left;

	if ( DEBUG ) printf("Rotating left on %s...\n", (*node)->str);

	*node = right;
	top->right = right->left;
	right->left = top;

	if ( x )
		x->parent = top;

	right->parent = top->parent;
	top->parent = right;
}

void tree_rotate_right( node_t ** node ) {
	node_t * top = *node;
	node_t * left = top->left;
	node_t * x = left->right;

	if ( DEBUG ) printf("Rotating right on %s...\n", (*node)->str);

	*node = left;
	top->left = left->right;
	left->right = top;

	if ( x )
		x->parent = top;
	
	left->parent = top->parent;
	top->parent = left;

	
}

void tree_balance( node_t ** node ) {
	int bf = tree_balance_factor( *node );
	if ( bf == 2 ) {
		if( tree_balance_factor( (*node)->left ) == -1 ) {
			tree_rotate_left( & (*node)->left );
		}
		tree_rotate_right( node );
	}
	else if ( bf == -2 ) {
		if( tree_balance_factor( (*node)->right ) == 1 ) {
			tree_rotate_right( & (*node)->right );
		}
		tree_rotate_left( node );		
	}
}

bool tree_insert( node_t ** target, node_t * node ) {

	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;

	node_t ** ancestor = target;

	if ( ! * target ) {
		*target = node;
		return true;
	}
	else {
		target = strcmp( (*target)->str, node->str ) < 0 ? & (*target)->right : & (*target)->left;
		if ( tree_insert( target, node ) ) {
			node->parent = *ancestor;
		}
		tree_balance( ancestor );
		return false;
	}
}

node_t * tree_search( node_t * branch, char * str, int * depth ) {
	*depth = 0;
	while( branch ) {
		int c = strcmp( branch->str, str );
		if ( c < 0 ) {
			branch = branch->right;
		} else if ( c > 0 ) {
			branch = branch->left;
		} else {
			break;
		}
		*depth += 1;
	}
	return branch;
}

node_t * get_next_node( node_t * node ) {
	if ( node->right ) {
		node = node->right;
		while( node->left ) {
			node = node->left;
		}
		return node;
	} else {
		node_t * parent = node->parent;
		while( parent ) {
			if ( strcmp(parent->str, node->str) > 0 )
				return parent;
			parent = parent->parent;
		}
		return parent;
	}
}


void tree_search_render( node_t * branch, char * str ) {
	int depth;
	node_t * node = tree_search( branch , str, & depth );
	printf("Searching \"%s\" : ", str );	
	if ( node ) {
		printf(" str=\"%s\", nb = %d", node->str, node->nb );
	}
	else {
		printf("NOT FOUND");
	}
	printf(", depth = %d", depth );
	printf("\n");
}

int tree_max_depth( node_t * node ) {
	if ( ! node )
		return 0;

	return max( tree_max_depth( node->right ), tree_max_depth( node->left ) ) + 1;
}

int main() {
	char * names [] = { "Florent",  "Louis", "Marie", "Charles", "Mathilde", "Lucie", "Fabienne", "Jean", "Patrick", "Nicolas", "Bernard", "Jacqueline", "Helene", "Guillaume", "Anam", "Jules", "Jeanne", "Elton", "Michael", "Jean-Paul", "Matthieu", "Trung", "Zhen", "Aline", "Anouk", "Adrien", "Alfred", "Sylvain", "Basile", "Constance", "A", "B", "C", "D", "E", "F", "G", "H", "I", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
	int nb = sizeof(names)/sizeof(char *);
	node_t nodes[nb];

	node_t * tree = NULL;

	{
   		int i;
		for( i = 0; i < nb; i++ ) {
			node_t * node = & nodes[i];
			node->str = names[i];
                        node->nb = i;

			if ( DEBUG ) printf("Inserting \"%s\" : %p\n", node->str, node );
			tree_insert( & tree, node );
		}
	}

	printf("Depth: %d\n", tree_max_depth( tree ) );

	tree_render( tree );
	{
		tree_search_render(tree, "Jerome");
		tree_search_render(tree, "Charles");
	}

	{
		int depth;
		node_t * n = tree_search( tree, "Bernard", & depth );
		while( n ) {
			printf("* %s\n", n->str);
			n = get_next_node( n );
		}
	}

	return 0;
}
