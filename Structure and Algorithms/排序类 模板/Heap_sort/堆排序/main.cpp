#include <iostream>

using namespace std;
/**
     * 堆排序
     * 时间复杂度O(nlogn)
     *
     * 二叉堆的数组从下标1开始存储，而不是0，若当前节点为i，则左子节点为2i，右子节点为2i+1，父节点为i/2
     *
     * 思路：
     *     1、构建大顶堆maxHeap（下标从0开始，所以和二叉堆有细微差别，节点i的左子节点为2i+1）
     *     2、大顶堆的0位置元素显然是最大的，将这个数沉到数组最末端
     *     3、重复步骤1、2
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
} //构建大顶堆
public static void maxHeap(int[] arr, int lastIndex) {
    for (int i = (lastIndex-1)/2; i >= 0; i--) {
            int k = i; //保存当前正在判断节点的索引 //如果当前节点存在子节点（判断依据是其左子节点索引在lastIndex范围内）
            while (2*k+1 <= lastIndex) { int biggerIndex = 2*k + 1; //biggerIndex总是记录值较大的节点的索引，初始值为左子节点索引
             if(biggerIndex < lastIndex) { //如果右子节点存在，否则会有
                 biggerIndex=lastIndex if(arr[biggerIndex] < arr[biggerIndex+1]) { //如果右子节点比左子节点的值大，则biggerIndex记录的是右子节点的索引
                        biggerIndex++;
                }
            }
    if(arr[k] < arr[biggerIndex])
             { //如果当前节点值小于其所有子节点中值最大的那个值，那么交换，//将当前节点索引设置为
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
