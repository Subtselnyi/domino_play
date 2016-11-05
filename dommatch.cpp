#include "dommatch.h"

dommatch::dommatch() //����������
{
     n=10;
    solution=new edge[n];
     for (int i=0;i<n; i++){
        solution[i].a=0;
        solution[i].b=0;
    }
    solutions=new edge[n];
     for (int i=0;i<n; i++){
        solutions[i].a=0;
        solutions[i].b=0;
    }
}

dommatch::~dommatch() //���������
{
    delete [] solution;
    delete [] solutions;
}

bool dommatch::reality() //�������� �� ���������
{
    int l=0;
    int massiv[6];
    int cc=0;
    for (int i=1;i<7;i++) //��������� ���������� ������
        massiv[i]=0;
    for (int i=0;i<n;i++) //����������� ������� �������� �����
    {
        massiv[mass[i].a]++;
        massiv[mass[i].b]++;
    }
    for (int i=1;i<=6;i++) //�������� �� ������� �������� �����
    {
        if (massiv[i]%2!=0){
            cc++;
            start[l++]=i;
        }
    }
    if (cc>2) return false; //��������� false ���� ������� �������� ����� ����� 2
    first=mass[0].a;

    for (int i=0;i<n;i++){ //������ ������ �������
        if ((mass[i].a==start[0])){
            first=mass[i].b;
            mass[i].mark=false;
            solution[num++]=mass[i];
            break;
        }
        if ((mass[i].b==start[0])){
            first=mass[i].a;
            mass[i].mark=false;
            solution[num++]=mass[i];
            break;
        }
    }

   /* for (int i=0;i<n;i++){//������ ������ �������
        if ((mass[i].a==start[1])&&(mass[i].a!=first)&&mass[i].mark){
            last=mass[i].b;
            mass[i].mark=false;
            solution[n-1]=mass[i];
            break;
        }
        if ((mass[i].b==start[1])&&(mass[i].b!=first)&&mass[i].mark){
            last=mass[i].a;
            mass[i].mark=false;
            solution[n-1]=mass[i];
            break;
        }
    }*/
    return true;

}

void dommatch::findsolution() //������ �������
{
    for (int j=0;j<n;j++){
    for (int i=0;i<n;i++)
    {
        if (num==n) continue;
        if (mass[i].mark&&(mass[i].a==first))//���� ���������� �����
        {
            first=mass[i].b;//���� ���������� �����
            mass[i].mark=false;
            solution[num++]=mass[i]; //������ �� ���������
        }
        if (mass[i].mark&&(mass[i].b==first))//���� ���������� �����
        {
            first=mass[i].a;
            mass[i].mark=false;
            solution[num++]=mass[i];//������ �� ��������
        }
    }
    }
    if (num!=n-1){cout<<"NO WAY"; return;}
    for (int i=0;i<n;i++) //������� ��������
    {
        cout<<solution[i].a<<" "<<solution[i].b<<endl;
    }

}


bool dommatch::findsol(int ffirst)
{
    for (int i=0;i<n;i++)
    {
        if(num==n){
            for(int j=0;j<n;j++){
                solutions[j]=solution[j];

            }
        }
        if(num!=n)
        {
            if ((ffirst==mass[i].a||ffirst==mass[i].b)&&mass[i].mark)
            {
                mass[i].mark=false;
                solution[num]=mass[i];
                num++;
                if ((ffirst==mass[i].a))
                    findsol(mass[i].b);
                else if (mass[i].a!=0)
                    findsol(mass[i].a);
                num--;
                mass[i].mark=true;
            }
        }
    }

}

void dommatch::outputsolution()
{
    if (solutions[0].a==0)
        cout<<"NO WAY"<<endl;
    else
     for (int i=0;i<n;i++) //������� ��������
    {
        cout<<solutions[i].a<<" "<<solutions[i].b<<endl;
    }
}
