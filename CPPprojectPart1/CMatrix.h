#ifndef C_MATRIX_H
#define C_MATRIX_H

#include "CLine.h"

template <class MyTypeElement>
class CMatrix
{
private:
	unsigned int uiMATColumnSize;
	unsigned int uiMATLineSize;
	CLine<MyTypeElement>* pLINMATArray;


public:
	/***************************************************************
	Default constructor overload assigning NULL to the array pointer and 0 to the sizes
	****************************************************************
	Input: None
	Requirements: None
	Output: CMatrix class instance
	Effect: Object is initialized with pointer equal to NULL and element value = 0
	****************************************************************/
	CMatrix();

	/***************************************************************
	Copy constructor overload
	****************************************************************
	Input: MATcopyParam
	Requirements: None
	Output: CMatrix class instance
	Effect: Object is initialized with a new pointer that have the same value that the one given in parameter and element value = the element value given in parameter
	****************************************************************/
	CMatrix(const CMatrix<MyTypeElement> & MATcopyParam);

	/***************************************************************
	Confort constructor overload
	****************************************************************
	Input: pMatrixFile
	Requirements: Make sure that the path of the file is valid
	Output: CMatrix class instance
	Effect: Object is initialized thanks to the file given in parameter
	****************************************************************/
	CMatrix(char* pMatrixFile);

	/***************************************************************
	Destructor overload
	****************************************************************
	Input: None
	Requirements: None
	Output: None
	Effect: Free the pointer before the destruction of the object
	****************************************************************/
	~CMatrix();

	/***************************************************************
	Getter for the column size of the Matrix
	****************************************************************
	Input: None
	Requirements: None
	Output: unsigned int the size of the column
	Effect: return an unsigned int that is the column size
	****************************************************************/
	unsigned int MATGetColumnSize();

	/***************************************************************
	Getter for the line size of the Matrix
	****************************************************************
	Input: None
	Requirements: None
	Output: unsigned int the size of the line
	Effect: return an unsigned int that is the line size
	****************************************************************/
	unsigned int MATGetLineSize();

	/***************************************************************
	Method to apply the transpose operation to a Matrix
	****************************************************************
	Input: None
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix<MyTypeElement> MATTranspose();

	/***************************************************************
	Overload of the operator [] that return the uilinePosition Line
	****************************************************************
	Input: uilinePosition the position we are looking at
	Requirements: uilinePosition have to be <= to uiMATColumnSize of the object in which we use it
	Output: CLine class instance
	Effect: Return the instance of the CLine object
	****************************************************************/
	CLine operator[](unsigned int uilinePosition);

	/***************************************************************
	Overload of the operator [] that allow to modify the uilinePosition Line Element
	****************************************************************
	Input: uilinePosition the position we are looking at
	Requirements: uilinePosition have to be <= to uiMATColumnSize of the object in which we use it
	Output: CLine class instance
	Effect: Return the instance of the CLine object
	****************************************************************/
	CLine& operator[](unsigned int uilinePosition);

	/***************************************************************
	Overload of the operator + that allow to add 2 Matrix
	****************************************************************
	Input: MATParam the matrix we want to add
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix<MyTypeElement> operator+(CMatrix MATParam);

	/***************************************************************
	Overload of the operator * that allow to multiply 2 Matrix
	****************************************************************
	Input: MATParam the matrix we want to multiply
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix operator*(CMatrix MATParam);

	/***************************************************************
	Overload of the operator / that allow to divide a Matrix by a scalar constant
	****************************************************************
	Input: dScalar the constant we want to devide by
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix operator/(double dScalar);

	/***************************************************************
	Overload of the operator * that allow to multiply a Matrix by a scalar constant
	****************************************************************
	Input: dScalar the constant we want to multiply by
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix operator*(double dScalar);

	/***************************************************************
	Overload of the operator = assign a new value thanks to an existing matrix
	****************************************************************
	Input: MATParam the matrix we want to copy
	Requirements: None
	Output: CMatrix class instance
	Effect: Assign to the matrix is new value
	****************************************************************/
	CMatrix operator=(CMatrix MATParam);

	/***************************************************************
	Overload of the operator * that allow to multiply a scalar constant by a Matrix
	****************************************************************
	Input: dScalar the constant we want to be multiply by the matrix MATParam
	Requirements: None
	Output: CMatrix class instance
	Effect: Create and allocate a new instance of the Matrix after the operation
	****************************************************************/
	CMatrix operator*(double dScalar, CMatrix MATParam);

};
#endif

template<class MyTypeElement>
inline CMatrix<MyTypeElement>::CMatrix()
{
	uiMATLineSize = 0;
	uiMATColumnSize = 0;
	pLINMATArray = NULL;
}


template<class MyTypeElement>
inline CMatrix<MyTypeElement>::CMatrix(const CMatrix<MyTypeElement>& MATcopyParam)
{

}

/*
template<class MyTypeElement>
inline CMatrix<MyTypeElement>::CMatrix(char * pMatrixFile)
{

}
*/

template<class MyTypeElement>
inline CMatrix<MyTypeElement>::~CMatrix()
{

}

template<class MyTypeElement>
inline unsigned int CMatrix<MyTypeElement>::MATGetColumnSize()
{
	return uiMATColumnSize;
}

template<class MyTypeElement>
inline unsigned int CMatrix<MyTypeElement>::MATGetLineSize()
{
	return uiMATLineSize;
}
