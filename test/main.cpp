#include <Windows.h>
#include <vector>
using namespace std;
int main()
{
	vector<int> vlst = { 1,2,3,4,5 };
	int n = vlst.capacity();
	vlst.resize(10);
	n = vlst.size();
	n = vlst.capacity();
	return 0;
}