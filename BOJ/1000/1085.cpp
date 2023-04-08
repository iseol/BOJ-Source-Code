#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int x, y;
	int w, h;
	
	cin >> x >> y >> w >> h;
	int arr[4] = {w-x, h-y, x, y};
	
	int ans = *min_element(arr, arr+4);
	cout << ans << '\n';
}
