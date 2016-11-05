#ifndef DOMINO_H
#define DOMINO_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

class domino
{
    public:
        int n; //������� �����
        int num=0; //��������
        void output(); //�������
        void input(); //�����
        domino(); //�����������
        virtual ~domino(); //����������
    protected:
        struct edge //������� �����
        {
            int a,b;
            bool mark;
        };
        edge *mass; //����� � �����
        edge *solution; //�������
        edge *solutions;
    private:

};

#endif // DOMINO_H
