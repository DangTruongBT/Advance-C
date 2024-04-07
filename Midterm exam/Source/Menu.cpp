#define _CRT_SECURE_NO_WARNINGS
/*
* File: member.c
* Author: Dang Minh Truong
* Date: 5/4/2024
* Description: This file contains all the functions/methods for Membership management
*/
#include "Menu.h"

#define FILE_CSV "Residents_Information.csv"

void writeData(Member member) {
	FILE *file = fopen(FILE_CSV, "a"); // Open file

	if (file == NULL) {
		printf("Error opening file.\n");

	}

	// Write member information to the file in CSV format
	fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);

	fclose(file); // Close file
}
/*
* Description: Update member data from the member list to a file.
* Input: 
* Output: None.
*/

void updateMemberInFile(char *searchKey, Member new_member) {
	FILE *temp = fopen("temp.csv", "w"); // Open file temp

	if (temp == NULL) {
		printf("Error opening file.\n");
		return;
	}

	FILE *file = fopen(FILE_CSV, "r"); // Open file 

	if (file == NULL) {
		printf("Error opening file.\n");
		fclose(temp);
		return;
	}

	char line[1024];

	while (fgets(line, sizeof(line), file)) {

		char *uid = strtok(line, ",");
		char *roomNumber = strtok(NULL, ",");
		char *name = strtok(NULL, ",");
		char *licensePlate = strtok(NULL, ",");


		if (strcmp(uid, searchKey) == 0) {

			fprintf(temp, "%s,%s,%s,%s", new_member.uid, new_member.roomNumber, new_member.name, new_member.licensePlate);
		}
		else {

			fprintf(temp, "%s,%s,%s,%s", uid, roomNumber, name, licensePlate);
		}
	}

	fclose(file);
	fclose(temp);

	remove(FILE_CSV);
	rename("temp.csv", FILE_CSV);
}
/*
* Description: Display the main menu of the program.
* Input: None.
* Output: None.
*/
void Menu()
{
	printf("\n\n\t***Apartment Building Residents Information Management System***\n\n");
	printf("\t\t\tMAIN MENU\n");
	printf("\t\t=======================\n");
	printf("\t\t[1] Add A New Resident.\n");
	printf("\t\t[2] Show All Members.\n");
	printf("\t\t[3] Delete A Resident.\n");
	printf("\t\t[4] Update The Information of The Resident.\n");
	printf("\t\t[5] Search for A Resident according to UID/License Plate.\n");
	printf("\t\t[0] Exit the Program.\n");
	printf("\t\t=======================\n");
	printf("\t\tEnter The Choice: ");
}
void runProgram()
{
	MemberNode *head = NULL;
	Member member;
	char searchKey[20];
	char option;
	Menu();
	printf("Nhap lua chon cua ban (1-6): ");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
	{
		printf("Enter UID: ");
		scanf("%s", member.uid);
		printf("Enter Room Number: ");
		scanf("%s", member.roomNumber);
		printf("Enter Name: ");
		scanf("%s", member.name);
		printf("Enter License Plate: ");
		scanf("%s", member.licensePlate);
		addNode(&head, member);
		writeData(member);
		break;
	}
	case 2:
	{
		displayMembers(FILE_CSV);
		break;
	}
	case 3:
	{
		printf("Enter the UID of the resident to detele: ");
		scanf("%s", searchKey);
		deleteMember(FILE_CSV, searchKey);
		break;
	}
	case 4:
	{
		Member new_member;
		printf("Enter the UID/License Plate of the resident to edit: ");
		scanf("%s", searchKey);
		printf("Enter the new name: \n");
		scanf("%s", new_member.name);
		printf("Enter the new room number: \n");
		scanf("%s", new_member.roomNumber);
		printf("Enter the new license plate: \n");
		scanf("%s", new_member.licensePlate);
		editMember(head, searchKey, new_member);
		updateMemberInFile(searchKey, new_member);
		break;
	}
	case 5:
	{
		printf("Enter the UID of the resident to find: ");
		scanf("%s", searchKey);
		searchMember(FILE_CSV, searchKey);
		break;
	}
	case 6:
	{
		printf("Exiting program.\n");
		break;
	}
	default:
		printf("Invalid option.\n");


	}
}
