#ifndef DOMMATCH_H
#define DOMMATCH_H

#include <domino.h>


class dommatch : public domino //������������
{
    public:
        bool reality(); //�������� �� ���������
        void findsolution(); //����������� ��������
        bool findsol(int);
        int first;
        void outputsolution();
        dommatch(); //�����������
        virtual ~dommatch(); //����������
    protected:
    private:
        int start[6]; //��������� �����
        int   //����� �����
        last; //������ �����
};

#endif // DOMMATCH_H
