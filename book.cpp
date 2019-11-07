#include<__msvc_all_public_headers.hpp>
using namespace std;	
class Classroom {
public:
	char room_name[200];
	char room_status[200] = "δ��׼";
};
class Application : public Classroom {
public:
	char student_name[200];
	char application_date[200];
	char exercise_name[200];
	Application(char* instu_name, char* indate, char* inexe_name, char* inroom_name);
	void show_application() {
		cout << "��ȷ������������Ϣ" << endl;
		cout << "����ѧ����" << this->student_name<<'\t';
		cout << "����ʹ�����ڣ� " << this->application_date<<'\t';
		cout << "����ԭ��/��;�� " << this->exercise_name<<'\t';
		cout << "������ң� " << this->room_name<<'\t';
	}
	void WriteData();
};
Application::Application(char* instu_name, char* indate, char* inexe_name, char* inroom_name) {
	strcpy_s(room_name, inroom_name);
	strcpy_s(student_name, instu_name);
	strcpy_s(application_date, indate);
	strcpy_s(exercise_name, inexe_name);
}

void Application::WriteData() {
	ofstream file;
	file.open("F://Applications.txt", ios::binary | ios::app);
	try {
		file.write(student_name, 200);
		file.write(application_date, 200);
		file.write(exercise_name, 200);
		file.write(room_name, 200);
		file.write(room_status, 200);
	}
	catch (...) {
		throw "file error occurred";
		file.close();
	}
	file.close();
}

void Welcome() {
	for (int i = 0; i < 2; i++) {
		cout << endl;
	}
	cout << "�ս�������ϵͳ" << endl;
}
void wait() {
	int judge;
	cout << endl;
	cout << "�������˵���1    �˳���0        ����������������������  "<<endl;
	cin >> judge;
	if (judge == 1)
		Welcome();
	else if (judge == 0)
		exit(0);
}
long GetFileLength(ifstream& ifs) {
	long tmppos;
	long respos;
	tmppos = ifs.tellg();
	ifs.seekg(0, ios::end);
	respos = ifs.tellg();
	ifs.seekg(tmppos, ios::beg);
	return respos;
}
void WaitView(int page) {
	char a;
	cin >> a;
	if (a == 'n') {
		page = page + 1;
	}
}

void ViewData(int selpage = 1) {
	int page = 0;
	int curpage = 0;
	int datacount = 0;
	char instu_name[200];
	char indate[200];
	char inexe_name[200];
	char inroom_name[200];
	char instatus[200];
	bool index = false;
	int filelength;
	curpage = selpage;
	ifstream file;
	file.open("F://Applications.txt", ios::binary);
	filelength = GetFileLength(file);
	datacount = filelength / (1000);
	if (datacount >= 1)index = true;
	page = datacount / 20 + 1;
	system("cls");
	cout << "���м�¼" << datacount << "    ";
	cout << "����ҳ��" << page << "   ";
	cout << "��ǰҳ��" << curpage << "  ";
	cout << "     n�� ��ʾ��һҳ  m������" << endl;
	cout << setw(5) << "index";
	cout << setw(10) << "stu";
	cout << setw(20) << "date" << setw(20) << "exe";
	cout << setw(15) << "room" << setw(15) << "status";
	cout << endl;
	try {
		file.seekg((curpage - 1) * 20 * (1000), ios::beg);
		if (!file.fail()) {
			for (int i = 1; i < 21; i++) {
				memset(instu_name, 0, 200);
				memset(indate, 0, 200);
				memset(inexe_name, 0,200);
				memset(inroom_name, 0, 200);
				memset(instatus, 0, 200);
				if (index) cout << setw(5) << (curpage - 1) * 20 + i;
				cout << setw(10);
				file.read(instu_name, 200);
				cout << instu_name;
				cout << setw(20);
				file.read(indate, 200);
				cout << indate;
				file.read(inexe_name, 200);
				cout << setw(20);
				cout << inexe_name;
				file.read(inroom_name, 200);
				cout << setw(15);
				cout << inroom_name;
				file.read(instatus, 200);
				cout << setw(15);
				cout << instatus;
				cout << endl;
				if (file.tellg() < 0)index = false;
				else index = true;
			}
		}
	}
	catch (...) {
		cout << "throw file exception" << endl;
		throw"file error occurred";
		file.close();
	}
	if (curpage < page) {
		curpage = curpage + 1;
		WaitView(curpage);
	}
	else WaitView(curpage);
	file.close();
}

	void ShowMenu() 
	{
	cout << endl;
	cout << "��ʼ��Ĳ�����" << endl;
	cout << endl;
	cout << "1������ս���" << endl;
	cout << endl;
	cout << "2���鿴����Ŀ¼" << endl;
	cout << endl;
	cout << "3���鿴������ս���Ŀ¼" << endl;
	cout << endl;
}
void applicate_room() {
	char instu_name[50], indate[20], inexe_name[50], inroom_name[50];
	int instatus;
	cout << "����������������:" << endl;
	cin >> instu_name;
	cout << "����������ʹ��ʱ��" << endl;
	cin >> indate;
	cout << "����������ԭ��" << endl;
	cin >> inexe_name;
	cout << "����������Ľ���" << endl;
	cin >> inroom_name;
	Application app(instu_name, indate, inexe_name, inroom_name);
	app.show_application();
	wait();
	app.WriteData();
	cout << "����ɹ�" << endl;
	system("pause");
	
}
void main() {
    
	Welcome();
	ShowMenu();
	applicate_room();
	ViewData();
    
	
	
}