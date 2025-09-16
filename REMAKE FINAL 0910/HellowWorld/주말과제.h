#pragma once



/// <summary>
/// ��¥�� �Է��ϸ� ������ �˷��ִ� �Լ�
/// </summary>
/// <param name="Year">���</param>
/// <param name="Month">���</param>
/// <param name="Day">����</param>
/// <returns>�ش� ���� ���ڿ�</returns>
const char* GetDayOfWeek(int Year, int Month, int Day);

/// <summary>
/// ���� �Ǻ� �Լ�
/// </summary>
/// <param name="Year">Ȯ���� ����</param>
/// <returns>�����̸� true, �ƴϸ� false</returns>
bool IsLeap(int Year);

/// <summary>
/// 1�� 1�� 1�Ͽ��� ��ĥ�� �������� ����ϴ� �Լ�
/// </summary>
/// <param name="Year">���</param>
/// <param name="Month">���</param>
/// <param name="Day">����</param>
/// <returns>��ü �ϼ�</returns>
int GetTotalDays(int Year, int Month, int Day);
