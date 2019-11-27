int fib(int);
int factoreal(int);

//int vals[1000000]; 

int main()
{
    //for(int i = 0; i < 100000; i++) vals[i] = i;    
    return fib(21);
}

int factoreal(int i)
{
    return i ? factoreal(i - 1) * i : 1;
}

int fib(int i)
{
        return i > 1 ? fib(i - 1) + fib(i - 2) : 1;
}


void _start(){ main(); }
