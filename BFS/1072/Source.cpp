#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

class Node {
public:
	int x_, y_;
	int step_;
	int timeleft_;
};

int xmove[] = { -1, 1, 0, 0 };
int ymove[] = { 0, 0, -1, 1 };

int labyrinthln, labyrinthcol;
int labyrinth[10][10];
int startx, starty;

int BFS() {

	queue<Node> q;
	int timeleft[10][10];
	memset(timeleft, 0, sizeof(timeleft));

	Node dad = { startx, starty, 0, 6 };
	timeleft[dad.x_][dad.y_] = 6;
	q.push(dad);
	while (!q.empty()) {

		dad = q.front();
		q.pop();

		//�����յ㣬���ص�ǰ����
		if (labyrinth[dad.x_][dad.y_] == 3)
			return dad.step_;

		//��ֻʣ1����λʱ�䣬����һ�����뵽���յ㣬��ֱ�ӽ�����һѭ��
		if (dad.timeleft_ == 1)
			continue;

		Node son;
		son.step_ = dad.step_ + 1;

		for (int i = 0; i < 4; ++i) {
			son.x_ = dad.x_ + xmove[i];
			son.y_ = dad.y_ + ymove[i];
			son.timeleft_ = dad.timeleft_ - 1;
			
			if (son.x_ > -1 & son.x_ < labyrinthln && son.y_ > -1 && son.y_ < labyrinthcol && labyrinth[son.x_][son.y_] != 0) {

				if (labyrinth[son.x_][son.y_] == 4) {
					son.timeleft_ = 6;
				}
				//������������ը��ʣ��ʱ��ʹ�ã�ʣ��ʱ�����֮ǰ�����ڵ�ǰλ�õ�ʣ��ʱ��
				if (son.timeleft_ > timeleft[son.x_][son.y_]){
					timeleft[son.x_][son.y_] = son.timeleft_;//���µ�ǰλ�õ�ʣ��ʱ��
					q.push(son);
				}

			}
		}

	}
	return -1;
}

int main() {

	int task;
	scanf("%d", &task);
	getchar();
	while (task-- != 0) {
		scanf("%d %d", &labyrinthln, &labyrinthcol);
		getchar();
		for (int i = 0; i < labyrinthln; ++i)
			for (int j = 0; j < labyrinthcol; ++j) {
				scanf("%d", &labyrinth[i][j]);
				getchar();
				if (labyrinth[i][j] == 2) {
					startx = i;
					starty = j;
				}
			}
		int step = BFS();
		printf("%d\n", step);
	}
}