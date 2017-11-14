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
	print n;
	x = 6+5*5%4+4;
	print x , sum , max;
	println "end";
}