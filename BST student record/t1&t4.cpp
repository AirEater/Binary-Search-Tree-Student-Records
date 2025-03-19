//#include	<iostream>
//#include	<fstream>
//#include	<cstdlib>
//#include	<cstdio>
//#include	<ctime>
//#include	"BST.h"
//#include    "Student.h"
//
//using namespace std;
//
//bool readFile(const char *, BST *);
//bool redundant(BST* , Student);
//bool redundant2(BTNode*, Student);
//int menu();
//
//int main() {
//	BST bst, cloneBST;
//	Student student;
//	readFile("student.txt", &bst);
//	student.id = 19;
//	cloneBST.CloneSubtree(bst, student);
//
//	system("pause");
//	return 0;
//}
//
//bool readFile(const char* filename, BST* t1)
//{
//	ifstream infile(filename);
//	Student stu;
//
//	if (!infile)
//	{
//		cout << "Fail to read file!\n";
//		return false;
//	}
//	else
//	{
//		char s[100];
//
//		while (!infile.eof())
//		{
//			// read student id
//			infile.getline(s, 14);
//			infile.clear();
//			infile >> stu.id;
//			infile.ignore();
//
//			// read student name
//			infile.getline(s, 8);
//			infile.clear();
//			infile.getline(stu.name, sizeof(stu.name) - 1);
//
//			// read student address
//			infile.getline(s, 11);
//			infile.clear();
//			infile.getline(stu.address, sizeof(stu.address) - 1);
//
//			// read student date of birth
//			infile.getline(s, 7);
//			infile.clear();
//			infile.getline(stu.DOB, sizeof(stu.DOB) - 1);
//
//			// read studnent's phone number
//			infile.getline(s, 16);
//			infile.clear();
//			infile.getline(stu.phone_no, sizeof(stu.phone_no) - 1);
//
//			// read student's course
//			infile.getline(s, 10);
//			infile.clear();
//			infile.getline(stu.course, sizeof(stu.course) - 1);
//
//			// read student's cgpa
//			infile.getline(s, 8);
//			infile.clear();
//			infile >> stu.cgpa;
//			infile.ignore();
//
//			infile.getline(s,99);
//
//			if(!redundant(t1, stu))
//				t1->insert(stu);
//		}
//
//		cout << t1->countNode() << " has successfully been recorded!\n\n";
//		infile.close();
//		return true;
//	}
//}
//
//bool redundant2(BTNode* cur, Student student)
//{
//	if (cur == NULL)
//		return false;
//	if (cur->item.compare2(student))
//	{
//		int same = 1;
//		if (strcmp(cur->item.name,student.name) == 0)	same++;
//		if (strcmp(cur->item.address, student.address) == 0) same++;
//		if (strcmp(cur->item.DOB, student.DOB) == 0 ) same++;
//		if (strcmp(cur->item.phone_no, student.phone_no) == 0) same++;
//		if (strcmp(cur->item.course, student.course) == 0) same++;
//		if (cur->item.cgpa == student.cgpa) same++;
//
//		if (same == 7)
//			return true;
//		return false;
//	}
//	else if (cur->item.compare1(student))
//		return redundant2(cur->left, student);
//	else
//		return redundant2(cur->right, student);
//
//}
//
//bool redundant(BST *bst, Student student)
//{
//	BTNode* cur;
//	if (bst->empty()) return false; // don't have Node will not has redundant data
//	cur = bst->root;
//
//	return redundant2(cur, student);
//}
