/*
 * cbfifo.c - a fixed-size FIFO implemented via a circular buffer
 */

#include"cbfifo.h"
#include"stdio.h"


#define noOfBytes 128
int length = 0, capacity = 128;
unsigned char cbfifo[noOfBytes];

/*
 * Enqueues data onto the FIFO, up to the limit of the available FIFO
 * capacity.
 *
 * Parameters:
 *   buf      Pointer to the data
 *   nbyte    Max number of bytes to enqueue
 * 
 * Returns:
 *   The number of bytes actually enqueued, which could be 0. In case
 * of an error, returns (size_t) -1.
 */

size_t cbfifo_enqueue(void *buf, size_t nbyte){
    
    int bytesToEnqueue = capacity-length>nbyte ? nbyte: capacity-length;
    for(int i=0;i<bytesToEnqueue;i++) 
        *(cbfifo+i+length) = *((unsigned char *)buf+i);

    length+=bytesToEnqueue;
    return bytesToEnqueue>0? bytesToEnqueue : 0;
}


/*
 * Attempts to remove ("dequeue") up to nbyte bytes of data from the
 * FIFO. Removed data will be copied into the buffer pointed to by buf.
 *
 * Parameters:
 *   buf      Destination for the dequeued data
 *   nbyte    Bytes of data requested
 * 
 * Returns:
 *   The number of bytes actually copied, which will be between 0 and
 * nbyte. 
 * 
 * To further explain the behavior: If the FIFO's current length is 24
 * bytes, and the caller requests 30 bytes, cbfifo_dequeue should
 * return the 24 bytes it has, and the new FIFO length will be 0. If
 * the FIFO is empty (current length is 0 bytes), a request to dequeue
 * any number of bytes will result in a return of 0 from
 * cbfifo_dequeue.
 */

size_t cbfifo_dequeue(void *buf, size_t nbyte){
    
    if (length==0){   
        buf = NULL;
        return 0;
    }
    int remBytes = length-nbyte;
    int bytes = remBytes>=0? nbyte:remBytes;
    length = length-bytes;
    for(int i=0;i<bytes;i++) 
        *((char *)buf+i) = *(cbfifo+length+i);
    return bytes;

}

/*
 * Returns the number of bytes currently on the FIFO. 
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   Number of bytes currently available to be dequeued from the FIFO
 */

size_t cbfifo_length(){
    return length;
}

/*
 * Returns the FIFO's capacity
 *
 * Parameters:
 *   none
 * 
 * Returns:
 *   The capacity, in bytes, for the FIFO
 */

size_t cbfifo_capacity(){
    return capacity;    
}

void cbfifo_dump_state(){
    printf("Capacity: %d, Length: %d\n",capacity,length);
}

