# PES-Assignment-2 WAYS OF IMPLEMENTING FIFO.

A FIFO object—often called a queue instead—is intended to connect some code which produces data 
with some code which consumes data. This design pattern is relatively widespread; it is commonly used 
when producer and consumer threads run asynchronously with respect to each other.

## A fixed size FIFO implemented via Circular Buffer: 

The cbfifo implementation will be statically allocated, with a size of 128 bytes.
Performs four major functions:

1. cbfifo_enqueue:
Enqueues data onto the FIFO, up to the limit of the available FIFO capacity.
2. cbfifo_dequeue:
Dequeues upto nbyte of data from the FIFO.
3. cbfifo_length:
Returns the number of bytes currently on the FIFO. 
4. cbfifo_capacity:
Returns the FIFO's capacity.

## A dynamically growing FIFO implemented via Linked Lists:

The llfifo implementation will be capable of growing dynamically through an efficient use of malloc().
Performs six major functions:

1. llfifo_create:
Creates and initializes the FIFO.
2. llfifo_enqueue:
Enqueues an element onto the FIFO, growing the FIFO by adding elements, if necessary.
3. llfifo_dequeue:
Removes ("dequeues") an element from the FIFO, and returns it.
4. llfifo_length:
Returns the number of elements currently on the FIFO.
5. llfifo_capacity:
Returns the FIFO's current capacity.
6. llfifo_destroy:
Teardown function: Frees all dynamically allocated memory. 


