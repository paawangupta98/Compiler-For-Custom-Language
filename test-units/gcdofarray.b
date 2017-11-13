declblock{
	int i , temp , gcd ,  j , a ,b,n;
	int ar[100000];	
}

codeblock{
	read n;
	for i=1,n
	{
		read ar[i];
	}
	gcd = ar[1];
	for i=2,n
	{
		a = ar[i];
		b = gcd;
		while(a!=0)
		{
			temp = a;
			a = b%a;
			b = temp;
		}
		gcd = b;
	}
	println "GCD = " , gcd;
}