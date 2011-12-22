///////////////////////////////////////////////////////////
//
// ProblemSolver.h: Head functions for all problems
// Copyright (c) 2011 - Mike Vegeto.  All Rights Reserved
//
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "qglobal.h"
#include <QString>
#include <vector>
#include "bigint-2010.04.30\BigInteger.hh"
using namespace std;

namespace Solvers {
	
	struct BinaryTreeResults {
		uint uValue,
			 uIndex;	
	};

	//////////////////////////////////////////////////////////////////////////
	//! Head functions for all problems
	class ProblemSolver {
	public:
		ProblemSolver( uint uProblem );		//!< Initialize ourselves
		
		//! Parses a text file for a grid of uints
		vector< vector<uint> > ParseFileForUints( QString strFileName, QString strSeparator= " " );
		
		//! Parses a text file for a vector of strings
		vector<QString> ParseFileForStrings( QString strFileName );
		
		//! Recursive binary tree lookahead, returns the sum of the lookahead from iRow and iElement
		BinaryTreeResults BinaryLookahead( uint uLookLength, uint iRow, uint iElement, vector< vector<uint> >& pBinaryTree );
		
		//! Recursively finds the number of paths given a width and height
		uint FindNumPaths( uint uHeight, uint uWidth );
		
		uint ProblemOne();					//!< A problem
		uint ProblemTwo();					//!< A problem
		unsigned long long int ProblemThree();	//!< A problem
		uint ProblemFour();					//!< A problem
		uint ProblemFive();					//!< A problem
		uint ProblemSix();					//!< A problem
		uint ProblemSeven();				//!< A Problem
		uint ProblemEight();				//!< A problem
		uint ProblemNine();					//!< A problem
		uint ProblemTen();					//!< A problem
		uint ProblemEleven();				//!< A problem
		uint ProblemTwelve();				//!< A problem
		uint ProblemThirteen();				//!< A problem
		uint ProblemFourteen();				//!< A problem
		uint ProblemFifteen();				//!< A problem
		uint ProblemSixteen();				//!< A problem
		uint ProblemSeventeen();			//!< A problem
		uint ProblemEighteen();				//!< A problem
		uint ProblemTwenty();				//!< A problem
		uint ProblemTwentyFive();			//!< A problem
		
		BigInteger* m_pBigInteger;
	}; // end class ProblemSolver
	
} // end namespace Solvers

