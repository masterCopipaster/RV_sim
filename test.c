int fib(int);

int main()
{
	return fib(0xff);
}

int fib(int i)
{
        return i > 1 ? fib(i - 1) + fib(i - 2) : 1;
}


