#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
void arrayTest() {
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	
	int b[5] = { 0,1,2,3,4 };
}

void insertSort(int a[], int n) {
	int k = 0;
	for (int i = 2; i < n; i++)
	{
		if (a[i]<a[i-1])
		{
			a[0] = a[i];
			for (k = i-1; k >= 0 && a[k]>a[0]; k--)
			{
				a[k + 1] = a[k];
			}
			a[k+1] = a[0];
		}
	}
}

int partionData(int a[], int low, int high) {
	int p = a[low];
	while (low < high) {
		while (a[high] > p && low < high) high--;
		a[low] = a[high];
		while (a[low] < p && low < high) low++;
		a[high] = a[low];
	}
	a[low] = p;
	return p;
}
void quickSort(int a[], int low,int high) {
	if (low<high)
	{
		int p = partionData(a,low,high);
		quickSort(a, low,p-1);
		quickSort(a, p + 1, high);
	}
}

int back[10];
void mergeData(int a[],  int low, int high, int m) {
	if (low<high)
	{
		for (int i = low; i <= high; i++)
		{
			back[i] = a[i];
		}
		int low_p = low;
		int high_p = m+1;
		int i = low;
		while (low_p<=m && high_p<=high)
		{
			if (back[low_p]<back[high_p])
			{
				a[i] = back[low_p];
				i++; low_p++;
			}
			else {
				a[i] = back[high_p];
				i++; high_p++;
			}
		}
		while (low_p<=m)
		{
			a[i] = back[low_p];
			i++; low_p++;
		}
		while (high_p <= high)
		{
			a[i] = back[high_p];
			i++; high_p++;
		}
	}
}
void mergeSort(int a[], int low, int high) {
	if (low<high)
	{
		int m = (low + high) / 2;
		mergeSort(a, low, m);
		mergeSort(a, m + 1, high);
		mergeData(a, low, high, m);
	}
}


int BinarySearch(int a[],int low,int high ,int target) {
	if (low<=high)
	{
		int m = (low+high) / 2;
		if (a[m] == target)
		{
			return m;
		}
		else if (a[m] > target) {
			return BinarySearch(a, m + 1, high, target);
		}
		else {
			return BinarySearch(a, low, m - 1, target);
		}
	}
	return -1;
}


char* get3Words(char* str,int index) {
	char *temp = malloc(4*sizeof(char));
	for (int i = 0; i < 3; i++,index++)
	{
		temp[i] = str[index];
	}
	temp[3] = '\0';
	return temp;
}
void testString() {
	char str[10];
	scanf_s("%9s", str, 10);
	int i = 0;
	int count = 0;
	while (str[i] != '\0') {
		i++;
	}
	for (int i = 0; i < 10; i++)
	{
		
		str[i] = toupper(str[i]);
		str[i] = tolower(str[i]);
	}
	for (int i = 0; i < 8; i++)
	{
		char* temp;
		temp = get3Words(str, i);
		if ((str[i]=='t' && str[i+1]=='h' && str[i+2]=='e')
			|| strcmp(temp,"the")==0)
		{
			count++;
		}
		free(temp);
	}
}

typedef struct Link {
	int val;
	struct Link* next;
}Link;
#define MAX 100
typedef struct Stack {
	int top;
	int a[MAX];
}Stack;


void addLink(Link* l, int val) {
	Link* temp = malloc(sizeof(Link));
	temp->val = val;
	temp->next = l->next;
	l->next = temp;
}
Link * InitLink() {
	Link* head = malloc(sizeof(Link));
	head->val = -1;
	head->next = NULL;
	return head;
}
Stack* InitStack() {
	Stack* s = malloc(sizeof(Stack));
	s->top = -1;
	return s;
}
void addStack(Stack* s, int val) {
	if (s->top<MAX-1)
	{
		s->a[++s->top] = val;
	}
	else {
		printf("stack overflow");
	}
}
int popStack(Stack* s) {
	if (s->top>=0)
	{
		return s->a[s->top--];
	}
	else {
		printf("stack underflow");
		return -1;
	}
}
typedef struct BTree {
	int val;
	struct BTree* left;
	struct BTree* right;
}BTree;

BTree* CreateTreeNode() {
	int val;
	scanf_s(" %d", &val);
	if (val==-1)
	{
		return NULL;
	}
	BTree* temp = malloc(sizeof(BTree));
	temp->val = val;
	temp->left = CreateTreeNode();
	temp->right = CreateTreeNode();
	return temp;
}
int GetDeep(BTree* tree) {
	if (tree==NULL)
	{
		return 0;
	}
	int left = GetDeep(tree);
	int right = GetDeep(tree);
	return (left > right ? left : right) + 1;
}

int cbd(int a, int b) {
	if (b==0)
	{
		return a;
	}
	return cbd(b, a % b);
}
#pragma region 不熟

void BuidMaxHead(int a[], int n) {
	//从中间到根节点逐个调整
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Adjust(a, i, n);
	}
}
void Adjust(int a[], int i, int length) {
	int temp = a[i];
	//从左孩子往叶子结点开始调
	for (int k = 2 * i + 1; k < length; k = 2 * k + 1)
	{
		if (k + 1 < length && a[k] < a[k + 1])
		{
			k++;
		}
		if (a[k] > temp)
		{
			a[i] = a[k];//上移左孩子
			i = k;//左孩子位置给当前节点
		}
		else {
			break;
		}
	}
	a[i] = temp;
}
void MaxHeadSort(int a[], int n) {
	BuidMaxHead(a, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(&a[0], &a[i]);//最大值放最后，从小到大排
		Adjust(a, 0, i);
	}
}

typedef struct Queue {
	int a[MAX];
	int front;
	int rear;
}Queue;

Queue* InitQueue() {
	Queue* q = malloc(sizeof(Queue));
	q->front = 0;
	q->rear = 0;
	return q;
}
int isQueueEmpty(Queue* q) {
	return q->front == q->rear;
}
int isQueueFull(Queue* q) {
	if (q->rear + 1 / MAX == q->front)
	{
		return 1;
	}
	else {
		return 0;
	}
}

void EnQueue(Queue* q, int val) {
	if (!isQueueFull(q))
	{
		q->a[q->rear] = val;
		q->rear = (q->rear++) % MAX;
	}
	else {
		printf("queue is full");
	}
}
int DeQueue(Queue* q) {
	if (isQueueEmpty(q))
	{
		printf("queue is empty");
		return -1;
	}
	int temp = q->a[q->front];
	q->front = q->front++ % MAX;
	return temp;
}

void printTime() {
	time_t t = time(NULL);
	struct tm* local;
	local = localtime(&t);

	printf("%d", local->tm_year);
}


void ReadFile(char* fileName) {
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		exit(1);
	}
	char line[100];
	while (fgets(line, 100, file) != NULL)
	{
		char name[10];
		char sex;
		int age;
		sscanf_s(line, "%9s %c %d", name, 10, &sex, 1, &age);
	}
	char c;
	while ((c = fgetc(file)) != EOF)
	{
		printf("%c", c);
	}
	fclose(file);
}

void SaveFile(char* fileName) {
	FILE* file = fopen(fileName, "w");
	fprintf(file, "%s %c %d", "gavin", 'M', 40);
	fclose(file);
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void allPrint(int a[],int index,int length) {
	if (index==length)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%d", a[i]);
		}
		return;
	}
	for (int i = index; i <= length; i++)
	{
		swap(&a[index], &a[i]);
		allPrint(a, i+1, length);
		swap(&a[index], &a[i]);
	}
}
#pragma endregion



int fibonaqie(int a) {
	if (a==1 || a==2)
	{
		return 1;
	}
	return fibonaqie(a -1)+fibonaqie(a-2);
}


void MathFunction() {
	abs(-2);
	ceil(2.5);
	floor(2.2);
	round(2.4);
}
void stringFunction() {
	char ch1[10] = "123";
	char ch2[10] = "234";
	if (strcmp(ch1, ch2) == 0) {
		printf("same");
	}
	strcat(ch1, ch2);
	printf_s("%s", ch1);
}
typedef struct MGraph {
	int vex[MAX];
	int edge[MAX][MAX];
	int vexnum;
	int arcnum;
}MGraph;
void prim(MGraph g) {
	int dist[MAX];
	int path[MAX];
	int isUse[MAX] = { 0 };
	dist[0] = -1;
	path[0] = -1;
	isUse[0] = 1;
	for (int i = 1; i < g.vexnum; i++)
	{
		if (g.edge[0][i]!=0)
		{
			path[i] = 0;
			dist[i] = g.edge[0][i];
		}
		else {
			dist[i] =INT_MAX;
		}
	}
	int min_vex = -1, min_data;
	for (int i = 1; i < g.vexnum; i++)
	{
		min_data = INT_MAX;
		for (int j = 0; j < g.vexnum; j++)
		{
			if (isUse[j]==0 && dist[j]<min_data)
			{
				min_vex = j;
				min_data = dist[j];
			}
		}
		
		isUse[min_vex] = 1;
		for (int j = 0; j < g.vexnum; j++)
		{
			if (isUse[j]==0 && dist[j]>g.edge[min_vex][j])
			{
				dist[j] = g.edge[min_vex][j];
				path[j] = min_vex;
			}
		}
	}
	for (int i = 0; i < g.vexnum; i++)
	{
		printf("%d -> %d %d \n", path[i],i,dist[i]);
	}
}
void dijkstra(MGraph g, int v) {
    int dist[MAX];
    int path[MAX];
    int isUse[MAX] = { 0 };

    for (int i = 0; i < g.vexnum; i++) {
        if (g.edge[v][i] > 0 && i != v) {
            dist[i] = g.edge[v][i];
            path[i] = v;
        } else {
            dist[i] = INT_MAX;
            path[i] = -1;
        }
    }

    dist[v] = 0;
    isUse[v] = 1;

    for (int i = 1; i < g.vexnum; i++) {
        int min_data = INT_MAX;
        int min_vex = -1;

        for (int j = 0; j < g.vexnum; j++) {
            if (!isUse[j] && dist[j] < min_data) {
                min_vex = j;
                min_data = dist[j];
            }
        }

        if (min_vex == -1) break;

        isUse[min_vex] = 1;

        for (int j = 0; j < g.vexnum; j++) {
            if (!isUse[j] && g.edge[min_vex][j] > 0 &&
                dist[min_vex] + g.edge[min_vex][j] < dist[j]) {
                dist[j] = dist[min_vex] + g.edge[min_vex][j];
                path[j] = min_vex;
            }
        }
    }

    // 输出结果可以加上 dist[] 和 path[] 打印
}

		
	
}
