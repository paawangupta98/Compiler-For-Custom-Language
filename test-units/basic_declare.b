declblock{
	int x0;
	int ar[102],yar;
	int max;
	int sum,x;
	int n;
	int i;
}

codeblock{
L1:	println "thisihs";
	max=0;
	sum=0;
	read n;
L2:	goto L1 if n==0;
	for i = 1 , n  { 
		read ar[i];
		if(max<ar[i])
		{
			max = ar[i];
		}
		goto L2;
	}
	i=1;
	while(i<=n)
	{
	L3:	sum = sum + ar[i];
		goto L3 if sum<10;
		i = i+1;
	}
	x = 6+5*5%4+4;
	print x , sum , max;
	println "end";
}