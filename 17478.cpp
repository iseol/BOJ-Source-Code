#include <iostream>
using namespace std;

int n;

void sol(int k) {
	int intend = n-k;
	string intendstr;
	for (int i = 0; i < intend; i++) {
		intendstr += "____";
	}
	if (k == 0) {
		cout  << intendstr << "\"����Լ��� ������?\"\n";
		cout << intendstr << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << intendstr << "��� �亯�Ͽ���.\n";
		return;
	}
	
	cout << intendstr << "\"����Լ��� ������?\"\n";
	cout << intendstr << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	cout << intendstr << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	cout << intendstr << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	sol(k-1);
	cout << intendstr << "��� �亯�Ͽ���.\n";
}

int main() {
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	cin >> n;
	sol(n);
}
