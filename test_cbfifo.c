#include"test_cbfifo.h"

void test_cbfifo(){
    // //FIFO 1 - Enqueue and Dequeue Operations
    char a[] = "abcdef";
    char b;
    assert(cbfifo_enqueue(&a[0],1) == 1);  //length = 1 capacity = 256
    assert(cbfifo_enqueue(&a[1],1) == 1);  //length = 2 capacity = 256
    assert(cbfifo_enqueue(&a[2],1) == 1);  //length = 3 capacity = 256
    assert(cbfifo_enqueue(&a[3],1) == 1);  //length = 4 capacity = 256
    assert(cbfifo_enqueue(&a[4],1) == 1);  //length = 5 capacity = 256
    assert(cbfifo_enqueue(&a[5],1) == 1);  //length = 6 capacity = 256
    assert(cbfifo_dequeue(&b,1) == 1); //length = 5 capacity = 256
    assert(b == 'f');
    assert(cbfifo_dequeue(&b,1) == 1); //length = 4 capacity = 256
    assert(b == 'e');
    assert(cbfifo_dequeue(&b,1) == 1); //length = 3 capacity = 256
    assert(b == 'd');
    assert(cbfifo_dequeue(&b,1) == 1); //length = 2 capacity = 256
    assert(b == 'c');
    assert(cbfifo_dequeue(&b,1) == 1); //length = 1 capacity = 256
    assert(b == 'b');
    assert(cbfifo_dequeue(&b,1) == 1); //length = 0 capacity = 256
    assert(b == 'a');

    //FIFO2 int queue
    int c[] = {1,2,3,4,5,6};
    int d;
    assert(cbfifo_enqueue(&c[0],4) == 4);//length = 4 capacity = 256
    assert(cbfifo_enqueue(&c[1],4) == 4);//length = 8 capacity = 256
    assert(cbfifo_enqueue(&c[2],4) == 4);//length = 12 capacity = 256
    assert(cbfifo_enqueue(&c[3],4) == 4);//length = 16 capacity = 256
    assert(cbfifo_enqueue(&c[4],4) == 4);//length = 20 capacity = 256
    assert(cbfifo_enqueue(&c[5],4) == 4);//length = 24 capacity = 256
    assert(cbfifo_dequeue(&d,4) == 4); //length = 24 capacity = 256
    assert(d == 6);
    assert(cbfifo_dequeue(&d,4) == 4); //length =20 capacity = 256
    assert(d == 5);
    assert(cbfifo_dequeue(&d,4) == 4); //length = 16 capacity = 256
    assert(d == 4);
    assert(cbfifo_dequeue(&d,4) == 4); //length = 12 capacity = 256
    assert(d == 3);
    assert(cbfifo_dequeue(&d,4) == 4); //length = 8 capacity = 256
    assert(d == 2);
    assert(cbfifo_dequeue(&d,4) == 4); //length = 4 capacity = 256
    assert(d == 1);
    assert(cbfifo_dequeue(&d,4) == 0); //length = 0 capacity = 256

    //FIFO3
    char array[128] = {[0 ... 127] = 'a'};
    char ele;
    for(int i=0;i<=127;i++){
        assert(cbfifo_enqueue((array+i),1) == 1);
    }
    for(int i=0;i<=127;i++){
        assert(cbfifo_dequeue(&ele,1) == 1);
        assert(ele == 'a');
    
    }
    assert(cbfifo_dequeue(&ele,1) == 0);

    //FIFO4
    int num = 10;
    assert(cbfifo_enqueue(&num,4) == 4);
    assert(cbfifo_enqueue(&num,4) == 4);
    assert(cbfifo_enqueue(&num,4) == 4);
    int num1;
    for(int i=0;i<8;i++)
    assert(cbfifo_dequeue(&num,1)==1);
    assert(cbfifo_dequeue(&num,4)==4);
    assert(num==10);

    
}
