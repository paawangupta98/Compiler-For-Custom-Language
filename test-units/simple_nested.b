declblock{
	int x0,yar;
	int zarray[102],tarrya;
	int i,t;
	int sum,n;
}

codeblock{
	x0=6;
	yar=7+x0-8*78;
	zarray[6]=7;
	x0 = zarray[6] + 1;
	read zarray[5];
	print zarray[5];

	x0=5;
	read n;
	for i=1,1,n {
		read t;
		if(sum<20)
		{
			sum = sum  + t;
		}
		println sum;
	}
	print "New Sum =" , sum ;
}