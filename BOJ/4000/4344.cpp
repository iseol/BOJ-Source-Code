#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        double sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        double cnt = 0;
        double average = sum / n;
        for (int i = 0; i < n; i++) {
            if (arr[i] > average) cnt++;
        }
        
        double percentage = cnt / n * 100;
        cout.precision(3);
        cout << fixed;
        cout << percentage << "%\n";
    }
}