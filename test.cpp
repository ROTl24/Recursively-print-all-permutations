#include <iostream>
#define Swap(a, b) {int temp = (a); (a) = (b); (b) = temp;}
//�������������Է�ֹ�ں궨��������ʱ��������

/*
�궨���е� "Swap" ��չ����ʵ�����ǽ������еı��ʽ�滻Ϊ�������ֵ�������ʹ�����Ž� "a" �� "b" �����������ܻᵼ���ں궨����ʹ��ʱ�������⡣

���磬����� "Swap" �궨����ʹ�� "Swap(x, y+1)"����չ������Ϊ "int temp = (x); (x) = (y+1); (y+1) = temp;"������Ȼ������ȷ�Ľ�����䡣

��ˣ�����������Ϊ��ȷ����������Ϊ�������ʽ�����ں궨������ȷ��ִ�н���������
*/
using namespace std;

int dataa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//"dataa" ��һ��ȫ�ֱ���������� Perm �����п���ֱ�ӷ��ʺ��޸ġ�
int num = 0;
//num������¼����
void Perm(int begin, int end) {
    if (begin == end) {
        for (int j = 0; j < end; j++) {//��ӡ���
            cout << dataa[j] << " ";
        }
        cout << endl;
        num++;
    }
    else {
        for (int i = begin; i < end; i++) {
            Swap(dataa[begin], dataa[i]);//����
            Perm(begin + 1, end);//�ݹ�
            Swap(dataa[begin], dataa[i]);//�ָ�
        }
    }
}
/*

�����ʽ��
123456789
123456798
123456879
������������������������
*/
int main() {
    Perm(0, 9);
    cout << num << endl;
    return 0;
}
