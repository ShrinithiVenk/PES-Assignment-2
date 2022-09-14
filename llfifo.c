/*
 * llfifo.c - a dynamically-growing FIFO
 */

#include"llfifo.h"
#include"stdlib.h"
#include"stdio.h"


/* 
 * The llfifo's main data structure. 
 *
 * Defined here as an incomplete type, in order to hide the
 * implementation from the user. You will need to define this struct
 * in your .c file.
 */

struct llfifo_s{
    int capacity;
    int length;
    void **ptr;
    };

/*
 * Creates and initializes the FIFO
 *
 * Parameters:
 *   capacity  the initial size of the fifo, in number of elements. 
 *             Valid values are in the range of 0 to the limits of memory
 * 
 * Returns: A pointer to a newly-created llfifo_t instance, or NULL in
 *   case of an error.
 */

llfifo_t *llfifo_create(int capacity){
    struct llfifo_s *llfifo = (llfifo_t *)malloc(sizeof(llfifo_t));
    llfifo->capacity = capacity>0 ? capacity: 0;
    llfifo->length=-1;
    void * p;
    llfifo->ptr = (void **)malloc(capacity*sizeof(*p));
    return llfifo;  
}   

/*
 * Enqueues an element onto the FIFO, growing the FIFO by adding
 *       elements, if necessary
 *
 * Parameters:
 *   fifo    The fifo in question
 *   element The element to enqueue, which cannot be NULL
 * 
 * Returns:
 *   The new length of the FIFO on success, -1 on failure. It is an error to attempt 
 * to enqueue the NULL pointer.
 */

int llfifo_enqueue(llfifo_t *fifo, void *element){

    //null check should be added
    if(element == NULL) 
        return -1;
    void * p;
    fifo->length++;
    //length is less than capacity
    if(fifo->length < fifo->capacity){
        void ** ptr = fifo->ptr+(fifo->length);
        *ptr = element;
        }

    //length is equal to capacity
    else{
        fifo->capacity++;
        fifo->ptr = (void **)realloc(fifo->ptr,fifo->capacity*sizeof(*p));
        void** ptr = fifo->ptr+(fifo->length);
        *ptr = element;
    }

    return fifo->length;
}

/*
 * Removes ("dequeues") an element from the FIFO, and returns it
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The dequeued element, or NULL if the FIFO was empty
 */

void *llfifo_dequeue(llfifo_t *fifo){
    if(fifo->length == -1) 
        return NULL;
    void **dequeue_element = fifo->ptr+(fifo->length);
    fifo->length--;
    return *dequeue_element;
}

/*
 * Returns the number of elements currently on the FIFO. 
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The number of elements currently on the FIFO
 */

int llfifo_length( llfifo_t *fifo){
    return fifo->length+1;
}

/*
 * Returns the FIFO's current capacity
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns:
 *   The current capacity, in number of elements, for the FIFO
 */

int llfifo_capacity( llfifo_t *fifo){
    return fifo->capacity;
}

/*
 * Teardown function: Frees all dynamically allocated
 * memory. After calling this function, the fifo should not be used
 * again!
 *
 * Parameters:
 *   fifo  The fifo in question
 * 
 * Returns: none
 */

void llfifo_destroy( llfifo_t *fifo){
     free(fifo->ptr);
     free(fifo);
     fifo = NULL;
}


void llfifo_dump_state(llfifo_t *fifo){
    printf("Capacity: %d, Length: %d\n",fifo->capacity,fifo->length+1);
    printf("Elements: ");
    for(int i=0;i<=fifo->length;i++)
        printf("%c ",*(char *)(*(fifo->ptr+i)));
    printf("\n");

}
