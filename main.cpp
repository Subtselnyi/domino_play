#include <iostream>
#include "domino.h"
#include "dommatch.h"

using namespace std;

int main()
{
    cout << "Subtselnyi Oleksandr Volodymyrovych" << endl;
    cout << "V : 20" << endl;
    cout << "L : B" << endl << endl;
    char h;
    while (h!='s'){
    dommatch* jbj = new dommatch(); //��������� ������
    jbj->output();//������� ���������� ������������� ��������
    jbj->input();//��������� ������ ��� ���
    if (jbj->reality()){ //�������� �� ���������
        cout<<"maybe possible"<<endl;
        //jbj->findsolution();//������ ����
        jbj->findsol(jbj->first);
        jbj->outputsolution();
    }
    else cout<<"NO!"<<endl;

    delete jbj; //�������� ����
    cout<<"if you want to stop press s";
    cin>>h;
    }
}
