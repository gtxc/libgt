/*
 * Created by gt on 11/25/21 - 12:47 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct ll_node_ {
    int i_;
    int d_;
    struct ll_node_ *p_;
};

static int index_ = 0;

/** Edits the node elements.*/
_Bool edit_node(struct ll_node_ *list, int index, int data, struct ll_node_ *ptr) {
    if (list) {
        (list)->i_ = index;
        (list)->d_ = data;
        (list)->p_ = ptr;
        return 1;
    }
    return 0;
}

/** Adds an element at the end of the list.*/
_Bool add_end(struct ll_node_ **list, int e) {
    if (!(*list)){
        *list = malloc(sizeof(struct ll_node_));
        edit_node(*list, index_++, e, NULL);
        return 1;
    }
    if (*list) {
        struct ll_node_ *tmp = *list;
        while (tmp->p_) {
            tmp = tmp->p_;
        }
        tmp->p_ = malloc(sizeof(struct ll_node_));
        edit_node(tmp->p_, index_++, e, NULL);
        return 1;
    }
    return 0;
}

/** Adds an element at the beginning of the list.*/
_Bool add_beginning(struct ll_node_ **list, int e) {
    if (!(*list)) {
        *list = malloc(sizeof (struct ll_node_));
        edit_node(*list, index_++, e, NULL);
        return 1;
    }
    if (*list) {
        struct ll_node_ *tmp = *list;
        while (tmp) {
            ++(tmp->i_);
            tmp = tmp->p_;
        }
        tmp = malloc(sizeof (struct ll_node_));
        edit_node(tmp, 1, (*list)->d_, (*list)->p_);
        edit_node(*list, 0, e, tmp);
        ++index_;
        return 1;
    }
    return 0;
}

/** Adds one or more elements at the end of the list.
 *  Input the number of element first will pass.*/
_Bool add_all_end(struct ll_node_ **list, int nitems, ...) {
    va_list args;
    va_start(args, nitems);
    if(!(*list)) {
        *list = malloc(sizeof (struct ll_node_));
        struct ll_node_ *head = *list;
        int arg = va_arg(args, int);
        edit_node(head, index_++, arg, NULL);
        for (int i = 0; i < nitems - 1; ++i) {
            arg = va_arg(args, int);
            struct ll_node_ *tmp = malloc(sizeof (struct ll_node_));
            head->p_ = tmp;
            head = head->p_;
            edit_node(tmp, index_++, arg, NULL);
        }
    }
    if (*list) {
        struct ll_node_ *head = *list;
        while (head->p_) {
            head = head->p_;
        }
        for (int i = 0; i < nitems; ++i) {
            int arg = va_arg(args, int);
            struct ll_node_ *tmp = malloc(sizeof (struct ll_node_));
            head->p_ = tmp;
            head = head->p_;
            edit_node(tmp, index_++, arg, NULL);
        }
        return 1;
    }
    va_end(args);
    return 0;
}

/** Adds the element at the specified position in the list.*/
_Bool add_index(struct ll_node_ **list, int index, int e) {
    if (index > index_) {
        fprintf(stderr, "Index out of bounds. Value cannot be inserted.\n");
        exit(EXIT_FAILURE);
    }
    if (!(*list)) {
        *list = malloc(sizeof (struct ll_node_));
        edit_node(*list, index_, e, NULL);
        return 1;
    }
    if (*list) {
        if (index == index_) {
            add_end(list, e);
            return 1;
        } else if (index == 0) {
            add_beginning(list, e);
            return 1;
        } else {
            struct ll_node_ *cur = *list;
            struct ll_node_ *next = cur->p_;
            while (cur) {
                if (cur->i_ == index - 1) {
                    break;
                }
                cur = cur->p_;
                next = cur->p_;
            }
            struct ll_node_ *tmp = malloc(sizeof (struct ll_node_));
            edit_node(tmp, index, e, next);
            cur->p_ = tmp;
            while (next) {
                ++(next->i_);
                next = next->p_;
            }
            ++index_;
            return 1;
        }
    }
    return 0;
}

/** Removes the element at the end of the list.*/
_Bool remove_end(struct ll_node_ **list) {
    if ((*list)->p_ == NULL) {
        free(*list);
        *list = NULL;
        --index_;
        return 1;
    }
    if ((*list)->p_) {
        struct ll_node_ *end = (*list)->p_;
        struct ll_node_ *tmp = *list;
        while (end->p_) {
            end = end->p_;
            tmp = tmp->p_;
        }
        tmp->p_ = NULL;
        free(end);
        end = NULL;
        --index_;
        return 1;
    }
    return 0;
}

/** Removes the element at the beginning of the list.*/
_Bool remove_beginning(struct ll_node_ **list) {
    if (*list) {
        struct ll_node_ *tmp = *list;
        while (tmp) {
            --(tmp->i_);
            tmp = tmp->p_;
        }
        tmp = *list;
        *list = (*list)->p_;
        free(tmp);
        tmp = NULL;
        --index_;
        return 1;
    }
    return 0;
}

/** Removes all elements from the list.
 *  Frees all the memory allocated by the list.*/
_Bool remove_all(struct ll_node_ **list) {
    if (*list) {
        struct ll_node_ *tmp;
        while (*list) {
            tmp = *list;
            *list = (*list)->p_;
            free(tmp);
            tmp = NULL;
        }
        index_ = 0;
        return 1;
    }
    return 0;
}

/** Removes the element at the specified position in the list.*/
_Bool remove_index(struct ll_node_ **list, int index) {
    if (index > index_ - 1) {
        fprintf(stderr, "Index out of bounds. There is no %i. indexed element.\n", index);
        exit(EXIT_FAILURE);
    }
    if (*list) {
        if (!(*list)->p_) {
            free(*list);
            *list = NULL;
            --index_;
            return 1;
        } else if (index == 0) {
            struct ll_node_ *tmp = *list;
            while (tmp) {
                --(tmp->i_);
                tmp = tmp->p_;
            }
            tmp = *list;
            *list = (*list)->p_;
            free(tmp);
            tmp = NULL;
            --index_;
            return 1;
        } else if (index == index_ - 1) {
            struct ll_node_ *end = (*list)->p_;
            struct ll_node_ *tmp = *list;
            while (end->p_) {
                end = end->p_;
                tmp = tmp->p_;
            }
            tmp->p_ = NULL;
            free(end);
            end = NULL;
            --index_;
            return 1;
        } else {
            struct ll_node_ *cur = *list;
            struct ll_node_ *prev = NULL;
            while (cur) {
                if (cur->i_ == index) {
                    break;
                }
                prev = cur;
                cur = cur->p_;
            }
            struct ll_node_ *tmp = cur;
            while (tmp) {
                --(tmp->i_);
                tmp = tmp->p_;
            }
            prev->p_ = cur->p_;
            free(cur);
            cur = NULL;
            --index_;
            return 1;
        }
    }
    return 0;
}

/** Checks whether the list contains the given value.*/
_Bool contains(struct ll_node_ *list, int e) {
    if (list) {
        while (list) {
            if (list->d_ == e) {
                return 1;
            }
            list = list->p_;
        }
    }
    return 0;
}

/** Returns the value of the element for the given index.*/
int get(struct ll_node_ *list, int index) {
    if (index > index_) {
        fprintf(stderr, "Index out of bounds. There is no %i. indexed element.\n", index);
        exit(EXIT_FAILURE);
    }
    if (list) {
        while (list) {
            if (list->i_ == index) {
                return list->d_;
            }
            list = list->p_;
        }
    }
    fprintf(stderr, "The list is empty.");
    exit(EXIT_FAILURE);
}

/** Returns the index of the first occurrence of the element for the given value.*/
int index_of(struct ll_node_ *list, int e) {
    if (list) {
        while (list) {
            if (list->d_ == e) {
                return list->i_;
            }
            list = list->p_;
        }
    }
    fprintf(stderr, "The list is empty OR the value is not found.");
    exit(EXIT_FAILURE);
}

/** Checks whether the list is empty.*/
_Bool is_empty(struct ll_node_ *list) {
    return list == NULL ? 1 : 0;
}

/** Replaces the element at the specified position in the list with the specified value.*/
_Bool set(struct ll_node_ *list, int index, int e) {
    if (list) {
        while (list) {
            if (list->i_ == index) {
                list->d_ = e;
                return 1;
            }
            list = list->p_;
        }
    }
    return 0;
}

/** Returns the number of elements in the list.*/
int list_size(struct ll_node_ *list) {
    int size = 0;
    while (list) {
        list = list->p_;
        ++size;
    }
    return size;
}


/** Prints the list content as (index, data)-->(...).*/
void print_linked_list(struct ll_node_ *list) {
    if (list) {
        while (list) {
            printf("(i:%i, v:%i)-->", list->i_, list->d_);
            list = list->p_;
        }
        printf("(NULL)\n");
        return;
    }
    fprintf(stderr, "The linked list is empty.");
}

int main() {
    struct ll_node_ *linked_list = NULL;
    add_all_end(&linked_list, 6, 0, 11, 22, 33, 44, 55);
    print_linked_list(linked_list);
    add_index(&linked_list, 1, 1234);
    printf("index: %i\n", index_);
    remove_all(&linked_list);
    return 0;
}