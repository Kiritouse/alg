#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	string str;
	string strans;
	str.resize(507, 0);
	strans.resize(507, 0);
	while (getline(cin, str)) {
		int len = str.length();
		int lenans = 0;
		int inputNow = 0;
		for (int i = 0; i < len; i++) {
			char now = str[i];
			string temp(1, now);
			switch (now) {
				case '[':
					inputNow = 0;//�ƶ�������
					break;
				case ']':
					inputNow = lenans; //�ƶ���ĩβ
					break;
				case '<':
					if (inputNow != 0) { //������
						inputNow--;
					}
					//else cout<<"���Ѿ��ƶ���������"<<endl;
					break;
				case '>':
					if (inputNow != lenans) { //����β
						inputNow++;
					}
					//else cout<<"���Ѿ��ƶ�����β��"<<endl;
					break;
				case '-':
					if (inputNow != 0) {
						strans.erase(inputNow - 1, 1);
						inputNow--;
						lenans--;
					}
					//else cout<<"���ײ���ɾ����ߵ�"<<endl;
					break;
				case '+':
					if (inputNow != lenans) {
						strans.erase(inputNow, 1);
						lenans--;
					}
					//else cout<<"��β����ɾ���ұߵ�"<<endl;
					break;
				default:
					strans.insert(inputNow++, temp);
					lenans++;
					break;
			}
		}
		for (int i = 0; i < lenans; i++) {
			cout << strans[i];
		}
		cout << "\n";
		str.resize(507, 0);
		strans.resize(507, 0);
	}
}
