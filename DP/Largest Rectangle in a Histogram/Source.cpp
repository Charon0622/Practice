#include<iostream>
using namespace std;

long long int h[100005], l[100005], r[100005];
long long int n, max;

void dp() {

	l[0] = 1;
	r[n - 1] = 1;
	int j;

	//����ʼ����
	for (int i = 1; i < n; ++i) {
		l[i] = 1;
		//��ǰһ�����Լ���, ���Լ���ʼ��
		//��ǰһ�����Լ���, ����ǰ�����������ǰһ��, ������ǰһ����бȽ�
		if (h[i] <= h[i - 1]) {
			j = i - 1;
			while (j >= 0 && h[i] <= h[j]) {
				l[i] += l[j];
				j -= l[j];
			}
		}
	}

	//���ҿ�ʼ����
	for (int i = n - 2; i >= 0; --i) {
		r[i] = 1;
		if (h[i] <= h[i + 1]) {
			j = i + 1;
			while (j < n && h[i] <= h[j]) {
				r[i] += r[j];
				j += r[j];
			}
		}
	}

	long long int sum;
	max = 0;
	for (int i = 0; i < n; ++i) {
		//�ܳ��� = �� + �� - 1
		//��� = �ܳ��� * ��
		sum = (r[i] + l[i] - 1)*h[i];
		//Ѱ��������
		if (sum > max)
			max = sum;
	}

}

int main() {

	while (scanf("%lld", &n), n) {

		getchar();
		for (int i = 0; i < n; ++i) {
			scanf("%lld", h + i);
			getchar();
		}
		dp();
		printf("%lld\n", max);
	}
	return 0;
}