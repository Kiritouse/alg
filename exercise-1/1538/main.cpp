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
					inputNow = 0;//移动到行首
					break;
				case ']':
					inputNow = lenans; //移动到末尾
					break;
				case '<':
					if (inputNow != 0) { //非行首
						inputNow--;
					}
					//else cout<<"你已经移动到行首了"<<endl;
					break;
				case '>':
					if (inputNow != lenans) { //非行尾
						inputNow++;
					}
					//else cout<<"你已经移动到行尾了"<<endl;
					break;
				case '-':
					if (inputNow != 0) {
						strans.erase(inputNow - 1, 1);
						inputNow--;
						lenans--;
					}
					//else cout<<"行首不能删除左边的"<<endl;
					break;
				case '+':
					if (inputNow != lenans) {
						strans.erase(inputNow, 1);
						lenans--;
					}
					//else cout<<"行尾不能删除右边的"<<endl;
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
