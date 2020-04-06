#ifndef C_LINE_H
#define C_LINE_H

template <class MyTypeElement>
class CLine
{
private:
	MyTypeElement* pLINMATArray;
	unsigned int uiLINSize;

public:
	/***************************************************************
	Default constructor overload
	****************************************************************
	Input: None
	Requirements: None
	Output: Cline class instance
	Effect: Object is initialized with pointer equal to NULL and size = 0
	****************************************************************/
	CLine();

	/***************************************************************
	Copy constructor overload
	****************************************************************
	Input: Instance of CLine object to copy
	Requirements: None
	Output: Cline class instance
	Effect: A deep copy of provided object is created
	****************************************************************/
	CLine(const CLine<MyTypeElement>& LINcopyParam);

	/***************************************************************
	Comfort constructor accepting the size of the new CLine instance
	****************************************************************
	Input: Size of the instance to be created
	Requirements: None
	Output: Cline class instances
	Effect: A new instance with the array length of uiSize is created
	****************************************************************/
	CLine(unsigned int uiSize);


	/***************************************************************
	Destructor overload
	****************************************************************
	Input: None
	Requirements: None
	Output: None
	Effect: Deallocates the array and deletes this object
	****************************************************************/
	~Cline();

	// Returns the size of the array
	inline unsigned int LINGetLineSize() const { return uiLINSize; }

	/***************************************************************
	Const overload of the [] operator that return the element at the uiPosition of this array
	****************************************************************
	Input: Postition of element to get
	Requirements: None
	Output: MyTypeElement that is at the uiPosition of this object
	Effect: Return the value of the element at provided position or
		throws the exception if the index is out of array's bounds
	****************************************************************/
	MyTypeElement operator[] (unsigned int uiPosition) const {
		if (uiPosition >= uiLINSize) throw CException;
		return pLINMATArray[uiPosition];
	};

	/***************************************************************
	Overload of the [] operator allow to modify the element at the uiPosition on this object
	****************************************************************
	Input: Postition of element to modify
	Requirements: None
	Output: Reference to the MyTypeElement at the uiPosition of this object
	Effect: Return the value of the reference at provided position or
		throws the exception if the index is out of array's bounds
	****************************************************************/
	MyTypeElement& operator[] (unsigned int uiPosition) {
		if (uiPosition >= uiLINSize) throw CException;
		return pLINMATArray[uiPosition];
	};


};

template<class MyTypeElement>
CLine<MyTypeElement>::CLine()
{
	pLINMATArray = nullptr;
	uiLINSize = 0;
}

template<class MyTypeElement>
CLine<MyTypeElement>::CLine(const CLine<MyTypeElement>& LINcopyParam)
{
	uiLINSize = LINcopyParam.uiLINSize;
	pLINMATArray = new MyTypeElement[uiLINSize];

	for (int iLoop = 0; iLoop < pLINMATArray; iLoop++) {
		pLINMATArray[iLoop] = LINcopyParam.pLINMATArray[iLoop];
	}
}

template<class MyTypeElement>
CLine<MyTypeElement>::CLine(unsigned int uiSize)
{
	uiLINSize = uiSize;
	pLINMATArray = new MyTypeElement[uiLINSize];
}

#endif
