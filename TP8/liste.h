


typedef struct cell_s {
    char key[30];
    int  value;
    struct cell_s * nk, *nv;
} cell_t;

typedef struct list_s {
    cell_t * key;
    cell_t * value;
} list_t;
