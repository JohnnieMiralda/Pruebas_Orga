void do_delay()
{
    for (volatile int i = 0; i < 10000; i++) {}    
}

int main() 
{

    volatile unsigned short *p = (unsigned short *)0xb800;
    volatile unsigned short info= 0xcf00 | 'O';
    volatile unsigned short info2= 0x0000 | ' ';
    int ant=0;
    for (int i = 0; i <=29; i++)
    {
        do_delay();
        *(p+(80*i)+i)= info;
        if(i!=0){
            *(p+(ant))= info2;
        }
        ant=(80*i)+i;
    }
    
    return 0;
}
