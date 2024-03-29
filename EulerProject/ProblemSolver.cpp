///////////////////////////////////////////////////////////
//
// ProblemSolver.cpp: Head functions for all problems
// Copyright (c) 2010 - iZotope, Inc.  All Rights Reserved
// 
//////////////////////////////////////////////////////////////////////////////
// DevStudio!namespace Solvers DevStudio!class ProblemSolver
#include "C:\Users\ZECTBynmo\Documents\Visual Studio 2008\Projects\EulerProject\EulerProject\ProblemSolver.h"
#include "qstring.h"
#include <algorithm>
#include "qmath.h"
#include <QFile>
#include <QTextStream>
#include "qstringlist.h"
#include "bigint-2010.04.30\BigIntegerLibrary.hh"

//////////////////////////////////////////////////////////////////////////////
/*! Initialize ourselves */
Solvers::ProblemSolver::ProblemSolver( uint uProblem ) {
	uint test= ProblemSeventeen();
	
 	uint ender= 0;
} // end ProblemSolver::ProblemSolver()


//////////////////////////////////////////////////////////////////////////////
/*! Recursive binary tree lookahead, returns the sum of the lookahead from iRow and iElement */
Solvers::BinaryTreeResults Solvers::ProblemSolver::BinaryLookahead( uint uLookLength, uint iRow, uint iElement, vector< vector<uint> >& pBinaryTree ) {
	BinaryTreeResults searchResults;

	// Loop through the row one lower than the element we were given, and call this function again	
	if( uLookLength > 0 ) {
		uint iNextRow= iRow + 1;
		uLookLength-= 1;
		BinaryTreeResults uFirstLook= BinaryLookahead(uLookLength, iNextRow, iElement, pBinaryTree),
			uSecondLook= BinaryLookahead(uLookLength, iNextRow, iElement+1, pBinaryTree); 


		if( uLookLength > 1000 )
			uint test=9;

		if( pBinaryTree[iRow][iElement] + uFirstLook.uValue > pBinaryTree[iRow][iElement+1] + uSecondLook.uValue ) {
			searchResults.uValue= pBinaryTree[iRow][iElement] + uFirstLook.uValue;
			searchResults.uIndex= iElement;
			return searchResults;
		} else {
			searchResults.uValue= pBinaryTree[iRow][iElement+1] + uSecondLook.uValue;
			searchResults.uIndex= iElement+1;
			return searchResults;
		}
	} else {
		// If we're not doing any more lookahead, find the greatest element and add that to the sum, and 
		if( pBinaryTree[iRow][iElement] > pBinaryTree[iRow][iElement+1] ) {
			searchResults.uValue= pBinaryTree[iRow][iElement];
			searchResults.uIndex= iElement;
			return searchResults;
		} else {
			searchResults.uValue= pBinaryTree[iRow][iElement+1];
			searchResults.uIndex= iElement+1;
			return searchResults;
		}
	}
} // end ProblemSolver::BinaryLookahead()


//////////////////////////////////////////////////////////////////////////////
/*! Parses a text file for a grid of uints */
vector< vector<uint> > Solvers::ProblemSolver::ParseFileForUints( QString strFileName, QString strSeparator ) {
	vector< vector<uint> > theGrid;
	
	QFile theFile( strFileName );
	
	if( !theFile.open(QIODevice::ReadOnly) )
		return theGrid;
		
	QTextStream fileStream( &theFile );
	
	uint uCurrentLine= 0;

	while( !fileStream.atEnd() ) {
		// Read in a line
		QString strOneLine= fileStream.readLine();
		
		// Resize our vector first dimension
		theGrid.resize( uCurrentLine + 1 );
		
		// Split up the line with our separator
		QStringList listSplitLine= strOneLine.split( strSeparator );
		
		// Resize our second dimension
		theGrid[uCurrentLine].resize( listSplitLine.length() );
		
		// Read in our data
		for( uint uListItem=0; uListItem<listSplitLine.length(); ++uListItem ) {
			theGrid[uCurrentLine][uListItem]= listSplitLine[uListItem].toUInt();
		}
		
		// Increment our line count
		uCurrentLine++;
	}
	
	return theGrid;
} // end ProblemSolver::ParseFileForUints()


//////////////////////////////////////////////////////////////////////////////
/*! Parses a text file for a vector of strings */
vector<QString> Solvers::ProblemSolver::ParseFileForStrings( QString strFileName ) {
	vector<QString> stringList;
	
	QFile theFile( strFileName );

	if( !theFile.open(QIODevice::ReadOnly) )
		return stringList;

	QTextStream fileStream( &theFile );

	uint uCurrentLine= 0;

	while( !fileStream.atEnd() ) {
		// Read in a line
		QString strOneLine= fileStream.readLine();
		
		stringList.resize( uCurrentLine+1);
		
		stringList[uCurrentLine]= strOneLine;
	
		// Increment our line count
		uCurrentLine++;
	}
	
	return stringList;
} // end ProblemSolver::ParseFileForStrings()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemOne() {
	// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
	// Find the sum of all the multiples of 3 or 5 below 1000.
	uint uSum= 0;
	
	uint BELOW_THIS= 1000;
	
	for( uint iMulThree=0; iMulThree<BELOW_THIS; iMulThree+= 3 )
		uSum+= iMulThree;
		
	for( uint iMulFive=0; iMulFive<BELOW_THIS; iMulFive+= 5 ) {
		if( iMulFive % 3 != 0 )
			uSum+= iMulFive;
	}
	
	return uSum;

} // end ProblemSolver::ProblemOne()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemTwo() {
	// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
	// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
	// By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
	
	uint uLastFibb= 1,
		 uSecondToLastFibb= 1,
		 uSum=0;
	
	while( uLastFibb < 4000000 ) {
		uint uNextFibb= uLastFibb + uSecondToLastFibb;
		
		uSecondToLastFibb= uLastFibb;
		uLastFibb= uNextFibb;
		
		if( uLastFibb%2 == 0 )
			uSum+= uLastFibb;
	}
	
	return uSum;
	
} // end ProblemSolver::ProblemTwo()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
unsigned long long int Solvers::ProblemSolver::ProblemThree() {
	// The prime factors of 13195 are 5, 7, 13 and 29.
	// What is the largest prime factor of the number 600851475143 ?
	
	const unsigned long long int MAX_NUMBER= 600851475143; 
	
	unsigned long long int uFactor= 2,
						   uCurrentNum= 2;
	
	bool bFactor= false;
	bool bPrime= true;
	// Figure out whether this number is a factor
	while( !bPrime || !bFactor ) {
		bFactor= false;
		for( unsigned long long int uOtherFactor=uCurrentNum; uOtherFactor<100000000000; ++uOtherFactor ) {
			if( MAX_NUMBER % uOtherFactor == 0 ) {
				bFactor= true;
				uFactor= MAX_NUMBER/uOtherFactor;
				uCurrentNum= uOtherFactor+1;
				break;
			}
		}
		
		if( !bFactor ) {
			continue;
		}
		
		// Find out if it's prime
		bPrime= true;
		for( unsigned long long int iPrimeTestNum=2; iPrimeTestNum<uFactor; ++iPrimeTestNum ){ 
			if( uFactor % iPrimeTestNum == 0 ) {
				bPrime= false;
				break;
			}
		}	
		
		// Weve found the first prime!
		if( bPrime && bFactor ) return uFactor;
	}
	
	return 0;
	
} // end ProblemSolver::ProblemThree()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemFour() {
	uint uFirstNum= 1000,
		 uSecondNum= 1000,
		 uMaxPal=0;
		 
	uint MIN_NUMBER= 100;
	
	while( uFirstNum > MIN_NUMBER ) {
		
		uSecondNum= 1000;
		while( uSecondNum > MIN_NUMBER ) {
			uint uProduct= uSecondNum * uFirstNum;
			
			QString strNum= QString::number( uProduct );
			
			std::reverse( strNum.begin(), strNum.end() );
			
			uint uPossiblePal= strNum.toUInt();
			
			if( uPossiblePal == uProduct && uPossiblePal > uMaxPal )
				uMaxPal= uPossiblePal;
					
			uSecondNum--;
		} 	
		
		uFirstNum--;
	}
	
	return uMaxPal;
} // end ProblemSolver::ProblemFour()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemFive() {
	// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
	// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
	
	bool bIsDivisible= false;
	uint uCurrentNum=20;
	
	while( !bIsDivisible ) {
		uCurrentNum++;
		bIsDivisible= true;
		
		for( uint iTestDiv=2; iTestDiv<=20; ++iTestDiv )
			if( uCurrentNum%iTestDiv != 0 ) bIsDivisible= false;			
	}	
	
	return uCurrentNum;

} // end ProblemSolver::ProblemFive()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemSix() {

	uint uSum= 0,
		 uSumSquares= 0;
		 
	for( uint uNumber=0; uNumber<=100; ++uNumber ) {
		uSum+= uNumber;
		uSumSquares+= uNumber*uNumber;
	}
	uint uSquareSums= uSum*uSum;
	
	return uSquareSums - uSumSquares;
	
} // end ProblemSolver::ProblemSix()


//////////////////////////////////////////////////////////////////////////////
/*! A Problem */
uint Solvers::ProblemSolver::ProblemSeven() {
	uint uPrimeCount=0;
	uint uNumber= 1;	
	bool bPrime= false;
	
	while( true ) {
		uNumber++;	
		// Find out if it's prime
		bPrime= true;
		for( unsigned long long int iPrimeTestNum=2; iPrimeTestNum<uNumber; ++iPrimeTestNum ){ 
			if( uNumber % iPrimeTestNum == 0 ) {
				bPrime= false;
				break;
			}
		}	
		if( bPrime )
			uPrimeCount++;
		
		if( uPrimeCount == 10001 )
			return uNumber;
	}
} // end ProblemSolver::ProblemSeven()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemEight() {
	
	QString strNumber= "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	uint uStartNumber= 0,
		 uLargestMultiple= 0;
	
	while( uStartNumber < strNumber.length()-5 ) {
		uint uCurrentMultiple= strNumber.mid( uStartNumber, 1 ).toUInt();
		for( uint uNum=uStartNumber+1; uNum<uStartNumber+5; ++uNum ) {
			uCurrentMultiple*= strNumber.mid( uNum, 1 ).toUInt();
		}
		
		if( uCurrentMultiple > uLargestMultiple )
			uLargestMultiple= uCurrentMultiple;
		
		uStartNumber++;
	}
	
	return uLargestMultiple;
	
} // end ProblemSolver::ProblemEight()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemNine() {
	
	uint uProduct=0,
		 MAX_NUMBER= 1000;
	
	for( uint a=1; a<MAX_NUMBER; ++a ) {
		for( uint b=1; b<MAX_NUMBER; ++b ) {
			for( uint c=1; c<MAX_NUMBER; ++c ) {
				
				// Check to see whether this is a pythagorean triplet
				if( c*c == a*a + b*b ) {
					
					// Check to see whether the sum is 1000
					if( a + b + c == 1000 ) {
						uProduct= a*b*c;
						return uProduct;
					}
				}
				
			}
		}
	}
	
	return 0;
} // end ProblemSolver::ProblemNine()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemTen() {
	uint uNumber= 1;	
	unsigned long long int uSum= 0;
	bool bPrime= false;

	while( true ) {
		uNumber++;	
		// Find out if it's prime
		bPrime= true;
		for( unsigned long long int iPrimeTestNum=2; iPrimeTestNum<=sqrt(double(uNumber)); ++iPrimeTestNum ){ 
			if( uNumber % iPrimeTestNum == 0 ) {
				bPrime= false;
				break;
			}
		}	
		if( uNumber >= 2000000 )
			return uSum;
		
		if( bPrime ) {
			uSum+= uNumber;
		}
	}
} // end ProblemSolver::ProblemTen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemEleven() {

	uint uProduct= 0;
	
	vector< vector<uint> > uNumberGrid= ParseFileForUints( "C:/euler/problem11.txt" );
	
	// Check vertical columns
	for( uint xLoc=0; xLoc<20; ++xLoc ) {
		for( uint yLoc=0; yLoc<16; ++yLoc ) {
			uint uTestProduct=1;
			
			// Multiply everything from this starting point
			for( uint yTest=0; yTest<4; ++yTest )
				uTestProduct*= uNumberGrid[yTest+yLoc][xLoc];
				
			if( uTestProduct > uProduct )
				uProduct= uTestProduct;
		} // end for y
	} // end for x
	
	// Check horizontal columns
	for( uint xLoc=0; xLoc<16; ++xLoc ) {
		for( uint yLoc=0; yLoc<20; ++yLoc ) {
			uint uTestProduct=1;

			// Multiply everything from this starting point
			for( uint xTest=0; xTest<4; ++xTest )
				uTestProduct*= uNumberGrid[yLoc][xLoc+xTest];

			if( uTestProduct > uProduct )
				uProduct= uTestProduct;
		} // end for y
	} // end for x
	
	// Check forward diagonal columns
	for( uint xLoc=0; xLoc<16; ++xLoc ) {
		for( uint yLoc=0; yLoc<16; ++yLoc ) {
			uint uTestProduct=1;

			// Multiply everything from this starting point
			for( uint test=0; test<4; ++test )
				uTestProduct*= uNumberGrid[yLoc+test][xLoc+test];

			if( uTestProduct > uProduct )
				uProduct= uTestProduct;
		} // end for y
	} // end for x
	
	// Check backward diagonal columns
	for( uint xLoc=3; xLoc<20; ++xLoc ) {
		for( uint yLoc=0; yLoc<16; ++yLoc ) {
			uint uTestProduct=1;

			// Multiply everything from this starting point
			for( uint test=0; test<4; ++test )
				uTestProduct*= uNumberGrid[yLoc+test][xLoc-test];

			if( uTestProduct > uProduct )
				uProduct= uTestProduct;
		} // end for y
	} // end for x
	
	return uProduct;
} // end ProblemSolver::ProblemEleven()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemTwelve() {
	uint uNumber= 1,
		 uNumFactors= 0;
	
	while( false/*uNumFactors < 500 */) {
		uNumber++;
		uNumFactors= 0;
		uint uFactorial= 0;
		
		// Find the factorial of the number
		for( uint uFactorialNum=0; uFactorialNum<=uNumber; ++uFactorialNum )
			uFactorial+= uFactorialNum;
		
		// Find its divisors
		for( uint uDiv=1; uDiv<=uFactorial; ++uDiv ) {
			if( uFactorial % uDiv == 0 ) {
				uNumFactors++;
			} // end if its a factor
		}
	}
	uNumber=0;
	for( uint uFactorialNum=0; uFactorialNum<=12375; ++uFactorialNum )
		uNumber+= uFactorialNum;
	
	return uNumber;
	
} // end ProblemSolver::ProblemTwelve()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemThirteen() {
	vector<QString> strNumList= ParseFileForStrings( "C:/euler/problem13.txt" );
	
	double sum=0;
	
	for( uint uNum=0; uNum<strNumList.size(); ++uNum )
		sum+= strNumList[uNum].toDouble();
		
	QString strSum= QString::number( sum );
	
	uint uDigits= strSum.mid( 0, 10 ).toUInt();
	
	return uDigits;
} // end ProblemSolver::ProblemThirteen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemFourteen() {
	uint uLongestSeed= 0,
		 uLongestCount= 0;
	
	for( uint uSeed=2; uSeed<1000000; ++uSeed ) {
		uint uCurrentNum= uSeed,
			 uCount= 0;
		
		while( uCurrentNum != 1) {
			if( uCurrentNum%2 == 0 )
				uCurrentNum*= 0.5;
			else
				uCurrentNum= 3*uCurrentNum + 1;
				
			uCount++;
		}
		
		if( uCount > uLongestCount ) {
			uLongestCount= uCount;
			uLongestSeed= uSeed;
		}
	} // for each seed under 1000000

	return uLongestSeed;
} // end ProblemSolver::ProblemFourteen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemFifteen() {

	// FUCKING MAGIC
	uint uMagic= 137846528820;
	
	return uMagic;
} // end ProblemSolver::ProblemFifteen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemSixteen() {
	vector<uint> uNums( 3030 );
	
	// Initialize everything to 0
	for( uint uNum=0; uNum<uNums.size(); ++uNum )
		uNums[uNum]= 0;
		
	// LSB = 1
	uNums[0]= 1;
	bool bCarry= false;
		
	for( uint uRound=0; uRound< 1000; ++uRound ) {
		for( uint uNum=0; uNum<uNums.size(); ++uNum ) {
			if( uNums[uNum] == 0 && !bCarry ) {
				bCarry= false;
			} else {			
				if( bCarry ) {
					uNums[uNum]= (uNums[uNum] - 1) * 2 + 1;
					bCarry= false;
				} else
					uNums[uNum]*= 2;
			}
			
			uint uCarryIndex= uNum;
			if( uNums[uCarryIndex] > 9 ) {
				uNums[uCarryIndex]-= 10;
				uCarryIndex++;
				uNums[uCarryIndex]+= 1;
				bCarry= true;
			}
		}
	}
	
	uint uSum=0;
	
	for( uint uNum=0; uNum<uNums.size(); ++uNum )
		uSum+= uNums[uNum];
	
	return uSum;
} // end ProblemSolver::ProblemSixteen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemSeventeen() {
	vector<QString> strNumList= ParseFileForStrings( "C:/euler/problem17.txt" );
	uint uLengthSum= 0;
	
	for( uint uNumber=1; uNumber<1000; ++uNumber ) {
		bool bExactHundred= false;
		QString strNumber;
	
		uint uHundreds= floor( (float)uNumber / 100.0f ),
			 uTens= floor( ((float)uNumber - (uHundreds*100.0f)) / 10.0f ),
			 uOnes= floor( ((float)uNumber - (uHundreds*100.0f) - (uTens*10.0f)) );
		
		if( uHundreds > 0 ) {
			strNumber+= strNumList[uHundreds];
			strNumber+= "Hundred";
			
			if( uNumber > uHundreds * 100 ) {
				strNumber+= "And";
			} else {
				bExactHundred= true;
			}
		}
		
		if( uTens > 0 ) {
			
			// We don't have specific tens words until twenty
			if( uTens > 1 ) {
				strNumber+= strNumList[uTens+17];
			}
		}
		
		if( !bExactHundred && (uOnes > 0 || uTens < 2) ) {
			if( uTens == 1 ) {
				strNumber+= strNumList[uOnes+9];
			} else {
				strNumber+= strNumList[uOnes-1];
			}
		}
	
		uLengthSum+= strNumber.length();			
	}
	
	uLengthSum+= QString("onethousand").length();
	
	return uLengthSum;
} // end ProblemSolver::ProblemSeventeen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemEighteen() {
	vector< vector<uint> > uNumbers= ParseFileForUints( "C:/euler/problem67.txt" );
	
	vector<BinaryTreeResults> chosenNumbers;
	
	const uint LOOKAHEAD_LENGTH= 20,
			   TOTAL_ROWS= uNumbers.size();
	
	uint uCurrentRow= 0,
		 uSum= 0;
	
	// Loop through every row in the triangle
	for( uint iRow= 0; iRow<TOTAL_ROWS; ++iRow ) {
		uint uMaxNum= 0,
			 iMaxElement= 0;
	
		BinaryTreeResults prevNumber;
		
		if( iRow != 0 ) {
			prevNumber= chosenNumbers[chosenNumbers.size()-1];
		
			// Search down the tree at the nest two numbers
			for( uint iElement=prevNumber.uIndex; iElement<prevNumber.uIndex+1; ++iElement ) {
				if ( iRow < TOTAL_ROWS - LOOKAHEAD_LENGTH ) {
					BinaryTreeResults uLook= BinaryLookahead( LOOKAHEAD_LENGTH, iRow, iElement, uNumbers );
					if( uLook.uValue > uMaxNum ) {
						iMaxElement= uLook.uIndex;
						uMaxNum= uLook.uValue;
					}
				} else {
					if( (int)TOTAL_ROWS - (int)iRow - 1 >= 0 ) {
						BinaryTreeResults uLook= BinaryLookahead( (int)TOTAL_ROWS - (int)iRow - 1, iRow, iElement, uNumbers );
						if( uLook.uValue > uMaxNum ) {
							iMaxElement= uLook.uIndex;
							uMaxNum= uLook.uValue;
						}
					}
				}
			} // end for each element
		}
		BinaryTreeResults newNumber;
		newNumber.uIndex= iMaxElement;
		newNumber.uValue= uNumbers[iRow][iMaxElement];
		chosenNumbers.push_back( newNumber );
	} // end for each row
	
	// Sum up the elements in the path we found
	for( uint iIndex=0; iIndex<chosenNumbers.size(); ++iIndex )
		uSum+= chosenNumbers[iIndex].uValue;
	
	return uSum;
} // end ProblemSolver::ProblemEighteen()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemTwenty() {	
 	BigInteger uBigNumber = 1;
 	
	for( uint iNumber= 1; iNumber<=100; ++iNumber ) {
		uBigNumber*= iNumber;
	}
	
	QString strNumber= QString::fromStdString( bigIntegerToString(uBigNumber) ); 
	
	uint uSum= 0;
	for( uint iDigit= 0; iDigit< strNumber.length(); ++iDigit ){
		uSum+= strNumber.mid(iDigit, 1).toUInt();
	}
	
	return uSum;
} // end ProblemSolver::ProblemTwenty()


//////////////////////////////////////////////////////////////////////////////
/*! A problem */
uint Solvers::ProblemSolver::ProblemTwentyFive() {
	BigInteger uFibb= 1,
			   uLastFibb= 0;
	
	QString strFibb;
	uint uRound= 0;
	while( strFibb.length() < 1000 ) {
		BigInteger uTemp= uFibb;
		uFibb+= uLastFibb;
		uLastFibb= uTemp;
		
		uRound++;
		strFibb= QString::fromStdString( bigIntegerToString(uFibb) );
	}

	return uRound+1;
} // end ProblemSolver::ProblemTwentyFive()
