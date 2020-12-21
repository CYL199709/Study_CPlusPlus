#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std; 
#define maxSize 100000
typedef int KeyType;

typedef struct Entry
{
	KeyType key;
}Entry;

typedef struct list
{
	int n;
	Entry D[maxSize];
}List;

/*输出*/
void Print(List *list,int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<list->D[i].key<<endl;
	return ;
}

/****************************************/
/*选择排序*/
/*
int FindMin(List list,int startIndex)
{
	int i,minIndex=startIndex;
	for(i=startIndex;i<list.n;i++)
	{
		if(list.D[i].key<list.D[minIndex].key)
			minIndex=i;
	}
	return minIndex;
}

void Swap(Entry *D,int i,int j)
{
	if(i==j)
		return ;
	Entry tmp=*(D+i);
	*(D+i)=*(D+j);
	*(D+j)=tmp;
}
*/
/*void SelectSort(List *list)
{
	int minIndex,startIndex=0;
	while(startIndex<list->n-1)
	{
		minIndex=FindMin(*list,startIndex);
		Swap(list->D,startIndex,minIndex);
		startIndex++;
	}
}*/
/*选择排序1*/
void Swap1(Entry &a,Entry &b)  
{  
    Entry temp=a;  
    a=b;  
    b=temp;  
}  
void SelectSort(List *list)    //简单选择排序  
{  
    int small;  
	Entry temp;
    for(int i=0;i<list->n-1;i++)  
    {  
        small=i;  
        for(int j=i+1;j<list->n;j++)  
            if(list->D[j].key<list->D[small].key)  
                small=j;  
        //Swap1(list->D[i],list->D[small]);  
		temp=list->D[i];  
		list->D[i]=list->D[small];  
		list->D[small]=temp;  
    }  
}  
/*****************************************/
/*插入排序*/
void InsertSort(List *list)
{
	int i,j;
	for(i=1;i<list->n;i++)
	{
		Entry insertItem=list->D[i];
		for(j=i-1;j>=0;j--)
		{
			if(insertItem.key<list->D[j].key)
				list->D[j+1]=list->D[j];
			else 
				break;
		}
		list->D[j+1]=insertItem;
	}
}
/*****************************************/
/*冒泡排序*/
void BubbleSort(List *list)
{
	int i,j;
	
	for(i=list->n-1;i>0;i--)
	{
		bool isSwap=false;
		for(j=0;j<i;j++)
		{
			if(list->D[j].key>list->D[j+1].key)
			{
				//Swap1(list->D[j],list->D[j+1]);
				Entry temp=list->D[j];  
				list->D[j]=list->D[j+1];  
				list->D[j+1]=temp;  
				isSwap=true;
			}
		}
		if(!isSwap)
			break;
	}
}
/***************************************/
/*快速排序*/
int Partition(List *list,int low,int high)
{
	int i=low,j=high+1;
	Entry pivot=list->D[low];
	do{
		do{
			i++;
		}while(list->D[i].key<pivot.key);
		do{
			j--;
		}
		while(list->D[j].key>pivot.key);
	}while(i<j);
	//Swap1(list->D[low],list->D[j]);
	Entry temp=list->D[low];  
    list->D[low]=list->D[j];  
    list->D[j]=temp;  
	return j;                  //此时j是分割元素下标
}

void QuickSort(List *list,int low,int high)
{
	int k;
	if(low<high)
	{
		k=Partition(list,low,high);
		QuickSort(list,low,k-1);
		QuickSort(list,k+1,high);
	}
}

void QuickSort(List *list)
{
	QuickSort(list,0,list->n-1);
}

/*********************************************/
/*归并排序*/
void Merge(List *l, Entry *temp, int low, int n1, int n2)
{
    int i = low, j = low + n1,k = low;
    while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1)
    {
        if (l->D[i].key <= l->D[j].key)
            temp[k++] = l->D[i++];
        else
            temp[k++] = l->D[j++];
    }
    while (i <= low + n1 - 1)
        temp[k++] = l->D[i++];
    while (j <= low + n1 + n2 - 1)
        temp[k++] = l->D[j++];
}

void MergeSort(List *l,int maxsize)
{
    Entry temp[maxSize];
    int low, n1, n2, i, s = 1;
    while(s < l->n)
    {
        low = 0;
        while (low + s < l->n )
        {
            n1 = s;
            if (low + s*2 < l->n)
                n2 = s;
            else
                n2 = l->n-low-s;
            Merge(l, temp, low, n1, n2);
            low = low + n1 + n2;
        }
        for (i = 0 ; i < l->n ; i++ )
        {
            l->D[i] = temp[i];
        }
        s = s*2;
    }
}

void InitList(List *list,int maxsize)
{
	list->n=0;
	for(int i=0;i<maxsize;i++)
	{
		list->D[i].key=0;
	}

}
void Init(int a[],List *list)
{
	for(int i=0;i<list->n;i++)
	{
		list->D[i].key=a[i];
	}
}



int main()
{
	int i;  char ch;
//	int number[maxSize];
	int *number;
	int maxsize;
	FILE *fp;
	fp=fopen("number.txt","w+");
	clock_t begin, duration;

	cout<<"时间做种，生成随机数，随机数存在number.txt文件中\n排序验证输出时间进行参考"<<endl ; 
	List list;
	cout<<"输入数目：";
		cin>>maxsize;
		InitList(&list,maxsize);
		number=new int[maxsize];
		srand(time(NULL));                //用时间做种，每次产生随机数不一样

		for (i=0; i<maxsize; i++)
		{          
			number[i]=(rand()%10001)*(rand()%100001);  
		//	number[i]=rand();
			fprintf(fp,"%d ",number[i]);
		} 
		printf("\n\n");

		for(i=0;i<maxsize;i++)
		{
			list.D[i].key=number[i];
		//	number1[i]=number[i];
			list.n++;
		}
	cout<<"1.冒泡排序\n2.选择排序\n3.快排\n4.插入排序\n5.归并排序\n";
	while(1)
	{
		cout<<"输入操作序号：";
		cin>>i;
		switch(i)
		{
		case 1:
	/******冒泡排序*******/
			Init(number,&list);
			begin=clock();
			BubbleSort(&list);
			duration=clock()-begin;
			cout<<"冒泡排序："<<(double)duration*1000/CLOCKS_PER_SEC<<endl;
			break;

		case 2:
			Init(number,&list);
			begin=clock();
			SelectSort(&list);
			duration=clock()-begin;
			cout<<"选择排序："<<(double)duration*1000/CLOCKS_PER_SEC<<endl;
			break;
	
		case 3:
			Init(number,&list);
			begin=clock();
			QuickSort(&list);
			duration=clock()-begin;
			cout<<"快速排序："<<(double)duration*1000/CLOCKS_PER_SEC<<endl;
			break;

		case 4:
			Init(number,&list);
			//Print(&list,list.n);
			begin=clock();
			InsertSort(&list);
			duration=clock()-begin;
//	cout<<endl;
//	Print(&list,list.n);
			cout<<"插入排序："<<(double)duration*1000/CLOCKS_PER_SEC<<endl;	break;
		case 5:
			Init(number,&list);
			begin=clock();
			MergeSort(&list,maxsize);
			duration=clock()-begin;
			cout<<"归并排序："<<(double)duration*1000/CLOCKS_PER_SEC<<endl;
			break;
		}
		cout<<"是否继续（输出n退出啊，其他字符继续循环）:";
		cin>>ch;
		if(ch=='n')
			break;
	}
	fclose(fp);
	return 0;
}





