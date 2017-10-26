declblock{
	int x0;
	int ar[102],yar;
	int max;
	int sum,x;
	int n;
	int i;
}

codeblock{
	println "thisihs";
	max=0;
	sum=0;
	read n;
	for i = 1 , n  { 
		read ar[i];
		if(max<ar[i])
		{
			max = ar[i];
		}
	}
	i=1;
	while(i<=n)
	{
		sum = sum + ar[i];
		i = i+1;
	}
	x = 6+5*5%4+4;
	print x , sum , max;
	println "end";
}