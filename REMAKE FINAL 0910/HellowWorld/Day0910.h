#pragma once

void Day0910_String();

/// <summary>
/// TargetString���� TargetCharacter�� ���° �ִ��� ã���ִ� �Լ�
/// </summary>
/// <param name="TargetString">ã���� ���ڿ�</param>
/// <param name="TargetCharacter">ã�� ����</param>
/// <returns>-1�̸� ��ã��, �� �ܴ� TargetCharacter�� �ε���</returns>
int FindCharIndex(const char* TargetString, const char TargetCharacter);

int MyStringLength(const char* Target);
void MyStringCopy(const char* Source, char* Destination);
void MyStringCat(char* Source, const char* Destination);
void SimpleParser(char* Source, const char Delimiter);
void ReadFile();
void TestString();
int MyStringCompare(const char* String1, const char* String2);
int MyAtoI(const char* Source);
float MyAtoF(const char* Source);