#define _CRT_SECURE_NO_WARNINGS 1

#include"Bank.h"



int avi[5];//全局变量
int arr[5];//全局变量

//打印函数
void my_printf(in &in, int &num)
{
	int i = 0;
	int j = 0;
	if (in.size == 0)
	{
		cout << "空" << endl;
		return;
	}
	while (i<in.size)
	{
		cout << "n:\t";
		cout << in.a[i].name << endl;
		cout << "M:\t";
		for (j = 0; j<num; j++)
		{
			cout << in.a[i].Max[j] << "\t";
		}
		printf("\n");
		cout << "A:\t";
		for (j = 0; j<num; j++)
		{
			cout << in.a[i].Allocation[j] << "\t";
		}
		printf("\n");
		cout << "N:\t";
		for (j = 0; j<num; j++)
		{
			cout << in.a[i].Need[j] << "\t";
		}
		cout << "\n";
		i++;
	}
	printf("\n");
	cout << "V:\t";
	for (j = 0; j<num; j++)
	{
		cout << avi[j] << "\t";
	}
	printf("\n");
}

//初始化函数
void init(in &in, int &num)
{
	int i = 0;
	in.a[in.size].OP = 0;
	for (i = 0; i<num; i++)
	{
		printf("请输入Max[%d]:>",i);
		scanf("%d", &in.a[in.size].Max[i]);
		printf("\n");
	}
	for (i = 0; i < num; i++)
	{
		printf("请输入Allocation[%d]:>", i);
		scanf("%d", &in.a[in.size].Allocation[i]);
		printf("\n");
		avi[i] = arr[i] - in.a[in.size].Allocation[i];
		arr[i] = avi[i];
	}
	for (i = 0; i<num; i++)
	{
		printf("Need[%d]:>", i);
		in.a[in.size].Need[i] = in.a[in.size].Max[i] - in.a[in.size].Allocation[i];
		printf("%d", in.a[in.size].Need[i]);
		printf("\n");
	}
	printf("请输入name:>");
	cin>>in.a[in.size].name;
	printf("\n");
	in.size++;
}

//判断函数（当前是否安全）
void judge(in in, int &num, ari tmp = {0})
{
	int work[5];
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < num; i++)
	{
		work[i] = avi[i];
	}
	for (i = 0; i < in.size; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (in.a[i].Need[j]>work[j])
				break;
		}
		if (j == num)
		{
			for (j = 0; j < num; j++)
			{
				work[j] += in.a[i].Allocation[j];
			}
			ari tmp = in.a[count];
			in.a[count] = in.a[i];
			in.a[i] = tmp;
			in.a[count].OP = 1;
			count++;
			i = count-1;
		}
	}
	for (i = 0; i < in.size; i++)
	{
		if (in.a[i].OP != 1)
		{
			printf("false!\n");
			for (j = 0; j < num; j++)
			{
				avi[j] += tmp.Need[j];
				in.a[i].Need[j] += tmp.Need[j];
			}
			break;
		}
	}
	my_printf(in, num);
}

//请求函数（请求获得资源，判断是否可以分配资源）
void requst(in &in,int &num)
{
	ari tmp;
	int value = 0;
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("请输入要请求的向量%d:>",i);
		scanf("%d", &tmp.Need[i]);
	}
	printf("请输入要请求资源的进程名：>");
	cin>>tmp.name;
	int count = in.size-1;
	while (count)
	{
		if (tmp.name == in.a[count].name)
			break;
		count--;
	}
	for (i = 0; i < num; i++)
	{
		if (tmp.Need[i]>in.a[count].Need[i] || tmp.Need[i] > avi[i])
		{
			printf("请求不成功！\n");
			break;
		}
	}
	if (i == num)
	{
		printf("请求成功！\n");
		for (i = 0; i < num; i++)
		{
			in.a[count].Need[i] -= tmp.Need[i];
			in.a[count].Allocation[i] += tmp.Need[i];
			avi[i] -= tmp.Need[i];
			if (in.a[count].Need[i] == 0)
			{
				value++;
			}
		}
		if (value == num);
		{
			avi[i] += in.a[count].Allocation[i];
			in.a[count].Allocation[i] = 0;
		}
		judge(in, num,tmp);
		
	}
}

void Meue()
{
	printf("*****************\n");
	printf("****1.init*******\n");
	printf("****2.printf*****\n");
	printf("****3.requst*****\n");
	printf("****4.judge******\n");
	printf("*****************\n");
}
int main()
{
	in in;
	in.size = 0;
	int tmp = 0;
	int num = 0;
	int i = 0;
	printf("请输入资源总数：");
	scanf("%d", &num);
	for (i = 0; i<num; i++)
	{
		printf("请输入资源总量%d：",i);
		scanf("%d", &arr[i]);
	}

	while (1)
	{
		Meue();
		printf("请选择：〉");
		scanf(" %d", &tmp);
		switch (tmp)
		{
		case 1:
			init(in, num);
			break;
		case 2:
			my_printf(in,num);
			break;
		case 3:
			requst(in,num);
			break;
		case 4:
            judge(in, num);
			break;
		}
	}
	return 0;
}