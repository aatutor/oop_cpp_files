class Empty {
	Empty();	// ctor
	~Empty();	// dtor
	Empty(Empty& ptr);// copy ctor
	Empty& operator= (const Empty& ptr); 
												// copy optor
	...
}
{
	Empty x; // 1
	Empty y(x); // 2
	x = y; // 3
}	 // 4
{
	Empty x; // ctor
	Empty y(x); // copy ctor
	x = y; // copy optor
}	'auto-delete x, y' // dtor
