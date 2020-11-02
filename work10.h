struct node
{
    int id;
    char name[200];
    struct node *next;
};

void print_list(struct node *Bob);

struct node *create_node(int i, char n[200]);

struct node *free_node(struct node *current);

struct node *insert_front(struct node *current, int num, char *n);

struct node *free_list(struct node *current);

struct node *remove_node(struct node *front, int data, char *n);