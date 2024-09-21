#include "whatever.hpp"


int	main()
{
	int x = 10;
	int y = 20;
	cout << "max : " << ::max(x, y) << endl;
	cout << "min : " << ::min(x, y) << endl;
	::swap(x, y);
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;
	cout << "===============" << endl;
	char x2 = 'x';
	char y2 = 'y';
	cout << "max : " << ::max(x2, y2) << endl;
	cout << "min : " << ::min(x2, y2) << endl;
	::swap(x2, y2);
	cout << "x2 : " << x2 << endl;
	cout << "y2 : " << y2 << endl;
	return 0;
}
