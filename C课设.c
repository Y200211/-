#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<stdlib.h> 
#include<string.h>

typedef struct Node{
	int id;//学号 
	char name[50];
	char sex[10];
	int ma,c,en;//高数，C语言，英语 
	int sum;
	struct Node* next;
}node; 

node List;//链表

//读取文件
int readFile(node *L); 

//保存文件
int saveFile(node *L); 


void welcome();//欢迎界面

//增加学生信息
void printaddStuInfo(); //界面 
void insertStuInfo(node* L,node e);//功能 

//删除学生信息
void deteleStuInfo();

//修改学生信息
void fixStuInfo();

//查询学生信息
void printSearchStuInfo(node *L);
	
	//按学号查询 
node *searchStuInfoById(int id,node *L);
//按姓名查询 
node *searchStuInfoByName(char name[],node *L);

//输出学生信息
void printStuInfo(node* L);

//退出程序 
void goodbye();



int main(){
	int choice = 0;
	readFile(&List);


	while(true){
		welcome();
	scanf("%d",&choice);
	switch(choice){
		case 1://增加学生信息
		printaddStuInfo();
			break;
		case 2://删除学生信息
		deteleStuInfo(); 
			break;
		case 3://修改学生信息 
		fixStuInfo();
			break;
		case 4://查询学生信息
		printSearchStuInfo(&List);
			break;
		case 5://输出学生信息
		printStuInfo(&List);
			break;
		case 0://退出程序 
		goodbye();
			break;
	}
	printf("是否还要继续操作? (YES:1 / NO:0)"); 
	scanf("%d",&choice);
	if(choice == 0){
		break;
	}
}
	return 0;
} 

void welcome(){
	system("cls");
	printf("********************\n");
	printf("**   学生成绩管理系统   **\n");
	printf("**                      **\n");
	printf("**  增加学生信息 ---1   **\n");
	printf("**  删除学生信息 ---2   **\n");
	printf("**  修改学生信息 ---3   **\n");
	printf("**  查询学生信息 ---4   **\n");
	printf("**  输出学生信息 ---5   **\n");
	printf("**  退出管理系统 ---0   **\n");
	printf("  请输入对应功能键数字： \n");
}

//增加学生信息
void printaddStuInfo(){
	system("cls");
	node st;
	printf("请输入新增学生相关信息\n");
	printf("学号：");
	scanf("%d",&st.id);
	printf("姓名：");
	scanf("%s",st.name);
	printf("性别：");
	scanf("%s",st.sex);
	printf("高数：");
	scanf("%d",&st.ma); 
	printf("C语言：");
	scanf("%d",&st.c);	
	printf("英语：");
	scanf("%d",&st.en);	
	st.sum = st.ma + st.c + st.en;
	
	insertStuInfo(&List,st);
	
}

void insertStuInfo(node* L,node e){
	//头插法 
	node *h = L;
	node *s=(node*)malloc(sizeof(node));
	*s = e;
	s -> next = h -> next;
	h -> next = s;
	saveFile(L); 
}
//删除学生信息
void deteleStuInfo(){
	printf("删除学生信息：\n"); 
}
//修改学生信息
void fixStuInfo(){
	printf("修改学生信息：\n"); 
}
//查询学生信息
void printSearchStuInfo(node *L){
		system("cls");
		int choice = 0; 
		char name[50];
		int id;
		node *st; 
	printf("按学号查询---------1\n"); 
	printf("按姓名查询---------2\n"); 	
	printf("请输入查询方式："); 
	scanf("%d",&choice);
	
	if(choice == 1){
		printf("请输入要查询的学号：");
		scanf("%d",&id);
		st=searchStuInfoById(id,L);
		
		if(st==NULL){
			printf("查无此人！\n");
		}else{
			st=st->next;
			printf("________________________________________________________\n");
			printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
			printf("________________________________________________________\n");
			printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->c,st->en,st->sum);
			printf("________________________________________________________\n");
		}
	}else if(choice ==2){
		printf("请输入要查询的姓名：");
			scanf("%s",name);
			st=searchStuInfoByName(name,L);
			
			if(st==NULL){
				printf("查无此人！\n");
			}else{
				st=st->next;
				printf("________________________________________________________\n");
				printf("|学号\t|姓名\t|性别\t|语文\t|数学\t|英语\t|总分\t|\n");
				printf("________________________________________________________\n");
				printf("%d|%s\t|%s\t|%d\t|%d\t|%d\t|%d\t|\n",st->id,st->name,st->sex,st->ma,st->c,st->en,st->sum);
				printf("________________________________________________________\n");
			}
	}
	
}
//按学号查询 
node *searchStuInfoById(int id,node *L){
	node *p = L;
	while(p -> next != NULL) {
		if(p -> next -> id == id){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
//按姓名查询 
node *searchStuInfoByName(char name[],node *L){
	node *p = L;
	while(p -> next != NULL) {
		if(strcmp(name,p->next->name)==0){
			return p;
		}
		p = p->next;
	}
	return NULL;	
}


//输出学生信息
void printStuInfo(node *L){
	system("cls"); 
	printf("输出学生信息：\n");
		
	node *p = L->next;
	if(p != NULL){
		printf("学号\t\t姓名\t性别\t高数\tC语言\t英语\t总分\n"); 
		while(p != NULL){
			printf("-------------------------------------------------------------\n");
			printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n",p ->id,p->name,p->sex,p->ma,p->c,p->en,p->sum);
			p=p->next;
		}
		
	} 
	
}
//退出程序 
void goodbye(){
	printf("退出管理系统");
	exit(0); 
}

//文件输入
int readFile(node *L){
	FILE *fpr = fopen("studentInfo.txt","r");
	node st;
	node *s;
	node *t = L;
	
	if(fpr == NULL){
		return 0;
	} else {
		//fscanf()
		while(fscanf(fpr,"%d %s %s %d %d %d %d",&st.id,st.name,st.sex,&st.c,&st.en,&st.ma,&st.sum) != EOF)  {
			s = (node*)malloc(sizeof(node));
		//测试用代码：	printf("%d %s %s %d %d %d %d\n",st.id,st.name,st.sex,st.c,st.en,st.ma,st.sum);
			*s = st;
			
			t -> next = s;
			t = s;
			t -> next = NULL;
			
			
		}
	}
	return 1;
} 

//保存文件
int saveFile(node *L){
	FILE *fpw = fopen("studentInfo.txt","w");
	if(fpw == NULL) return 0;
	
	node *p = L -> next;
	while(p != NULL){
		fprintf(fpw,"%d %s %s %d %d %d %d\n",p -> id, p->name,p->sex,p->ma,p->c,p->en,p->sum);
		p = p->next;
	}
	 



	return 1;
} 


