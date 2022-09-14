#include"test_llfifo.h"

void test_llfifo(){

    //FIFO 1 - Element Enqueue Dequeue Testcases
    llfifo_t *my_fifo = llfifo_create(5);
    assert (llfifo_length(my_fifo) == 0);
    assert (llfifo_capacity(my_fifo) == 5);
    char a[] = "abcde";
    llfifo_enqueue(my_fifo, &a[0]);   // does not result in a malloc (len = 1, cap = 5)
    llfifo_enqueue(my_fifo, &a[1]);   // does not result in a malloc (len = 2, cap = 5)
    llfifo_enqueue(my_fifo, &a[2]);   // does not result in a malloc (len = 3, cap = 5)
    llfifo_enqueue(my_fifo, &a[3]);    // does not result in a malloc (len = 4, cap = 5)
    llfifo_enqueue(my_fifo, &a[4]);  // does not result in a malloc (len = 5, cap = 5)
    char *b = (char *)llfifo_dequeue(my_fifo);  //  len = 4, cap = 5
    assert(*b == 'e');
    b = (char *)llfifo_dequeue(my_fifo);//  cap = 4, len = 4
    assert(*b == 'd');
    b = (char *)llfifo_dequeue(my_fifo);//  cap = 4, len = 3
    assert(*b == 'c');
    b = (char *)llfifo_dequeue(my_fifo);//  cap = 4, len = 2
    assert(*b == 'b');
    b = (char *)llfifo_dequeue(my_fifo);//  cap = 4, len = 1
    assert(*b == 'a');
    b = (char *)llfifo_dequeue(my_fifo);//  cap = 4, len = 0
    assert(b == NULL);
    free(my_fifo);

    //FIFO 2 Length and capacity testcases
    llfifo_t *my_fifo1 = llfifo_create(3);
    int arr[5] = {3,4,5,6,7};
    assert(llfifo_length(my_fifo1)==0);
    llfifo_enqueue(my_fifo1, &arr[0]);   // does not result in a malloc (len = 1, cap = 3)
    assert(llfifo_length(my_fifo1)==1);
    llfifo_enqueue(my_fifo1, &arr[1]);   // does not result in a malloc (len = 2, cap = 3)
    assert(llfifo_length(my_fifo1)==2);
    llfifo_enqueue(my_fifo1, &arr[2]);   // does not result in a malloc (len = 3, cap = 3)
    assert(llfifo_length(my_fifo1)==3);
    llfifo_enqueue(my_fifo1, &arr[3]);    // does4 result in a malloc (len = 4, cap = 4)   
    assert(llfifo_length(my_fifo1)==4);
    assert(llfifo_capacity(my_fifo1)==4);
    llfifo_enqueue(my_fifo1, &arr[4]);   // does4 result in a malloc (len = 5, cap = 5)   
    free(my_fifo1);


    //FIFO 3 Example testcases
    llfifo_t *my_fifo2 = llfifo_create(5);
    assert (llfifo_length(my_fifo2) == 0);
    assert (llfifo_capacity(my_fifo2) == 5);
    llfifo_enqueue(my_fifo2, "Sleepy");   // does not result in a malloc (len = 1, cap = 5)
    llfifo_enqueue(my_fifo2, "Grumpy");   // does not result in a malloc (len = 2, cap = 5)
    llfifo_enqueue(my_fifo2, "Sneezy");   // does not result in a malloc (len = 3, cap = 5)
    llfifo_enqueue(my_fifo2, "Happy");    // does not result in a malloc (len = 4, cap = 5)
    llfifo_enqueue(my_fifo2, "Bashful");  // does not result in a malloc (len = 5, cap = 5)
    llfifo_dequeue(my_fifo2);             // removes "Sleepy"; len = 4, cap = 5
    llfifo_enqueue(my_fifo2, "Dopey");    // does not result in a malloc (len = 5, cap = 5)
    llfifo_enqueue(my_fifo2, "Doc");    
    free(my_fifo2);

    //FIFO4 nullcheck 
    llfifo_t *my_fifo3 = llfifo_create(5);
    int *p = NULL;
    assert(llfifo_enqueue(my_fifo3,p)==-1);
    free(my_fifo3);

    //FIFO5
    llfifo_t *my_fifo4 = llfifo_create(-1);
    assert (llfifo_length(my_fifo4) == 0);
    assert (llfifo_capacity(my_fifo4) == 0);
    int marr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    llfifo_enqueue(my_fifo4, &marr[0]);   // does  result in a malloc (len = 1, cap = 1)
    llfifo_enqueue(my_fifo4, &marr[1]);   // does  result in a malloc (len = 2, cap = 2)
    llfifo_enqueue(my_fifo4, &marr[2]);   // does  result in a malloc (len = 3, cap =3)
    int* ptr;
    for(int j=2;j>=0;j--){
        ptr = (int *)llfifo_dequeue(my_fifo4); 
        for(int i=0;i<3;i++) 
    
        assert(*(ptr+i)==marr[j][i]);
        }
}
