#include	<iostream>
#include	<fstream>
#include	<cstdlib>
#include	<cstdio>
#include	<ctime>
#include	"BST.h"
#include    "Student.h"

using namespace std;

bool readFile(const char *, BST *);
bool redundant(BST* , Student);
bool redundant2(BTNode*, Student);

int menu();

int main() {
	menu();

	cout << "\n\n";
	system("pause");
	return 0;
}


int menu() 
{
	BST t1, t2;
	bool quit = false;
	int choice;
	
	while (!quit) {
		system("cls");

		cout << " ___    ___        _        ______   ___      __      ___    ___   ________   ___      __   ____     ____           " << endl;
		cout << "|   \\  /   |      / \\      |__  __| |   \\    |  |    |   \\  /   | |  ______| |   \\    |  | |    |   |    |     " << endl;
		cout << "|    \\/    |     / _ \\        ||    |    \\   |  |    |    \\/    | | |______  |    \\   |  | |    |   |    |     " << endl;
		cout << "|          |    / / \\ \\       ||    |  |\\ \\  |  |    |          | |        | |  |\\ \\  |  | |    |   |    |    " << endl;
		cout << "|  |\\  /|  |   / /___\\ \\      ||    |  | \\ \\ |  |    |  |\\  /|  | |  ______| |  | \\ \\ |  | |    \\___/    | " << endl;
		cout << "|  | \\/ |  |  /   ___   \\   __||__  |  |  \\ \\|  |    |  | \\/ |  | | |______  |  |  \\ \\|  |  \\           /   " << endl;
		cout << "|__|    |__| /___|   |___\\ |______| |__|   \\____|    |__|    |__| |________| |__|   \\____|   \\_________/        " << endl;
		cout << endl;
		cout << "(1) Read data to BST" << endl;
		cout << "(2) Print deepest nodes" << endl;
		cout << "(3) Display student" << endl;
		cout << "(4) Clone Subtree" << endl;
		cout << "(5) Print Level Nodes" << endl;
		cout << "(6) Print Path" << endl;
		cout << "(7) Exit" << endl;
		cout << "Please select your choice:";
		cin >> choice;

		
		
		system("cls");
		if (choice == 1)
		{
			quit = false;
			cout << "||=========================================================================================================||  " << endl;
			cout << "||   _______                                   __       ______                       __                    ||  " << endl;
			cout << "||  |   _   \\   _______     ______       _____|  |     |      \\       ______     ___|  |___    ______      || " << endl;
			cout << "||  |  |_)   | |   _   |   /      \\     /   __   |     |   __  \\     /      \\    |___   ___|  /      \\     || " << endl;
			cout << "||  |        | |  |_|  |  /   _    \\    |  /  |  |     |  |  \\  \\   /   _    \\      |  |     /  _     \\    || " << endl;
			cout << "||  |       /  |  _____| |   |_|    \\   |  \\__|  |     |  |__/  |  |   |_|    \\     |  |    |  |_|     \\   ||  " << endl;
			cout << "||  |  | \\  \\  | |_____   \\     |\\   \\  |        |     |       /    \\     |\\   \\    |  |     \\     |\\   \\  || " << endl;
			cout << "||  |__|  \\__\\ |_______|   \\____| \\___\\ \\________/     |______/      \\____| \\___\\   |__|      \\____| \\___\\ || " << endl;
			cout << "||=========================================================================================================||   " << endl << endl;
			
			//Go to Read data to BST
			readFile("student.txt", &t1);
			
			system("PAUSE");
		}

		else if (choice == 2)
		{
			quit = false;
			cout << "||====================================================================================================================|| " << endl;
			cout << "||  _____    ______   ______   _______   ______   ______   _____     __   ___   _________   _____    ______   ______  ||  " << endl;
			cout << "|| |  __ \\  |  ____| |  ____| |  ___  | |  ____| |   ___| |__ __|   |  \\ |   | /  _____  \\ |  __ \\  |  ____| |   ___| || " << endl;
			cout << "|| | |  | | | |__    | |__    | |___| | | |__    |  |___    | |     |   \\|   | | /     \\ | | |  | | | |__    |  |___  || " << endl;
			cout << "|| | |  | | |    |   |    |   |   ____| |    |   |___   |   | |     |        | | |     | | | |  | | |    |   |___   | ||   " << endl;
			cout << "|| | |  | | |  __|   |  __|   |  |      |  __|       |  |   | |     |  |\\    | | |     | | | |  | | |  __|       |  | ||  " << endl;
			cout << "|| | |__| | | |____  | |____  |  |      | |____   ___|  |   | |     |  | \\   | | \\_____/ | | |__| | | |____   ___|  | || " << endl;
			cout << "|| |_____/  |______| |______| |__|      |______| |______|   |_|     |__|  \\__| \\_________/ |_____/  |______| |______| || " << endl;
			cout << "||====================================================================================================================||  " << endl;
			
			t1.deepestNodes();
			//Go to Print deepest nodes
			
			system("PAUSE");
		}

		else if (choice == 3)
		{
			int order, source;
			quit = false;
			do {
				system("cls");
				cout << "||===============================================================================================|| " << endl;
				cout << "|| ###    ### #### ###### #      ####### #       #    #### ##### #   # ###    #### #     # ##### || " << endl;
				cout << "|| #  #    #  #    #    # #      #     #  #     #     #      #   #   # #  #   #    ##    #   #   || " << endl;
				cout << "|| #   #   #  #    #    # #      #     #   #   #      #      #   #   # #   #  #    # #   #   #   || " << endl;
				cout << "|| #    #  #  #### ###### #      #######    ###       ####   #   #   # #    # #### #  #  #   #   ||" << endl;
				cout << "|| #   #   #     # #      #      #     #     #           #   #   #   # #   #  #    #   # #   #   ||" << endl;
				cout << "|| #  #    #     # #      #      #     #     #           #   #   #   # #  #   #    #    ##   #   || " << endl;
				cout << "|| ###    ### #### #      ###### #     #     #        ####   #   ##### ###    #### #     #   #   || " << endl;
				cout << "||===============================================================================================|| " << endl << endl;

				cout << "How would you like to print the order? (1 - ascending, 2 - descending): ";
				cin >> order;
				cout << "Where to display the output? (1 - screen, 2 - file): ";
				cin >> source;
			} while ((order != 1 && order != 2) || (source != 1 && source != 2));
			t1.display(order, source);
			//Go to Display student
			
			system("PAUSE");
		}

		else if (choice == 4)
		{
			Student subtree;
			quit = false;
			cout << "||============================================================================================================================||  " << endl;
			cout << "||   _______   __       _______   __     __   _____      ______   __    __   ______   _________   _________   _____   _____   ||  " << endl;
			cout << "||  /  _____| |  |     | _____ | |   \\  |  | |  ___|    |   ___| |  |  |  | |   _  \\ |___   ___| |   ____  | |  ___| |  ___|  ||  " << endl;
			cout << "|| /  /       |  |     | |    || |    \\ |  | | |___     |  |___  |  |  |  | |  |_| |    |  |     |  |____| | | |___  | |___   || " << endl;
			cout << "|| |  |       |  |     | |    || |     \\|  | |     |    |___   | |  |  |  | |  ____/    |  |     |   __  __| |     | |     |  ||" << endl;
			cout << "|| |  |       |  |     | |    || |  |\\     | |  ___|        |  | |  |  |  | |   _  \\    |  |     |  |  | |   |  ___| |  ___|  ||" << endl;
			cout << "||  \\ \\_____  |  |___  | |____|| |  | \\    | | |___      ___|  | |  |__|  | |  |_| |    |  |     |  |   | |  | |___  | |___   || " << endl;
			cout << "||   \\______| |______| |_______| |__|  \\.__| |_____|    |______| |________| |______/    |__|     |__|    |_| |_____| |_____|  || " << endl;
			cout << "||============================================================================================================================|| " << endl << endl;

			cout << "Which subtree you are going to clone? Please enter a student id: ";
			cin >> subtree.id;
			t2.CloneSubtree(t1, subtree);

			system("PAUSE");
			//clone subtree
			//Go to Clone Subtree
			//BST::CloneSubtree(t1,item);
			
		}

		else if (choice == 5)
		{
			quit = false;
			cout << "||==================================================================================================================|| " << endl;
			cout << "|| ##                                             ###      ###     ###                     ##                       || " << endl;
			cout << "|| ##                                             ###      #####   ###                     ##                       || " << endl;
			cout << "|| ##         ######    ##        ##    ######    ###      ######  ###    #######    ########    ######    ######## || " << endl;
			cout << "|| ##       ##      ##   ##      ##   ##      ##  ###      ###  ## ###   ###   ###  ##     ##  ##      ## #         ||" << endl;
			cout << "|| ##       ##########    ##    ##    ##########  ###      ###   #####  ###     ### ##     ##  #########   #######  ||" << endl;
			cout << "|| ##        ##            ##  ##      ##         ###      ###    ####   ###   ###  ##     ##   ##                # || " << endl;
			cout << "|| ########   #######        ##         #######   ###      ###     ###    #######    ########    #######  ########  || " << endl;
			cout << "||==================================================================================================================|| " << endl;

			t1.printLevelNodes();
			//Go to Print Level Nodes
			//BST::printLevelNodes();
			
			system("PAUSE");
		}

		else if (choice == 6)
		{	
			quit = false;
			cout << "||===================================================================================================================||" << endl;
			cout << "|| &&&&&&&     $$$$$$$     %%%%%%%%%   **     **  @@@@@@@@       !!!!!!!!          ;;        ^^^^^^^^^^  ???    ???  ||" << endl;
			cout << "|| &&     &    $$     $    %%%%%%%%%   ***    **  @@@@@@@@       !!      !!       ;;;;       ^^^^^^^^^^  ???    ???  ||" << endl;
			cout << "|| &&      &&  $$      $$     %%%      ****   **     @@          !!       !!     ;;  ;;          ^^      ???    ???  ||" << endl;
			cout << "|| &&     &    $$     $       %%%      ** **  **     @@          !!      !!     ;;    ;;         ^^      ??????????  ||" << endl;
			cout << "|| &&&&&&&     $$$$$$$        %%%      **  ** **     @@          !!!!!!!!      ;;      ;;        ^^      ??????????  ||" << endl;
			cout << "|| &&          $$  $$         %%%      **   ****     @@          !!           ;;;;;;;;;;;;       ^^      ???    ???  ||" << endl;
			cout << "|| &&          $$   $$     %%%%%%%%%   **    ***     @@          !!          ;;          ;;      ^^      ???    ???  ||" << endl;
			cout << "|| &&          $$    $$    %%%%%%%%%   **     **     @@          !!         ;;            ;;     ^^      ???    ???  ||" << endl;
			cout << "||===================================================================================================================||" << endl;
			
			t1.printPath();
			//Go to Print Path
			//BST::printPath();
			
			system("PAUSE");
		}
		
		else if (choice == 7)
		{
			//Exit the program
			quit = true;
			
			cout << "You have asked to exit the progam. \n" << endl;
			cout << "   __________   ___   ___    ___       __    __   ___  __     ___  ___   ________   __     __   ___      " << endl;
			cout << "  /___   ___/  /  /  /   /  /   |     /  | /  /  /  / / /     \\  \\/  /  /  ___  /  / /    / /  /  /     " << endl;
			cout << "     /  /     /  /__/   /  / _  |    /   |/  /  /  / /_/       \\    /  /  /  / /  / /    / /  /  /      " << endl;
			cout << "    /  /     /   __    /  / /_| |   /  |    /  /   ,<           /  /  /  /  / /  / /    / /  /  /       " << endl;
			cout << "   /  /     /   / /   /  / ___  |  /  /|   /  /   /| |         /  /  /  /__/ /  / /____/ /  /__/     " << endl;
			cout << "  /__/     /___/ /___/  /_/   |_| /__/ |__/  /___/ |_|        /__/   \\______/   \\_______/   ==          " << endl;

		}

		else
		{
			cout << "You have entered the wrong choice.Please enter a valid choice (1-7)" << endl;
			system("PAUSE");
			quit = false;
			continue;
		}
	}

	return 0;
}

bool readFile(const char* filename, BST* t1)
{
	ifstream infile(filename);
	Student stu;

	if (!infile)
	{
		cout << "Fail to read file!\n";
		return false;
	}
	else
	{
		char s[100];

		while (!infile.eof())
		{
			// read student id
			infile.getline(s, 14);
			infile.clear();
			infile >> stu.id;
			infile.ignore();

			// read student name
			infile.getline(s, 8);
			infile.clear();
			infile.getline(stu.name, sizeof(stu.name) - 1);

			// read student address
			infile.getline(s, 11);
			infile.clear();
			infile.getline(stu.address, sizeof(stu.address) - 1);

			// read student date of birth
			infile.getline(s, 7);
			infile.clear();
			infile.getline(stu.DOB, sizeof(stu.DOB) - 1);

			// read studnent's phone number
			infile.getline(s, 16);
			infile.clear();
			infile.getline(stu.phone_no, sizeof(stu.phone_no) - 1);

			// read student's course
			infile.getline(s, 10);
			infile.clear();
			infile.getline(stu.course, sizeof(stu.course) - 1);

			// read student's cgpa
			infile.getline(s, 8);
			infile.clear();
			infile >> stu.cgpa;
			infile.ignore();

			infile.getline(s, 99);

			if (!redundant(t1, stu))
				t1->insert(stu);
		}

		cout << t1->countNode() << " has successfully been recorded!\n\n";
		infile.close();
		return true;
	}
}

bool redundant2(BTNode* cur, Student student)
{
	if (cur == NULL)
		return false;
	if (cur->item.compare2(student))
	{
		int same = 1;
		if (strcmp(cur->item.name, student.name) == 0)	same++;
		if (strcmp(cur->item.address, student.address) == 0) same++;
		if (strcmp(cur->item.DOB, student.DOB) == 0) same++;
		if (strcmp(cur->item.phone_no, student.phone_no) == 0) same++;
		if (strcmp(cur->item.course, student.course) == 0) same++;
		if (cur->item.cgpa == student.cgpa) same++;

		if (same == 7)
			return true;
		return false;
	}
	else if (cur->item.compare1(student))
		return redundant2(cur->left, student);
	else
		return redundant2(cur->right, student);

}

bool redundant(BST* bst, Student student)
{
	BTNode* cur;
	if (bst->empty()) return false; // don't have Node will not has redundant data
	cur = bst->root;

	return redundant2(cur, student);
}
