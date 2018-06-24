#include <iostream>

using namespace std;
/**
     * ������
     * ʱ�临�Ӷ�O(nlogn)
     *
     * ����ѵ�������±�1��ʼ�洢��������0������ǰ�ڵ�Ϊi�������ӽڵ�Ϊ2i�����ӽڵ�Ϊ2i+1�����ڵ�Ϊi/2
     *
     * ˼·��
     *     1�������󶥶�maxHeap���±��0��ʼ�����ԺͶ������ϸ΢��𣬽ڵ�i�����ӽڵ�Ϊ2i+1��
     *     2���󶥶ѵ�0λ��Ԫ����Ȼ�����ģ������������������ĩ��
     *     3���ظ�����1��2
     */
 public static int[] heapSort(int[] arr) {
     if(arr.length <= 1){
          return arr;
    }
    for (int i = 0; i < arr.length; i++) {
        maxHeap(arr, arr.length-1-i);
        swap(arr, 0, arr.length-1-i);
    }
    return arr;
} //�����󶥶�
public static void maxHeap(int[] arr, int lastIndex) {
    for (int i = (lastIndex-1)/2; i >= 0; i--) {
            int k = i; //���浱ǰ�����жϽڵ������ //�����ǰ�ڵ�����ӽڵ㣨�ж������������ӽڵ�������lastIndex��Χ�ڣ�
            while (2*k+1 <= lastIndex) { int biggerIndex = 2*k + 1; //biggerIndex���Ǽ�¼ֵ�ϴ�Ľڵ����������ʼֵΪ���ӽڵ�����
             if(biggerIndex < lastIndex) { //������ӽڵ���ڣ��������
                 biggerIndex=lastIndex if(arr[biggerIndex] < arr[biggerIndex+1]) { //������ӽڵ�����ӽڵ��ֵ����biggerIndex��¼�������ӽڵ������
                        biggerIndex++;
                }
            }
    if(arr[k] < arr[biggerIndex])
             { //�����ǰ�ڵ�ֵС���������ӽڵ���ֵ�����Ǹ�ֵ����ô������//����ǰ�ڵ���������Ϊ
                 biggerIndex swap(arr, k, biggerIndex);
                k = biggerIndex;
            } else break;
        }
    }

}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
