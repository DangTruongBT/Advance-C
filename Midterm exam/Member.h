#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
* File: member.h
* Author: Dang Minh Truong
* Date: 5/4/2024
* Description: This file contains all the functions prototypes for Membership management library.
*/
#ifndef __MEMBER_H
#define __MEMBER_H
#define FILE_CSV "Residents_Information.csv"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Member {
	char uid[20];
	char roomNumber[10];
	char name[50];
	char licensePlate[20];
} Member;

typedef struct MemberNode {
	Member data;
	struct MemberNode* next;
} MemberNode;

MemberNode *CreateMemberNode(Member member);
void addNode(MemberNode **head, Member member);
void deleteMember(const char* filename, const char* uid);
int searchMember(const char* filename, char* searchKey);
void displayMembers(const char* filename);
void editMember(MemberNode *head, char *searchKey, Member new_member);
#endif