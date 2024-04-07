#define FILE_CSV "Residents_Information.csv"
#define _CRT_SECURE_NO_WARNINGS
#include "member.h"


MemberNode *CreateMemberNode(Member member) {
	MemberNode *newnode = (MemberNode*)malloc(sizeof(MemberNode));
	newnode->data = member;
	newnode->next = NULL;
	return newnode;
}

/*
* Function: addNode
* Description: Add a new member to the member list.
* Input: A pointer to a pointer to the head of the member list.
* Output: None.
*/

void addNode(MemberNode **head, Member member) {
	MemberNode *curr, *p;

	curr = CreateMemberNode(member);

	p = *head;
	if (*head == NULL) {
		*head = curr;
	}
	else {
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = curr;
	}
}
void deleteMember(const char* filename, const char* uid) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Error opening file for reading.\n");
		return;
	}

	FILE* tempFile = fopen("temp.csv", "w");
	if (tempFile == NULL) {
		fclose(file);
		printf("Error opening temporary file for writing.\n");
		return;
	}

	char line[1000]; // Assuming maximum length of line is 1000 characters
	int found = 0;
	while (fgets(line, sizeof(line), file)) {
		char tempUID[20];
		sscanf(line, "%[^,],", tempUID);
		if (strcmp(tempUID, uid) != 0) {
			fputs(line, tempFile);
		}
		else {
			found = 1;
		}
	}

	fclose(file);
	fclose(tempFile);

	if (!found) {
		printf("Member with UID %s not found.\n", uid);
		remove("temp.csv"); // Delete the temporary file
	}
	else {
		remove(filename); // Delete the original file
		rename("temp.csv", filename); // Rename the temporary file to the original name
		printf("Member with UID %s deleted successfully.\n", uid);
	}
}
void displayMembers(const char* filename) {
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		perror("Unable to open CSV file");
		return;
	}

	printf("List of Members:\n");
	printf("UID\t\tRoom\tName\t\tLicense Plate\n");

	char line[256];
	while (fgets(line, sizeof(line), file) != NULL) {
		char* token = strtok(line, ",");
		while (token != NULL) {
			printf("%s\t", token);
			token = strtok(NULL, ",");
		}
		printf("\n");
	}

	fclose(file);
}

int searchMember(const char* filename, char* searchKey)
{
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		printf("Unable to open CSV file");
		return -1;
	}

	Member member;
	char line[1000];
	while (fgets(line, sizeof(line), file) != NULL)
	{
		sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);
		if (strcmp(member.uid, searchKey) == 0)
		{

			printf("Resident found:\n");
			printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
			break;
		}
		else if (strcmp(member.licensePlate, searchKey) == 0)
		{
			printf("Resident found:\n");
			printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
			break;
		}
		break;
	}
	{
		printf("Resident not found\n");
	}
	return 1;
}

void editMember(MemberNode *head, char *searchKey, Member new_member) {
	MemberNode *current = head;
	int found = 0;

	while (current != NULL) {
		if (strcmp(current->data.uid, searchKey) == 0 || strcmp(current->data.licensePlate, searchKey) == 0) {
			// Find a resident that needs updating
			printf("Resident found:\n");
			printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n", current->data.uid, current->data.roomNumber, current->data.name, current->data.licensePlate);
			// Update resident information
			strcpy(current->data.name, new_member.name);
			strcpy(current->data.roomNumber, new_member.roomNumber);
			strcpy(current->data.licensePlate, new_member.licensePlate);
			printf("Resident information updated successfully.\n");
			found = 1;
			break;
		}
		current = current->next;
	}
	if (found == 1) {
		printf("Sua thanh cong! Sua tiep (Y/n)?");
	}

	if (!found) {
		printf("Resident with UID/License Plate %s not found.\n", searchKey);
	}




}


