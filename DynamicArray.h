#pragma once //<- 최신 버전 redefine 안되게 해주는 것

#ifndef __DynamicArray_H__ // <- 옛날 버전 정의 안되어 있으면 밑에 #define하고 밑에 클래스 해라
#define __DynamicArray_H__


class DynamicArray
{
public:
	DynamicArray()
	{
		Size = 0;
		Data = nullptr;
		//Data = new int[Size];
	}
	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}

	void PushBack(int InValue)
	{
		Size++;
		//Capacity 크기 조절
		if (Size >= Capacity)
		{
			IncreasCapacity();
		}
		//영역 할당
		int* NewData = new int[Capacity];

		//원본 복제
		for (int i = 0; i < Size -1; i++)
		{
			NewData[i] = Data[i];
		}
		// 새로운 값 넣어줌
		NewData[Size - 1] = InValue;

		//원본 주소할당 취소
		delete[] Data;
		
		//원래 데이터에 새로운 데이터 복사
		Data = NewData;





		////늘어난 영역만큼 새로 할당
		//int* NewData = new int[Size];

		////원본 복제
		//for (int i = 0; i < Size - 1; ++i)
		//{
		//	NewData[i] = Data[i];
		//}

		//// 새로 들어온 값을 넣는다.
		//NewData[Size -1] = InValue;

		//// 원래 있던걸 지운다.
		//delete[] Data;

		//// 원래 데이터의 포인터에 새 데이터 포인터 연결
		//Data = NewData;
	}

	// 해당 Index의 값을 삭제
	void Pop(int Index)
	{
		// 새로운 주소 할당
		int* NewData = new int[Size];

		//빈 값이면 반환
		if (Size == 0)
		{
			return;
		}

		// 새로운 곳에 값 다 옮김 i번째 index만 빼고
		for (int i = 0; i < Size; i++)
		{
			if (i < Index)
			{
				NewData[i] = Data[i];

			}
			else if(i> Index)
			{
				NewData[i - 1] = Data[i];
			}
		}

		// 원본 데이터 주소 할당 취소
		delete[] Data;
		
		// 원본데이터에 새로운 데이터 복사
		Data = NewData;

		Size--;

	}

	inline int GetSize()
	{
		return Size;
	}

	// operator overload 키워드를 연산자로 재정의 할거야
	int operator[](int Index) const
	{
		return Data[Index];
	}

	inline int GetCapacity()
	{
		return Capacity;
	}

	void IncreasCapacity()
	{
		Capacity *= 2;
	}

private:
	int* Data;
	int Size = 0;
	int Capacity = 1;

};

#endif // !__DynamicArray_H__

